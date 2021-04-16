class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>> st;
        int n = s.length();
        for(int i = n-1; i>=0; i--) {
            char ch = s[i];
            if(st.empty() || st.top().first != ch)
                st.push({ch, 1});
            else {
                st.top().second++;
                if(st.top().second == k) {
                    st.pop();
                }
            }
        }
        
        string result = "";
        while(!st.empty()) {
            int x   = st.top().second;
            char ch = st.top().first;
            while(x--)
                result += ch;
            st.pop();
        }
        
        return result;
    }
};
