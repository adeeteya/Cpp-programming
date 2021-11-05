#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, K;
    int check = 0;
    cin >> N >> K;
    int L[N], R[N];
    for (int i = 0; i < N; i++)
        cin >> L[i] >> R[i];
    for (int i = 1; i < N; i++)
    {
        if (L[i] < R[i - 1])
        {
            check = 1;
            break;
        }
    }
    if (check == 0)
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
