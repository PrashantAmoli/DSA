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
        head->next = create(data);
        head->next->next = head;
        head = head->next;
    }
    return head;
}

void pop(stack *head)
{
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
        cout << temp->data << " - ";
        temp = temp->next;
    }
}

int main()
{
    stack *head = NULL;
    int i, data;
    cout << "1\tCreate\n2\tPush\n3\tPop\n4\tDisplay\n5\tEnd" << endl;
    do
    {
        cout << "Enter your choice:";
        cin >> i;
        switch (i)
        {
        case 1:
            cout << "Create:\n\tInput:";
            cin >> data;
            head = create(data);
            break;
        case 2:
            cout << "Push:\n\tInput:";
            cin >> data;
            head = push(head, data);
            break;
        case 3:
            cout << "Pop:" << endl;
            pop(head);
            break;
        case 4:
            cout << "Display:\n";
            display(head);
            break;
        case 5:
            cout << "Exit:";
            return 0;
            break;
        default:
            cout << "Invalid Input!" << endl;
        }
    } while (1);

    return 0;
}