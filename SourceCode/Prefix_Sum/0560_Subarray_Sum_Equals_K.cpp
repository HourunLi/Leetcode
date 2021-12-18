class Solution {
private:
  int *arr;
public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int prefix = 0;

    int ret = 0;
    map<int, int> memo;
    memo[0] = 1;
    for(int i  = 0; i < n; i++) {
      prefix += nums[i];
      if(memo.find(prefix-k) != memo.end()) {
        ret += memo[prefix-k];
      }
      //! this express has poor performance
      // ret += memo[prefix-k];
      memo[prefix]++;
    }
    return ret;
  }
};

/*optimized*/
class Solution {
private:
  int *arr;
public:
  int subarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int prefix = 0;

    int ret = 0;
    unordered_map<int, int> memo;
    memo[0] = 1;
    for(int &i : nums) {
      prefix += i;
      if(memo.find(prefix-k) != memo.end()) {
        ret += memo[prefix-k];
      }
      //! this express has poor performance
      // ret += memo[prefix-k];
      memo[prefix]++;
    }
    return ret;
  }
};