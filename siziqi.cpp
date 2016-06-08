#include <iostream>
using namespace std;

int win = 0;
char c[6][6];

void Initial()
{
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            c[i][j] = '-';
        }
    }
}

void Print()
{
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            cout<<c[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

void Check()
{
    //henxiang
    int flag1 = 0;
    int flag2 = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (c[i][j]=='O'&&
                    c[i][j]==c[i][j+1]) {
                flag1++;
            }
            if (c[i][j]=='X'&&
                    c[i][j]==c[i][j+1]) {
                flag2++;
            }
        }
    }
    if (flag1==3) {
        cout<<"Player 1 Wins."<<endl;
        win++;
    }
    if (flag2==3) {
        cout<<"Player 2 Wins."<<endl;
        win++;
    }


    //shuxiang
    flag1 = 0;
    flag2 = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (c[i][j]=='O'&&
                    c[i][j]==c[i+1][j]) {
                flag1++;
            }
            if (c[i][j]=='X'&&
                    c[i][j]==c[i+1][j]) {
                flag2++;
            }
        }
    }
    if (flag1==3) {
        cout<<"Player 1 Wins."<<endl;
        win++;
    }
    if (flag2==3) {
        cout<<"Player 2 Wins."<<endl;
        win++;
    }

    // \fangxiang
    flag1 = 0;
    flag2 = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (c[i][j]=='O'&&
                    c[i][j]==c[i+1][j+1]) {
                flag1++;
            }
            if (c[i][j]=='X'&&
                    c[i][j]==c[i+1][j+1]) {
                flag2++;
            }
        }
    }
    if (flag1==3) {
        cout<<"Player 1 Wins."<<endl;
        win++;
    }
    if (flag2==3) {
        cout<<"Player 2 Wins."<<endl;
        win++;
    }

    // /fangxiang
    flag1 = 0;
    flag2 = 0;
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (c[i][j]=='O'&&
                    c[i][j]==c[i+1][j-1]) {
                flag1++;
            }
            if (c[i][j]=='X'&&
                    c[i][j]==c[i+1][j-1]) {
                flag2++;
            }
        }
    }
    if (flag1==3) {
        cout<<"Player 1 Wins."<<endl;
        win++;
    }
    if (flag2==3) {
        cout<<"Player 2 Wins."<<endl;
        win++;
    }

}

class Player
{
public:
    int r;//row
    char t;//type
    Player(char tt):
        t(tt)
    {
        r = 5;
    }
    void Laozi(int n)
    {
        r= 5;
        while(c[r][n-1]!='-')
        {
            r--;
        }
        c[r][n-1] = t;
    }
};


int main()
{
    Initial();
    Player p1('O');
    Player p2('X');

    while (1) {
        cout<<"Player 1, choose a column: ";
        int cp1;
        cin>>cp1;
        p1.Laozi(cp1);
        Print();
        Check();
        if (win) {
            break;
        }

        cout<<"Player 2, choose a column: ";
        int cp2;
        cin>>cp2;
        p2.Laozi(cp2);
        Print();
        Check();
        if (win) {
            break;
        }
    }

    return 0;
}
