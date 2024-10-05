#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n , x;
    cin >> n >> x;
    vector<pair<int,int>>values(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> values[i].first;
        values[i].second = i;
    }
    sort(values.begin(),values.end());
    int left = 1 , right = n;
    while(left < right)
    {
        if(values[left].first + values[right].first == x)
            break;
        else if(values[left].first + values[right].first > x)
            right--;
        else
            left++;
    }
    if(left >= right)
        cout << "IMPOSSIBLE";
    else
        cout << values[left].second << ' ' << values[right].second;
}