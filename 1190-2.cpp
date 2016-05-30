#include <iostream>

#include <string>

#include <vector>

using namespace std;


class Tv

{

private:

    int no;

    int mod;

    int chan;

    int vol;

    static int tvnum;

    static int dvdnum;

public:

    Tv(){}

    ~Tv(){}

    friend void RemoteControl(Tv& t,int tmod,int tchan,int tvol);

    void Print();

    void Set(int i);

    static void numprint();

};

int Tv::tvnum = 0;

int Tv::dvdnum = 0;

void RemoteControl(Tv& t,int tmod,int tchan,int tvol)

{

    if (tmod == 2) {

        if (t.mod==1&&tmod==2) {
            Tv::dvdnum++;

            Tv::tvnum--;
        }

        t.mod = 2;

        t.chan = 99;
    }

    else if (tmod ==1) {

        if (t.mod==2&&tmod==1) {
            Tv::dvdnum--;

            Tv::tvnum++;
        }

        t.mod = 1;

        t.chan = tchan;
    }


    int nv = t.vol + tvol;

    if (nv>0&&nv<100) {

        t.vol += tvol;

    }
    else if (nv>=100) {
        t.vol = 100;
    }
    else if (nv<=0) {
        t.vol = 0;
    }

    t.Print ();
}



void Tv::Set(int i)

{

    no = i;

    chan = i;

    vol = 50;

    mod = 1;

    Tv::tvnum++;

}



void Tv::Print ()

{
    cout<<no<<"*"<<mod<<"*"<<chan<<"*"<<vol<<endl;

//    if (mod == 1) {

//        cout<<"第"<<no<<"号电视机--"

//           <<"TV模式--频道"<<chan

//          <<"--音量"<<vol<<endl;

//    }

//    else if (mod==2) {

//        cout<<"第"<<no<<"号电视机--"

//           <<"DVD模式--频道"<<chan

//          <<"--音量"<<vol<<endl;

//    }

}


void Tv::numprint()

{
    cout<<Tv::tvnum<<"*"<<Tv::dvdnum<<endl;

//    cout<<"播放电视的电视机数量为"<<Tv::tvnum<<endl;

//    cout<<"播放DVD的电视机数量为"<<Tv::dvdnum<<endl;

}


int main()

{

    int n;

    cin>>n;

    vector<Tv> ccav(n);

    for (int i = 0; i < n; ++i) {

        ccav[i].Set(i+1);

    }


    int t;

    cin>>t;

    for (int var = 0; var < t; ++var) {

        int i,k,x,vc;

        cin>>i>>k>>x>>vc;

        RemoteControl (ccav[i-1],k,x,vc);

    }

    Tv::numprint();

}




