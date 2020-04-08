// 445. Add Two Numbers II

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = nullptr, *p = nullptr;
        vector<int> v1;
        vector<int> v2;
        int carryOn = 0;
        
        for(ListNode* node1 = l1; node1; node1 = node1 -> next) {
            int tmp;
            tmp = node1 -> val;
            v1.push_back(tmp);
        }
        for(ListNode* node2 = l2; node2; node2 = node2 -> next) {
            int tmp;
            tmp = node2 -> val;
            v2.push_back(tmp);
        }
        
        while(v1.size() != v2.size()) {
            vector<int>::iterator it1; it1 = v1.begin();
            vector<int>::iterator it2; it2 = v2.begin();
            if(v1.size() > v2.size()) v2.insert(it2, 0);
            else v1.insert(it1, 0);
        }
        
        for(int i=v1.size()-1; i>-1; i--) {
            int tmp = v1[i] + v2[i] + carryOn;
            if(tmp >= 10) carryOn = 1;
            else carryOn = 0;
            tmp %= 10;
            
            p = new ListNode(tmp);
            p -> next = result;
            result = p;
        }
        
        if(carryOn == 1) {
            p = new ListNode(1);
            p -> next = result;
            result = p;
        }

        return result;
    }
};
