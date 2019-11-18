/**
 * @file Test.h
 * @author Connie Li
 * @date 2019-11-11
 */

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include "Queue.h"
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
	/** Tests the Queue's isEmpty() method on a newly created queue.
	 * @pre Assume that the newly constructed Queue should be empty.
	 * @return true if isEmpty() returns true, else false.
	 */
	bool testIsEmpty1() const;

	/** Tests the Queue's isEmpty() method on a queue containing 1 item.
	 * @pre Assume that the enqueue() adds an item properly.
	 * @return true if isEmpty() returns false, else false.
	 */
	bool testIsEmpty2();

	/** Tests the Queue's enqueue() method: Node is added to the back of the queue, Node added contains the correct data.
	 * @return true if a Node was added, else false.
	 */
	bool testEnqueue();

	/** Tests the Queue's dequeue() method: behavior when the queue is empty, behavior when the queue is not empty; successful removal of the Node at the front.
	 * @return true if all subtests are passed, else false.
	 */
	bool testDequeue();

	/** Tests the Queue's peekFront() method: behavior when the queue is empty, behavior when the queue is not empty, the queue is unchanged, the value at the front is returned correctly.
	 * @return true if all subtests are passed, else false.
	 */
	bool testPeekFront() const;

	// -------- PRINTING HELPER METHODS -------- //
	/** Prints a header for the current test with the test title and the given description.
	 * @param title the title of the current test.
	 * @param descrip a description of the current test.
	 * @post prints the given information.
	 */
	void printTestHeader(string title, string descrip) const;

	/** Prints the result of the test, "PASSED" or "FAILED".
	 * @param isPassed true if the test is passed, else false.
	 * @post prints PASSED or FAILED based on the value of isPassed.
	 */
	void printTestResult(bool isPassed) const;

	/** Prints the given error message to the console.
	 * @param msg the body of the error message
	 * @post prints a message to the console in the format: "ERROR: <msg>"
	 */
	void printError(string msg) const;
};

#endif