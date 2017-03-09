//
//  CircularList.hpp
//  MegaData
//
//  Created by Nilson, Jake on 3/1/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef CircularList_h
#define CircularList_h

#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public DoublyLinkedList<Type>
{
private:
    //No Need to redefine the private data members of DoublyLinkedList.
public:
    CircularList();
    ~CircularList();
    
    void add(Type data);
    Type remove(int index);
    //Other methods as needed :D
};

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    //Deal with circle list stuff only here.
}

template <class Type>
void CircularList<Type> :: add(Type data)
{
    
}

#endif /* CircularList_h */
