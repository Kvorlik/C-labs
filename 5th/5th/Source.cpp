#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
char* new_string(const int n) {
	char* string = new char [n];
	if (!string) {
		printf("������ � �������� �������\n");
		return NULL;
	}
	return string;
}
char* del_string(char* string) {
	delete[] string;
	return NULL;
}
char* read_string(int *n) {
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
	char* string = new_string(*n);
	if (!string) {
		fclose(f);
		return NULL;
	}
	for (int i = 0; i < *n; i++) {
			if (fscanf(f, "%c", &string[i]) != 1) {
				printf("������ ������.\n");
				string = del_string(string);
				fclose(f);
				return NULL;
			}
		}
	fclose(f);
	return string;
}
char save_string(int n, char* string) {
	int flag = 0;
	char s[81];
	printf("\n������� �������� ����� ��� ���������� ������: ");
	gets_s(s);
	if (strchr(s, '.') == NULL) strcat(s, ".txt");
	FILE *f = fopen(s, "w");
	if (f == NULL) {
		printf("������ ��� ��������\n");
		return 1;
	}
	fprintf(f, "%i", n);
	for (int i = 0; i < n; i++) {
		if (string[i] == 'x') {
			if (flag == 0) {
				fprintf(f, "ks");
				flag = 1;
			}
			else fprintf(f, "%c", string[i]);
		}
		else fprintf(f, "%c", string[i]);
	}
	fclose(f);
	printf("���������.\n");
	return 1;
}
void print_string(const int n, char* string) {
	printf("������: ");
	for (int i = 0; i < n; i++) {
		if (string[i] == 'x') {
			printf("ks");
		}
		else printf("%c", string[i]);
	}
	printf("\n");
}
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	char* string;
	printf("��������� �������� ������ \'x\' �� ������� \'ks\'\n");
	if ((string = read_string(&n)) == NULL) return 0;
	print_string(n, string);
	save_string(n, string);
	return 0;
}