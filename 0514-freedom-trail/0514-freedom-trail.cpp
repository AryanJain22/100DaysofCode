class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<pair<int, int>> s[128], x{make_pair(0, 0)};
        int rS = ring.size(), res = INT_MAX;
        for(int i = 0; i < rS; ++i) s[ring[i]].push_back(make_pair(i, 0));
        for(int c : key) {
            for(int i = 0; i < s[c].size(); ++i) {
                int minDis = INT_MAX, pos = s[c][i].first;
                for(int j = 0; j < x.size(); ++j) {
                    int dis = abs(x[j].first - pos);
                    minDis = min(minDis, x[j].second + min(dis, rS-dis));
                }
                s[c][i].second = minDis;
            }
            x = s[c];
        }
        for(int i = 0; i < x.size(); ++i) res = min(res, x[i].second);
        return res + key.size();
    }
};