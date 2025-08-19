#include<iostream>
using namespace std;
#include<vector>

int firstoccurence(vector<int>& arr, int n, int k){
    int start = 0;
    int end = n -1;
    int mid = start + (end-start)/2;
    int answer = -1;

    while(start<=end){
        if(arr[mid]==k){
            answer = mid;
            end = mid -1;
        }
        else if(k<arr[mid]){
            end = mid -1;
        }
        else if(k>arr[mid]){
            start = mid +1;
        }
        mid = start + (end-start)/2;
    }
    return answer;
}


int lastoccurence(vector <int>& arr, int n, int k){
    int start = 0;
    int end = n -1;
    int mid = start + (end-start)/2;
    int answer = -1;

    while(start<=end){
        if(arr[mid]==k){
            answer = mid;
            start = mid +1;
        }
        else if(k<arr[mid]){
            end = mid -1;
        }
        else if(k>arr[mid]){
            start = mid +1;
        }
        mid = start + (end-start)/2;
    }
    return answer;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
        pair <int,int> p;
        p.first = firstoccurence(arr,n,k);
        p.second = lastoccurence(arr,n,k);

        return p;

}
