//
// Created by slam on 19-4-22.
//

// heap在stl中通过优先级队列实现. std::priority_queue
#include <iostream>
#include <queue>

// 最大堆和最小堆在使用时, 最大堆往往存储较小的一部分数据, 最小堆总是存储较大的一部分数据.
// 因为堆的操作都是在堆顶进行的. 在进行push top pop等操作时, 不要管堆内是如何调整顺序的, 只要记住最大堆的堆顶是最大值, 最小堆的堆顶是最小值.

int find_Kth_largest(std::vector<int>& nums, int k);
int main(int argc, char** argv) {
    std::priority_queue<int> big_heap; // 默认是大根堆(最大堆)
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap; // 小根堆(最小堆)
    std::priority_queue<int, std::vector<int>, std::less<int>> big_heap2;
    // 已知一个未排序的数组, 求这个数组中第K大的数字.

    std::vector<int> nums{3,2,1,5,6,4};
    int Kth_nums = find_Kth_largest(nums, 2);
    std::cout << "Kth_largest: " << Kth_nums << std::endl;
}

int find_Kth_largest(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap;
    for (int i = 0; i < nums.size(); i++) {
        if(small_heap.size() < k){
            small_heap.push(nums[i]);
        }
        else if(small_heap.top() < nums[i]){ // 逐步把堆中的最小值替换掉,最后堆中剩下的就是前K大的数据.又因为这是个最小堆, 所以堆顶就是第K大的值.
            small_heap.pop();
            small_heap.push(nums[i]);
        }
    }
    return small_heap.top();
}