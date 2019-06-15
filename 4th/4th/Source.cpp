#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <time.h>
int** new_mass(const int n) {
	int** mass = new int *[n];
	if (!mass) {
		printf("Ошибка в создании массива\n");
		return NULL;
	}
	for (int i = 0; i < n; i++) {
		mass[i] = new int[n];
		if (!mass[i]) {
			printf("Error in new.\n");
			return NULL;
		}
	}
	return mass;
}
int** del_mass(const int n, int** mass) {
	for (int i = 0; i < n; i++)
		delete[] mass[i];
	delete[] mass;
	return NULL;
}
int** read_mass(int *n) {
	char s[80];
	printf("Введите имя файла: ");
	gets_s(s);
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
	int** mass = new_mass(*n);
	if (!mass) {
		fclose(f);
		return NULL;
	}
	for (int i = 0; i < *n; i++) {
		for (int j = 0; j < *n; j++) {
			if (fscanf(f, "%d", &mass[i][j]) != 1) {
				printf("Ошибка чтения.\n");
				mass = del_mass(*n, mass);
				fclose(f);
				return NULL;
			}
		}
	}
	fclose(f);
	return mass;
}
int save_mass(int n, int** mass) {
	char s[81];
	printf("Введите название файла: ");
	gets_s(s);
	if (strchr(s, '.') == NULL) strcat(s, ".txt");
	FILE *f = fopen(s, "w");
	if (f == NULL) {
		printf("Ошибка при открытии\n");
		return 1;
	}
	fprintf(f, "%i\n", n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			fprintf(f, "%d ", mass[i][j]);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 1;
}
int print_mass(const int n, int** mass) {
	printf("\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", mass[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	return 0;
}
int mult_mass(const int n, int** A, int** B) {
	int** a_mass;		//A
	int** b_mass;		//B
	int** e_mass;		//E
	char ch;
	char s[50];

	a_mass = new_mass(n);
	b_mass = new_mass(n);
	e_mass = new_mass(n);							//(A - 3E)^2
	if (!a_mass) { return 1; }

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a_mass[i][j] = 0;						//A в нули
			b_mass[i][j] = 0;						//B в нули
			e_mass[i][j] = 0;						//E в нули
		}
		e_mass[i][i] = 3;							//A -> E
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a_mass[i][j] = A[i][j] - e_mass[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				b_mass[i][j] += a_mass[i][k] * a_mass[k][j];
			}
		}
	}

	printf("Результирующая матрица:\n");
	print_mass(n, b_mass);
	printf("Сохранить массив в фаил? (y/n) ");
	gets_s(s);
	ch = s[0];

	if (ch == 'y') {
		save_mass(n, b_mass);
	}
	a_mass = del_mass(n, a_mass);
	a_mass = del_mass(n, b_mass);
	a_mass = del_mass(n, e_mass);
	return 0;
}
int** keyboard(int *n) {
	int** mass;
	mass = new_mass(*n);
	printf("Введите значение массива A:\n");
	for (int i = 0; i < *n; i++)
		for (int j = 0; j < *n; j++) {
			printf("A[%d][%d] = ", i, j);
			scanf("%d", &mass[i][j]);
		}
	return mass;
}
int main() {
	setlocale(LC_ALL, "rus");
	int n;
	int** A;
	char ch;
	char s[81];
	do {
		printf("Заполнить массив с клавиатуры? (y/n) ");
		gets_s(s);
		ch = s[0];
		if (ch == 'y') {
			printf("Введите размерность матрицы: ");
			scanf("%d", &n);
			A = keyboard(&n);
		}
		else {
			printf("Введите название файла: ");
			A = read_mass(&n);
		}
		gets_s(s);
		if (A) {
			printf("\nНачальная матрица:\n");
			print_mass(n, A);
			mult_mass(n, A, A);
			A = del_mass(n, A);
		}

		printf("Повторить? (y/n) ");
		gets_s(s);
		ch = s[0];

		while ((ch != 'y') && (ch != 'n')) {
			printf("Нажмите \"y\" для повтора или \"n\" выхода: ");
			gets_s(s);
			ch = s[0];
		}
	}
	while (ch == 'y');

	return 0;
}