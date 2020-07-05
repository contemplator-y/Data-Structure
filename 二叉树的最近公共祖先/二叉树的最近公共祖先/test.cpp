#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;


 struct TreeNode {
     int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	bool isExit(TreeNode* root, TreeNode* tar) {
		if (root == NULL)
			return false;
		return tar == root || isExit(root->left, tar) || isExit(root->right, tar);
	}
	//��ȡ�����ڵ��·�������ջ��
	void getPath(TreeNode* root, stack<TreeNode*>& st, TreeNode* tar) {

	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL)
			return NULL;
		//����һ��Ϊ���ڵ�
		if (root == p || root == q)
			return root;

		//������������
		if (isExit(root->left, p) && isExit(root->left, q))
			return lowestCommonAncestor(root->left, p, q);
		//������������
		if (isExit(root->right, p) && isExit(root->right, q))
			return lowestCommonAncestor(root->right, p, q);

		//�ֱ�������������
		return root;
	}
};
int main() {
	sytem("pause");
	return 0;
}