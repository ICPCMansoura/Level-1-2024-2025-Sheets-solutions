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
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	seive(200000);
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> a(n, vector<long long>(m));
	for (long long i = 0; i < n; i++)
		for (long long j = 0; j < m; j++)
		{
			long long x;
			cin >> x;
			a[i][j] = *lower_bound(primes.begin(), primes.end(), x) - x;
		}
	long long ans = 1e9;
	for (long long i = 0; i < n; i++)
	{
		long long sum = 0;
		for (long long j = 0; j < m; j++)
			sum += a[i][j];
		ans = min(ans, sum);
	}
	for (long long j = 0; j < m; j++)
	{
		long long sum = 0;
		for (long long i = 0; i < n; i++)
			sum += a[i][j];
		ans = min(ans, sum);
	}
	cout << ans << endl;
}