class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
    stack<int>st;
    unordered_set<int>se;
    int n =s.length();
    for (int i =0;i<n;i++)
    {
        if (s[i]=='(')
        st.push(i);
        else if (s[i]==')')
        {
            if (st.empty())
            se.insert(i);
            else 
            st.pop();
        }
    }
    while(!st.empty())
    {
        se.insert(st.top());
        st.pop();
    }
    string res="";
    for (int i =0;i<n;i++)
    {
        if (se.find(i)==se.end())
        res+=s[i];
    }
    return res;    
    }
};