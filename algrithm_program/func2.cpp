#include "func2.h"
#include<stack>
#include<functional>
#include<algorithm>
#include<unordered_map>
int find_path(TreeNode* root);


int trap(vector<int>& height)
{
    stack<int>st;
    int res = 0;
    for (int i = 0; i < height.size(); i++) {
        while (!st.empty() && height[i] > height[st.top()]) {
            int index = st.top();
            st.pop();
            if (!st.empty()) {
                res += (height[st.top()] - height[index]) * (i - st.top() - 1);
            }
        }
        if (height[i] == height[st.top()])continue;
        st.push(i);
    }
    return res;
}

int maxArea(vector<int>& height) {
    return 0;
}

int longestValidParentheses(string s)
{
    stack<int>st;
    int max = 0;
    st.push(-1);
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        }
        else {
            if(st.size()>1){
                st.pop();
                if ((i - st.top()) > max)max = i - st.top();
            }
            else {
                st.pop();
                st.push(i);
            }
        }
    }
    return max;
}

int max_path;
int maxPathSum(TreeNode* root) {
    max_path = root->val;
    find_path(root);
    return max_path;
}

int find_path(TreeNode* root) {
    if (root == nullptr)return 0;
    int path_left = 0, path_right = 0;
    if (root->left)path_left = find_path(root->left);
    if (root->right)path_right = find_path(root->right);
    int res = root->val;
    if (path_left > 0)res += path_left;
    if (path_right > 0)res += path_right;
    if (res > max_path)max_path = res;
    return root->val+max(max(path_right, path_left), 0);
}

vector<string>res;
void back_track(string digits, int level, unordered_map<char, string>&phone,string ans) {
    if (level = digits.length()) {
        res.push_back(ans);
        return;
    }
    for (auto c : phone[digits[level]]) {
        ans += c;
        back_track(digits, level + 1, phone, ans);
        ans.pop_back();
    }
}
vector<string> letterCombinations(string digits) {
    unordered_map<char, string>phone = { {'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
    string ans="";
    back_track(digits, 0, phone, ans);
    return res;
}

vector<vector<int>>res1;
vector<int>ans1;
void dfs(vector<int>& candidates,int target,int index,int sum) {
    for (int i = index; i < candidates.size(); i++) {
        if ((sum + candidates[i]) < target) {
            ans1.push_back(candidates[i]);
            dfs(candidates, target, i + 1, sum + candidates[i]);
            ans1.pop_back();
        }
        else if ((sum + candidates[i]) == target) {
            ans1.push_back(candidates[i]);
            res1.push_back(ans1);
            ans1.pop_back();
            return;
        }
        else {
            return;
        }
    }
 
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    dfs(candidates, target, 0, 0);
    return res1;
}

