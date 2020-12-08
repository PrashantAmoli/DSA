// Implement stack from Scratch
#include <iostream>
using namespace std;

struct stack
{
    int data;
    struct stack *next;
};

stack *create(int data)
{
    stack *s1 = new stack;
    s1->data = data;
    s1->next = NULL;
    return (s1);
}

stack *push(stack *head, int data)
{
    if (head == NULL)
    {
        head = create(data);
    }
    else
    {
        stack *s1 = new stack;
        s1->data = data;
        s1->next = head;
        head = s1;
    }
    return head;
}

void pop(stack **head) //Double Pointer argument &head
{
    stack *temp = *head;
    (*head) = (*head)->next;
    delete (temp);
}

void display(stack *head)
{
    if (head == NULL)
    {
        cout << "Empty Stack!" << endl;
        return;
    }
    stack *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "<-> ";
        temp = temp->next;
    }
}

int main()
{
    stack *head = NULL;
    int i, data;
    cout << "1\tPush\n2\tPop\n3\tDisplay\n4\tEnd" << endl;
    do
    {
        cout << "Enter your choice:";
        cin >> i;
        switch (i)
        {
        case 1:
            cout << "Push:\n\tInput:";
            cin >> data;
            head = push(head, data);
            break;
        case 2:
            cout << "Pop:" << endl;
            pop(&head);
            break;
        case 3:
            cout << "Display:\n";
            display(head);
            break;
        case 4:
            cout << "Exit:";
            return 0;
            break;
        default:
            cout << "Invalid Input!\n"
                 << endl;
        }
    } while (1);

    return 0;
}