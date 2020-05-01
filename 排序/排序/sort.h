#pragma once
#include <stdlib.h>
#include <stdio.h>

//��ӡ����
void printArr(int* arr, int n);
//��������
void insertSort(int* arr, int n);
//ϣ������
void shellSort(int* arr, int n);
//ѡ������
void selectSort(int* arr, int n);

//������
void shiftDown(int* arr, int n, int parent);
void heapSort(int*arr, int n);
//ð������
void bubbleSort(int* arr, int n);

//��������ݹ�ʵ��
//hoare���ַ���
int partion1(int* arr, int start, int end);
//�ڿӻ��ַ�
int partion2(int* arr, int start, int end);
//ǰ��ָ�뻮�ַ�
int partion3(int* arr, int start, int end);
void quickSort(int* arr, int start, int end);
