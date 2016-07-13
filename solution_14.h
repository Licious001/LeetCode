//
//  solution_14.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/13.
//  Copyright (c) 2015年 李鑫. All rights reserved.

//Write a function to find the longest common prefix string amongst an array of strings.

#ifndef LeetCode_solution_14_h
#define LeetCode_solution_14_h

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        string longestCommonPrefix(vector<string>& strs){
            if(strs.size() == 0)    return "";
            if(strs.size() == 1)    return strs[0];
            string prefix = strs[0];
            for(int i = 1; i < strs.size(); i ++){
                int len1 = prefix.length();
                int len2 = strs[i].length();
                int len = min(len1, len2); 
                while(len > 0){
                    string s1 = prefix.substr(0, len);
                    string s2 = strs[i].substr(0, len);
                    if(s1 == s2){   prefix = s1; break;}
                    len --;
                }
                if(len == 0) return "";
            }
            return prefix;
        }
};

#endif
