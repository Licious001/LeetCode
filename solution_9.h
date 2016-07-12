//
//  solution_9.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/12.
//  Copyright (c) 2015年 李鑫. All rights reserved.

//  Determine whether an integer is a palindrome. Do this without extra space.

#ifndef LeetCode_solution_9_h
#define LeetCode_solution_9_h

#include<iostream>
using namespace std;

class Solution{
    public:
        bool isPalindrome(int x){
            long y = 0;
            int z = x;
            while(x > 0){
                int c = x % 10;
                y = y*10 + c;
                x = x / 10;
            }
            return y == z;
        }
};

#endif
