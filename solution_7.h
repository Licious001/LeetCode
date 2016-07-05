//
//  solution_7.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/05.
//  Copyright (c) 2015年 李鑫. All rights reserved.

#ifndef LeetCode_solution_7_h
#define LeetCode_solution_7_h

#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
class Solution{
    public:
        int reverse(int x){
            bool negative = (x < 0);
            int absX = abs(x);
            int result = 0;
            while(absX > 0){
                int d = absX % 10;
                if(result > INT_MAX / 10) return 0;
                result = result * 10 + d;
                absX = absX / 10;
            }
            if(negative) return -result;
            else return result;   
        }
};
#endif

