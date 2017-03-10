#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
void create()
{
	ofstream mf;
	char ans;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	char s[80];
	do
	{
		cout<<"Enter line"<<'\n';
		gets(s);
		mf<<s<<' ';
		mf.put('\n');
		cout<<"Want to write more? Y/N ";
		cin>>ans;
	}
	while(ans=='Y'||ans=='y');
	mf.close();
}

void display()
{
	clrscr();
	ifstream mf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	char s[80];
	mf.getline(s,80);
	while(mf)
	{
		cout<<s<<'\n';
		mf.getline(s,80);
	}
	mf.close();
	getch();
}
void no_lines()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		exit(0);
	}
	char s[80];
	int c=0;
	mf.getline(s,80);
	while(mf)
	{
		c++;
		mf.getline(s,80);
	}
	cout<<"number of lines= "<<c;
	mf.close();
	getch();
}
void beg_T()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		exit(0);
	}
	char s[80];
	mf.getline(s,80);
	while(mf)
	{
		if(s[0]=='T'||s[0]=='t')
		cout<<s<<'\n';
		mf.getline(s,80);
	}
	mf.close();
	getch();
}
void copy_vowel()
{
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	ofstream nf;
	ifstream cf;
	nf.open("B.txt");
	char s[25];
	char ch;
	mf.getline(s,80);
	while(mf)
	{
		ch=toupper(s[0]);
		if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
			{
			     nf<<s<<' ';
			     nf.put('\n');
			}
		mf.getline(s,80);
	}
	mf.close();
	nf.close();
	cf.open("B.txt");
	while(cf)
	{
		cf.getline(s,80);
		cout<<'\n'<<'\n'<<s<<'\n';
	}
	cf.close();
	getch();
}
void main()
{
	int n;
	do{
	clrscr();
	cout<<'\n'<<'\n';
	cout<<"create a file.........0"<<'\n'<<'\n';
	cout<<"display the contents of the file.........1"<<'\n'<<'\n';
	cout<<"count the number of lines..2"<<'\n'<<'\n';
	cout<<"print those lines which begin with T...3"<<'\n'<<'\n';
	cout<<"copy the lines which begin with vowel...4"<<'\n'<<'\n';
	cout<<"Exit..................5"<<'\n'<<'\n';
	cout<<"enter your choice      ";
	cin>>n;
	switch(n)
	{
		case 0:{
				create();
				break;
			}
		case 1:{
				display();
				break;
			}
		case 2:{
				no_lines();
				break;
			}
		case 3:{
				beg_T();
				break;
			}
		case 4:{
				copy_vowel();
				break;
			}
		case 5:{
				exit(0);
				break;
			}
		default:cout<<"wrong input";
	}
	  }
	while(n!=5);
  getch();
}