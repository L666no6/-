//��Ŀ��:
//���:TRY-B
/*
 Special
*/

//ready!

//������:���Ѳ�

#include<bits/stdc++.h>
using namespace std;

string input_s;
string output_s;

char choose_litter(int i)
{
	return input_s[i];
}

int main()
{
	cin>>input_s;
	output_s="";
	for (int i=0;i<input_s.length();i++)
	{
		output_s+=choose_litter (i);
	}
	cout<<output_s;
	return 0;
}

