// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> vp;
        for(int i=0;i<n;++i)
            vp.push_back(make_pair(end[i], start[i]));
        sort(vp.begin(), vp.end());
        int ans = 1;
        int lastmeeting = vp[0].first;  // end time of last meeting
        for(int i=1;i<n;++i)
        {
            if(vp[i].second > lastmeeting)  // if start time of current meeting greater than end time of lastmeeting
                ans++, lastmeeting = vp[i].first;
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends