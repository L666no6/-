//项目名:
//编号:B-
//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
	{
		printf ("|");
		for (int j=0;j<n-i-1;j++)
		{
			printf (" ");
		}
		printf ("/1");
		printf ("\n");
	}
	char c=(char)47;
	for (int i=n;i>=1;i++)
	{
		printf ("|");
		for (int j=0;j<n-i;j++)
		{
			printf (" ");
		}
		printf ("%c\n",c);
	}
	return 0;
}

