
// Soluiton_4.h
// LeetCode

//  Created by 李鑫 on 15/10/14.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/* Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there 
 * exists one unique longest palindromic substring.
 */

#ifndef LeetCode_Solution_4_h
#define LeetCode_Solution_4_h

#include<vector>
#include<iostream>
using namespace std;

class Solution{
public:
    string longestPalindrome(string s){
        
        int length = s.length();
        string reverse_s = "";
        
        for(int i = 0; i < length; i ++)
            reverse_s = s[i] + reverse_s;
       
        //Find longest common substring for s and reverse_s
        vector<int> pre_len;
        vector<int> cur_len;
        for(int i = 0; i < length; i ++){
           for(int j = 0; j < length; j ++){
           
           } 
        }
        return reverse_s;
    }
};

#endif
