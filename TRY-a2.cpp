//项目名:
//编号:TRY-a
/*
 Special
*/

//ready!

//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const bool DEBUGING=0;

template <class T>
void out(string s,T ans){
	if (DEBUGING==0) {return;}
	cout<<endl<<"example # "<<s<<" : "<<ans;
}
//						 AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz
const string rules_08="000102030405060710111213141516172021222324252627303132";
const string rules_10="000102030405060708091011121314151617181920212223242526";
const string rules_16="001A191817161514131211100F0E0D0C0B0A090807060504030201";

char chage(char s[3],int rule)
{
	int Aa;
	if (s[0]=='s') Aa=0;
	if (s[0]=='b') Aa='A'-'a';
	
	string rules;
	if (rule==8) rules=rules_08;
	if (rule==10)rules=rules_10;
	if (rule==16)rules=rules_16;
	int x=-1;
	for (int i=2;i<rules.length();i+=2)
	{
		if (s[1]==rules[i])
		{
			for (int j=i+1;j<rules.length() && rules[j-1]==s[1];j++)
			{
				if (rules[j]==s[2])
				{
					x=(j-1)/2;
					goto next;
				}
			}
		}
	}
	return '0';
	
	next:
	
	return (char)x-1+'a'+Aa;
}

int main()
{
	int rule;
	char input_a[3];
	cin>>input_a;
	cin>>rule;
	cout<<chage(input_a,rule);
	return 0;
}

