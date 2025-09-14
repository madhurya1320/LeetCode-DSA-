class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>st; int sum;
        for(string o : operations) {
        if(o == "+") {
            int s1 = st.top(); st.pop();
            int y = s1 + st.top(); st.push(s1); st.push(y);
            sum = sum + y;
        } else if(o == "D"){
            int x = 2*st.top();
            sum = sum + x;
            st.push(x);

        } else if(o == "C") {
            sum = sum - st.top();
            st.pop();
        }
        else {
            st.push(stoi(o));
            sum = sum + st.top(); 
        }
    }
    return sum;
    }
};