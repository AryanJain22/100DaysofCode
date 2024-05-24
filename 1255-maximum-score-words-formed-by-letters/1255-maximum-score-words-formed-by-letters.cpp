class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int>count(26,0);
        vector<int>letterscount(26,0);
        for(auto &c:letters){
            count[c-'a']++;
        }
        int ans=0;
        backtracking(words,score,count,letterscount,0,0,ans);
        return ans;
    }
    void backtracking(vector<string>&words,vector<int>&score,vector<int>&count,vector<int>&letterscount,int pos,int temp,int &ans){
        for(int i=0;i<26;i++){
            if(letterscount[i]>count[i]) return;
        }
        ans=max(ans,temp);
        for(int i=pos;i<words.size();i++){
            for(auto&c:words[i]){
                letterscount[c-'a']++;
                temp+=score[c-'a'];
            }
            backtracking(words,score,count,letterscount,i+1,temp,ans);
            for(auto&c:words[i]){
                letterscount[c-'a']--;
                temp-=score[c-'a'];
            }
        }
    }
};