class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<>> minHeap;
        int n = matrix.size();
        for(int i = 0; i < min(n, k); i++){
            minHeap.push({matrix[i][0], i, 0});
        }
        for(int i = 1; i < k; i++){
            vector<int> temp = minHeap.top();
            minHeap.pop();
            temp[2]++;
            if(temp[2] < n){
                temp[0] = matrix[temp[1]][temp[2]];
                minHeap.push(temp);
            }
        }
        return minHeap.top()[0];
    }
};
