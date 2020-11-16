//Given an array which consists of only 0,1 &2. Sort the array without using any sorting algorithm.
#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {1, 2, 0};
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            arr[i] += arr[i + 1];
            arr[i + 1] = arr[i] - arr[i + 1];
            arr[i] = arr[i] - arr[i + 1];
        }
        if (arr[1] > arr[2] && arr[0] > arr[1])
        // goto sort;
    }
    for (int i = 0; i < 3; i++)
        cout << arr[i] << "  ";
    return 0;
}