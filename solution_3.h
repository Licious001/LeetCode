//
//  solution_3.h
//  LeetCode
//
//  Created by 李鑫 on 15/10/15.
//  Copyright (c) 2015年 李鑫. All rights reserved.
//

#ifndef LeetCode_solution_3_h
#define LeetCode_solution_3_h
#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    int lengthOfLongestSubstring(string s) {
        int index[100];
        int maxLen = 0;
        int pos = 0;
        for(int i = 0; i < 100; i ++)
            index[i] = -1;
        for(int i = 0; i < s.size(); i ++){
            char cur = s[i];
            if(index[cur] < pos)
                index[cur] = -1;
            if (index[cur] == -1) {
                index[cur] = i;
            }else{
                if(i-pos > maxLen)
                    maxLen = i-pos;
                if(maxLen == 95) // 字符数目最多95个
                    return 95;
                pos = index[cur] + 1;
              
                index[cur] = i;
                
            }
        }
        if(s.size()-pos > maxLen)
            return s.size()-pos;
        return maxLen;
    }
};

#endif
