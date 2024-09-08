/*
725. Split Linked List in Parts
Solved
Medium
Topics
Companies
Hint
Given the head of a singly linked list and an integer k, split the linked list into k consecutive linked list parts.

The length of each part should be as equal as possible: no two parts should have a size differing by more than one. This may lead to some parts being null.

The parts should be in the order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal to parts occurring later.

Return an array of the k parts.
*/

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
    int fun(ListNode* head){
        ListNode* temp = head;
        int count=0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        
        if(head==NULL){
            ans.resize(k);
            return ans;
        }
       
        int count = fun(head);
        int val1 = ceil((double)count/(double)k);
        int val2 = count/k;
        int n_val1 = count - val2*k; //number of LL that will have size val1
        int n_val2 = k - n_val1;//number of LL that will have size val2
        

        ListNode* temp = head;
        ListNode* prev = NULL;

        while(n_val1--){
            ans.push_back(temp);
            for(int i=0;i<val1;i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next=NULL;
        }

        while(n_val2--){
            ans.push_back(temp);
            for(int i=0;i<val2;i++){
                prev = temp;
                temp = temp->next;
            }
            prev->next=NULL;
        }

        return ans;

    }
};