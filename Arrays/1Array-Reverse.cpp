// Reversing an array
#include <iostream>
using namespace std;

void input(int arr[], int n)
{
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void reverse(int arr[], int n)
{
    int x, j = n - 1;
    for (int i = 0; i < n / 2; i++)
    {
        if (arr[i] == arr[j])
            break;
        x = arr[i];
        arr[i] = arr[j];
        arr[j] = x;
        j--;
    }
}

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " <-> ";
    }
}

int main()
{
    int n;
    cout << "Enter the size of array:";
    cin >> n;
    int arr[n];
    input(arr, n);
    reverse(arr, n);
    display(arr, n);
    return 0;
}