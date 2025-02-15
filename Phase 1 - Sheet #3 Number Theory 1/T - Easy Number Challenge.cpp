#include <iostream>
#include <vector>
using namespace std;
vector<bool> isprime;
vector<long long> primes;
void sieve(long long n)
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
long long primefactorization(long long n)
{
	long long ans = 1;
	for (long long i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++)
	{
		long long counter = 0;
		while (n % primes[i] == 0)
		{
			n /= primes[i];
			counter++;
		}
		ans *= (counter + 1);
	}
	if (n > 1)
		ans *= 2;
	return ans;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long a, b, c;
	cin >> a >> b >> c;
	sieve(a * b * c);
	vector<long long> v(1e6+1);
	v[0] = 0;
	v[1] = 1;
	for (long long i = 2; i <= a*b*c; i++)
	{
		v[i] = primefactorization(i);
	}
	long long ans = 0;
	for (long long i = 1; i <= a; i++)
	{
		for (long long j = 1; j <= b; j++)
		{
			for (long long k = 1; k <= c; k++)
			{
				ans += v[i * j * k];
			}
		}
	}
	cout << ans % 1073741824 << endl;
}

