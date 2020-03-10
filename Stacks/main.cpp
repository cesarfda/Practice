/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/15/18.
 *  Copyright (c) 2018 Lee Barney
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/* !!!!GRADING INSTRUCTIONS!!!!
 *
 * When you report your score for this test set, report
 * the percentage of assertTrues found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
int asserts_existing = 112;

#include <iostream>
#include "stack.h"
#include "../unit_testing.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;



int main(int argc, const char* argv[]) {
    
    /*
     * Testing default constructor
     */
    stack <int> defaultStack;
    assertTrue(defaultStack.numCapacity == 0);
    assertTrue(defaultStack.numElements == 0);
    assertTrue(defaultStack.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    
    /*
     * Testing Size
     */
    stack <int> sizeTestStack;
    
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 4;
    assertTrue(sizeTestStack.size() == 4);
    cout << "Size Tests Passed" << endl;
    
    /*
     * Testing Capacity
     */
    assertTrue(sizeTestStack.capacity() == 8);
    sizeTestStack.numCapacity = 0;
    assertTrue(sizeTestStack.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    
    /*
     * Resetting for further use
     */
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 0;
    sizeTestStack.buffer = new int[sizeTestStack.numCapacity];
    for (int i = 0; i < sizeTestStack.numCapacity; i++) {
        sizeTestStack.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestStack.clear();
    assertTrue(sizeTestStack.numCapacity == 8);
    assertTrue(sizeTestStack.numElements == 0);
    assertTrue(sizeTestStack.buffer != NULL);
    cout << "Clear Test Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestStack.numElements = 3;
    assertTrue(!sizeTestStack.empty());
    
    sizeTestStack.numElements = 0;
    
    assertTrue(sizeTestStack.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing resize
     */
    stack<int> emptyResizeStack;
    emptyResizeStack.resize(-1);
    assertTrue(emptyResizeStack.numCapacity == 0);
    assertTrue(emptyResizeStack.numElements == 0);
    assertTrue(emptyResizeStack.buffer == NULL);
    cout<<"Passed negative resize test."<<endl;
    
    emptyResizeStack.resize(7);
    assertTrue(emptyResizeStack.numCapacity == 7);
    assertTrue(emptyResizeStack.numElements == 0);
    assertTrue(emptyResizeStack.buffer != NULL);
    cout<<"Passed default stack resized test."<<endl;
    
    stack <int> resizeStack;
    resizeStack.buffer = new int[5];
    resizeStack.numCapacity = 5;
    resizeStack.numElements = 5;
    resizeStack.buffer[0] = 7;
    resizeStack.buffer[1] = 12;
    resizeStack.buffer[2] = 10;
    resizeStack.buffer[3] = 9;
    resizeStack.buffer[4] = 8;
    
    int *theBuffer = resizeStack.buffer;
    resizeStack.resize(10);
    assertTrue(theBuffer != resizeStack.buffer);
    assertTrue(resizeStack.numCapacity == 10);
    assertTrue(resizeStack.numElements == 5);
    assertTrue(resizeStack.buffer[0] == 7);
    assertTrue(resizeStack.buffer[1] == 12);
    assertTrue(resizeStack.buffer[2] == 10);
    assertTrue(resizeStack.buffer[3] == 9);
    assertTrue(resizeStack.buffer[4] == 8);
    
    theBuffer = resizeStack.buffer;
    resizeStack.resize(2);
    assertTrue(theBuffer != resizeStack.buffer);
    assertTrue(resizeStack.numCapacity == 2);
    assertTrue(resizeStack.numElements == 2);
    assertTrue(resizeStack.buffer[0] == 7);
    assertTrue(resizeStack.buffer[1] == 12);
    
    theBuffer = resizeStack.buffer;
    resizeStack.resize(0);
    assertTrue(resizeStack.numCapacity == 0);
    assertTrue(resizeStack.numElements == 0);
    assertTrue(resizeStack.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    
    
    /*
     * Testing push with resizing
     */
    stack <int> pushStack;
    theBuffer = pushStack.buffer;
    pushStack.push(1);
    assertTrue(pushStack.numCapacity == 1);
    assertTrue(pushStack.numElements == 1);
    assertTrue(theBuffer != pushStack.buffer);
    assertTrue(pushStack.buffer[0] == 1);
    cout << "Push First ElementTest Passed" << endl;
    
    theBuffer = pushStack.buffer;
    pushStack.push(3);
    assertTrue(pushStack.numCapacity == 2);
    assertTrue(pushStack.numElements == 2);
    assertTrue(theBuffer != pushStack.buffer);
    assertTrue(pushStack.buffer[0] == 1);
    assertTrue(pushStack.buffer[1] == 3);
    cout << "Push Second ElementTest Passed" << endl;
    
    theBuffer = pushStack.buffer;
    pushStack.push(5);
    assertTrue(pushStack.numCapacity == 4);
    assertTrue(pushStack.numElements == 3);
    assertTrue(theBuffer != pushStack.buffer);
    assertTrue(pushStack.buffer[0] == 1);
    assertTrue(pushStack.buffer[1] == 3);
    assertTrue(pushStack.buffer[2] == 5);
    cout << "Push Third ElementTest Passed" << endl;
    
    
    theBuffer = pushStack.buffer;
    pushStack.push(7);
    assertTrue(pushStack.numCapacity == 4);
    assertTrue(pushStack.numElements == 4);
    assertTrue(theBuffer == pushStack.buffer);
    assertTrue(pushStack.buffer[0] == 1);
    assertTrue(pushStack.buffer[1] == 3);
    assertTrue(pushStack.buffer[2] == 5);
    assertTrue(pushStack.buffer[3] == 7);
    cout << "Push Fourth ElementTest Passed" << endl;
    
    
    
    /*
     * Testing pop
     */
    
    stack<int> popStack;
    popStack.pop();
    assertTrue(popStack.numElements == 0);
    assertTrue(popStack.numCapacity == 0);
    assertTrue(popStack.buffer == NULL);
    
    /*
     * Simulate situation where one push has been done.
     */
    popStack.numElements = 1;
    popStack.numCapacity = 1;
    popStack.buffer = new int[1];
    popStack.buffer[0] = 3;
    
    popStack.pop();
    assertTrue(popStack.numElements == 0);
    assertTrue(popStack.numCapacity == 1);
    assertTrue(popStack.buffer != NULL);
    assertTrue(popStack.buffer[0] == 3);//this value is abandoned, but not replaced by pop.
    
    /*
     * Simulate situation where elements != capacity.
     */
    delete [] popStack.buffer;
    popStack.buffer = new int[5];
    popStack.numElements = 3;
    popStack.numCapacity = 5;
    popStack.buffer[0] = 1;
    popStack.buffer[1] = -7;
    popStack.buffer[2] = 3861;
    
    popStack.pop();
    assertTrue(popStack.numElements == 2);
    assertTrue(popStack.numCapacity == 5);
    assertTrue(popStack.buffer != NULL);
    assertTrue(popStack.buffer[0] == 1);
    assertTrue(popStack.buffer[1] == -7);
    assertTrue(popStack.buffer[2] == 3861);
    
    cout<<"Pop tests passed."<<endl;
    
    /*
     * Testing top getter
     */
    stack<int> topStack;
    try{
        int topValue = topStack.top();
        topValue = 18;
        assertTrue(false);
    } catch (const char* message) {
        strcmp(message, "Error: asking for top of empty stack.");
    }
    //simulating full buffer
    topStack.numElements = 5;
    topStack.numCapacity = 5;
    topStack.buffer = new int[5];
    topStack.buffer[0] = 1;
    topStack.buffer[1] = -7;
    topStack.buffer[2] = 3861;
    topStack.buffer[3] = 0;
    topStack.buffer[4] = 18;
    assertTrue(topStack.top() == 18);
    //simulating non-full buffer
    topStack.numElements = 3;
    assertTrue(topStack.top() == 3861);
    
    int topValue = topStack.top();
    topValue = 34;
    assertTrue(topStack.top() == 3861);
    
    /*
     * Testing top setter
     */
    //reseting
    delete [] topStack.buffer;
    topStack.buffer = NULL;
    topStack.numElements = 0;
    topStack.numCapacity = 0;
    try{
        topStack.top() = 3;
        assertTrue(false);
    } catch (const char* message) {
        strcmp(message, "Error: asking for top of empty stack.");
    }
    //simulating full buffer
    topStack.numElements = 5;
    topStack.numCapacity = 5;
    topStack.buffer = new int[5];
    topStack.buffer[0] = 1;
    topStack.buffer[1] = -7;
    topStack.buffer[2] = 3861;
    topStack.buffer[3] = 0;
    topStack.buffer[4] = 18;
    topStack.top() = -13;
    assertTrue(topStack.top() == -13);
    //simulating non-full buffer
    topStack.numElements = 3;
    topStack.top() = 421;
    assertTrue(topStack.top() == 421);
    
    cout<<"Top tests passed."<<endl;
    /*
     * Testing Accessor
     */
    stack <int> beginEndStack;
    beginEndStack.buffer = new int[6];
    beginEndStack.buffer[0] = -500;
    beginEndStack.buffer[1] = 0;
    beginEndStack.buffer[2] = 7;
    beginEndStack.buffer[3] = 13;
    beginEndStack.buffer[4] = 23;
    beginEndStack.numCapacity = 6;
    beginEndStack.numElements = 5;
    
    
    
    /*
     * Testing = operator and copy constructor
     */
    stack <int> stackToCopy;
    stackToCopy.numCapacity = 8;
    stackToCopy.numElements = 8;
    stackToCopy.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numCapacity; i++) {
        stackToCopy.buffer[i]=i*i+1;
    }
    stack <int> stackAssignedCopy;
    stackAssignedCopy = stackToCopy;
    assertTrue(stackAssignedCopy.numCapacity == 8);
    assertTrue(stackAssignedCopy.numElements == 8);
    assertTrue(stackAssignedCopy.buffer != stackToCopy.buffer);
    assertTrue(stackAssignedCopy.buffer[0] == 1);
    assertTrue(stackAssignedCopy.buffer[1] == 2);
    assertTrue(stackAssignedCopy.buffer[2] == 5);
    assertTrue(stackAssignedCopy.buffer[3] == 10);
    assertTrue(stackAssignedCopy.buffer[4] == 17);
    assertTrue(stackAssignedCopy.buffer[5] == 26);
    assertTrue(stackAssignedCopy.buffer[6] == 37);
    assertTrue(stackAssignedCopy.buffer[7] == 50);
    cout << "(full) = Operator Test Passed" << endl;
    
    stack <int> stackCopy(stackToCopy);
    assertTrue(stackCopy.numCapacity == 8);
    assertTrue(stackCopy.numElements == 8);
    assertTrue(stackCopy.buffer != stackToCopy.buffer);
    assertTrue(stackCopy.numCapacity == 8);
    assertTrue(stackCopy.buffer[0] == 1);
    assertTrue(stackCopy.buffer[1] == 2);
    assertTrue(stackCopy.buffer[2] == 5);
    assertTrue(stackCopy.buffer[3] == 10);
    assertTrue(stackCopy.buffer[4] == 17);
    assertTrue(stackCopy.buffer[5] == 26);
    assertTrue(stackCopy.buffer[6] == 37);
    assertTrue(stackCopy.buffer[7] == 50);
    cout << "(Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Resetting to not full stack
     */
    
    stackToCopy.numElements = 3;
    
    stack <int> notFullStackAssignedCopy;
    notFullStackAssignedCopy = stackToCopy;
    assertTrue(notFullStackAssignedCopy.numCapacity == 3);
    assertTrue(notFullStackAssignedCopy.numElements == 3);
    assertTrue(notFullStackAssignedCopy.buffer != stackToCopy.buffer);
    assertTrue(notFullStackAssignedCopy.buffer[0] == 1);
    assertTrue(notFullStackAssignedCopy.buffer[1] == 2);
    assertTrue(notFullStackAssignedCopy.buffer[2] == 5);
    cout << "(Not full) = Operator Test Passed" << endl;
    
    stack <int> notFullStackCopy(stackToCopy);
    assertTrue(notFullStackCopy.numCapacity == 3);
    assertTrue(notFullStackCopy.numElements == 3);
    assertTrue(notFullStackCopy.buffer != stackToCopy.buffer);
    assertTrue(notFullStackCopy.buffer[0] == 1);
    assertTrue(notFullStackCopy.buffer[1] == 2);
    assertTrue(notFullStackCopy.buffer[2] == 5);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    
    
    /*
     * Testing push for Non-Integer Stack Behavior (Just to Make Sure stack Works For Other Types)
     */
    stack <string> stringStack;
    
    stringStack.push("Hello");
    stringStack.push("It's me");
    stringStack.push("I was wondering");
    assertTrue(stringStack.numCapacity == 4);
    assertTrue(stringStack.buffer[0] == "Hello");
    assertTrue(stringStack.buffer[1] == "It's me");
    assertTrue(stringStack.buffer[2] == "I was wondering");
    
    cout << "This stack can hold strings!!!!" << endl;
    
    
    generateTestingReport();
    
    return 0;
}
