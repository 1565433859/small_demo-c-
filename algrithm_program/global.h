#pragma once
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode* father;
	TreeNode(int x) : val(x), left(NULL), right(NULL),father(NULL) {}
};

//JZ02不修改数组找出重复的数字
int duplicateInArray(std::vector<int>& nums);

//JZ03二维数组中的查找
bool searchArray(std::vector<vector<int>> array, int target);

//JZ06. 重建二叉树
TreeNode* buildTree(std::vector<int>& preorder, vector<int>& inorder);

//JZ07. 二叉树的下一个节点
TreeNode* inorderSuccessor(TreeNode* p);

//JZ10. 旋转数组的最小数字
int findMin(std::vector<int>& nums);

//JZ11. 矩阵中的路径
bool hasPath(std::vector<vector<char>>& matrix, string& str);

//JZ12. 机器人的运动范围
int movingCount(int threshold, int rows, int cols);

//JZ15. 数值的整数次方
double Power(double base, int exponent);

//JZ18. 正则表达式匹配
bool isMatch(string s, string p);

//JZ19. 表示数值的字符串
bool isNumeric(string str);

//JZ20. 调整数组顺序使奇数位于偶数前面
void reOrderArray(vector<int>& array);

//JZ30. 栈的压入、弹出序列
bool isPopOrder(vector<int> pushV, vector<int> popV);

//JZ33. 之字形打印二叉树
vector<vector<int>> printFromTopToBottom(TreeNode* root);

//JZ35. 二叉树中和为某一值的路径
int FindPath(TreeNode* root, int sum);


