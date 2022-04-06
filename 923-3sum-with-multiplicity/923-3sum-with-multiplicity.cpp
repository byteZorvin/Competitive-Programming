class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int n = arr.size(), mod = 1e9 + 7;
        
        long long int ans = 0;
        for(int i = 0; i<n-2; i++) {
            if(arr[i]>target) break;
            int sum = target-arr[i];
            int j = i+1, k = n-1;
            while(j<k) {
                if(arr[j] + arr[k] < sum)
                    j++;
                else if(arr[j] + arr[k] > sum) k--; 
                else {
                    if(arr[j] == arr[k]) {
                        ans = (ans + (k-j+1)*(k-j)/2)%mod;
                        break;
                    }
                    int a = 1, b= 1;
                    while(j+1<k && arr[j]==arr[j+1])
                        j++, a++;
                    while(k-1>j && arr[k]==arr[k-1]) 
                        k--, b++;
                    ans = (ans + a*b)%mod;
                    j++, k--;
                }
            }
        }
        return ans;
    }
};