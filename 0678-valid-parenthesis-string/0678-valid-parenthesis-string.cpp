class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st;
        set<int> mp;
        int c=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='*'){
                mp.insert(i);
            }
            else if(s[i]=='('){
                st.push(i);
            }
            else{
                if(!st.empty()){
                   st.pop();
                }
                else{
                    if(mp.size()){
                        if(i>*mp.begin())
                        mp.erase(*mp.begin());
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        if(st.empty())
        return true;
        while(!st.empty()){
            int f=0;
            for(auto it:mp){
                if(st.top()<it){
                    mp.erase(it);
                    f=1;
                    break;
                }
            }
            if(!f)
            return false;
            st.pop();
        }
        return true;

    }
};