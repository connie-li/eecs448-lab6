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
    /** constructor
     * @param q a reference to a Queue object.
     * @post sets m_queue to refer to q.
     */
    Test(Queue<int>& q);
    
    /**
     *
     */
    void runTests();

private:
    Queue<int>& m_queue;
};

#endif
