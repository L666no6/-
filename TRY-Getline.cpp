//项目名:
//编号:TRY-Getline
/*
 Special
*/
//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const bool DEBUGING=0;

template <class T>
void out(string s,T ans){
	if (DEBUGING==0) {return;}
	cout<<endl<<"example # "<<s<<" : "<<ans;
}

string Getline (char s[])
{
	int i=0;
	char c;
	scanf ("%c",&c);
	while (c!='\n') {
		s[i]=c;
		i++;
		scanf ("%c",&c);
	}
	s[i]='\0';
	string s1=s;
	return s1;
}

int main()
{
	char s[100];
	string s1=Getline (s);
	cout<<s1;
	return 0;
}

