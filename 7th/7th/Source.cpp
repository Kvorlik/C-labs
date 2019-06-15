#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
using namespace std;

int main(){
	setlocale(LC_ALL, "rus");
	List* head = 0;
	int tmp;
	int key;

	printf("��������� ��������� ����������� ������\n");

	do {
		printf("\n");
		printf("1. �������� �������\n");
		printf("2. ������� �������\n");
		printf("3. ����� �������� ��������, ��������������� ��������\n");
		printf("4. �����\n");
		printf("��������� (1-4): ");
		scanf("%d", &tmp);
		while ((tmp != 1) && (tmp != 2) && (tmp != 3) && (tmp != 4)) {
			printf("��������� (1-4): ");
			scanf("%d", &tmp);
		}

		switch (tmp) {
		case 1:
			printf("���������� ��������� � ������...\n");
			printf("������� ����: ");
			scanf("%d", &key);
			if (!head) {
				first_elem(&head, key);
				system("cls");
				Print_List(head);
			}
			else {
				add(head, key);
				system("cls");
				Print_List(head);
			}
			key = NULL;
			break;

		case 2:
			printf("�������� ��������...\n");
			printf("������� ����� ��������: ");
			scanf("%d", &key);
			Delete_Item_List(head, key);
			system("cls");
			Print_List(head);
			key = NULL;
			break;
			
		case 3:
			printf("\n");
			printf("������� �������� ��������: ");
			scanf("%d", &key);
			printf("����� ��������...\n");
			printf("�������� ���������� ��������: %d\n", Find_Item_List(head, key));
			Print_List(head);
			key = NULL;
			break;

		case 4:
			return 0;
		}
	} while (true);
}