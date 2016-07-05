//
//  solution_6.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/05.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/*
  string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows
  like this: (you may want to display this pattern in a fixed font for better legibility)

  P   A   H   N
  A P L S I I G
  Y   I   R
   
  And then read line by line: "PAHNAPLSIIGYIR"
  Write the code that will take a string and make this conversion given a number of rows:
  string convert(string text, int nRows);
  convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
#ifndef LeetCode_solution_6_h
#define LeetCode_solution_6_h
#include <iostream>
using namespace std;
class Solution{
    public:
        string convert(string s, int numRows){
            // calculate the col num
            
            int len = s.length();
            if(len == 0)    return s;
            int t = 2*numRows-2;
            if(t == 0)  return s;
            int a = len / t;
            int b = len % t;
            int col = a * (numRows - 1);
            if(b > 0 && b <= numRows) col ++;
            if(b > numRows) col = col + b - numRows + 1;
            
            string result = "";

            for(int i = 0; i < numRows; i ++){
                if(i == 0){
                    int count = 0;
                    while(true){
                        int index = i + count * t;
                        if(index < len){ result += s[index]; count ++;}
                        else break;
                    }
                }
                else if(i == numRows-1){
                    int count = 0;
                    while(true){
                        int index = i + count * t;
                        if(index < len){result += s[index]; count++;}
                        else break;
                    }
                }
                else{
                    int count = 0;
                    while(true){
                        int index1 = i + count*t;
                        if(index1 < len)  {result += s[index1];}
                        else break;
                        int index2 = index1 + 2*(numRows-1-i);
                        if(index2 < len)  {result += s[index2];count ++;}
                        else break;
                    }
                }
            }
            return result;
        } 
};
#endif
