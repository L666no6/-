//项目名:
//编号:TRY-D-Password
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
	
	
	ifstream in("TRY-D.txt");
 	in>>number_of_user;
	
	for (int i=0;i<number_of_user;i++)
	{
		in>>p[i].user_name;
		in>>p[i].password;
		in>>p[i].level;
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
	ofstream out("TRY-D.txt");
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

void deleteP(name)//administrator,special
{
	
}

int main()
{
	load();
	password_again:
	bool b=password();
	if (b==0) goto password_again;
	
	return 0;
}

