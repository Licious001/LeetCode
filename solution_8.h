//
//  solution_8.h
//  LeetCode
//
//  Created by 李鑫 on 15/10/14.
//  Copyright (c) 2015年 李鑫. All rights reserved.

#ifndef LeetCode_solution_8_h
#define LeetCode_solution_8_h

#include<iostream>
#include<cctype>
using namespace std;

class  Solution{
    public:
        int myAtoi(string str){
            int res = 0;
            bool flag = false;
            bool sign = true;
            bool overflow = false;
            string s = "";
            for(int i = 0;i < str.length(); i ++){
                char c = str[i];
                if(isspace(c)){if(flag) break;else continue;}
                else if(isdigit(c)){flag = true; if (res > (INT_MAX-c+'0') /10) {overflow = true; break;}res = res*10 + c - '0';}
                else if(c == '+' || c == '-'){if(flag) break;else {flag = true;sign = c == '+';}}
                else break;
            }
            if(overflow){
                if(sign)return INT_MAX;
                else return INT_MIN;
            }
            if(!sign) res = -res;
            if(res > INT_MAX) return INT_MAX;
            if(res < INT_MIN) return INT_MIN;
            return res;
        }
};

#endif
