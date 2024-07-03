#include<iostream>
#include<stack>
#include<unordered_map>
#include"global.h"

using namespace std;

int duplicateInArray(std::vector<int>& nums){
	int l = 1, r = nums.size() - 1;
	while (l < r) {
		int mid = l + (r - l) / 2;
		int l_num = 0, r_num = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= l && nums[i] <= mid)l_num++;
			else {
				if (nums[i] > mid && nums[i] <= r)r_num++;
			}
		}
		if ((mid - l + 1) >= l_num)l = mid + 1;
		else r = mid;
	}
	return l;
}

bool searchArray(vector<vector<int>> array, int target) {
	/*int m=0, n=0;
	if (((m = array.size()) == 0) || ((n = array[0].size()) == 0))return false;
	int i = 0, j = 0;
	while (array[i][j] < target&&j<n) {
		j++;
	}
	if (j == n)j--;
	if (array[i][j] == target)return true;
	while(i<m&&j<n){
		i++;
		while (array[i][j] > target && j >= 0)j--;
		if (j < 0)return false;
		if (array[i][j] == target)return true;
	}
	return false;*/

	if (array.empty() || array[0].empty())return false;
	int m = array.size(), n = array[0].size();
	int i = 0, j = n - 1;
	while (j >= 0 && i < m) {
		if (array[i][j] == target)return true;
		else if (array[i][j] > target)j--;
		else i++;
	}
	return false;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	if (preorder.size() != 0) {
		TreeNode* root = new TreeNode(preorder[0]);
		int index = 0;
		while (index < inorder.size()) {
			if (inorder[index] == preorder[0])break;
			index++;
		}
		vector<int>lpre(preorder.begin() + 1, preorder.begin() + 1+index);
		vector<int>lin(inorder.begin(), inorder.begin() + index);
		vector<int>rpre(preorder.begin() + 1 + index, preorder.end());
		vector<int>rin(inorder.begin() + index + 1, inorder.end());
		root->left = buildTree(lpre, lin);
		root->right = buildTree(rpre, rin);
		return root;
	}
	else {
		return nullptr;
	}
}

TreeNode* inorderSuccessor(TreeNode* p) {
	if (p->right == NULL) {
		while (p->father != NULL && p->father->right == p) {
			p = p->father;
		}
		if (p->father == NULL)return NULL;
		else return p->father;

	}
	else {
		p = p->right;
	}
	while (p->left)p = p->left;
	return p;
}

int findMin(vector<int>& nums) {
	if (nums.size() == 0)return -1;
	int l = 0, r = nums.size() - 1;
	if (nums[r] > nums[l])return nums[l];
	while (nums[l] == nums[r])r--;
	while (l < r) {
		int mid = l + (r - l) / 2;
		if (nums[mid] > nums[0]) {
			l = mid + 1;
		}
		else r = mid;
	}
	return nums[l];
}

vector<vector<bool>>is_visit;
string g_str;
bool dfs(vector<vector<char>>matrix,int i,int j,int m,int n,int index,int length) {
	if (index == length - 1) {
		return true;
	}
	if (j > 0 && !is_visit[i][j - 1] && matrix[i][j - 1] == g_str[index + 1]) {
		is_visit[i][j - 1] = true;
		if (dfs(matrix, i, j - 1, m, n, index + 1, length))return true;
		is_visit[i][j - 1] = false;
	}
	if (j < n-1 && !is_visit[i][j + 1] && matrix[i][j + 1] == g_str[index + 1]) {
		is_visit[i][j + 1] = true;
		if (dfs(matrix, i, j + 1, m, n, index + 1, length))return true;
		is_visit[i][j + 1] = false;
	}
	if (i > 0 && !is_visit[i-1][j] && matrix[i-1][j ] == g_str[index + 1]) {
		is_visit[i-1][j] = true;
		if (dfs(matrix, i-1, j, m, n, index + 1, length))return true;
		is_visit[i-1][j] = false;
	}
	if (i <m-1 && !is_visit[i+1][j] && matrix[i+1][j] == g_str[index + 1]) {
		is_visit[i+1][j] = true;
		if (dfs(matrix, i+1, j, m, n, index + 1, length))return true;
		is_visit[i+1][j] = false;
	}
	return false;
}

bool hasPath(vector<vector<char>>& matrix, string& str) {
	if (matrix.empty() || matrix[0].empty())return false;
	int m = matrix.size(), n = matrix[0].size();
	g_str = str;
	is_visit.resize(m, vector<bool>(n, false));
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix[i][j] == str[0]) {
				is_visit[i][j] = true;
				if (dfs(matrix,i, j, m, n, 0, str.length()))return true;
				is_visit[i][j] = false;
			}
		}
	}
	return false;
}

int get_byteSum(int num) {
	int sum = 0;
	while (num > 0) {
		sum += (num % 10);
		num /= 10;
	}
	return sum;
}

vector<vector<bool>>is_visit2;
int res;
void dfs(int x,int y,int rows,int cols,int threshold){
	if (is_visit2[x][y])return;
	if ((get_byteSum(x) + get_byteSum(y)) <= threshold) {
		res++;
		is_visit2[x][y] = true;
		if(x>0)dfs(x - 1, y, rows, cols, threshold);
		if(x<rows-1)dfs(x + 1, y, rows, cols, threshold);
		if(y>0)dfs(x, y-1, rows, cols, threshold);
		if(y<cols-1)dfs(x, y+1, rows, cols, threshold);
	}
}


int movingCount(int threshold, int rows, int cols) {
	if (rows == 0 || cols == 0)return 0;
	is_visit2.resize(rows, vector<bool>(cols, false));
	res = 0;
	dfs(0, 0, rows, cols, threshold);
	return res;
}

double get_pow(double base, int exponent) {
	if (exponent == 0)return 1;
	if (exponent == 1)return base;
	if ((exponent & 1) == 0) {
		double res = get_pow(base, exponent / 2);
		return res * res;
	}
	else {
		double res = get_pow(base, exponent / 2);
		return res * res * base;
	}
}

double Power(double base, int exponent) {
	if (exponent < 0) {
		exponent = -exponent;
		base = 1 / base;
	}
	return get_pow(base, exponent);
}


bool isMatch(string s, string p) {
	int m = p.length(), n = s.length();
	vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
	dp[0][0] = true;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (j == 0) {
				if (p[i - 1] == '*')
					dp[i][j] = dp[i - 2][j];
				else
					dp[i][j] = false;
			}
			else {
				if (s[j - 1] == p[i - 1]) {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else {
					if (p[i - 1] == '*') {
						if (p[i - 2] == '.' || s[j - 1] == p[i - 2])
							dp[i][j] = dp[i - 2][j] || dp[i][j - 1] ||
							dp[i - 1][j - 1];
						else dp[i][j] = dp[i - 2][j];
					}
					else if (p[i - 1] == '.')
						dp[i][j] = dp[i - 1][j - 1];
					else
						dp[i][j] = false;
				}
			}
		}
	}
	return dp[m][n];
}


bool isNumeric(string str) {
	bool is_float = false, is_E = false, is_Num = false, is_flag = false;
	int begin, end;
	for (begin = 0; begin < str.length(); begin++) {
		if (str[begin] != ' ')break;
	}
	for (end = str.length() - 1; end >= 0; end--) {
		if (str[end] != ' ')break;
	}
	while (begin <= end) {
		if (str[begin] == ' ')return false;
		else if (str[begin] == '+' || str[begin] == '-') {
			if (is_flag)return false;
			if (is_Num)return false;
			is_flag = true;
		}
		else if (str[begin] >= '0' && str[begin] <= '9')is_Num = true;
		else if (str[begin] == 'E' || str[begin] == 'e') {
			if ((!is_Num && !is_float) || is_E)return false;
			is_E = true;
			is_Num = false;
			is_flag = false;
		}
		else if (str[begin] == '.') {
			if (is_float || is_E)return false;
			is_float = true;
		}
		else return false;
		begin++;
	}
	return is_Num;
}


void swap(int& num1, int& num2) {
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void reOrderArray(vector<int>& array) {
	int flag = 0;
	for (int i = 0; i < array.size(); i++) {
		if ((array[i] & 1) == 1) {
			if (i != flag) {
				swap(array[flag], array[i]);
			}
			flag++;
		}
	}
}


bool isPopOrder(vector<int> pushV, vector<int> popV) {
	stack<int>st;
	int i = 0, j = 0;
	while (!st.empty() && (i < pushV.size()) && (j < popV.size())) {
		if (!st.empty()) {
			if (st.top() == popV[j]) {
				j++;
				st.pop();
			}
			else {
				st.push(pushV[i++]);
			}
		}
		else {
			st.push(pushV[i++]);
		}
	}
	return st.empty();
}

vector<vector<int>> printFromTopToBottom(TreeNode* root) {
	vector<vector<int>>res;
	vector<int>ans;
	if (root == nullptr)return res;
	deque<TreeNode*>node_que;
	node_que.push_back(root);
	TreeNode* flag = root;
	bool dir_left = true;
	while (!node_que.empty()) {
		TreeNode* tmp;
		if (dir_left) {
			tmp = node_que.front();
			node_que.pop_front();
			if (tmp->left)node_que.push_back(tmp->left);
			if (tmp->right)node_que.push_back(tmp->right);
		}
		else {
			tmp = node_que.back();
			node_que.pop_back();
			if (tmp->right)node_que.push_front(tmp->right);
			if (tmp->left)node_que.push_front(tmp->left);
		}
		ans.push_back(tmp->val);
		if (tmp == flag) {
			res.push_back(ans);
			ans.clear();
			if (dir_left)flag = node_que.front();
			else flag = node_que.back();
			dir_left = !dir_left;
		}
	}
	return res;
}
unordered_map<int, int>path_map;
int find(TreeNode* root, int sum, int length) {
	int res = path_map[length - (sum - root->val)];
	path_map[length + root->val]++;
	if (root->left)res += find(root->left, sum, length + root->val);
	if (root->right)res += find(root->right, sum, length + root->val);
	path_map[length + root->val]--;
	return res;
}

int FindPath(TreeNode* root, int sum) {
	// write code here
	if (root == nullptr)return 0;
	path_map[0] = 1;
	return find(root, sum, 0);
}
