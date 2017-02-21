//
//  List.hpp
//  MegaData
//
//  Created by Nilson, Jake on 2/21/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef List_h
#define List_h

#include "Node.hpp"
#include <assert.h>

using namespace std

template <class Type>
class List
{
private:
    int size;
    Node<Type> * front;
public:
    List<Type>();
    List<Type>(cont List<Type> & source);
    ~List<Type>();
    
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(ind index, Type data);
    Type getFromIndex(ind index);
    bool contains(Type data);
    int getSize() const;
    Node<Type> * getFront() const;
};

template <class Type>
List<Type> :: List<Type>()
{
    
}

template <class Type>
List<Type> :: List(int size)
{
    assert(size > 0);
    
    this->size = size;
    this->front = new Node<Type>();
    
    for(int index = 1; index < size; index++)
    {
        Node<Type> * current = new Node<Type>();
        current->setNodePointer(front);
        front=current;
    }
}

template <class Type>
List<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < size);
    
    Type value;
    
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    value = current->getNodeData();
    
    return value;
}

template <class Type>
List<Type> :: getSize() const
{
    return size;
}

template <class Type>
List<Type> :: ~List<Type>()
{
    
}

#endif /* List_h */
