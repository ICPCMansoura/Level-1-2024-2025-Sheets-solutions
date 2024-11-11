#include <bits/stdc++.h>

using namespace std;

#define Sonic ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define int long long

const int mod = 1e9 + 7;
int n;
vector<bool> rows(11, true), cols(11, true), diags1(11, true), diags2(11, true);
vector<vector<string>> solutions;
void queens(int r, vector<string> &board) {
    if (r == n) {
        solutions.push_back(board);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (cols[i] && diags1[r - i + n] && diags2[r + i]) {
            board[r][i] = 'Q';
            rows[r] = cols[i] = diags1[r - i + n] = diags2[r + i] = false;
            queens(r + 1, board);
            board[r][i] = '.';
            rows[r] = cols[i] = diags1[r - i + n] = diags2[r + i] = true;
        }
    }
}
void palmer() {
    cin >> n;
    vector<string> board(n, string(n, '.'));
    queens(0, board);
    for (int i = 0; i < solutions.size(); i++) {
        for (int j = 0; j < solutions[i].size(); j++) {
            cout << solutions[i][j] << "\n";
        }
        cout << "\n";
    }
}

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Sonic
    int t = 1; //cin >> t;
    while (t--){
        palmer();
        if (t > 0)
            cout << "\n";
    }
}