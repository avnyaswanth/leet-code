struct Node {
    
    Node *links[26];
    int pc, ec;
    
    Node()
    {
        pc = 0;
        ec = 0;
        memset(links, NULL, sizeof(links));
    }
    
    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }
    
    void putKey(char ch, Node *node)
    {
        links[ch-'a'] = node;
    }
    
    Node* moveNext(char ch)
    {
        return links[ch-'a'];
    }
    
    void increasePrefix()
    {
        pc++;
    }
    
    void increaseEnd()
    {
        ec++;
    }
};

class Trie {
    
    public : 
    
    Node *root;
    
    public :
    
    Trie() 
    {
        root = new Node();
    }
    
    void insert(string str)
    {
        int n = str.length();
        Node *node = root;
        for(int i=0;i<n;++i)
        {
            if(!node->containsKey(str[i]))
                node->putKey(str[i], new Node());
            node = node->moveNext(str[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        Trie t;
        for(int i=0;i<n;++i)
            t.insert(strs[i]);
        Node *node = t.root;
        string ans = "";
        int m = strs[0].length();
        int i = 0;
        while(i < m)
        {
            node = node->moveNext(strs[0][i]);
            if(node->pc != n)
                break;
            ans.push_back(strs[0][i]);
            i++;
        }
        return ans;
    }
};