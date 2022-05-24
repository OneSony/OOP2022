#include<iostream>
#include<regex>
using namespace std;

struct user_info{
    string username;
    string password;
    string email;
    bool illegal;
}user;

int main(){
    user.illegal=0;
    string json;

    getline(cin,json);

    regex r_username(R"(\"username\"[ ]*:[ ]*\"([a-zA-Z]\w{3,14})\")");
    regex r_password(R"(\"password\"[ ]*:[ ]*\"([a-zA-z0-9]{8,20})\")");
    regex r_email(R"(\"email\"[ ]*:[ ]*\"([\w]+@(?:\w+.)+\w+)\")");
    smatch s;

    //string a=R"({"password" : "abc12345", "username": "correct", "email": "a@b.c.com"})";
    if(regex_search(json,s,r_username)){
        user.username=s[1];
        //cout<<s[1]<<endl;
    }else{
        user.username="0";
        user.illegal=1;
        //cout<<"?"<<endl;
    }


    regex d("\\d");
    regex a("[a-zA-Z]");

    if(regex_search(json,s,r_password)&&regex_search(string(s[1]),d)&&regex_search(string(s[1]),a)){
        user.password=s[1];
        //cout<<s[1]<<endl;
    }else{
        user.password="0";
        user.illegal=1;
        //cout<<"?"<<endl;
    }

    if(regex_search(json,s,r_email)){
        user.email=s[1];
        //cout<<s[1]<<endl;
    }else{
        user.email="0";
        user.illegal=1;
        //cout<<"?"<<endl;
    }

    if(user.illegal==1){
        cout<<"Illegal ";
        if(user.username=="0"){
            cout<<"username";
        }
        if(user.password=="0"){
            if(user.username=="0"){
                cout<<",";
            }
            cout<<"password";
        }
        if(user.email=="0"){
            if(user.username=="0"||user.password=="0"){
                cout<<",";
            }
            cout<<"email";
        }
        cout<<endl;
    }else{
        cout<<"Successfully registered."<<endl;

        cout<<"username: ";
        for(int i=0;i<user.username.size();i++){
            if(i<3){
                cout<<user.username[i];
            }else{
                cout<<"*";
            }
        }
        cout<<endl;

        cout<<"password: ";
        for(int i=0;i<user.password.size();i++){
            cout<<"*";
        }
        cout<<endl;

        cout<<"email: ";
        for(int i=0;i<user.email.size();i++){
            if(user.email[i]=='@'||user.email[i]=='.'){
                cout<<user.email[i];
            }else{
                cout<<"*";
            }
        }
        cout<<endl;
    }
}