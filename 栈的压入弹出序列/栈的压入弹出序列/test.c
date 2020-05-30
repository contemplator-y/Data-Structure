#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

/*
���������У���һ����������ջ��˳���жϵڶ��������Ƿ�Ϊ����˳��
*/

#define true 1
#define false 0
#define bool int

typedef struct stack{
	int* arr;
	int size;
	int capacity;
}stack;

void stackInit(stack* st) {
	st->arr = (int*)malloc(sizeof(int) * 10);
	st->size = 0;
	st->capacity = 10;
}

void stackPush(stack* st, int val) {
	if (st->size == st->capacity) {
		st->capacity *= 2;
		st->arr = (int*)realloc(st->arr, sizeof(int) * st->capacity);
	}
	st->arr[st->size++] = val;
}
void stackPop(stack* st) {
	st->size--;
}

bool stackEmpty(stack* st) {
	return st->size == 0;
}

int stackTop(stack* st) {
	return st->arr[st->size - 1];
}
void stackDestory(stack* st) {
	free(st->arr);
	st->size = st->capacity = 0;
}


bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
	if (pushedSize == 0)
		return true;

	stack st;
	stackInit(&st);
	int idx1 = 0, idx2 = 0;

	while (idx1 < pushedSize) {
		//�����е�ǰԪ�����
		if (pushed[idx1] == popped[idx2]) {
			idx1++;
			idx2++;
		}
		else if (stackEmpty(&st)) {
			//��ǰԪ�ز������ջΪ��
			stackPush(&st, pushed[idx1++]);
		}
		else if (stackTop(&st) == popped[idx2]) {
			//����2��ǰԪ����ջ��Ԫ�����
			stackPop(&st);
			idx2++;
		}
		else {
			//����2��ǰԪ����ջ����1�е�ǰԪ�ؾ������
			stackPush(&st, pushed[idx1++]);
		}
	}
	if (idx2 == poppedSize)
		return true;
	while (!stackEmpty(&st)) {
		int top = stackTop(&st);
		if (top == popped[idx2]) {
			stackPop(&st);
			idx2++;
		}
		else {
			return false;
		}
	}

	return true;
}
int main() {
	int arr1[] = { 1, 2, 3, 4, 5 };
	int arr2[] = { 4, 5, 3, 2, 1 };
	bool ret = validateStackSequences(arr1, 5, arr2, 5);
	printf("%d\n", ret);

	system("pause");
	return 0;
}