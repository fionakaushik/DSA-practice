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
    ListNode* findKthNode(ListNode* head,int k )
    {
        int cnt=1;
        while(head)
        {
            if(cnt==k)
                return head;
            cnt++;
            head=head->next;

        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||k==0)
            return head;
        ListNode* tail=head;
        int len=1;
        while(tail->next!=NULL) //tail will stand at the last node
        {
            len++;
            tail=tail->next;

        }
        if(k%len==0)   //ll remains same after roation no need to do anythng ,just ret head
            return head;
        k=k%len;
        //make a circular list
        tail->next=head;
        //find new last node
        ListNode* newLstNode=findKthNode(head,len-k);
        //update head;
        head=newLstNode->next;
        newLstNode->next=NULL;
        
        return head;


        


        
    }
};