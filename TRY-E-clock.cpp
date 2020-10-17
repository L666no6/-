//项目名:
//编号:TRY-E-time
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

void wait(int ms)
{
	clock_t a;
	while (clock()-a<ms);
}

int main()
{
	cout<<'a';
	wait(3000);
	cout<<'b' ;
	return 0;
}

