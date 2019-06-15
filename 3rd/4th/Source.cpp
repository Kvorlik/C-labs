#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <ctime>
#include <conio.h>

void manual(int num, int mass[]) {
	for (int i = 0; i < num; i++) {
		printf("������� ������� %d: ", i+1); scanf_s("%d", &mass[i]);
	}
	return;
}

void random(int num, int mass[]) {
	int min, max;
	printf("������� ������ ������� �������: "); scanf_s("%d", &min);
	printf("������� ������� ������� �������: "); scanf_s("%d", &max);
	srand(time(0));
	for (int i = 0; i < num; i++) {
		mass[i] = rand() % (max - min + 1) + min;
	}
	return;
}

void print(int num, int mass[]) {
	for (int i = 0; i < num; i++) {
		printf("������� %d = %d\n", i + 1, mass[i]);
	}
	return;
}

void method(int num, int mass[]) {
	int sel;
	scanf_s("%d", &sel);
	switch(sel) {
	case 1:
		manual(num, mass);
		printf("\n���������� ������:\n");
		print(num, mass);
		break;
	case 2:
		random(num, mass);
		printf("\n���������� ������:\n");
		print(num, mass);
		break;
	}
}

void streak_counter(int num, int mass[]) {
	int tmp = 1;
	int count = 1;
	for (int i = 1; i < num; i++) {
		if (mass[i] == mass[i - 1]) {
			tmp++;
			if (tmp > count) count = tmp;
		}
		else tmp = 1;
	}

	printf("\n����� ������� ����� ���������� ��������� = %d\n", count);

	return;
}

void max_finder(int num, int mass[]) {
	int max = mass[0];
	int flag = 0;

	for (int i = 1; i < num; i++) {
		if (mass[i] == mass[i - 1] || mass[i] == max) {
			flag = 1;
			continue;
		}
		if (mass[i] > max) {
			max = mass[i];
			flag = 0;
		}
	}

	if (flag == 1) printf("������������ �� �����, ������������� ����� ���� ���, �� �������\n");
	else printf("������������ �� �����, ������������� ����� ���� ��� = %d\n", max);
	return;
}

void main() {
	setlocale(LC_ALL, "rus");
	const int number = 10;
	int arr[number];
	printf("������ ����� ���� ��������:\n1) ������� � ����������\n2) ���������� �������\n������������ ������� (1 ��� 2): ");
	method(number, arr);
	streak_counter(number, arr);
	max_finder(number, arr);
	return;
}