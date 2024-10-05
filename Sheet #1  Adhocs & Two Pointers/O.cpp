#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    // FAST_IO;
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll>a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    vector<pair<pair<int, int>, int>>operations(m + 1);
    int idx = 1;
    vector<ll>partial_operations(m + 2), partial_sum(n + 2);
    //<<l,r>,d>


    for (int idx = 1; idx <= m; idx++)
    {
        int l, r, d;
        cin >> l >> r >> d;
        operations[idx].first.first = l;
        operations[idx].first.second = r;
        operations[idx].second = d;
    }
    while (k--)
    {
        int x, y;
        cin >> x >> y;
        partial_operations[x] += 1;
        partial_operations[y + 1] -= 1;
    }
    for (int i = 1; i <= m; i++)
    {
        partial_operations[i] += partial_operations[i - 1];
    }
    for (int i = 1; i <= m; ++i) {
        int l = operations[i].first.first;
        int r = operations[i].first.second;
        ll d = operations[i].second;
        partial_sum[l] += (d * partial_operations[i]);
        partial_sum[r + 1] -= (d * partial_operations[i]);
    }
    for (int i = 1; i <= n; ++i) {
        partial_sum[i] += partial_sum[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += (partial_sum[i]);
        cout << a[i] << " ";
    }
}
