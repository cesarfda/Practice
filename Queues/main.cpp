/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/18/18.
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
int asserts_existing = 144;

#include <iostream>
#include "queue.h"
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
    queue <int> defaultQueue;
    assertTrue(defaultQueue.numCapacity == 0);
    assertTrue(defaultQueue.numPush == 0);
    assertTrue(defaultQueue.numPop == 0);
    assertTrue(defaultQueue.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    
    
    /*
     * Testing Size
     */
    queue <int> sizeTestQueue;
    
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPush = 4;
    sizeTestQueue.numPop = 0;
    assertTrue(sizeTestQueue.size() == 4);
    
    sizeTestQueue.numPop = 4;
    assertTrue(sizeTestQueue.size() == 0);
    
    sizeTestQueue.numPop = 2;
    assertTrue(sizeTestQueue.size() == 2);
    
    
    sizeTestQueue.numPush = 32;
    sizeTestQueue.numPop = 29;
    assertTrue(sizeTestQueue.size() == 3);
    
    cout << "Size Tests Passed" << endl;
    
    /*
     * Testing Capacity
     */
    assertTrue(sizeTestQueue.capacity() == 8);
    sizeTestQueue.numCapacity = 0;
    assertTrue(sizeTestQueue.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    
    /*
     * Resetting for further use
     */
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPush = 8;
    sizeTestQueue.numPop = 0;
    sizeTestQueue.buffer = new int[sizeTestQueue.numCapacity];
    for (int i = 0; i < sizeTestQueue.numCapacity; i++) {
        sizeTestQueue.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestQueue.clear();
    assertTrue(sizeTestQueue.numCapacity == 8);
    assertTrue(sizeTestQueue.numPush == 0);
    assertTrue(sizeTestQueue.numPop == 0);
    assertTrue(sizeTestQueue.buffer != NULL);
    cout << "Clear Test Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestQueue.numPush = 3;
    sizeTestQueue.numPop = 2;
    assertTrue(!sizeTestQueue.empty());
    
    sizeTestQueue.numPop = 3;
    
    assertTrue(sizeTestQueue.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing resize
     */
    queue<int> emptyResizeQueue;
    emptyResizeQueue.resize(-1);
    assertTrue(emptyResizeQueue.numCapacity == 0);
    assertTrue(emptyResizeQueue.numPush == 0);
    assertTrue(emptyResizeQueue.numPop == 0);
    assertTrue(emptyResizeQueue.buffer == NULL);
    cout<<"Passed negative resize test."<<endl;
    
    emptyResizeQueue.resize(7);
    assertTrue(emptyResizeQueue.numCapacity == 7);
    assertTrue(emptyResizeQueue.numPush == 0);
    assertTrue(emptyResizeQueue.numPop == 0);
    assertTrue(emptyResizeQueue.buffer != NULL);
    cout<<"Passed default queue resized test."<<endl;
    /*
    queue <int> resizeQueue;
    resizeQueue.buffer = new int[5];
    resizeQueue.numCapacity = 5;
    resizeQueue.numPush = 5;
    resizeQueue.numPop = 0;
    resizeQueue.buffer[0] = 7;
    resizeQueue.buffer[1] = 12;
    resizeQueue.buffer[2] = 10;
    resizeQueue.buffer[3] = 9;
    resizeQueue.buffer[4] = 8;
    
    int *theBuffer = resizeQueue.buffer;
    resizeQueue.resize(10);
    assertTrue(theBuffer != resizeQueue.buffer);
    assertTrue(resizeQueue.numCapacity == 10);
    assertTrue(resizeQueue.numPush == 5);
    assertTrue(resizeQueue.numPop == 0);
    assertTrue(resizeQueue.buffer[0] == 7);
    assertTrue(resizeQueue.buffer[1] == 12);
    assertTrue(resizeQueue.buffer[2] == 10);
    assertTrue(resizeQueue.buffer[3] == 9);
    assertTrue(resizeQueue.buffer[4] == 8);
    
    theBuffer = resizeQueue.buffer;
    //reset
    delete [] resizeQueue.buffer;
    resizeQueue.buffer = new int[5];
    theBuffer = resizeQueue.buffer;
    resizeQueue.numCapacity = 5;
    resizeQueue.numPush = 18;
    resizeQueue.numPop = 13;
    resizeQueue.buffer[0] = 7;
    resizeQueue.buffer[1] = 12;
    resizeQueue.buffer[2] = 10;
    resizeQueue.buffer[3] = 9;
    resizeQueue.buffer[4] = 8;
   
    resizeQueue.resize(10);
    assertTrue(theBuffer != resizeQueue.buffer);
    assertTrue(resizeQueue.numCapacity == 10);
    assertTrue(resizeQueue.numPush == 5);
    assertTrue(resizeQueue.numPop == 0);
    assertTrue(resizeQueue.buffer[0] == 9);
    assertTrue(resizeQueue.buffer[1] == 8);
    assertTrue(resizeQueue.buffer[2] == 7);
    assertTrue(resizeQueue.buffer[3] == 12);
    assertTrue(resizeQueue.buffer[4] == 10);
    
    
    
    theBuffer = resizeQueue.buffer;
    resizeQueue.resize(2);
    assertTrue(theBuffer != resizeQueue.buffer);
    assertTrue(resizeQueue.numCapacity == 2);
    assertTrue(resizeQueue.numPush == 2);
    assertTrue(resizeQueue.numPop == 0);
    assertTrue(resizeQueue.buffer[0] == 9);
    assertTrue(resizeQueue.buffer[1] == 8);
    
    theBuffer = resizeQueue.buffer;
    resizeQueue.resize(0);
    assertTrue(resizeQueue.numCapacity == 0);
    assertTrue(resizeQueue.numPush == 0);
    assertTrue(resizeQueue.numPop == 0);
    assertTrue(resizeQueue.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    */
    /*
     * Testing iHead and iTail
     */
    queue <int> headTailQueue;
    headTailQueue.buffer = new int[8];
    headTailQueue.numCapacity = 8;
    headTailQueue.numPush = 0;
    headTailQueue.numPop = 0;
    assertTrue(headTailQueue.iHead() == 0);
    assertTrue(headTailQueue.iTail() == -1);
    
    
    headTailQueue.numPush = 1;
    headTailQueue.numPop = 0;
    assertTrue(headTailQueue.iHead() == 0);
    assertTrue(headTailQueue.iTail() == 0);
    
    
    headTailQueue.numPush = 2;
    headTailQueue.numPop = 0;
    assertTrue(headTailQueue.iHead() == 0);
    assertTrue(headTailQueue.iTail() == 1);
    
    
    headTailQueue.numPush = 2;
    headTailQueue.numPop = 1;
    assertTrue(headTailQueue.iHead() == 1);
    assertTrue(headTailQueue.iTail() == 1);
    
    
    headTailQueue.numPush = 2;
    headTailQueue.numPop = 2;
    assertTrue(headTailQueue.iHead() == 2);
    assertTrue(headTailQueue.iTail() == 1);
    
    
    headTailQueue.numPush = 21;
    headTailQueue.numPop = 17;
    assertTrue(headTailQueue.iHead() == 1);
    assertTrue(headTailQueue.iTail() == 4);
    
    
    /*
     * Testing push with resizing
     */
    queue <int> pushResizeQueue;
    pushResizeQueue.push(1);
    assertTrue(pushResizeQueue.numCapacity == 1);
    assertTrue(pushResizeQueue.numPush == 1);
    assertTrue(pushResizeQueue.numPop == 0);
    assertTrue(pushResizeQueue.buffer[0] == 1);
    cout << "Push with resize First ElementTest Passed" << endl;
    
    pushResizeQueue.push(5);
    assertTrue(pushResizeQueue.numCapacity == 2);
    assertTrue(pushResizeQueue.numPush == 2);
    assertTrue(pushResizeQueue.numPop == 0);
    assertTrue(pushResizeQueue.buffer[0] == 1);
    assertTrue(pushResizeQueue.buffer[1] == 5);
    cout << "Push with resize Second Element Test Passed" << endl;
    
    pushResizeQueue.push(10);
    assertTrue(pushResizeQueue.numCapacity == 4);
    assertTrue(pushResizeQueue.numPush == 3);
    assertTrue(pushResizeQueue.numPop == 0);
    assertTrue(pushResizeQueue.buffer[0] == 1);
    assertTrue(pushResizeQueue.buffer[1] == 5);
    assertTrue(pushResizeQueue.buffer[2] == 10);
    cout << "Push with resize Third Element Test Passed" << endl;
    
    pushResizeQueue.push(11);
    assertTrue(pushResizeQueue.numCapacity == 4);
    assertTrue(pushResizeQueue.numPush == 4);
    assertTrue(pushResizeQueue.numPop == 0);
    assertTrue(pushResizeQueue.buffer[0] == 1);
    assertTrue(pushResizeQueue.buffer[1] == 5);
    assertTrue(pushResizeQueue.buffer[2] == 10);
    assertTrue(pushResizeQueue.buffer[3] == 11);
    cout << "Push with resize Fourth Element Test Passed" << endl;
    
    pushResizeQueue.push(13);
    assertTrue(pushResizeQueue.numCapacity == 8);
    assertTrue(pushResizeQueue.numPush == 5);
    assertTrue(pushResizeQueue.numPop == 0);
    assertTrue(pushResizeQueue.buffer[0] == 1);
    assertTrue(pushResizeQueue.buffer[1] == 5);
    assertTrue(pushResizeQueue.buffer[2] == 10);
    assertTrue(pushResizeQueue.buffer[3] == 11);
    assertTrue(pushResizeQueue.buffer[4] == 13);
    cout << "Push with resize Fifth Element Test Passed" << endl;
    
    /*
     * Testing Pop
     */
    
    
    
    /*
     * Testing = operator and copy constructor
     */
    queue <int> queueToCopy;
    queueToCopy.numCapacity = 8;
    queueToCopy.numPush = 8;
    queueToCopy.numPop = 0;
    queueToCopy.buffer = new int[queueToCopy.numCapacity];
    for (int i = 0; i < queueToCopy.numCapacity; i++) {
        queueToCopy.buffer[i]=i*i+1;
    }
    queue <int> queueAssignedCopy;
    queueAssignedCopy = queueToCopy;
    assertTrue(queueAssignedCopy.numCapacity == 8);
    assertTrue(queueAssignedCopy.numPush == 8);
    assertTrue(queueAssignedCopy.numPop == 0);
    assertTrue(queueAssignedCopy.buffer != queueToCopy.buffer);
    assertTrue(queueAssignedCopy.buffer[0] == 1);
    assertTrue(queueAssignedCopy.buffer[1] == 2);
    assertTrue(queueAssignedCopy.buffer[2] == 5);
    assertTrue(queueAssignedCopy.buffer[3] == 10);
    assertTrue(queueAssignedCopy.buffer[4] == 17);
    assertTrue(queueAssignedCopy.buffer[5] == 26);
    assertTrue(queueAssignedCopy.buffer[6] == 37);
    assertTrue(queueAssignedCopy.buffer[7] == 50);
    cout << "(full) = Operator Test Passed" << endl;
    
    queue <int> queueCopy(queueToCopy);
    assertTrue(queueCopy.numCapacity == 8);
    assertTrue(queueCopy.numPush == 8);
    assertTrue(queueCopy.numPop == 0);
    assertTrue(queueCopy.buffer != queueToCopy.buffer);
    assertTrue(queueCopy.numCapacity == 8);
    assertTrue(queueCopy.buffer[0] == 1);
    assertTrue(queueCopy.buffer[1] == 2);
    assertTrue(queueCopy.buffer[2] == 5);
    assertTrue(queueCopy.buffer[3] == 10);
    assertTrue(queueCopy.buffer[4] == 17);
    assertTrue(queueCopy.buffer[5] == 26);
    assertTrue(queueCopy.buffer[6] == 37);
    assertTrue(queueCopy.buffer[7] == 50);
    cout << "(Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Resetting to not full queue
     */
    
    queueToCopy.numPop = 5;
    
    queue <int> notFullQueueAssignedCopy;
    notFullQueueAssignedCopy = queueToCopy;
    assertTrue(notFullQueueAssignedCopy.numCapacity == 3);
    assertTrue(notFullQueueAssignedCopy.numPush == 3);
    assertTrue(notFullQueueAssignedCopy.numPop == 0);
    assertTrue(notFullQueueAssignedCopy.buffer != queueToCopy.buffer);
    assertTrue(notFullQueueAssignedCopy.buffer[0] == 26);
    assertTrue(notFullQueueAssignedCopy.buffer[1] == 37);
    assertTrue(notFullQueueAssignedCopy.buffer[2] == 50);
    cout << "(Not full) = Operator Test Passed" << endl;
    
    queue <int> notFullQueueCopy(queueToCopy);
    assertTrue(notFullQueueCopy.numCapacity == 3);
    assertTrue(notFullQueueCopy.numPush == 3);
    assertTrue(notFullQueueCopy.numPop == 0);
    assertTrue(notFullQueueCopy.buffer != queueToCopy.buffer);
    assertTrue(notFullQueueCopy.buffer[0] == 26);
    assertTrue(notFullQueueCopy.buffer[1] == 37);
    assertTrue(notFullQueueCopy.buffer[2] == 50);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    
    /*
     * Testing back
     */
    
    queue<int> frontBackQueue;
    frontBackQueue.numPush = 0;
    frontBackQueue.numPop = 0;
    frontBackQueue.numCapacity = 16;
    try{
        int& theBackRef = frontBackQueue.back();
        assertTrue(false);
    } catch(const char* message){
        assertTrue(strcmp(message, "Error: asking for back of empty queue.") == 0);
    }
    //simulating use
    frontBackQueue.buffer = new int[16];
    for (int i = 0; i < 16; i++) {
        frontBackQueue.buffer[i] = 2*i;
    }
    frontBackQueue.numPush = 8;
    frontBackQueue.numPop = 4;
    assertTrue(frontBackQueue.back() == 14);
    frontBackQueue.back() = 15;
    assertTrue(frontBackQueue.buffer[7] == 15);
    
    
    //reset queue
    frontBackQueue.buffer = new int[16];
    for (int i = 0; i < 16; i++) {
        frontBackQueue.buffer[i] = 2*i;
    }
    frontBackQueue.numPush = 0;
    frontBackQueue.numPop = 0;
    frontBackQueue.numCapacity = 16;
    /*
     * Testing front
     */
    try{
        int& theFrontRef = frontBackQueue.front();
        assertTrue(false);
    } catch(const char* message){
        assertTrue(strcmp(message, "Error: asking for front of empty queue.") == 0);
    }
    
    frontBackQueue.numPush = 8;
    frontBackQueue.numPop = 4;
    
    assertTrue(frontBackQueue.front() == 8);
    frontBackQueue.front() = 9;
    assertTrue(frontBackQueue.buffer[4] == 9);
    
    /*
     * Testing push for Non-Integer Queue Behavior (Just to Make Sure queue Works For Other Types)
     */
    queue <string> stringQueue;
    
    stringQueue.push("Hello");
    stringQueue.push("It's me");
    stringQueue.push("I was wondering");
    assertTrue(stringQueue.numCapacity == 4);
    assertTrue(stringQueue.buffer[0] == "Hello");
    assertTrue(stringQueue.buffer[1] == "It's me");
    assertTrue(stringQueue.buffer[2] == "I was wondering");
    
    cout << "This queue can hold strings!!!!" << endl;
    
    generateTestingReport();
    return 0;
}
