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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p1;
        ListNode* p2;
        p1 = l1;
        p2 = l2;

        ListNode* result = new ListNode;
        ListNode* tmp = result;
        int flag=0;
        int x=0;
        while (l1!=NULL || l2!=NULL) {
            if (l1==NULL) {
                x = l2->val + flag;
                if (x>9) {
                    tmp->val = x - 10;
                    flag = 1;
                }
                else{
                    tmp->val = x;
                    flag = 0;
                }
                l2 = l2->next;
            }
            else if (l2==NULL) {
                x = l1->val + flag;
                if (x>9) {
                    tmp->val = x - 10;
                    flag = 1;
                }
                else{
                    tmp->val = x;
                    flag = 0;
                }
                l1 = l1->next;
            }
            else{
                int x = l1->val + l2->val + flag;
                if (x>9) {
                    tmp->val = x - 10;
                    flag = 1;
                }
                else {
                    tmp->val = x;
                    flag = 0;
                }
                l1 = l1->next;
                l2 = l2->next;
            }
            if (l1!=NULL || l2!=NULL){
                tmp->next = new ListNode;
                tmp = tmp->next;
            }
            else{
                if (flag>0) {
                    tmp->next = new ListNode;
                    tmp = tmp->next;
                    tmp->val = 1;
                }
            }
        }
        return result;
    }
};
