//
// Created by aal on 19-4-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 一个整数序列，如果两个相邻元素的差恰好正负(负正)交替出现，则该序列被称为摇 摆序列。一个小于2个元素的序列直接为摇摆序列。
 * 给定一个随机序列，求满足摇摆条件的最长子序列的长度。注意是最长子序列，并不要求连续。
 * 规律：当序列的一段为连续的递增或递减时，为了形成摇摆子序列，只需要保留这一段的首尾元素，这样更可能使得尾部的后一个元素成为摇摆元素。
 * 思路：设置三种状态：起始，上升，下降。当状态切换时，最长序列的长度加一
 * 这里贪心体现在，当出现连续上升（或者下降）时，贪心的选择这一段中最大（或最小）的数，当做摇摆元素。
 */

int wiggle_max_length(std::vector<int>& nums){
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