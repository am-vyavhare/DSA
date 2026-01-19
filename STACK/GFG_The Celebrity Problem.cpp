class Solution {
    private:
    //Function to check a knows b or not
    bool knows(vector<vector<int>>& mat, int a, int b, int n){
        //if 1 then knows so return true else false
        if(mat[a][b] == 1){
            return true;
        }
        else
        {
            return false;
        }
    }
    
  public:
    int celebrity(vector<vector<int>>& mat) {
        //size of mat
        int n = mat.size();
        
        //stack to store the persons in party
        stack<int> s;
        
        //push all the element in the stack they are nothing but the index till the stack size
        for(int i = 0 ; i < n ; i++){
            s.push(i);
        }
        
        //step 2 - get 2 elements and compare them
        while(s.size() > 1){
            //first element
            int a = s.top();
            s.pop();
            
            //second element
            int b = s.top();
            s.pop();
            
            //if a know b then b is celebrity so push b
            if(knows(mat, a, b ,n )){
                s.push(b);
            }
            //else a is celebrity
            else{
                s.push(a);   
            }
        }
        
        //consider the remaining last element as the celebrity
        int ans = s.top();
        //step 3 - single element in stack is potential celebrity
        //so verify it
        
        //if all zero in row then he or she knows no one means celebrity
        //Row Check
        for(int i = 0; i < n; i++){
            if(i != ans && mat[ans][i] == 1){
                return -1;
            }
        }
        
        // Column check
        for(int i = 0; i < n; i++){
            if(i != ans && mat[i][ans] == 0){
                return -1;
            }
        }

        return ans;
    }
};