#include<iostream>
#include<vector>
using namespace std;


void reverseArray(vector<int> &arr , int m) {
    // Write your code here       	
    int start = m+1, end = arr.size()-1;

    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
    } 
} 