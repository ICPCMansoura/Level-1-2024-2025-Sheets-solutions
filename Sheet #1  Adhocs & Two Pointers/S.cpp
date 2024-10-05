#include <iostream>
#include<istream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <stack>
#include <climits>
#include<map>
#include<string>
#include<set>
#include <cstring>
#include<unordered_map>
#include <numeric>
#include <iomanip>
#include <cstdio>
#include <cstring>
#define ll   long long
#define MOD 1000000007
#define endl "\n"
using namespace std;
void fast() {
    std::ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(nullptr);
}
ll  gcd(ll  a, ll  b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
signed main() {
    fast();
    //freopen("paintbarn.in", "r", stdin);
    //freopen("paintbarn.out", "w", stdout);
    int N, M; cin >> N >> M;
    vector<vector<int>>AC(N + 1, vector<int>(M + 1)), NotAC(N + 1, vector<int>(M + 1));
    int submissions; cin >> submissions;
    while (submissions--)
    {
        int c, p; string sub;
        cin >> c >> p >> sub;
        if (sub != "AC")
            NotAC[c][p]++;
        else
            AC[c][p] += NotAC[c][p];
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            AC[i][j] += AC[i][j - 1];
        }
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            AC[i][j] += AC[i - 1][j];
        }
    }
    int q; cin >> q;
    while (q--)
    {
        int c1, p1, c2, p2;
        cin >> c1 >> p1 >> c2 >> p2;
        cout << AC[c2][p2] - AC[c1 - 1][p2] - AC[c2][p1 - 1] + AC[c1 - 1][p1 - 1] << endl;
    }
}
