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
class Compare{
public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};

class Solution {
public:
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, Compare> minheap;

        for (auto list: lists){
            if (list!=NULL) minheap.push(list);
        }

        ListNode* dummy= new ListNode(0);
        ListNode* tail=dummy;

        while(!minheap.empty()){
            ListNode* smallest=minheap.top();
            minheap.pop();
            tail->next=smallest;
            tail=tail->next;

            if (smallest->next!=nullptr) minheap.push(smallest->next);
        }

        return dummy->next;
    }
};
