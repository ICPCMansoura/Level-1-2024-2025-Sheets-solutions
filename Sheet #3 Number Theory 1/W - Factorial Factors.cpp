#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
long long primefactorization(long long n)
{
	long long factors = 0;
	for (long long i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			factors++;
			n /= i;
		}
	}
	if (n > 1)
	{
		factors++;
	}
	return factors;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	vector<long long> v(1e6+1);
	for (long long i = 2; i <= 1e6; i++)
	{
		v[i] = primefactorization(i) + v[i-1];
	}
	long long n;
	while (cin >> n)
	{
		cout << v[n] << endl;
	}
}
