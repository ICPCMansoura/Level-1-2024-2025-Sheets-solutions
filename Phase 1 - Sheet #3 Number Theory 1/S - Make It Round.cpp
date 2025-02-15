#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long tempn = n;
        long long n2 = 0;
        long long n5 = 0;
        while (tempn % 2 == 0)
        {
            tempn /= 2;
            n2++;
        }
        while (tempn % 5 == 0)
        {
            tempn /= 5;
            n5++;
        }
        long long ans = 1;
        if (n2 < n5)
        {
            while (n2 < n5 && ans * 2 <= m)
            {
                ans *= 2;
                n2++;
            }
        }
        else if (n2 > n5)
        {
            while (n2 > n5 && ans * 5 <= m)
            {
                ans *= 5;
                n5++;
            }
        }
        if (n2 == n5)
        {
            while (ans * 10 <= m)
            {
                ans *= 10;
            }
        }
        ans *= (m / ans);
        ans *= n;
        cout << ans << "\n";
    }
}
