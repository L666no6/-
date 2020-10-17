//项目名:
//编号:TRY-choose_a_string
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

string choose_a_string(string s,int start,int len)
{
	string output="";
	for (int i=0;i<len;i++)
	{
		output+=s[i+start];
	}
	return output;
}

int main()
{
	string input;
	cin>>input;
	string output=choose_a_string(input,2,7);
	cout<<output;
	return 0;
}

