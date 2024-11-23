#User function Template for python3

class Solution:
    def getMinDiff(self,k, arr):
        # code here
        n = len(arr)
        if n == 1:
            return 0   

        
        arr.sort()

        
        ans = arr[-1] - arr[0]

         
        for i in range(1, n):
            
            max_height = max(arr[-1] - k, arr[i-1] + k)
            min_height = min(arr[0] + k, arr[i] - k)
            
            
            ans = min(ans, max_height - min_height)

        return ans



#{ 
 # Driver Code Starts
#Initial Template for Python 3
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        k = int(input())
        arr = list(map(int, input().strip().split()))
        solution = Solution()
        res = solution.getMinDiff(k, arr)
        print(res)
        print("~")

# } Driver Code Ends