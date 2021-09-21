#include "main.hpp"
#include <iostream>
using namespace std;

ListNode* Solution::mergeKLists(vector<ListNode*>& lists){
    int tmp = 0;
    vector<int> nullLists;
    for (int i = 0; i < lists.size(); i++){
        if (lists[i] != nullptr){
            if (lists[tmp] == nullptr){
                tmp = i;
            }
            tmp = (lists[tmp]->val <= lists[i]->val) ? tmp : i;
        }
        else{
            nullLists.push_back(i);
        }
    }
    if (nullLists.size() == lists.size()){
        return nullptr;
    }
    ListNode* cur = lists[tmp];
    lists[tmp] = lists[tmp]->next;
    for (int i = 0; i < nullLists.size(); i++){
        lists.erase(lists.begin() + nullLists[i] - i);
    }
    nullLists.clear();
    cur->next = mergeKLists(lists);
    return cur;
}

int main(int argc, char* argv[]) {
    Solution sol;
    vector<ListNode*> lists;
    ListNode *empty = new ListNode();
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(5);
    ListNode *b1 = new ListNode(1);
    ListNode *b2 = new ListNode(3);
    ListNode *b3 = new ListNode(4);
    ListNode *c1 = new ListNode(2);
    ListNode *c2 = new ListNode(6);
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    c1->next = c2;
    lists.push_back(a1);
    lists.push_back(b1);
    lists.push_back(c1);
    ListNode* result = sol.mergeKLists(lists);
    while (result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}