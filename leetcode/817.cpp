// 817. Linked List Components

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
    int numComponents(ListNode* head, vector<int>& G) {
        ListNode* node1 = head;
        int result = 0;
        bool flag = false;
        bool arr[10001] = {0, };
        for(int i : G) {
            arr[i] = 1;
        }
        for(ListNode* node = head; node; node = node->next) {
            if(arr[node -> val] == 1 && flag == false) {
                flag = true;
                result++;
            }
            else if(arr[node -> val] == 0 && flag == true) {
                flag = false;
            }
        }
        
        return result;
    }
};
