#include <iostream>
using namespace std;
int count=0;
void f(char* str){
    //static int count=0;
    cout<<str<<endl;
    count++;
}
void f(char* str,bool flag){
    extern int count;
    if(flag==true){
        int temp=count;
        for(int i=0;i<temp;i++){
            f(str);
        }
    }else{
        f(str);
    }
}

int main(){
    f("OOP0");
    f("OOP1");
    f("OOP2", true);
    f("OOP3", false);
    f("OOP4", true);
    return 0;
}