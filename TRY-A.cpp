//项目名:
//编号:TRY-A
/*
 Special
*/

//Ready!

//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const string rules_08="000102030405060710111213141516172021222324252627303132";
const string rules_10="000102030405060708091011121314151617181920212223242526";
const string rules_16="001A191817161514131211100F0E0D0C0B0A090807060504030201";

string answer="";

const bool DEBUGING=0;

template <class T>

void out(string s,T ans)
{
	if (DEBUGING==0) return;
	cout<<endl<<"example # "<<s<<" : "<<ans;
}

void choose_08(char c)
{
	int n=c-'A'+1;
	answer+=rules_08[2*n];
	
	out("choose_08 - 1",(int)c);
	
	answer+=rules_08[2*n+1];
	
	out("choose_08 - 2",rules_08[2*n+1]);
}

void choose_10(char c)
{
	int n=c-'A'+1;
	answer+=rules_10[2*n];
	
	out("choose_10 - 1",answer);
	
	answer+=rules_10[2*n+1];
	
	out("choose_10 - 2",answer);
}

void choose_16(char c)
{
	int n=c-'A'+1;
	answer+=rules_16[2*n];
	
	out("choose_16 - 1",answer);
	
	answer+=rules_16[2*n+1];
	
	out("choose_16 - 2",answer);
}

void choose_rule(char c,int rule)
{
	if (c==' ') {answer=answer+'0'+'0'+'0';return;}
	
	if ('a'<=c && c<='z')
	{
		c=c-'a'+'A';
		answer+='s';
		out("choose_rule a->A c",c);
	}
	else answer+='b';
	out("choose_rule a->A c",c);
	
	if (rule==8)
	{
		choose_08(c);
		return ;
	}
	if (rule==10)
	{
		choose_10(c);
		return;
	}
	if (rule==16)
	{
		choose_16(c);
		return;
	}
}

int main()
{
	char c;
	int rule;
	cin>>c;
	cin>>rule;
		out("main-out-1",answer);
		choose_rule(c,rule);
		out("main-out-2",answer);
		cout<<answer;
		cout<<endl;
	return 0;
}

