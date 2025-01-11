//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        int maxLength = 0, start = 0;
        int freq[256] = {0};

        for (int end = 0; end < s.length(); ++end) {
                freq[s[end]]++;

            while (freq[s[end]] > 1) {
                freq[s[start]]--;
                start++;
        }

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends