//项目名:
//编号:Real-rule
/*
 Special
*/
//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

//From <TRY-A>
const string rules_08="000102030405060710111213141516172021222324252627303132";
const string rules_10="000102030405060708091011121314151617181920212223242526";
const string rules_16="001A191817161514131211100F0E0D0C0B0A090807060504030201";

string answer="";

const bool DEBUGING=0;



bool Isnumber (char c);
bool Isletter (char c);

template <class T>

void out(string s,T ans)
{
	if (DEBUGING==0) return;
	cout<<endl<<"example # "<<s<<" : "<<ans;
}

void choose_08(char c)
{
										out ("choose_08","go");
	int n=c-'A'+1;
	answer+=rules_08[2*n];
										out("choose_08 - 1",answer);
	answer+=rules_08[2*n+1];
										out("choose_08 - 2",answer);
}

void choose_10(char c)
{
										out ("choose_10","go");
	int n=c-'A'+1;
	answer+=rules_10[2*n];
										out("choose_10 - 1",answer);
	answer+=rules_10[2*n+1];
										out("choose_10 - 2",answer);
}

void choose_16(char c)
{
										out ("choose_16","go");
	int n=c-'A'+1;
	answer+=rules_16[2*n];
										out("choose_16 - 1",answer);
	answer+=rules_16[2*n+1];
										out("choose_16 - 2",answer);
}

void choose_rule(char c,int rule)
{
										out ("\n\nchoose_rule","go");
	if (c=='_') {answer=answer+'0'+'0'+'0';return;}
	
	if (Isnumber(c)==1) {answer=answer+c;return;}
	
	if ('a'<=c && c<='z')
	{
		c=c-'a'+'A';
		answer+='s';
										out("choose_rule a->A c",c);
	}
	else {
		answer+='b';
										out("choose_rule a->A c",c);	
	}
										out ("choose_rule rule",rule);
	
	if (rule==8) {choose_08(c);return;}
	if (rule==10){choose_10(c);return;}
	if (rule==16){choose_16(c);return;}
}

//From <TRY-A>

//From <TRY-B>
string input_s;
string output_s;

char choose_litter(int i) {return input_s[i];}

bool yih(bool a,bool b)//异或
{
	if (a==0 && b==1) return 1;
	if (a==1 && b==0) return 0;
	return 0;
} 

string Chage1(int rule)
{
										out ("Chage1","go");
										out ("Chage1 rule",rule);
	output_s="";
	char lastchar='#';
	for (int i=0;i<input_s.length();i++){
		char nowchar=choose_litter (i);
										out ("Chage1 [for] nowchar ",nowchar);
										out ("Chage1 [for] lastchar",lastchar);
		if (i!=0 && yih(Isnumber(lastchar),Isnumber(nowchar) ) )
		{
			output_s+="BAB";
		}
		if (Isnumber(nowchar)==1){
			
			output_s+=nowchar;
			lastchar=nowchar;
			continue;
		}
										out ("Chage1 [for] rule",rule);
		choose_rule(nowchar,rule);
										out ("Chage1 [for] answer",answer);
		output_s+=answer;
		answer="";
		lastchar=nowchar;
	}
//	if (Isnumber(input_s[input_s.length()-1])==1) output_s+="BAB"; 
	return output_s;
}
//From <TRY-B>

//From <TRY-C>
string input_C;

bool read(int go,int& start,int& end,const char& a,const char& b)//ready!
//识别 ()[]{},but no twins
{
//										out("\n\nread ","go_on!!\n");
	int len=input_C.length();
//										out("read get the length of string from input",len);
	for (int i=go;i<len;i++)
	{
//										out("read find start - c",input_C[i]);
//										out("read find start - i",i);
		if (input_C[i]==a) {start=i;break;}
		if (input_C[i]==b) return 0;
	}
//										out("read found start - c",input_C[start]);
//										out("read found start",start);
	for (int i=start+1;i<len;i++)
	{
//										out("read find end - c",input_C[i]);
//										out("read find end - i",i);
		if (input_C[i]==a) return 0;
		if (input_C[i]==b) {
			end=i;
//										out("read found end - c",input_C[end]);
//										out("read found end",end);
			return 1;
		}
	}
//										out("read can't find end - c\n",input_C[len-1]);
	return 0;
}

int now=0;

string GetInString(int go,int& rule)
{
	int start,end;
										out("\n\nGetInString ","go_on!!\n");
	bool b=read(go,start,end,'[',']');
										out("GetInString -b",b);
	if (b==0) return "Error";
										out("GetInString -start (of '[')",start);
										out("GetInString -end (of ']')",end);
	string answer="";
	for (int i=start+1;i<end;i++)
	{
		answer+=input_C[i];
	}
										out("GetInString -answer",answer);
	
	string number="";
	b=read(end,start,end,'(',')');
										out("GetInString -b",b);
	if (b==0) return "Error";
										out("GetInString -start",start);
										out("GetInString -end",end);
	for (int i=start+1;i<end;i++)
	{
		number+=input_C[i];
	}
										out("GetInString -rule",number);
	if (number=="8" || number=="08") {rule=8;now=end;}
	else if (number=="10" ) {rule=10;now=end;}
	else if (number=="16" ) {rule=16;now=end;}
	else return "Error";
	return answer;
}
//From <TRY-C>

bool qustion(string q,char _true,char _false)
{
	again:
	cout<<q;
	printf (": (%c/%c)",_true,_false);
	char answer;
	cin>>answer;
	if (answer==_true)
	{
		return 1;
	}
	if (answer==_false)
	{
		return 0;
	}
	printf ("Error!!\n");
	printf ("Please put in your order again!!\n");
	goto again;
}

//From TYR-D
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
string ORDER1="He_loves_ZY.You_do_not_know!";
string ORDER2="His_best_friends_is_his_roommates!";

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
	}
	in.close();
}

void newuser ()
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
	if (order==ORDER2) 
		np.level="ClassMates";
	if (order==ORDER1)
		np.level="GirlFriend";
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
			return 1;
		}
		if (x.password!=LXB.password)
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

//From TRY-D

//From TRY-E
void wait(int ms)
{
	clock_t a;
	while (clock()-a<ms);
}
//From TRY-E

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

string LtoN(string input_C)
{
//	out("main-A",0);

//	out("main-B",input_C);
	string output="";
	int rule;
	int lastrule=0;
	for (now=0;now<input_C.length();now++)
	{
		if (input_C[now]=='[')
		{
			if (now!=0 && input_C[now-1]!=')') output+="EEE";
			input_s=GetInString(now,rule);
			if (input_s=="Error") {output="Error";break;}
			Chage1(rule);
			out ("main [for] now",now);
			out ("main rule",rule);
			out ("main lastrule",lastrule);
			if (rule!=lastrule)
			{
				if (rule==8) output+="DDD";
				if (rule==10)output+="CCC";
				if (rule==16)output+="FFF";
			}
			output+=output_s;
		}
		else 
		{
			if (now==0 || input_C[now-1]==')') output+="EEE";
			output+=input_C[now];
		}
	}
	if (input_C[input_C.length()-1]!=')') output+="EEE";
//	out("main-C",output);
	
	return output;
}

int Rand (int start,int end)// [a,b]
{
	srand( (unsigned int) ( clock() ) );
	return rand()%(end-start)+start;
}

string choose_a_string(string s,int start,int len)
{
//										out ("\n\nchoose_a_string","go");
	string output="";
//										out ("choose_a_string output",output);
	for (int i=0;i<len;i++)
	{
		output+=s[i+start];
//										out ("choose_a_string i",i+start);
//										out ("choose_a_string s[i]",s[i+start]);
//										out ("choose_a_string output",output);
	}
	return output;
}

string zidong(string input)
{
//										out ("\n\nzidong","go");
	int len =input.length();
	string output="";
	int zidong_now=0;
	int lastrule=0;
	while (zidong_now<len)
	{
		int nowlen;
//										out ("zidong len (of input)",len);
//										out ("zidong zidong_now",zidong_now);
//										out ("zidong len-now",len-zidong_now);
		if (len-zidong_now<5) nowlen=len-zidong_now;
		else
		{
			nowlen=Rand(400,900)/100;
//			if (nowlen+zidong_now>len) nowlen=len-now;
		}
//										out ("zidong nowlen",nowlen);
		
		string input1=choose_a_string(input,zidong_now,nowlen);
		again:
		int rule=Rand(0,1000);
		if		(0<=rule && rule<=450) rule=8;
		else if (451<=rule && rule<=600) rule=10;
		else if	(601<=rule && rule<=1000) rule=16;
		else goto again;
										cout<<endl<<endl;
//										out ("zidong [while] nowlen",nowlen);
//										out ("zidong [while] zidong_now",zidong_now);
										out ("zidong [while] rule",rule);
										out ("zidong [while] -input",input1);
		input_s=input1;
		if (rule != lastrule)
		{
			if (rule==8 ) output+="DDD";
			if (rule==10) output+="CCC";
			if (rule==16) output+="FFF";
		}
		output+=Chage1(rule);
										out ("zidong [while] output",output);
		zidong_now=zidong_now+nowlen;
	}
	out ("zidong <while> over!","zidong over!"); 
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
	cout<<"\nNote: do not enter spaces, use underscores instead\n";
	cout<<"Please input!\n";
	cin>>input;
	cout<<"\n\n\n"<<zidong(input);
	cout<<"\n\n\n"<<LtoN(input);
	
	cout<<"\n\nAre you want to run again? (y/n):";
	char answer_main_c;
	cin>>answer_main_c;
	if (answer_main_c=='y') goto go_on;
	return 0;
}
/*
A:  aa[bb](08)cc[dd](10)[ee](16)ff[gg](10)[hh](10)ii
	EEEaaEEEDDDs02s02EEEccEEECCCs04s04FFFs16s16EEEffEEECCCs07s07CCCs08s08EEEiiEEE
B:	lxblxblxblxblxb_zyzyzyzyzy
	 
C:	AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz
	
*/
