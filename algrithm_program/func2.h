#pragma once
#include<vector>
#include<string>
#include"global.h"
using namespace std;

//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode() : val(0), left(nullptr), right(nullptr) {}
//	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
//};

//接雨水
int trap(vector<int>& height);

//盛水最多的容器
int maxArea(vector<int>& height);

//最长有效括号
int longestValidParentheses(string s);

//二叉树中的最大路径和
int maxPathSum(TreeNode* root);

vector<string> letterCombinations(string digits);

vector<vector<int>> combinationSum(vector<int>& candidates, int target);