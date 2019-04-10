//
// Created by slam on 19-4-10.
//

#ifndef LEETCODE_LINKLIST_H
#define LEETCODE_LINKLIST_H

#include <iostream>
#include "node.h"

class LinkList {
public:
    LinkList(){
        head_ = new Node; // 头结点为空
        head_->value_ = 0;
        head_->pnext_ = NULL;
    }
    LinkList(Node* p){
        this->head_ = p;
    }

    ~LinkList(){delete head_;}

    void create_linklist(const std::vector<int>& nums);
    void travese();
    void inverse_loop();
    void inverse_recursive();

private:
    Node* inverse(Node* head);

    Node *head_;
};


#endif //LEETCODE_LINKLIST_H
