/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
		Node* head = nullptr;
    Node* second = nullptr;
    Node* third = nullptr;
		Node* fourth = nullptr;

		fourth = new Node(4, nullptr);
    third = new Node(3, fourth);
		second = new Node(2, third);
		head = new Node(1, second);

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(head, odds, evens);	

		cout << odds->value << endl; 
		cout << odds->next->value << endl; 
		
		cout << evens->value << endl; 
		cout << evens->next->value << endl; 

		while (odds != nullptr){
			Node* temp = odds;
			odds = odds->next;
			delete temp;
		}

		while (evens != nullptr){
			Node* temp = evens;
			evens = evens->next;
			delete temp;
		}

		return 0;
}
