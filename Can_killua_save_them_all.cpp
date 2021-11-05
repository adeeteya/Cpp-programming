#include <iostream>
#include <string>
using namespace std;
int isPalindrome(string str)
{
    int l = 0;
    int h = str.length() - 1;
    while (h > l)
        if (str[l++] != str[h--])
            return 0;
    return 1;
}
int isRotationOfPalindrome(string str)
{
    if (isPalindrome(str))
        return 1;
    int n = str.length();
    for (int i = 0; i < n - 1; i++)
    {
        string str1 = str.substr(i + 1, n - i - 1);
        string str2 = str.substr(0, i + 1);
        if (isPalindrome(str1.append(str2)))
            return 1;
    }
    return 0;
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    string str;
    str.reserve(N);
    cin >> str;
    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << isRotationOfPalindrome(str.substr(l - 1, (r - l) + 1)) << endl;
    }
    return 0;
}
