//
// Created by slam on 19-4-10.
//

#include <linklist.h>

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

void LinkList::create_linklist(const std::vector<Node*>& nodes){
    Node* ptemp = this->head_;
    for (int i = 0; i < nodes.size(); i++){
        ptemp->pnext_ = nodes[i];
        ptemp = ptemp->pnext_;
    }
}

Node* LinkList::get_head() const{
    return this->head_;
}

int LinkList::travese() const {
    int length = 0;
    if (this->head_ == NULL){
        std::cout << "empty list" << std::endl;
        return length;
    }
    Node* ptmp = this->head_->pnext_;
    do{
        length++;
        std::cout << ptmp->value_ << std::endl;
        ptmp = ptmp->pnext_;
    }while(ptmp !=NULL);
    std::cout << "traverse finished! " << std::endl;
    return length;
}

void LinkList::inverse_loop() { // 就地逆置
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

void LinkList::inverse_recursive(){ // 递归的方法
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
    head->pnext_->pnext_ = head; // 从后尾向头逆置，比如a->b->c->d<-e<-f，d之后的都已经逆置，之前的都没有逆置
    head->pnext_=nullptr;
    return p;
}

void LinkList::inverse_between(int m, int n) {
    /*
     * 注意几个结点的设置，pre_head是逆置部分之前的结点，
     * inversed_list_tail是逆置部分的第一个结点，也是逆置之后的最后一个结点
     * new_head：是逆置部分的在逆置完成后的头结点
     * pcur：用于遍历链表，并记录逆置部分之后的第一个结点
     * */
    int change_len = n - m + 1;
    Node* pre_head = nullptr;
    Node* result = this->head_;
    Node* pcur = this->head_->pnext_;
    while(this->head_ && --m){
        pre_head = pcur;
        pcur = pcur->pnext_;
    }
    Node* inversed_list_tail = pcur;
    Node* new_head = nullptr;
    while(pcur && change_len) {
        Node* ptmp = pcur->pnext_;
        pcur->pnext_ = new_head;
        new_head = pcur;
        pcur = ptmp;
        change_len--;
    }
    inversed_list_tail->pnext_ = pcur;
    if(pre_head){
        pre_head->pnext_ = new_head;
    }
    else{
        result->pnext_ = new_head;
    }
}

void LinkList::merge_two_lists(const LinkList& l1, const LinkList& l2){
    Node* pre = this->head_;
    Node* p1_cur = l1.get_head()->pnext_;
    Node* p2_cur = l2.get_head()->pnext_;
    while(p1_cur && p2_cur){
        if(p1_cur->value_ < p2_cur->value_){
            pre->pnext_ = p1_cur;
            p1_cur = p1_cur->pnext_;
        }
        else {
            pre->pnext_ = p2_cur;
            p2_cur = p2_cur->pnext_;
        }
        pre = pre->pnext_;
        if(p1_cur){
            pre->pnext_ = p1_cur;
        }
        if(p2_cur){
            pre->pnext_ = p2_cur;
        }
    }
}

Node* LinkList::get_intersection_node(const LinkList &l1, const LinkList &l2) {
    int l1_length = l1.travese();
    int l2_length = l2.travese();
    Node *ptmp1=nullptr,  *ptmp2=nullptr;
    ptmp1 = l1.get_head()->pnext_;
    ptmp2 = l2.get_head()->pnext_;
    if(l1_length > l2_length){
        int delta = l1_length - l2_length;
        while(ptmp1 && delta){
            ptmp1 = ptmp1->pnext_;
            delta--;
        }
    }
    else{
        int delta = l2_length - l1_length;
        Node* ptmp2 = l2.get_head()->pnext_;
        while(ptmp2 && delta){
            ptmp2 = ptmp2->pnext_;
            delta--;
        }
    }
    while(ptmp1 && ptmp2){
        if(ptmp1 == ptmp2){
            return ptmp1;
        }
        ptmp1 = ptmp1->pnext_;
        ptmp2 = ptmp2->pnext_;
    }
    return nullptr;
}

Node* LinkList::detect_cycle() {
    Node* pcur = this->head_;
    Node* fast = this->head_;
    Node* slow = this->head_;
    Node* meet = nullptr;
    while(fast){
        fast = fast->pnext_;
        slow = slow->pnext_;
        if(!fast){
            return nullptr;
        }
        fast = fast->pnext_;
        if(fast == slow){
            meet = fast;
            break;
        }
    }
    if(meet==nullptr){
        return nullptr;
    }
//    meet = meet->pnext_;
    while(pcur && meet){
        if(meet == pcur){
            return meet;
        }
        meet = meet->pnext_;
        pcur = pcur->pnext_;
    }
    return nullptr;
}

void LinkList::partition(int val) {
    // 小于val的值放在val的前面, 大于等于val的值,放在val的后面. 划分之后, 需要保持原来的相对位置.
    Node* less_head = new Node(0);
    Node* more_head = new Node(0);
    Node* less_tmp = less_head;
    Node* more_tmp = more_head;
    Node* pcur = this->head_->pnext_;
    while(pcur){
        if(pcur->value_ < val){
            less_tmp->pnext_ = pcur;
            less_tmp = pcur;
        }
        if(pcur->value_ >= val){
            more_tmp->pnext_ = pcur;
            more_tmp = pcur;
        }
        pcur = pcur->pnext_;
    }
    less_tmp->pnext_ = more_head->pnext_;
    more_tmp->pnext_ = nullptr;
    this->head_ = less_head;
}
