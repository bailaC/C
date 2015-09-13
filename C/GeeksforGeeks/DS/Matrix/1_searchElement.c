#include <stdio.h>
#include <stdlib.h>

/* Input format :
	<no. of testcase>
	<rows> <columns>
	(row wise elements)
	<element to search>
*/

void printMatrix (int **, int, int);



int main () {

	int row, col, r, c, i, j, iTCCount, x, match;
	int **matrix;
	scanf ("%d", &iTCCount ) ;
	
	while ( iTCCount--) {
		scanf ("%d %d", &row, &col);
		matrix = (int **) malloc (sizeof(int *) * row);

		for (i = 0; i < row; i++) {
			matrix[i] = (int *) malloc (sizeof(int) * col);
			for (j = 0; j < col; j++) {
				scanf ("%d", &matrix[i][j]);
			}

		}
		scanf ("%d", &x);
		match = 0;
		r = 0;
		c = col - 1;

		while (c >= 0 && r < row ) {
			if (matrix[r][c] == x) {
				printf("Match found at (%d, %d)\n", r + 1, c + 1);
				match = 1;
				break;
			}

			if (matrix[r][c] < x) {
				r++;
			} else {
				c--;
			} 
		}
		if (!match) {
			printf("No match found\n");
		}
		
		//printMatrix(matrix, row, col);
	}
}

/* prints the elements of the matrix */
void printMatrix (int **ip, int row, int column) {
	int i, j;

	for (i = 0; i < row; i++ ) {
		for (j = 0; j < column; j ++) {
			printf("%d\t", ip[i][j]);
		}
		printf("\n");
	}
}