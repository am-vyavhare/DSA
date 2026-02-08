#include <bits/stdc++.h>
vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n)
{
    //Step 1 - create a map to store the element and its frequency
    unordered_map<int, int> freq;
    //create a answer vector
    vector<pair<int,int>> answer;
    //Traverse through the array and check each time target matching pair exist or not 
    for(int i = 0; i < n ; i++){
        //calculate needed
        int needed = target - arr[i];
        //check if needed value element exist with at least one time
        if(freq[needed] > 0){
            //use it to form pair and decrease frequency
            answer.push_back({arr[i],needed});
            freq[needed]--;
        }
        else{
            //if not found then add current element
            freq[arr[i]]++;
        }
    }
    //check if result is empty then add (-1, -1)
    if(answer.empty()){
        answer.push_back({-1,-1});
    }
    return answer;
}
