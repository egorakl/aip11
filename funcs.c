#include "Header.h"

int int_input() {
	int input;
	char temp;
	if ((scanf_s("%d%c", &input, &temp) != 2 || temp != '\n')) {
		printf("Error: invalid input\n");
		exit(-1);
	}
	return input;
}

node* add_node() {   // Добавление элемента
	node* n = malloc(sizeof(node));
	printf("Enter the degree of x: ");
	n->deg = int_input();
	printf("Enter coefficient: ");
	n->coef = int_input();

	while (n->deg < 0) {   // Если введена отрицательная степень
		printf("Degree can not be less than zero!\nEnter coefficient: ");
		n->deg = int_input();
	}

	while (n->coef == 0) {   // Если введен нулевой коэффициент
		printf("Coeff cannot be equal to zero!\nEnter coefficient: ");
		n->coef = int_input();
	}
	n->next = NULL;
	return n;
}

int deg_repeat(node* head, node* n) {   // Возвращает 1, если степени повторяются
		while (head != NULL) {
			if (head->deg == n->deg)
				return 1;
			head = head->next;
		}
	return 0;
}

node* poly_create(node* head, int num) {
	head = add_node();
	node *n = head;
	for (int i = 1; i < num; i++) {
		node* n1 = add_node();
		if (deg_repeat(head, n1)) {   // Проверка на повторяющиеся степени
			printf("Error: this degree already exists\n");
			free_nodes(n1);
			free_nodes(head);
			exit(-1);
		}
		n->next = n1;
		n = n1;
	}
	return head;
}

int poly_count(node *head) {   //   Подсчет элементов многочлена
	node *nd = head;
	int n = 0;
	while (nd != NULL) {
		nd = nd->next;
		n++;
	}
	return n;
}

void poly_print(node *head) {   //  Вывод многочлена на экран
	node *nd = head;
	int n = poly_count(head);
	if (n == 0) {    //  Если многочлен пуст
		printf("**the polynom is empty**");
		return;
	}
	for (int i = 0; i < n - 1; i++) {
		if (nd->deg == 0) {
			printf("%d + ", nd->coef);
		}
		else printf("%dx^%d + ", nd->coef, nd->deg);
		nd = nd->next;
	}
	printf("%dx^%d\n", nd->coef, nd->deg);
}

node *task(node *head, float a) {

	node *temp1;

	while (head != NULL) {   
		if (head->coef > a) {   //  Удаляем первые элементы с коэффициентом, большим a
			temp1 = head;
			head = head->next;
			free(temp1);
		}
		else break;
	}

	node *temp;
	int n = poly_count(head);
	for (int i = 0; i < n; i++) {    //  Удаление остальных элементов
		temp = head;
		while (temp != NULL && temp->next != NULL){
			if (temp->next->coef > a) {
				temp1 = temp->next;
				temp->next = temp->next->next;
				free(temp1);
			}
			temp = temp->next;
		}
	}
		
	return head;
}

void free_nodes(node* head) {    //  Освобождение памяти
	node* n;
	while (head != NULL) {
		n = head;
		head = head->next;
		free(n);
	}
}