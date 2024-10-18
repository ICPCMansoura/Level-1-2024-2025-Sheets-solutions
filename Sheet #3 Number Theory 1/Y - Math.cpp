#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<int, int> factors;
	int maximum = 0;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			factors[i]++;
			n /= i;
			maximum = max(maximum, factors[i]);
		}
	}
	int maxpow2 = 1,counter = 0;
	while (maxpow2 < maximum)
	{
		maxpow2 *= 2;
		counter++;
	}
	int ans = 1, flag = 0;
	for (auto i : factors)
	{
		if (i.second != maxpow2)
		{
			flag = 1;
		}
		ans *= i.first;
	}
	cout << ans << " " << counter + flag;

}

