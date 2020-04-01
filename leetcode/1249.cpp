class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<vector<int>> st;
        for(int i=0; i<s.length(); i++) {
            vector<int> v = vector(2, 0);
            if(s[i] == '(') { // '(' == 1
                v[0] = 1 ; v[1] = i;
                st.push(v);
            }
            else if(s[i] == ')') { // ')' == 2
                if(!st.empty() && st.top()[0] == 1) st.pop();
                else {
                    v[0] = 2; v[1] = i;
                    st.push(v);
                }
            }
        }
        while(!st.empty()) {
            int tmp = st.top()[1];
            st.pop();
            s.erase(tmp, 1);
        }
        return s;
    }
};
