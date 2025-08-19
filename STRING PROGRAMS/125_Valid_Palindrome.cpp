class Solution {
public:
    bool valid(char ch){
        if(ch >= 'a' && ch <='z' ||  ch >= 'A' && ch <='Z' || ch >= '0' && ch <='9'){
            return true;
    }
    return false;
    }
    
    char toLowerCase(char ch){
        if(ch >= 'a' && ch <='z' || ch >= '0' && ch <='9'){
            return ch;
        }
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }

    bool checkPalindrome(string t){
        int start = 0;
        int end = t.length()-1;
        while(start <= end ){
            if(toLowerCase(t[start]) != toLowerCase(t[end])){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    bool isPalindrome(string s) {
        string temp;
        
        for(int j = 0 ; j < s.length(); j++){
            if(valid(s[j])){
                temp.push_back(s[j]);
            }
        }
        
        // for(int j = 0 ; j < temp.length(); j++){
        //     temp[j] = toLowerCase(temp[j]);
        // }

        return  checkPalindrome(temp);
        }
};  