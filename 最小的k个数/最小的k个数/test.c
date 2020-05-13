#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/**
* Note: The returned array must be malloced, assume caller calls free().
*/

typedef struct heap {
	int* arr;
	int size;
	int capacity;
}heap;

void Swap(int*arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//һ�����µ���
void shiftDown(int* arr, int n, int parent) {
	int child = 2 * parent + 1;
	while (child < n) {
		//childָ��ϴ�ĺ���
		if (child + 1 < n && arr[child + 1] > arr[child]) {
			child++;
		}
		//�����Ӵ��ڸ��ף�����
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		}
		else {
			break;
		}
	}
}
void heapCreate(heap* hp, int* arr, int n) {
	//����Ԫ�أ���ʼ��
	hp->arr = (int*)malloc(sizeof(int) * n);
	memcpy(hp->arr, arr, sizeof(int) * n);
	hp->size = hp->capacity = n;

	//�ӵ�һ����Ҷ�ڵ���ǰ���µ���
	for (int parent = (n - 2) / 2; parent >= 0; parent--) {
		shiftDown(hp->arr, n, parent);
	}
}
int heapTop(heap* hp) {
	return hp->arr[0];
}
//���ϵ���
void shiftUp(int* arr, int child) {
	int parent = (child - 1) / 2;
	while (parent >= 0) {
		//���Ӵ��ڸ��ף�����
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else {
			break;
		}
	}
}
//���
void heapPush(heap* hp, int val) {
	//�������
	if (hp->size == hp->capacity) {
		hp->capacity *= 2;
		hp->arr = (int*)realloc(hp->arr, sizeof(int) * hp->capacity);
	}
	//β��
	hp->arr[hp->size++] = val;
	//���ϵ���
	shiftUp(hp->arr, hp->size - 1);
}
//�ѵ�ɾ����ɾ���Ѷ�֮�����µ�����
void heapPop(heap* hp) {
	//������βԪ��
	Swap(hp->arr, 0, hp->size - 1);
	//βɾ
	hp->size--;
	//���µ���һ��
	shiftDown(hp->arr, hp->size, 0);
}


//�ڿӷ����ݻ�׼ֵ��������
int pation(int* arr, int start, int end) {
	int key = arr[start];
	while (start < end) {
		//�Ӻ���ǰ�ҵ�һ��С�ڻ�׼ֵ��Ԫ��
		while (start < end && arr[end] >= key) {
			end--;
		}
		//�������
		arr[start] = arr[end];
		//��ǰ�����ҵ�һ�����ڻ�׼ֵ��Ԫ��
		while (start < end && arr[start] <= key) {
			start++;
		}
		//�������
		arr[end] = arr[start];
	}
	//����׼ֵ���������Ŀӵ�λ��
	arr[start] = key;
	//���ػ�׼ֵλ��
	return start;
}
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
	//���ݿ��ŵĻ�������ȷ��λ��Ϊk��Ԫ�أ�ǰk��Ԫ�ؼ�Ϊ����
	// *returnSize = k;
	// int* res = (int*)malloc(sizeof(int) * k);
	// if (k == 0) {
	//     return res;
	// }

	// //k�����鳤����ȣ�ֱ�ӿ���Ԫ��
	// if (k == arrSize) {
	//     memcpy(res, arr, sizeof(int) * k);
	//     return res;
	// }
	// //���ϵػ��֣�ֱ�����ֺ��׼ֵ��λ��Ϊk����ǰk��Ԫ��һ������õ�k����
	// int start = 0, end = arrSize - 1;
	// int idx = pation(arr, start, end);
	// while (idx != k) {
	//     //���������������
	//     if (idx > k) {
	//         end = idx - 1;
	//         idx = pation(arr, start, end);
	//     } else {
	//         //�����Ұ�����
	//         start = idx + 1;
	//         idx = pation(arr, start, end);
	//     }
	// }

	// //����ǰk��Ԫ��
	// memcpy(res, arr, sizeof(int) * k);

	// return res;

	//����Ѵ��ǰk�����ݣ�������������ݣ����ݶѶ�Ԫ�غ͸�Ԫ�صĴ�Сȷ���Ƿ���ѣ����ն��ڵ����ݼ�Ϊ����

	int* res = (int*)malloc(sizeof(int) * k);
	*returnSize = k;
	if (k == 0) {
		return res;
	}
	heap hp;
	//��ǰk����������
	heapCreate(&hp, arr, k);

	//����֮���Ԫ��
	for (int i = k; i < arrSize; i++) {
		int top = heapTop(&hp);
		if (arr[i] < top) {
			heapPop(&hp);
			heapPush(&hp, arr[i]);
		}
	}

	//�������е�Ԫ��
	memcpy(res, hp.arr, sizeof(int) * k);
	return res;
}
int main() {
	system("pause");
	return 0;
}