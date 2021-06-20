/*rotate the linked list counter-clockwise by k nodes,
 where k is a given positive integer smaller than or equal to length of the linked list.*/

class Solution
{
public:
    //Function to rotate a linked list.
    Node *rotate(Node *head, int k)
    {
        struct Node *cur = head;
        struct Node *tail = head;
        int count = 1;
        while (tail->next != NULL)
        {
            tail = tail->next;
            count++;
        }
        if (k > count)
        {
            k = k % count;
        }
        if (k == 0)
        {
            return head;
        }
        for (int i = 1; i < k; i++)
        {
            cur = cur->next;
        }
        tail->next = head;
        head = cur->next;
        cur->next = NULL;

        return head;
    }
};
