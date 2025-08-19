#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    
    int i = 1;
    int space=n-1;
    int row=1;
    int num=1;
    
    while(i<=n){
    
        space = n - i;    
        while(space){
            cout<<" ";
            space--;
        }
        
        num=1;
        int j=1;
        
        while(j<=row){
            cout<<num<<" ";
            if(j>=i){
                num--;
            }
            else{
                num++;
            }
            j++;
        }
        cout<<endl;
        row+=2;
        i++;
    }

    return 0;
}