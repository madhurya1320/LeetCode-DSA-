class Solution {
public:
    bool isValid(string str) {
    stack<char>st;
            for(auto s : str) {
                if(s == '(' || s =='{' || s == '[') {
                    st.push(s);
                } else {
                    if(st.size() == 0) {
                        return false;
                    } 
                    char ch = st.top();
                    st.pop();
                    if((s == ')' && ch == '(') || (s == ']' && ch == '[' )|| (s == '}' && ch == '{' )) {
                        continue;
                    } else {
                        return false;
                    }

                }
            }
           return st.empty();
    }
};