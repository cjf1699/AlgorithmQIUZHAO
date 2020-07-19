/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // 1. 迭代解法
        ListNode *newhead = new ListNode(0);
        ListNode *p = newhead;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 == nullptr) {
            p->next = l2;
        } else {
            p->next = l1;
        }
        return newhead->next;
        
    // 2. 递归解法
        if (l1 == nullptr)  return l2;
        if (l2 == nullptr)  return l1;

        return l1->val < l2->val ? (l1->next = mergeTwoLists(l1->next, l2), l1) : (l2->next = mergeTwoLists(l2->next, l1), l2);
    }   
};

// 1. 双指针，迭代
// 2. 递归，