class Solution {
public:
    bool isAnagram(string s, string t) {
        int freq[26];
        if(s.length() != t.length())
            return false;
        
        memset(freq, 0, sizeof(freq));
        for(int i=0;i<s.length();++i)
        {
            freq[s[i]-'a']++;
            freq[t[i]-'a']--;
        }
        for(auto num : freq)
            if(num < 0 || num > 1)
                return false;
        return true;
    }
};