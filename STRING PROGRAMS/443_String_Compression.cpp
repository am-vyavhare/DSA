class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0;
        int n = chars.size();
        int answerindex = 0;

        while( i < n ){
            int j = i + 1;
            while( j < n && chars[i] == chars[j]){
                j++;
            }

            chars[answerindex++] = chars[i];
            int count = j - i;

            if(count > 1){
                string number = to_string(count);
                
                for(char ch:number){
                    chars[answerindex++] = ch;   
                }
            }
            i=j;
          }
          return answerindex;
    }
};