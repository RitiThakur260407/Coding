class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lost, won;
        for (int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            int loser = matches[i][1];
            if (lost.find(winner) == lost.end()) {
                won[winner]++;
            }
            if (won.find(loser) != won.end()) {
                won.erase(loser);
            }
            lost[loser]++;
        }
        vector<vector<int>> ans(2);
        for (auto it : won) {
            ans[0].push_back(it.first);
        }
        for (auto it : lost) {
            if (it.second == 1) {
                ans[1].push_back(it.first);
            }
        }
        return ans;
    }
};