#include "main.hpp"
#include <iostream>
using namespace std;


ListNode* Solution::swapPairs(ListNode* head){
    if (head == nullptr || head->next == nullptr){
        return head;
    }
    ListNode *nextHead = head->next->next;
    ListNode *curHead = head->next;
    curHead->next = head;
    head->next = swapPairs(nextHead);
    return curHead;
}

int main(int argc, char* argv[]){
    ListNode *empty = new ListNode();
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    Solution sol;
    auto result = sol.swapPairs(a1);
    while (result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}