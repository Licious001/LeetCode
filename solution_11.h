//
//  solution_11.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/13.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/* Given n non-negative integers a1, a2, ..., an, where each represents a point 
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 * forms a container, such that the container contains the most water.
 * Note: You may not slant the container.
 */

#ifndef LeetCode_solution_11_h
#define LeetCode_solution_11_h

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int maxArea(vector<int>& height){
        int lo = 0;
        int hi = height.size()-1;
        int maxS = 0;
        while(lo < hi){
            int H = min(height[lo], height[hi]);
            int S = H * (hi-lo); 
            if(S > maxS) maxS = S;
            if(height[lo] < height[hi]) lo ++;
            else hi --;
        }
        return maxS;
    }
};

#endif
