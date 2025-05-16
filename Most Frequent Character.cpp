class Solution {
  public:
    // Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string& s) {
        // Your code here
        int n=s.size();
        int freq[26]={0};
        
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        
        int maxi=-1; 
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i] > maxi ){
                maxi=freq[i];
                ans=i;
            }
        }
        return 'a' + ans;
    }
};
