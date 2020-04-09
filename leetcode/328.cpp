// 328. Odd Even Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL) return head;
        
        ListNode* tmp = head -> next;
        ListNode* odd_head = head;
        ListNode* even_head = tmp;
        
        while(head -> next != NULL && tmp -> next != NULL) {
            head -> next = tmp -> next;
            head = head -> next;
            if(tmp -> next != NULL) {
                tmp -> next = head -> next;
                tmp = tmp -> next;
            }
        }
        
        head -> next = even_head;
        return odd_head;
    }
};
