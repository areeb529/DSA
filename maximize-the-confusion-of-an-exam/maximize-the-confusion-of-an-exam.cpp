class Solution {
public:
    int maxConfusion=0;
    void ansConfusion(string &answerKey, int k,int n,char ans1,char ans2){
        int i=0,j=0;
        while(j<n){
            if(answerKey[j]==ans1){
                maxConfusion=max(maxConfusion,j-i+1);
                j++;
            }
            else{
                while(k==0&&i<=j){
                    if(answerKey[i]==ans2)k++;
                    i++;
                }
                maxConfusion=max(maxConfusion,j-i+1);
                k--;
                j++;
            }
        }
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        ansConfusion(answerKey,k,n,'T','F');
        ansConfusion(answerKey,k,n,'F','T');
        return maxConfusion;
    }
};