#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include "struct.h"
aeroflot* new_string(int n) {
	aeroflot* string = new aeroflot[n];
	if (!string) {
		printf("Ошибка в создании массива\n");
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
	printf("Введите имя файла: ");
	gets_s(s);
	if (strchr(s, '.') == NULL) strcat(s, ".txt");
	FILE *f = fopen(s, "r");
	if (!f) {
		printf("Ошибка открытия.\n");
		return NULL;
	}
	if (fscanf(f, "%i", n) != 1) {
		printf("Ошибка чтения.\n");
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
			printf("Ошибка чтения.\n");
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
	printf("\nВведите название файла для сохранения: ");
	scanf("%c", s);
	if (strchr(s, '.') == NULL) strcat(s, ".txt");
	FILE *f = fopen(s, "w");
	if (f == NULL) {
		printf("Ошибка при открытии\n");
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
	printf("Сохранено.\n");
	return 0;
}
void print_string(int n, aeroflot* mas) {
	for (int i = 0; i < n; i++) {
		printf("%d | Пункт назначения: %s\n", i+1, mas[i].dest);
		printf("%d | Номер рейса: %d\n", i+1, mas[i].number);
		printf("%d | Тип самолета: %s\n", i+1, mas[i].type);
		printf("%d | Количество занятых мест: %d\n", i+1, mas[i].occupied);
		printf("%d | Общее количество мест: %d\n", i+1, mas[i].all);
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
		printf("%d | Название пункта назначения рейса: ", i+1);		scanf("%s", &mas[i].dest);
		printf("%d | Номер рейса: ", i+1);							scanf("%d", &mas[i].number);
		printf("%d | Тип самолета: ", i+1);							scanf("%s", &mas[i].type);
		printf("%d | Количество занятых мест: ", i+1);				scanf("%d", &mas[i].occupied);
		printf("%d | Общее количество мест: ", i+1);					scanf("%d", &mas[i].all);
		printf("-------------------------------------\n");
		order(n, mas);
	}
	return;
}
void print_flight(int n, aeroflot* mas) {
	int tmp, flag = 0;
	printf("Введите номер рейса: ");
	scanf("%d", &tmp);
	printf("-------------------------------------\n");
	for (int i = 0; i < n; i++) {
		if (mas[i].number == tmp) {
			printf("%d | Пункт назначения: %s\n", i, mas[i].dest);
			printf("%d | Номер рейса: %d\n", i, mas[i].number);
			printf("%d | Тип самолета: %s\n", i, mas[i].type);
			printf("%d | Количество свободных мест: %d\n\n", i, mas[i].all - mas[i].occupied);
			printf("-------------------------------------\n");
			flag = 1;
		}
	}
	if (flag == 0) printf("Рейсы с таким номером не найдены.\n");
}