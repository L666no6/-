//项目名:
//编号:TYR-C-[key]
/*
 Special
*/

//ready

//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const bool DEBUGING=0;

template <class T>

void out(string s,T ans)
{
	if (DEBUGING==0) return;
	cout<<"example # "<<s<<" : "<<ans<<endl;
}

string input_C;

bool read(int go,int& start,int& end,const char& a,const char& b)//ready!
//识别 ()[]{},but no twins
{
	int len=input_C.length();
//	out("read get the length of string from input",len);
	for (int i=go;i<len;i++)
	{
//		out("read find start - c",input_C[i]);
//		out("read find start - i",i);
		if (input_C[i]==a) {start=i;break;}
		if (input_C[i]==b) return 0;
	}
//	out("read found start - c",input_C[start]);
//	out("read found start",start);
	for (int i=start+1;i<len;i++)
	{
//		out("read find end - c",input_C[i]);
//		out("read find end - i",i);
		if (input_C[i]==a) return 0;
		if (input_C[i]==b) {
			end=i;
//			out("read found end - c",input_C[end]);
//			out("read found end",end);
			return 1;
		}
	}
//	out("read can't find end - c\n",input_C[len-1]);
	return 0;
}

int now=0;

string GetInString(int go,int& rule)
{
	int start,end;
	bool b=read(go,start,end,'[',']');
//	out("GetInString -b",b);
	if (b==0) return "Error";
//	out("GetInString -start (of '[')",start);
//	out("GetInString -end (of ']')",end);
	string answer="";
	for (int i=start+1;i<end;i++)
	{
		answer+=input_C[i];
	}
//	out("GetInString -answer",answer);
	
	string number="";
	b=read(end,start,end,'(',')');
//	out("GetInString -b",b);
	if (b==0) return "Error";
//	out("GetInString -start",start);
//	out("GetInString -end",end);
	for (int i=start+1;i<end;i++)
	{
		number+=input_C[i];
	}
//	out("GetInString -rule",number);
	if (number=="8" || number=="08") {rule=8;now=end;}
	else if (number=="10" ) {rule=10;now=end;}
	else if (number=="16" ) {rule=16;now=end;}
	else return "Error";
	return answer;
}

int main()
{
	cin>>input_C;
	int start,end;
	int rule;
	string s=GetInString(now,rule);
	if (s=="Error") cout<<"Error";
	else cout<<s<<' '<<rule;
	return 0;
}

