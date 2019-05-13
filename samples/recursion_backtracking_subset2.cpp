//
// Created by aal on 19-4-25.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/*
 * 已知一组数（有重复元素），求这组数可以组成的所有子集，结果中不能有重复的子集
 * 因为有重复元素，所以组成的子集中可能有重复的集合。
 * 如：{2， 1， 2， 2}. 组成的子集{2,1,2}和{1，2,2}就是重复的。
 * 重复的情况有两种：
 * 1，不用位置的元素组成的是同一个子集，顺序相同。如位置0,1,2和位置0,1,3.
 * 2，不同位置的元素组成的是同一个子集，顺序不同。如位置0,1,2和位置1,2,3.
 * 解决方法：
 * 先对数组进行排序，{1， 2， 2， 2}，这样组成重复子集，它们的顺序是相同的。
 * 然后使用set去重。
 * */

class Solution{
public:
    std::vector<std::vector<int>> subsets_with_dup(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        std::vector<int> item; // 子集的元素
        std::set<std::vector<int>> res_set;
        std::sort(nums.begin(), nums.end());
        results.push_back(item);
        generate(0, nums, item, results, res_set);
        return results;
    }

private:
    void generate(int i, std::vector<int>& nums, std::vector<int>& item, std::vector<std::vector<int>>& result,
            std::set<std::vector<int>>& res_set){
        if(i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        if(res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, item, result, res_set); // 第一次选择元素i，然后递归调用
        item.pop_back();
        generate(i+1, nums, item, result, res_set); // 第二次不选择元素i，然后递归调用。
    }
};

int main(int argc, char** argv){
    std::vector<int> nums{2, 1, 2, 2};

    // 递归与回溯的方法
    Solution s;
    std::vector<std::vector<int>> result;
    result = s.subsets_with_dup(nums);
    for(int i = 0; i< result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            std::cout << result[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}