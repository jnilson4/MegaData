//
//  Node.hpp
//  MegaData
//
//  Created by Nilson, Jake on 2/13/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type> * nextPointer;
public:
    Node();
    Node(Type nodeData);
    Node(Type data, Node<Type> * next);
    
    void setNodeData(Type data);
    void setNextPointer(Node<Type> * pointer);
    Type getNodeData();
    Node<Type> * getNextPointer();
};

/*
Implementation Section
*/

template <class Type>
Node<Type> :: Node()
{
    //Explicitly DO NOT instantiate the nodeData data member
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type data, Node<Type> * pointer)
{
    this->nodeData = nodeData;
    this->nextPointer = nextPointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type data)
{
    this->nodeData = data;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type> * nextPointer)
{
    this->nextPointer = nextPointer;
}

template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}

template <class Type>
Node<Type> * Node<Type> :: getNextPointer()
{
    return this->nextPointer;
}

#endif /* Node_hpp */
