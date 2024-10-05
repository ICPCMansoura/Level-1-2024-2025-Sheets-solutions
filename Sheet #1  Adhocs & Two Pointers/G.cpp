#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int TestCases;
    cin >> TestCases;
    while(TestCases--)
    {
        int n; cin >> n;
        vector<ll>cells(n);
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> cells[i];
            sum += cells[i];
        }
        string directions; cin >> directions;
        int left = 0, right = n - 1;
        ll points = 0;
        while (left < right)
        {
            while (directions[left] == 'R')
            {
                sum -= cells[left];
                left++;
            }
            while (directions[right] == 'L')
            {
                sum -= cells[right];
                right--;
            }
            if (right < left)
                break;
            points += sum;
            sum = sum - cells[left] - cells[right];
            left++; right--;
        }
        cout << points << "\n";
    }
}