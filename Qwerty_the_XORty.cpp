#include <bits/stdc++.h>
#include <cmath>
using namespace std;
void findX(int arr[], int n)
{
    int *itr = max_element(arr, arr + n);
    int p = log2(*itr) + 1;
    int X = 0;
    for (int i = 0; i < p; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] & (1 << i))
            {
                count++;
            }
        }
        if (count > (n / 2))
        {
            X += 1 << i;
        }
    }
    long long int sum = 0;
    for (int i = 0; i < n; i++)
        sum += (X ^ arr[i]);
    cout << X;
}

int main()
{
    int N;
    cin >> N;
    int arr[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    findX(arr, N);
    return 0;
}
