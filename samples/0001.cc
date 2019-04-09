//
// Created by slam on 19-4-9.
//
#include <iostream>
#include <vector>
#include <unordered_map>
/*
 * 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 * 思路: 暴力搜索,需要遍历两边数组.
 *      使用哈希map, key是数组的元素, value是元素的下标. 一边遍历数据, 一边建立hashmap, 并且查找当前被遍历的元素在hashmap中是否有符合的对应元素.
 * */
class Solution0001{
public:
    Solution0001(std::vector<int> nums, int target);

    std::vector<int> two_sum(const std::vector<int>& nums, int target) {
        std::unordered_map<int, int> hash_map;
        int size = nums.size();
        for (int i = 0; i < size; i ++) {
            auto it = hash_map.find(target - nums[i]);
            if(it != hash_map.end())
                return {i, it->second};
            else
                hash_map[nums[i]] = i;
        }
        return {0, 0};
    }

private:
    std::vector<int> nums_;
    int target_;
};

Solution0001::Solution0001(const std::vector<int> nums, int target):
                nums_(nums),
                target_(target){}

int main(int argc, char** argv) {
    std::vector<int> nums{2, 7, 11, 15};
    int target = 26;
    Solution0001 s(nums, target);
    std::vector<int> rst = s.two_sum(nums, target);
    std::cout << rst[0] << " " << rst[1] << std::endl;
    return 0;
}