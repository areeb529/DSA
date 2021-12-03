class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i=0,j=0;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int maxP=0;
        int p=1;
        while(j<n){
            if(p*nums[j]>0){
                p=p*nums[j];
                maxP=max(maxP,p);
            }
            else if(p*nums[j]<0){
                p=p*nums[j];
                if(j==n-1){
                    if(p<0){
                    while(i<j){
                        p=p/nums[i];
                        if(nums[i]<0){
                            maxP=max(maxP,p);
                            break;
                        }
                        i++;
                    }
                }
                }
            }
            else if(p*nums[j]==0){
                if(p<0){
                    while(i<j-1){
                        p=p/nums[i];
                        if(nums[i]<0){
                            maxP=max(maxP,p);
                            break;
                        }
                        i++;
                    }
                }
                i=j;
                i++;
                p=1;
            }
            j++;
        }
        return maxP;
    }
};