//Move all the negative elements to one side of the array
#include <iostream>
using namespace std;

void negatives(int arr[], int n)
{
    for (int j = 0; j < n; j++)
    {
        int neg = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
            {
                int temp = arr[neg];
                arr[neg] = arr[i];
                arr[i] = temp;
                neg++;
            }
        }
    }
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int arr[n];
    cout << "Enter the number of elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    negatives(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    return 0;
}