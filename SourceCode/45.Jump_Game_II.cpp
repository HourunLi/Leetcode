class Solution {
public:
    int jump(vector<int>& nums) {
        int range = 0, len = nums.size()-1, cnt = -1, num=0, cur = 0;
        if(!len) return 0;
        while(++cnt <= len) {
            int tem = nums[cnt] + cnt;
            if(tem >= len) return num + 1;
            if(tem > range) {
                range = tem;
            }
            if(cnt == cur){
                cur = range;
                num++;
            }
        }
        return -1;
    }
};