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

//JZ02���޸������ҳ��ظ�������
int duplicateInArray(std::vector<int>& nums);

//JZ03��ά�����еĲ���
bool searchArray(std::vector<vector<int>> array, int target);

//JZ06. �ؽ�������
TreeNode* buildTree(std::vector<int>& preorder, vector<int>& inorder);

//JZ07. ����������һ���ڵ�
TreeNode* inorderSuccessor(TreeNode* p);

//JZ10. ��ת�������С����
int findMin(std::vector<int>& nums);

//JZ11. �����е�·��
bool hasPath(std::vector<vector<char>>& matrix, string& str);

//JZ12. �����˵��˶���Χ
int movingCount(int threshold, int rows, int cols);

//JZ15. ��ֵ�������η�
double Power(double base, int exponent);

//JZ18. ������ʽƥ��
bool isMatch(string s, string p);

//JZ19. ��ʾ��ֵ���ַ���
bool isNumeric(string str);

//JZ20. ��������˳��ʹ����λ��ż��ǰ��
void reOrderArray(vector<int>& array);

//JZ30. ջ��ѹ�롢��������
bool isPopOrder(vector<int> pushV, vector<int> popV);

//JZ33. ֮���δ�ӡ������
vector<vector<int>> printFromTopToBottom(TreeNode* root);

//JZ35. �������к�Ϊĳһֵ��·��
int FindPath(TreeNode* root, int sum);


