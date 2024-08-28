class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0;
        int j=0;
        while(i<m && j<n){
            if (nums1[i]>nums2[j]){
                shift(nums1,i,m-1);
                nums1[i]=nums2[j];
                m++;
                j++;
            }
            i++;
        }
        while(j<n){
            nums1[i++]=nums2[j++];
        }
    }

    void shift(vector<int>& nums1, int start, int end){
        for(int i=end; i>=start; i--){
            nums1[i+1]=nums1[i];        }
    }
};
