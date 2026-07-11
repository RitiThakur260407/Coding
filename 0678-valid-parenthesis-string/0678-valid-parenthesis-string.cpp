class Solution {
public:
    bool checkValidString(string s) {
        int mini = 0, maxi = 0;
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                mini++;
                maxi++;
            } else if (s[i] == ')') {
                if (mini >= 1) {
                    mini--;
                }
                if (maxi >= 1) {
                    maxi--;
                } else {
                    return false;
                }
            } else {
                if (mini >= 1) {
                    mini--;
                }
                maxi++;
            }
        }
        return (mini == 0) ;
    }
};