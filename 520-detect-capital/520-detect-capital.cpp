class Solution {
public:
    bool detectCapitalUse(string word) {
       int n=word.size();
        if(n==1)return true;
        int ct=0;
        for(auto &c:word){
            if(c<'a')ct++;
        }
        if(word[0]<'a'){
            return ct==n||ct==1;
        }
        else{
            return ct==0;
        }
    }
};