#include<iostream>
#include<vector>
using namespace std;
#include <bits/stdc++.h> 



bool ispossible(vector<int> &boards, int k, int mid){
    int paintercount = 1;
    int boardsum = 0;

    for(int i =0 ; i < boards.size(); i++){
        if(boardsum+boards[i]<=mid){
            boardsum = boardsum + boards[i];
        }
        else{
            paintercount = paintercount +1;
            if(paintercount > k || boards[i] > mid){
                return false;
        }
        
        boardsum = boards[i];   
        }
    }
    return true;
}


int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int s = 0;
   
     int sum = 0;
    for(int i = 0; i < boards.size(); i++){
        sum = sum + boards[i];
    }

    int e = sum;
    int mid = s + (e-s)/2;
    int ans = -1;
    
    while(s<=e){
        if(ispossible(boards, k, mid)){
            ans=mid;
            e = mid -1;
        }
        else{
            s = mid + 1; 
        }
        mid = s + (e-s)/2;
    }
    return ans;
}


