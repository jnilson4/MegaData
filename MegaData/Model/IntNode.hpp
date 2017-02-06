//
//  IntNode.hpp
//  MegaData
//
//  Created by Nilson, Jake on 2/6/17.
//  Copyright © 2017 Nilson. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp

class IntNode
{
private:
    int nodeData;
    IntNode * nodePointer;
public:
    //Constructors
    IntNode();
    IntNode(int value);
    /*
     Creates and IntNode with a specified value and next node pointer.
    */
    IntNode(int value, IntNode * nextNode);
    
    //Methods
    int getNodeData();
    IntNode * getNodePointer();
    
    void setNodeData(int value);
    void setNotePointer(IntNode * next);
};

#endif /* IntNode_hpp */
