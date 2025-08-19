class Solution {
public:
    bool checkequal(int a[], int b[]){
        for(int i = 0; i<26 ; i++){
            if(a[i] != b[i]){
                return 0;
            }
        }
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {0};
        
        //character count of first array
        for(int i = 0 ; i < s1.length() ; i++){
            int index = s1[i] - 'a';
            count1[index]++; 
        }

        //traverse s2 string in window size length of s1 and compare
        int i = 0 ;
        int windowSize = s1.length();
        int count2[26] = {0};

        while(i < s1.length()  && i < s2.length()){
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }
        
        //check equality of both count array that will tell the matching permutation 

        if(checkequal(count1,count2)){
            return 1;
        }

    //process for the next window size

    while(i< s2.length()){
        char newchar = s2[i];
        int index = newchar - 'a';
        count2[index]++;

        char oldchar = s2[i - windowSize];
        index = oldchar - 'a';
        count2[index]--;

        i++;

        if(checkequal(count1,count2)){
            return 1;
        }

    }
    return 0;
    }
};