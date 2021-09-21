#ifndef MAIN
#define MAIN

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr){}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
    ListNode *mergeTwoLists(ListNode* l1, ListNode* l2);
    ListNode *mergeTwoListsR(ListNode* l1, ListNode* l2);
};

#endif

