/**
 * @file Test.cpp
 * @author Connie Li
 * @date 2019-11-11
 */

#include "Test.h"
using namespace std;

Test::Test()
{

}

void Test::runTests()
{

}

bool Test::testIsEmpty1() const
{
	Queue q;
	return(q.isEmpty());
}

bool Test::testIsEmpty2()
{
	Queue q;
	q.enqueue(0);
	return(!(q.isEmpty()));
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