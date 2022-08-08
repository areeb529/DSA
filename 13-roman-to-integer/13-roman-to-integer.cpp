class Solution {
public:
    unordered_map<char,int> mp;
    int romanToInt(string s) {
        mp['I']=1,mp['V']=5,mp['X']=10,mp['L']=50,mp['C']=100,mp['D']=500,mp['M']=1000;
        int num=0;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(i+1<n&&mp[s[i]]<mp[s[i+1]]){
                num-=mp[s[i]];
            }
            else{
                num+=mp[s[i]];
            }
        }
        return num;
        
    }
};