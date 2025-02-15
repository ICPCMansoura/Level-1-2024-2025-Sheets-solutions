#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<bool> isprime;
vector<int> primes;
void sieve(int n)
{
	isprime.resize(n + 1, true);
	isprime[0] = isprime[1] = false;
	for (int i = 2; i <= n; i++)
	{
		if (isprime[i])
		{
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i)
				isprime[j] = false;
		}
	}
}
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	sieve(50);
	int counter = 0;
	for (int i = 0; i < primes.size(); i++)
	{
		cout << primes[i] << endl;
		cout.flush();
		string s;
		cin >> s;
		if (s == "yes")
		{
			counter++;
			if (primes[i] * primes[i] <= 100)
			{
				cout << primes[i] * primes[i] << endl;
				cout.flush();
				cin >> s;
				if (s == "yes")
					counter++;
			}
		}
		if (counter >= 2)
		{
			cout << "composite" << endl;
			cout.flush();
			return 0;
		}
	}
	cout << "prime" << endl;
	cout.flush();
	return 0;
}

