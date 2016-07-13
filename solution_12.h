//
//  solution_12.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/13.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/*Given an integer, convert it to a roman numeral.
 * Input is guaranteed to be within the range from 1 to 3999.
 * */

#ifndef LeetCode_solution_12_h
#define LeetCode_solution_12_h

#include<iostream>
using namespace std;

class Solution{
    public:
        string intToRoman(int num){
            string s[4][10] = {
                {"","I","II","III","IV","V","VI","VII","VIII","IX"},
                {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
                {"","M","MM","MMM"}
            };
            string result = "";
            result.append(s[3][num/1000%10]);
            result.append(s[2][num/100%10]);
            result.append(s[1][num/10%10]);
            result.append(s[0][num%10]);
            return result;
        }
};

#endif
