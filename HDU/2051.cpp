#include <bits/stdc++.h>

using namespace std;

const int Size = 32;

char str[Size];

int main(void)
{
	int num;
	while (~scanf("%d", &num))
	{
		bitset <Size> bs(num);
		strcpy(str, bs.to_string().c_str());
		for (int i = Size - (int)log2(num + 1e-9) - 1; i < Size; ++i)
			putchar(str[i]);
		if( num == 0 )cout<<0;
		putchar('\n');
	}
	return 0;
}
