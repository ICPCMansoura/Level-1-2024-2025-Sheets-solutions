#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int n;
	cin >> n;
	vector<int> a(n);
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		while (a[i] % 2 == 0)
			a[i] /= 2;
		while (a[i] % 3 == 0)
			a[i] /= 3;
		if (a[i] != a[0])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

}

