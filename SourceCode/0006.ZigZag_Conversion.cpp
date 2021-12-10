/*mathmatical C method*/
char * convert(char * s, int numRows){
    int cnt = 0;
    if(numRows == 1) return s;
    int len = strlen(s);
    char *ret = (char *)malloc(len * sizeof(char)+5);
    memset(ret, 0, len+5);
    int cycle = 2 * numRows - 2;
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j + i <len; j += cycle){
            ret[cnt++] = s[i+j];
            if(i!=0 && i != numRows - 1 && j+cycle-i < len){
                ret[cnt++] = s[j+cycle-i];  
            }
        }
    }
    return ret;
}

/*mathmatical C++ method*/
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ret;
        int len = s.size();
        int cycle = 2 * numRows - 2;
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j + i <len; j += cycle){
                ret += s[i+j];
                if(i!=0 && i != numRows - 1 && j+cycle-i < len){
                    ret += s[j+cycle-i];  
                }
            }
        }
        return ret;      
    }
};

/*simulation C++ method*/
//How to utilize sting and vector????
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        string ret;
        bool down = false;
        vector<string> rows(numRows < s.size() ? numRows : s.size());
        int len = s.size(), num = 0;
        for(char c: s) {
            rows[num] += c;
            if(num == 0 || num == numRows-1) down = !down;
            num += down ? 1 : -1;
        }
        for(int i = 0; i < numRows; i++) {
            ret += rows[i];
        }
        return ret;
    }
};