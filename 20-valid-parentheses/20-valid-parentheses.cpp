class Solution {
public:
    bool isValid(string s) {
        int n(s.length());
        stack<char> stk;
        map<char, char> mp;
        mp[')'] = '(';
        mp[']'] = '[';
        mp['}'] = '{';
        for(int i=0;i<n;++i)
        {
            char ch = s[i];
            if(ch == '[' || ch == '{' || ch =='(')
                stk.push(ch);
            else
            {
                if(!stk.empty() && mp[ch] == stk.top())
                    stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};