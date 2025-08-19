#include<iostream>
using namespace std;

void Fibonacci(int first, int second, int till, int count) {
    if(count == till){
        return;
    }
    cout << first+second << " ";
    count++;
    Fibonacci(second, first+second, till, count);

}

int main(){
    int till;
    cout<<"enter the number till u want the Fibonacci series: ";
    cin>>till;

    int first = 0;
    int second = 1;
    
    cout << first << " ";   
    cout << second << " ";
    
    int count = 2;
    
    Fibonacci(first, second, till, count);

    return 0;
}
