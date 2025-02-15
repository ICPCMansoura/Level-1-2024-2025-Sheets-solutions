#include<bits/stdc++.h>
using namespace std;

#define Bankai ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

string s;

int calc(int i, int first, int second, int rem1, int rem2) {
     if(first + rem1 < second || second + rem2 < first || i == 10)
         return i;

    if(i % 2 == 0) { // first
        if(s[i] == '1')
            return calc(i + 1, first + 1, second, rem1 - 1, rem2);
        else if(s[i] == '0')
            return calc(i + 1, first, second, rem1 - 1, rem2);
        else
            return min(calc(i + 1, first, second, rem1 - 1, rem2), calc(i + 1, first + 1, second, rem1 - 1, rem2));
    }else { // second
        if(s[i] == '1')
            return calc(i + 1, first, second + 1, rem1, rem2 - 1);
        else if(s[i] == '0')
            return calc(i + 1, first, second, rem1, rem2 - 1);
        else
            return min(calc(i + 1, first, second, rem1, rem2 - 1), calc(i + 1, first, second + 1, rem1, rem2 - 1));
    }
}

void ROOM() {
    cin >> s;
    cout << calc(0, 0, 0, 5, 5);
}

int main() {
    Bankai
    int t = 1;
    cin >> t;
    while (t--) {
        ROOM();
        cout << "\n";
    }
    return 0;
}