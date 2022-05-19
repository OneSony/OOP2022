#include "add.h"
void addNode::calc(){
    input1->calc();
    input2->calc();

    UpdateValue();
}

void addNode::UpdateValue(){
    value_=input1->value()+input2->value();
}

void subNode::calc(){
    input1->calc();
    input2->calc();

    UpdateValue();
}

void subNode::UpdateValue(){
    value_=input1->value()-input2->value();
}