#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, t;
	scanf("%d", &n);
	set <int> s;
	s.insert(0);
	while(n --)
	{
		scanf("%d", &t);
		if(t < *s.rbegin())
		{
			s.erase(*(s.upper_bound(t)));
		}
		s.insert(t);
	}
	printf("%d\n", s.size() - 1);
	return 0;
}
