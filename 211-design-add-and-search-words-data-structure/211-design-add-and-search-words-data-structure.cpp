class WordDictionary {
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
    WordDictionary() {
        root=new TrieNode('\0');
    }
    void addWord(TrieNode*root,string &word,int i){
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
        addWord(child,word,i+1);
    }
    void addWord(string word) {
        addWord(root,word,0);
    }
    
    bool search(TrieNode*root,string &word,int i){
        if(i==word.size()){
            return root->isTerminal;
        }
        if(word[i]=='.'){
            bool f=false;
            for(int j=0;j<26;j++){
                TrieNode*child=root->children[j];
                if(child)
                f=search(child,word,i+1);
                if(f)return true;
            }
            return false;
        }
        else{
            int index=word[i]-'a';
            TrieNode*child;
            if(root->children[index]==NULL)return false;
            child=root->children[index];
            return search(child,word,i+1);
        }
    }
    bool search(string word) {
        return search(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */