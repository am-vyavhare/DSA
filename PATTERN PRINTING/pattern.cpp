#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int count=1;
    int i=1;
    while(i<=n){
        
        int j=0;
        while(j<i){
            cout<<count<<" ";
        j++;
        count++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}