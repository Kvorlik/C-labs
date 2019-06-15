#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "list.h"
using namespace std;

void Make_List(int n, List** head){
	if (n > 0){
		(*head) = new List();
		printf("Введите значение: ");
		scanf("%d", &((*head)->key));
		(*head)->next = NULL;
		Make_List(n - 1, &((*head)->next));
	}
}

void Print_List(List* head){
	if (head != NULL){
		printf("%d ", head->key);
		Print_List(head->next);
	}
	else printf("\n");
}

List* Delete_Item_List(List* &head, int number){
	List *ptr;
	List *current = head;
	for (int i = 1; i < number && current != NULL; i++)
		current = current->next;
	if (current != NULL){
		if (current == head){
			head = head->next;
			delete(current);
			current = head;
		}
		else {
			ptr = head;
			while (ptr->next != current)
				ptr = ptr->next;
			ptr->next = current->next;
			delete(current);
			current = ptr;
		}
	}
	return head;
}

int Find_Item_List(List* head, int data){
	List *ptr;
	List *prev;
	ptr = head;
	prev = NULL;
	for (int i = 0; i < data; i++) {
		if (data == ptr->key){
			return prev->key;
		}
		else {
			prev = ptr;
			ptr = ptr->next;
		}
	}
	return 0;
}

void Delete_List(List* head) {
	if (head != NULL) {
		Delete_List(head->next);
		delete head;
	}
}

void add(List *head, int key) {
	printf("Добавление элемента в конец списка...\n");
	List *last = getLast(head);
	List *tmp = new List;
	tmp->key = key;
	tmp->next = NULL;
	last->next = tmp;
}

List* getLast(List *head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void first_elem(List* *head, int d){
	printf("Создание списка, первый элемент...\n");
	List* ph = new List;
	ph->key = d;
	ph->next = 0;
	*head = ph;
}