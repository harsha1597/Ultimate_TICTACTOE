
#include "Tic_tac_toe_small.cpp"
#include<iostream>
#include<stdlib.h>
using namespace std;
class tic2: public tic
{

tic tac[9];
tic res;   //the final tictactoe that'll determine the winner
int sx,sy;



public:

    void anybox()
    {
            system("cls");
            int ch;
            char p;
            int x,y;
            cout<<setw(18)<<"Choose which box to begin in "<<"\n\n";
            cout<<"\t\t_1_|_2_|_3_"<<endl<<"\t\t_4_|_5_|_6_"<<endl<<"\t\t_7_|_8_|_9_"<<endl;
            cin>>ch;
            enter2(ch-1);

    }

    void display2(int n) // n for selecting the active block
    {int xx=18,yy=5,ac=0; //old value xx=18 yy=5 ac to activate a box

              for(int i=0;i<9;i++)
        {
            if(i==n)
                ac=1;
            tac[i].display(xx,yy,ac);
            xx+=14;
            if((i+1)%3==0)
            {
                xx=18;
                yy+=8;
            }
            ac=0;
        }
        xx=18;
        int y1=11;
        yy=19;
        for(int i=0;i<40;i++)
        {

            gotoxy(xx,yy);
            cout<<"_";
            gotoxy(xx,y1);
            cout<<"_";
            xx++;
        }
        xx=30;
        int x1=44;
        yy=5;
        for(int i=0;i<21;i++)
        {
            gotoxy(xx,yy);
            cout<<"|";
            gotoxy(x1,yy);
            cout<<"|";
            yy++;
        }

cout<<"\n\n";
    }

    void enter2(int chn) //chn gives box number
    {
        char c;
        static int num=0;
        int next,k;
        if(num%2!=0) //Odd turn for X, Turn 1 for X
            c='X';
        else
            c='O';


        int flag=0;
        system("cls");
        display2(chn);
        while(flag==0)
        {
            flag=tac[chn].enter(c);
            display2(chn);
            //res.display(18,30,0);


        }
        k=tac[chn].check(c);
        num++;
        switch(k)
        {
            case 1:res.resenter(c,chn+1);
                   break;
            case 0: res.resenter('#',chn+1);
                    break;
            default:break;
        }
        next=tac[chn].getnext();
        if(res.resret(next+1)=='#'||tac[next].conjest(res.resret(next+1)))
            anybox();
        else
            enter2(next);
    }
}test;

int main()
{

   cout<<setw(30)<<"\t\t\t     ULTIMATE TIC TAC TOE "<<endl;


   cout<<"\n\n\n\t\t\t\t    RULES\n";
   cout.setf(ios::left,ios::adjustfield);
   cout.width(70);
   cout<<setfill('*')<<"\n\t";
   cout<<"\n    1. Player 1 , 'X' plays first move in any box "<<endl;
   cout<<"\n    2. Player 2, 'O' plays in the box corresponding to the move of X "<<endl;
   cout<<"\n    3. If all the places in a box are filled , then a player can play in ANY BOX"<<endl;
    cout.width(70);
    cout<<setfill('*')<<"\n\t";
   cout<<"\n\n\t\tPlayer 1 X"<<"\n\t\tPlayer 2 O";
   cout<<"\n\n\t\tPress Enter to Start the Game!!";
   getch();
   cout.unsetf(ios::adjustfield);
   cout.fill(' ');

   test.anybox();





}
