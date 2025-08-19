#include<iostream>
#include <vector>
using namespace std;

int getpivot(vector<int>& arr, int n)
{
    int s = 0 ;
    int e = n-1;
    int mid = s + (e-s)/2;

    while(s<e){
        if(arr[mid] >= arr[0]){
            s = mid +1;
        }
        else{
            e = mid;
        }
        mid = s + (e-s)/2;
    }
    return s ;
}


int binarysearch(vector <int>&a, int s, int e, int element){
    int start = s;
    int end = e;
    
    int mid = start+(end-start)/2;

    while(start<=end){
        
        if(a[mid]==element){
            return mid;
        }
        if(element > a[mid]){
                start = mid+1;
        }
        else{
                end = mid-1;
        }
        mid = start+(end-start)/2;
        }
    
    return -1;
}


int search(vector<int>& arr, int n, int k)
{
    
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int pivot = getpivot(arr,n);
    if(k >= arr[pivot] && k <= arr[n-1]){
        binarysearch(arr,pivot,n-1,k);
    }
    else{
        binarysearch(arr,0,pivot-1,k);
    }


}
