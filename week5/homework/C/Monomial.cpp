#include"Monomial.h"

Monomial::Monomial(int _c, int _d){
    coe=_c;
    deg=_d;
}

Monomial::Monomial(){
    coe=0;
    deg=0;
}

istream& operator>>(istream& in,Monomial& m_in){
    char ctemp[51];
    in.get();
    in.getline(ctemp,50);
    sscanf(ctemp,"%dx^%d",&m_in.coe,&m_in.deg);
    //printf("!:%d %d\n",m_in.coe,m_in.deg);
    return in;
}

ostream& operator<<(ostream& out,Monomial& m_out){
    cout<<m_out.coe<<"x^"<<m_out.deg<<endl;
    return out;
}

Monomial Monomial::operator+(const Monomial &x) const{
    if(this->coe+x.coe==0){
        return Monomial(0,0);
    }else{
        return Monomial(this->coe+x.coe,this->deg);
    }
}

Monomial Monomial::operator-(const Monomial &x) const{
    if(this->coe-x.coe==0){
        return Monomial(0,0);
    }else{
        return Monomial(this->coe-x.coe,this->deg);
        //Monomial rtemp(this->coe-x.coe,this->deg);
    }
}

Monomial Monomial::operator*(const Monomial &x) const{
    if(this->coe*x.coe==0){
        return Monomial(0,0);
    }else{
        return Monomial(this->coe*x.coe,this->deg+x.deg);
    }
}

Monomial Monomial::operator/(const Monomial &x) const{
    if(this->coe/x.coe==0){
        return Monomial(0,0);
    }else{
        return Monomial(this->coe/x.coe,this->deg-x.deg);
    }
}

int Monomial::definite_integral(const int a, const int b) const{
    Monomial integral(this->coe/(this->deg+1),this->deg+1);
    //printf("%d %d\n",integral.coe,integral.deg);
    //printf("%d %d\n",integral.get_val(b),integral.get_val(a));
    return integral.get_val(b)-integral.get_val(a);
}

Monomial Monomial::derive() const{//!!!!

    if(this->deg==0){
        return Monomial(0,0);
    }else{
        return Monomial(this->coe*this->deg,this->deg-1);
    }
}

int Monomial::get_val(int x) const{
    double r=1;
    if(this->deg>0){
        for(int i=0;i<this->deg;i++){
            r*=x;
        }
    }else if(this->deg<0){
        for(int i=0;i<-(this->deg);i++){
            r/=x;
        }
    }else if(this->deg==0){
        r=1;
    }

    return this->coe*r;
}