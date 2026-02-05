//Optimal Solution 
#include <bits/stdc++.h>
using namespace std;

bool isPossibleToSplit(int n, vector<int> &arr) {

    // If array size is less than 2, splitting is not possible
    // Also, array must be at least size 2 to form subarrays
    if (n < 2) {
        return false;
    }

    // Map to store frequency of each element
    // key   -> element value
    // value -> number of times it appears
    unordered_map<int, int> freq;

    // Count frequency of each element in the array
    for (int x : arr) {
        freq[x]++;
    }

    // Variable to store GCD of all frequencies
    int g = 0;

    // Compute GCD of frequencies
    // gcd(0, x) = x, so first frequency initializes g
    for (auto &it : freq) {
        g = std::gcd(g, it.second);
    }

    // If GCD is at least 2, we can split the array into
    // equal-sized subarrays where each subarray contains
    // the same element
    if (g >= 2) {
        return true;
    }

    // Otherwise, no valid equal-size splitting is possible
    return false;
}



//Possible Brute force approach
#include <bits/stdc++.h> 
bool isPossibleToSplit(int n, vector<int> &arr){
    //check whether the size of the array is atleast 4 since the smallest subarray size ca be 2
    if(n<4){
        return false;
    }
    //two vector to store uniqueElements and its count
    vector<int> uniqueElements;
    vector<int> count;
    
    //initial first element push
    uniqueElements.push_back(arr[0]);
    count.push_back(1);

    //traverse the given array and insert unique elements in the uniqueElements and maintain its count
    for(int i = 1; i < n/2; i++){
        int value = arr[i];
        int j = 0;
        for(; j < uniqueElements.size(); j++){
            //if found increase its count
            if(uniqueElements[j] == value){
            //if one element have count greater than half of the array size then return false because it is not possible 
                if(count[j] == n/2){
                    return false;
                }
                count[j]++;
                break;
            }
        }
        //if element not found then insert and assign count as 1
        if(j == uniqueElements.size()){
            //if count array exceed size more than half then return false
            if(count.size() +  1 <= n/2){
                return false;
            }
        uniqueElements.push_back(value);
        count.push_back(1);
        }
    }

    //check if all count are same or not since if any element count is different subarray cannot form 
    for(int i = 0; i < count.size() -1; i++){
        if(count[i] != count[i+1]){
            return false;
        }
    }
    //if all the above remain passed then the subarray of equal size and same element can be created so return true
    return true;
}