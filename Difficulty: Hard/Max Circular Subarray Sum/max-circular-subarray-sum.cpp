//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    int circularSubarraySum(vector<int> &arr) {

        int n=arr.size();
        int max_kadane=arr[0];
        int curr_max=arr[0];
        
        for(int i=1; i<n; i++){
            
            curr_max= max(arr[i], curr_max+arr[i]);
            max_kadane= max(max_kadane, curr_max);
        }
        
        
        int total_sum= accumulate(arr.begin(), arr.end(), 0);
        
        
        int min_kadane= arr[0];
        int curr_min= arr[0];
        
        for(int i=1; i<n; i++){
            curr_min=min(arr[i], curr_min+arr[i]);
            min_kadane=min(min_kadane, curr_min);
        }
        
        int max_wraparound= total_sum - min_kadane;
        
        
        if(min_kadane == total_sum){
            return max_kadane;
        }
        
        return max(max_kadane, max_wraparound);
        
        
    }
    
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends