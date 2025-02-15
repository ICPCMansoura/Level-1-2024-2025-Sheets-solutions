#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 10 , M = 2;

vector<long long> divisors;
void getDivisors(int n) {
    for (int i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i * i != n) {
                divisors.push_back(n / i);
            }
        }
    }
}

void solve()
{
    int n; cin >> n;
    getDivisors(n);
    sort(divisors.begin(), divisors.end());

    cout << divisors.size() << '\n';
    for (int i : divisors) {
        cout << i << ' ';
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int testCases = 1;
  //  cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}