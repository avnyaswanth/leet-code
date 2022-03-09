class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<int> ans;
        unordered_map<char, int> mp;
        
        for(auto ch : p)
            mp[ch]++;
        
        int count = mp.size();
        
        int i = 0, j = 0;
        while(j < n)
        {
            if(mp.find(s[j]) != mp.end())
            {
                mp[s[j]]--;
                if(mp[s[j]] == 0)
                    count--;
            }
            if(j - i + 1 == m)
            {
                if(count == 0)
                    ans.push_back(i);
                if(mp.find(s[i]) != mp.end())
                {
                  if(mp[s[i]] == 0)
                      count++;
                  mp[s[i]]++;
                }
                i++;
                j++;
            }
            else j++;
        }
        return ans;
    }
};