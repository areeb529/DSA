class Solution {
public:
    
    string getPermutation(int n, int k) {
        vector<int> numbers;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans;
        k=k-1;
        while(true){
            ans=ans+to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+k/fact,numbers.begin()+k/fact+1);
            if(numbers.size()==0)break;
            k=k%fact;
            fact=fact/numbers.size();
        }
        return ans;
        
       
        
    }
};