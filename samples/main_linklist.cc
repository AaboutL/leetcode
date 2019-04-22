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
    std::vector<int> nums{1,4, 3, 2, 5, 2};
    LinkList ll;
    ll.create_linklist(nums);
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    // inverse
//    ll.travese();
//    std::cout << std::endl;
//    ll.inverse_between(1, 5);
    ll.partition(3);
    ll.travese();
    std::cout << std::endl;

    // merge
    std::vector<int> n1{1, 4, 5, 7};
    std::vector<int> n2{2, 3, 6, 8, 9};
    LinkList l1, l2, l3;
    l1.create_linklist(n1);
    l2.create_linklist(n2);
    l3.merge_two_lists(l1, l2);
    l3.travese();

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "time cost : " << dur.count() << std::endl;
    return 0;
}