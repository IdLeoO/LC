#include "main.hpp"
#include <iostream>

ListNode* Solution::mergeTwoLists(ListNode* l1, ListNode* l2){
    ListNode *head = new ListNode();
    ListNode *curPtr = head;
    bool emptyL1 = (l1 == nullptr) ? 1 : 0;
    bool emptyL2 = (l2 == nullptr) ? 1 : 0;
    if (emptyL1 && emptyL2){
        return nullptr;
    }
    else if(emptyL1){
        head = l2;
        return head;
    }
    else if(emptyL2){
        head = l1;
        return head;
    }

    if (l1->val <= l2->val){
        head->val = l1->val;
        l1 = l1->next;
    }
    else{
        head->val = l2->val;
        l2 = l2->next;
    }
    while (l1 != nullptr || l2 !=nullptr){
        if (l1 == nullptr){
            curPtr -> next = l2;
            return head;
        }
        else if (l2 == nullptr){
            curPtr -> next = l1;
            return head;
        }
        else{
            if (l1->val <= l2->val){
                curPtr->next = new ListNode(l1->val);
                l1 = l1->next;
                curPtr = curPtr->next;
            }
            else{
                curPtr->next = new ListNode(l2->val);
                l2 = l2->next;
                curPtr = curPtr->next;
            }
        }
    }
    return head;
}

// divide and conquer
ListNode* Solution::mergeTwoListsR(ListNode* l1, ListNode* l2){
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;
    if (l1->val < l2->val){
        l1->next = mergeTwoListsR(l1->next, l2);
        return l1;
    }
    else{
        l2->next = mergeTwoListsR(l1, l2->next);
        return l2;
    }
}


int main(int argc, char* argv[]){
    Solution sol;
    ListNode *empty = new ListNode();
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(4);
    ListNode *b1 = new ListNode(1);
    ListNode *b2 = new ListNode(3);
    ListNode *b3 = new ListNode(4);
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    ListNode *result = sol.mergeTwoListsR(a1, b1);
    if (result == nullptr){
        std::cout << "" << std::endl;
        return 0;
    }
    while (result->next != nullptr){
        std::cout << result->val << " ";
        result = result->next;
    }
    std::cout << result->val<< std::endl;
}