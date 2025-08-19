#include<iostream>
using namespace std;

int main(){
    char ch;
    cout<<"Enter the Character between a-z A-Z 0-9"<<endl;
    cin>>ch;

    int a = ch;
    if(a>96){
        cout<<"the char is lowercase"<<endl;
    }
    else if(a>64){
        cout<<"the char is uppercase"<<endl;
    }
    else{
        cout<<"The char is number";
    }
return 0;    
}