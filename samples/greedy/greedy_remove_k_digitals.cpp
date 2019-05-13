//
// Created by aal on 19-4-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 已知一个使用字符串表示的非负整数num，将num中k个数字移除，求剩下的数字可以组成的最小的新数
 * 分析：若去掉一个数字之后，为了使剩下的数最小，则对于新数字，优先让最高位最小，其次是次高位最小。。。
 * 规律：从数字的高位向低位遍历，如果对应的数字大于下一位数字，则把该位数字去掉。
 * 使用栈来存储最终结果，并处理删除操作。
 * 从高位向低位遍历num，如果遍历的数字大于栈顶元素，则将该数字入栈。
 * 如果小于栈顶元素，则进行pop弹栈，直到栈空，或不能再删除数字，或栈顶小于当前元素为止。
 */

std::string remove_k_digits(const std::string& nums, int k){
    std::vector<int> S; // 表示栈
    std::string result = "";
    for (int i = 0; i< nums.size(); i++){
        int number = nums[i]-'0';
        while(S.size()!=0 && S[S.size()-1] > number && k>0){
            S.pop_back();
            k--;
        }
        if(number!=0 || S[S.size()-1] < number){
            S.push_back(number);
        }
    }
    while(S.size()!=0 && k > 0){
        S.pop_back();
        k--;
    }
    for(int i = 0; i < S.size(); i++){
        result.append(1, '0'+S[i]);
    }
    if(result==""){
        result = "0";
    }
    return result;
}

int main(int argc, char** argv) {
    std::string result = remove_k_digits("1432219", 3);
    std::cout << result << std::endl;
}