//
//  main.cpp
//  Evaluate_Reverse_Polish_Notation
//
//  Created by 李佳 on 15/11/11.
//  Copyright © 2015年 LiJia. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;


class Solution {
public:
    
    bool isOperation(string str)
    {
        char ch = str[0];
        bool isOperation = ch == '+' || ch == '-' || ch == '*' || ch == '/';
        return isOperation && str.size() == 1;
    }
    
    int doOperation(char operation, int l, int r)
    {
        switch (operation)
        {
            case '+':
                return l + r;
            case '-':
                return l - r;
            case '*':
                return l * r;
            case'/':
                return l / r;
            default:
                return 0;
        }
    }
    
    int evalRPN(vector<string>& tokens)
    {
        stack<int> nums;
        for (int i = 0; i < tokens.size(); ++i)
        {
            if (isOperation(tokens[i]))
            {
                if (nums.size() < 2) //有错误
                    return 0;
                int r = nums.top();
                nums.pop();
                int l = nums.top();
                nums.pop();
                
                int result = doOperation(tokens[i][0], l, r);
                nums.push(result);
            }
            else
            {
                int num = atoi(tokens[i].c_str());
                nums.push(num);
            }
        }
        return nums.top();
    }
};

int main(int argc, const char * argv[])
{
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    Solution sol;
    int result = sol.evalRPN(tokens);
    printf("result = %d", result);
    return 0;
}
