class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n=words.size();
        vector<int> nums(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<words[i].size();j++){
                nums[i]|=(1<<(words[i][j]-'a'));
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(!(nums[i]&nums[j])){
                    int length1=words[i].size();
                    int length2=words[j].size();
                    ans=max(ans,length1*length2);
                }
            }
        }
        return ans;
        
    }
};