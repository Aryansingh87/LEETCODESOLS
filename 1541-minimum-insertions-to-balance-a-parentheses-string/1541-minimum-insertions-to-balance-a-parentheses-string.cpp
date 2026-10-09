class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.length();
        int open = 0;
           for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                
            }else {
                if(i+1 < n && s[i+1]==')'){
                i++;
            }else{
                open++;
            }
                if(st.size()>0){
                    st.pop();
                }else{
                    open++;
                }
            }
           }
           open += 2*st.size();
           return open;
}
};