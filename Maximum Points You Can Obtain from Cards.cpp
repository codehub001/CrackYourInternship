class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int leftSum = 0, rightSum = 0, maxSum = 0;
        for(int i = 0; i < k; i++) 
            leftSum += cardPoints[i];
        maxSum = leftSum;

        for(int leftIdx = k-1, rightIdx = n-1; leftIdx >= 0; leftIdx--, rightIdx--){
            leftSum -= cardPoints[leftIdx];
            rightSum += cardPoints[rightIdx];
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};
