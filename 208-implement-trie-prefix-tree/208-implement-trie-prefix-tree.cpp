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
    void insert(TrieNode*root,string &word,int i){
        if(i==word.size()){
            root->isTerminal=true;
            return;
        }
        int index=word[i]-'a';
        TrieNode*child;
        if(root->children[index]!=NULL){
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[i]);
            root->children[index]=child;
        }
        insert(child,word,i+1);
    }
    void insert(string word) {
        insert(root,word,0);
    }
    bool search(TrieNode*root,string &word,int i){
        if(i==word.size()){
            return root->isTerminal;
        }
        int index=word[i]-'a';
        if(root->children[index]==NULL)return false;
        TrieNode*child=root->children[index];
        return search(child,word,i+1);
    }
    bool search(string word) {
        return search(root,word,0);
    }
    bool startsWith(TrieNode*root,string &prefix,int i){
        if(i==prefix.size())return true;
        int index=prefix[i]-'a';
        if(root->children[index]==NULL)return false;
        TrieNode*child=root->children[index];
        return startsWith(child,prefix,i+1);
    }
    bool startsWith(string prefix) {
        return startsWith(root,prefix,0);
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */