struct Node {
    Node *links[26];
    bool flag;

    bool containsKey(char ch)
    {
        return links[ch-'a'] != NULL;
    }
    
    Node *moveNext(char ch)
    {
        return links[ch-'a'];
    }
    
    void setEnd()
    {
        flag = true;
    }
    
    bool isEnd()
    {
        return flag;
    }
};

class Trie {
public:
    Node *root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(int i=0;i<word.length();++i)
        {
            if(!node->containsKey(word[i]))
            {
                node->links[word[i]-'a'] = new Node();
            }
            node = node->moveNext(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node *node = root;
        for(int i=0;i<word.length();++i)
        {
            if(!node->containsKey(word[i]))
                return false;
            node = node->moveNext(word[i]);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(int i=0;i<prefix.length();++i)
        {
            if(!node->containsKey(prefix[i]))
                return false;
            node = node->moveNext(prefix[i]);
        }
        return true;
    }
};