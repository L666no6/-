//项目名:
//编号:TRY-RAND 
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

int Rand (int start,int end)// [a,b]
{
	srand( (unsigned int) ( clock() ) );
	return rand()%(end-start)+start;
}


int main()
{
	for (int i=0;i<20;i++)
	{
		cout<<Rand(1,3)<<' ';
	}
	cout<<endl;
	for (int i=0;i<20;i++)
	{
		cout<<Rand(1,3)<<' ';
	}
	return 0;
}

