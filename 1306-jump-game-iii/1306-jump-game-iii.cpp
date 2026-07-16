class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();

        queue<int> q;
        q.push(start);
        vector<int> visited(n) ;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            if (arr[current] == 0) {
                return true;
            }

            if (current + arr[current] < n && (visited[current + arr[current]] == 0)) {
                q.push(current + arr[current]);
                visited[current + arr[current]] = 1 ;
            }
            if (current - arr[current] >= 0 && (visited[current - arr[current]] == 0)) {
                q.push(current - arr[current]);
                visited[current - arr[current]] = 1 ;
            }
        }
        return false;
    }
};