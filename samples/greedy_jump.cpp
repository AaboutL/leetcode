//
// Created by aal on 19-4-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 一个数组存储了非负整型数据, 数组中的第i个元素nums[i]代表可以从数组第i个位置最多向前跳跃nums[i]步,已知数组个元素的情况下,求是否可以从数组的
 * 第0个位置跳跃到数组的最后一个元素的位置.
 * 思考: 从0位置可以向后跳跃的位置为1, 2, ..., nums[0].在这几个位置中到底应该跳到哪个位置?
 * 思路: 在当前位置和之前所有的位置能够向后到达的最远的位置.(只考虑当前能够到达的最远的位置, 就是贪心)
 * 首先记录从当前位置可以到达的最远的位置.保存在数组index中.
 * 初始化: 设置变量jump表示当前的位置, 初始化为0.
 *        设置变量max_index表示从位置0到第jump(不包括)位置这个过程中, 所能到达的最远的位置, 初始化为index[0]
 *        利用jump遍历index数组, 知道jump到达index数组尾部,或者jump超过max_index, 遍历过程中更新max_index
 *        若最终jump为数组长度, 则返回true, 否则返回false
 *
 */

bool can_jump(std::vector<int>& nums) {
    std::vector<int> index;
    for (int i = 0; i < nums.size(); i++){
        index.push_back(i + nums[i]);
    }
    int jump = 0;
    int max_index = index[0];
    while(jump < index.size() && jump <= max_index){
        if(max_index < index[jump]){
            max_index = index[jump];
        }
        jump ++;
    }
    if(jump == index.size()){
        return true;
    }
    return false;
}

int main(int argc, char** argv) {
    std::vector<int> nums{3, 2, 1, 0, 4};
    std::cout << can_jump(nums) << std::endl;
}