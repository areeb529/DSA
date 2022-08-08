class Solution {
public:
     unordered_map<int,string> mp;
    string helper(int num,vector<int> &arr){
        string ans;
        while(true){
            if(mp.count(num)==1){
                ans=ans+mp[num];
                break;
            }
            else{
                auto it=upper_bound(arr.begin(),arr.end(),num);
                int idx=it-arr.begin()-1;
                ans=ans+mp[arr[idx]];
                num=num-arr[idx];
            }
        }
        return ans;
    }
    string intToRoman(int num) {
        mp[1]="I";
        mp[4]="IV";
        mp[5]="V";
        mp[9]="IX";
        mp[10]="X";
        mp[40]="XL";
        mp[50]="L";
        mp[90]="XC";
        mp[100]="C";
        mp[400]="CD";
        mp[500]="D";
        mp[900]="CM";
        mp[1000]="M";
        vector<int> arr={1,4,5,9,10,40,50,90,100,400,500,900,1000};
        return helper(num,arr);
    }
};