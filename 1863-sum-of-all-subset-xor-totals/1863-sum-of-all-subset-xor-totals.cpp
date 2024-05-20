class Solution {
public:

    int sol(vector<int>&a,int i,int xorSum){
        if(i == a.size()){
            return xorSum;
        }
        int ans1 = sol(a,i+1,xorSum);
        xorSum = xorSum ^ a[i];
        int ans2 = sol(a,i+1,xorSum);
        return ans1 + ans2;
    }

    int subsetXORSum(vector<int>& a) {
        return sol(a,0,0);   
    }
};