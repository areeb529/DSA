class Solution {
public:
    unordered_set<string> supplyAvailable;
    unordered_map<string,int> recipeMap;
    bool recipeCanBeMade(vector<string>& recipes,int i,vector<vector<string>>& ingredients,vector<int> &dp){
        if(dp[i]==-2)dp[i]=-1;
        else{
            if(dp[i]==-1)return false;
            else return dp[i];
        }
        if(dp[i]>=0)return dp[i];
        for(int j=0;j<ingredients[i].size();j++){
            if(supplyAvailable.count(ingredients[i][j])==0){
                if(recipeMap.count(ingredients[i][j])==0)return dp[i]=false;
                else{
                    bool f=recipeCanBeMade(recipes,recipeMap[ingredients[i][j]],ingredients,dp);
                    if(!f)return dp[i]=false;
                }
            }
        }
        return dp[i]=true;
    }
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        for(int i=0;i<supplies.size();i++){
            supplyAvailable.insert(supplies[i]);
        }
        int n=recipes.size();
        for(int i=0;i<n;i++){
            recipeMap[recipes[i]]=i;
        }
        vector<int> dp(n,-2);
        vector<string> ans;
        for(int i=0;i<n;i++){
            bool f=recipeCanBeMade(recipes,i,ingredients,dp);
            if(f)ans.push_back(recipes[i]);
        }
        return ans;
        
    }
};