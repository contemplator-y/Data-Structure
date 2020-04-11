#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;		// ջ��
	int _capacity;  // ���� 
}Stack;
// ��ʼ��ջ 
void StackInit(Stack* ps) {
	ps->_capacity = 10;
	ps->_a = (STDataType*)malloc(sizeof(STDataType) * ps->_capacity);
	ps->_top = 0;
}
// ��ջ 
void StackPush(Stack* ps, STDataType data) {
	if (ps->_top == ps->_capacity) {
		ps->_capacity *= 2;
		ps->_a = (STDataType *)realloc(ps->_a, ps->_capacity * sizeof(STDataType));
	}
	ps->_a[ps->_top++] = data;
}
// ��ջ 
void StackPop(Stack* ps) {
	if (ps->_top) {
		ps->_top--;
	}
}
// ��ȡջ��Ԫ�� 
STDataType StackTop(Stack* ps) {
	if (ps->_top == 0) {
		return (STDataType)0;
	}
	return ps->_a[ps->_top - 1];
}
// ����ջ 
void StackDestroy(Stack* ps) {
	free(ps->_a);
	ps->_top = ps->_capacity = 0;
	ps->_a = NULL;
}

void reverse(char* s, int start, int end) {
	while (start < end) {
		char tmp = *(s + start);
		*(s + start) = *(s + end);
		*(s + end) = tmp;
		start++;
		end--;
	}
}
char * reverseParentheses(char * s){
	Stack st;
	StackInit(&st);
	if (strlen(s) <= 1) {
		return s;
	}
	int size = strlen(s);
	for (int i = 0; i < size; i++) {
		if (*(s + i) == '(') {
			//��¼�����ŵ�λ��
			StackPush(&st, i);
		}
		else if (*(s + i) == ')') {
			int start = StackTop(&st);
			StackPop(&st);
			int end = i;
			//��ת�����м������
			reverse(s, start + 1, end - 1);
			//ɾ���������,�����м����������һλ�������ź��������������λ
			for (int i = start + 1; i < end; i++) {
				*(s + i - 1) = *(s + i);
			}
			for (int i = end + 1; i <= strlen(s); i++) {
				*(s + i - 2) = *(s + i);
			}
			//�����ַ������Ⱥ�����i
			size -= 2;
			i -= 2;
		}
	}
	StackDestroy(&st);
	return s;
}