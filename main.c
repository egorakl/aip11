#include "Header.h"

int main()
{
	node *p = NULL, *p2=NULL;
	int n;
	float a;
	char temp;

	printf("Enter the number of terms: ");
	if ((scanf_s("%d%c", &n, &temp) != 2 || temp != '\n' || n<=0)) {
		printf("Error: invalid input\n");
		exit(-1);
	}
	printf("\n");
	p = poly_create(p, n);
	printf("\n");
	poly_print(p);
	printf("\nEnter a: ");
	if ((scanf_s("%f%c", &a, &temp) != 2 || temp != '\n')) {
		printf("Error: invalid input\n");
		exit(-1);
	}

	p2 = task(p, a);
	printf("Result:\n");
	poly_print(p2);
	free_nodes(p2);
	return 0;
}
