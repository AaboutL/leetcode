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


bool cmp(const std::pair<int, int>& a, const std::pair<int, int>& b){
    return a.first < b.first;
}

int find_min_arrow_shots(std::vector<std::pair<int, int>>& points){
    if(points.size() == 0)
        return 0;
    std::sort(points.begin(), points.end(), cmp);
    int shoot_num = 1;
    int shoot_begin = points[0].first;
    int shoot_end = points[0].second;
    for (int i = 1; i< points.size(); i++){
        if(shoot_end >= points[i].first){
            shoot_begin = points[i].first;
            if(shoot_end > points[i].second){
                shoot_end = points[i].second;
            }
        }
        else{
            shoot_num++;
            shoot_begin = points[i].first;
            shoot_end = points[i].second;
        }
    }
    return shoot_num++;
}

int main(int argc, char** argv) {
    std::vector<std::pair<int, int>> nums{{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    std::cout << find_min_arrow_shots(nums) << std::endl;
}