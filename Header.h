#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int coef;
	int deg;
	struct node *next;
}node;

node* poly_create(node* head, int num);
void poly_print(node *head);
void free_nodes(node* head);
int poly_count(node *head);
node *task(node *head, float a);