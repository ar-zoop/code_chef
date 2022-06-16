#include <bits/stdc++.h>
using namespace std;
#define N 100000
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, count = 0;
        cin >> n;
        string s;
        cin >> s;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                count++;
            }
        }
        long long int ans = count * (count + 1) / 2;
        cout << ans << endl;
    }
    return 0;
}