class Solution {
public:
    class Trie {
    public:
    class TrieNode{
    public:
      char data;
      TrieNode**children;
      bool isTerminal;
      TrieNode(char data){
          this->data=data;
          children=new TrieNode*[26];
          for(int i=0;i<26;i++){
              children[i]=NULL;
          }
          isTerminal=false;
      }
    };
    TrieNode*root;
    Trie() {
        root=new TrieNode('\0');
    }
    void insert(TrieNode*root,string &word,int i,int n){
        if(i==n){
         root->isTerminal=true;
         return;
        }
        if(root->children[word[i]-'a']==NULL){
            TrieNode*newNode=new TrieNode(word[i]);
            root->children[word[i]-'a']=newNode;
            insert(newNode,word,i+1,n);
        }
        else{
            insert(root->children[word[i]-'a'],word,i+1,n);
        }
    }
    void insert(string word) {
        int n=word.size();
        insert(root,word,0,n);
    }
    void getSuggestions(TrieNode*root,string &prefix,int i,int n,vector<string>&v,string &s){
        if(i<n){
            if(root->children[prefix[i]-'a']==NULL){
                return;
            }
            s.push_back(prefix[i]);
            getSuggestions(root->children[prefix[i]-'a'],prefix,i+1,n,v,s);
        }
        else{
            if(root->isTerminal){
                if(v.size()<3)
                v.push_back(s);
            }
            if(v.size()>=3)return;
            for(int j=0;j<26;j++){
                if(root->children[j]){
                    s.push_back('a'+j);
                    getSuggestions(root->children[j],prefix,i,n,v,s);
                    s.pop_back();
                }
            }
        }
        
    }
    void getSuggestions(string prefix,vector<vector<string>> &res){
        int n=prefix.size();
        vector<string> v;
        string s;
        getSuggestions(root,prefix,0,n,v,s);
        res.push_back(v);
    }
    
};
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        int numProducts=products.size();
        Trie obj;
        for(auto &i:products){
            obj.insert(i);
        }
        vector<vector<string>> res;
        string prefix;
        for(int i=0;i<searchWord.size();i++){
            prefix.push_back(searchWord[i]);
            obj.getSuggestions(prefix,res);
        }
        return res;
    }
};