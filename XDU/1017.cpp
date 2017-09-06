#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

struct rating
{
	string first;
	int second;
} rr[10009];

bool comp(const rating a, const rating b)
{
	return a.second != b.second ? a.second > b.second : a.first < b.first;
}

int main()
{
	int n;
	ios::sync_with_stdio(false);
	while(cin >> n && n)
	{
		for(int i = 1;i <= n;i ++)
			cin >> rr[i].first >> rr[i].second;
		sort(rr + 1, rr + 1 + n, comp);
		for(int i = 1;i <= n;i ++)
			cout << rr[i].first << ' ' << rr[i].second << endl;
	}
	return 0;
}
