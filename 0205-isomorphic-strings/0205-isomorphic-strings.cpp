class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char a[130];
        char b[130];
        for(int i=0;i<26;i++){
            a[i]=NULL;
            b[i]=NULL;
        }
        for(int i=0;i<s.length();i++){
            if(a[s[i]-' ']==NULL && b[t[i]-' ']==NULL){
                a[s[i]-' ']=t[i];
                b[t[i]-' ']=s[i];
            }
            else if(a[s[i]-' ']!=t[i] || b[t[i]-' ']!=s[i]){
                return false;
            }
        }
        return true;
    }
};