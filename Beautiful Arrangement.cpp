class Solution {
public:
    int ans = 0 , siz;
    void solve(vector<int>& arr, int i){
        if(i > siz){
            ans++;
            return;
        } 
        for(int ind = i;  ind <= siz; ind++){
            if(arr[ind] % i == 0 || i % arr[ind] == 0){
                swap(arr[i], arr[ind]);
                solve(arr, i + 1);
                swap(arr[i], arr[ind]);
            }
        }
    }
    int countArrangement(int n) {
        vector<int> arr(n+1);
        siz = n;
        for(int i = 1; i <= n; i++){
            arr[i] = i;
        }
        solve(arr, 1);
        return ans;
    }
};
