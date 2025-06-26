// User function Template for C++

class Solution {
  public:
    bool isPalindrome(int n) {
        // Code here.
        int temp=n;
        int rev=0;
        while(n>0){
            int ld=n%10;
            rev=rev*10+ld;
            n=n/10;
        }
        if(rev==temp){
            return true;
        }
        return false;
    }
};
