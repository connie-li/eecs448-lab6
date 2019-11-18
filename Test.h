/**
 * @file Test.h
 * @author Connie Li
 * @date 2019-11-11
 */

#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

	/** Tests whether enqueue() adds the correct entry data. Creates a new Queue, adds one item, then checks that item's data.
	 * @pre Assume that enqueue() adds an item; assume that peekFront() works properly.
	 * @return true if the entry in the queue matches the argument given to enqueue, else false.
	 */
	bool testEnQEntry();

	/** Tests whether enqueue() adds items to the back of the Queue. Creates a new queue, adds multiple items, then checks whether the first entry added is at the front.
	 * @pre Assume that peekFront() works properly.
	 * @return true if the value added first is at the front, else false.
	 */
	bool testEnQBack();

	/** Tests the behavior of dequeue() when the queue is empty. Creates a new Queue and attempts to dequeue from it.
	 * @pre Assume that Queues are properly created (ie, empty).
	 * @return 1 if a std::runtime_error is thrown, 2 if some other kind of error is thrown, or 3 if no error is thrown.
	 */
	int testDeQEmpty();

	/** Tests the behavior of dequeue() when the queue is not empty. Creates a new Queue and adds one item, then tests dequeue().
	 * @pre Assume that enqueue properly adds one item; assume that isEmpty() works properly.
	 * @return true if the item is successfully removed, else false.
	 */
	bool testDeQRemove1();

	/** Tests whether dequeue always deletes the front of the queue.
	 * @pre (Based on prior tests) assumes that enqueue() adds items to the front; assumes that dequeueing removes an item.
	 * @return true if the front is deleted, else false.
	 */
	bool testDeQFront();
	/** Tests the behavior of peekFront() when the queue is empty.
	 * @pre Assume that isEmpty() works correctly.
	 * @return 1 if a std::runtime_error is thrown, 2 if some other kind of error is thrown, or 3 if no error is thrown.
	 */
	int testPeekEmpty() const;

	/** Tests the Queue's peekFront() method: behavior when the queue is empty, behavior when the queue is not empty, the queue is unchanged, the value at the front is returned correctly.
	 * @pre Assume that enqueue() works properly when adding a single item to a new queue.
	 * @return true if all subtests are passed, else false.
	 */
	bool testPeekNotEmpty() const;

	/** Prints values present in a queue to help find enqueue's bug. Creates an example queue, adds values 0 through 4, then prints each value in order from front to back.
	 * @pre assumes that dequeue() works properly.
	 * @post prints all values present in the queue.
	 */
	void printEnqueued() const;

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