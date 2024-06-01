class Solution {
public:
    int scoreOfString(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n-1;i++){
            char ch=s[i];
            char sh=s[i+1];
            int diff=abs((int)ch-(int)sh);
            ans+=diff;
        }
        return ans;
    }
};