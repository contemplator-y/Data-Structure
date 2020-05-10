#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

void reversePrintList(struct ListNode* head, int* arr, int* idx) {
	if (head == NULL) {
		return;
	}
	if (head->next == NULL) {
		arr[*idx] = head->val;
		++(*idx);
		return;
	}
	reversePrintList(head->next, arr, idx);
	arr[*idx] = head->val;
	++(*idx);
}
int* reversePrint(struct ListNode* head, int* returnSize){
	int size = 0;
	//ͳ�ƽ�����
	struct ListNode* cur = head;
	while (cur) {
		size++;
		cur = cur->next;
	}

	//���ռ�
	int* res = (int*)malloc(sizeof(int) * size);
	*returnSize = size;
	if (size == 0) {
		return res;
	}
	//�ݹ�ʵ���������
	int idx = 0;
	reversePrintList(head, res, &idx);

	return res;
}

int main() {
	system("pause");
	return 0;
}