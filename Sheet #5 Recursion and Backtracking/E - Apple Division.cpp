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

vector<int> a;
int n;

int fun(int i, int sum1, int sum2)
{
    // base case
    if (i == n)
    {
        return abs(sum1 - sum2);
    }

    // recursive call
    int op1 = fun(i + 1, sum1 + a[i], sum2);
    int op2 = fun(i + 1, sum1, sum2 + a[i]);

    return min(op1, op2);
}

void solve()
{
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int mn = fun(0, 0, 0);

    cout << mn << endl;
}

signed main()
{
    fast;

    int tc = 1;
    // cin >> tc;

    while (tc--)
    {
        solve();
    }

    return 0;
}