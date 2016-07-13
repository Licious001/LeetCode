//
//  solution_10.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/12.
//  Copyright (c) 2015年 李鑫. All rights reserved.
/* Implement regular expression matching with support for '.' and '*'.

   '.' Matches any single character.
   '*' Matches zero or more of the preceding element.

   The matching should cover the entire input string (not partial).

   The function prototype should be:
   bool isMatch(const char *s, const char *p)

   Some examples:
   isMatch("aa","a") → false
   isMatch("aa","aa") → true
   isMatch("aaa","aa") → false
   isMatch("aa", "a*") → true
   isMatch("aa", ".*") → true
   isMatch("ab", ".*") → true
   isMatch("aab", "c*a*b") → true
   */
#ifndef LeetCode_solution_10_h
#define LeetCode_solution_10_h

#include<iostream>
using namespace std;
class Solution{
    public:
        bool isMatch(string s, string p){
            int lenS = s.length();
            int lenP = p.length();
            if(lenP == 0) return lenS == 0;
            if(lenP == 1){
                if(s.length() != 1) return false;
                else return s[0] == p[0] || p[0] == '.';
            }
            if(p[1] != '*'){
                if(lenS == 0)   return false;
                if(s[0] == p[0] || p[0] == '.') 
                    return isMatch(s.substr(1, lenS-1), p.substr(1, lenP-1));
                else return false;
            }else{
                int index = 0;
                while(index < s.length()){
                    if(s[index] != p[0] && p[0] != '.') break;
                    string subS = s.substr(index, lenS-index);
                    string subP = p.substr(2, lenP-2);
                    if(isMatch(subS, subP)) return true;
                    index ++;
                }
                return isMatch(s.substr(index, lenS-index), p.substr(2, lenP-2));
            }
        }
        bool isMatch2(string s, string p){
            cout << s << " "<< p << endl;
            if(s.length() == 0){
                int index1 = 0;
                while(index1+1 < p.length()){
                    if(p[index1+1] != '*')  return false;
                    index1 += 2;
                }
                if(p.length() % 2 == 1)    return false;
                else return true;
            }
            else{
                if(p.length() == 0) return false;
                else if(p.length() == 1){
                    if(s.length() > 1)  return false;
                    if(s[0] == p[0] || p[0] == '.' )    return true;
                    else    return false;
                }else{
                    if(s[0] == p[0]){
                        if(p[1] == '*'){
                            int index = 0;
                            while(index < s.length()){
                                if(s[index] != p[0]){break;}
                                string ns = s.substr(index, s.length()-index);
                                string np = p.substr(2, p.length()-2);
                                if(isMatch(ns, np)) return true;
                                index ++;
                            }
                            return isMatch(s.substr(index, s.length()-index), p.substr(2, p.length()-2));

                        }else{
                            string ns = s.substr(1, s.length()-1);
                            string np = p.substr(1, p.length()-1);
                            return isMatch(ns,np);
                        }
                    }else if(p[0] == '.'){
                        if(p[1] == '*'){
                            int index = 0;
                            while(index < s.length()){ 
                                string ns = s.substr(index, s.length()-index);
                                string np = p.substr(2, p.length()-2);
                                if(isMatch(ns, np)) return true;
                                index ++;
                            }
                            return isMatch("", p.substr(2, p.length()-2));
                        }else{
                            string ns = s.substr(1, s.length()-1);
                            string np = p.substr(1, p.length()-1);
                            return isMatch(ns,np);
                        }
                    }
                    else{
                        if(p[1] == '*'){ // isMatch()
                            string np = p.substr(2, p.length()-2);
                            return isMatch(s, np);
                        }
                        else    return false;
                    }
                } 
            }

        }
};
#endif
