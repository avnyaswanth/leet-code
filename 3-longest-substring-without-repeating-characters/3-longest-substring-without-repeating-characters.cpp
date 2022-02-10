class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        if(n == 0)
            return 0;
        vector<int> mp(256, -1);
        int left = 0, right = 0, ans = 0;
        while(right < n)
        {
            char r = s[right];
            int index = mp[r];
            if(index != -1 and index >=left and index < right)
                left = index + 1;
            ans = max(ans, right-left+1);
            mp[r] = right;
            right++;
        }
        return ans;
    }
};