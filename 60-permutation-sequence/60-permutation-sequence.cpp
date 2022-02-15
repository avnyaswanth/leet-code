class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "";
        for(int i=1;i<=n;++i)
            str += '0' + i;
        string ans = "";
        for(int i=2;i<=k;++i)
            next_permutation(str.begin(), str.end());
        ans = str;
        return ans;
    }
};