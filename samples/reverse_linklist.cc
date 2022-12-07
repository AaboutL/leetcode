#include <iostream>

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class ReverseSolution{
public:
    // 递归反转
    ListNode* reverse(ListNode* head){
        // 空或者只有一个，直接返回
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        ListNode* last = reverse(head->next); // 递归的反转当前结点之后的结点，返回的last是反转之后链表的头结点
        head->next->next = head; // 把当前结点和其后的结点进行反转
        head->next = nullptr; // 当前这次递归把head->next置空了，但是返回到上一层递归时，通过head->next->next = head进行了新的指向
        return last; // 可以看出没有对last进行任何操作，每次递归调用后都把last直接返回，所以last就是原链表的最后一个结点。
    }

    // 本地反转，迭代
    ListNode* reverse_iterate(ListNode* head){
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* nxt = head;
        while(cur != nullptr){
            nxt = cur->next; // 保持住cur之后的结点，防止断链
            cur->next = pre; // 反转当前结点的指向
            pre = cur; // 向后移动
            cur = nxt; // 向后移动
        }
        return pre; // 循环到最后，cur变成空了，所以返回pre
    }

    // 反转链表前N个结点：反转以head为起点的N个结点，返回新的头结点
    ListNode* successor = nullptr; // 记录第N个结点的后驱结点
    ListNode* reverseN(ListNode* head, int n){
        if(n == 1){
            // 有两个作用：一是当只反转一个结点时，直接返回；二是当递归到最后时，要保存后驱结点
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

    // 反转链表的一部分，反转[m, n]区间内的部分
    ListNode* reverseBetween(ListNode* head, int m, int n){
        if(m == 1){
            return reverseN(head, n);
        }
        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }

    // k个一组反转
    ListNode* reverseKGroup(ListNode* head, int k){
        for(int i = 0; i < k; i++){
            head = head->next;
        }
    }

};

int main(){
    ListNode* n1 = new ListNode(1);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(3);
    ListNode* n4 = new ListNode(4);
    ListNode* n5 = new ListNode(5);
    ListNode* n6 = new ListNode(6);
    ListNode* n7 = new ListNode(7);
    ListNode* n8 = new ListNode(8);
    ListNode* n9 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = nullptr;

    ReverseSolution RS;
    ListNode* ln = RS.reverseN(n1, 4);
    while(ln){
        std::cout << ln->val << "  ";
    }
    std::cout << std::endl;
}