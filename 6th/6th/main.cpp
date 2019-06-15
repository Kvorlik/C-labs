#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "struct.h"

aeroflot* new_string(int n);
aeroflot* del_string(int n, aeroflot* mas);
aeroflot* read_string(int *n);
int save_string(int n, aeroflot* string);
void print_string(int n, aeroflot* mas);
void order(int n, aeroflot* mas);
void input(int n, aeroflot* mas);
void print_flight(int n, aeroflot* mas);

int main() {
	setlocale(LC_ALL, "rus");
	int tmp = 0;
	int size = 2;
	int sel = NULL;
	int save_sel = NULL;
	aeroflot* mas = 0;

	printf("��������� ��������� ���� ������ ���������.\n�������� ��������:\n");
	do {
		printf("1. �������� ��������\n");
		printf("2. �������� ���� ������ ������\n");
		printf("3. �������� ������ ������ �� ������ �����\n");
		printf("4. ��������� �� �����\n");
		printf("5. �����\n");
		printf("��������� (1-5): ");
		scanf("%d", &tmp);
		while ((tmp != 1) && (tmp != 2) && (tmp != 3) && (tmp != 4) && (tmp != 5)) {
			printf("��������� (1-5): ");
			scanf("%d", &tmp);
		}
		switch (tmp) {
		case 1:
			printf("���������� ����������� ���������: ");
			size += scanf("%d", &size) - 1;
			mas = new_string(size);
			input(size, mas);
			printf("��������� ������ � ���� (1/0)? ");
			scanf("%d", &save_sel);
			while ((tmp != 1) && (tmp != 0)) {
				printf("��������� ������ � ���� (1/0)? ");
				scanf("%d", &save_sel);
			}
			if (save_sel == 1) { save_string(size, mas); save_sel = 0; }
			else { save_sel = 0;  break; }
		case 2:
			if (mas == 0) {
				printf("������� ���������� �������� ������� � ����\n");
				break;
			}
			printf("� | ������\n");
			print_string(size, mas);
			break;
		case 3:
			printf("� | ������\n");
			print_flight(size, mas);
			break;
		case 4:
			mas = read_string(&size);
			printf("������ �������. ������� �� �� ������� (1/0)? ");
			scanf("%d", &save_sel);
			while ((sel != 1) && (sel != 0)) {
				printf("������ �������. ������� �� �� ������� (1/0)? ");
				scanf("%d", &save_sel);
			}
			if (save_sel == 1) { print_string(size, mas); save_sel = 0; }
			else { save_sel = 0;  break; }
		case 5:
			mas = del_string(size, mas);
			return 0;
		}

		printf("\n> ��������� � ���� (1/0)? ");
		scanf("%d", &sel);
		while ((sel != 1) && (sel != 0)) {
			printf("������� \"1\" ��� ������� ��� \"0\" ������: ");
			scanf("%d", &sel);
		}
	} while (sel == 1);

	mas = del_string(size, mas);
	return 0;
}