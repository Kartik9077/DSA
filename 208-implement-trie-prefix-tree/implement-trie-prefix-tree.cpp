class TrieNode {
public:
TrieNode *child[26];
bool endword;
TrieNode(){
    endword=false;
    for(int i=0;i<26;i++)
        child[i]=NULL;
    }
};
class Trie{
    public:
     TrieNode * root;
    Trie() {
        root=new TrieNode();
      } 
    
    
    void insert(string word) {
       TrieNode *node=root;
       for(char c:word){
        if(node->child[c-'a']==NULL)
            node->child[c-'a']=new TrieNode();
            node=node->child[c-'a'];
       } 
       node->endword=true;
    }
    
    bool search(string word) {
     TrieNode * node=root;
     for(char c:word){
        if(node->child[c-'a']==NULL)return 0;
        else node=node->child[c-'a'];
     }
     return node->endword;   
    }
    
    bool startsWith(string prefix) {
       TrieNode * node=root;
       for(char c: prefix){
        if(node->child[c-'a']==NULL)return 0;
        else node=node->child[c-'a'];
       } 
       return true;
    }
};

