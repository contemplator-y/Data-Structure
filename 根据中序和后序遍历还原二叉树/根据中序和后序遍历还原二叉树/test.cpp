#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;




 struct TreeNode {

     int val;

	 TreeNode *left;

     TreeNode *right;

     TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};



class Solution {

public:

	TreeNode* _buildTree(vector<int>& inorder, int instart, int inend,

		vector<int>& postorder, int poststart, int postend) {

		//����ǰ���������������������ʼ�ͽ���λ��

		TreeNode* root = new TreeNode(postorder[postend]); //���ڵ�



		if (instart == inend) {

			root->left = root->right = nullptr;

			return root;

		}

		int pos = 0;

		for (; pos < inorder.size(); pos++) { //�������������ҵ�����λ��

			if (inorder[pos] == postorder[postend])

				break;

		}

		//��ȡ�������ĸ���

		int LenOfRight = inend - pos;

		if (pos == instart)

			root->left = nullptr;

		else

			root->left = _buildTree(inorder, instart, pos - 1, postorder, poststart, postend - 1 - LenOfRight);

		if (pos == inend)

			root->right = nullptr;

		else

			root->right = _buildTree(inorder, pos + 1, inend, postorder

			, postend - 1 - LenOfRight, postend - 1);



		return root;

	}



	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

		int size = inorder.size();

		if (size == 0)

			return nullptr;



		TreeNode* root = _buildTree(inorder, 0, size - 1, postorder, 0, size - 1);



		return root;

	}

};

int main() {
	system("pause");
	return 0;
}