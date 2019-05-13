//
// Created by aal on 19-4-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

/*
 * 已知在一个平面上有一定数量的气球， 平面可以看作一个坐标系，在x轴上的不同位置安排弓箭手向y轴方向射箭， 弓箭可以向y轴走无穷远；
 * 给定每个气球的宽度xstart <= x <= xend; 问至少需要多少弓箭手， 将全部气球打破
 * 思路：如果只有一个气球，则必须至少有一个弓箭手。如果气球宽度有重叠时，则只需要把一个弓箭手安排在重叠的位置。
 *      如果新的气球无法被射穿，则需要安排新的弓箭手，并且这个弓箭手的起始位置和终止位置需要更新。
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