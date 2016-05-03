//
//  solution_1.h
//  LeetCode
//
//  Created by 李鑫 on 15/10/14.
//  Copyright (c) 2015年 李鑫. All rights reserved.
/*
 Given an array of integers, find two numbers such that they add up to a specific target number.

 The function twoSum should return indices of the two numbers such that they add up to the
 target, where index1 must be less than index2. Please note that your returned answers (both 
 index1 and index2) are not zero-based.

 You may assume that each input would have exactly one solution.

 Input: numbers={2, 7, 11, 15}, target=9
 Output: index1=1, index2=2
*/
#ifndef LeetCode_solution_1_h
#define LeetCode_solution_1_h
#include <vector>
using namespace std;
class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int index1 = -1, index2 = -1;
        int a1, a2;
        vector<int> num(nums);
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i ++){
            a1 = nums.at(i);
            int a = target - nums.at(i);
            if(a < nums.at(i))
                break;
            int index = locate(nums, a, i);
            if(index > 0){
                a2 = nums.at(index);
                break;
            }
        }
        for(int i = 0; i < num.size(); i ++){
            if(num.at(i) == a1 || num.at(i) == a2){
                if(index1 < 0)
                    index1 = i + 1;
                else{
                    index2 = i + 1;
                    break;
                }
            }
        }
        vector<int> result = {index1, index2};
        cout << index1 << "\t" << index2 << endl;
        return result;
    }
    int locate(vector<int>& nums, int target, int begin){
        int start = begin;
        int end = nums.size()-1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(nums.at(mid) == target)
                return mid;
            else if(nums.at(mid) > target)
                end = mid -1;
            else
                start = mid +1;
        }
        return -1;
    }
};

#endif
