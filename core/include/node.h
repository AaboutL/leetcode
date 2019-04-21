//
// Created by slam on 19-4-10.
//

#ifndef LEETCODE_NODE_H
#define LEETCODE_NODE_H

#include <iostream>
#include <vector>

class Node{
public:
    Node(){}

    Node(int value){
        this->value_ = value;
        this->pnext_ = nullptr;
    }

    int value_;
    Node *pnext_;
};

#endif //LEETCODE_NODE_H
