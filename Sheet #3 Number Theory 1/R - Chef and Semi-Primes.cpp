#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
bool issemiprime(int n)
{
	map<int, int> m;
	int cnt = 0;
	for (int i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			m[i]++;
			cnt++;
			n /= i;

		}
	}
	if (n > 1)
		cnt++, m[n]++;
	return (cnt == 2) && (m.size() == 2);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool flag = false;
		for (int i = 4; i <= n; i++)
		{
			if (issemiprime(i) && issemiprime(n - i))
			{
				flag = true;
				break;
			}
		}
		if (flag)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}
