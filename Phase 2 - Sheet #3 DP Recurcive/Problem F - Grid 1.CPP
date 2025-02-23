#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

vector<vector<int>> dp;
vector<pair<int, int>> bags;
int k, m;

int go(int i, int w) {
    if (i == m || w == 0)
        return 0;

    if (dp[i][w] != -1)
        return dp[i][w];

    int skip = go(i + 1, w);
    int take = 0;

    if (bags[i].first <= w) {
        take = bags[i].second + go(i + 1, w - bags[i].first);
    }

    dp[i][w] = max(skip, take);

    return dp[i][w];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;

    while (n--) {
        cin >> k >> m;

        bags.resize(m);
        dp.assign(m + 1, vector<int>(k + 1, -1));

        for (int i = 0; i < m; i++) {
            cin >> bags[i].first >> bags[i].second;
        }

        cout << "Hey stupid robber, you can get " << go(0, k) << "." << endl;
    }

    return 0;
}
