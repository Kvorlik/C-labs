#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "struct.h"
aeroflot* new_string(int n) {
	aeroflot* string = new aeroflot[n];
	if (!string) {
		printf("������ � �������� �������\n");
		return NULL;
	}
	return string;
}
aeroflot* del_string(int n, aeroflot* mas) {
	for (int i = 0; i < n; i++) {
		mas[i].dest[20] = NULL;
		mas[i].number = NULL;
		mas[i].type[20] = NULL;
		mas[i].occupied = NULL;
		mas[i].all = NULL;
	}
	delete[] mas;
	return NULL;
}
aeroflot* read_string(int *n) {
	char s[80];
	printf("������� ��� �����: ");
	gets_s(s);
	if (strchr(s, '.') == NULL) strcat(s, ".txt");
	FILE *f = fopen(s, "r");
	if (!f) {
		printf("������ ��������.\n");
		return NULL;
	}
	if (fscanf(f, "%i", n) != 1) {
		printf("������ ������.\n");
		fclose(f);
		return NULL;
	}
	aeroflot* mas = new_string(*n);
	if (!mas) {
		fclose(f);
		return NULL;
	}
	for (int i = 0; i < *n; i++) {
		if (
			fscanf(f, "%i", n) ||
			fscanf(f, "%s", &mas[i].dest) ||
			fscanf(f, "%d", &mas[i].number) ||
			fscanf(f, "%s", &mas[i].type) ||
			fscanf(f, "%d", &mas[i].occupied) ||
			fscanf(f, "%d", &mas[i].all)
			!= 1) {
			printf("������ ������.\n");
			mas = del_string(*n, mas);
			fclose(f);
			return NULL;
		}
	}
	fclose(f);
	return mas;
}
int save_string(int n, aeroflot* string) {
	char s[81];
	printf("\n������� �������� ����� ��� ����������: ");
	scanf("%c", s);
	if (strchr(s, '.') == NULL) strcat(s, ".txt");
	FILE *f = fopen(s, "w");
	if (f == NULL) {
		printf("������ ��� ��������\n");
		return 1;
	}
	fprintf(f, "%i", n);
	for (int i = 0; i < n; i++) {
		fprintf(f, "%s", string[i].dest);
		fprintf(f, "%d", string[i].number);
		fprintf(f, "%s", string[i].type);
		fprintf(f, "%d", string[i].occupied);
		fprintf(f, "%d", string[i].all);
	}
	fclose(f);
	printf("���������.\n");
	return 0;
}
void print_string(int n, aeroflot* mas) {
	for (int i = 0; i < n; i++) {
		printf("%d | ����� ����������: %s\n", i+1, mas[i].dest);
		printf("%d | ����� �����: %d\n", i+1, mas[i].number);
		printf("%d | ��� ��������: %s\n", i+1, mas[i].type);
		printf("%d | ���������� ������� ����: %d\n", i+1, mas[i].occupied);
		printf("%d | ����� ���������� ����: %d\n", i+1, mas[i].all);
		printf("-------------------------------------\n");
	}

}
void order(int n, aeroflot* mas) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (strcmp(mas[i].dest, mas[j].dest) > 0) {
				aeroflot tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}
	}
	return;
}
void input(int n, aeroflot* mas) {
	for (int i = 0; i < n; i++) {
		printf("%d | �������� ������ ���������� �����: ", i+1);		scanf("%s", &mas[i].dest);
		printf("%d | ����� �����: ", i+1);							scanf("%d", &mas[i].number);
		printf("%d | ��� ��������: ", i+1);							scanf("%s", &mas[i].type);
		printf("%d | ���������� ������� ����: ", i+1);				scanf("%d", &mas[i].occupied);
		printf("%d | ����� ���������� ����: ", i+1);					scanf("%d", &mas[i].all);
		printf("-------------------------------------\n");
		order(n, mas);
	}
	return;
}
void print_flight(int n, aeroflot* mas) {
	int tmp, flag = 0;
	printf("������� ����� �����: ");
	scanf("%d", &tmp);
	printf("-------------------------------------\n");
	for (int i = 0; i < n; i++) {
		if (mas[i].number == tmp) {
			printf("%d | ����� ����������: %s\n", i, mas[i].dest);
			printf("%d | ����� �����: %d\n", i, mas[i].number);
			printf("%d | ��� ��������: %s\n", i, mas[i].type);
			printf("%d | ���������� ��������� ����: %d\n\n", i, mas[i].all - mas[i].occupied);
			printf("-------------------------------------\n");
			flag = 1;
		}
	}
	if (flag == 0) printf("����� � ����� ������� �� �������.\n");
}