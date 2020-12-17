// Implement 2 stacks in an array
// head1 [0 to n elements] head2
#include <iostream>
using namespace std;

//OBJECT-ORIENTED APPROACH
class Stacks
{
    int *arr;               //Storing the whole array in heap
    int *top1, *top2, size; //Pointers to the top of two stack

public:
    Stacks(int SIZE)
    {                        //Constructor to initialize object upon creation
        size = SIZE;         //Storing size of array in objects class
        arr = new int[size]; //Initializing array & allocating memory
        top1 = nullptr;      //NOTE nullptr points to null/0 address whereas NULL points to value zero
        top2 = nullptr;
    }

    void push1(int data)     //Push to Stack1 from the beginning
    {                        //Check if empty stack
        if (top1 == nullptr) //if empty start point to index 0
        {
            top1 = arr;   //top1 = arr will also work //use & when mentioning the index
            *top1 = data; //Add data to top by derefrencing
            return;       //Return to avoid further opertions
        }

        if (top1 < top2 - 1) //If not empty check if it overlaps with Stack2
        {                    //if not then update the top
            top1++;          //increment pointer to point to next index if it has empty value
            *top1 = data;    //derefence and store the value to new top
        }
        else                                   //else it points to memory location of Stack 2
            cout << "Stack Overflow!" << endl; //hence Stack Overflow
    }
    void push2(int data) //REVIEW
    {
        if (top2 == nullptr)
        {                          //If empty
            top2 = &arr[size - 1]; //then point to last element
            *top2 = data;
            return;
        }
        if (top2 > top1)  //Check if stack2 is not overlapping with Stack1
        {                 //if not then update pointer top
            top2--;       //Decrement to point to previous index if it has empty value
            *top2 = data; //Update the value of top
        }
        else                                     //else it points to memory location of stack1
            cout << "\nStack Overflow!" << endl; //hence stack overflow
    }
    // NOTE
    // Instead of deleting value top update the pointer in ARRAY and leaving it will make
    // That value will not be displayed using top and other is available to rewrite for both stacks
    void pop1() //Popping element from Stack1
    {
        if (top1 >= &arr[0]) //Check if top is greater than of equal to first element
        {
            cout << "Popped : " << *top1; //Display popped element
            top1--;                       //Update top to previous value by decrementing
        }
        else                                    //If reached 0 index(bottom)
            cout << "Stack Underflow!" << endl; //Then
    }
    void pop2()
    {
        if (top2 < &arr[size])            //check if top is less than the last index
        {                                 //if it is
            cout << "Popped : " << *top2; //Display popped value
            top2++;                       //update top to point to next value
        }
        else
            cout << "Stack Underflow!" << endl;
    }

    void display1()
    {
        int *temp = top1;       //temp point to address stored in top
        while (temp >= &arr[0]) //Continue until the base of stack is reached
        {
            cout << *temp << "->";
            temp--;
        }
    }
    void display2()
    {
        int *temp = top2;
        while (temp < &arr[size])
        {
            cout << *temp << "<-";
            temp++;
        }
    }

    void peek() //Peek to know what's on Top of both stacks
    {
        cout << "Top of Stack 1 ->" << *top1 << endl;
        cout << "Top of Stack 2 ->" << *top2 << endl;
    }
};

int main()
{
    int size, choice;             //Size of array and choice of operation
    cout << "Enter Array size :"; //input size of array
    cin >> size;
    Stacks obj(size); //Declare an object passing size as argument for constructor

    do
    {
        int data; //declare variable for data to be pushed
        cout << "\n\t1\tPush to Stack 1\n\t2\tPush to Stack 2";
        cout << "\n\t3\tPop from Stack 1\n\t4\tPop from Stack 2"; //Menu of Operations
        cout << "\n\t5\tDisplay Stack 1\n\t6\tDisplay Stack 2";
        cout << "\n\t7\tDisplay Top of both Stacks\n\t8\tExit";
        cout << "\n Enter choice :"; //Ask choice after every operation
        cin >> choice;               //Input choice of operation
        switch (choice)
        {
        case 1:
            cout << "Enter element to push :";
            cin >> data;
            obj.push1(data);
            break;

        case 2:
            cout << "Enter element to push :";
            cin >> data;
            obj.push2(data);
            break;

        case 3:
            obj.pop1();
            break;

        case 4:
            obj.pop2();
            break;

        case 5:
            cout << "\tDisplaying Stack 1" << endl;
            obj.display1();
            break;

        case 6:
            cout << "\tDisplaying Stack 2" << endl;
            obj.display2();
            break;

        case 7:
            cout << "\tTop of both Stacks" << endl;
            obj.peek();
            break;

        case 8:
            cout << "\t Exit" << endl;
            break;

        default:
            cout << "Invalid Input!" << endl;
            break;
        }
    } while (choice != 8); //Exit Condition

    return 0;
}