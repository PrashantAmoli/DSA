//Find the union and intersecton of two sorted arrays.
#include <iostream>
using namespace std;

void uni(int arr1[], int arr2[])
{
    int i = 0;
    while (arr1[i] != '\0')
    {
        i++;
        if (i == 5)
            cout << "\n\ti = " << i << endl;
    }
    cout << "i = " << i << endl;
}
void inter(int arr1[], int arr2[])
{
    int i = 0;
}

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6}, arr2[] = {5, 6, 7, 8, 9};
    uni(arr1, arr2);
    inter(arr1, arr2);
    return 0;
}