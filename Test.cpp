/**
 * @file Test.cpp
 * @author Connie Li
 * @date 2019-11-11
 */

#include "Test.h"
using namespace std;

Test::Test()
{
	m_size = 0;
}

void Test::runTests()
{

}

bool Test::testConstruction() const
{

}

bool Test::testIsEmpty() const
{

}

bool Test::testEnqueue()
{

}

bool Test::testDequeue()
{

}

bool Test::testPeekFront() const
{

}

// -------- PRINTING HELPER METHODS -------- //
void Test::printTestHeader(string title, string descrip) const
{
	cout << title << ": " << descrip << ": ";
	return;
}

void Test::printTestResult(bool isPassed) const
{
	if(isPassed)
	{
		cout << "PASSED\n";
	}
	else
	{
		cout << "FAILED\n";
	}
}