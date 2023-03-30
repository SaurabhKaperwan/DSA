/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
        {
            ListNode* nodeA = headA;
            ListNode* nodeB = headB;

            while(nodeA)
            {
                nodeB = headB; 
                while(nodeB)
                {
                    if(nodeA == nodeB)
                        return nodeA;
                    nodeB = nodeB -> next;
                }
                nodeA = nodeA -> next;
            }
            return nullptr;
        }
};
