struct List {
	int key;
	List* next;
};
void Make_List(int n, List** Head);
void Print_List(List* Head);
List* Delete_Item_List(List* &Head, int Number);
int Find_Item_List(List* head, int dataitem);
void Delete_List(List* head);
void first_elem(List* *head, int d);
void add(List *head, int key);
List* getLast(List *head);