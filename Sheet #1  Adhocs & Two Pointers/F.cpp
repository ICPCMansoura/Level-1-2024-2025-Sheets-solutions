#include <bits/stdc++.h>
using namespace std;
int main()
{
    int TestCases;
    cin >> TestCases;
    while(TestCases--)
    {
        int n ; cin >> n;
        vector<int>candies(n);
        for (int i = 0; i < n; ++i) {
            cin >> candies[i];
        }
        int left = 0 , right = n-1 , CandiesEaten = 0 , MaxCandiesEaten = 0;
        int Alice = 0 , Bob = 0;
        while(left <= right)
        {
            if(left==right && Alice == Bob)
                break;
           if(Alice == Bob)
           {
               MaxCandiesEaten = CandiesEaten;
               Alice+=candies[left++];
               Bob+=candies[right--];
               CandiesEaten+=2;
           }
           else if (Alice>Bob)
           {
               Bob+=candies[right--];
               CandiesEaten++;
           }
           else
           {
               Alice+=candies[left++];
               CandiesEaten++;
           }
        }

        if(Alice == Bob)
            MaxCandiesEaten = CandiesEaten;

        cout << MaxCandiesEaten << endl ;
    }
}