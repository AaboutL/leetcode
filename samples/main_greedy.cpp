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

int remove_k_digits(std::string& nums, int k){
    if(nums.size() < 2){
        return nums.size();
    }
    static const int BEGIN=0;
    static const int UP = 1;
    static const int DOWN=2;
    int STATE=BEGIN;
    int max_length = 1;
    for (int i = 1; i < nums.size(); i++){
        switch (STATE){
            case BEGIN:
                if(nums[i] > nums[i-1]){
                    STATE = UP;
                    max_length++;
                }
                else if(nums[i] < nums[i - 1]){
                    STATE = DOWN;
                    max_length++;
                }
                break;
            case UP:
                if(nums[i] < nums[i-1]){
                    STATE = DOWN;
                    max_length++;
                }
                break;
            case DOWN:
                if(nums[i] > nums[i - 1]){
                    STATE = UP;
                    max_length++;
                }
                break;
        }
    }
    return max_length;
}

int main(int argc, char** argv) {
    std::vector<int> nums{1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    int max_length = wiggle_max_length(nums);
    std::cout << max_length << std::endl;
}