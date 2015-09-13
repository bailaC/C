#include <stdio.h>
#include <stdlib.h>

/* Input format :
	<no. of testcase>
	<rows> <columns>
	(row wise elements)
*/

void printMatrix (int **, int, int);



int main () {

	int row, col, r, c, i, j, iTCCount;
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

		r = 0;
		c = 0;

		while (row > 0 && col > 0 ) {

			/* print a row from left to right */
			for (i = 0; i < col; i++) {
				printf("%d ", matrix[r][c++]);
			}
			row--; r++; c--;

			/* print a column from top to bottom */
			for (i = 0; i < row; i++) {
				printf("%d ", matrix[r++][c]);
			}
			col--; r--; c--;

			/* print a row from right to left */
			if (row > 0) {
				for (i = 0; i < col; i++) {
					printf("%d ", matrix[r][c--]);
				}
				row--; r--; c++;
			}			

			/* print a column from bottom to top */
			if (col > 0) {
				for (i = 0; i < row; i++) {
					printf("%d ", matrix[r--][c]);
				}
				col--; r++; c++;
			}			
		}
		printf("\n");
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