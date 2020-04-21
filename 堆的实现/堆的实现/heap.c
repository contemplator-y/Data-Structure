#include "heap.h"

// �ѵĹ���(��С�ѣ�
void HeapCreate(Heap* hp, HPDataType* arr, int n) {
	//��������
	hp->_a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	hp->_capacity = hp->_size = n;
	memcpy(hp->_a, arr, sizeof(HPDataType) * n);
	//�����һ����Ҷ�ڵ㿪ʼ���ж�����µ���
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(hp->_a, hp->_size, i);
	}
}
//��������
void Swap(HPDataType* arr, int left, int right) {
	HPDataType tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//һ�����µ���
void shiftDown(HPDataType* arr, int size, int parent) {
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && arr[child + 1] < arr[child]) {
			child++;
		}
		if (arr[child] < arr[parent]) {
			Swap(arr, parent, child);
			parent = child;
			child = 2 * parent + 1;
		} else {
			break;
		}
	}
}
//�����ѵ�Ԫ��
void HeapPrint(Heap* hp) {
	for (int i = 0; i < hp->_size; i++) {
		printf("%d ", hp->_a[i]);
	}
	printf("\n");
}
// �ѵĲ���
void HeapPush(Heap* hp, HPDataType x) {
	//�������
	if (hp->_size == hp->_capacity) {
		hp->_capacity *= 2;
		hp->_a = (HPDataType*)realloc(hp->_a, sizeof(HPDataType) * hp->_capacity);
	}
	//β��
	hp->_a[hp->_size++] = x;
	//���ϵ���
	int child = hp->_size - 1;
	int parent = (child - 1) / 2;
	while (parent >= 0) {
		if (hp->_a[child] < hp->_a[parent]) {
			Swap(hp->_a, parent, child);
			child = parent;
			parent = (child - 1) / 2;
		} else {
			break;
		}
	}
}
// �ѵ�ɾ��
void HeapPop(Heap* hp) {
	if (hp->_size == 0) {
		return;
	}
	//����ͷ�������һ��Ҷ�ڵ�
	Swap(hp->_a, 0, hp->_size - 1);
	//βɾ��
	hp->_size--;
	//�Ӹ��ڵ����µ���һ��
	shiftDown(hp->_a, hp->_size, 0);
}
// ȡ�Ѷ�������
HPDataType HeapTop(Heap* hp) {
	return hp->_a[0];
}
// �ѵ����ݸ���
int HeapSize(Heap* hp) {
	return hp->_size;
}
// �ѵ��п�
int HeapEmpty(Heap* hp) {
	return hp->_size == 0;
}
// �ѵ�����
void HeapDestory(Heap* hp) {
	free(hp->_a);
	hp->_size = hp->_capacity = 0;
}
// ��������ж�����
void HeapSort(int* arr, int n) {
	//ԭ�ؽ���
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(arr, n, i);
	}
	while (n > 1) {
		//�ѵ�ɾ��������ֵ�����������һ��Ԫ�أ�
		Swap(arr, 0, n - 1);
		n--;
		//���µ���һ��
		shiftDown(arr, n, 0);
	}
} 

// TopK���⣺�ҳ�N����������� / ��С��ǰK�����⡣
// ���磺δ��������ǰ10�����ɣ�������ͨ��ѧ������ҫ����ǰ10�ĺ��ţ�ȫ������ǰ10����ס��ȵ����ⶼ��Topk���⣬
// ��Ҫע�⣺
// ������ǰK��������K������С��
// ����С��ǰK��������K�����Ĵ��
void PrintTopK(int* a, int n, int k) {
	//��ǰk��Ԫ�ؽ���(С�ѣ�
	Heap hp;
	HeapCreate(&hp, a, k);
	
	//���������Ԫ��
	for (int i = k; i < n; i++) {
		int top = HeapTop(&hp);
		if (a[i] > top) {
			HeapPop(&hp);
			HeapPush(&hp, a[i]);
		}
	}
	HeapPrint(&hp);
}
void TestTopk() {
	int a[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	PrintTopK(a, 10, 3);
}
