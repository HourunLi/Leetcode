/*最大堆，最小堆*/
class MedianFinder {
priority_queue<int, vector<int>, less<int> > q_min; //从大到小
priority_queue<int, vector<int>, greater<int> > q_max; //从小到大
int cnt;
public:
    MedianFinder() {
        cnt = 2;
        q_min.push(INT_MIN);
        q_max.push(INT_MAX);
    }
    
    void addNum(int num) {
        //如果是奇数
        if(cnt & 1) {
            if(num <= q_min.top()) {
                q_max.push(q_min.top());
                q_min.pop();
                q_min.push(num);
            }else {
                q_max.push(num);
            }
        }else{ //如果是偶数
            if(num <= q_max.top()) {
                q_min.push(num);
            }else{
                q_min.push(q_max.top());
                q_max.pop();
                q_max.push(num);
            }
        }
        cnt++;
    }
    
    double findMedian() {
        if(cnt == 2) return -1;
        if(cnt & 1) return q_min.top();
        else return (q_min.top() + q_max.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

//如何利用数据结构--树？？
//相同元素是怎么存储的
/*二叉树，黑红二叉树，STL，保证有序*/
class cmp{
    bool operator ()(const int a, const int b) {
        return a <= b;
    }
};


class MedianFinder {
int cnt;
multiset<int>::iterator left, right;
multiset<int, cmp> tree;
public:
    MedianFinder() {
        cnt = 0;
        left = right = tree.end();
    }

    void addNum(int num) {
        tree.insert(num);
        if(!cnt) {
            left = right = tree.begin();
        }else if(cnt&1) { //如果是奇数
            if(num < *left) {
                left--;
            }else{
                right++;
            }
        }else{ //如果是偶数
            if(num < *left) {
                right--;
            }else if(num >= *right) {
                left++;
            }else{
                left++;
                right--;
            }
        }
        cnt++;
    }
    
    double findMedian() {
        return (*left + *right)/2.0;
    }
};