//
// Created by aal on 19-4-25.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/*
 * n组括号，有多少种可能的组合
 * 思路：1，左括号和右括号的数量不可能超过n
 *      2，每放一个左括号，才能放右括号，右括号不能先于左括号放置。
 *      根据1,2得到递归的限制条件：
 *      1. 左括号和右括号的数量，最多放置n个
 *      2，若左括号的数量<=右括号数量，不可以进行放置右括号的递归。
 * */

class Solution{
public:
    std::vector<std::string> generate_parenthesis(int n) {
        std::vector<std::string> result;
        std::string item;
        generate(item, n, n, result);
        return result;
    }

private:
    void generate(std::string& item, int left, int right, std::vector<std::string>& result){ // left,right是当前还可以放置的数量
        if(left==0 && right==0){
            result.push_back(item);
            return;
        }
        if(left>0){
            item = item+"(";
            generate(item, left-1, right, result);
        }
        if(left < right){
            item = item+")";
            generate(item, left, right-1, result);
        }
    }
};

int main(int argc, char** argv){
    // 递归与回溯的方法
    Solution s;
    std::vector<std::string> result;
    result = s.generate_parenthesis(3);
    for(int i = 0; i< result.size(); i++){
        std::cout << result[i] << ' ';
    }

    return 0;
}