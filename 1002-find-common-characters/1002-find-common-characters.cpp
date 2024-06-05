class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int n=words.size();
        vector<string> ans;
        vector<vector<int>> map(n, vector<int>(26,0));
        for(int i=0; i<n; ++i){
            for(int j=0; j<words[i].size(); ++j){
                map[i][words[i][j]-'a']++;
            }
        }
        for(int k=0; k<26; ++k){
            int minVal=INT_MAX;
            for(int i=0; i<n; ++i){
                minVal=min(minVal,map[i][k]);
            }
            while(minVal>0){
                string t;
                t.push_back('a'+k);
                ans.push_back(t);
                minVal--;
            }
        }
        return ans;
    }
};