//
// Created by slam on 19-4-9.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
#include "linklist.h"

int main(int argc, char** argv) {
    LinkList ll;
    std::vector<Node*> nodelist(9);
    Node* n1 = new Node(1); nodelist[0] = n1;
    Node* n2 = new Node(8); nodelist[1] = n2;
    Node* n3 = new Node(6); nodelist[2] = n3;
    Node* n4 = new Node(2); nodelist[3] = n4;
    Node* n5 = new Node(5); nodelist[4] = n5;
    Node* n6 = new Node(4); nodelist[5] = n6;
    Node* n7 = new Node(8); nodelist[6] = n7;
    Node* n8 = new Node(2); nodelist[7] = n8;
    Node* n9 = new Node(7); nodelist[8] = n9;
    ll.create_linklist(nodelist);

    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "time cost : " << dur.count() << std::endl;
    return 0;
}