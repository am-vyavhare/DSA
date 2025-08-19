#include <bits/stdc++.h> 
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    
    vector <int> ans;
    for(int i = 0 ; i < mCols ; i ++){
        if(i%2==0){
        for(int j = 0 ; j < nRows ; j++){
            // cout<<arr[j][i]<<" ";
            ans.push_back(arr[j][i]);
        }
        }
        else{
            for(int j = nRows-1 ; j >= 0 ; j--){
            // cout<<arr[j][i]<<" ";
            ans.push_back(arr[j][i]);
        }
        }
        // cout<<endl;
    }
    //Write your code here
    return ans;
}