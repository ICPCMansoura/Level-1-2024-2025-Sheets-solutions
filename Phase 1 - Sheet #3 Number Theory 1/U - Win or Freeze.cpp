#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long>primefactors(long long n)
{
	vector<long long> factors;
	for (long long i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			factors.push_back(i);
			n /= i;
			if (factors.size() >= 3)
			{
				break;
			}
		}
		if (factors.size() >= 3)
		{
			break;
		}
	}
	if (n>1)
	{
		factors.push_back(n);
	}
	return factors;
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n;
	cin >> n;
	vector<long long> factors = primefactors(n);
	if (factors.size() <= 1)
	{
		cout << "1\n0";
	}
	else if (factors.size() == 2)
	{
		cout << "2";
	}
	else
	{
		cout << "1\n" << factors[0] * factors[1];
	}
	return 0;
}
