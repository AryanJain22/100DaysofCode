class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int ans=1;
        int l=points[0][0];//initialize the left
        int r=points[0][1];//intitialize the right
        int n=points.size();
        for(auto i:points)
        {
            l=max(i[0],l);
            r=min(i[1],r);//find the intersection
            if(l>r)//no intersection found
            {
                ans++;// new arrow needed
                l=i[0],r=i[1];//reset the range to the current interval
            }
        }
        return ans;
    }
};