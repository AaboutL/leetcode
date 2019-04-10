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
    std::vector<int> nums{1,8,6,2,5,4,8,3,7};
    LinkList ll;
    ll.create_linklist(nums);
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    ll.travese();
    Node* pr = ll.inverse_loop();

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "time cost : " << dur.count() << std::endl;
    return 0;
}