#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#includ <stdio.h>

void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//ǰ��ָ�뷨���ݻ�׼ֵ��������
int pation(int* arr, int start, int end) {
	//ѡȡ��׼ֵ
	int key = arr[start];
	int cur = start + 1;
	int pre = start;//���һ��С��key��λ��
	while (cur <= end) {
		if (arr[cur] < key && ++pre != cur) {
			Swap(arr, pre, cur);
		}
		cur++;
	}
	Swap(arr, pre, start);

	//���ػ�׼ֵ����λ��
	return pre;
}
int majorityElement(int* nums, int numsSize){
	//�������飬��������ֵ��һ���������е����֣�һ���������
	//������ʱ������ǰԪ���뱣����������ͬ��������1���������-1���������0����
	//�޸ı���������Ϊ��ǰԪ�أ�����Ϊ1
	// int key = nums[0], n = 1;
	// for (int i = 1; i < numsSize; i++) {
	//     if (nums[i] == key) {
	//         n++;
	//     } else {
	//         n--;
	//         if (n == 0) {
	//             key = nums[i];
	//             n = 1;
	//         }
	//     }
	// }

	// return key;


	//ͨ�����ϵĽ��л����ҵ���λ��������λ����һ�������������
	int start = 0, end = numsSize - 1;
	int mid = (numsSize - 1) / 2;
	int idx = pation(nums, start, end);
	while (idx != mid) {
		if (idx < mid) {
			start = idx + 1;
			idx = pation(nums, start, end);
		}
		else {
			end = idx - 1;
			idx = pation(nums, start, end);
		}
	}

	return nums[mid];
}

int main() {
	system("pause");
	return 0;
}