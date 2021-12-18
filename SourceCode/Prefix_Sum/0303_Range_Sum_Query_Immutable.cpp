class NumArray {
private:
  int n;
  int *arr;
public:
  NumArray(vector<int>& nums) {
    n = nums.size();
    arr = (int*)malloc(n * sizeof(int));
    if(n) 
      arr[0] = nums[0];
    for(int i = 1; i < n; i++) {
      arr[i] = arr[i-1] + nums[i];
    }
    return;
  }
  
  int sumRange(int left, int right) {
    if(left)
      return arr[right] - arr[left-1];
    return arr[right];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */