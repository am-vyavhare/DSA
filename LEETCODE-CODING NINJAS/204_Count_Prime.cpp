class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        vector <bool> prime(n+1,true);

        prime[0] = prime [1] = false;
        
        for(int i = 2 ; i < n ; i++){
            
            if(prime[i]){  //check for the mark true by default 
                count++;
            }
            for(int j = 2*i ; j < n; j=j+i)  //check that the current present numbers are present in the table of given numbers starting from i if yes mark them false
            {
                prime[j] = false;
            }
        }
    return count;
    }
};