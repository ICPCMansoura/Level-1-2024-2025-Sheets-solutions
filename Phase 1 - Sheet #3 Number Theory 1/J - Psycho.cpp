#include <bits/stdc++.h>
#define int long long

using namespace std;


bool isPsycho(int n) {
    map <int,int> freq;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            freq[i]++;
            n /= i;
        }
    }
    if (n > 1) {
        freq[n]++;
    }

    int even = 0 , odd = 0;
    for (auto &[factor , power] : freq) {
        if(power % 2 == 0) even++;
        else odd++;
    }
    return even > odd;
}

void solve()
{
    int n; cin >> n;
    if(isPsycho(n)) cout << "Psycho Number\n";
    else cout << "Ordinary Number\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif


    int testCases = 1;
    cin >> testCases;
    for (int testCase = 1 ; testCase <= testCases ; ++testCase){
        solve();
    }
}