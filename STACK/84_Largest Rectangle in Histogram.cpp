class Solution{
private:
//function to find next smallest index of each element
vector<int> nextSmallerElement(vector<int> arr, int n){
    //stack to store the right compare elements
    stack<int> s;
    //store the indexes
    vector<int> ans(n);
    //initially first element is -1 if smallest not found then use it
    s.push(-1); 

    //traverse the complete histogram heights to find next smallest
    for(int i = n - 1; i >=0 ; i--){
        int curr = arr[i];
    //pop if big element found
    while(s.top() != -1 && arr[s.top()] >= curr){
        s.pop();
    }
    //update the stack and resultant vector
    ans[i] = s.top();
    s.push(i);
    }
    //return answer vector
    return ans;
}

//function to find the previous smallest index of each element
vector<int> previousSmallerElement(vector<int> arr, int n){
    //stack to store the left compare elements
    stack<int> s;
    //store the indexes
    vector<int> ans(n);
    //initially first element is -1 if smallest not found then use it
    s.push(-1); 

    //traverse the complete histogram heights to find previous smallest
    for(int i = 0; i < n ; i++){
        int curr = arr[i];
    //pop if big element found
    while(s.top() != -1 && arr[s.top()] >= curr){
        s.pop();
    }
    //update the stack and resultant vector
    ans[i] = s.top();
    s.push(i);
    }
    //return answer vector
    return ans;
}

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        
        vector<int> next(n); //vector to store the next smaller element index of each position
        next = nextSmallerElement(heights, n); //Function to do so

        vector<int> previous(n); // same for previous smaller element index 
        previous = previousSmallerElement(heights, n); 

        int area = INT_MIN; //variable to store maximum area
        //Traverse the heights array till last to get the maximum possible area
        for(int i = 0; i < n; i++){
            // length is nothing but the height of poll so get from heights
            int length = heights[i];
            //if next smaller not found then the index should be size handle this case
            if(next[i] == -1){
                next[i] = n;
            }
            //breadth is nothing but the next smaller index - previous smaller 
            //in between we can make rectangle 
            int breadth = next[i] - previous[i] - 1;
            //current situation new area calculation 
            int newArea = length * breadth;
            area = max(area, newArea);
        }
        return area;
        }
};