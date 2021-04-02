#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "util.h"

int is_large(int num1, int num2)
{
	return num1 > num2;
}

int sum_x(int x1, int x2)
{
	int sum = 0;
	/* Fill this function */
	sum = x1 + x2;

	return sum;
}

void sub_y(int y1, int y2, int *sub)
{
	/* Fill this function */
	*sub = y1 - y2;
}

// You have to allocate memory for pointer members of "struct Point_ref"
// Hint: Use malloc()
void Point_val_to_Point_ref(struct Point_val *P1, struct Point_ref *P2)
{
	/* Fill this function */
	P2 = malloc(sizeof(struct Point_ref));

	P2->x = &P1->x;
	P2->y = &P1->y;

}

void Point_ref_to_Point_val(struct Point_ref *P1, struct Point_val *P2)
{
	/* Fill this function */
	P2->x = *P1->x;
	P2->y = *P1->y;
}

int calc_area1(struct Point_val *P1, struct Point_val *P2)
{
	/* Fill this function */
	int area = 0;
	int hor = 0;
	int ver = 0;

	sub_y(P1->x, P2->x, &ver);
	sub_y(P1->y, P2->y, &hor);

	area = ver * hor;

	if(area < 0) area = area * (-1);
	
	return area;
}

void calc_area2(struct Point_ref *P1, struct Point_ref *P2, int *area)
{
	/* Fill this function */
	int hor = 0;
	int ver = 0;
	int temp = 0;

	sub_y(*P1->x, *P2->x, &ver);
	sub_y(*P1->y, *P2->y, &hor);

	temp = ver * hor;

	if(temp < 0) temp = temp * (-1);

	area = &temp;
}

char* reverse(char *word)
{
	/* Fill this function */
	char temp[1024];
	int i = strlen(word);
	int j = 0;

	while(i >= 0){
		temp[j] = word[i-1];
		j++;
		i--;
	}

	strcpy(word, temp);

	return word;
}
