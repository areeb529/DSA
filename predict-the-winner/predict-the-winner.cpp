class Solution {
public:
    bool helper(vector<int>& nums,int i,int j,int sum1,int sum2,bool f){
        if(i>j){
            if(f){
            if(sum1>=sum2)return true;
            else return false;
            }
            else{
                if(sum2>sum1)return true;
                else return false;
            }
        }
        if(f){
        bool opt1=helper(nums,i+1,j,sum1+nums[i],sum2,!f);
        bool opt2=helper(nums,i,j-1,sum1+nums[j],sum2,!f);
            if(!opt1||!opt2)return true;
            else return false;
        }
        else{
        bool opt1=helper(nums,i+1,j,sum1,sum2+nums[i],!f);
        bool opt2=helper(nums,i,j-1,sum1,sum2+nums[j],!f);
            if(!opt1||!opt2)return true;
            else return false;
        }
    }
    bool PredictTheWinner(vector<int>& nums) {
        return helper(nums,0,nums.size()-1,0,0,true);
    }
};