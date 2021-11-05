#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    int N, minScore = 0, maxScore = 0;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    for (int i = 0; i < N; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), greater<int>());
    for (int i = 0; i < N; i++)
        minScore += A[i] * B[i];
    sort(A.begin(), A.end(), greater<int>());
    for (int i = 0; i < N; i++)
        maxScore += A[i] * B[i];
    cout << minScore << " " << maxScore;
}