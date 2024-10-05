#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    string word;
    int letters[256]={0},right,left=0;
    char missed;
    cin >> word;
    for (right=0; right < word.size(); right++)
    {
        if (word[right] != '?')
        {
            letters[word[right]]++;
            while (letters[word[right]] > 1)
            {
                if (word[left] != '?')
                    letters[word[left]]--;
                left++;
            }
        }
        if (right - left == 25)
        {
            for (missed='A'; left <= right; left++)
                if (word[left] == '?')
                {
                    while (letters[missed] > 0)
                        missed++;
                    word[left]=missed;
                    letters[missed]++;
                }
            for (int l=0; l < word.size(); l++)
                if (word[l] == '?')
                    word[l]='A';
            cout << word;
            return 0;
        }
    }
    cout << -1;
}
