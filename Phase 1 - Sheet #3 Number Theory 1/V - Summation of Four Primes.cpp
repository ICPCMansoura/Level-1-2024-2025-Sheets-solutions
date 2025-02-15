#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<bool> isprime;
vector<long long> primes;
void seive(long long n)
{
	isprime.resize(n + 1, true);
	isprime[0] = isprime[1] = false;
	for (long long i = 2; i <= n; i++)
	{
		if (isprime[i])
		{
			primes.push_back(i);
			for (long long j = i * i; j <= n; j += i)
				isprime[j] = false;
		}
	}
}

int main()
{
	seive(10000000);
	long long n;
	while (cin >> n)
	{
		bool flag = true;
		vector<long long> ans;
		for (long long i = 6; i >= 0; i-=2)
		{
			long long it = upper_bound(primes.begin(), primes.end(), n - i) - primes.begin() - 1;
			if (it < 0)
			{
				flag = false;
				break;
			}
			n -= primes[it];
			ans.push_back(primes[it]);
		}
		if (flag)
		{
			for (long long i = 0; i < 4; i++)
			{
				cout << ans[i];
				if (i != 3)
					cout << " ";
			}
			cout << endl;
		}
		else
			cout << "Impossible." << endl;
	}
}

