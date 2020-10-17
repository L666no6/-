//项目名:密码规则III
//编号:B-密码规则III-TRY
/*
 Special
*/
//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const char letterA[28]={"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
const char letterB[28]={"abcdefghijklmnopqrstuvwxyz"};



string ChageALetter(char c,int rule)
{
	// Load
	string answer="";
const string rules_08={"000102030405060710111213141516172021222324252627303132"};
const string rules_10={"000102030405060708091011121314151617181920212223242526"};
const string rules_16={"001A191817161514131211100F0E0D0C0B0A090807060504030201"};
	
	//Load
	
	//GoOn
	
	if ('A'<=c && c<='Z')
	{
		answer+='b';
		goto rules;
	}
	if ('a'<=c && c<='z')
	{
		answer+='s';
		c=c-'a'+'A';
		goto rules;
	}
	answer+=c;
	return answer;
	
	rules:
	
	if (rule==8)
	{
		answer+=rules_08[c-'A'+1];
		goto end;
	}
	if (rule==10)
	{
		answer+=rules_10[c-'A'+1];
		goto end;
	}
	if (rule==16)
	{
		answer+=rules_16[c-'A'+1];
		goto end;
	}
	
	end:
	return answer;
}

int main()
{
	char c;
	int rule;
	cin>>c>>rule;
		cout<<ChageALetter(c,rule);
	return 0;
}

