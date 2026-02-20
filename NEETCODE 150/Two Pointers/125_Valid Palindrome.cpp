//Approach 1 - acceptable and interview preferred but if told dont use built in functions then solution is using ASCII
class Solution {
public:
    bool isPalindrome(string s) {
    //Declare two pointers from start and end
    int start = 0;
    int end = s.length() - 1;
    //Traverse until they cross each other
    while(start < end){
        //skip the non alphanumeric from left 
        while(start < end && !isalnum(s[start]))
            start++;
        
        //skip the non alphanumeric from right
        while(start < end && !isalnum(s[end]))
            end--;

        //compare the start and end
        if(tolower(s[start]) != tolower(s[end])){
            return false;
        }
        //update the pointer
        start++;
        end--;
    }
    return true;
    }
};

//Approach 2 - Using the Ascii value but not recommended 
class Solution {
public:
    bool isPalindrome(string s) {
        //step 1 - create two pointers to traverse only char and numbers from the start and end
        int start = 0;
        int end = s.length()-1;
        while(start <= end){
            char st = s[start];
            char en = s[end];
            if((st > 64 && st < 91) || (st > 96 && st < 123) || (st>47 && st < 58)){
                if((en > 64 && en < 91) || (en > 96 && en < 123) || (en>47 && en < 58)){
                    if(!((st>47 && st < 58) && (en > 47 && en < 58))){
                        if(tolower(s[start]) != tolower(s[end]))
                            return false;
                    }
                    else{
                        if(s[start] != s[end])
                            return false;
                    }
                    start++;
                    end--;
                }
                else{
                    end--;
                }
            }
            else{
                start++;
            }
        }
        return true;                
    }
};