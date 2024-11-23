//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        // code here
       
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int ans = arr[n-1] - arr[0];
        int tempmin, tempmax;

        for (int i = 1; i < n; i++) {
        tempmin = min(arr[0] + k, arr[i]-k);
        tempmax = max(arr[n-1] - k, arr[i-1] + k);
        ans = min(ans, tempmax - tempmin);
        }

        return ans;
        }
    
    };

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends