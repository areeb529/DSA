class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m)return false;
        if(s==goal){
            vector<int> v(26);
            for(int i=0;i<n;i++){
                if(!v[s[i]-'a'])v[s[i]-'a']++;
                else return true;
            }
            return false;
            
        }
        int x=0,y=0;
        int ct=2;
        for(int i=0;i<n;i++){
            if(s[i]!=goal[i]&&ct==2){
                x=i;
                ct--;
            }
            else if(s[i]!=goal[i]&&ct==1){
                y=i;
                ct--;
            }
            else if(s[i]!=goal[i]&&ct==0)return false;
        }
        if(s[x]==goal[y]&&s[y]==goal[x])return true;
        else return false;
        
        
    }
};