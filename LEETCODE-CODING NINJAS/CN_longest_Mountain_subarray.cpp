//Optimal Solution in the O(N) time complexity using two pointer/ Sliding Window
#include <bits/stdc++.h> 
int longestMountain(int *arr, int n)
{
    //if the array length is less than 3 then there is no possibility of mountain
    if(n < 3){
        return 0;
    }
    int len = 0; // length of final subarray
    int up = 0; // counter for the climbing movement of the hill
    int down = 0; // counter for the down movement 
    //Traverse the array once and keep track of ongoing up and down patterns
    for(int i = 0; i < n -1; i++){
        //if down is more than 0 means there is down pattern going and and also check flat surface
        //if current situation breaks it then reset the up and down to 0 
        if((down > 0 && arr[i] < arr[i+1]) || (arr[i] == arr[i+1])){
            up = 0;
            down = 0;
        }
        //if climb pattern then increase the up count
        if(arr[i] < arr[i+1]){
            up++;
        }
        //if down movement then increase down count 
        if(arr[i] > arr[i+1]){
            down++;
        }
        
        //if on current situation there is up and down count is > 0 means we have
        //just crossed on peak and moving forward then calculate the length
        //of it and update len to max value till now 
        if(up > 0 && down > 0){
            len = max(len, up + down +1);
            //lenght is up + down and + 1 since the up increase till peak and down
            //increase after peak so we need to add 1 for the peak element 
            //that is considered in the mountain 
        }
    }
    return len;
}