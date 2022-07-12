class Solution {
public:
//     bool helper(vector<int>& matchsticks,int i,long posX,long negX,long posY,long negY){
//         if(i==matchsticks.size()){
//             if(posX==negX&&negX==posY&&posY==negY&&negY==posX&&posX&&negX&&posY&&negY)return true;
//             return false;
//         }
//         bool op1=helper(matchsticks,i+1,posX+matchsticks[i],negX,posY,negY);
//         bool op2=helper(matchsticks,i+1,posX,negX+matchsticks[i],posY,negY);
//         bool op3=helper(matchsticks,i+1,posX,negX,posY+matchsticks[i],negY);
//         bool op4=helper(matchsticks,i+1,posX,negX,posY,negY+matchsticks[i]);
//         bool res=op1||op2||op3||op4;
//         return res;
       
//     }
    bool partition(vector<int>& nums,int i,int curSum,int k,int targetSum,vector<bool> &visited,int n){
        if(k==1){
            return true;
        }
        if(curSum==targetSum){
            return partition(nums,0,0,k-1,targetSum,visited,n);
        }
        else{
            for(int j=i;j<n;j++){
                if(visited[j])continue;
                visited[j]=true;
                if(partition(nums,j+1,curSum+nums[j],k,targetSum,visited,n)==true)return true;
                visited[j]=false;
            }
            return false;
        }
    }
    bool makesquare(vector<int>& matchsticks) {
        // int n=matchsticks.size();
        // return helper(matchsticks,0,0,0,0,0);
        int n=matchsticks.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=matchsticks[i];
        }
        
        if(sum%4!=0)return false;
        vector<bool> visited(n,false);
        return partition(matchsticks,0,0,4,sum/4,visited,n);
        
    }
};