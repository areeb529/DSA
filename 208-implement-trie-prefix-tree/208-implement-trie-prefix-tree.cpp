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
    bool search(TrieNode*root,string &word,int i,int n){
        if(i==n){
            return root->isTerminal==true;
        }
        if(root->children[word[i]-'a']==NULL)return false;
        return search(root->children[word[i]-'a'],word,i+1,n);
    }
    bool search(string word) {
        int n=word.size();
        return search(root,word,0,n);
    }
    bool startsWith(TrieNode*root,string &prefix,int i,int n){
        if(i==n){
            return true;
        }
        if(root->children[prefix[i]-'a']==NULL)return false;
        return startsWith(root->children[prefix[i]-'a'],prefix,i+1,n);
    }
    bool startsWith(string prefix) {
        int n=prefix.size();
        return startsWith(root,prefix,0,n);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */