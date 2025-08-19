#include<iostream>
using namespace std;

int main(){
	
    int answer = 0;
    int arr [10] = {4,2,1,3,1};
    for(int i=0 ; i<5; i++){        
        answer = answer ^ arr[i];
        cout<<"Answer is "<<answer<<endl;
    }

    for(int i =1; i<5; i++){
        answer = answer^i;
        cout<<"---Answer is "<<answer<<endl;
    }

    return 0;
}
