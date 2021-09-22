#include "main.hpp"
#include <iostream>
#include <stack>

using namespace std;

ListNode* Solution::reverseKGroup(ListNode* head, int k){
    stack<ListNode*> storage;
    ListNode* curPtr = head;
    if (k == 1){
        return head;
    }
    for (int i = 0; i < k; i++){
        if (curPtr == nullptr){
            return head;
        }
        storage.push(curPtr);
        curPtr = curPtr->next;
    }
    ListNode* reverseHead = storage.top();
    ListNode* nextRec = reverseHead->next;
    storage.pop();
    reverseHead->next = storage.top();
    for (int i = 0; i < k - 1; i++){
        ListNode* reverseCur = storage.top();
        storage.pop();
        if (storage.empty()){
            reverseCur->next = reverseKGroup(nextRec, k);
        }
        else{
            reverseCur->next = storage.top();
        }   
    }
    return reverseHead;
}




int main(int argc, char* argv[]){
    ListNode *empty = new ListNode();
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    Solution sol;
    auto result = sol.reverseKGroup(a1, 1);
    while (result){
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;
    return 0;
}