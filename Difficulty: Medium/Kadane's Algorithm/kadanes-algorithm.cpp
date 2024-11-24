//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find the sum of contiguous subarray with maximum sum.
    int maxSubarraySum(vector<int> &arr) {
        
        // code here...
        
        int max_current = arr[0];  
        int max_global = arr[0];   

        for (size_t i = 1; i < arr.size(); ++i) {
         
        if (max_current + arr[i] > arr[i]) {
            max_current = max_current + arr[i];
        } else {
            max_current = arr[i];
        }

        
        if (max_current > max_global) {
            max_global = max_current;
        }
    }

    return max_global;
}
    
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.maxSubarraySum(arr) << endl;
    }
}
// } Driver Code Ends