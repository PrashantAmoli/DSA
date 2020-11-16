//Find the kth maximum and minimum element of an array
#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
}

int main()
{
    int n, k;
    cout << "Enter the size of Array:";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of Array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, n);
    // Display Sorted Array
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << "  ";
    // }
input:
    cout << "Enter the value of k:";
    cin >> k;
    cout << endl;
    if (k <= n)
    {
        cout << k << " Maximum -> " << arr[n - k] << endl;
        cout << k << " Minimum -> " << arr[k - 1] << endl;
    }
    else
    {
        cout << "Enter an integer value less than or equal to " << n << endl;
        goto input;
    }

    return 0;
}