#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

int main() {
    FAST_IO;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    vector<int> freq(n + 1, 0);
    int currentMEX = 0;
    int left = 0, right = 0;
    int MaxMEX = 0, MaxRange = 0;

    while (right < n) {
        freq[nums[right]]++;
        while (freq[currentMEX] > 0) {
            currentMEX++;
        }
        while (freq[nums[right]] > 1) {
            freq[nums[left]]--;
            if (nums[left] < currentMEX && freq[nums[left]] == 0) {
                currentMEX = nums[left];
            }
            left++;
        }
        if (currentMEX > MaxMEX) {
            MaxMEX = currentMEX;
            MaxRange = right - left + 1;
        } else if (currentMEX == MaxMEX) {
            MaxRange = max(MaxRange, right - left + 1);
        }
        right++;
    }

    cout << MaxRange;
}
