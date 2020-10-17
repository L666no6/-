//项目名:
//编号:rule III
/*
 Special
*/
//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const bool DEBUGING=1;

//函数声明 
void wait(int ms);
void load();
void newuser ();
bool password ();
char chage(char s[3],int rule);
void choose(const int& go,char result[3]);
bool same (string a,string b);
string NtoL(string input);
//函数声明 

//From TRY-D,E
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

struct person
{
	string user_name;
	string password;
	string level;
};

#include <fstream>
#include <iostream>

person LXB;
person X;
string ORDER="He_loves_ZY.You_do_not_know!";

int number_of_user;
person p[20];

void load()
{
	LXB.user_name="L666no6";
	LXB.password="lxb1224022625";
	LXB.level="administrator";
	X.user_name="X";
	X.password="He_dislike_anyone_knows_his_things";
	X.level="special";
	
	
	ifstream in("Users imformation.txt");
 	in>>number_of_user;
	
	for (int i=0;i<number_of_user;i++)
	{
		in>>p[i].user_name;
		in>>p[i].password;
		in>>p[i].level;
		p[i].user_name=NtoL(p[i].user_name );
		p[i].password=NtoL(p[i].password );
		p[i].level =NtoL(p[i].level );
	}
	in.close();
}

void newuser ()//administrator,special,Trusted people
{
	person np;
	string s,s1;
	cout<<"Name:";
	cin>>np.user_name;
	password:
	cout<<"Password";
	cin>>s;
	cout<<"Input again";
	cin>>s1;
	if (s==s1) np.password=s;
	else 
	{
		cout<<"Error"<<endl;
		goto password;
	}
	np.level="user";
	cout<<"Please input administrator's order!";
	string order;
	cin>>order;
	if (order==ORDER) 
		np.level="Trusted people";
	ofstream out("Users imformation.txt");
	for (int i=0;i<number_of_user;i++)
	{
		out<<p[i].user_name <<' '<<p[i].password<<' '<<p[i].level;
	}
	number_of_user++;
	out<<np.user_name <<' '<<np.password<<' '<<np.level;
	out.close();
	cout<<"Please close!";
}

int now_person_number;

bool password ()
{
	person x;
	printf ("Please input a User name!\n");
	cin>>x.user_name;
	printf ("Please input a Password!!\n");
	cin>>x.password;
	if (x.user_name==LXB.user_name)
	{
		if (x.password==LXB.password )
		{
			cout<<"Welcome";
			now_person_number=-1;
			return 1;
		}
		if (x.password!=LXB.password)
		{
			cout<<"Locked!!!";
			while (1);
		}
	}
	if (x.user_name==X.user_name)
	{
		if (x.password==X.password )
		{
			cout<<"Welcome";
			now_person_number=-2;
			return 1;
		}
		if (x.password!=X.password)
		{
			cout<<"Locked!!!";
			while (1);
		}
	}
	for (int i=0;i<number_of_user;i++)
	{
		if (x.user_name==p[i].user_name)
		{
			if (x.password==p[i].password )
			{
				now_person_number=i;
				cout<<"Hello,"<<x.user_name;
				return 1;
			}
			else 
			{
				cout<<"Error!";
				return 0;
			}
		}
	}
}
//From Try D,E

//From TRY-a
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
	return '#';
	
	next:
	
	return (char)x-1+'a'+Aa;
}
//From TRY-a

//Form TRY-b
string input_b="";
char result_b[3];

void choose(const int& go,char result[3]) { for (int i=0;i<3;i++) result[i]=input_b[go+i]; }
//Form TRY-b

bool same (string a,string b)
{
	if (a==b) return 1;
	return 0;
}


bool Isnumber(char c)
{
	if ('0'<=c && c<='9') return 1;
	return 0;
}

bool Isletter(char c)
{
	if ('a'<=c && c<='z') return 1;
	if ('A'<=c && c<='Z') return 1;
	return 0;
}

string NtoL(string input)
{
	string output="";
	int len=input.length();
	bool fany=1;
	bool BAB=0;
	int rule=0;
	for (int i=0;i<len;i++)
	{
										out ("NtoL [for] loading - i",i);
										out ("NtoL [for] loading - fany",fany);
										out ("NtoL [for] loading - BAB",BAB);
										out ("NtoL [for] loading - rule",rule);
										out ("NtoL [for] loading - input[i]",input[i]);
		if ( !( ('a'<=input[i] && input[i]<='z') || 
				('A'<=input[i] && input[i]<='Z') ||
				('0'<=input[i] && input[i]<='9') ) )
		{
										out ("NtoL [for] input[i] isn't number or letter char!",1);
			output+=input[i];
			continue;
		}
		if (BAB==1 && Isnumber(input[i])==1)
		{
										out ("NtoL [for] input[i] was a number!",1);
			output+=input[i];
			continue;
		}
		char now[3];
		input_b=input;
		choose(i,now);
		out ("NtoL [for] - i ",i);
		out ("NtoL [for] - now[3]",now);
		if (same (now,"EEE"))
		{
			out ("NtoL found a EEE",'\n');
			fany=!fany;
			i+=2;
			continue;
		}
		if (same (now,"BAB"))
		{
			out ("NtoL found a BAB",'\n');
			BAB=1;
			i+=2;
			continue;
		}
		
		else if (BAB==1 && (input[i]=='b' || input[i]=='s') ) 
		{
			BAB=0;
		}
		if (same (now,"CCC")) {rule=10;out("NtoL found a CCC",'\n');i+=2;continue;}
		if (same (now,"DDD")) {rule=8 ;out("NtoL found a DDD",'\n');i+=2;continue;}
		if (same (now,"FFF")) {rule=16;out("NtoL found a FFF",'\n');i+=2;continue;}
		if (fany)
		{
			if (same (now,"000"))
			{
				output+=' ';
				out("NtoL found a 000",' ');
				i+=2;
				continue;
			}
			char c;
			c=chage(now,rule);
			out("NtoL chage-c",c);
			if (c=='#') {output="Error";/*out("main: chage Error",'\n');*/break;}
			output+=c;
			out("NtoL output+=c",output);
			i+=2;
			cout<<endl;
		}
		else 
		{
			output += input[i];
		}
	}
	out("NtoL: [for] break",'\n');
	return output;
}

int main()
{
	if (DEBUGING==0)
	{
		load();
		bool b=0;
		for (int i=0;i<3 && b==0;i++)
		{
			b=password();
		}
		if (b==0)
		{
			cout<<"Locked!!";
			while (1);
		}
	
		wait (1000);
		system("cls");
	}
	
	
	go_on:
	
	string input;
	cin>>input;
	cout<<NtoL(input);
		
	cout<<"\n\nAre you want to run again? (y/n):";
	char answer_main_c;
	cin>>answer_main_c;
	if (answer_main_c=='y') goto go_on;
	
	return 0;
}

