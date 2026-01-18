//optimal approach 
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    //Create stack to store and search for the smallest element in it
    stack<int> stk;
    stk.push(-1); //Base element as -1 means if any small not found then push: -1

    vector<int> ans(n); //Resultant vector
    
    //Traverse from the last element since the we need to check on right everytime so we push the right side elements in stack
    for(int i = n-1 ; i >= 0; i--){
        int curr = arr[i];
        //pop stack elements until smallest is found
           while(stk.top() >= curr){
               stk.pop();
           }
        //store the smallest element in the answer vector
        ans[i] = stk.top();
        stk.push(curr); //push the current element in the stack`
        }
    //return answer
    return ans;
}

//Brute Force Approach - not accetable just given for reference 
/*
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    int size = arr.size();
    vector<int> result;

    for(int i = 0 ; i < size - 1 ; i++){
        int k = i+1;
        for( ; k < size; k++){
            if(arr[k] < arr[i]){
                result.push_back(arr[k]);
                break;
            }
        }
        if(k==size){
            result.push_back(-1);
        }
    }
    result.push_back(-1);
    return result;
}
*/