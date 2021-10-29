class Solution {
public:
    bool detectCapitalUse(string word) {
        bool f=false;
        int n=word.size();
        if(n==1)return true;
        for(int i=0;i<n-1;i++){
            if(word[i]>='a'&&word[i+1]<'a')return false;
            if(i>0&&word[i]<'a'&&word[i+1]>='a')return false;
        }
        return true;
    }
};