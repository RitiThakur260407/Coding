class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> mpp;
        int m = s.length();
        int n = t.length();

        for (int i = 0; i < n; i++) {
            mpp[t[i]]++;
        }

        int l = 0, r = 0, minLen = INT_MAX, start = -1, count = 0;
        while (r < m) {
            if (mpp[s[r]] > 0) {
                count++;
            }
            mpp[s[r]]--;

            while (count == n) {
                int len = r - l + 1;
                if (len < minLen) {
                    minLen = len;
                    start = l;
                }
                if (mpp[s[l]] >= 0) {
                    count--;
                }
                mpp[s[l]]++;
                l++;
            }

            r++;
        }
        if(start == -1)
        {
            return "" ;
        }
        
        string minimum = s.substr(start,minLen) ;

        return minimum ;
    }
};