//
// Created by aal on 19-4-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 一个数组存储了非负整型数据, 数组中的第i个元素nums[i]代表可以从数组第i个位置最多向前跳跃nums[i]步,已知数组个元素的情况下,求跳到最后一个位置，
 * 最少需要跳跃几次
 * 思考: 希望用最少的跳跃到达最后的位置，则需要明确何时进行跳跃最合适。
 * 思路: 只有在无法到达更远的位置时，才选择跳跃（但是此时准备跳跃的位置并不一定是当前遍历到的位置）。而选择从这之间的哪个位置进行跳跃呢？ 应选择
 *       一个可以到达更远位置的位置，跳到这个位置之后，再往前跳。
 * 初始化: 设置变量min_jump表示跳跃的最小次数.
 *        current_max_index为当前可以到达的最远位置, 初始为nums【0】。
 *        pre_max_max_index为再遍历各个位置的过程中， 各个位置可达到的最远的位置, 初始为nums[0]。
 *
 */

int min_jump(std::vector<int>& nums) {
   if(nums.size() < 2)
       return 0;
   int current_max_index = nums[0];
   int pre_max_max_index = nums[0];
   int min_jump = 1;
   for (int i = 0; i < nums.size(); i++){
       if(i > current_max_index){
           min_jump++;
           current_max_index = pre_max_max_index;
       }
       if(pre_max_max_index < nums[i] + i){
           pre_max_max_index = nums[i] + i;
       }
   }
   return min_jump;
}

int main(int argc, char** argv) {
    std::vector<int> nums{2, 3, 1, 1, 4};
    std::cout << min_jump(nums) << std::endl;
}