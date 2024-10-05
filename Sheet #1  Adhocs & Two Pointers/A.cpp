#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   vector<int>cards(n);
    for (int i = 0; i < n; ++i) {
        cin >>cards[i];
    }
    int right = n - 1 , left = 0;
    bool turn = true ; //To switch turns of the game
    long long Sereja = 0, Dima = 0;

    // In this game Sereja moves first
    // so when turn = 1 it is Sereja's turn and if turn = 0 it is Dima's turn
    while(left <= right)
    {
        if(turn)
        {
            if(cards[left]>cards[right])
                Sereja += cards[left++];
            else
                Sereja += cards[right--];
        }
        else
        {
            if(cards[left]>cards[right])
                Dima += cards[left++];
            else
                Dima += cards[right--];
        }
        turn = (turn ^ 1);
        //to switch between 1 and 0 we use xor whit 1
        //if turn is 1 -> turn = 1 ^ 1 = 0
        //if turn is 0 -> turn = 0 ^ 1 = 1
    }
    cout << Sereja <<' '<<Dima;

}