#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//���������ҵ���������ȵ����ֲ�����������ɾ����֮ǰ��������һ������ֵĸ�����Ȼ�������鳤�ȵ�һ��
//������ĸ���ֻ��ԭ����һ���ʱ��ʣ�µľͶ�Ϊ����
int getMornThanHalfNum(vector<int>& v) {
	int size = v.size();
	if (v.size() == 1)
		return v.front();
	while (v.size() > size / 2) {
		auto it = ++v.begin();
		while (it != v.end()) {
			if (*it != v.front()) {
				v.erase(it);
				v.erase(v.begin());
				break;
			}
		}
	}

	return v.front();

}
int main() {
	int arr[] = { 1, 4, 4, 1, 6, 4 , 4};
	vector<int> v(arr, arr + sizeof(arr));
	int ret = getMornThanHalfNum(v);

	cout << ret << endl;
	system("pause");
	return 0;
}