class Solution
{
public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node *head)
    {
        if (head == NULL)
        {
            return false;
        }
        Node *p = head;
        Node *q = head;
        while (p != NULL && q != NULL && q->next != NULL)
        {
            p = p->next;
            q = q->next->next;
            if (p == q)
            {
                return true;
            }
        }
        return false;
    }
};
