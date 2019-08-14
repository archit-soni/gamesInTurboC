#include<iostream.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
void gameover(score)
{
cout<<endl<<"GAME OVER!"<<endl<<"Final score = "<<score;
getch();
exit(0);
}
int levels(score, m, s, x, r)
{
int a=0;
for(s; s<=m; s++)
	{
	cout<<"Guess the number"<<endl;
	cin>>r;
	if(x==r)
		{
		cout<<"Correct Guess"<<endl;
		score=score+10-(s*2);
		a=10-(s*2);
		break;
		}
	else if(r<x&&s<m)
		cout<<"Wrong guess... Try again with a greater number.."<<endl<<endl<<m-s<<" chances left"<<endl<<endl;
	else if(r>x&&s<m)
		cout<<"Wrong guess... Try again with a smaller number.."<<endl<<endl<<m-s<<" chances left"<<endl<<endl;
	else if(r!=x&&s==m)
		cout<<"Wrong guess... "<<endl<<endl;
	}
if(a==0)
gameover(score);
return score;
}
int first(int x, int m)        //first day of year/month
{
int day;
int x1, x2, x3;
x1=(x-1)/4;
x2=(x-1)/100;
x3=(x-1)/400;
day=(x+x1-x2+x3)%7;
if(m==2)
day=day+3;
else if(m==3)
day=day+3;
else if(m==4)
day=day+6;
else if(m==5)
day=day+1;
else if(m==6)
day=day+4;
else if(m==7)
day=day+6;
else if(m==8)
day=day+2;
else if(m==9)
day=day+5;
else if(m==10)
day=day;
else if(m==11)
day=day+3;
else if(m==12)
day=day+5;
return day%7;
}
int days(int m, int leap)
{
int x;
if(m==1)
x=31;
else if(m==2)
	{
	if(leap==1)
	x=29;
	else
	x=28;
	}
else if(m==3)
x=31;
else if(m==4)
x=30;
else if(m==5)
x=31;
else if(m==6)
x=30;
else if(m==7)
x=31;
else if(m==8)
x=31;
else if(m==9)
x=30;
else if(m==10)
x=31;
else if(m==11)
x=30;
else if(m==12)
x=31;
return x;
}
void print(int m)
{
if(m==1)
cout<<"January";
else if(m==2)
cout<<"February";
else if(m==3)
cout<<"March";
else if(m==4)
cout<<"April";
else if(m==5)
cout<<"May";
else if(m==6)
cout<<"June";
else if(m==7)
cout<<"July";
else if(m==8)
cout<<"August";
else if(m==9)
cout<<"September";
else if(m==10)
cout<<"October";
else if(m==11)
cout<<"November";
else if(m==12)
cout<<"December";
cout<<endl<<endl;
}
void choice(char n[3][3], int m)      //Assigns our number to a 2D list
{
if(m==1)
n[0][0]='X';
else if(m==2)
n[0][1]='X';
else if(m==3)
n[0][2]='X';
else if(m==4)
n[1][0]='X';
else if(m==5)
n[1][1]='X';
else if(m==6)
n[1][2]='X';
else if(m==7)
n[2][0]='X';
else if(m==8)
n[2][1]='X';
else if(m==9)
n[2][2]='X';
}
void choices(char n[3][3], int m)      //Assigns our number to a 2D list
{
if(m==1)
n[0][0]='O';
else if(m==2)
n[0][1]='O';
else if(m==3)
n[0][2]='O';
else if(m==4)
n[1][0]='O';
else if(m==5)
n[1][1]='O';
else if(m==6)
n[1][2]='O';
else if(m==7)
n[2][0]='O';
else if(m==8)
n[2][1]='O';
else if(m==9)
n[2][2]='O';
}
void fill(char n[3][3])                    //Fills 2D list as empty
{
n[0][0]=' ';
n[0][1]=' ';
n[0][2]=' ';
n[1][0]=' ';
n[1][1]=' ';
n[1][2]=' ';
n[2][0]=' ';
n[2][1]=' ';
n[2][2]=' ';
}
void display(char n[3][3])
{
cout<<n[0][0]<<'\t'<<"|"<<'\t'<<n[0][1]<<'\t'<<"|"<<'\t'<<n[0][2]<<endl<<"---------------------------------------"<<endl<<n[1][0]<<'\t'<<"|"<<'\t'<<n[1][1]<<'\t'<<"|"<<'\t'<<n[1][2]<<endl<<"---------------------------------------"<<endl<<n[2][0]<<'\t'<<"|"<<'\t'<<n[2][1]<<'\t'<<"|"<<'\t'<<n[2][2]<<endl;
}
void comp(char n[3][3], int r[], int m)                //Computer moves
{
two:
srand(time(0));
int x=rand()%9;
r[m]=x;
for(int i=0; i<m; i++)
	{
	if(x==r[i]||x==0)
	goto two;
	}
if(x==1)
n[0][0]='O';
else if(x==2)
n[0][1]='O';
else if(x==3)
n[0][2]='O';
else if(x==4)
n[1][0]='O';
else if(x==5)
n[1][1]='O';
else if(x==6)
n[1][2]='O';
else if(x==7)
n[2][0]='O';
else if(x==8)
n[2][1]='O';
else if(x==9)
n[2][2]='O';
}
void victory(char n[3][3])                        //Result
{
if(n[0][0]==n[0][1]&&n[0][0]==n[0][2]&&n[0][0]=='X')
cout<<"X Wins!";
else if(n[0][0]==n[0][1]&&n[0][0]==n[0][2]&&n[0][0]=='O')
cout<<"O Wins!";
else if(n[1][0]==n[1][1]&&n[0][0]==n[1][2]&&n[1][0]=='X')
cout<<"X Wins!";
else if(n[1][0]==n[1][1]&&n[0][0]==n[1][2]&&n[1][0]=='O')
cout<<"O Wins!";
else if(n[2][0]==n[2][1]&&n[2][0]==n[2][2]&&n[2][0]=='X')
cout<<"X Wins!";
else if(n[2][0]==n[2][1]&&n[2][0]==n[2][2]&&n[2][0]=='O')
cout<<"O Wins!";
else if(n[0][0]==n[1][0]&&n[0][0]==n[2][0]&&n[0][0]=='X')
cout<<"X Wins!";
else if(n[0][0]==n[1][0]&&n[0][0]==n[2][0]&&n[0][0]=='O')
cout<<"O Wins!";
else if(n[0][1]==n[1][1]&&n[0][0]==n[2][1]&&n[0][1]=='X')
cout<<"X Wins!";
else if(n[0][1]==n[1][1]&&n[0][1]==n[2][1]&&n[0][1]=='O')
cout<<"O Wins!";
else if(n[0][2]==n[1][2]&&n[0][2]==n[2][2]&&n[0][2]=='X')
cout<<"X Wins!";
else if(n[0][2]==n[1][2]&&n[0][2]==n[2][2]&&n[0][2]=='O')
cout<<"O Wins!";
else if(n[0][0]==n[1][1]&&n[0][0]==n[2][2]&&n[0][0]=='X')
cout<<"X Wins!";
else if(n[0][0]==n[1][1]&&n[0][0]==n[2][2]&&n[0][0]=='O')
cout<<"O Wins!";
else if(n[0][2]==n[1][1]&&n[0][2]==n[2][0]&&n[0][2]=='X')
cout<<"X Wins!";
else if(n[0][2]==n[1][1]&&n[0][2]==n[2][0]&&n[0][2]=='O')
cout<<"O Wins!";
else
cout<<"Draw!";
}
int snake(int l)
{
if(l==81)
	{
	cout<<"Snake!"<<endl;
	l=41;
	}
if(l==98)
	{
	cout<<"Snake!"<<endl;
	l=56;
	}
if(l==54)
	{
	cout<<"Snake!"<<endl;
	l=17;
	}
return l;
}
int ladder(int l)
{
if(l==29)
	{
	cout<<"Ladder!"<<endl;
	l=79;
	}
if(l==25)
	{
	cout<<"Ladder!"<<endl;
	l=79;
	}
if(l==4)
	{
	cout<<"Ladder!"<<endl;
	l=9;
	}
if(l==45)
	{
	cout<<"Ladder!"<<endl;
	l=91;
	}
return l;
}

void main()
{
clrscr();
int m;
cout<<"Enter choice "<<endl<<"1. Snakes and Ladders"<<endl<<"2. Tic Tac Toe"<<endl<<"3. Calendar"<<endl<<"4. Guess The Number"<<endl<<"5. High & Low"<<endl;
cin>>m;
switch(m)
	{
	case 1:
	{
int pl1=0, pl2=0;
char n[10][10], p1[30], p2[30];
clrscr();
cout<<"Enter Player 1's Name - ";
cin>>p1;
cout<<"Enter Player 2's Name - ";
cin>>p2;
clrscr();
one:
cout<<'\t'<<'\t'<<'\t'<<"SNAKES AND LADDERS!!"<<endl<<endl;
cout<<"100"<<'\t'<<"99"<<'\t'<<"\\S\\"<<'\t'<<"97"<<'\t'<<"96"<<'\t'<<"95"<<'\t'<<"94"<<'\t'<<"93"<<'\t'<<"92"<<'\t'<<"/R/"<<endl;
cout<<"90"<<'\t'<<"89"<<'\t'<<"88"<<'\t'<<"\\N\\"<<'\t'<<"86"<<'\t'<<"85"<<'\t'<<"84"<<'\t'<<"83"<<'\t'<<"/E/"<<'\t'<<"|S|"<<endl;
cout<<"80"<<'\t'<<"\\R\\"<<'\t'<<"78"<<'\t'<<"\\A\\"<<'\t'<<"76"<<'\t'<<"75"<<'\t'<<"74"<<'\t'<<"/D/"<<'\t'<<"72"<<'\t'<<"|N|"<<endl;
cout<<"70"<<'\t'<<"|E|"<<'\t'<<"\\E\\"<<'\t'<<"67"<<'\t'<<"\\K\\"<<'\t'<<"65"<<'\t'<<"/D/"<<'\t'<<"63"<<'\t'<<"62"<<'\t'<<"|A|"<<endl;
cout<<"60"<<'\t'<<"|D|"<<'\t'<<"58"<<'\t'<<"\\D\\"<<'\t'<<"\\E\\"<<'\t'<<"/A/"<<'\t'<<"/E/"<<'\t'<<"53"<<'\t'<<"52"<<'\t'<<"|K|"<<endl;
cout<<"50"<<'\t'<<"|D|"<<'\t'<<"48"<<'\t'<<"47"<<'\t'<<"\\D\\"<<'\t'<<"/L/"<<'\t'<<"/K/"<<'\t'<<"43"<<'\t'<<"42"<<'\t'<<"|E|"<<endl;
cout<<"40"<<'\t'<<"|A|"<<'\t'<<"38"<<'\t'<<"37"<<'\t'<<"36"<<'\t'<<"\\A\\"<<'\t'<<"34"<<'\t'<<"33"<<'\t'<<"32"<<'\t'<<"31"<<endl;
cout<<"30"<<'\t'<<"|L|"<<'\t'<<"28"<<'\t'<<"27"<<'\t'<<"/N/"<<'\t'<<"\\L\\"<<'\t'<<"24"<<'\t'<<"23"<<'\t'<<"22"<<'\t'<<"21"<<endl;
cout<<"20"<<'\t'<<"19"<<'\t'<<"18"<<'\t'<<"/S/"<<'\t'<<"16"<<'\t'<<"15"<<'\t'<<"14"<<'\t'<<"13"<<'\t'<<"12"<<'\t'<<"11"<<endl;
cout<<"10"<<'\t'<<"R"<<'\t'<<"E"<<'\t'<<"D"<<'\t'<<"D"<<'\t'<<"A"<<'\t'<<"L"<<'\t'<<"3"<<'\t'<<"2"<<'\t'<<"1"<<endl<<endl;
cout<<p1<<" "<<"Press a key to roll dice!"<<endl;
getch();
el:
srand(time(0));
int x=rand()%6;
if(x==0)
goto el;
cout<<x<<endl;
pl1=pl1+x;
		if(pl1>100)
		pl1=pl1-x;
		if(pl1==98||pl1==54||pl1==81)
		pl1=snake(pl1);
		if(pl1==4||pl1==29||pl1==25||pl1==45)
		pl1=ladder(pl1);
		cout<<"Previous position of "<<p1<<" - "<<pl1-x<<endl;
		cout<<"New Position of "<<p1<<" - "<<pl1<<endl;
		cout<<p2<<" "<<"Press a key to roll dice!"<<endl;
		getch();
		le:
		srand(time(0));
		int y=rand()%6;
		if(y==0)
		goto le;
		pl2=pl2+y;
		if(pl2>100)
		pl2=pl2-y;
		if(pl2==98||pl2==54||pl2==81)
		pl2=snake(pl2);
		if(pl2==4||pl2==29||pl2==25||pl2==45)
		pl2=ladder(pl2);
		cout<<y<<endl;
		cout<<"Previous Position of "<<p2<<"  - "<<pl2-x<<endl;
		cout<<"New Position of "<<p2<<"  - "<<pl2<<endl;
		getch();
		clrscr();
		if(pl1<100&&pl2<100)
		goto one;
		if(pl1==100)
		cout<<p1<<" WON!";
		else
		cout<<p2<<" WON!";
		getch();
	break;
	case 2:
int q;
clrscr();
cout<<'\t'<<'\t'<<'\t'<<"TIC-TAC-TOE!!"<<endl<<endl;
char na[3][3];
int m=0, r[10];
cout<<"Enter choice"<<endl<<"1. vs Computer"<<endl<<"2. Multiplayer"<<endl;
cin>>q;
	fill(na);
	clrscr();
	cout<<'\t'<<'\t'<<'\t'<<"TIC-TAC-TOE!!"<<endl<<endl;
	cout<<"1"<<'\t'<<"2"<<'\t'<<"3"<<endl<<"4"<<'\t'<<"5"<<'\t'<<"6"<<endl<<"7"<<'\t'<<"8"<<'\t'<<"9"<<endl<<endl;
	if(q==1)
	{
	ones:
	cout<<"Enter the position where you want to enter X"<<endl;
	cin>>r[m];
	choice(na, r[m]);
	for(int i=0; i<m; i++)
		{
		if(r[m]==r[i])
			{
			cout<<"Already occupied"<<endl;
			goto ones;
			}
		}
	cout<<endl;
	display(na);
	cout<<endl;
	m++;
	comp(na, r, m);
	m++;
	cout<<"After computer played"<<endl;
	cout<<endl;
	display(na);
	cout<<endl;
	if(m<8)
	goto ones;
	cout<<"Enter the position where you want to enter X"<<endl;
	cin>>r[m];
	choice(na, r[m]);
	display(na);
	cout<<"Game over"<<endl;
	victory(na);
	getch();
	}
else
	{
	fill(na);
	on:
	cout<<"Enter the position where you want to enter X"<<endl;
	cin>>r[m];
	choice(na, r[m]);
	cout<<endl;
	display(na);
	cout<<endl;
	m++;
	cout<<"Enter the position where you want to enter O"<<endl;
	cin>>r[m];
	choices(na, r[m]);
	cout<<endl;
	display(na);
	cout<<endl;
	m++;
	if(m<8)
	goto on;
	cout<<"Enter the position where you want to enter X"<<endl;
	cin>>r[m];
	choice(na, r[m]);
	cout<<endl;
	display(na);
	cout<<endl;
	cout<<"Game over"<<endl;
	victory(na);
	getch();
	}
}
	getch();
	break;
	case 3:
clrscr();
int year, leap, mn;
cout<<"Enter year"<<endl;
cin>>year;
if(year%4==0)
leap=1;
cout<<"Month for which you want the Calendar (in number)"<<endl;
cin>>mn;
clrscr();
cout<<'\t'<<'\t'<<'\t'<<year<<endl<<endl;
int l=first(year, mn);	  //first day of year
if(leap==1&&mn>2)
l=(l+1)%7;
int r=days(mn, leap);           //days in a month
print(mn);
cout<<"S"<<'\t'<<"M"<<'\t'<<"T"<<'\t'<<"W"<<'\t'<<"T"<<'\t'<<"F"<<'\t'<<"S"<<endl<<endl;
for(int j=1; j<=l; j++)
	{
	cout<<'\t';
	}
for(int i=(1+l); i<=(l+r); i++)
	{
	cout<<(i-l)<<'\t';
	if(i%7==0)
	cout<<endl;
	}
getch();


	getch();
	break;
	case 4:
int x, z, y=1, score=0, s=0;
srand(time(0));
x=rand()%10;
clrscr();
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"Rules :-"<<endl;
cout<<"There will be 5 levels."<<endl<<"Level 1 - A random number between 0-10"<<endl<<"You have 2 chances"<<endl<<endl;
cout<<"Level 2 - A random number between 0-20"<<endl<<"You will have 3 chances"<<endl<<endl;
cout<<"Level 3 - A random number between 0-30"<<endl<<"You will have 4 chances"<<endl<<endl;
cout<<"Level 4 - A random number between 0-40"<<endl<<"You will have 5 chances"<<endl<<endl;
cout<<"Level 5 - A random number between 0-50"<<endl<<"You will have 6 chances"<<endl<<endl;
getch();
clrscr();
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"Rules :-"<<endl;
cout<<"10 Points for guessing in 1st attempt"<<endl<<"8 Points for guessing in 2nd attempt"<<endl<<"6 Points for guessing in 3rd attempt"<<endl<<"4 Points for guessing in 4th attempt"<<endl<<"2 Points for guessing in 5th attempt"<<endl<<"0 Points for guessing after 5th attempt"<<endl;
getch();
clrscr();
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"LEVEL 1"<<endl<<endl;
score=levels(score, y, s, x, z);
cout<<"Present score = "<<score;
getch();
clrscr();
y++;
s=0;
x=rand()%20;
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"LEVEL 2"<<endl<<endl;
score=levels(score, y, s, x, z);
cout<<"Present score = "<<score;
getch();
clrscr();
y++;
s=0;
x=rand()%30;
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"LEVEL 3"<<endl<<endl;
score=levels(score, y, s, x, z);
cout<<"Present score = "<<score;
getch();
clrscr();
y++;
s=0;
x=rand()%40;
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"LEVEL 4"<<endl<<endl;
score=levels(score, y, s, x, z);
cout<<"Present score = "<<score;
getch();
clrscr();
y++;
s=0;
x=rand()%50;
cout<<'\t'<<'\t'<<'\t'<<"GUESS THE NUMBER GAME!!"<<endl<<endl<<"LEVEL 5"<<endl<<endl;
score=levels(score, y, s, x, z);
cout<<"Present score = "<<score;
gameover(score);
getch();

	getch();
	break;
	case 5:
	clrscr();
	int hl, hll, ll;
	char ch;
	srand(time(0));
	hl=rand()%100;
	for(int qe=1; ll!=0; qe++)
		{
		hll=rand()%100;
		cout<<hl;
		cout<<endl<<"Guess whether next number will be Higher or Lower? (h/l)"<<endl;
		cin>>ch;
		if((ch=='h'&&hll>hl)||(ch=='l'&&hll<hl))
			{
			cout<<"Correct!"<<endl;
			hl=hll;
			}
		else
			{
			cout<<hll;
			ll=0;
			}
		}
	gameover(qe);
	getch();
	break;
	}
}
