//
//  Array.hpp
//  MegaData
//
//  Created by Nilson, Jake on 2/15/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef Array_h
#define Array_h

#include "Node.hpp"
#include <assert.h>

template <class Type>
class Array
{
private:
    int size;
    Node<Type> * front;
public:
    Array();
    Array(int size);
    
    int getSize();
    void setAtIndex(int index, Type value);
    Type getFromIndex(int index);
};

/*
Implementation Section
*/


#endif /* Array_h */
