/*
Link=> https://www.codechef.com/problems/IPCCERT
Question:
There were N students (numbered 1 through N) participating in the Indian Programming Camp (IPC) and they watched a total of K lectures (numbered 1 through K). For each student i and each lecture j, the i-th student watched the j-th lecture for Ti,j minutes.

Additionally, for each student i, we know that this student asked the question, "What is the criteria for getting a certificate?" Qi times.

The criteria for getting a certificate is that a student must have watched at least M minutes of lectures in total and they must have asked the question no more than 10 times.

Find out how many participants are eligible for a certificate.

Input
The first line of the input contains three space-separated integers N, M and K.
N lines follow. For each valid i, the i-th of these lines contains K+1 space-separated integers Ti,1,Ti,2,…,Ti,K,Qi.
Output
Print a single line containing one integer — the number of participants eligible for a certificate.

Constraints
1≤N,K≤1,000
1≤M≤106
1≤Qi≤106 for each valid i
1≤Ti,j≤1,000 for each valid i and j
Example Input
4 8 4
1 2 1 2 5
3 5 1 3 4
1 2 4 5 11
1 1 1 3 12
Example Output
1
Explanation
Participant 1 watched 1+2+1+2=6 minutes of lectures and asked the question 5 times. Since 6<M, this participant does not receive a certificate.
Participant 2 watched 3+5+1+3=12 minutes of lectures and asked the question 4 times. Since 12≥M and 4≤10, this participant receives a certificate.
Participant 3 watched 1+2+4+5=12 minutes of lectures and asked the question 11 times. Since 12≥M but 11>10, this participant does not receive a certificate.
Participant 4 watched 1+1+1+3=6 minutes of lectures and asked the question 12 times. Since 6<M and 12>10, this participant does not receive a certificate.
Only participant 2 receives a certificate.
*/
/*****************                SOLUTION                ***************************************/
#include <iostream>

using namespace std;

int main()
{
    int n, m, k, result = 0; //n=students||  m=Min Duration of Lect||    k=Lectures|| result=students passed
    // cout << "Enter n, m, k: ";
    cin >> n >> m >> k;
    int t[n][k], q[n], sum[n];

    for (int i = 0; i < n; i++) //Input for each student 1-n
    {
        sum[i] = 0;                 //initializing sum to 0 to add time for each lect.
        for (int j = 0; j < k; j++) //Input for student i's duration in each lecture
        {
            cin >> t[i][j];    //Storing time taken in each lecture 1by1
            sum[i] += t[i][j]; //Sum of time for student i
        }

        cin >> q[i];  //Input for not time's he asked annoying question
        cout << endl; //Changing line and shifting to student i+1
    }

    for (int i = 0; i < n; i++)
    {
        if (q[i] <= 10)
        {
            // for (int j = 0; j < k; j++)//    Time = 4.5sec
            // {
            //     sum += t[i][j];
            // }
            if (sum[i] >= m)
                result++;
        }
    }
    cout << "\nResult = " << result << endl;
    return 0;
}

/*
Time taken: 0.13 seconds
*/