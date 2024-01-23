#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

#include <iostream> //delete later

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
/**
	* Adds a new value to the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_back(const std::string& val){
	//if empty, create new item and put at front
	if (size_ == 0){
		Item* myItem = new Item();
		head_ = myItem;
		tail_ = myItem;
		myItem->first = 0;
		myItem->last = 1;
		myItem->val[0] = val;
		size_++;
		std::cout << "Made new Item with this at front: " << val << std::endl;
	}
	else {
		Item* myItem = tail_;
		if (myItem->last < ARRSIZE){
			//if not empty and there is space, put item at back
			myItem->last++;
			myItem->val[myItem->last-1] = val;
			size_++;
			std::cout << "Added this to the back of tail: " << val << std::endl;
		}
		else {
			//if not empty and there is no space, create new item and put item at front
			myItem = new Item();
			tail_->next = myItem;
			myItem->prev = tail_;
			tail_ = myItem;
			myItem->first = 0;
			myItem->last = 1;
			myItem->val[0] = val;
			size_++;
			std::cout << "Previous item full, made new Item with this at front: " << val << std::endl;
		}
	}
}

/**
	* Removes a value from the back of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_back(){
	//if empty
	if (size_ == 0){
		return;
	}
	//remove the back of the list in an Item without stuff (delete Item)
	Item* myItem = tail_;
	if (myItem->last == myItem->first + 1){
		//if item is part of a chain
		if (myItem->prev != nullptr){
			(myItem->prev)->next = nullptr;
			tail_ = myItem->prev;
		}
		//if item is last item
		else{
			head_ = nullptr;
			tail_ = nullptr;
		}
		delete myItem;
		size_--;
		std::cout << "Removed back item and deleted Item" << std::endl;
	}
	//remove the back of the list in an Item with stuff
	else{
		//std::cout << "Index of last: " << myItem->last << std::endl;
		myItem->val[myItem->last - 1] = "";
		myItem->last--;
		size_--;
		std::cout << "Removed back item" << std::endl;
	}
}

/**
	* Adds a new value to the front of the list.
	* If there is room before the 'first' value in
	* the head node add it there, otherwise, 
	* allocate a new head node.
	*   - MUST RUN in O(1)
	*/
void ULListStr::push_front(const std::string& val){
	//if empty, create new item and put at front
	if (size_ == 0){
		Item* myItem = new Item();
		head_ = myItem;
		tail_ = myItem;
		myItem->first = ARRSIZE-1;
		myItem->last = ARRSIZE;
		myItem->val[ARRSIZE-1] = val;
		size_++;
		std::cout << "Made new Item with this at end: " << val << std::endl;
	}
	else {
		Item* myItem = head_;
		if (myItem->first > 0){
			//if not empty and there is space, put item at front
			myItem->first--;
			myItem->val[myItem->first] = val;
			size_++;
			std::cout << "Added this to the front of head: " << val << std::endl;
		}
		else {
			//if not empty and there is no space, create new item and put item at front
			myItem = new Item();
			head_->prev = myItem;
			myItem->next = head_;
			head_ = myItem;
			myItem->first = ARRSIZE-1;
			myItem->last = ARRSIZE;
			myItem->val[ARRSIZE-1] = val;
			size_++;
			std::cout << "Previous item full, made new Item with this at front: " << val << std::endl;
		}
	}
}

/**
	* Removes a value from the front of the list
	*   - MUST RUN in O(1)
	*/
void ULListStr::pop_front(){
	//if empty
	if (size_ == 0){
		return;
	}
	//remove the front of the list in an Item without stuff (delete Item)
	Item* myItem = head_;
	if (myItem->last == myItem->first + 1){
		//if item is part of a chain
		if (myItem->next != nullptr){
			(myItem->next)->prev = nullptr;
			head_ = myItem->next;
		}
		//if item is last item
		else{
			head_ = nullptr;
			tail_ = nullptr;
		}
		delete myItem;
		size_--;
		std::cout << "Removed front item and deleted Item" << std::endl;
	}
	//remove the front of the list in an Item with stuff
	else{
		myItem->val[myItem->first] = "";
		myItem->first++;
		size_--;
		std::cout << "Removed front item" << std::endl;
	}
}

/**
	* Returns a const reference to the back element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::back() const{
	Item* myItem = tail_;
	return myItem->val[myItem->last - 1];
}

/**
	* Returns a const reference to the front element
	*   - MUST RUN in O(1)
	*/
std::string const & ULListStr::front() const{
	return *getValAtLoc(0);
}

/** 
	* Returns a pointer to the item at index, loc,
	*  if loc is valid and NULL otherwise
	*   - MUST RUN in O(n) 
	*/
std::string* ULListStr::getValAtLoc(size_t loc) const{
	if (size_ == 0){
		return nullptr;
	}
	
	int count = loc;
	Item* temp = head_;
	while (temp != NULL){
		int length = temp->last - temp->first;
		//std::cout << "For location " << loc << " the length is " << length << " and the count is " << count << std::endl;
		if (count < length){
			return &temp->val[temp->first + count];
		}
		count -= length;
		temp = temp->next;
	}

	return nullptr;
}

//END OF MY CODE

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
