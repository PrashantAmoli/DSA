// Find the middle element of the stack
// This can be done using either an Array or Linked List
// The array implementation is simple:(address of index 0 - &top)/2
// Linked List Implementation will be explained below
// Use 2 pointers and iterate through the list by incrementing the second pointer once in every 2 times till the the second pointer reaches the end

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *next;
};

Node *push(Node *head, int data)
{
  if (head == NULL)
  {
    head = new Node;
    head->next = NULL;
    head->data = data;
  }
  else
  {
    Node *temp = head;
    head = new Node;
    head->data = data;
    head->next = temp;
  }
  return head;
}

void pop(Node **head)
{
  if (*head != NULL)
  {
    Node *temp = *head;
    (*head) = (*head)->next;
    cout << "Popped : " << temp->data << endl;
    delete (temp);
  }
  else
    cout << "Stack Underflow!" << endl;
}

void display(Node *head)
{
  while (head != NULL)
  {
    cout << "->" << head->data;
    head = head->next;
  }
  cout << endl;
}

int middle(Node *head)
{
  Node *mid = head;
  int i = 0;
  while (head != NULL)
  {
    i++;
    if (i % 2 == 0)
      mid = mid->next;
    head = head->next;
  }
  if (i % 2 != 0)
    cout << "Lower Bound Element in the middle" << endl;
  return (mid->data);
}

int main()
{
  Node *head = NULL;
  int choice, data, mid;

  do
  {
    cout << "\t 1: Push\n\t 2: Pop\n\t 3: Display\n\t 4: Find Middle element \n\t 5: Exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
      cout << "Enter element to Push : ";
      cin >> data;
      head = push(head, data);
      break;

    case 2:
      pop(&head);
      break;

    case 3:
      display(head);
      break;

    case 4:
      mid = middle(head);
      cout << "Middle Element :" << mid << endl;
      break;

    case 5:
      cout << "\t EXIT" << endl;
      break;

    default:
      cout << "\tInvalid Input!" << endl;
    }
  } while (choice != 5);

  return 0;
}
