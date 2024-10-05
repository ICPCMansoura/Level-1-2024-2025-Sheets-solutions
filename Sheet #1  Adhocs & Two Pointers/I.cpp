#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, minutes;
    cin >> n >> minutes;
    vector<ll>Books(n);
    for (long long i = 0; i < n; i++)
        cin >> Books[i];
    ll right = 0, left = 0;
    ll sum = 0, ans = 0;
    while (right < n)
    {
        sum += Books[right];

        while (sum > minutes)
        {
            sum -= Books[left];
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    cout << ans ;
}
