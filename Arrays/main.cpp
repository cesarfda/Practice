/*
 * main.cpp
 *
 *  Created by Lee Barney on 3/13/2019.
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
int asserts_existing = 76;

#include <iostream>
#include "array.h"
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
    array <int> defaultArray;
    assertTrue(defaultArray.buffer == NULL);
    assertTrue(defaultArray.numCapacity == 0);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing sized array constructor
     */
    try{
        array<int> badSizeArray(-3);
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: array sizes must be greater than zero.") == 0);
    }
    array<int> sizedArray(4);
    assertTrue(sizedArray.buffer != NULL);
    assertTrue(sizedArray.numCapacity == 4);
    cout << "Sized Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    array<int> sizeTestArray;
    
    sizeTestArray.numCapacity = 8;
    assertTrue(sizeTestArray.size() == 8);
    
    cout << "Size Tests Passed" << endl;
    /*
     * Testing Capacity
     */
    assertTrue(sizeTestArray.capacity() == 8);
    sizeTestArray.numCapacity = 0;
    assertTrue(sizeTestArray.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestArray.numCapacity = 8;
    
    assertTrue(!sizeTestArray.empty());
    
    sizeTestArray.numCapacity = 0;
    
    assertTrue(sizeTestArray.empty());
    cout << "Empty Tests Passed" << endl;
    
   
    
    /*
     * Testing copy constructor
     */
    array<int> copyTestArray;
    copyTestArray.numCapacity = 5;
    copyTestArray.buffer = new int[copyTestArray.numCapacity];
    copyTestArray.buffer[0] = 1;
    copyTestArray.buffer[1] = 5;
    copyTestArray.buffer[2] = 10;
    copyTestArray.buffer[3] = 0;
    copyTestArray.buffer[4] = -2;
   
    array<int> arrayCopy(copyTestArray);
    assertTrue(arrayCopy.numCapacity == copyTestArray.numCapacity);
    assertTrue(arrayCopy.buffer != copyTestArray.buffer);
    assertTrue(arrayCopy.buffer[0] == 1);
    assertTrue(arrayCopy.buffer[1] == 5);
    assertTrue(arrayCopy.buffer[2] == 10);
    assertTrue(arrayCopy.buffer[3] == 0);
    assertTrue(arrayCopy.buffer[4] == -2);
    cout << "Copy Constructor Test Passed" << endl;
    
    /*
     * Testing destructor
     */
    
    //resetting counter
    unit_testing_delete_call_counter = 0;
    array<int>* arrayToDestroy = new array<int>();
    delete arrayToDestroy;
    assertTrue(unit_testing_delete_call_counter == 1);
    
    //resetting counter
    unit_testing_delete_call_counter = 0;
    arrayToDestroy = new array<int>(4);
    delete arrayToDestroy;
    assertTrue(unit_testing_delete_call_counter == 1);
    
    
    //resetting counter
    unit_testing_delete_call_counter = 0;
    array<int>* filledArrayToDestroy = new array<int>(4);
    filledArrayToDestroy->buffer[0] = 3;
    filledArrayToDestroy->buffer[1] = 5;
    filledArrayToDestroy->buffer[2] = 7;
    filledArrayToDestroy->buffer[3] = 1;
    delete filledArrayToDestroy;
    assertTrue(unit_testing_delete_call_counter == 1);
    
    cout<<"Passed Array Destructor Tests"<<endl;
    /*
     * Testing = operator
     */
    array<int> arrayAssignedTo = copyTestArray;
    assertTrue(arrayAssignedTo.numCapacity == copyTestArray.numCapacity);
    assertTrue(arrayAssignedTo.buffer != copyTestArray.buffer);
    assertTrue(arrayAssignedTo.buffer[0] == 1);
    assertTrue(arrayAssignedTo.buffer[1] == 5);
    assertTrue(arrayAssignedTo.buffer[2] == 10);
    assertTrue(arrayAssignedTo.buffer[3] == 0);
    assertTrue(arrayAssignedTo.buffer[4] == -2);
    cout << "Assignment Operator = Test Passed" << endl;
    
    /*
     * Testing == operator
     */
    array<int> equalityTestArray;
    equalityTestArray.numCapacity = 5;
    equalityTestArray.buffer = new int[5];
    equalityTestArray.buffer[0] = 1;
    equalityTestArray.buffer[1] = 5;
    equalityTestArray.buffer[2] = 10;
    equalityTestArray.buffer[3] = 0;
    equalityTestArray.buffer[4] = -2;
    assertTrue(equalityTestArray == equalityTestArray);
    assertTrue(equalityTestArray == copyTestArray);
    
    array<int> notEqualTestArray;
    //testing differing capacities
    notEqualTestArray.numCapacity = 3;
    assertTrue(!(equalityTestArray == notEqualTestArray));
    notEqualTestArray.numCapacity = 10;
    assertTrue(!(equalityTestArray == notEqualTestArray));
    notEqualTestArray.numCapacity = INT_MAX;
    assertTrue(!(equalityTestArray == notEqualTestArray));
    
    //testing same capacity, different values
    notEqualTestArray.numCapacity = 5;
    //null buffer test
    assertTrue(!(equalityTestArray == notEqualTestArray));
    
    //last different
    notEqualTestArray.buffer = new int[notEqualTestArray.numCapacity];
    notEqualTestArray.buffer[0] = 1;
    notEqualTestArray.buffer[1] = 5;
    notEqualTestArray.buffer[2] = 10;
    notEqualTestArray.buffer[3] = 0;
    notEqualTestArray.buffer[4] = 3;
    assertTrue(!(equalityTestArray == notEqualTestArray));
    
    //first different
    notEqualTestArray.buffer = new int[notEqualTestArray.numCapacity];
    notEqualTestArray.buffer[0] = 7;
    notEqualTestArray.buffer[1] = 5;
    notEqualTestArray.buffer[2] = 10;
    notEqualTestArray.buffer[3] = 0;
    notEqualTestArray.buffer[4] = -2;
    assertTrue(!(equalityTestArray == notEqualTestArray));
    
    //all different
    notEqualTestArray.buffer = new int[notEqualTestArray.numCapacity];
    notEqualTestArray.buffer[0] = 8;
    notEqualTestArray.buffer[1] = 6;
    notEqualTestArray.buffer[2] = 9;
    notEqualTestArray.buffer[3] = -100;
    notEqualTestArray.buffer[4] = 54;
    assertTrue(!(equalityTestArray == notEqualTestArray));
    
    
    /*
     * Testing [] operator
     */
    
    array<int> randomAccessTestArray;
    try{
        //size zero and buffer NULL
        randomAccessTestArray[0];
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: index must be less than the capacity of the array.") == 0);
    }
    randomAccessTestArray.numCapacity = 5;
    randomAccessTestArray.buffer = new int[randomAccessTestArray.numCapacity];
    randomAccessTestArray.buffer[0] = 8;
    randomAccessTestArray.buffer[1] = 6;
    randomAccessTestArray.buffer[2] = 9;
    randomAccessTestArray.buffer[3] = -100;
    randomAccessTestArray.buffer[4] = 54;
    try{
        //invalid index
        randomAccessTestArray[-1];
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: index must be greater than or equal to zero.") == 0);
    }
    try{
        //invalid index
        randomAccessTestArray[5];
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: index must be less than the capacity of the array.") == 0);
    }
    try{
        //invalid index assignment
        randomAccessTestArray[6] = 13;
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: index must be less than the capacity of the array.") == 0);
    }
    //testing accessor operator
    const int fixedResult = randomAccessTestArray[4];
    assertTrue(fixedResult == randomAccessTestArray.buffer[4]);
    
    //testing mutator operator
    randomAccessTestArray[4] = 32;
    assertTrue(randomAccessTestArray.buffer[4] == 32);
    
    
    
    /*
     * Testing Iterator
     */
    
    int* aDataPointer = new int(3);
    
    //testing default constructor
    array<int>::iterator anIterator;
    assertTrue(anIterator.dataPtr == NULL);
    
    array<int>::iterator* iteratorPtr = new array<int>::iterator();
    assertTrue(iteratorPtr->dataPtr == NULL);
    
    //testing non-default constructor
    array<int>::iterator iteratorWithData(aDataPointer);
    assertTrue(aDataPointer == iteratorWithData.dataPtr);
    
    array<int>::iterator* iteratorWithDataPtr = new array<int>::iterator(aDataPointer);
    assertTrue(aDataPointer == iteratorWithDataPtr->dataPtr);
    
    cout<<"Passed Iterator Constructor Tests"<<endl;
    
    //testing copy constructor for default iterator
    array<int>::iterator iteratorToCopy;
    array<int>::iterator copiedIterator(iteratorToCopy);
    assertTrue(copiedIterator.dataPtr == NULL);
    assertTrue(copiedIterator.dataPtr == iteratorToCopy.dataPtr);
    
    //testing copy constructor iterator with data pointer
    iteratorToCopy.dataPtr = aDataPointer;
    array<int>::iterator copiedDataIterator(iteratorToCopy);
    assertTrue(copiedDataIterator.dataPtr == aDataPointer);
    
    cout<<"Passed Iterator Copy Constructor Tests"<<endl;
    
    //testing iterator destructor
    unit_testing_delete_call_counter = 0;
    delete iteratorPtr;
    assertTrue(unit_testing_delete_call_counter == 1);
    
    unit_testing_delete_call_counter = 0;
    delete iteratorWithDataPtr;
    assertTrue(unit_testing_delete_call_counter == 1);
    
    cout<<"Passed Iterator Destructor Tests"<<endl;
    
    /*
     * Testing iterator operators
     */
    
    //testing assignment operator
    array<int>::iterator iteratorToAssign;
    array<int>::iterator assignedToIterator = iteratorToAssign;
    assertTrue(assignedToIterator.dataPtr == NULL);
    assertTrue(assignedToIterator.dataPtr == iteratorToAssign.dataPtr);
    
    iteratorToAssign.dataPtr = aDataPointer;
    array<int>::iterator assignedToIteratorWithData(iteratorToAssign);
    assertTrue(assignedToIteratorWithData.dataPtr == aDataPointer);
    
    cout<<"Passed Iterator Assignment Operator Tests"<<endl;
    
    //testing iterator equality operator
    array<int>::iterator comparisonOperatorIterator;
    assertTrue(iteratorToAssign == iteratorToAssign);
    assertTrue(iteratorToAssign == assignedToIteratorWithData);
    assertTrue(!(comparisonOperatorIterator == iteratorToAssign));
    
    cout<<"Passed Equality Operator Tests"<<endl;
    
    //testing inequality operator
    assertTrue(comparisonOperatorIterator != iteratorToAssign);
    //reset
    int* someOtherDataPtr = new int(4);
    comparisonOperatorIterator.dataPtr = someOtherDataPtr;
    assertTrue(!(iteratorToAssign != assignedToIteratorWithData));
    cout<<"Passed Inequality operator Test."<<endl;
    /*
     * Testing Dereference Operator
     */
    array<int>::iterator nullIt;
    try {
        *nullIt;
        assertTrue(false);
    } catch(const char* exceptionMessage){
        assertTrue(strcmp(exceptionMessage,"Error: dereferencing null data in iterator.") == 0);
    }
    assertTrue(*comparisonOperatorIterator == 4);
    
    *comparisonOperatorIterator = 7;
    assertTrue(*(comparisonOperatorIterator.dataPtr) == 7);
    
    cout<<"Passed Dereference Operator Test."<<endl;
    /*
     * Testing iterator incrementor
     */
    assertTrue((nullIt++).dataPtr == NULL);
    assertTrue((++nullIt).dataPtr == NULL);
    
    array<int> incrementorTestArray;
    incrementorTestArray.buffer = new int[5];
    incrementorTestArray.buffer[0] = 1;
    incrementorTestArray.buffer[1] = -456;
    incrementorTestArray.buffer[2] = 2;
    incrementorTestArray.buffer[3] = 15;
    incrementorTestArray.buffer[4] = -3;
    //setting to the beginning of buffer
    array<int>::iterator fakeBeginIt = array<int>::iterator();
    fakeBeginIt.dataPtr = incrementorTestArray.buffer;
    
    assertTrue((fakeBeginIt++).dataPtr == incrementorTestArray.buffer);
    //reset
    fakeBeginIt.dataPtr = incrementorTestArray.buffer;
    assertTrue((++fakeBeginIt).dataPtr == incrementorTestArray.buffer+1);
    
    cout<<"Passed Pre and Post-increment ++ Test."<<endl;
    
    /*
     * Testing Array begin And end Methods
     */
    
    array<int> emptyArray;
    emptyArray.buffer = NULL;
    
    assertTrue(emptyArray.begin().dataPtr == NULL);
    assertTrue(emptyArray.end().dataPtr == NULL);
    
    
    array<int> beginEndTestArray;
    beginEndTestArray.numCapacity = 5;
    beginEndTestArray.buffer = new int[beginEndTestArray.numCapacity];
    beginEndTestArray.buffer[0] = 1;
    beginEndTestArray.buffer[1] = -456;
    beginEndTestArray.buffer[2] = 2;
    beginEndTestArray.buffer[3] = 15;
    beginEndTestArray.buffer[4] = -3;
    
    assertTrue(beginEndTestArray.begin().dataPtr != NULL);
    assertTrue(beginEndTestArray.begin().dataPtr == beginEndTestArray.buffer);
    assertTrue(beginEndTestArray.end().dataPtr == beginEndTestArray.buffer+5);
    cout<<"Passed Array Begin and End Tests"<<endl;
    
    
    /*
     * Testing assignment operator for Non-Integer Array Behavior (Just to Make Sure array Works For Other Types)
     */
    array<string> sString(3);
    
    sString[0]="Hello";
    sString[1]="It's me";
    sString[2]="I was wondering";
    assertTrue(sString.buffer[0].compare("Hello") == 0);
    assertTrue(sString.buffer[1].compare("It's me") == 0);
    assertTrue(sString.buffer[2].compare("I was wondering") == 0);
    //resetting counter
    unit_testing_delete_call_counter = 0;
    array<string>* stringArrayToDestroy = new array<string>(4);
    stringArrayToDestroy->buffer[0] = "bob";
    stringArrayToDestroy->buffer[1] = "sue";
    stringArrayToDestroy->buffer[2] = "sven";
    stringArrayToDestroy->buffer[3] = "jessie";
    stringArrayToDestroy->buffer[4] = "hymie";
    delete stringArrayToDestroy;
    assertTrue(unit_testing_delete_call_counter == 5);
    
    cout << "This array can hold strings!!!!" << endl;
    generateTestingReport();
    
    
    
    return 0;
}


