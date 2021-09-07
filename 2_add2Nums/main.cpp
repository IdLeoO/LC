#include <iostream>
#include "main.hpp"

using namespace std;

class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* result = new ListNode;
//         int mult = 1;
//         while (l1 != nullptr || l2 != nullptr){
//             if (l1 != nullptr){
//                 result->val += l1->val * mult;
//                 l1 = l1->next;
//             }
//             if (l2 != nullptr){
//                 result->val += l2->val * mult; 
//                 l2 = l2->next;
//             }
//             mult *= 10; 
//         }
//         return result;        
//     }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *resultDigit = new ListNode;
        ListNode *l1Next = nullptr;
        ListNode *l2Next = nullptr;
        if (l1 == nullptr && l2 == nullptr){
            delete resultDigit;
            return nullptr;
        }
        if (l1 != nullptr){
            resultDigit->val += l1->val;
            l1Next = l1->next;
        }
        if (l2 != nullptr){
            resultDigit->val += l2->val;
            l2Next = l2->next;
        }
        if (resultDigit->val >= 10){
            resultDigit->val -= 10;
            ListNode *carry = new ListNode(1);
            ListNode *tmp = addTwoNumbers(carry, l1Next);
            resultDigit->next = addTwoNumbers(tmp, l2Next);
        }
        else{
            resultDigit->next = addTwoNumbers(l1Next, l2Next);
        }
        return resultDigit;
    }

};

int main(int args, char* argv[]){
    Solution sol;
    ListNode* digit1 = new ListNode(0);
    ListNode* digit2 = new ListNode(9);
    ListNode* digit3 = new ListNode(8);
    digit1->next = digit2;
    digit2->next = digit3;

    ListNode* digit11 = new ListNode(4);
    ListNode* digit12 = new ListNode(3);
    ListNode* digit13 = new ListNode(2);
    digit11->next = digit12;
    digit12->next = digit13;
    ListNode *result = sol.addTwoNumbers(digit1, digit11);

    while (result != nullptr){
        cout << result->val << endl;
        result = result->next;
    }

    return 0;    
}
