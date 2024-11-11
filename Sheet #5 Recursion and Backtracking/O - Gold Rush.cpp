#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,fma")

#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);

#define int long long

using namespace std;

bool fun(int n, int m) // n -> ops , m -> target
{
    // base case
    if (n == m)
    {
        return true;
    }

    if (n % 3 != 0)
    {
        return false;
    }

    // recursive call.
    int ch1 = fun(n / 3, m);
    int ch2 = fun(2 * n / 3, m);

    return (ch1 || ch2);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    if (fun(n, m))
        cout << "YES";
    else
        cout << "NO";

    cout << endl;
}

signed main()
{
    fast;

    int tc = 1;
    cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}