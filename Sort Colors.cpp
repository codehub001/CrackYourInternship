class Solution {public:
    //Count the 0, 1 and 2
    //Approach 1
    // void sortColors(vector<int>& nums) {
    //     int zero = 0;
    //     int one = 0;
    //     int two = 0;

    //     for(int i = 0; i < nums.size(); i++){
    //         if(nums[i] == 0){
    //             zero++;
    //         }
    //         else if(nums[i] == 1){
    //             one++;
    //         }
    //         else{
    //             two++;
    //         }
    //     }
    //     int i = 0;
    //     while(zero--){
    //         nums[i++] = 0;
    //     }
    //     while(one--){
    //         nums[i++] = 1;
    //     }
    //     while(two--){
    //         nums[i++] = 2;
    //     }    
    // }
    //Approach 2
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = nums.size() - 1;
        while (w <= b){
            if (!nums[w])
                swap(nums[r++], nums[w++]);
            else if (nums[w] == 1)
                w++;
            else
                swap(nums[w], nums[b--]);
        }
    }
};
