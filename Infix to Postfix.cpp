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

// Given an infix expression in the form of string s. Convert this infix expression to a postfix expression.

// Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
// Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
// Note: The order of precedence is: ^ greater than * equals to / greater than + equals to -. Ignore the right associativity of ^.

// Examples :

// Input: s = "a+b*(c^d-e)^(f+g*h)-i"
// Output: abcd^e-fgh*+^*+i-
// Explanation: After converting the infix expression into postfix expression, the resultant expression will be abcd^e-fgh*+^*+i-
// Input: s = "A*(B+C)/D"
// Output: ABC+*D/
// Explanation: After converting the infix expression into postfix expression, the resultant expression will be ABC+*D/
// Input: s = "(a+b)*(c+d)"
// Output: ab+cd+*
// Constraints:
// 1 ≤ s.length ≤ 30

