#include <bits/stdc++.h>

using namespace std;

map <string, int> mp;
set <int> g[10009];

string x[10009];

int main()
{
	ios::sync_with_stdio(false);
	int m, edg0;
	string a, b;
	while(cin >> m)
	{
		edg0 = 0;
		//mp.clear();
		//for(int i = 1;i <= m * 2;i ++)g[i].clear();
		while(m --)
		{
			cin >> a >> b;
			if(! mp[a])
			{
				edg0 ++;
				mp[a] = edg0;
			}
			x[mp[a]] = a;
			if(! mp[b])
			{
				edg0 ++;
				mp[b] = edg0;
			}
			x[mp[b]] = b;
			g[mp[a]].insert(mp[b]);
			g[mp[b]].insert(mp[a]);
		}
		cout << edg0 << endl;
		for(int i = 1;i <= edg0;i ++)
		{
			/*
			map <string, int> ::reverse_iterator rit;
			if(g[i].size() == 1)
			{
				for(rit = mp.rbegin();rit != mp.rend();rit ++)
					if((* rit).second == i)
						break;
				cout << (*rit).first << " " << g[g[i][0]].size() - 1 << endl;
				continue;
			}
			g[0].clear();
			for(int j = 1;j <= edg0;j ++)g[0].push_back(j);
			int ans = 0, tmp;
			for(int j = 0;j < g[i].size() - 1;j ++)
			{
				for(int k = j + 1;k < g[i].size();k ++)
				{
					vector <int> :: iterator it;
					it = set_intersection(g[g[i][j]].begin(), g[g[i][j]].end(),
				    	g[g[i][k]].begin(), g[g[i][k]].end(),
						g[0].begin());
					g[0].resize(it - g[0].begin());
					tmp = g[0].size();
					ans = max(ans, tmp);
				}
			}*/
			int p = 0, t = 0;
			for(int j = 1; j <= edg0; j++)
			{
				if(i != j && g[i].find(j) == g[i].end())
				{
					int x = 0;
					for(set <int>::iterator it = g[i].begin(); it != g[i].end(); it ++)
						if(g[j].find(*it) != g[j].end())
							x++;
					if(x > p) p = x, t = 1;
					else if(x == p) t++; 
				}
			}
			cout << x[i] << " " << t << endl;
		}
	}
	return 0;
}
