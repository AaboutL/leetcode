//
// Created by slam on 19-4-9.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <chrono>
/* 0015
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 * 注意：答案中不可以包含重复的三元组
 * 思路： 三个数相加等于0, 相当与两个数相加，判断和是否为数组中其他数的相反数。
 *      用到了排序和首尾指针。排序之后，在遍历过程中，可以快速过滤掉相同的元素。
 * */
class Solution0001{
public:
    bool compare(int i, int j) {return (i < j);}

    std::vector<std::vector<int>> three_sum(std::vector<int>& nums) {
        if (nums.size() < 3)
            return {};
        std::sort(nums.begin(), nums.end());
        if(nums[0]>0 || nums[nums.size()-1]<0)
            return {};
        std::vector<std::vector<int>> rst;
        for (int i = 0; i < nums.size()-2; i++){
            if((i==0||i>0 && nums[i]!=nums[i-1])&&nums[i]<=0){
                int j = i + 1, k = nums.size() -1, sum = 0 - nums[i];
                while(j < k){
                    if (nums[j] + nums[k] == sum){
                        rst.emplace_back(std::vector<int>{nums[i], nums[j], nums[k]});
                        while(j < k && nums[j]==nums[j+1]) j++;
                        while(j < k && nums[k] == nums[k-1]) k--;
                        j++; // j+1 和 k+1 是因为在当前这个循环里， 去查找其他符合条件的元组， 因为可能不止一对j，k的组合使得和为sum
                        k--; // 与下一个循环没有关系。因为每个循环的j都是从i+1开始，k从最后一个数开始
                    }
                    else if(nums[j] + nums[k] < sum){
                        while(j < k && nums[j] == nums[j+1]) j++;
                        j++;
                    }
                    else {
                        while(j < k && nums[k] == nums[k-1]) k--;
                        k--;
                    }
                }
            }
        }
        return rst;
    }
};

int main(int argc, char** argv) {
    std::vector<int> nums{1,8,6,2,5,4,8,3,7};
    Solution0001 s;
    std::chrono::steady_clock::time_point t1 = std::chrono::steady_clock::now();

    int rst = s.max_area2(nums);

    std::chrono::steady_clock::time_point t2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> dur = std::chrono::duration_cast<std::chrono::duration<double>>(t2 - t1);
    std::cout << "time cost : " << dur.count() << std::endl;
    std::cout << rst << std::endl;
    return 0;
}