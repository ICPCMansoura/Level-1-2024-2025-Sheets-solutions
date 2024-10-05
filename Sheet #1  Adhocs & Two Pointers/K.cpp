#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[1005][1005], c[1005][1005], e[1005][1005];
int main()
{
    int N ,M ;cin >> N >> M;

    for(int i=1; i <= N; i++)
    {
        for(int j=1; j <= M; j++) {
            char x;
            cin >> x;
            a[i][j] = a[i][j-1] + a[i-1][j] - a[i-1][j-1] + (x == 'a' ? 1 : 0);
            c[i][j] = c[i][j-1] + c[i-1][j] - c[i-1][j-1] + (x == 'c' ? 1 : 0);
            e[i][j] = e[i][j-1] + e[i-1][j] - e[i-1][j-1] + (x == 'e' ? 1 : 0);
        }
    }

    int q; cin>>q;
    while (q--)
    {
        int x1,x2,y1,y2 ;cin >> x1 >> y1 >> x2 >> y2;

        int c1 = a[x2][y2] - a[x2][y1-1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1];
        int c2 = c[x2][y2] - c[x2][y1-1] - c[x1 - 1][y2] + c[x1 - 1][y1 - 1];
        int c3 = e[x2][y2] - e[x2][y1-1] - e[x1 - 1][y2] + e[x1 - 1][y1 - 1];
        cout<<min({c1,c2,c3})<<endl;
    }

}
