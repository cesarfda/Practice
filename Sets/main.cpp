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
int asserts_existing = 358;

#include <iostream>
#include "set.h"
#include "../unit_testing.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

/*
 * While set can be implemented either sorted
 * or not sorted, for this class, you are
 * required to implement the sorted design.
 */

int main(int argc, const char* argv[])
{
    
    /*
     * Testing default constructor
     */
    set <int> defaultset;
    assertTrue(defaultset.numCapacity == 0);
    assertTrue(defaultset.numElements == 0);
    assertTrue(defaultset.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing sized set constructor
     */
    try{
        set<int> badSizeset(-3);
        assertTrue(false);
    } catch(const char* exceptionMessage)
    {
        assertTrue(strcmp(exceptionMessage,"Error: set sizes must be greater than or equal to 0.") == 0);
    }
    
    set <int> sizedset(4);
    assertTrue(sizedset.numCapacity == 4);
    assertTrue(sizedset.numElements == 0);
    assertTrue(sizedset.buffer != NULL);
    cout << "Sized Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    set <int> sizeTestset;
    
    sizeTestset.numCapacity = 8;
    sizeTestset.numElements = 4;
    assertTrue(sizeTestset.size() == 4);
    cout << "Size Tests Passed" << endl;
    
    /*
     * Resetting for further use
     */
    sizeTestset.numCapacity = 8;
    sizeTestset.numElements = 8;
    sizeTestset.buffer = new int[sizeTestset.numCapacity];
    for (int i = 0; i < sizeTestset.numCapacity; i++)
    {
        sizeTestset.buffer[i]=i*i+1;
    }
    //buffer: [1,2,5,10,17,26,50,65]
    /*
     * Testing Clear
     */
    sizeTestset.clear();
    assertTrue(sizeTestset.numCapacity == 8);
    assertTrue(sizeTestset.numElements == 0);
    assertTrue(sizeTestset.buffer != NULL);
    cout << "Clear Test Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestset.numElements = 3;
    assertTrue(!sizeTestset.empty());
    
    sizeTestset.numElements = 0;
    
    assertTrue(sizeTestset.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing insert with no resizing
     */
    set <int> insertset;
    insertset.buffer = new int[5];
    insertset.numCapacity = 5;
    insertset.numElements = 0;
    
    int * tempBuffer = insertset.buffer;
    insertset.insert(3);
    assertTrue(tempBuffer == insertset.buffer);
    assertTrue(insertset.numCapacity == 5);
    assertTrue(insertset.numElements == 1);
    assertTrue(insertset.buffer[0] == 3);
    cout << "Insert First Element Test Passed" << endl;
    
    //make sure inserting a duplicate makes no changes to the end result.
    insertset.insert(3);
    assertTrue(insertset.numCapacity == 5);
    assertTrue(insertset.numElements == 1);
    assertTrue(insertset.buffer[0] == 3);
    cout << "Insert Second Element Test Passed" << endl;
    
    
    insertset.insert(7);
    assertTrue(insertset.numCapacity == 5);
    assertTrue(insertset.numElements == 2);
    assertTrue(insertset.buffer[0] == 3);
    assertTrue(insertset.buffer[1] == 7);
    cout << "Insert Third Element Test Passed" << endl;
    
    
    insertset.insert(-5);
    assertTrue(insertset.numCapacity == 5);
    assertTrue(insertset.numElements == 3);
    assertTrue(insertset.buffer[0] == -5);
    assertTrue(insertset.buffer[1] == 3);
    assertTrue(insertset.buffer[2] == 7);
    
    cout<<"Passed insert no-resize Tests"<<endl;
    
    
    
    /*
     * Testing FindIndex
     */
    set<int> findIndexSet;
    //testing find with empty set
    findIndexSet.numElements = 0;
    findIndexSet.numCapacity = 0;
    findIndexSet.buffer = NULL;
    assertTrue(findIndexSet.findIndex(35) == 0);
    
    //resetting
    findIndexSet.numElements = 3;
    findIndexSet.numCapacity = 4;
    findIndexSet.buffer = new int[4];
    findIndexSet.buffer[0] = 2;
    findIndexSet.buffer[1] = 4;
    findIndexSet.buffer[2] = 8;
    //buffer - [2,4,8]
    //Testing happy paths
    assertTrue(findIndexSet.findIndex(8) == 2);
    assertTrue(findIndexSet.findIndex(2) == 0);
    assertTrue(findIndexSet.findIndex(4) == 1);
    //Testing not found. Indicates where the element should be inserted when not found.
    assertTrue(findIndexSet.findIndex(5) == 2);
    assertTrue(findIndexSet.findIndex(27) == 3);
    assertTrue(findIndexSet.findIndex(0) == 0);
    assertTrue(findIndexSet.findIndex(-100) == 0);
    cout<<"findIndex Test Passed."<<endl;
    
    
    
    
    
    /*
     * Testing Raw Iterators
     */
    set<int>::iterator nullIt = set<int>::iterator();
    assertTrue(nullIt.ptr == NULL);
    int someInt = 3;
    int *someIntPtr = &someInt;
    set<int>::iterator intPtr = set<int>::iterator(&someInt);
    assertTrue(intPtr.ptr == someIntPtr);
    
    cout<<"Passed Raw Iterator Test."<<endl;
    
    /*
     * Testing Iterator Assignment Operator
     */
    set<int>::iterator iteratorToAssign;
    iteratorToAssign.ptr = someIntPtr;
    set<int>::iterator assignedToIterator;
    assignedToIterator = iteratorToAssign;
    assertTrue(assignedToIterator.ptr == someIntPtr);
    cout<<"Passed iterator assignment test."<<endl;
    
    /*
     * Testing Iterator Comparison Operators
     */
    
    //reset
    int someOtherInt = 4;
    int* someOtherIntPtr = &someOtherInt;
    assignedToIterator.ptr = someOtherIntPtr;
    
    set<int>::iterator duplicateValueIterator;
    duplicateValueIterator.ptr = someIntPtr;
    
    
    assertTrue(iteratorToAssign == duplicateValueIterator);
    assertTrue(!(assignedToIterator == iteratorToAssign));
    
    cout<<"Passed operator == test."<<endl;
    
    assertTrue(iteratorToAssign != assignedToIterator);
    assertTrue(!(iteratorToAssign != duplicateValueIterator));
    cout<<"Passed operator != test."<<endl;
    /*
     * Testing Dereference Operator
     */
    assertTrue(*assignedToIterator == 4);
    cout<<"Passed dereference operator test."<<endl;
    /*
     * Testing iterator incrementor
     */
    nullIt.ptr = NULL;
    assertTrue((nullIt++).ptr == NULL);
    assertTrue((++nullIt).ptr == NULL);
    
    set<int> incrementTesterSet;
    incrementTesterSet.buffer = new int[3];
    //setting to the beginning of buffer
    set<int>::iterator fakeBeginIt = set<int>::iterator();
    fakeBeginIt.ptr = incrementTesterSet.buffer;
    
    assertTrue((fakeBeginIt++).ptr == incrementTesterSet.buffer);
    //reset
    fakeBeginIt.ptr = incrementTesterSet.buffer;
    assertTrue((++fakeBeginIt).ptr == incrementTesterSet.buffer+1);
    
    cout<<"Passed pre and post-increment ++ test."<<endl;
    
    incrementTesterSet.buffer = new int[8];
    incrementTesterSet.numCapacity = 8;
    incrementTesterSet.numElements = 5;
    incrementTesterSet.buffer[0] = 6;
    incrementTesterSet.buffer[1] = 4;
    incrementTesterSet.buffer[2] = -3;
    incrementTesterSet.buffer[3] = 2;
    incrementTesterSet.buffer[4] = 0;
    //buffer: [6,4,-3,2,0]
    //setting to the end of buffer
    set<int>::iterator fakeEndIt = set<int>::iterator();
    fakeEndIt.ptr = incrementTesterSet.buffer+incrementTesterSet.numElements;
    assertTrue((fakeEndIt--).ptr == incrementTesterSet.buffer+incrementTesterSet.numElements);
    //reset
    fakeEndIt.ptr = incrementTesterSet.buffer+incrementTesterSet.numElements;
    assertTrue((--fakeEndIt).ptr == incrementTesterSet.buffer+incrementTesterSet.numElements - 1);
    cout<<"Passed pre and post-increment -- test."<<endl;
    
    /**
     - ToDo: Move union, intersection, and difference to be tested after
     resize() since they use resize.
     */
    
    /*
     * Testing union operator
     */
    set<int>shortSet;
    shortSet.numCapacity = 0;
    shortSet.numElements = 0;
    shortSet.buffer = NULL;
    
    set<int>longSet;
    longSet.numCapacity = 0;
    longSet.numElements = 0;
    longSet.buffer = NULL;
    
    //testing union empty sets is empty set
    assertTrue((shortSet || longSet).numCapacity == 0);
    assertTrue((shortSet || longSet).numElements == 0);
    assertTrue((shortSet || longSet).buffer == NULL);
    cout<<"Passed empty set union test."<<endl;
    
    //testing union empty set with filled buffer set
    longSet.buffer = new int[10];
    longSet.numCapacity = 10;
    longSet.numElements = 10;
    longSet.buffer[0] = 3;
    longSet.buffer[1] = 4;
    longSet.buffer[2] = 5;
    longSet.buffer[3] = 6;
    longSet.buffer[4] = 7;
    longSet.buffer[5] = 8;
    longSet.buffer[6] = 9;
    longSet.buffer[7] = 10;
    longSet.buffer[8] = 11;
    longSet.buffer[9] = 12;
    
    assertTrue((shortSet || longSet).numCapacity == 10);
    assertTrue((shortSet || longSet).numElements == 10);
    assertTrue((shortSet || longSet).buffer != NULL);
    assertTrue((shortSet || longSet).buffer != longSet.buffer);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer);
    assertTrue((shortSet || longSet).buffer[0] == 3);
    assertTrue((shortSet || longSet).buffer[1] == 4);
    assertTrue((shortSet || longSet).buffer[2] == 5);
    assertTrue((shortSet || longSet).buffer[3] == 6);
    assertTrue((shortSet || longSet).buffer[4] == 7);
    assertTrue((shortSet || longSet).buffer[5] == 8);
    assertTrue((shortSet || longSet).buffer[6] == 9);
    assertTrue((shortSet || longSet).buffer[7] == 10);
    assertTrue((shortSet || longSet).buffer[8] == 11);
    assertTrue((shortSet || longSet).buffer[9] == 12);
    
    //testing union empty set with partially filled buffer set
    //reset longSet
    longSet.numElements = 3;
    assertTrue((shortSet || longSet).numCapacity == 3);
    assertTrue((shortSet || longSet).numElements == 3);
    assertTrue((shortSet || longSet).buffer != NULL);
    assertTrue((shortSet || longSet).buffer != longSet.buffer);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer);
    assertTrue((shortSet || longSet).buffer[0] == 3);
    assertTrue((shortSet || longSet).buffer[1] == 4);
    assertTrue((shortSet || longSet).buffer[2] == 5);
    
    //testing union partially filled buffer set with full buffer
    //reset longSet
    longSet.numElements = 3;
    //reset shortSet
    shortSet.buffer = new int[5];
    shortSet.numCapacity = 5;
    shortSet.numElements = 5;
    shortSet.buffer[0] = 5;
    shortSet.buffer[1] = 6;
    shortSet.buffer[2] = 7;
    shortSet.buffer[3] = 8;
    shortSet.buffer[4] = 9;
    
    assertTrue((shortSet || longSet).numCapacity == 7);
    assertTrue((shortSet || longSet).numElements == 7);
    assertTrue((shortSet || longSet).buffer != NULL);
    assertTrue((shortSet || longSet).buffer != longSet.buffer);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer);
    assertTrue((shortSet || longSet).buffer[0] == 3);
    assertTrue((shortSet || longSet).buffer[1] == 4);
    assertTrue((shortSet || longSet).buffer[2] == 5);
    assertTrue((shortSet || longSet).buffer[3] == 6);
    assertTrue((shortSet || longSet).buffer[4] == 7);
    assertTrue((shortSet || longSet).buffer[5] == 8);
    assertTrue((shortSet || longSet).buffer[6] == 9);
    
    //testing union two full sets -- no elements in common
    //resetting longSet
    longSet.numElements = 10;
    shortSet.buffer = new int[6];
    shortSet.numCapacity = 6;
    shortSet.numElements = 6;
    shortSet.buffer[0] = -6;
    shortSet.buffer[1] = -5;
    shortSet.buffer[2] = -4;
    shortSet.buffer[3] = -3;
    shortSet.buffer[4] = -2;
    shortSet.buffer[5] = -1;
    assertTrue((shortSet || longSet).numCapacity == 16);
    assertTrue((shortSet || longSet).numElements == 16);
    assertTrue((shortSet || longSet).buffer != NULL);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer);
    assertTrue((shortSet || longSet).buffer != longSet.buffer);
    assertTrue((shortSet || longSet).buffer[0] == -6);
    assertTrue((shortSet || longSet).buffer[1] == -5);
    assertTrue((shortSet || longSet).buffer[2] == -4);
    assertTrue((shortSet || longSet).buffer[3] == -3);
    assertTrue((shortSet || longSet).buffer[4] == -2);
    assertTrue((shortSet || longSet).buffer[5] == -1);
    assertTrue((shortSet || longSet).buffer[6] == 3);
    assertTrue((shortSet || longSet).buffer[7] == 4);
    assertTrue((shortSet || longSet).buffer[8] == 5);
    assertTrue((shortSet || longSet).buffer[9] == 6);
    assertTrue((shortSet || longSet).buffer[10] == 7);
    assertTrue((shortSet || longSet).buffer[11] == 8);
    assertTrue((shortSet || longSet).buffer[12] == 9);
    assertTrue((shortSet || longSet).buffer[13] == 10);
    assertTrue((shortSet || longSet).buffer[14] == 11);
    assertTrue((shortSet || longSet).buffer[15] == 12);
    
    //testing union two full sets all of short found in long
    //resetting short set
    shortSet.buffer[0] = 5;
    shortSet.buffer[1] = 7;
    shortSet.buffer[2] = 8;
    shortSet.buffer[3] = 9;
    shortSet.buffer[4] = 10;
    shortSet.buffer[5] = 11;
    
    assertTrue((shortSet || longSet).numCapacity == 10);
    assertTrue((shortSet || longSet).numElements == 10);
    assertTrue((shortSet || longSet).buffer != NULL);
    assertTrue((shortSet || longSet).buffer != longSet.buffer);
    assertTrue((shortSet || longSet).buffer != shortSet.buffer);
    assertTrue((shortSet || longSet).buffer[0] == 3);
    assertTrue((shortSet || longSet).buffer[1] == 4);
    assertTrue((shortSet || longSet).buffer[2] == 5);
    assertTrue((shortSet || longSet).buffer[3] == 6);
    assertTrue((shortSet || longSet).buffer[4] == 7);
    assertTrue((shortSet || longSet).buffer[5] == 8);
    assertTrue((shortSet || longSet).buffer[6] == 9);
    assertTrue((shortSet || longSet).buffer[7] == 10);
    assertTrue((shortSet || longSet).buffer[8] == 11);
    assertTrue((shortSet || longSet).buffer[9] == 12);
    
    //testing union with itself
    assertTrue((longSet || longSet).numCapacity == 10);
    assertTrue((longSet || longSet).numElements == 10);
    assertTrue((longSet || longSet).buffer != NULL);
    assertTrue((longSet || longSet).buffer != longSet.buffer);
    assertTrue((longSet || longSet).buffer[0] == 3);
    assertTrue((longSet || longSet).buffer[1] == 4);
    assertTrue((longSet || longSet).buffer[2] == 5);
    assertTrue((longSet || longSet).buffer[3] == 6);
    assertTrue((longSet || longSet).buffer[4] == 7);
    assertTrue((longSet || longSet).buffer[5] == 8);
    assertTrue((longSet || longSet).buffer[6] == 9);
    assertTrue((longSet || longSet).buffer[7] == 10);
    assertTrue((longSet || longSet).buffer[8] == 11);
    assertTrue((longSet || longSet).buffer[9] == 12);
    
    /**
     - ToDo: test partial and partial together.
     */
    
    /**
     - ToDo: test returning empty.
     */
    cout<<"Passed Union Tests."<<endl;
    
    /*
     * Testing Intersection
     */
    //resetting shortSet
    shortSet.buffer = NULL;
    shortSet.numCapacity = 0;
    shortSet.numElements = 0;
    
    //resetting longSet
    longSet.buffer = NULL;
    longSet.numCapacity = 0;
    longSet.numElements = 0;
    //testing intersection of empty sets
    
    assertTrue((shortSet && longSet).numCapacity == 0);
    assertTrue((shortSet && longSet).numElements == 0);
    assertTrue((shortSet && longSet).buffer == NULL);
    
    //resetting longSet
    longSet.buffer = new int[10];
    longSet.numCapacity = 10;
    longSet.numElements = 10;
    longSet.buffer[0] = 3;
    longSet.buffer[1] = 4;
    longSet.buffer[2] = 5;
    longSet.buffer[3] = 6;
    longSet.buffer[4] = 7;
    longSet.buffer[5] = 8;
    longSet.buffer[6] = 9;
    longSet.buffer[7] = 10;
    longSet.buffer[8] = 11;
    longSet.buffer[9] = 12;
    
    //testing intersection of empty set and non-empty set
    assertTrue((shortSet && longSet).numCapacity == 0);
    assertTrue((shortSet && longSet).numElements == 0);
    assertTrue((shortSet && longSet).buffer == NULL);
    
    //resetting shortSet
    shortSet.buffer = new int[6];
    shortSet.numCapacity = 6;
    shortSet.numElements = 6;
    shortSet.buffer[0] = -6;
    shortSet.buffer[1] = -5;
    shortSet.buffer[2] = -4;
    shortSet.buffer[3] = -3;
    shortSet.buffer[4] = -2;
    shortSet.buffer[5] = -1;
    
    //testing intersection nothing in common
    assertTrue((shortSet && longSet).numCapacity == 0);
    assertTrue((shortSet && longSet).numElements == 0);
    assertTrue((shortSet && longSet).buffer == NULL);
    
    
    //resetting shortSet
    shortSet.buffer[0] = 5;
    shortSet.buffer[1] = 7;
    shortSet.buffer[2] = 8;
    shortSet.buffer[3] = 9;
    shortSet.buffer[4] = 10;
    shortSet.buffer[5] = 11;
    
    //testing intersection all short set in common
    assertTrue((shortSet && longSet).numCapacity == 6);
    assertTrue((shortSet && longSet).numElements == 6);
    assertTrue((shortSet && longSet).buffer != NULL);
    assertTrue((shortSet && longSet).buffer != shortSet.buffer);
    assertTrue((shortSet && longSet).buffer != longSet.buffer);
    assertTrue((shortSet && longSet).buffer[0] == 5);
    assertTrue((shortSet && longSet).buffer[1] == 7);
    assertTrue((shortSet && longSet).buffer[2] == 8);
    assertTrue((shortSet && longSet).buffer[3] == 9);
    assertTrue((shortSet && longSet).buffer[4] == 10);
    assertTrue((shortSet && longSet).buffer[5] == 11);
    
    //resetting shortSet
    shortSet.buffer[3] = 70;
    shortSet.buffer[4] = 121;
    shortSet.buffer[5] = 1273;
    
    
    //testing intersection some elements in common
    assertTrue((shortSet && longSet).numCapacity == 3);
    assertTrue((shortSet && longSet).numElements == 3);
    assertTrue((shortSet && longSet).buffer != NULL);
    assertTrue((shortSet && longSet).buffer != shortSet.buffer);
    assertTrue((shortSet && longSet).buffer != longSet.buffer);
    assertTrue((shortSet && longSet).buffer[0] == 5);
    assertTrue((shortSet && longSet).buffer[1] == 7);
    cout<<"Passed Intersection Tests."<<endl;
    
    /*
     * Testing Difference
     */
    
    //resetting shortSet
    shortSet.numCapacity = 0;
    shortSet.numElements = 0;
    shortSet.buffer = NULL;
    //resetting longSet
    longSet.numCapacity = 0;
    longSet.numElements = 0;
    longSet.buffer = NULL;
    
    //testing difference empty sets both directions
    
    assertTrue((shortSet - longSet).numCapacity == 0);
    assertTrue((shortSet - longSet).numElements == 0);
    assertTrue((shortSet - longSet).buffer == NULL);
    
    assertTrue((longSet - shortSet).numCapacity == 0);
    assertTrue((longSet - shortSet).numElements == 0);
    assertTrue((longSet - shortSet).buffer == NULL);
    
    //resetting longSet
    longSet.buffer = new int[10];
    longSet.numCapacity = 10;
    longSet.numElements = 10;
    longSet.buffer[0] = 3;
    longSet.buffer[1] = 4;
    longSet.buffer[2] = 5;
    longSet.buffer[3] = 6;
    longSet.buffer[4] = 7;
    longSet.buffer[5] = 8;
    longSet.buffer[6] = 9;
    longSet.buffer[7] = 10;
    longSet.buffer[8] = 11;
    longSet.buffer[9] = 12;
    
    //testing one set empty difference both ways
    
    assertTrue((shortSet - longSet).numCapacity == 0);
    assertTrue((shortSet - longSet).numElements == 0);
    assertTrue((shortSet - longSet).buffer == NULL);
    
    assertTrue((longSet - shortSet).numCapacity == 10);
    assertTrue((longSet - shortSet).numElements == 10);
    assertTrue((longSet - shortSet).buffer != NULL);
    assertTrue((longSet - shortSet).buffer != longSet.buffer);
    assertTrue((longSet - shortSet).buffer[0] == 3);
    assertTrue((longSet - shortSet).buffer[1] == 4);
    assertTrue((longSet - shortSet).buffer[2] == 5);
    assertTrue((longSet - shortSet).buffer[3] == 6);
    assertTrue((longSet - shortSet).buffer[4] == 7);
    assertTrue((longSet - shortSet).buffer[5] == 8);
    assertTrue((longSet - shortSet).buffer[6] == 9);
    assertTrue((longSet - shortSet).buffer[7] == 10);
    assertTrue((longSet - shortSet).buffer[8] == 11);
    assertTrue((longSet - shortSet).buffer[9] == 12);
    
    //testing difference for sets with same elements
    
    assertTrue((shortSet - shortSet).numCapacity == 0);
    assertTrue((shortSet - shortSet).numElements == 0);
    assertTrue((shortSet - shortSet).buffer == NULL);
    
    //resetting shortSet
    shortSet.numCapacity = 6;
    shortSet.numElements = 6;
    shortSet.buffer = new int[6];
    shortSet.buffer[0] = -6;
    shortSet.buffer[1] = -5;
    shortSet.buffer[2] = -4;
    shortSet.buffer[3] = -3;
    shortSet.buffer[4] = -2;
    shortSet.buffer[5] = -1;
    
    //testing difference nothing in common both ways
    //longSet [3,4,5,6,7,8,9,10,11,12]
    assertTrue((shortSet - longSet).numCapacity == 6);
    assertTrue((shortSet - longSet).numElements == 6);
    assertTrue((shortSet - longSet).buffer != NULL);
    assertTrue((shortSet - longSet).buffer != shortSet.buffer);
    assertTrue((shortSet - longSet).buffer != longSet.buffer);
    assertTrue((shortSet - longSet).buffer[0] == -6);
    assertTrue((shortSet - longSet).buffer[1] == -5);
    assertTrue((shortSet - longSet).buffer[2] == -4);
    assertTrue((shortSet - longSet).buffer[3] == -3);
    assertTrue((shortSet - longSet).buffer[4] == -2);
    assertTrue((shortSet - longSet).buffer[5] == -1);
    
    assertTrue((longSet - shortSet).numCapacity == 10);
    assertTrue((longSet - shortSet).numElements == 10);
    assertTrue((longSet - shortSet).buffer != NULL);
    assertTrue((longSet - shortSet).buffer != longSet.buffer);
    assertTrue((longSet - shortSet).buffer != shortSet.buffer);
    assertTrue((longSet - shortSet).buffer[0] == 3);
    assertTrue((longSet - shortSet).buffer[1] == 4);
    assertTrue((longSet - shortSet).buffer[2] == 5);
    assertTrue((longSet - shortSet).buffer[3] == 6);
    assertTrue((longSet - shortSet).buffer[4] == 7);
    assertTrue((longSet - shortSet).buffer[5] == 8);
    assertTrue((longSet - shortSet).buffer[6] == 9);
    assertTrue((longSet - shortSet).buffer[7] == 10);
    assertTrue((longSet - shortSet).buffer[8] == 11);
    assertTrue((longSet - shortSet).buffer[9] == 12);
    
    //resetting shortSet
    shortSet.buffer[0] = -21;
    shortSet.buffer[1] = -13;
    shortSet.buffer[2] = 0;
    shortSet.buffer[3] = 1;
    shortSet.buffer[4] = 5;
    shortSet.buffer[5] = 11;
    
    //testing some elements in common both ways
    //longSet [3,4,5,6,7,8,9,10,11,12]
    assertTrue((shortSet - longSet).numCapacity == 4);
    assertTrue((shortSet - longSet).numElements == 4);
    assertTrue((shortSet - longSet).buffer != NULL);
    assertTrue((shortSet - longSet).buffer != shortSet.buffer);
    assertTrue((shortSet - longSet).buffer != longSet.buffer);
    assertTrue((shortSet - longSet).buffer[0] == -21);
    assertTrue((shortSet - longSet).buffer[1] == -13);
    assertTrue((shortSet - longSet).buffer[2] == 0);
    assertTrue((shortSet - longSet).buffer[3] == 1);
    
    assertTrue((longSet - shortSet).numCapacity == 8);
    assertTrue((longSet - shortSet).numElements == 8);
    assertTrue((longSet - shortSet).buffer != NULL);
    assertTrue((longSet - shortSet).buffer != longSet.buffer);
    assertTrue((longSet - shortSet).buffer != shortSet.buffer);
    assertTrue((longSet - shortSet).buffer[0] == 3);
    assertTrue((longSet - shortSet).buffer[1] == 4);
    assertTrue((longSet - shortSet).buffer[2] == 6);
    assertTrue((longSet - shortSet).buffer[3] == 7);
    assertTrue((longSet - shortSet).buffer[4] == 8);
    assertTrue((longSet - shortSet).buffer[5] == 9);
    assertTrue((longSet - shortSet).buffer[6] == 10);
    assertTrue((longSet - shortSet).buffer[7] == 12);
    
    cout<<"Passed Difference Tests."<<endl;
    
    /*
     * Testing Find
     */
    set<int>findSet;
    findSet.numCapacity = 0;
    findSet.numElements = 0;
    findSet.buffer = NULL;
    
    set<int>::iterator foundIt;
    foundIt = findSet.find(3);
    assertTrue(foundIt.ptr == NULL);
    
    //resetting
    findSet.numCapacity = 5;
    findSet.numElements = 4;
    findSet.buffer = new int[5];
    findSet.buffer[0] = -231;
    findSet.buffer[1] = 0;
    findSet.buffer[2] = 13;
    findSet.buffer[3] = 857;
    
    //testing happy path
    foundIt = findSet.find(-231);
    assertTrue(foundIt.ptr == findSet.buffer);
    
    foundIt = findSet.find(857);
    assertTrue(foundIt.ptr == findSet.buffer+3);
    
    //testing non-existant
    
    foundIt = findSet.find(23);
    assertTrue(foundIt.ptr == NULL);
    
    cout<<"Passed find tests"<<endl;
    
    /*
     * Testing Erase
     */
    set <int> eraseSet;
    eraseSet.buffer = new int[6];
    eraseSet.numCapacity = 6;
    eraseSet.numElements = 5;
    eraseSet.buffer[0] = -500;
    eraseSet.buffer[1] = 0;
    eraseSet.buffer[2] = 7;
    eraseSet.buffer[3] = 13;
    eraseSet.buffer[4] = 23;
    
    eraseSet.erase(nullIt);
    assertTrue(eraseSet.numCapacity == 6);
    assertTrue(eraseSet.numElements == 5);
    assertTrue(eraseSet.buffer[0] == -500);
    assertTrue(eraseSet.buffer[1] == 0);
    assertTrue(eraseSet.buffer[2] == 7);
    assertTrue(eraseSet.buffer[3] == 13);
    assertTrue(eraseSet.buffer[4] == 23);
    
    
    set<int>::iterator eraseLastIter = set<int>::iterator(eraseSet.buffer+4);
    eraseSet.erase(eraseLastIter);
    assertTrue(eraseSet.numCapacity == 6);
    assertTrue(eraseSet.numElements == 4);
    assertTrue(eraseSet.buffer[0] == -500);
    assertTrue(eraseSet.buffer[1] == 0);
    assertTrue(eraseSet.buffer[2] == 7);
    assertTrue(eraseSet.buffer[3] == 13);
    
    set<int>::iterator eraseMidIter = set<int>::iterator(eraseSet.buffer+2);
    eraseSet.erase(eraseMidIter);
    assertTrue(eraseSet.numCapacity == 6);
    assertTrue(eraseSet.numElements == 3);
    assertTrue(eraseSet.buffer[0] == -500);
    assertTrue(eraseSet.buffer[1] == 0);
    assertTrue(eraseSet.buffer[2] == 13);
    
    set<int>::iterator eraseFirstIter = set<int>::iterator(eraseSet.buffer);
    eraseSet.erase(eraseFirstIter);
    assertTrue(eraseSet.numCapacity == 6);
    assertTrue(eraseSet.numElements == 2);
    assertTrue(eraseSet.buffer[0] == 0);
    assertTrue(eraseSet.buffer[1] == 13);
    cout<<"Passed erase tests"<<endl;
    
    /*
     * Testing resize
     */
    set<int> emptyResizeset;
    emptyResizeset.resize(-1);
    assertTrue(emptyResizeset.numCapacity == 0);
    assertTrue(emptyResizeset.numElements == 0);
    assertTrue(emptyResizeset.buffer == NULL);
    cout<<"Passed negative resize test."<<endl;
    
    emptyResizeset.resize(7);
    assertTrue(emptyResizeset.numCapacity == 7);
    assertTrue(emptyResizeset.numElements == 0);
    assertTrue(emptyResizeset.buffer != NULL);
    cout<<"Passed default set resized test."<<endl;
    
    set <int> resizeSet;
    resizeSet.buffer = new int[5];
    resizeSet.numCapacity = 5;
    resizeSet.numElements = 5;
    resizeSet.buffer[0] = 7;
    resizeSet.buffer[1] = 12;
    resizeSet.buffer[2] = 10;
    resizeSet.buffer[3] = 9;
    resizeSet.buffer[4] = 8;
    //buffer: [7,12,10,9,8]
    
    int *theBuffer = resizeSet.buffer;
    resizeSet.resize(10);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assertTrue(theBuffer != resizeSet.buffer);
    assertTrue(resizeSet.numCapacity == 10);
    assertTrue(resizeSet.numElements == 5);
    assertTrue(resizeSet.buffer[0] == 7);
    assertTrue(resizeSet.buffer[1] == 12);
    assertTrue(resizeSet.buffer[2] == 10);
    assertTrue(resizeSet.buffer[3] == 9);
    assertTrue(resizeSet.buffer[4] == 8);
    
    theBuffer = resizeSet.buffer;
    resizeSet.resize(2);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assertTrue(theBuffer != resizeSet.buffer);
    assertTrue(resizeSet.numCapacity == 2);
    assertTrue(resizeSet.numElements == 2);
    assertTrue(resizeSet.buffer[0] == 7);
    assertTrue(resizeSet.buffer[1] == 12);
    
    theBuffer = resizeSet.buffer;
    resizeSet.resize(0);
    assertTrue(resizeSet.numCapacity == 0);
    assertTrue(resizeSet.numElements == 0);
    assertTrue(resizeSet.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    
    
    /*
     * Testing insert with resize
     */
    set<int> insertResizeSet;
    insertResizeSet.buffer = NULL;
    insertResizeSet.numCapacity = 0;
    insertResizeSet.numElements = 0;
    
    insertResizeSet.insert(21);
    assertTrue(insertResizeSet.buffer != NULL);
    assertTrue(insertResizeSet.numCapacity == 1);
    assertTrue(insertResizeSet.numElements == 1);
    assertTrue(insertResizeSet.buffer[0] == 21);
    
    int* oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(7);
    assertTrue(insertResizeSet.buffer != NULL);
    assertTrue(insertResizeSet.buffer != oldBuffer);
    assertTrue(insertResizeSet.numCapacity == 2);
    assertTrue(insertResizeSet.numElements == 2);
    assertTrue(insertResizeSet.buffer[0] == 7);
    assertTrue(insertResizeSet.buffer[1] == 21);
    
    //testing insert something that already exits
    oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(7);
    assertTrue(insertResizeSet.buffer != NULL);
    assertTrue(insertResizeSet.buffer == oldBuffer);
    assertTrue(insertResizeSet.numCapacity == 2);
    assertTrue(insertResizeSet.numElements == 2);
    assertTrue(insertResizeSet.buffer[0] == 7);
    assertTrue(insertResizeSet.buffer[1] == 21);
    
    //testing resize on insert yet again
    oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(100);
    assertTrue(insertResizeSet.buffer != NULL);
    assertTrue(insertResizeSet.buffer != oldBuffer);
    assertTrue(insertResizeSet.numCapacity == 4);
    assertTrue(insertResizeSet.numElements == 3);
    assertTrue(insertResizeSet.buffer[0] == 7);
    assertTrue(insertResizeSet.buffer[1] == 21);
    assertTrue(insertResizeSet.buffer[2] == 100);
    
    
    //testing no-resize on insert
    oldBuffer = insertResizeSet.buffer;
    insertResizeSet.insert(50);
    assertTrue(insertResizeSet.buffer != NULL);
    assertTrue(insertResizeSet.buffer != oldBuffer);
    assertTrue(insertResizeSet.numCapacity == 4);
    assertTrue(insertResizeSet.numElements == 4);
    assertTrue(insertResizeSet.buffer[0] == 7);
    assertTrue(insertResizeSet.buffer[1] == 21);
    assertTrue(insertResizeSet.buffer[2] == 50);
    assertTrue(insertResizeSet.buffer[3] == 100);
    cout<<"Passed Insert With Resize Tests."<<endl;
    
    
    
    /*
     * Testing = operator and copy constructor
     */
    set <int> setToCopy;
    setToCopy.numCapacity = 8;
    setToCopy.numElements = 8;
    setToCopy.buffer = new int[setToCopy.numCapacity];
    for (int i = 0; i < setToCopy.numCapacity; i++)
    {
        setToCopy.buffer[i]=i*i+1;
    }
    set <int> setAssignedCopy;
    setAssignedCopy = setToCopy;
    assertTrue(setAssignedCopy.numCapacity == 8);
    assertTrue(setAssignedCopy.numElements == 8);
    assertTrue(setAssignedCopy.buffer != setToCopy.buffer);
    assertTrue(setAssignedCopy.buffer[0] == 1);
    assertTrue(setAssignedCopy.buffer[1] == 2);
    assertTrue(setAssignedCopy.buffer[2] == 5);
    assertTrue(setAssignedCopy.buffer[3] == 10);
    assertTrue(setAssignedCopy.buffer[4] == 17);
    assertTrue(setAssignedCopy.buffer[5] == 26);
    assertTrue(setAssignedCopy.buffer[6] == 37);
    assertTrue(setAssignedCopy.buffer[7] == 50);
    cout << "(full) = Operator Test Passed" << endl;
    
    set <int> setCopy(setToCopy);
    assertTrue(setCopy.numCapacity == 8);
    assertTrue(setCopy.numElements == 8);
    assertTrue(setCopy.buffer != setToCopy.buffer);
    assertTrue(setCopy.numCapacity == 8);
    assertTrue(setCopy.buffer[0] == 1);
    assertTrue(setCopy.buffer[1] == 2);
    assertTrue(setCopy.buffer[2] == 5);
    assertTrue(setCopy.buffer[3] == 10);
    assertTrue(setCopy.buffer[4] == 17);
    assertTrue(setCopy.buffer[5] == 26);
    assertTrue(setCopy.buffer[6] == 37);
    assertTrue(setCopy.buffer[7] == 50);
    cout << "(Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Resetting to not full set
     */
    
    setToCopy.numElements = 3;
    
    set <int> notFullsetAssignedCopy;
    notFullsetAssignedCopy = setToCopy;
    assertTrue(notFullsetAssignedCopy.numCapacity == 3);
    assertTrue(notFullsetAssignedCopy.numElements == 3);
    assertTrue(notFullsetAssignedCopy.buffer != setToCopy.buffer);
    assertTrue(notFullsetAssignedCopy.buffer[0] == 1);
    assertTrue(notFullsetAssignedCopy.buffer[1] == 2);
    assertTrue(notFullsetAssignedCopy.buffer[2] == 5);
    cout << "(Not full) = Operator Test Passed" << endl;
    
    set <int> notFullSetCopy(setToCopy);
    assertTrue(notFullSetCopy.numCapacity == 3);
    assertTrue(notFullSetCopy.numElements == 3);
    assertTrue(notFullSetCopy.buffer != setToCopy.buffer);
    assertTrue(notFullSetCopy.buffer[0] == 1);
    assertTrue(notFullSetCopy.buffer[1] == 2);
    assertTrue(notFullSetCopy.buffer[2] == 5);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    
    
    /*
     * Testing insert for Non-Integer set Behavior (Just to Make Sure set Works For Other Types)
     */
    set <string> stringset;
    
    stringset.insert("Hello");
    stringset.insert("It's me");
    stringset.insert("Are you wondering");
    assertTrue(stringset.numCapacity == 4);
    assertTrue(stringset.buffer[0] == "Are you wondering");
    assertTrue(stringset.buffer[1] == "Hello");
    assertTrue(stringset.buffer[2] == "It's me");
    
    cout << "This set can hold strings!!!!" << endl;
    
    
    generateTestingReport();
    
    return 0;
}
