//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  bool isPossible(const vector<int> &arr, int n, int k, int maxPages) {
    int students = 1;
    int pagesSum = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > maxPages) {
            return false;
        }

        if (pagesSum + arr[i] > maxPages) {
            students++;
            pagesSum = arr[i];

            if (students > k) {
                return false;
            }
        } else {
            pagesSum += arr[i];
        }
    }

    return true;
}
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
    if (k > n) {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int result = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (isPossible(arr, n, k, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}
    
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends