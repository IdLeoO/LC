#include "main.hpp"
#include <iostream>

ListNode* Solution::removeNthFromEnd(ListNode *head, int n){
    ListNode *current = head;
    if (head == nullptr){
        return nullptr;
    }
    int size = 1;
    while (current->next != nullptr){
        current =  current->next;
        size++;
    }
    if (n == size){
        head = head->next;
        return head;
    }
    current = head;
    int cnt = 1; // find the previous node of the target
    while (n + cnt != size){
        current = current->next;
        cnt ++;
    }
    ListNode *target = current->next;
    current->next = target->next;
    delete target;
    return head;
}
// With the fast ptr lagging for n-1 steps, the target node will
// be reached when the fast node goes to the end of the linked list
ListNode* Solution::removeNthFromEnd1(ListNode* head, int n){
    ListNode *slow = head, *fast = head, *slowPrev = head;
    for (int i = 0; i < n - 1; i++){
        fast = fast->next;
    }
    while (fast->next != nullptr){
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (slow == head){
        head = head->next;
        return head;
    }
    slowPrev->next = slow->next;
    delete slow;
    return head;
}

int main (int argc, char* argv[]){
    Solution sol;
    ListNode *head = new ListNode(1, nullptr);
    ListNode *prev = head;
    for (int i = 2; i < 6; i++){
        ListNode *node = new ListNode(i, nullptr);
        prev->next = node;
        prev = node;
    }
    auto *result = sol.removeNthFromEnd1(head, 2);
    while (result->next != nullptr){
        std::cout << result->val;
        result = result->next;
    }
    std::cout << result->val << std::endl;
}