#include<iostream>
#include<cmath>
using namespace std;
class Int
{
private:
	int high, low; //实际值为high * 10^2 + low;

public:
    Int(int in_high=0,int in_low=0){
        high=in_high;
        low=in_low;
    }

    Int operator+(Int b){
        int templow,temphigh;
        templow=this->low+b.low;
        temphigh=this->high+b.high;

        temphigh+=templow/100;
        if(templow!=0){
            templow=templow%100;
        }

        this->high=temphigh;
        this->low=templow;
        return *this;
    }

    /*Int operator-(Int b){
        int templow,temphigh,unsignhigh,unsignlow;
        bool h=0,l=0;//负为1
        temphigh=this->high-b.high;
        templow=this->low-b.low;

        if(temphigh<0){
            h=1;
            unsignhigh=-temphigh;
        }else{
            unsignhigh=temphigh;
        }

        if(templow<0){
            l=1;
            unsignlow=-templow;
        }else{
            unsignlow=templow;
        }

        if(h!=l){
            unsignhigh--;
        }

        
    }*/

    int phigh(){
        return this->high;
    }

    int plow(){
        return this->low;
    }

    friend istream& operator>>(istream& in,Int& a);
    friend ostream& operator<<(ostream& out,Int& a);
};

istream& operator>>(istream& in,Int& a){
    in>>a.high>>a.low;
    return in;
}

ostream& operator<<(ostream& out,Int& a){
    out.fill('0');
    out<<a.high;
    out.width(2);
    out<<a.low<<endl;
    return out;
}

int main(){
    int a,b,c,d;
    Int obj1,obj2;
    cin>>obj1>>obj2;
    obj1=obj1+obj2;
    cout<<obj1;
    //printf("%d %02d",obj1.phigh(),obj1.plow());
}