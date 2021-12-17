/* solution1
class Solution {
public:
    int countVowelStrings(int n) {
        int vis[6];
        for(int i = 0 ; i < 6; i++) 
            vis[i] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 5; j>=0; j--) {
                for(int k = 1; k <j; k++) {
                    vis[j] += vis[k];
                }
            }
        }


        return vis[5];
    }
};
*/

/*solution2*/
class Solution {
public:
    int countVowelStrings(int n) {
        int vis[6];
        vis[0]=0;
        for(int i = 1 ; i < 6; i++) 
            vis[i] = 1;
        
        for(int i = 0; i < n; i++) {
            for(int j = 1; j <=5; j++) {
                vis[j]  += vis[j-1];
            }
        }
        return vis[5];
    }
};