// Reverse a string
#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str, rev;
    int i = 0, n;
    getline(cin, str);
    n = str.length();
    // cout << n << endl;
    while (i < n)
    {
        // rev += str[n - i - 1];         //Method 1
        rev.push_back(str[n - i - 1]); //Method 2
        i++;
    }
    cout << rev << endl;
    return 0;
}