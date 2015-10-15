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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(nullptr == head || (nullptr == head->next && 1 == n) )
            return nullptr;
        else if(0 == n)
                return head;

        ListNode* pTail = head;
        for(int i = 0; i < n - 1; i++)
            pTail = pTail->next;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pHead = head, *preHead = &dummy;
        while(nullptr != pTail->next)
        {
            preHead = pHead;
            pHead = pHead->next;
            pTail = pTail->next;
        }
        preHead->next = pHead->next;
        
            
        return dummy.next;
    }
};