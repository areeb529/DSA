class Solution {
public:
    bool checkIfPangram(string sentence) {
        int arr[26]={};
        int n=sentence.size();
        if(n<26)return false;
        int count=26;
        for(int i=0;i<n;i++){
            if(arr[sentence[i]-'a']==0){
                count--;
                arr[sentence[i]-'a']=1;
            }
        }
        if(count==0)return true;
        else return false;
    }
};