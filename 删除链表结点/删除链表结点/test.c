#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType data;
	struct SListNode* next;
}SListNode;

typedef struct SList {
	SListNode* head;
}SList;

//�������
SListNode* BuySListNode(SLTDateType x) {
	SListNode* node = (SListNode*)malloc(sizeof(SListNode));
	node->data = x;
	node->next = NULL;
	return node;
}
// �������ӡ
void SListPrint(SListNode* plist) {
	while (plist) {
		printf("%d->", plist->data);
		plist = plist->next;
	}
	printf("NULL\n");
}

// �������ͷ��
void SListPushFront(SListNode** pplist, SLTDateType x) {
	SListNode* node = BuySListNode(x);
	//�ձ�
	if (*pplist == NULL) {
		*pplist = node;
		return;
	}
	//�ǿ�
	node->next = *pplist;
	*pplist = node;
}

// ���������
SListNode* SListFind(SListNode* plist, SLTDateType x) {
	if (plist == NULL) {
		return NULL;
	}
	while (plist) {
		if (plist->data == x) {
			return plist;
		}
		plist = plist->next;
	}
	return NULL;
}

//ɾ����ǰ���
void deleteNode(SListNode** head, SListNode* tar) {
	if (head == NULL || *head == NULL) {
		return;
	}
	//��ǰ���Ϊβ���
	if (tar->next == NULL) {
		SListNode* pre = NULL;
		SListNode* cur = *head;
		while (cur != tar) {
			pre = cur;
			cur = cur->next;
		}
		//��ǰ���Ҳ��ͷ���
		if (pre == NULL) {
			free(*head);
			*head = NULL;
		} else {
			pre->next = NULL;
			free(cur);
		}
	} else {
		SListNode* next = tar->next;
	    //������һ����data����ǰ��㣬ɾ����һ�����
		tar->data = next->data;
		tar->next = next->next;
		free(next);
	}
}
// �����������
void SListDestory(SList* sl) {
	if (sl == NULL || sl->head == NULL) {
		return;
	}
	SListNode* cur = sl->head;
	while (cur) {
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	sl->head = NULL;
	printf("���ٵ�����ɹ���\n");
}

int main() {
	SList sl = { NULL };
	SListPushFront(&sl.head, 1);
	
	SListNode* pos = SListFind(sl.head, 1);
	deleteNode(&sl.head, pos);
	SListPrint(sl.head);
	SListDestory(&sl);

	system("pause");
	return 0;
}