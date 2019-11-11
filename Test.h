/**
 * @file Test.h
 * @author Connie Li
 * @date 2019-11-11
 */

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
using namespace std;

class Test
{
public:
	/** Constructor
	 * @post initializes m_size to 0.
	 */
	Test();

	/** Runs all tests.
	 * @post prints the results of all tests.
	 */
	void runTests();

private:
	Queue<int> m_queue;	// the queue being tested.
	int m_size;	// size of the queue.

	/** Tests whether the queue was constructed properly: if the queue's pointers exist, and the queue is empty.
	 * @return true if the queue was constructed properly, else false.
	 */
	bool testConstruction() const;

	/** Tests the Queue's isEmpty() method.
	 * @return true if
	 */
	bool testIsEmpty() const;

	bool testEnqueue();

	bool testDequeue();

	bool testPeekFront() const;


};

#endif