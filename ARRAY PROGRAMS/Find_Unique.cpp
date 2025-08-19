#include<iostream>
using namespace std;

int main(){
    int unique =0;
    int arr [10] = {3,4,5,3,5,23,34,34,23,5};
    for(int i = 0 ; i< sizeof(arr)/sizeof(arr[0]);i++){
        unique = unique^arr[i];
        cout<<"the unique at "<<i<<"is "<<unique<<endl;
    }
    cout<<"Final Answer is - "<<unique;

    
    return 0;
}   