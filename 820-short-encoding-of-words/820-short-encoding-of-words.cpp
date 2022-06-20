class Solution {
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
    class Trie{
        public:
        TrieNode*root;
        Trie(){
            root=new TrieNode('\0');
        }
        void insert(TrieNode*root,string &word,int i,int n){
            if(i==n){
                root->isTerminal=true;
                return;
            }
            if(root->children[word[i]-'a']){
                insert(root->children[word[i]-'a'],word,i+1,n);
            }
            else{
                root->children[word[i]-'a']=new TrieNode(word[i]);
                insert(root->children[word[i]-'a'],word,i+1,n);
            }
        }
        void insert(string word){
            int n=word.size();
            insert(root,word,0,n);
        }
        bool search(TrieNode*root,string &word,int i,int n){
            if(i==n)return root->isTerminal==true;
            if(root->children[word[i]-'a']==NULL)return false;
            return search(root->children[word[i]-'a'],word,i+1,n);
        }
        bool search(string word){
            int n=word.size();
            return search(root,word,0,n);
        }
        
    };
    static bool compare(const string &a,const string &b){
        return a.size()>b.size();
    }
    int minimumLengthEncoding(vector<string>& words) {
        int n=words.size();
        Trie obj;
        int res=0;
        sort(words.begin(),words.end(),compare);
        for(auto &i:words){
            if(obj.search(i)==true)continue;
            string prefix;
            for(int j=i.size()-1;j>=0;j--){
                prefix=i.substr(j);
                obj.insert(prefix);
            }
            res+=(i.size()+1);
            cout<<i<<" "<<i.size()<<" "<<res<<" ";
        }
        cout<<endl;
        return res;
    }
};