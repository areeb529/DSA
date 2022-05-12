class Solution {
public:
    int minTimeToType(string word) {
        int n=word.size();
        int ans=0;
        ans=ans+min(word[0]-'a',1+'z'-word[0]);
        ans++;
        for(int i=1;i<n;i++){
            if(word[i]>word[i-1]){
                ans=ans+min(word[i]-word[i-1],'z'-word[i]+word[i-1]-'a'+1);
            }
            else{
                ans=ans+min(word[i-1]-word[i],'z'-word[i-1]+word[i]-'a'+1);
            }
            ans++;
        }
        return ans;
    }
};