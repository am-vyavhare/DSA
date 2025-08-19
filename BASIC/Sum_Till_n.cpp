#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter the number till u want that sum"<<endl;
    cin>>n;
    int sum=0;
    int i=1;
    while(i<=n)
    {
     sum = sum+i;
     i++;   
    }
    cout<<"The sum till n "<<n<<" is : "<<sum<<endl;
    int sum2 = (n/2)*(1+n);
    cout<<"The sum till n "<<n<<" by formula is : "<<sum2<<endl;
    return 0;
}