#include<iostream>
using namespace std;

int binarysearch(int a[], int element){
    int start = 0;
    int end = 9;
    int mid = start+(end-start)/2;

    while(start<=end){
        if(a[mid]==element){
            return mid;
        }
        else{
            if(element < a[mid])
                end = mid-1;
            else
                start = mid+1;
        }
        mid = start+(end-start)/2;

    }
    return -1;
}


int main(){
    
    int a[10] = {23,24,64,99,123,234,345,456,567,675};

    int n = 10;
   

    int element;
    cout<<"Enter the element to search"<<endl;
    cin>>element;

    int index = binarysearch(a,element);
    cout<<"the position of the element is "<<index << " and the element is "<<a[index]<<endl;
    
}