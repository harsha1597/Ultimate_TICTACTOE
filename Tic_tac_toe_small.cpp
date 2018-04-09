#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define ARROW_UP    0x48
#define ARROW_LEFT  0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN  0x50
#define ARROW_NONE  0x00
#define ESC_KEY     0x1B


using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

class tic{

char xo[3][3];
int a,b;
//int flag; //for helping cursor movements , a for row,b for column
int y; //The colour element
HANDLE console;


public:

	tic()
	{
	    console = GetStdHandle(STD_OUTPUT_HANDLE);
	    //y=240;// 240 = white background, black foreground
		a=0;  //a and b for cursor
		b=0;
		for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                xo[i][j]='_';
            }
        }
		//xo={{'_','_','_'},{'_','_','_'},{'_','_','_'}};
       	//flag=0;

	}
	bool conjest(char c)
	{
	    if(c=='X'||c=='O')
        {
            if (xo[0][0]!='_'&&xo[0][1]!='_'&&xo[0][2]!= '_'&&xo[1][0]!='_'&&xo[1][1]!= '_'&&xo[1][2]!='_'&&xo[2][0]!='_'&&xo[2][1]!='_'&&xo[2][2]!='_')
		return true;
            else
        return false;
        }
        return false;
	}

	  void gotoxy(int x,int y)
    {
        COORD cord;
        cord.X=x;
        cord.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),cord);
    }
    int check(char c)    //return 1, game is over with result; -1, game in progress; 0, game is over, no result
{
	if (xo[0][0] == xo[0][1] && xo[0][1] == xo[0][2]&& xo[0][0]==c)
		return 1;
	else if (xo[1][0] == xo[1][1] && xo[1][1] == xo[1][2]&& xo[1][0]==c)
		return 1;
	else if (xo[2][0] == xo[2][1] && xo[2][1] == xo[2][2]&& xo[2][0]==c)
		return 1;
	else if (xo[0][0] == xo[1][0] && xo[1][0] == xo[2][0]&& xo[0][0]==c)
		return 1;
	else if (xo[0][1] == xo[1][1] && xo[1][1] == xo[2][1]&& xo[0][1]==c)
		return 1;
	else if (xo[0][2] == xo[1][2] && xo[1][2] == xo[2][2]&& xo[0][2]==c)
		return 1;
	else if (xo[0][0] == xo[1][1] && xo[1][1] == xo[2][2]&& xo[0][0]==c)
		return 1;
	else if (xo[0][2] == xo[1][1] && xo[1][1] == xo[2][0]&& xo[0][2]==c)
		return 1;
	else if (xo[0][0]!='_'&&xo[0][1]!='_'&&xo[0][2]!= '_'&&xo[1][0]!='_'&&xo[1][1]!= '_'&&xo[1][2]!='_'&&xo[2][0]!='_'&&xo[2][1]!='_'&&xo[2][2]!='_')
		return 0;
	else
		return -1;
}

int getnext()
{
    if(a==0&&b==0)
        return 0;
    if(a==0&&b==1)
        return 1;
    if(a==0&&b==2)
        return 2;
    if(a==1&&b==0)
        return 3;
    if(a==1&&b==1)
        return 4;
    if(a==1&&b==2)
        return 5;
    if(a==2&&b==0)
        return 6;
    if(a==2&&b==1)
        return 7;
    if(a==2&&b==2)
        return 8;

}
char resret(int n)
{
    int x,y;
    switch(n)
            {
                case 1 : x=y=0;
                    break;
                 case 2 : x=0; y=1;
                    break;
                 case 3 : x=0; y=2;
                    break;
                 case 4 : x=1; y=0;
                    break;
                 case 5 : x=1; y=1;
                    break;
                 case 6 : x=1; y=2;
                    break;
                 case 7 : x=2; y=0;
                    break;
                 case 8 : x=2; y=1;
                    break;
                 case 9 : x=y=2;
                    break;
            }
            return xo[x][y];
}
void resenter(char c,int n)
{
    int x,y,k;
    switch(n)
            {
                case 1 : x=y=0;
                    break;
                 case 2 : x=0; y=1;
                    break;
                 case 3 : x=0; y=2;
                    break;
                 case 4 : x=1; y=0;
                    break;
                 case 5 : x=1; y=1;
                    break;
                 case 6 : x=1; y=2;
                    break;
                 case 7 : x=2; y=0;
                    break;
                 case 8 : x=2; y=1;
                    break;
                 case 9 : x=y=2;
                    break;
            }
            if(xo[x][y]=='_')
                xo[x][y]=c;

            k=check(c);
            switch(k)
        {
            case 1: if(c=='X')
                    {
                        system("cls");
                        display(32,13,0);


                        cout<<"\n\t\t\t Player 1 wins!!";
                        getch();
                        exit(0);
                    }
                    else
                        system("cls");
                        display(32,13,0);
                        cout<<endl<<"\n\t\t\tPlayer 2 wins!!";
                        getch();
                        exit(0);

                    break;

            case 0: system("cls");
                    display(32,13,0);
                    cout<<"\n\t\tDraw match";
                    getch();
                    exit(0);

                    break;
            default:return;
        }


}


    void display(int xx,int yy,int ac)
    {//system("cls");
        if(ac==1)
            y=240;
        else
            y=15;

        for(int i=0;i<3;i++)
        {gotoxy(xx,yy);
             for(int j=0;j<3;j++)
             {
                 if(i==a&&j==b)
                 SetConsoleTextAttribute(console,y);
                 cout<<setw(2)<<xo[i][j]<<setw(2);
                 SetConsoleTextAttribute(console,15);
                if(j==0||j==1)
                    cout<<"|";

             }
            yy++;
            gotoxy(xx,yy);
            if(i==0||i==1)
            cout<<"___|___|___";
            yy++;

        }
        yy--;
        gotoxy(xx,yy);
        cout<<"   |   |   ";

    }

    int enter(char c)  //return 1, game is over with result; -1, game in progress; 0, game is over, no result
{char k=0,cnt=0;
    int f=0;

		while(f==0)
		{   //display(xx,yy,1);//Change it later
			f=getArrow();
			if(f==0)
                return 0;
            //cout<<"f= "<<f<<endl;
			//cout<<endl<<a<<setw(2)<<b<<endl<<flag;
			//kbhit();
        }

        if(xo[a][b]=='_')
		{
		    xo[a][b]=c;
		    return 1;
		    //num++;
		}
		else
            return 0;
		//display(xx,yy,1);



    }
    int getArrow()
    {
        //kbhit();

                unsigned char ch = getch();
                //cout<<"getarrow ch= "<<(int)ch<<endl;
                if((int)ch==13)
                return 1;

                if ((int)ch == 0xe0)
                {

                    //first char is a zero so lets look at the next char....

                    ch = getch();

                    switch(ch)
                    {

                        case ARROW_UP:
										if(a==0)
											a=2;
										else
											a--;
											return 0;
                                        cout<<"Arrow up"<<endl;
										break;
						case ARROW_LEFT:if(b==0)
											b=2;
										else
											b--;
                                        return 0;
											cout<<"Arrow left"<<endl;
											break;

                        case ARROW_RIGHT:if(b==2)
											b=0;
										else
											b++;
											return 0;
											cout<<"Arrow right"<<endl;
											break;

                        case ARROW_DOWN:if(a==2)
											a=0;
										else
											a++;
											return 0;
											cout<<"Arrow down"<<endl;
										break;

                        default: //flag=1;
                                cout<<"Default"<<endl;

								break;
            }



        }




}



};

/*int main()
{
 tic test;
 int flag=0;
    while(flag==0)
    {
        flag=test.enter(1,1);
        //cout<<endl<<flag;
    }


}

*/
