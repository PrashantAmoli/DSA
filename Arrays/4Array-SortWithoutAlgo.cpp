// Given an array which consists of only 0,1 &2. Sort the array without using any sorting algorithm.
// Answer => Traverse the array=> prepend 0 to beginning 2 to the end=> 1 will be left in the middle

#include <iostream>
using namespace std;

void sort(int array[], int n)
{
    int zero = 0, two = n - 1, i = 0;
    while (i <= two) // Greater than two will be the section of sorted 2
    {
        switch (array[i])
        {
        case 0:
            swap(array[i++], array[zero++]); // Add 0 to the beginning
            break;

        case 1:
            i++; // Just increment
            break;

        case 2:
            swap(array[i], array[two--]); // Add 2 to the end
            break;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int arr[n];

    cout << "Enter n elements (only 0,1,2)";
    for (int i = 0; i < n; i++)
    {
    input:
        cin >> arr[i];
        switch (arr[i])
        {
        case 0:break;
        case 1:break;
        case 2:break;
        default:
            cout << "Invalid Input! \nEnter 0, 1 or 2 only :";
            goto input;
        }
    }

    sort(arr, n);

    for (int i = 0; i < n; i++)
        cout << arr[i] << "\t";
    cout << "\n\tThe End" << endl;

    // int x = 000, y = 123;
    // swap(x, y);
    // cout << x << "x|y" << y;
    return 0;
}

// Another Approach :=> Count the number of 0s, 1s and 2s in the given array. Then store all the 0s in the beginning followed by all the 1s then all the 2s.
// Algorithm:
// Keep three counter c0 to count 0s, c1 to count 1s and c2 to count 2s
// Traverse through the array and increase the count of c0 is the element is 0,increase the count of c1 is the element is 1 and increase the count of c2 is the element is 2
// Now again traverse the array and replace first c0 elements with 0, next c1 elements with 1 and next c2 elements with 2.