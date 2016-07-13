//
//  solution_13.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/13.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/*Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 * */

#ifndef LeetCode_solution_13_h
#define LeetCode_solution_13_h

#include<iostream>
using namespace std;

class Solution{
    public:
        int getRomanValue(char c){
            if(c == 'I')    return 1;
            else if(c == 'V')   return 5;
            else if(c == 'X')   return 10;
            else if(c == 'L')   return 50;
            else if(c == 'C')   return 100;
            else if(c == 'D')   return 500;
            else if(c == 'M')   return 1000;
            else return 0;
        }
        int romanToInt(string s){
            if(s.length() < 1) return 0;
            int result = 0;
            int sub = getRomanValue(s[0]);
            int pre = sub;
            for(int i = 1; i < s.length(); i ++){
                int cur = getRomanValue(s[i]);
                if(cur == pre){
                    sub += cur;
                }else if(cur < pre){
                    result += sub;
                    sub = cur;
                }else{
                    sub = cur - sub;
                }
                pre = cur;
            }
            result += sub;
            return result;
        }
};
#endif
