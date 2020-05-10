#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fact(int n) {
	int res = 1;
	for (int i = 2; i <= n; i++) {
		res *= i;
	}
	return res;
}

void Swap(char* s, char* t) {
	char tmp = *s;
	*s = *t;
	*t = tmp;
}
//�ݹ�ʵ�����ַ���������
void permu(char* s, char* start, int n, char** res, int* idx) {
	if (strlen(s) == 1) {
		//����
		for (int i = 0; i < *idx; i++) {
			if (!strcmp(res[i], start)) {
				return;
			}
		}
		//�����ַ���
		char* tmp = (char*)malloc(sizeof(char) * (n + 1));
		memcpy(tmp, start, (n + 1));
		res[*idx] = tmp;
		(*idx)++;
		return;
	}
	for (int i = 0; i < strlen(s); i++) {
		//������ǰ�ַ��ͺ�����ַ�Ȼ�������ַ���������
		Swap(s, s + i);
		permu(s + 1, start, n, res, idx);
		//��һ�ν����ַ�
		Swap(s, s + i);
	}
}
char** permutation(char* s, int* returnSize){
	int len = strlen(s);
	char** res = (char**)malloc(sizeof(char*) * fact(len));
	int idx = 0;
	permu(s, s, len, res, &idx);
	*returnSize = idx;

	return res;
}
int main() {
	char s[] = "dkjphedy";
	int size = 0;
	char** res = permutation(s, &size);
	for (int i = 0; i < size; i++) {
		printf("%s\n", res[i]);
	}

	system("pause");
	return 0;
}