class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
    //variable to store maximum and minimum element and assume first element as max and min
        int min = arr[0];
        int max = arr[0];
    
    //Traverse complete vector and udpate max and min
        for(int i = 0; i < arr.size(); i++){
            if(min>=arr[i]){
                min = arr[i];
            }
            if(max<=arr[i]){
                max = arr[i];
            }
        }
        
    //Vector to store Result [min , max]
        vector<int> result;
        result.push_back(min);
        result.push_back(max);
        
    //Return Result pair
        return result;
    }
};