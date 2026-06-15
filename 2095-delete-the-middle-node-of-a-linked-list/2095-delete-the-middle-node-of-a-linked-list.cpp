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
    ListNode* deleteMiddle(ListNode* head) {
        if(!head||!head->next)
            return NULL;
        // ListNode* temp=head;
        // int cnt=0;
        // while(temp)
        // {   
        //     cnt++;
        //     temp=temp->next;

        // }
        // int n =floor(cnt/2);
        // cnt=0;
        // temp=head;
        // ListNode* prev=NULL;
        // while(temp)
        // {
        //     if(cnt==n)
        //     {
        //         prev->next=temp->next;
        //         temp->next=NULL;

        //     }
        //     prev=temp;
        //     temp=temp->next;
        //     cnt++;
        // }
        // return head;

        //slow fast ptr approach
        ListNode *slow=head,*fast=head,*prev=NULL;
        //find middle node;
        while(fast && fast->next )
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;

        }  //slow stops at the middle node
        prev->next=slow->next;
        slow->next=NULL;
        delete slow;
        return head;

        
    }
};