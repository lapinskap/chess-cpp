#include "UnitTest++/UnitTestPP.h";

#include <iostream>

int main(int, char const* [])
{
	std::cout << "Test start...." << std::endl;
	int test_result = UnitTest::RunAllTests();
	std::cout << "Test completed" << std::endl;
	return test_result;
}