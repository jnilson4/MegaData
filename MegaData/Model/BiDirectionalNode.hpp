//
//  BiDirectionalNode.hpp
//  MegaData
//
//  Created by Nilson, Jake on 2/27/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef BiDirectionalNode_h
#define BiDirectionalNode_h

template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
    BiDirectionalNode<Type> * previous;
    BiDirectionalNode<Type> * next;
    Type data;
public:
    BiDriectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDrectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>()
{
    
}

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node<Type>(data)
{
    
}

//template <class Type>
//BiDirectionalNode<Type> :: BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) : Node<Type>(data)
//{
//    
//}

#endif /* BiDirectionalNode_h */
