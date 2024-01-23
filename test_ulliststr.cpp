#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
	ULListStr dat;
	dat.push_back("1"); //why do i have to put it in "" when the example doesn't
	std::cout << dat.get(0) << std::endl;
	dat.push_back("20");
	std::cout << dat.get(1) << std::endl;
	dat.push_back("3");
	dat.push_back("4");
	dat.push_back("5");
	dat.push_back("6");
	dat.push_back("7");
	dat.push_back("8");
	dat.push_back("9");
	dat.push_back("10");

	for (int i = 0; i < 10; i++){
		std::cout << dat.get(i) << " " << std::endl;
	}
	
	dat.push_back("11");
	std::cout << dat.get(10) << std::endl;

	dat.pop_back();
	dat.pop_back();

	for (int i = 0; i < 9; i++){
		std::cout << dat.get(i) << " " << std::endl;
	}

	dat.push_front("0");
	std::cout << dat.get(0) << std::endl;

	dat.push_front("-1");
	std::cout << dat.get(0) << std::endl;

	dat.pop_front();
	std::cout << dat.get(0) << std::endl;

	dat.pop_front();
	std::cout << dat.get(0) << std::endl;

	std::cout << dat.back() << std::endl;
	std::cout << dat.front() << std::endl;

	dat.pop_front();
	std::cout << dat.get(0) << std::endl;

	dat.push_front("1");
	dat.push_front("0");
	std::cout << dat.get(0) << std::endl;
}
