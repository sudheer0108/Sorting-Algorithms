struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
    struct Node *temp = head;
    struct Node *mid = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    count = (count / 2) + 1;
    while (count > 1)
    {
        mid = mid->next;
        count--;
    }
    return mid->data;
}
