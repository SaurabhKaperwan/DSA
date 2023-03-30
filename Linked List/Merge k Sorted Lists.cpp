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
class Compare
{
    public:
        bool operator() (const ListNode* a, const ListNode* b)const {
        return a->val > b->val;
        }
};

class Solution 
{
    public:
        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {
            priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
            
            //Add first element from each list to pq
            for(auto list : lists)
            {
                if(list)
                    pq.push(list);
            }

            //dummy ListNode to serve as the head of the merged list
            ListNode* dummy = new ListNode(0);
            /*Create a tail pointer to keep track of the 
            element added to the merged list
            */
            ListNode* tail = dummy;

            while(!pq.empty())
            {
                ListNode* node = pq.top();
                pq.pop();
                tail->next = node;
                tail = node;

                if(node->next)
                    pq.push(node->next);
            }
            return dummy->next;
        }
};
