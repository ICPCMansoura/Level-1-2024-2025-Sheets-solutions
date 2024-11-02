#include <bits/stdc++.h>
using namespace std;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

const int MAX = 1e5;
vector<int> divs[MAX + 1];

void generate_divisors() {
  for (int i = 1; i <= MAX; ++i)
    for (int j = i; j <= MAX; j += i)
      divs[j].push_back(i);
}

void solve() {
  int x = 0;
  cin >> x;
  for (auto& d : divs[x])
    cout << d << ' ';
  cout << '\n';
}

int main() {
    fastio();
    generate_divisors();
    int t;
    cin >> t;
    while (t--)
      solve();
    return 0;
}
