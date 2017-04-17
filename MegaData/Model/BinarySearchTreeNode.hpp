//
//  BinarySearchTreeNode.h
//  MegaData
//
//  Created by Nilson, Jake on 4/11/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef BinarySearchTreeNode_h
#define BinarySearchTreeNode_h

#include "Node.hpp"

template <class Type>
class BinarySearchTreeNode : public Node<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    BinarySearchTreeNode<Type> * leftChild;
    BinarySearchTreeNode<Type> * rightChild;
    
public:
    BinarySearchTreeNode();
    ~BinarySearchTreeNode();
    BinarySearchTreeNode(Type data);
    
    BinarySearchTreeNode<Type> * getRootPointer();
    BinarySearchTreeNode<Type> * getLeftChild();
    BinarySearchTreeNode<Type> * getRightChild();
    
    void setRootPointer(BinarySearchTreeNode<Type> * root);
    void setLeftChild(BinarySearchTreeNode<Type> * left);
    void setRightChild(BinarySearchTreeNode<Type> * right);
};

template <class Type>
BinarySearchTreeNode<Type> :: ~BinarySearchTreeNode()
{
    delete leftChild;
    delete rightChild;
}

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode() : Node<Type>()
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> :: BinarySearchTreeNode(Type data) : Node<Type>(data)
{
    this->root = nullptr;
    this->leftChild = nullptr;
    this->rightChild = nullptr;
}

template <class Type>
BinarySearchTreeNode<Type> * :: BinarySearchTreeNode<Type> :: getRootPointer()
{
    return this->root;
}

template <class Type>
BinarySearchTreeNode<Type> * :: BinarySearchTreeNode<Type> :: getLeftChild()
{
    return this->leftChild;
}

template <class Type>
BinarySearchTreeNode<Type> * :: BinarySearchTreeNode<Type> :: getRightChild()
{
    return this->rightChild;
}

template <class Type>
void BinarySearchTreeNode<Type> :: BinarySearchTreeNode<Type> :: setRootPointer(BinarySearchTreeNode<Type>* root)
{
    this->root = root;
}

template <class Type>
void BinarySearchTreeNode<Type> :: BinarySearchTreeNode<Type> :: setLeftChild(BinarySearchTreeNode<Type>* left)
{
    this->leftChild = left;
}

template <class Type>
void BinarySearchTreeNode<Type> :: BinarySearchTreeNode<Type> :: setRightChild(BinarySearchTreeNode<Type>* right)
{
    this->rightChild = right;
}

#endif /* BinarySearchTreeNode_h */
