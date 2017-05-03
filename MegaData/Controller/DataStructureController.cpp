//
//  DataStructureController.cpp
//  MegaData
//
//  Created by Nilson, Jake on 2/8/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#include "DataStructureController.hpp"

#include <iostream>

using namespace std;

DataStructureController :: DataStructureController()
{
    
}

void DataStructureController :: start()
{
    testHashTable();
}

void DataStructureController :: testIntArray()
{
    cout << "Testing the array" << endl;
    
    IntNodeArray temp = IntNodeArray(3);
    
    for(int index = 0; index < 3; index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
    
    cout << "Testing input" << endl;
    
    for(int index = 0; index < 3; index++)
    {
        temp.setAtIndex(index, index);
    }
    
    for(int index = 0; index < temp.getSize(); index++)
    {
        cout << temp.getFromIndex(index) << " is at spot " << index << endl;
    }
}

void DataStructureController :: testIntStack()
{
    Stack<int> numberStack;
    numberStack.add(2315);
    numberStack.push(9999);
    int testValue = numberStack.pop();
    
    cout << "Test value is: " << testValue << " and should be 9999." << endl;
    
    numberStack.add(1);
    numberStack.add(32);
    numberStack.add(87);
    
    cout << "The size of the stack is: " << numberStack.getSize() << " and should be 4." << endl;
    
    int peeked = numberStack.peek();
    
    cout << "The number that was peeked was: " << peeked << " and should be: 87." << endl;
    
    numberStack.add(167);
    numberStack.add(13);
    
    int removed = numberStack.remove(5);
    
    cout << "The number that was removed was: " << removed << " and should be: 13." << endl;
    
    cout << "The current size of the list is: " << numberStack.getSize() << " and should be: 6." << endl;
}

void DataStructureController :: testFoodQueue()
{
    Queue<FoodItem> tastyFood;
    FoodItem generalTaos("Delicious Chinese Chicken Dish");
    FoodItem ramen("Ramen");
    FoodItem macNCheese("Delicious pasta with cheese.");
    FoodItem soup("Chicken Noodle!!");
    
    tastyFood.enqueue(generalTaos);
    tastyFood.add(ramen);
    
    FoodItem removed = tastyFood.dequeue();
    cout << "The item removed from the queue was: " << removed.getFoodName() << " and should be: Delicious Chinese Chicken Dish" << endl;
    
    tastyFood.add(macNCheese);
    
    FoodItem peeked = tastyFood.peek();
    cout << "The item that was peeked from the queue was: " << peeked.getFoodName() << " and should be: Ramen. " << "The current size of the list is: " << tastyFood.getSize() << endl;
    
    tastyFood.add(soup);
    tastyFood.add(generalTaos);
    
    FoodItem actualRemoved = tastyFood.remove(0);
    cout << "The item that was removed from the queue was: " << actualRemoved.getFoodName() << " and should be: Ramen. " << "The current size of the list is: " << tastyFood.getSize() << endl;
}

void DataStructureController :: testFoodDouble()
{
    DoubleList<FoodItem> tastyFood;
    FoodItem generalTaos("Delicious Chinese Chicken Dish");
    FoodItem ramen("Ramen");
    FoodItem macNCheese("Delicious pasta with cheese.");
    FoodItem soup("Chicken Noodle!!");
    
    tastyFood.add(generalTaos);
    tastyFood.add(ramen);
    tastyFood.add(macNCheese);
    tastyFood.add(soup);
    
    FoodItem fromIndex = tastyFood.getFromIndex(3);
    
    cout << "The item from index 3 is: " << fromIndex.getFoodName() << " and should be: Chicken Noodle!!" << endl;
    
    tastyFood.remove(0);
    FoodItem fromIndexFast = tastyFood.getFromIndexFast(1);
    
    cout << "The item from index 1 is: " << fromIndexFast.getFoodName() << " and should be: Delicious pasta with cheese." << endl;
}

void DataStructureController :: testFoodCircularList()
{
    CircularList<int> tastyFood;
    
    for(int index = 0; index < 10; index++)
    {
        tastyFood.add(index);
        cout << "The size of food are: " << tastyFood.getSize() << ", and should be " << (index + 1) << endl;
    }
    
    int testGet = tastyFood.getFromIndex(1);
    cout << "The value from the list should be 3 and is: " << testGet << endl;
}

void DataStructureController :: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout << "This should go 1, 2, 3" << endl;
    
    for(int index = 0; index < sample.getSize(); index++)
    {
        cout << sample.getFromIndex(index) << endl;
    }
    
    cout << "Size should read 3 and is " << sample.getSize() << endl;
}

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    Timer totalTimer;
    totalTimer.startTimer();
    for(int index = 0; index < 1000000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTime [10000];
    long fastTime [10000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow += averageSlow/10000.00;
    averageFast += averageFast/10000.00;
    totalTimer.stopTimer();
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds." << endl;
    cout << "The average speed for the getFromIndexFast method was: " << averageFast << " microseconds" << endl;
}

void DataStructureController :: testList()
{
    List<int> numbers;
    
    numbers.addFront(5);
    numbers.addEnd(6);
    numbers.addFront(20);
    numbers.addFront(45897);
    numbers.addFront(123);
    numbers.addEnd(67);
    
    cout << "The size of the list is: " << numbers.getSize() << " and should be: 6." << endl;
    
    int numberRemoved = numbers.remove(2);
    
    cout << "The number that was removed was: " << numberRemoved << " and should have been: 20" << endl;
    cout << "The size of the list is: " << numbers.getSize() << " and should be: 5." << endl;
    
    numbers.addAtIndex(2, 234098);
    
    cout << "The number added at index 2 is: " << numbers.getFromIndex(2) << " and should be: 234098." << endl;
    
    numbers.setAtIndex(2, 1);
    
    cout << "The number that is now at index 2 is: " << numbers.getFromIndex(2) << " and should be: 1." << endl;
    
    cout << "The number 67 is contained in the list returns: " << numbers.contains(67) << " and should be 1." << endl;
}

void DataStructureController :: testBinarySearchTreeOperations()
{
    
    BinarySearchTree<int> numbers;
    
    numbers.insert(9843);
    
    numbers.insert(10);
    
    numbers.insert(43);
    
    cout << "The size is: " << numbers.getSize() << " and should be: 3." << endl;
    
    numbers.insert(-123);
    
    numbers.insert(23465);
    
    numbers.insert(10); // won't go in
    
    numbers.insert(43243);
    
    cout << "The size is: " << numbers.getSize() << " and should be: 6." << endl;
    
    numbers.insert(-45677654);
    
    numbers.insert(92165);
    
    
    cout << "Size should be 8 and is: " << numbers.getSize() << endl;
    
    cout << "In order traversal should be: \n\t-45677654 \n\t-123 \n\t10 \n\t43 \n\t9843 \n\t23465 \n\t43243 \n\t92165" << endl;
    
    numbers.inOrderTraversal();
    
    
    cout << "Height should be 4 and is: " << numbers.getHeight() << endl;
    
    cout << "Balanced should be false || 0 and is: " << numbers.isBalanced() << endl;
    
}

void DataStructureController :: testHashTable()
{
    HashTable<int> numbers;
    
    numbers.add(123);
    
    cout << "The size of numbers is: " << numbers.getSize() << " and should be 1." << endl;
    
    numbers.add(87435);
    
    numbers.add(757);
    
    numbers.add(883);
    
    numbers.add(102);
    
    cout << "The size of numbers is: " << numbers.getSize() << " and should be 5." << endl;
    
    cout << "Contains: " << numbers.contains() << endl;
    
    numbers.add(890);
    
    numbers.add(00);
    
    numbers.add(453);
    
    numbers.add(891);
    
    numbers.add(78);
    
    cout << "The size of numbers is: " << numbers.getSize() << " and should be: 10" << endl;
}
