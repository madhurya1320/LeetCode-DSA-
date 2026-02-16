class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>s(deadends.begin(), deadends.end());
        if(s.count("0000")) return -1;

        queue<pair<string, int>>q;
        q.push({"0000", 0});
        s.insert("0000");

        while(!q.empty()) {
            auto [lock, turns] = q.front();
            q.pop();

            if(lock == target) return turns;
            for(auto i : child(lock)) {
                if(!s.count(i)) {
                    s.insert(i);
                    q.push({i, turns + 1});
                }
            }

        }
        return -1;

    }

        vector<string>child(string lock) {
            vector<string>res;

           for(int i = 0; i<4; i++) {
            string next = lock;
            next[i] = (next[i] - '0' + 1) % 10 + '0';
            res.push_back(next);

            next = lock;

            next[i] = (next[i] - '0' - 1 + 10) % 10 + '0';
            res.push_back(next);

           }
           return res;
        }
};