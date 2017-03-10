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
	char w[20];
	do
	{
		cout<<"Enter word "<<'\n';
		gets(w);
		mf<<w<<' ';
		cout<<"Want to write more words ? Y/N ";
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
		cout<<"Stream not created "; getch();
		exit(0);
	}
	char w[20];
	mf>>w;
	while(mf)
	{
		cout<<w<<' ';
		mf>>w;
	}
	mf.close();
	getch();
}
void me_my()
{
	clrscr();
	ifstream mf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	char word[25];
	int m=0;
	mf>>word;
	while(mf)
	{
		if((strcmpi(word,"ME")==0) || (strcmpi(word,"MY")==0))
		m++;
		mf>>word;
	}
	cout<<"Me or My appeared "<<m<<" times "<<'\n';
	mf.close();
	getch();
}

void this_these()
{
	clrscr();
	ifstream mf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	char word[25];
	int c1=0,c2=0;
	mf>>word;
	while(mf)
	{
		if((strcmpi(word,"THESE")==0))
		c1++;
		else if((strcmpi(word,"THIS")==0))
		c2++;
		mf>>word;
	}
	mf.close();
	cout<<"'This' appeared "<<c2<<" times "<<'\n';
	cout<<"'These' appeared "<<c1<<" times "<<'\n';
	getch();
}

void begin_a()
{
	clrscr();
	ifstream mf,cf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	ofstream nf;
	nf.open("B.txt");
	char w[25];
	int f=0;
	mf>>w;
	while(mf)
	{
		if(w[0]=='A'||w[0]=='a')
		{
			nf<<w<<' ';
			f=1;
		}
		mf>>w;
	}
	mf.close();
	nf.close();
	cf.open("B.txt");
	while(cf)
	{
		cf>>w;
		cout<<w<<'\n';
	}
	cf.close();
	if(f==0)
	cout<<"No such word found "<<'\n';
	else
	{
		cout<<"Copied "<<'\n';
		cout<<"New file: "<<'\n';
		getch();
	}
}


void begin_vowel()
{
	clrscr();
	ifstream mf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	ofstream nf;
	ifstream cf;
	nf.open("B.txt");
	char w[25];
	mf>>w;
	char ch;
	while(mf)
	{
		ch=toupper(w[0]);
		if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
			{
				nf<<w<<' ';
			}
		mf>>w;
	}
	mf.close();
	nf.close();
	cf.open("B.txt");
	while(cf)
	{
		cf>>w;
		cout<<w<<'\n';
	}
	cf.close();
	getch();
}


void words_i()
{
	clrscr();
	ifstream mf,cf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	ofstream nf;
	nf.open("B.txt");
	char w[25];
	mf>>w;
	while(mf)
	{
		for(int i=0;w[i]!='\0';i++)
		{
			if(w[i]=='i'||w[i]=='I')
			{
				nf<<w<<' ';
				break;
			}
		}
		mf>>w;
	}
	mf.close();
	nf.close();
	cf.open("B.txt");
	while(cf)
	{
		cf>>w;
		cout<<w<<'\n';
	}
	cf.close();
	getch();
}


void words_vowel()
{
	clrscr();
	ifstream mf,cf;
	mf.open("abc.txt");
	if(!mf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	ofstream nf;
	nf.open("B.txt");
	char w[25];
	char ch;
	mf>>w;
	while(mf)
	{
		for(int i=0;w[i]!='\0';i++)
		{
			ch=toupper(w[i]);
			if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')
			{
				nf<<w<<' ';
				break;
			}
		}
		mf>>w;
	}
	mf.close();
	nf.close();
	cf.open("B.txt");
	while(cf)
	{

		cf>>w;
		cout<<w<<'\n';
	}
	cf.close();
	getch();
}

void main()
{
	int n;
	do{
	clrscr();
	cout<<'\t'<<'\t'<<"--------MENU--------"<<'\n'<<'\n';
	cout<<"create a file.........0"<<'\n'<<'\n';
	cout<<"display the contents of the file.........1"<<'\n'<<'\n';
	cout<<"count the number of me n my in the file..2"<<'\n'<<'\n';
	cout<<"count the number of this n these in the file...3"<<'\n'<<'\n';
	cout<<"copy the words which begin with a or A...4"<<'\n'<<'\n';
	cout<<"copy those words which begin with vowel...5"<<'\n'<<'\n';
	cout<<"copy those words which contain i...6"<<'\n'<<'\n';
	cout<<"copy those words which contain vowel..7"<<'\n'<<'\n';
	cout<<"Exit..................8"<<'\n'<<'\n';
	cout<<"enter your choice";
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
				me_my();
				break;
			}
		case 3:{
				this_these();
				break;
			}
		case 4:{
				begin_a();
				break;
			}
		case 5:{
				begin_vowel();
				break;
			}
		case 6:{
				words_i();
				break;
			}
		case 7: {
				words_vowel();
				break;
			}
		case 8: {
				exit(0);
				break;
			}
		default:cout<<"wrong input";
	}
	  }
	while(n!=8);
  getch();
}