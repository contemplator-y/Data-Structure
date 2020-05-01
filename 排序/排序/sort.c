#define _CRT_SECURE_NO_WARNINGS 1
#include "sort.h"

//��ӡ����
void printArr(int* arr, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

//��������
void Swap(int* arr, int left, int right) {
	int tmp = arr[left];
	arr[left] = arr[right];
	arr[right] = tmp;
}
//��������
void insertSort(int* arr, int n) {
	//��δ�����λ�ÿ�ʼ��ǰѰ�ҿɲ����λ��
	for (int bound = 0; bound < n - 1; bound++) {
		//Ѱ�Һ���λ��
		int key = arr[bound + 1], i = bound;
		for (; i >= 0; i--) {
			if (key < arr[i]) {
				arr[i + 1] = arr[i];
			} else {
				break;
			}
		}
		//��������
		arr[i + 1] = key;
	}
}
//ϣ������
void shellSort(int* arr, int n) {
	int gap = n;
	while (gap > 1) {
		gap /= 2;
		//��δ�����λ�ÿ�ʼ��ǰѰ�ҿɲ����λ��
		for (int bound = 0; bound < n - gap; bound++) {
			//Ѱ�Һ���λ��
			int key = arr[bound + gap], i = bound;
			for (; i >= 0; i -= gap) {
				if (key < arr[i]) {
					arr[i + gap] = arr[i];
				} else {
					break;
				}
			}
			//��������
			arr[i + gap] = key;
		}
	}
}

//ѡ������
void selectSort(int* arr, int n) {
	for (int i = 0; i < n - 1; i++) {
		//��¼δ��������ֵ������
		int min = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min]) {
				min = j;
			}
		}
		Swap(arr, min, i);
	}
}
//������
void shiftDown(int* arr, int n, int parent) {
	int child = 2 * parent + 1;
	while (child < n) {
		if (child + 1 < n && arr[child + 1] > arr[child])
			child++;
		if (arr[child] > arr[parent]) {
			Swap(arr, child, parent);
			parent = child;
			child = 2 * parent + 1;
		} else {
			break;
		}
	}
}
void heapSort(int* arr, int n) {
	//ԭ�ؽ���
	for (int i = (n - 2) / 2; i >= 0; i--) {
		shiftDown(arr, n, i);
	}
	//ѭ��ɾ���Ѷ�Ԫ��
	while (n) {
		Swap(arr, 0, n - 1);
		n--;
		shiftDown(arr, n, 0);
	}
}
//ð������
void bubbleSort(int* arr, int n) {
	for (int bound = 0; bound < n - 1; bound++) {
		//��ӱ��flag���ڷ���ʣ��δ���򲿷��Ѿ�����ʱ����ѭ��,flagΪ1��ʾ����
		int flag = 1;
		for (int i = n - 1; i > bound; i--) {
			if (arr[i] < arr[i - 1]) {
				Swap(arr, i, i - 1);
				flag = 0;
			}
		}
		if (flag)
			break;
	}
}

//��������ݹ�ʵ��
//hoare���ַ���
int partion1(int* arr, int start, int end) {
	int key = arr[start], keyPos = start;
	while (start < end) {
		//�Ӻ���ǰ�ҵ�һ��С��key��λ��
		while (start < end && arr[end] >= key)
			end--;
		//��ǰ�����ҵ�һ������key��λ��
		while (start < end && arr[start] <= key)
			start++;
		//����end��start����Ԫ��
		Swap(arr, end, start);
	}
	//����׼ֵ��������λ�ô�����
	Swap(arr, end, keyPos);
	return end;
}
//�ڿӻ��ַ�
int partion2(int* arr, int start, int end) {
	int key = arr[start];
	while (start < end) {
		//�Ӻ���ǰ�ҵ�һ��С��key��λ��
		while (start < end && arr[end] >= key)
			end--;
		//��Ԫ���������
		arr[start] = arr[end];
		//��ǰ�����ҵ�һ������key��λ��
		while (start < end && arr[start] <= key)
			start++;
		arr[end] = arr[start]; 
	}
	//����׼ֵ�������
	arr[start] = key;
	return start;
}
//ǰ��ָ�뻮�ַ�
int partion3(int* arr, int start, int end) {
	int key = arr[start];
	//���һ��С�ڻ�׼ֵ��λ��
	int pre = start;
	//��һ��С�ڻ�׼ֵ��λ��
	int cur = start + 1;
	while (cur <= end) {
		//�·��ֵ�С���ݺ�βָ��ָ���λ�ò����������м京�д��ڻ�׼ֵ�����ݣ��ʽ��н���
		//����������ƶ���С������ǰ�ƶ�
		if (arr[cur] < key && ++pre != cur)
			Swap(arr, pre, cur);
		++cur;
	}
	Swap(arr, pre, start);
	return pre;
}
void quickSort(int* arr, int start, int end) {
	if (start >= end)
		return;
	int key = arr[start];
	//���ݻ�׼ֵ��������
	int keyPos = partion3(arr, start, end);
	//��������ֱ�����
	quickSort(arr, 0, keyPos - 1);
	quickSort(arr, keyPos + 1, end);
}
