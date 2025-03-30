class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    int priority(char c){
        if(c == '^') return 3;
        if(c == '*' || c == '/') return 2;
        if(c == '+' || c == '-') return 1;
        
        return 0;  //for '('
    }
    string infixToPostfix(string& s) {
        // Your code here
        int i=0;
        stack<char> st;
        string ans="";
        while(i<s.size()){
            if((s[i] >= 'A' && s[i] <='Z') ||
               (s[i] >= 'a' && s[i] <='z') ||
               (s[i] >= '0' && s[i] <='9')){
                  ans+=s[i];
             }
             else if(s[i] == '('){
                 st.push(s[i]);
             }
             else if(s[i] == ')'){
                 while( !st.empty() && st.top() != '('){
                     ans+=st.top();
                     st.pop();
                 }
                 st.pop();       //pop the opening bracket (
             }
             else{
                 while( !st.empty() && priority(s[i]) <= priority(st.top())){
                     ans+=st.top();
                     st.pop();
                 }
                 st.push(s[i]);
             }
             i++;
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};

// Infix to Postfix

