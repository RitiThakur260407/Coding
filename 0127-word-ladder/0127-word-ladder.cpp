class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        unordered_set<string> st;
        for (int i = 0; i < wordList.size(); i++) {
            st.insert(wordList[i]) ;
        }

        if (st.find(endWord) == st.end()) {
            return 0;
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        if (st.find(beginWord) != st.end()) {
            st.erase(beginWord);
        }


        while (!q.empty()) {
            string curr = q.front().first;
            int level = q.front().second;

            q.pop();

            if(curr == endWord)
            return level ;

            for (int i = 0; i < curr.size(); i++) {
                char ch=curr[i];
                for (int j = 0; j < 26; j++) {
                    curr[i] = j + 'a';

                    if (st.find(curr) != st.end()) {
                        st.erase(curr);
                        q.push({curr, level + 1});
                    }
                }
                curr[i]=ch;
            }
        }

        return 0;
    }
};