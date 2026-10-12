class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
         int n = students.size(); 
        queue<int> q;
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(sandwiches[n-i-1]);
            q.push(students[i]);
        }
        int last=0;
        while(q.size()>0 && last < q.size()){
            if(st.top()==q.front()){
                st.pop();
                q.pop();
                last=0;
            }else{
                q.push(q.front());
                q.pop();
                last++;
            }
        }
        return q.size();
    }
};