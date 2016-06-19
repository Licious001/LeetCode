// Soluiton_4.h
// LeetCode

//  Created by 李鑫 on 15/10/14.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/* Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there 
 * exists one unique longest palindromic substring.
 */

#ifndef LeetCode_solution_4_h
#define LeetCode_solution_4_h

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        string longestPalindrome(string s){

            int length = s.length();
            string reverse_s = "";

            for(int i = 0; i < length; i ++)
                reverse_s = s[i] + reverse_s;

            //cout << s << endl;
            //cout << reverse_s << endl;
            //Find longest common substring for s and reverse_s
            vector<int> pre_len(length, 0);
            vector<int> cur_len(length, 0);

            int max_pos = 0;
            int max_len = 0;
            for(int i = 0; i < length; i ++){
                cur_len.assign(length,0);
                for(int j = 0; j < length; j ++){
                    if(reverse_s[i] == s[j]){
                        if(j == 0) cur_len[j] = 1;
                        else    cur_len[j] = pre_len[j-1] + 1;
                    }
                    else
                        cur_len[j] = 0;
                    if(cur_len[j] > max_len){
                        max_len = cur_len[j];
                        max_pos = j;
                    }
                }

                pre_len = cur_len;
            }
            //cout << max_pos << "\t" << max_len << endl;
            //cout << s[max_pos] << endl;
            string result = s.substr(max_pos-max_len+1, max_len);
            if(result == "")    result += s[0];
            return result;
        }
};

#endif
