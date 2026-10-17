class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int ,int>> ans;

        ans.reserve(n);

        for(int i=0;i<n;i++){
            ans.push_back({position[i],speed[i]});

        }
        sort(ans.begin(),ans.end());
        stack<double> st;
        for(int i=0;i<n;i++){
            double time = (target - ans[i].first) / (double)ans[i].second;
            while(st.size()>0 && st.top()<= time){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};