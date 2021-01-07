// Implement Queue from Scratch
// NULL <-- (REAR) data <-- data <-(next)- data <-- data <-- data (FRONT)
// using OOP and Singly Linkedlist in C++
#include <iostream>
using namespace std;

struct node //Singly LinkedList
{
    int data;
    node *next;
};

class queue
{
    node *rear, *front; //front and rear of queue of type node(LL)

public:
    queue() //Constructor to initialize front & rear of each object to null
    {
        rear = NULL;
        front = NULL;
    }

    bool isEmpty() //is front is NULL then Queue is empty
    {
        if (front == NULL)
            return 1; //True
        else
            return 0; //False
    }

    void enqueue(int data)
    {
        node *element = new node; //For every enqueue make new node in heap
        element->data = data;     //Put data in new node
        element->next = NULL;     //intialize next of new node to NULL

        if (front == NULL)   //If front of object is NULL then its empty
        {                    //hence it's the first element
            front = element; //so point front and rear to new node
            rear = element;
        }
        else //if it's not the first element|leave front unmodified
        {
            rear->next = element; //Point rear's next to new node
            rear = rear->next;    //then increment it to update rear
        }
    }

    void dequeue()
    {
        node *temp = front;         //Point temp to front
        front = front->next;        //Decrement(to next) front
        cout << temp->data << endl; //Diplay dequeued data
        delete (temp);              //Delete data
    }

    void display()
    {
        if (isEmpty()) //Check if queue is empty
            return;

        node *temp = front; //Point temp to front
        while (temp != NULL)
        {
            cout << "<- " << temp->data; //Print temps data
            temp = temp->next;           //increment temp
        }
        cout << endl;
    }
};

int main()
{
    queue *q = new queue; //queue class object
    int choice;
    do
    {
        int data;
        cout << "\n\t1:\tEnqueue\n\t2:\tDequeue\n\t3:\tDisplay\n\t4:\tExit\nChoice :"; //Menu driven program to perform queue operations
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enqueue Data : ";
            cin >> data;
            q->enqueue(data);
            break;

        case 2:
            cout << "Dequeued :";
            q->dequeue();
            break;

        case 3:
            cout << "Data :";
            q->display();
            break;

        case 4:
            cout << "\tExited" << endl;
            return 0;
            break;

        default:
            cout << "\tInvalid Input!" << endl;
            break;
        }
    } while (choice != 4);

    return 0;
}