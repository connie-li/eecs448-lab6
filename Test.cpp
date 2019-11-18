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
	bool prevPassed = false;
	printTestHeader("Test isEmpty() #1", "does a new Queue evaluate as empty?");
	prevPassed = testIsEmpty1();
	printTestResult(prevPassed);

	printTestHeader("Test isEmpty() #2", "Queue containing 1 item");
	prevPassed = testIsEmpty2();
	printTestResult(prevPassed);
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

bool Test::testEnQEntry()
{
	srand(time(NULL));
	Queue q;
	int random = rand() % 100 -50;
	q.enqueue(random);
	bool valueCorrect = false;
	try
	{
		valueCorrect = (q.peekFront() == random);
	}
	catch(...)
	{
		printError("peekFront");
	}
	return(valueCorrect);
}

bool Test::testEnQBack()
{
	srand(time(NULL));
	Queue q;
	int size = 5;
	int* randVals = new int[size];
	for(int i = 0; i < size; i++)
	{
		randVals[i] = rand() % 100 -50;
		q.enqueue(randVals[i]);
	}

	bool frontCorrect = false;
	try
	{
		frontCorrect = (q.peekFront() == randVals[0]);
	}
	catch(...)
	{
		printError("peekFront");
	}
	delete[] randVals;
	return(frontCorrect);
}

bool Test::testDequeue()
{

}

int Test::testPeekEmpty() const
{
	Queue q;
	int result = 3;
	try
	{
		q.peekFront();
	}
	catch(runtime_error& e)
	{
		result = 1;
	}
	catch(...)
	{
		result = 2;
	}

	return(result);
}

bool Test::testPeekNotEmpty() const
{
	srand(time(NULL));
	Queue q;
	int randVal = rand() % 100 - 50;
	q.enqueue(randVal);
	int frontVal = 0;
	try
	{
		frontVal = q.peekFront();
	}
	catch(...)
	{
		printError("peekFront");
	}

	return(randVal == frontVal);
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

void Test::printError(string msg) const
{
	cout << "\tERROR: " << msg << '\n';
}