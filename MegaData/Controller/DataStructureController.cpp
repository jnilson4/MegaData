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
    testIntStack();
    testFoodQueue();
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
    
    numberStack.peek();
    numberStack.remove(3);
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
    
}

void DataStructureController :: testFoodCircularList()
{
    
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
