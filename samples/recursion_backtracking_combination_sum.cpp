//
// Created by aal on 19-4-25.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

/*
 * 已知一组数（有重复元素），求这组数组成的所有子集中，各个元素想家的和为整数target的子集，结果中不能有重复的子集,
 * 因为有重复元素，所以组成的子集中可能有重复的集合。
 * 如：{2， 1， 2， 2}. 组成的子集{2,1,2}和{1，2,2}就是重复的。
 * 重复的情况有两种：
 * 1，不用位置的元素组成的是同一个子集，顺序相同。如位置0,1,2和位置0,1,3.
 * 2，不同位置的元素组成的是同一个子集，顺序不同。如位置0,1,2和位置1,2,3.
 * 解决方法：
 * 先对数组进行排序，{1， 2， 2， 2}，这样组成重复子集，它们的顺序是相同的。
 * 然后使用set去重。
 * 如果用subset2的方法去找到所有的子集，然后对每个子集判断其和是否为target，则会进行很多不必要的尝试。因为子集的前几个元素之和可能已经大于
 * target了，再去查找这个子集，就没有必要了。
 * 所以，可以对回溯方法进行剪枝，对于已经确定不能满足要求的，直接return。
 * */

class Solution{
public:
    std::vector<std::vector<int>> combination_sum(std::vector<int>& nums, int target) {
        std::vector<std::vector<int>> results;
        std::vector<int> item; // 子集的元素
        std::set<std::vector<int>> res_set;
        std::sort(nums.begin(), nums.end());
        results.push_back(item);
        generate(0, nums, item, results, res_set, 0, target);
        return results;
    }

private:
    void generate(int i, std::vector<int>& nums, std::vector<int>& item, std::vector<std::vector<int>>& result,
            std::set<std::vector<int>>& res_set, int sum, int target){
        if(i >= nums.size() || sum > target){
            return;
        }
        sum += nums[i];
        item.push_back(nums[i]);
        if(target==sum && res_set.find(item) == res_set.end()){
            result.push_back(item);
            res_set.insert(item);
        }
        generate(i+1, nums, item, result, res_set, sum, target); // 第一次选择元素i，然后递归调用
        sum -= nums[i];
        item.pop_back();
        generate(i+1, nums, item, result, res_set, sum, target); // 第二次不选择元素i，然后递归调用。
    }
};

int main(int argc, char** argv){
    std::vector<int> nums{10, 1, 2, 7, 6, 1, 5};

    // 递归与回溯的方法
    Solution s;
    std::vector<std::vector<int>> result;
    result = s.combination_sum(nums, 8);
    for(int i = 0; i< result.size(); i++){
        for (int j = 0; j < result[i].size(); j++){
            std::cout << result[i][j] << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}