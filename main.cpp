/**
*	@file main.cpp
*	@author John Gibbons
*	@date 2014.04.02
*	modified by Connie Li, 2019-11-11
*/

#include <iostream>
#include <stdexcept>
#include "Queue.h"

int main()
{
	Queue q;
	Test tester(q);
	tester.runTests();

	return(0);
}
