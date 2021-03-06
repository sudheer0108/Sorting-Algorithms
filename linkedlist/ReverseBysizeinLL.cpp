#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void Print(struct Node **head)
{
    struct Node *temp = *head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void Insert(struct Node **head, int newdata)
{
    struct Node *newNode = new Node(newdata);
    if (*head == NULL)
        *head = newNode;
    else
    {
        struct Node *temp = *head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

struct Node *reverseGroup(struct Node *head, int k)
{
    struct Node *cur, *prev, *next, *start1, *start2;
    int flag = 0, m = 0;
    cur = head;
    prev = NULL;
    start1 = cur;
    while (cur != NULL)
    {
        for (int i = 0; i < k; i++)
        {
            if (cur == NULL)
                break;

            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        if (m != 0)
        {
            start1->next = prev;
            start1 = start2;
        }
        start2 = cur;
        m++;
        if (flag == 0)
        {
            head = prev;
            flag = 1;
        }
        prev = NULL;
    }

    return head;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        struct Node *head = NULL;
        int N, l, K;

        cin >> N;
        for (int i = 0; i < N; i++)
        {
            cin >> l;
            Insert(&head, l);
        }
        cin >> K;
        head = reverseGroup(head, K);
        Print(&head);
    }
    return 0;
}