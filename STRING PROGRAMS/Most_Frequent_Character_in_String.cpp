class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int count[26] = {0};
        for(int i = 0 ; i < s.length(); i++)
        {
            int number = s[i] - 'a';
            count[number]++;
        }
    
    int max = -1;
    int answer = 0;
    for(int j = 0; j < 26 ; j++){
        if(count[j]>max){
            max = count[j];
            answer = j;
        }
    }
    
    return 'a' + answer;
}
};