// 725. Split Linked List in Parts

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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int size = 0;
        int front, back;
        vector<ListNode*> v;
        for(ListNode* tmp = root; tmp; tmp = tmp -> next) {
            size++;
        }
        
        if(size < k) {
            ListNode* a;
            for(int i=0; i<k; i++) {
                if(root != NULL) {
                    a = root;
                    root = root -> next;
                    a -> next = NULL;
                    v.push_back(a);
                }
                else v.push_back(NULL);
            }
            return v;
        }
        
        front = size % k; // size / k + 1 개
        back = k - size % k; // size / k 개
        ListNode* roottmp;
        ListNode* tmp;
        for(int i=0; i<front; i++) {
            roottmp = root;
            for(int j=0; j<size / k; j++) {
                root = root -> next;
            }
            tmp = root;
            root = root -> next;
            tmp -> next = NULL;
            v.push_back(roottmp);
        }
        for(int i=0; i<back; i++) {
            roottmp = root;
            for(int j=0; j<size / k - 1; j++) {
                root = root -> next;
            }
            tmp = root;
            root = root -> next;
            tmp -> next = NULL;
            v.push_back(roottmp);
        }
        return v;
    }
};