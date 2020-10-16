//项目名:
//编号:密码规则III 二和一最终程序 
/*
 Special
*/
//制作人:林暄博

#include<bits/stdc++.h>
using namespace std;

const bool DEBUGING=1;

template <class T>
void out(string s,T ans){
	if (DEBUGING==0) {return;}
	cout<<endl<<"example # "<<s<<" : "<<ans;
}

//-------------------------------LtoN-----------------------------------------------
//-------------------------------LtoN-----------------------------------------------
//-------------------------------LtoN-----------------------------------------------

//From <TRY-A>
//						 AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz
const string rules_08="000102030405060710111213141516172021222324252627303132";
const string rules_10="000102030405060708091011121314151617181920212223242526";
const string rules_16="001A191817161514131211100F0E0D0C0B0A090807060504030201";

string answer="";

bool yih(bool a,bool b)//异或
{
	if (a==0 && b==1) return 1;
	if (a==1 && b==0) return 0;
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


void choose_08(char c)
{
	int n=c-'A'+1;
	answer+=rules_08[2*n];
//	out("choose_08 - 1",answer);
	answer+=rules_08[2*n+1];
//	out("choose_08 - 2",answer);
}

void choose_10(char c)
{
	int n=c-'A'+1;
	answer+=rules_10[2*n];
//	out("choose_10 - 1",answer);
	answer+=rules_10[2*n+1];
//	out("choose_10 - 2",answer);
}

void choose_16(char c)
{
	int n=c-'A'+1;
	answer+=rules_16[2*n];
//	out("choose_16 - 1",answer);
	answer+=rules_16[2*n+1];
//	out("choose_16 - 2",answer);
}

void choose_rule(char c,int rule)
{
	
	if ( !( ('a'<=c && c<='z') || ('A'<=c && c<='Z') ) )
	{
		answer+=c;
		return ;
	}
	
	if ('a'<=c && c<='z')
	{
		c=c-'a'+'A';
		answer+='s';
//		out("choose_rule a->A c",c);
	}
	else 
	{
		answer+='b'; 
	}
//	out("choose_rule a->A c",c);
	
	if (rule==8) {choose_08(c);return;}
	if (rule==10){choose_10(c);return;}
	if (rule==16){choose_16(c);return;}
}

//From <TRY-A>

//From <TRY-B>
string input_s;
string output_s;

char choose_litter(int i) {return input_s[i];}

string Chage1(int rule)
{
//										out ("Chage1","go");
//										out ("Chage1 rule",rule);
	output_s="";
	char lastchar='#';
	for (int i=0;i<input_s.length();i++){
		char nowchar=choose_litter (i);
//										out ("Chage1 [for] nowchar ",nowchar);
//										out ("Chage1 [for] lastchar",lastchar);
		if (i!=0 && yih(Isnumber(lastchar),Isnumber(nowchar) ) )
		{
			output_s+="BAB";
		}
		if (Isnumber(nowchar)==1){
			
			output_s+=nowchar;
			lastchar=nowchar;
			continue;
		}
//										out ("Chage1 [for] rule",rule);
		choose_rule(nowchar,rule);
//										out ("Chage1 [for] answer",answer);
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
	bool b=read(go,start,end,'[',']');
//										out("GetInString -b",b);
	if (b==0) return "Error";
//										out("GetInString -start (of '[')",start);
//										out("GetInString -end (of ']')",end);
	string answer="";
	for (int i=start+1;i<end;i++)
	{
		answer+=input_C[i];
	}
//										out("GetInString -answer",answer);
	
	string number="";
	b=read(end,start,end,'(',')');
//										out("GetInString -b",b);
	if (b==0) return "Error";
//										out("GetInString -start",start);
//										out("GetInString -end",end);
	for (int i=start+1;i<end;i++)
	{
		number+=input_C[i];
	}
//										out("GetInString -rule",number);
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


string LtoN(string input_C)
{
//										out("main-A",0);

//										out("main-B",input_C);
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
//										out("main-C",output);
	
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
//										cout<<endl<<endl;
//										out ("zidong [while] nowlen",nowlen);
//										out ("zidong [while] zidong_now",zidong_now);
//										out ("zidong [while] rule",rule);
//										out ("zidong [while] -input",input1);
		input_s=input1;
		if (rule != lastrule)
		{
			if (rule==8 ) output+="DDD";
			if (rule==10) output+="CCC";
			if (rule==16) output+="FFF";
		}
		output+=Chage1(rule);
//										out ("zidong [while] output",output);
		zidong_now=zidong_now+nowlen;
	}
//										out ("zidong <while> over!","zidong over!"); 
	return output;
}


//-------------------------------LtoN-----------------------------------------------
//-------------------------------LtoN-----------------------------------------------
//-------------------------------LtoN-----------------------------------------------



//-------------------------------NtoL-----------------------------------------------
//-------------------------------NtoL-----------------------------------------------
//-------------------------------NtoL-----------------------------------------------

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

//From TRY-a

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

string NtoL(string input)
{
	string output="";
	int len=input.length();
	bool fany=1;
	int rule=0;
	for (int i=0;i<len;i++)
	{
		if ( !( ('a'<=input[i] && input[i]<='z') || 
				('A'<=input[i] && input[i]<='Z') ||
				('0'<=input[i] && input[i]<='9') ) )
		{
			output+=input[i];
			continue;
		}
		char now[3];
		input_b=input;
		choose(i,now);
//										out ("main for-i ",i);
//										out ("main now[3]",now);
		if (same (now,"EEE"))
		{
//										out ("main found a EEE",'\n');
			fany=!fany;
			i+=2;
			continue;
		}
		if (same (now,"CCC")) {
			rule=10;
										/*out("main found a CCC",'\n');*/
			i+=2;
			continue;
		}
		if (same (now,"DDD")) {
			rule=8 ;
										/*out("main found a DDD",'\n');*/
			i+=2;
			continue;
		}
		if (same (now,"FFF")) {
			rule=16;
										/*out("main found a FFF",'\n');*/
			i+=2;
			continue;
		}
		if (fany)
		{
			if (same (now,"000"))
			{
				output+=' ';
//										out("main found a 000",' ');
				i+=2;
				continue;
			}
			char c;
			c=chage(now,rule);
//										out("main chage-c",c);
			if (c=='#') {
				output="Error";
										/*out("main: chage Error",'\n');*/
				break;
				}
			output+=c;
//										out("main output+=c",output);
			i+=2;
		}
		else 
		{
			output += input[i];
		}
	}
//										out("main: [for] break",'\n');
	return output;
}

//-------------------------------NtoL-----------------------------------------------
//-------------------------------NtoL-----------------------------------------------
//-------------------------------NtoL-----------------------------------------------



//-------------------------------password-------------------------------------------- 
//-------------------------------password-------------------------------------------- 
//-------------------------------password-------------------------------------------- 
//From TYR-D
struct person
{
	string user_name;
	string password;
	string level;
	int number_of_level;
};

#include <fstream>
#include <iostream>

person LXB;
person X;
string ORDER1="He_loves_ZY.You_do_not_know!";
string ORDER2="His_best_friends_is_his_roommates!";

int number_of_user;
person p[20];


int now_person_number;

//From TRY-D

//From TRY-E
void wait(int ms)
{
	clock_t a;
	while (clock()-a<ms);
}
//From TRY-E

#include <fstream>
#include <iostream>

void load()
{
	LXB.user_name="L666no6";
	LXB.password="lxb1224022625";
	LXB.level="administrator";
	LXB.number_of_level=4;
	X.user_name="X";
	X.password="He_dislike_anyone_knows_his_things";
	X.level="special";
	X.number_of_level=3;
	
	ifstream in("Users imformation.txt");
 	in>>number_of_user;
	
	for (int i=0;i<number_of_user;i++)
	{
		in>>p[i].user_name;
		in>>p[i].password;
		in>>p[i].level>>p[i].number_of_level;
		p[i].user_name=NtoL(p[i].user_name );
		p[i].password=NtoL(p[i].password );
		p[i].level =NtoL(p[i].level );
										out ("main input users user_name",p[i].user_name );
										out ("main input users password",p[i].password );
										out ("main input users level",p[i].level );
										out ("main input users number_of_lever",p[i].number_of_level);
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
	cout<<"Password: ";
	cin>>s;
	cout<<"Input again: ";
	cin>>s1;
	if (s==s1) np.password=s;
	else 
	{
		cout<<"Error"<<endl;
		goto password;
	}
	np.level="user";
	np.number_of_level=0;
	cout<<"Please input administrator's order!\n";
	string order;
	cin>>order;
	if (order==ORDER2) 
		np.level="ClassMates";
		np.number_of_level=1;
	if (order==ORDER1)
		np.level="GirlFriend";
		np.number_of_level=2;
	ofstream out("Users imformation.txt");
	out<<number_of_user+1<<endl;
	for (int i=0;i<number_of_user;i++)
	{
		out<<zidong(p[i].user_name) <<' '<<
			 zidong(p[i].password)  <<' '<<
			 zidong(p[i].level)	  <<' '<<
			 p[i].number_of_level<<endl;
	}
	number_of_user++;
	out<<zidong(np.user_name)<<' '<<
		 zidong(np.password) <<' '<<
		 zidong(np.level)	   <<' '<<
		 np.number_of_level;
	out.close();
	cout<<"Please close!";
}


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

//-------------------------------password-------------------------------------------- 
//-------------------------------password-------------------------------------------- 
//-------------------------------password-------------------------------------------- 

int main()
{
	//---------------------------go in----------------------------------------
	load();
	bool b=0;
	char LAJI[1000];
	
	go_in:
	
	for (int i=0;i<3 && b==0;i++)
	{
		b=password();
	}
	if (b==0)
	{
		cout<<"Locked!!";
		while (1);
	}
	
	string user_name;
	string user_lever;
	int user_number;
	if (now_person_number==-1) 
	{
		user_name="L666no6";
		user_lever="administrator";
		user_number=4;
	}
	else if (now_person_number==-2)
	{
		user_name="X";
		user_lever="special";
		user_number=3;
	}
	else
	{
		user_name=p[now_person_number].user_name;
		user_lever=p[now_person_number].level;
		user_number=p[now_person_number].number_of_level;
	}
	
	wait(1000);
	
	go_on:
	
	system("cls");
	
	printf ("Welcome to the offline encryption and decryption program!\n");
	printf ("You name:  ");cout<<user_name<<endl;
	printf ("You lever: ");cout<<user_lever<<endl;
	printf ("\nyou can let me do...\n\n");
	
	if (user_number>=0) printf ("0.Exit\n");
	if (user_number>=0) printf ("1.encryption text by input\n");
	if (user_number>=0) printf ("2.encryption text by Input.txt\n");
	if (user_number>=1) printf ("3.Automatic encryption text by input\n");
	if (user_number>=1) printf ("4.Decryption text by input\n");
	if (user_number>=1) printf ("5.Decryption text by input.txt\n");
	if (user_number>=3) printf ("6.New User\n");
	if (user_number>=3) printf ("7.Delete a User\n");
	if (user_number>=4) printf ("8.Create a new encryption rule\n");
	if (user_number>=4) printf ("9.Delete an encryption rule\n");
	
	int choose_number;
	while (1)
	{
		printf ("\nPlease input your choose : ");
		scanf("%d",&choose_number);
		
		if (choose_number<0)				   {printf ("Error!");continue;}
		if (user_number<=4 && choose_number>9) {printf ("Error!");continue;}
		if (user_number<=3 && choose_number>7) {printf ("Error!");continue;}
		if (user_number<=2 && choose_number>5) {printf ("Error!");continue;}
		if (user_number<=1 && choose_number>5) {printf ("Error!");continue;}
		if (user_number<=0 && choose_number>2) {printf ("Error!");continue;}
		
		break;
	}
	if (choose_number==0)
	{
		system ("cls");
		goto go_in;
	}
	if (choose_number==1) {
		cin>>input_C;
										out ("main order1 input_C",input_C);
		cout<<LtoN(input_C);
	} 
	if (choose_number==2) {
		ifstream fin ("./Users/Administrator/Desktop/input.txt") ;
		ofstream fout("./Users/Administrator/Desktop/output.txt");
		fin>>input_C;
		fout<<LtoN(input_C);
		fout.close();
		fin.close();
	}
	if (choose_number==3){
		cin>>input_C;
		cout<<zidong(input_C);
	}
	if (choose_number==4) {
		cin>>input_C;
		cout<<NtoL(input_C);
	}
	if (choose_number==5) {
		ifstream fin ("./Users/Administrator/Desktop/input.txt") ;
		ofstream fout("./Users/Administrator/Desktop/output.txt");
		fin>>input_C;
		fout<<NtoL(input_C);
		fout.close();
		fin.close();
	}
	if (choose_number==6) {
		newuser();
	} 
	if (choose_number==7) {
		printf ("Sorry!\n");
	}
	if (choose_number==8) {
		printf ("Sorry!\n");
	} 
	if (choose_number==9) {
		printf ("Sorry!\n");
	}
	
	cout<<"\n\nAre you want to run again? (y/n):";
	char answer_main_c;
	cin>>answer_main_c;
	if (answer_main_c=='y') goto go_on;
	
	return 0;
}

