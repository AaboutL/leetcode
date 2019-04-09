//
// Created by slam on 19-4-9.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <chrono>
/* 0011
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 说明：你不能倾斜容器，且 n 的值至少为 2。。
 * 思路: 1. 暴力搜索的方法, 遍历两遍数据.
 *      2. 目标函数 (q - p) * max(height[p], height[q]), 使用首尾指针, 两个指针分别向中间移动, 每一步都记录最大的面积, 这样就可以缩小搜索空间.
 *          移动的策略: 因为每次只移动一个指针, 而且step为1, 所以每次移动的是值较小的指针.
 * */
class Solution0001{
public:

    int max_area1(const std::vector<int>& nums) {
        int max_area = 0;
        for (int p = 0; p < nums.size()-1; p++) {
            for (int q = p + 1; q < nums.size(); q++){
                int area = (q - p) * std::min(nums[p], nums[q]);
                if (area > max_area)
                    max_area = area;
            }
        }
        return max_area;
    }
    int max_area2(const std::vector<int>& height) {
        int max_area = 0;
        int p = 0, q = height.size() - 1;
        while(p < q){
            max_area = std::max(max_area, (q - p) * std::min(height[p], height[q]));
            if (height[p] > height[q]) q--;
            else p++;
        }
        return max_area;
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