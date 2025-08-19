#include<iostream>
#include<math.h> 
using namespace std;

void printarray(int a[], int size){
for(int i=0; i<size ;i++){
    cout<<a[i]<<" ";
}
cout<<endl;
}

void swapalternate(int a[],int size){
    for(int i=0;i<size-1;i+=2){
        if (i+1<size){
            swap(a[i], a[i+1]);
        }
        printarray(a,size);
    
        
        
    }
}

int main(){
    int arr[10] = {12,34,54,23,54,65,76,85,45,39};
    int size = 10;
    cout<<size<<endl;
    // cout<<"Enter the 10 array elements"<<endl;
    // for(int i=0; i<sizeof(arr); i++)
    // {
    //     cin>>arr[i];
    // }
    cout<<"Original array is"<<endl;
    printarray(arr,size);

    swapalternate(arr,size);

    cout<<"Array after swapalternate array is"<<endl;
    printarray(arr,size);

    return 0;
}