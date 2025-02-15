#include<bits/stdc++.h>
using namespace std;

#define Bankai ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

int p[101];
int n, l, r, x;

int count(int i, int mn = 1e9, int mx = 0, int cnt = 0, int sum = 0) {
    if(i == n)
        return (sum >= l && sum <= r && mx - mn >= x &&  cnt >= 2);

    return count(i + 1, mn, mx, cnt,  sum) + count(i + 1, min(mn, p[i]), max(mx, p[i]), cnt + 1, sum + p[i]);
}

void ROOM() {
    cin >> n >> l >> r >> x;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    cout << count(0);
}

int main() {
    Bankai
    int t = 1;
    while (t--) {
        ROOM();
        cout << "\n";
    }
    return 0;
}