#include<bits/stdc++.h>
using namespace std;
class Solution {
private:
const pair<int, string> valueSymbols[] = {
  {1000, "M"},
  {900,  "CM"},
  {500,  "D"},
  {400,  "CD"},
  {100,  "C"},
  {90,   "XC"},
  {50,   "L"},
  {40,   "XL"},
  {10,   "X"},
  {9,    "IX"},
  {5,    "V"},
  {4,    "IV"},
  {1,    "I"},
};
public:
  string intToRoman(int num) {
    string ret;
    for(const auto &[value, symbol] : valueSymbols) {
      while(num >= value) {
        num -= value;
        ret += symbol;
      }
      if(!num) 
        break;
    }
    return ret;
  }
};