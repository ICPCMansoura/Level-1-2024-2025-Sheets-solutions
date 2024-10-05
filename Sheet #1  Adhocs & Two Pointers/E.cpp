#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int TestCases;
    cin >> TestCases;
    while(TestCases--)
    {
        ll n , m; cin >> n >> m;
        vector <ll> petals(n);

        for (int i = 0; i < n; i++) {
            cin >> petals[i];
        }
        sort(petals.begin() , petals.end());

        if(petals.front() > m) {
            cout << 0 << '\n';
            continue;
        }
        ll currentSum = 0 , ans = 0;
        int left = 0 , right = 0;
        while (right < n) {
            currentSum += petals[right];
            while (right < n && left < n && left < right && currentSum > m || petals[right] - petals[left] > 1) {
                currentSum -= petals[left];
                left++;
            }
            ans = max(ans , currentSum);
            right++;
        }

        cout << ans << '\n';
    }
}