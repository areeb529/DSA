class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int n=words1.size(),m=words2.size();
        vector<string> res;
        vector<int> mp2(26,0);
        for(int i=0;i<m;i++){
            vector<int> temp(26,0);
            for(int j=0;j<words2[i].size();j++){
                temp[words2[i][j]-'a']++;
                mp2[words2[i][j]-'a']=max(temp[words2[i][j]-'a'],mp2[words2[i][j]-'a']);
            }
        }
        for(int i=0;i<n;i++){
            vector<int> mp1(26,0);
            for(int j=0;j<words1[i].size();j++){
                mp1[words1[i][j]-'a']++;
            }
            bool flag=true;
            for(int j=0;j<26;j++){
                if(mp2[j]>mp1[j]){
                    flag=false;
                    break;
                }
            }
            if(flag)res.push_back(words1[i]);
        }
        return res;
    }
};