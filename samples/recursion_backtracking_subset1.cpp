//
// Created by aal on 19-4-25.
//

#include <iostream>
#include <vector>

/*
 * 已知一组数（无重复元素），求这组数可以组成的所有子集，结果中不能有重复的子集
 * */

class Solution{
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> results;
        std::vector<int> item; // 子集的元素
        results.push_back(item);
        generate(0, nums, item, results);
        return results;
    }

private:
    void generate(int i, std::vector<int>& nums, std::vector<int>& item, std::vector<std::vector<int>>& result){
        if(i >= nums.size()){
            return;
        }
        item.push_back(nums[i]);
        result.push_back(item);
        generate(i+1, nums, item, result); // 第一次选择元素i，然后递归调用
        item.pop_back();
        generate(i+1, nums, item, result); // 第二次不选择元素i，然后递归调用。
    }
};

std::vector<std::vector<int>> subset(std::vector<int>& nums){
    std::vector<std::vector<int>> res;
    int all_set = 1 << nums.size();
    for (int i = 0; i < all_set; i++){
        std::vector<int> item;
        for(int j = 0; j < nums.size(); j++){
            if(i & (1 << j)){
                item.push_back(nums[j]);
            }
        }
        res.push_back(item);
    }
    return res;
}

int main(int argc, char** argv){
    std::vector<int> nums{1, 2, 3};

    // 递归与回溯的方法
    Solution s;
    std::vector<std::vector<int>> result;
    result = s.subsets(nums);
    for(int i = 0; i< result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            std::cout << result[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    // 位运算的方法
    std::vector<std::vector<int>> res;
    res = subset(nums);
    for(int i = 0; i< result.size(); i++){
        for (int j = 0; j < res[i].size(); j++){
            std::cout << res[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}