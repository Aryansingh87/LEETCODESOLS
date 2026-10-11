class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.length()== k) return "0";

        string ans = "";
        for(char digit : num){
            while(k>0 && !ans.empty() && ans.back()>digit){
                ans.pop_back();
                k--;
            }
            ans.push_back(digit);
        }
        while(k > 0 && !ans.empty()){
            ans.pop_back();
            k--;
        }
        int stidx = 0;
        while(stidx < ans.length() && ans[stidx] == '0'){
            stidx++;
        }
        ans = ans.substr(stidx);
        return ans.empty() ? "0": ans;
    }
};