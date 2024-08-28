class SegmentTree{    
private:
    vector<int> arr;
public:
    SegmentTree(int n){
        arr.assign(n*4+1, 0);
    }
    void build(int i, vector<int>& nums, int l, int r){
        if(l == r){
            arr[i] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        build(2*i+1, nums, l, mid);
        build(2*i+2, nums, mid+1, r);
        arr[i] = arr[2*i+1] + arr[2*i+2];
    }
    int sumRange(int i, int sl, int sr, int l, int r){
        // cout<<sl<<" "<<sr<<endl;
        if(l <= sl && r >= sr) return arr[i];
        if(r < sl || l > sr) return 0;
        int mid = (sl + sr)/2;
        return sumRange(2*i+1, sl, mid, l, r) + sumRange(2*i+2, mid+1, sr, l, r);
    }
    void update(int i, int sl, int sr, int index, int diff){
        if(index < sl || index > sr) return;
        arr[i] += diff;
        if(sl == sr) return;
        int mid = (sl + sr)/2;
        update(2*i+1, sl, mid, index, diff);
        update(2*i+2, mid+1, sr, index, diff);
    }
};
class NumArray {
    SegmentTree* seg;
    vector<int> nums;
public:
    NumArray(vector<int>& nums) {
        seg = new SegmentTree(nums.size());
        this->nums = nums;
        seg->build(0, nums, 0, nums.size()-1);
    }
    
    void update(int index, int val) {
        seg->update(0, 0, nums.size()-1, index, val-nums[index]);
        nums[index] = val;
    }
    
    int sumRange(int left, int right) {
        // cout<<"____________________________"<<endl;
        return seg->sumRange(0, 0, nums.size()-1, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
