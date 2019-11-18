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
	// tests that depend only on the constructor
	printTestHeader("Test dequeue() #1", "dequeueing from an empty queue");
	int result = testDeQEmpty();
	printTestResult(result == 1);

	printTestHeader("Test isEmpty() #1", "new Queue evaluates as empty");
	printTestResult(testIsEmpty1());

	// tests that depend on other member methods
	printTestHeader("Test peekFront() #1", "peek when queue is empty");
	result = testPeekEmpty();
	printTestResult(result == 1);

	printTestHeader("Test enqueue() #1", "entry value added correctly");
	printTestResult(testEnQEntry());

	printTestHeader("Test peekFront() #2", "peek when queue contains 1 item");
	printTestResult(testPeekNotEmpty());

	printTestHeader("Test enqueue() #2", "items always added to back");
	printTestResult(testEnQBack());

	printTestHeader("Test isEmpty() #2", "Queue containing 1 item");
	printTestResult(testIsEmpty2());

	printTestHeader("Test dequeue() #2", "removing 1 item");
	printTestResult(testDeQRemove1());

	printTestHeader("Test enqueue() #3", "actual enqueue order");
	printEnqueued();
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

int Test::testDeQEmpty()
{
	Queue q;
	int result = 3;
	try
	{
		q.dequeue();
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

bool Test::testDeQRemove1()
{
	srand(time(NULL));
	Queue q;
	q.enqueue(rand() % 100 - 50);
	try
	{
		q.dequeue();
	}
	catch(...)
	{
		printError("dequeue");
	}

	return(q.isEmpty());
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

bool Test::testDeQFront()
{
	Queue q;
	for(int i = 0; i < 5; i++)
	{
		q.enqueue(i);
	}

	q.dequeue();
	int front = q.peekFront();

	return(front == 3);
}

bool Test::testDeQAll()
{
	Queue q;
	for(int i = 0; i < 5; i++)
	{
		q.enqueue(i);
	}

	bool succeeded = true;
	for(int i = 0; i < 5; i++)
	{
		try
		{
			q.dequeue();
		}
		catch(...)
		{
			printError("dequeue error on index " + to_string(i));
			succeeded = false;
		}
	}

	return(succeeded);
}

void Test::printEnqueued() const
{
	Queue q;
	for(int i = 0; i < 5; i++)
	{
		q.enqueue(i);
	}

	for(int i = 0; i < 5; i++)
	{
		cout << q.peekFront() << ' ';
		q.dequeue();
	}
	cout << '\n';
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