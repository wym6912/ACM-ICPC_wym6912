#include <bits/stdc++.h>

using namespace std;

struct data_book
{
	int time;
	int bh, bm;
	bool hasb, fi;
	data_book(int time, int bh, int bm, bool hasb, bool fi)
	 : time(time), bh(bh), bm(bm), hasb(hasb), fi(fi) {}
	data_book(){}
};
data_book book[2009];

int main()
{
	int n, bookid, hh, mm, ans1, ans3;
	double ans2;
	char ch;
	scanf("%d", &n);
	while(n --)
	{
		ans1 = 0;
		ans2 = 0.0;
		for(int i = 1; i <= 1000; i ++)
		{
			book[i] = data_book(0, 0, 0, false, false);
		}
		bookid = -1;
		while(scanf("%d %c %d:%d", &bookid, &ch, &hh, &mm) && bookid)
		{
			switch(ch)
			{
				case 'S':
					book[bookid].bm = mm + hh * 60;
					book[bookid].hasb = true;
					break;
				case 'E':
					if(book[bookid].hasb)
					{
						ans2 += (double)(hh * 60 + mm - book[bookid].bm);
						ans1 ++;
						book[bookid].bm = 0;
						book[bookid].hasb = false;
						book[bookid].fi = true;
					}
					break;
				default:
					assert(false);
			}
		}
		if(ans1)
		{
			ans2 /= ans1;
		}
		ans3 = (double)(ans2 + 0.5f);
		printf("%d %d\n", ans1, ans3);
	}
	return 0;
}
/*
4
1 S 08:10
2 S 08:35
1 E 10:00
2 E 13:16
0 S 17:00
0 S 17:00
3 E 08:10
1 S 08:20
2 S 09:00
1 E 09:20
0 E 17:00
1000 S 00:00
2 S 00:00
298 S 00:01
298 E 23:59
2 E 23:59
1000 E 23:59
0 E 23:59
*/
