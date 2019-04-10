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

void LinkList::inverse_loop() {
    if(this->head_ == nullptr){
        std::cout << "List is NULL" << std::endl;
        return;
    }
    Node* prev = nullptr;
    Node* pcur = this->head_->pnext_;
    while(pcur != nullptr){
        Node* ptmp = pcur->pnext_;
        pcur->pnext_ = prev;
        prev = pcur;
        pcur = ptmp;
    }
    Node* pr_head = new Node;
    pr_head->value_ = 0;
    pr_head->pnext_ = prev;
    this->head_ = pr_head;
//    return pr_head;
}

void LinkList::inverse_recursive(){
    if(this->head_ == nullptr){
        std::cout << "List is NULL" << std::endl;
        return;
    }
    Node* p = inverse(this->head_->pnext_);
    Node* pr_head = new Node;
    pr_head->value_ = 0;
    pr_head->pnext_ = p;
    this->head_ = pr_head;

}

Node* LinkList::inverse(Node* head){
    if (head == nullptr || head->pnext_ == nullptr)
        return head;
    Node* p = inverse(head->pnext_);
    head->pnext_->pnext_ = head;
    head->pnext_=nullptr;
    return p;
}