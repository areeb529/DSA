class Solution {
public:
    string interpret(string command) {
        int n=command.size();
        string temp;
        string ans;
        for(int i=0;i<n;i++){
            temp.push_back(command[i]);
            if(temp=="G"){
                ans+=temp;
                temp="";
            }
            else if(temp=="()"){
                ans+="o";
                temp="";
            }
            else if(temp=="(al)"){
                ans+="al";
                temp="";
            }
        }
        return ans;
    }
};