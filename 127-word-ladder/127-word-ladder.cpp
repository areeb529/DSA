class Solution {
public:
    unordered_set<string> st;
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto &i:wordList){
            st.insert(i);
        }
        queue<string> pN;
        pN.push(beginWord);
        int cnt=1;
        bool flag=false;
        while(!pN.empty()){
            int n=pN.size();
            for(int i=0;i<n;i++){
                string word=pN.front();
                if(word==endWord){
                    flag=true;
                    break;
                }
                pN.pop();
                for(int k=0;k<word.size();k++){
                    char temp=word[k];
                    for(char ch='a';ch<='z';ch++){
                        if(ch==temp)continue;
                        word[k]=ch;
                        if(st.count(word)==0)continue;
                        pN.push(word);
                        st.erase(word);
                    }
                    word[k]=temp;
                }
            }
            if(flag)break;
            cnt++;
        }
        if(flag)return cnt;
        else return 0;
    }
};