class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        int n = s.size();
        int ans = 0;
        if(s.size() == 1)return stoi(s[0]);
        for(int i = 0;i < n;i++) {
            if(s[i] != "+" && s[i] != "-" && s[i] != "/" && s[i] != "*") {
                st.push(stoi(s[i]));
            }else {
                if(s[i] == "+") {
                    int f = st.top();st.pop();
                    int s = st.top();st.pop();
                    ans = (f + s);
                    st.push(f + s);
                }else if(s[i] == "-") {
                    int f = st.top();st.pop();
                    int s = st.top();st.pop();
                    ans = (s - f);
                    st.push(s - f);
                }else if(s[i] == "/") {
                    int f = st.top();st.pop();
                    int s = st.top();st.pop();
                    ans = (s/f);
                    st.push(s/f);
                }else if(s[i] == "*") {
                    int f = st.top();st.pop();
                    int s = st.top();st.pop();
                    ans = (f * s);
                    st.push(f * s);
                }
            }
        }
        return ans;
    }
};