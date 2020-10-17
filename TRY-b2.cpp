//项目名:
//编号:TRY-b2
/*
 Special
*/
//制作人:林暄博

//ready!!! 

#include<bits/stdc++.h>
using namespace std;

const bool DEBUGING=0;

template <class T>
void out(string s,T ans){
	if (DEBUGING==0) {return;}
	cout<<endl<<"example # "<<s<<" : "<<ans;
}

string input_b="";
char result_b[3];

void choose(const int& go,char result[3]) { for (int i=0;i<3;i++) result[i]=input_b[go+i]; }

int main()
{
	cin>>input_b;
	if (input_b.length()%3 !=0) {cout<<"Error!";return 0;}
	string output="";
	for (int i=0;i<input_b.length();i+=3)
	{
		choose(i,result_b);
		output=output+result_b+'\n';
	}
	cout<<output;
	return 0;
}

