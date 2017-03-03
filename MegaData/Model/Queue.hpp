//
//  Queue.hpp
//  MegaData
//
//  Created by Nilson, Jake on 3/3/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include "DoublyLinkedList.hpp"

template <class Type>
class Queue : public DoublyLinkedList<Type>
{
private:
    
public:
    Queue();
    ~Queue();
    
    void add(Type data);
    Type remove(int index);
    
    void enqueue(Type data);
    Type dequeue();
    Type peek();
};

template <class Type>
void Queue<Type> :: add(Type value)
{
    enqueue(value);
}

/*
 Add to Queue;
 Create Node
 If first - adjust front
 else add to end
 move end
 adjust size
*/
template <class Type>
void Queue<Type> :: enqueue(Type insertedValue)
{
    BiDirectionalNode<Type> * added = BiDirectionalNode<Type>(insertedValue);
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(added);
    }
    else
    {
        this->getEnd()->setNextPointer(added);
    }
    this->setEnd(added);
    this->setSize(this->getSize() + 1);
}

/*
 Remove from the queue
 Check valid index
 call dequeue
*/
template <class Type>
Type Queue<Type> :: remove(int index)
{
    assert(index == 0 && this->getSize() > 0);
    return dequeue();
}

/*
 Check size
 
*/
template <class Type>
Type Queue<Type> :: dequeue()
{
    
}


#endif /* Queue_h */


