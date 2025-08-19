#include<iostream>
using namespace std;

int main(){
    int n2000count = 0;
    int n500count = 0;
    int n100count = 0;
    int n50count = 0;
    int n20count = 0;
    int n10count = 0;
    int n5dollar = 0;
    int n2dollar =  0;
    int n1dollar = 0;
    
    int amount = 0;
    cout<<"Enter the total amount u have"<<endl;
    cin>>amount;

    int note;
    while(amount!=0){
        if(amount/2000>0){
            note = 2000;
        }
        else if(amount/500>0){
            note = 500;
        }
        else if(amount/100>0){
            note = 100;
        }
        else  if(amount/50>0){
            note = 50;
        }
        else if(amount/20>0){
            note = 20;
        }
        else if(amount/10>0){
            note = 10;
        }
        else if(amount/5>0){
            note = 5;
        }

        else if(amount/2>0){
            note = 2;
        }
        else if(amount/1>0){
            note = 1;
        }
        
        switch (note)
        {
        
        case 2000:
            n2000count = amount/2000;
            amount = amount%2000;
            break;
        case 500:
            n500count = amount/500;
            amount = amount%500;
            break;
        case 100:
            n100count = amount/100;
            amount = amount%100;
            break;
        case 50:
            n50count = amount/50;
            amount = amount%50;
            break;
        case 20:
            n20count = amount/20;
            amount = amount%20;
            break;
        case 10:
            n10count = amount/10;
            amount = amount%10;
            break;
        
        case 5:
            n5dollar = amount/5;
            amount = amount%5;
            break;
        
        case 2:
            n2dollar = amount/2;
            amount = amount%2;
            break;
        
        case 1:
            n1dollar = amount/1;
            amount = amount%1;
            break;
        default:
            break;
        }
    }
     cout<<"2000 note required is : "<<n2000count<<endl;
    cout<<"500 note required is : "<<n500count<<endl;
    cout<<"100 note required is : "<<n100count<<endl;
    cout<<"50 note required is : "<<n50count<<endl;
    cout<<"20 note required is : "<<n20count<<endl;
    cout<<"10 note required is : "<<n10count<<endl;
     cout<<"5 rupee dollar required is : "<<n5dollar<<endl;
    cout<<"2 rupee dollar required is : "<<n2dollar<<endl;
    cout<<"1 rupee dollar required is : "<<n1dollar<<endl;
    

    return 0;
}