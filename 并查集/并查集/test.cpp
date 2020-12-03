#include <iostream>
#include <vector>
using namespace std;

class UnionFindSet {
public:
	// ��ʼ�����鼯��ÿ��Ԫ����Ϊһ������
	UnionFindSet(int n) {
		_v.resize(n, -1);
	}

	// ��ȡ�ڵ�ĸ�
	int findRoot(int x) {
		while (_v[x] >= 0) {
			x = _v[x];
		}

		return x;
	}

	// �ϲ������ڵ����ڵļ���
	bool Union(int x1, int x2) {
		// �ҵ������ڵ�ĸ�
		int r1 = findRoot(x1);
		int r2 = findRoot(x2);
		// ����ͬһ������
		if (r1 == r2)
			return false;
		// �޸�v1�Ľڵ��������v2�ĸ��ڵ��޸�Ϊv1
		_v[r1] += _v[r2];
		_v[r2] = r1;

		return true;
	}

	size_t size() {
		int sz = 0;
		for (auto e : _v) {
			if (e < 0)
				sz++;
		}

		return sz;
	}
private:
	vector<int> _v;
};

int main() {
	system("pause");
	return 0;
}