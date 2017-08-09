#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a,b,k;
	cin>>k>>a>>b;
	int sum = 0;
	if(a < k && b < k)cout<<-1<<endl;
	else 
	{
		sum += a / k ;
		sum += b / k ;
		cout<<sum<<endl;
	}
	return 0;
} 
