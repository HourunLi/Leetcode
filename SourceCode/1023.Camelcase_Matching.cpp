class Solution {
private:
    int patternSize;
public:
    bool canMatch(string &item, string &pattern) {
        int itemSize = item.size();
        int i = 0, j = 0;
        while(i <= patternSize && j < itemSize) {
                if(i != patternSize && pattern[i] == item[j]) 
                    i++, j++;
                else if(islower(item[j]))
                    j++;
                else 
                    return false;
        }
        if(i == patternSize && j == itemSize) return true;
        return false;
    }
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        patternSize = pattern.size();
        for(auto &item : queries) {
            if(canMatch(item, pattern))
                ret.emplace_back(true);
            else 
                ret.emplace_back(false);
        }
        return ret;
    }
};