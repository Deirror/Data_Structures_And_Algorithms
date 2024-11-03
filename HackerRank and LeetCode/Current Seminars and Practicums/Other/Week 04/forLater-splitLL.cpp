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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }

        int times = size / k;
        if(!times) {
            return {head};
        }
        vector<ListNode*> res;
        ListNode* curr = head;
        for(int i = 0; i < times; i++) {
            temp = curr;
            for(int j = 0; j < k - 1; j++) {
                curr = curr->next;
            }
            ListNode* next = curr->next;
            if(!(i + 1 == times && size % k)) {
                 curr->next = nullptr;
            }
            res.push_back(temp);
            curr = next;
        }
      //....................................
        return res;
    }
};
