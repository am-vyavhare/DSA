#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int j = 1;
        int i = 0;
        int count = 0;
        int answer = 0;

        while(count<=k){
            
            if(i<arr.size()){
            if(arr[i]==j){
                i++;
                j++;
            }
            else{
                j++;
                answer = j;
                count++;
            }
        }
        else
        {
            if(count<=k){
                while(1){
                     if(count==k){
                        break;
                    }
                    count++;
                    j++;
                    answer = j;
                }
        }
        }
        
        if(count==k){
            break;
        }
     }
        return answer-1;
    }
};