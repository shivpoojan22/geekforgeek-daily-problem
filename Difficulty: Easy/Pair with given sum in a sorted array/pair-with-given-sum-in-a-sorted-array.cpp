//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n = arr.size();
        int i = 0, j = n - 1;
        int ans = 0;

        while (i < j) {
        int sum = arr[i] + arr[j];
        if (sum == target) {
            ans++;
            int st = i + 1;
            int e = j - 1;

            while (st < j && arr[st] + arr[j] == target) {
                ans++;
                st++;
            }

            while (e > i && arr[e] + arr[i] == target) {
                ans++;
                e--;
            }

            i++;
            j--;
        } else if (sum > target) {
            j--;
        } else {
            i++;
        }
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
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends