//
// Created by slam on 19-4-10.
//

#include "linklist.h"

void LinkList::create_linklist(const std::vector<int>& nums){
    Node *pnew, *ptemp;
    ptemp = this->head_;
    for (int i = 0; i < nums.size(); i++){
        pnew = new Node;
        pnew->value_ = nums[i];
        pnew->pnext_ = NULL;
        ptemp->pnext_ = pnew;
        ptemp = pnew;
    }
}

void LinkList::travese() {
    if (this->head_ == NULL){
        std::cout << "empty list" << std::endl;
        return;
    }
    Node* ptmp = this->head_->pnext_;
    do{
        std::cout << ptmp->value_ << std::endl;
        ptmp = ptmp->pnext_;
    }while(ptmp !=NULL);
}

Node* LinkList::inverse_loop() {
    if(this->head_ == NULL){
        std::cout << "List is NULL" << std::endl;
        return NULL;
    }
    Node* prev = NULL;
    Node* pcur = this->head_->pnext_;
    while(pcur != NULL){
        Node* ptmp = pcur->pnext_;
        pcur->pnext_ = prev;
        prev = pcur;
        pcur = ptmp;
    }
    return prev;
}