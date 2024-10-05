#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TestCases;
    cin >> TestCases;
    while (TestCases--)
    {
        int W, H, N;
        cin >> W >> H >> N;
        vector<vector<int>>bord(W + 2, vector<int>(H + 2, 0));

        while (N--)
        {
            int X1, Y1, X2, Y2;
            cin >> X1 >> Y1 >> X2 >> Y2;
            if (X1 > X2)swap(X1, X2);
            if (Y1 > Y2)swap(Y1, Y2);
            bord[X1][Y1] += 1;
            bord[X1][Y2 + 1] -= 1;
            bord[X2 + 1][Y1] -= 1;
            bord[X2 + 1][Y2 + 1] += 1;
        }
        for (int i = 1; i <= W; ++i) {
            for (int j = 1; j <= H; ++j) {
                bord[i][j] += bord[i][j - 1];
            }
        }
        for (int i = 1; i <= W; ++i) {
            for (int j = 1; j <= H; ++j) {
                bord[i][j] += bord[i - 1][j];
            }
        }
        int Num_of_portion = 0;
        for (int i = 1; i <= W; ++i) {
            for (int j = 1; j <= H; ++j) {
                if (bord[i][j] > 0)
                    Num_of_portion++;
            }
        }
        cout << W * H - Num_of_portion << endl;
    }
}