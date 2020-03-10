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
 * the percentage of asserts found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING
//Do not change the next line without instructor approval.
//To do so is cheating and, when found, will result in consequences.
int asserts_existing = 119;

#include <iostream>
#include "vector.h"
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
    vector <int> defaultVector;
    assertTrue(defaultVector.numCapacity == 0);
    assertTrue(defaultVector.numElements == 0);
    assertTrue(defaultVector.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing sized vector constructor
     */
    try{
        vector<int> badSizeVector(-3);
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: vector sizes must be greater than or equal to 0.") == 0);
    }
    
    vector <int> sizedVector(4);
    assertTrue(sizedVector.numCapacity == 4);
    assertTrue(sizedVector.numElements == 4);
    assertTrue(sizedVector.buffer != NULL);
    assertTrue(sizedVector.buffer[0] == 0);
    assertTrue(sizedVector.buffer[1] == 0);
    assertTrue(sizedVector.buffer[2] == 0);
    assertTrue(sizedVector.buffer[3] == 0);
    cout << "Sized Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    vector <int> sizeTestVector;
    
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 4;
    assertTrue(sizeTestVector.size() == 4);
    cout << "Size Tests Passed" << endl;
    
    /*
     * Testing Capacity
     */
    assertTrue(sizeTestVector.capacity() == 8);
    sizeTestVector.numCapacity = 0;
    assertTrue(sizeTestVector.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    
    /*
     * Resetting for further use
     */
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 0;
    sizeTestVector.buffer = new int[sizeTestVector.numCapacity];
    for (int i = 0; i < sizeTestVector.numCapacity; i++) {
        sizeTestVector.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestVector.clear();
    assertTrue(sizeTestVector.numCapacity == 8);
    assertTrue(sizeTestVector.numElements == 0);
    assertTrue(sizeTestVector.buffer != NULL);
    cout << "Clear Test Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestVector.numElements = 3;
    assertTrue(!sizeTestVector.empty());
    
    sizeTestVector.numElements = 0;
    
    assertTrue(sizeTestVector.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing resize
     */
    vector<int> emptyResizeVector;
    emptyResizeVector.resize(-1);
    assertTrue(emptyResizeVector.numCapacity == 0);
    assertTrue(emptyResizeVector.numElements == 0);
    assertTrue(emptyResizeVector.buffer == NULL);
    cout<<"Passed negative resize test."<<endl;
    
    emptyResizeVector.resize(7);
    assertTrue(emptyResizeVector.numCapacity == 7);
    assertTrue(emptyResizeVector.numElements == 0);
    assertTrue(emptyResizeVector.buffer != NULL);
    cout<<"Passed default vector resized test."<<endl;
    
    vector <int> resizeVector;
    resizeVector.buffer = new int[5];
    resizeVector.numCapacity = 5;
    resizeVector.numElements = 5;
    resizeVector.buffer[0] = 7;
    resizeVector.buffer[1] = 12;
    resizeVector.buffer[2] = 10;
    resizeVector.buffer[3] = 9;
    resizeVector.buffer[4] = 8;
    
    int *theBuffer = resizeVector.buffer;
    resizeVector.resize(10);
    assertTrue(theBuffer != resizeVector.buffer);
    assertTrue(resizeVector.numCapacity == 10);
    assertTrue(resizeVector.numElements == 5);
    assertTrue(resizeVector.buffer[0] == 7);
    assertTrue(resizeVector.buffer[1] == 12);
    assertTrue(resizeVector.buffer[2] == 10);
    assertTrue(resizeVector.buffer[3] == 9);
    assertTrue(resizeVector.buffer[4] == 8);
    
    theBuffer = resizeVector.buffer;
    resizeVector.resize(2);
    assertTrue(theBuffer != resizeVector.buffer);
    assertTrue(resizeVector.numCapacity == 2);
    assertTrue(resizeVector.numElements == 2);
    assertTrue(resizeVector.buffer[0] == 7);
    assertTrue(resizeVector.buffer[1] == 12);
    
    theBuffer = resizeVector.buffer;
    resizeVector.resize(0);
    assertTrue(resizeVector.numCapacity == 0);
    assertTrue(resizeVector.numElements == 0);
    assertTrue(resizeVector.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    
    
    /*
     * Testing push_back with no resizing
     */
    vector <int> pushBackVector(5);
    int * tempBuffer = pushBackVector.buffer;
    pushBackVector.push_back(1);
    assertTrue(tempBuffer != pushBackVector.buffer);
    assertTrue(pushBackVector.numCapacity == 10);
    assertTrue(pushBackVector.numElements == 6);
    assertTrue(pushBackVector.buffer[0] == 0);
    assertTrue(pushBackVector.buffer[1] == 0);
    assertTrue(pushBackVector.buffer[2] == 0);
    assertTrue(pushBackVector.buffer[3] == 0);
    assertTrue(pushBackVector.buffer[4] == 0);
    assertTrue(pushBackVector.buffer[5] == 1);
    cout << "Push_back First ElementTest Passed" << endl;
    
    pushBackVector.push_back(3);
    assertTrue(pushBackVector.numCapacity == 10);
    assertTrue(pushBackVector.numElements == 7);
    assertTrue(pushBackVector.buffer[0] == 0);
    assertTrue(pushBackVector.buffer[1] == 0);
    assertTrue(pushBackVector.buffer[2] == 0);
    assertTrue(pushBackVector.buffer[3] == 0);
    assertTrue(pushBackVector.buffer[4] == 0);
    assertTrue(pushBackVector.buffer[5] == 1);
    assertTrue(pushBackVector.buffer[6] == 3);
    
    
    
    
    /*
     * Testing Accessor
     */
    vector <int> beginEndVector;
    beginEndVector.buffer = new int[6];
    beginEndVector.buffer[0] = -500;
    beginEndVector.buffer[1] = 0;
    beginEndVector.buffer[2] = 7;
    beginEndVector.buffer[3] = 13;
    beginEndVector.buffer[4] = 23;
    beginEndVector.numCapacity = 6;
    beginEndVector.numElements = 5;
    
    //test accessor
    assertTrue(beginEndVector[0] == -500);
    //test mutator
    beginEndVector[0] = 35;
    assertTrue(beginEndVector.buffer[0] == 35);
    
    try{
        beginEndVector[-1];
        assertTrue(false);
    } catch (const char * message) {
        assertTrue(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    
    try{
        beginEndVector[6];
        assertTrue(false);
    } catch (const char * message) {
        assertTrue(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    
    vector <int> emptyVector;
    try{
        emptyVector[0];
        assertTrue(false);
    } catch (const char* message) {
        assertTrue(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    cout << "Accessor tests passed"<<endl;
    
    
    
    /*
     * Testing = operator and copy constructor
     */
    vector <int> vectorToCopy;
    vectorToCopy.numCapacity = 8;
    vectorToCopy.numElements = 8;
    vectorToCopy.buffer = new int[vectorToCopy.numCapacity];
    for (int i = 0; i < vectorToCopy.numCapacity; i++) {
        vectorToCopy.buffer[i]=i*i+1;
    }
    vector <int> vectorAssignedCopy;
    vectorAssignedCopy = vectorToCopy;
    assertTrue(vectorAssignedCopy.numCapacity == 8);
    assertTrue(vectorAssignedCopy.numElements == 8);
    assertTrue(vectorAssignedCopy.buffer != vectorToCopy.buffer);
    assertTrue(vectorAssignedCopy.buffer[0] == 1);
    assertTrue(vectorAssignedCopy.buffer[1] == 2);
    assertTrue(vectorAssignedCopy.buffer[2] == 5);
    assertTrue(vectorAssignedCopy.buffer[3] == 10);
    assertTrue(vectorAssignedCopy.buffer[4] == 17);
    assertTrue(vectorAssignedCopy.buffer[5] == 26);
    assertTrue(vectorAssignedCopy.buffer[6] == 37);
    assertTrue(vectorAssignedCopy.buffer[7] == 50);
    cout << "(full) = Operator Test Passed" << endl;
    
    vector <int> vectorCopy(vectorToCopy);
    assertTrue(vectorCopy.numCapacity == 8);
    assertTrue(vectorCopy.numElements == 8);
    assertTrue(vectorCopy.buffer != vectorToCopy.buffer);
    assertTrue(vectorCopy.numCapacity == 8);
    assertTrue(vectorCopy.buffer[0] == 1);
    assertTrue(vectorCopy.buffer[1] == 2);
    assertTrue(vectorCopy.buffer[2] == 5);
    assertTrue(vectorCopy.buffer[3] == 10);
    assertTrue(vectorCopy.buffer[4] == 17);
    assertTrue(vectorCopy.buffer[5] == 26);
    assertTrue(vectorCopy.buffer[6] == 37);
    assertTrue(vectorCopy.buffer[7] == 50);
    cout << "(Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Resetting to not full vector
     */
    
    vectorToCopy.numElements = 3;
    
    vector <int> notFullVectorAssignedCopy;
    notFullVectorAssignedCopy = vectorToCopy;
    assertTrue(notFullVectorAssignedCopy.numCapacity == 3);
    assertTrue(notFullVectorAssignedCopy.numElements == 3);
    assertTrue(notFullVectorAssignedCopy.buffer != vectorToCopy.buffer);
    assertTrue(notFullVectorAssignedCopy.buffer[0] == 1);
    assertTrue(notFullVectorAssignedCopy.buffer[1] == 2);
    assertTrue(notFullVectorAssignedCopy.buffer[2] == 5);
    cout << "(Not full) = Operator Test Passed" << endl;
    
    vector <int> notFullVectorCopy(vectorToCopy);
    assertTrue(notFullVectorCopy.numCapacity == 3);
    assertTrue(notFullVectorCopy.numElements == 3);
    assertTrue(notFullVectorCopy.buffer != vectorToCopy.buffer);
    assertTrue(notFullVectorCopy.buffer[0] == 1);
    assertTrue(notFullVectorCopy.buffer[1] == 2);
    assertTrue(notFullVectorCopy.buffer[2] == 5);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Testing Raw Iterators
     */
    vector<int>::iterator nullIt = vector<int>::iterator();
    assertTrue(nullIt.ptr == NULL);
    int someInt = 3;
    int *someIntPtr = &someInt;
    vector<int>::iterator intPtr = vector<int>::iterator(&someInt);
    assertTrue(intPtr.ptr == someIntPtr);
    
    cout<<"Passed Raw Iterator Test."<<endl;
    
    /*
     * Testing begin and end
     */
    vector<int>::iterator emptyVectorBeginIt = emptyVector.begin();
    assertTrue(emptyVectorBeginIt.ptr == NULL);
    
    
    vector<int>::iterator emptyVectorEndIt = emptyVector.end();
    assertTrue(emptyVectorEndIt.ptr == NULL);
    
    vector<int>::iterator notFullVectorBeginIt = notFullVectorCopy.begin();
    assertTrue(notFullVectorCopy.buffer == notFullVectorBeginIt.ptr);
    
    
    vector<int>::iterator notFullVectorEndIt = notFullVectorCopy.end();
    assertTrue(notFullVectorCopy.buffer+notFullVectorCopy.numElements == notFullVectorEndIt.ptr);
    cout<<"Passed iterator begin and end test."<<endl;
    
    /*
     * Testing Iterator Assignment Operator
     */
    vector<int>::iterator iteratorToAssign;
    iteratorToAssign.ptr = someIntPtr;
    vector<int>::iterator assignedToIterator;
    assignedToIterator = iteratorToAssign;
    assertTrue(assignedToIterator.ptr == someIntPtr);
    cout<<"Passed iterator assignment test."<<endl;
    
    /*
     * Testing Iterator Comparison Operators
     */
    assertTrue(iteratorToAssign == assignedToIterator);
    //reset
    int someOtherInt = 4;
    int* someOtherIntPtr = &someOtherInt;
    assignedToIterator.ptr = someOtherIntPtr;
    assertTrue(iteratorToAssign != assignedToIterator);
    cout<<"Passed comparison operators test."<<endl;
    /*
     * Testing Dereference Operator
     */
    assertTrue(*assignedToIterator == 4);
    cout<<"Passed dereference operator test."<<endl;
    /*
     * Testing iterator incrementor
     */
    assertTrue((nullIt++).ptr == NULL);
    assertTrue((++nullIt).ptr == NULL);
    
    //setting to the beginning of buffer
    vector<int>::iterator fakeBeginIt = vector<int>::iterator();
    fakeBeginIt.ptr = notFullVectorCopy.buffer;
    
    assertTrue((fakeBeginIt++).ptr == notFullVectorCopy.buffer);
    //reset
    fakeBeginIt.ptr = notFullVectorCopy.buffer;
    assertTrue((++fakeBeginIt).ptr == notFullVectorCopy.buffer+1);
    
    cout<<"Passed pre and post-increment ++ test."<<endl;
    
    //setting to the end of buffer
    vector<int>::iterator fakeEndIt = vector<int>::iterator();
    fakeEndIt.ptr = notFullVectorCopy.buffer+notFullVectorCopy.numElements;
    assertTrue((fakeEndIt--).ptr == notFullVectorCopy.buffer+notFullVectorCopy.numElements);
    //reset
    fakeEndIt.ptr = notFullVectorCopy.buffer+notFullVectorCopy.numElements;
    assertTrue((--fakeEndIt).ptr == notFullVectorCopy.buffer+notFullVectorCopy.numElements - 1);
    
    cout<<"Passed pre and post-increment -- test."<<endl;
    
    
    
    
    
    /*
     * Testing push_back for Non-Integer Vector Behavior (Just to Make Sure vector Works For Other Types)
     */
    vector <string> stringVector;
    
    stringVector.push_back("Hello");
    stringVector.push_back("It's me");
    stringVector.push_back("I was wondering");
    assertTrue(stringVector.numCapacity == 4);
    assertTrue(stringVector.buffer[0] == "Hello");
    assertTrue(stringVector.buffer[1] == "It's me");
    assertTrue(stringVector.buffer[2] == "I was wondering");
    
    cout << "This vector can hold strings!!!!" << endl;
    
    generateTestingReport();
    
    return 0;
}
