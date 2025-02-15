#include <bits/stdc++.h>

using namespace std;

void fileIO() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}
int lcm (int a, int b) {
    return a / __gcd(a, b) * b;
}


#define int long long
typedef long long ll;
#define endl '\n'
#define SetPre(n, x)  cout << fixed << setprecision(n) << x


signed main() {
    fastIO();
    fileIO();
    while(true) {
        int N, G = 0;
        cin >> N;
        if(!N) {
            break;
        }
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j <= N; j++) {
                G += __gcd(i, j);
            }
        }
        cout << G << endl;
    }

}