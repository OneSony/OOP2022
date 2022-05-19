#pragma once
#include "operation.h"
class addNode:public OperationNodeTwo{
public:
    addNode(string name,Node* x1,Node* x2):OperationNodeTwo(name,x1,x2){}
    ~addNode(){}
    void calc();
    void UpdateValue();
};

class subNode:public OperationNodeTwo{
public:
    subNode(string name,Node* x1,Node* x2):OperationNodeTwo(name,x1,x2){}
    ~subNode(){}
    void calc();
    void UpdateValue();
};