#include <bits/stdc++.h>

using namespace std;

int main()
{
	int hh, mm;
	scanf("%d:%d", &hh, &mm);
	if((hh == 12 && mm == 0) || (hh < 12))
		printf("Only %02d:%02d.  Too early to Dang.", hh, mm);
	else 
	{
		while(mm)mm = 0, printf("Dang");
		while(hh != 12)hh --, printf("Dang");
	}
	printf("\n");
	return 0;
}
