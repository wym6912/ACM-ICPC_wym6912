#include <bits/stdc++.h>

using namespace std;

char data[11][10] = 
{"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu", "fu"};

int main()
{
	int x;
	bool flag = false;
	scanf("%d", &x);
	if(x < 0)x = -x, printf("%s ", data[10]);
	if(x)
	{
		stack <int> st;
		while(x)
		{
			st.push(x % 10);	
			x /= 10;
		}
		while(! st.empty())
		{
			printf("%s", data[st.top()]);
			st.pop();
			if(! st.empty())printf(" ");
			else printf("\n");
		}
	}
	else puts(data[0]);
	return 0;
}
