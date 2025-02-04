#include <stdio.h>
#include <stdlib.h>
//int main(void)
//{
//	int **a, total = 0, i, j, nrows = 3, ncolumns = 4;
//	a = (int **)malloc(nrows * sizeof(int*));
//	a[0] = (int *)malloc(nrows * ncolumns * sizeof(int));
//	for (i = 1; i < nrows; i++) {
//		a[i] = a[0] + i * ncolumns;
//	}
//	a[0][0] = 10; a[0][1] = 11; a[0][2] = 12; a[0][3] = 13;// a[0][4] = 14;
//	a[1][0] = 20; a[1][1] = 21; a[1][2] = 22; a[1][3] = 23;
//	a[2][0] = 30; a[2][1] = 31; a[2][2] = 32; a[2][3] = 33;
//
//	for (i = 0; i < nrows; i++) {
//		for (j = 0; j < ncolumns; j++) {
//			total += a[i][j];
//		}
//	}
//	printf("result = %d\n", total);
//	free(a);
//	return 0;
//}