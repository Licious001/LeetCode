//
//  solution_2.h
//  LeetCode
//
//  Created by 李鑫 on 15/10/14.
//  Copyright (c) 2015年 李鑫. All rights reserved.
//

#ifndef LeetCode_solution_2_h
#define LeetCode_solution_2_h
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1,ListNode* l2) {
        ListNode* result = NULL;
        ListNode* t = NULL;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        int flag = 0;
        while(t1 != NULL && t2 != NULL){
            int sum = t1->val + t2->val + flag;
            if(sum > 9){
                sum = sum % 10;
                flag = 1;
            }else
                flag = 0;
            if(result == NULL){
                result = new ListNode(sum);
                t = result;
            }
            else{
                ListNode* p = new ListNode(sum);
                t->next = p;
                t = p;
            }
            t1 = t1->next;
            t2 = t2->next;
            
        }
        while(t1 != NULL){
            int sum = t1->val + flag;
            if(sum > 9){
                sum = sum % 10;
                flag = 1;
            }else
                flag = 0;
            ListNode* p = new ListNode(sum);
            t->next = p;
            t = p;
            t1 = t1->next;
        }
        while(t2 != NULL){
            int sum = t2->val + flag;
            if(sum > 9){
                sum = sum % 10;
                flag = 1;
            }else
                flag = 0;
            ListNode* p = new ListNode(sum);
            t->next = p;
            t = p;
            t2 = t2->next;
        }
        if(flag == 1){
            ListNode* p = new ListNode(1);
            t->next = p;
        }
        return result;
    }
   
};

#endif
