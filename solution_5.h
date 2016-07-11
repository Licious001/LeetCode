//
//  solution_5.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/05.
//  Copyright (c) 2015年 李鑫. All rights reserved.

#ifndef LeetCode_solution_5_h
#define LeetCode_solution_5_5

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            int lo1 = 0;
            int lo2 = 0;
            int hi1 = nums1.size() - 1;
            int hi2 = nums2.size() - 1;
            while(true){
                int mid1 = (lo1 + hi1) / 2;
                int mid2 = (lo2 + hi2) / 2;
                int n1 = nums.at(mid1);
                int n2 = nums.at(mid2);
                if(n1 == n2){
                    if((hi1 + hi2) % 2 == 1)
                        return n1;
                    else{
                        if(nums.at(mid1+1) > nums.at(mid2+1))
                            return (n1+n2)/2.0;
                    }
                }
            }
        }
};

#endif
