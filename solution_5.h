//
//  solution_5.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/05.
//  Copyright (c) 2015年 李鑫. All rights reserved.
/* There are two sorted arrays nums1 and nums2 of size m and n respectively.

   Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

   Example 1:
   nums1 = [1, 3]
   nums2 = [2]

   The median is 2.0
   Example 2:
   nums1 = [1, 2]
   nums2 = [3, 4]

   The median is (2 + 3)/2 = 2.5
   */

#ifndef LeetCode_solution_5_h
#define LeetCode_solution_5_h

#include <iostream>
#include <vector>
using namespace std;

class Solution{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
            int len1 = nums1.size();
            int len2 = nums2.size();
            int len = nums1.size() + nums2.size();

            if(len % 2 == 1)
                return findKthNum(nums1, 0, len1, nums2, 0, len2, len/2+1);
            else
                return (findKthNum(nums1, 0, len1, nums2, 0, len2, len/2) + findKthNum(nums1, 0, len1, nums2, 0, len2, len/2+1))/2.0;

        }
        int findKthNum(vector<int>& nums1, int l1, int h1, vector<int>& nums2, int l2, int h2, int k){
            if(h1-l1 > h2-l2){
                return findKthNum(nums2, l2, h2,nums1, l1, h1, k);
            }
            if(h1-l1 == 0) return nums2[k-1];
            if(k == 1)  return min(nums1[l1], nums2[l2]);
            int index1 = min(k/2, h1-l1);
            int index2 = k - index1;
            if(nums1[index1-1+l1] < nums2[index2-1+l2]){
                return findKthNum(nums1, index1+l1, h1, nums2, l2, h2, k-index1); 
            }else if(nums1[index1-1+l1] > nums2[index2-1+l2]){
                return findKthNum(nums1, l1, h1, nums2, index2+l2, h2, k-index2);
            } 
            else    
                return nums1[index1-1+l1];
        }
};

#endif
