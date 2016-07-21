//
//  solution_15.h
//  LeetCode
//
//  Created by 李鑫 on 16/7/13.
//  Copyright (c) 2015年 李鑫. All rights reserved.

/*Given an array S of n integers, are there elements a, b, c in S 
 * such that a + b + c = 0? Find all unique triplets in the array 
 * which gives the sum of zero.
 * */

#ifndef LeetCode_solution_15_h
#define LeetCode_solution_15_h

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
        vector<vector<int> > threeSum(vector<int>& nums){
            vector<vector<int> > result;
            if(nums.size() < 3) return result;
            sort(nums.begin(), nums.end());
            for(int i = 0; i < nums.size()-2; i ++){
                int t = nums[i];
                if(t > 0)   return result;
                if(i != 0 && nums[i-1] == nums[i]) continue;
                int lo = i+1;
                int hi = nums.size()-1;
                while(lo < hi){
                    if(nums[hi] < 0 || nums[lo] > -t)   break;
                    int target = nums[lo] + nums[hi] + t;
                    if(target == 0){
                        vector<int> tmp;
                        tmp.push_back(nums[lo]);
                        tmp.push_back(t);
                        tmp.push_back(nums[hi]);
                        result.push_back(tmp);
                        while(++lo < hi && nums[lo] == nums[lo-1]);
                        while(--hi > lo && nums[hi] == nums[hi+1]);
                    }else if(target < 0){
                        while(++lo < hi && nums[lo] == nums[lo-1]);
                    }else{
                        while(--hi > lo && nums[hi] == nums[hi+1]);
                    }
                }
            }
            return result;
        }
};

#endif
