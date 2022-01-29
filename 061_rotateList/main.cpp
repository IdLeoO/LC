#include "main.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

ListNode* Solution::rotateRight(ListNode* head, int k){
   if (k == 0 || head == nullptr) return head;
   int len = 0;
   ListNode* end = head;
   for (ListNode* i = head; i != nullptr; i = i->next){
      len++;
      end = i;
   }
   if (k % len == 0) return head;
   ListNode* newEnd = head;
   for (int i = 0; i < len - k % len - 1; i++){
      newEnd = newEnd->next;
   }
   ListNode* newHead = newEnd->next;
   newEnd->next = nullptr;
   end->next = head;
   return newHead;
}
 
int main(int argc, char* argv[]){
   Solution sol;
   ListNode l5 (5);
   ListNode *pl5 = &l5;
   ListNode l4 (4, pl5);
   ListNode *pl4 = &l4;
   ListNode l3 (3, pl4);
   ListNode *pl3 = &l3;
   ListNode l2 (2, pl3);
   ListNode *pl2 = &l2;
   ListNode l1 (1, pl2);
   ListNode *pl1 = &l1;

   auto x = sol.rotateRight(pl1, 5);
   while (x != nullptr){
      cout << x->val << ' ';
      x = x->next;
   }
   cout << endl;


}