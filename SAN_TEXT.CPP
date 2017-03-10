#include<fstream.h>
#include<ctype.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
void create()
{
	ofstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		getch();
		exit(0);
	}
	char ch,ans;
	do
	{
		cout<<"Enter the character";
		ch=getch();
		mf.put(ch);
		cout<<'\n'<<"Want to continue?"<<'\n';
		cin>>ans;
	}
	while(ans=='Y' || ans=='y');
	mf.close();
	getch();
}
void display_file()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"Not created";
		getch();
		exit(0);
	}
	char ch;
	cout<<"Displaying contents"<<'\n';
	mf.get(ch);
	while(mf)
	{
		cout<<ch<<'\n';
		mf.get(ch);
	}
	mf.close();
	getch();
}
void counter()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		exit(0);
	}
	int cd=0,cb=0,ca=0;
	char ch;
	mf.get(ch);
	while(mf)
	{
		if(isdigit(ch))
		cd++;
		else if(ch>='A'&& ch<='Z'||ch>='a'&& ch<='z')
		ca++;
		else if(ch==' ')
		cb++;
		mf.get(ch);
	}
	cout<<"number of alphabets="<<ca<<'\n';
	cout<<"number of digits="<<cd<<'\n';
	cout<<"number of blanks="<<cb;
	mf.close();
	getch();
}

void word_sentence()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		exit(0);
		getch();
	}
	int word=0,sentence=0;
	char ch;
	mf.get(ch);
	while (mf)
	{
		if(ch=='.')
		{
			sentence++;
			word++;
		}
		else if (ch==','||ch==' '||ch==';')
		word++;
		mf.get(ch);
	}
	cout<<"number of words="<<word<<'\n';
	cout<<"number of sentence="<<sentence;
	mf.close();
	getch();
}
void occurence()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		exit(0);
		getch();
	}
	char a,ch;
	int c=0;
	cout<<"enter the character to count its occurence ";
	cin>>a;
	mf.get(ch);
	while (mf)
	{
		if (ch==a)
		c++;
		mf.get(ch);
	}
	mf.close();
	cout<<"number of occurences of "<<a<<" is "<<c;
	getch();
}
void display_newfile()
{
	ifstream nf;
	nf.open("def.txt");
	if(!nf)
	{
		cout<<"Stream not created ";
		exit(0);
	}
	char ch;
	nf.get(ch);
	while(nf)
	{
		cout<<ch;
		nf.get(ch);
	}
	nf.close();
	getch();
}
void blanks()
{
	clrscr();
	ifstream mf("abc.txt");
	if(!mf)
	{
		cout<<"stream not created";
		exit(0);
		getch();
	}
	ofstream nf;
	nf.open("def.txt");
	char ch;
	mf.get(ch);
	while(mf)
	{
		if(ch==' ')
		{
			{
				while(ch==' ')
				mf.get(ch);
			}
		nf<<' ';
		}
		nf<<ch;
		mf.get(ch);
       }
}

void main()
{
	int n;
	do{
	clrscr();
	cout<<'\t'<<'\t'<<"------MENU------"<<'\n'<<'\n';
	cout<<"create a file.........0"<<'\n'<<'\n';
	cout<<"display the file.........1"<<'\n'<<'\n';
	cout<<"count all the alphabets,digits and blanks...2"<<'\n'<<'\n';
	cout<<"count the number of words and sentences...3"<<'\n'<<'\n';
	cout<<"count the occurences of a character...4"<<'\n'<<'\n';
	cout<<"consecutive blanks should be replaced by single blank..5"<<'\n'<<'\n';
	cout<<"Exit..................6"<<'\n'<<'\n';
	cout<<"enter your choice";
	cin>>n;
	switch(n)
	{
		case 0:{
				create();
			}
			break;
		case 1:{
				display_file();
			}
			break;
		case 2:{
				counter();
			}
			break;
		case 3:{
				word_sentence();
			}
			break;
		case 4:{
				occurence();
			}
			break;
		case 5:{
				blanks();
				display_newfile();
			}
			break;
		case 6:{
				exit(0);
			}
			break;

		default:cout<<"wrong input";
	}
	  }
	while(n!=10);
  getch();
}
