class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        int shash[26], phash[26];
        memset(shash, 0, sizeof(shash));
        memset(phash, 0, sizeof(phash));
        for(int i=0;i<m;++i)
            phash[p[i]-'a']++;
        int i = 0, j = 0;
        while(j < n)
        {
            shash[s[j]-'a']++;
            if(j - i + 1 == m)
            {
                bool flag(1);
                for(int k=0;k<26;++k)
                {
                    if(shash[k] != phash[k])
                    {
                        flag = 0;
                        break;
                    }
                }
                if(flag)
                    ans.push_back(i);
                shash[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};