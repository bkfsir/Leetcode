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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(nullptr == head || nullptr == head->next || 1 == k || 0 == k)
            return head;
        
        int cWnd = 1;
        ListNode* pTail = head, *pPreTail = nullptr, *pNext = nullptr;
        ListNode* ret = head;
        bool hasGotNewHead = false;
        
        while(nullptr != pTail && nullptr != pTail->next)
        {
            cWnd++;
            pTail = pTail->next;
            
            if(k == cWnd)
            {
                if(!hasGotNewHead)
                {
                    hasGotNewHead = true;
                    ret = pTail;
                }
                pNext = pTail->next;
                reverseList(head, pTail);
                if(nullptr != pPreTail)
                    pPreTail->next = pTail;
                pPreTail = head;
                head = pNext;
                pTail = head;
                if(nullptr == head)
                {
                    pPreTail->next = nullptr;
                    return ret;
                }
                cWnd = 1;

            }
            
        }
        if(hasGotNewHead)
        {
            pPreTail->next = head;
            return ret;
        }
        else
            return head;
    }
    
    //逆序旧链表
    void reverseList(ListNode* pHead, ListNode* pTail)
    {
        ListNode* next = pHead->next;
        ListNode* preNode = pHead;

        pHead = next;
        
        while(pHead != pTail)
        {
            next = pHead->next;
            pHead->next = preNode;
            preNode = pHead;
            pHead = next;
        }
        
        pHead->next = preNode;
        return;
    }
};
