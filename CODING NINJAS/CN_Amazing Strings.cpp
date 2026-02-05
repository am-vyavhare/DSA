#include<unordered_map>
string amazingStrings(string first, string second,string third) {
    //map to store the char count 
    unordered_map<char,int> mp;
    //if third string does not match length of another 2
    if(first.length()+second.length() != third.length()){
        return "NO";
    }
    //store first string char
    for(char ch: first){
        mp[ch]++;
    }
    //store second string char
    for(char ch : second){
        mp[ch]++;
    }
    //traverse 3rd string and check for existance of the char
    for(char ch : third){
        //if not found return no
        if(mp.find(ch) == mp.end()){
            return "NO";
        }
        //if found then decrease count to avoid repeat character count 
        else{
            mp[ch]--;
        }
    }
    return "YES";
}
