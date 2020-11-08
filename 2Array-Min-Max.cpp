// Find the minimum and maximum element of an array
#include <iostream>
using namespace std;

void input(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\tElement " << (i + 1) << ":";
        cin >> array[i];
    }
}

void find(int array[], int n)
{
    int min = 0, max = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] < min)
            min = array[i];

        if (array[i] > max)
            max = array[i];
    }
    cout << "\nMaximum = " << max << endl;
    cout << "Minimum = " << min << endl;
}

int main()
{
    int n;
    cout << "Enter the number of elements:";
    cin >> n;
    int array[n];
    input(array, n);
    find(array, n);

    return 0;
}