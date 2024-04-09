class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res = 0;
        int v = tickets[k];
        
        for (int i = 0; i < tickets.size(); ++i) {
            if (i == k + 1) --v;
            res += min(tickets[i], v);
        }
        
        return res;
    }
};