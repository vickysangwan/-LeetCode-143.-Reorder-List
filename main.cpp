/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//Idea:
//
//Suppose we have a list [1,2,3,4,5,6,7]
//
//Steps as follow:
//
//1-Divide the list into front list: [1,2,3,4] and tail list: [5,6,7]
//2- Reverse the tail list to [7,6,5]
//3- Join front and tail list,
//1 ->2 ->3 ->4
//->7 ->6 ->5
//Result: [1,7,2,6,3,5,4]
void reorderList(ListNode* head) {
        if(!head) return;
        ListNode * slowptr,*fastptr;
        slowptr=fastptr=head;
        while(fastptr!=NULL && fastptr->next!=NULL)
        {
            slowptr=slowptr->next;
            fastptr=fastptr->next->next;
        }

        ListNode* current = slowptr;
        ListNode *prev = NULL, *next = NULL;

        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        slowptr = prev;

        ListNode *f1,*f2;
        f1= head->next; f2=slowptr->next;
        while(f2!=NULL)
        {
            head->next= slowptr;
            slowptr->next=f1;
            head=f1;
            slowptr=f2;
            f1=f1->next;
            f2=f2->next;
        }
    }
