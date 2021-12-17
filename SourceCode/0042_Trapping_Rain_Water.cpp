/*brute method*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        for (int i = 1; i < n-1; i++) {
            int max_left = 0, max_right = 0;
            for(int j = i; j >= 0; j--) 
                max_left = max_left < height[j] ? height[j] : max_left;
            for(int j = i; j < n; j++) 
                max_right = max_right < height[j] ? height[j] : max_right;
            int h = max_left < max_right ? max_left : max_right;
            ans += h - height[i];
        }
        return ans;
    }
};

/*DP*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        int *max_left = new int[n], *max_right = new int[n];
        memset(max_left, 0, sizeof(int) *n);
        memset(max_right, 0, sizeof(int) *n);
        max_left[0] = height[0];
        max_right[n-1] = height[n-1];
        for(int i = 1; i < n; i++) 
            max_left[i] = max_left[i-1] > height[i] ? max_left[i-1] : height[i];
        for(int i = n-2; i >= 0; i--) 
            max_right[i] = max_right[i+1] > height[i] ? max_right[i+1] : height[i];
        
        for(int i = 1; i < n-1; i++) {
            int h = max_left[i] < max_right[i] ? max_left[i] : max_right[i];
            ans += h - height[i];
        }
        return ans;
    }
};
/*monotonic stack */
/*学会转换求解思路, 竖着不行横着来*/
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        stack<int> s;
        for(int i = 0; i < n; i++) {
            while(!s.empty() && height[i] > height[s.top()]) {
                int mid = s.top();
                s.pop();
                if(s.empty()) break;
                int left = s.top();
                int width = i - left - 1;
                int h = height[i] > height[left] ? height[left] - height[mid] : height[i] - height[mid];
                ans += h * width;
            }
            s.push(i);
        }
        return ans;
    }
};

/*monotonic stack 2*/
/*double pointer*/
//仔细分析更新条件，求解的数值是否是充分必要的
class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0, n = height.size();
        int l = 0, r = n-1;
        int left_max = height[l], right_max = height[r];
        while(l <= r) {
            if(left_max < right_max) {
                height[l] > left_max ? (left_max = height[l]) : (ans += left_max - height[l]);
                l++;
            }else{
                height[r] > right_max ? (right_max = height[r]) : (ans += right_max - height[r]);
                r--;               
            }
        }
        return ans;
    }
};