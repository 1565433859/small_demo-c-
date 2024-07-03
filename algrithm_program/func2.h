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

//����ˮ
int trap(vector<int>& height);

//ʢˮ��������
int maxArea(vector<int>& height);

//���Ч����
int longestValidParentheses(string s);

//�������е����·����
int maxPathSum(TreeNode* root);

vector<string> letterCombinations(string digits);

vector<vector<int>> combinationSum(vector<int>& candidates, int target);