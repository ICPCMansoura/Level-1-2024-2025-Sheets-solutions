#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    
        int n; cin >> n;
        vector <int> songs(n);

        for (int i = 0; i < n; i++)
            cin >> songs[i];

        map <int,int> freq;
        int left = 0 , right = 0 , total = -1;
        while (right < n) {
            freq[songs[right]]++;
            if(freq[songs[right]] == 1) {
                total = max(total , right - left + 1);
                right++;
            } else {
                while (left < right && freq[songs[right]] != 1) {
                    freq[songs[left]]--;
                    left++;
                }
                right++;
            }
        }

        cout << total << '\n';
    }
