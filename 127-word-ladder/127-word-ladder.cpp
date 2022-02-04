class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        unordered_set<string> st;
        for(int i=0;i<n;i++){
            st.insert(wordList[i]);
        }
        if(st.count(endWord)==0)return 0;
        int ladder=0;
        queue<string> pN;
        pN.push(beginWord);
        while(!pN.empty()){
            int size=pN.size();
            ladder++;
            while(size--){
                string word=pN.front();
                if(word==endWord){
                    return ladder;
                }
                pN.pop();
                st.erase(word);
                for(int j=0;j<word.size();j++){
                    char c=word[j];
                    for(int k=0;k<26;k++){
                        word[j]='a'+k;
                        if(st.count(word)==1){
                            pN.push(word);
                        }
                    }
                    word[j]=c;
                }
            }
        }
        return 0;
        
    }
};