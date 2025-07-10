class Solution {
public:
    #define ll long long
    struct Trie
    {
        unordered_map<int,Trie*>child;
        int count;
        Trie()
        {
            count=0;   
        }
    };
    void insert(Trie *root, string &s)
    {
        Trie *node=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int key=26*(s[i]-'a')+(s[n-1-i]-'a');
            if(node->child.find(key)==node->child.end())
                node->child[key]=new Trie();
            node=node->child[key];
            node->count++;    
        }
    }
    int search(Trie *root, string &s)
    {
        Trie *node=root;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            int key=26*(s[i]-'a')+(s[n-1-i]-'a');
            if(node->child.find(key)==node->child.end())
                return false;
            node=node->child[key]; 
        }
        return node->count;
    }
    long long countPrefixSuffixPairs(vector<string>& words) 
    {
        ll res=0;
        Trie *root=new Trie();
        for(int i=words.size()-1;i>=0;i--)
        {
            auto &word=words[i];
            res+=search(root,word);
            insert(root,word);
        }
        return res;
    }
};