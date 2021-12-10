#include <bits/stdc++.h>
using namespace std;
/*brute method*/
char *getLongestOddString(char *s, int length)
{
    int ans = 0;
    int l = 0, r = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if ((j + i) >= length)
                break;
            if (s[i - j] != s[i + j])
                break;
            if (2 * j + 1 > ans)
            {
                ans = 2 * j + 1;
                l = i;
                r = j;
            }
        }
    }
    char *ret = (char *)malloc(sizeof(char) * (2 * r + 1 + 1));
    memset(ret, 0, sizeof(char) * (2 * r + 1 + 1));
    strncpy(ret, s + l - r, 2 * r + 1);
    return ret;
}

char *getLongestEvenString(char *s, int length)
{
    int ans = 0;
    int l = 0, r = 0;
    for (int i = 1; i < length; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if ((j + i) > length)
                break;
            if (s[i - j] != s[i + j - 1])
                break;

            if (2 * j > ans)
            {
                ans = 2 * j;
                l = i;
                r = j;
            }
        }
    }
    if (!r)
        return NULL;
    char *ret = (char *)malloc(sizeof(char) * (2 * r + 1));
    memset(ret, 0, sizeof(char) * (2 * r + 1));
    strncpy(ret, s + l - r, 2 * r);
    return ret;
}

char *longestPalindrome(char *s)
{
    int length = strlen(s);
    if (length == 0 || length == 1)
        return s;
    char *even = getLongestEvenString(s, length);
    char *odd = getLongestOddString(s, length);
    if (!even)
        return odd;
    if (!odd)
        return even;
    if (strlen(even) < strlen(odd))
        return odd;
    else
        return even;
}
/*
    * immport annotation
    ! deprecated
    ? asd
    
*/
int main(){
    char s[] = "SOD";
    longestPalindrome(s);//todo :get aa 
    return 0;
}