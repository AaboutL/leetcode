//
// Created by slam on 19-4-22.
//

// heap在stl中通过优先级队列实现. std::priority_queue
#include <iostream>
#include <queue>

// 最大堆和最小堆在使用时, 最大堆往往存储较小的一部分数据, 最小堆总是存储较大的一部分数据.
// 因为堆的操作都是在堆顶进行的. 在进行push top pop等操作时, 不要管堆内是如何调整顺序的, 只要记住最大堆的堆顶是最大值, 最小堆的堆顶是最小值.
// 找到数组中的中位数. 这个数据可能是动态增长的.
class MedianFinder{
public:
    MedianFinder(){}
    void addNum(int num);
    double findMedian();

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap;
    std::priority_queue<int, std::vector<int>, std::less<int>> big_heap;
};

void MedianFinder::addNum(int num){
    if(big_heap.empty()){
        big_heap.push(num);
        return;
    }
    if(big_heap.size() == small_heap.size()){
        if(num < big_heap.top()){
            big_heap.push(num);
        }
        else{
            small_heap.push(num);
        }
    }
    else if(big_heap.size() > small_heap.size()){
        if(num > big_heap.top()){
            small_heap.push(num);
        }
        else{
            small_heap.push(big_heap.top());
            big_heap.pop();
            big_heap.push(num);
        }
    }
    else if(big_heap.size() < small_heap.size()){
        if(num < small_heap.top()){
            big_heap.push(num);
        }
        else{
            big_heap.push(small_heap.top());
            small_heap.pop();
            small_heap.push(num);
        }
    }
}

double MedianFinder::findMedian() {
    if(big_heap.size() == small_heap.size())
        return (big_heap.top() + small_heap.top()) / 2;
    else if(big_heap.size() > small_heap.size())
        return big_heap.top();
    else return small_heap.top();
}


int main(int argc, char** argv) {
    std::priority_queue<int> big_heap; // 默认是大根堆(最大堆)
    std::priority_queue<int, std::vector<int>, std::greater<int>> small_heap; // 小根堆(最小堆)
    std::priority_queue<int, std::vector<int>, std::less<int>> big_heap2;
    // 已知一个未排序的数组, 求这个数组中第K大的数字.

    std::vector<int> nums{6, 10, 1, 7, 99, 4, 33};
    MedianFinder finder;
    for (int i = 0; i < nums.size(); i++) {
        finder.addNum(nums[i]);
        std::cout << "current median: " << finder.findMedian() << std::endl;
    }
}
