class Solution {
public:
    int operation(int num1,int num2,string &op){
        if(op=="+"){
            return num1+num2;
        }
        else if(op=="-"){
            return num1-num2;
        }
        else if(op=="*"){
            return num1*num2;
        }
        else{
            return num1/num2;
        }
    }
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int n=tokens.size();
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/"){
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();
                int res=operation(num1,num2,tokens[i]);
                st.push(res);
            }
            else{
                int num=stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};