//
// Created by aal on 19-4-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 已知一些孩子和一些糖果，每个孩子有需求因子g，每个糖果有大小s，当 某个糖果的大小s >=某个孩子的需求因子g时，代表该糖果可以满足该孩子；
    求使用这 些糖果，最多能满足多少孩子？(注意，某个孩子最多只能用1个糖果满足)
    1. 如果某颗糖果不能满足某个孩子，则这个糖果一定不能满足需求因子更大的孩子
    2. 某个孩子可以用更小的糖果满足时，则不必用更大的糖果满足，因为可以保留更大的糖果去满足需求因子更大的孩子
    3. 孩子的需求因子更小，则更容易满足。所以优先从需求因子小的孩子尝试，可以得到正确的结果
 */
int find_content_children(std::vector<int>& g, std::vector<int>& s){
    // g是需求因子数组， s是糖果大小数组
    std::sort(g.begin(), g.end());
    std::sort(s.begin(), s.end());
    int child = 0, cookie = 0;
    while(child < g.size() && cookie < s.size()) {
        if(g[child] < s[cookie]){
            child ++;
        }
        cookie++;
    }
    return child;
}

int main(int argc, char** argv) {
    std::vector<int> g{5, 10, 2, 9, 15, 9};
    std::vector<int> s{6, 1, 20, 3, 8};
    int num_content = find_content_children(g, s);
    std::cout << num_content << std::endl;
}