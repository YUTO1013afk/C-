#include <stdio.h>
//typedef struct{	/* �\���̐錾 */
//	double wa;
//	double sa;
//	double seki;
//	double sho;
//}enzan;
//
//enzan sisoku(double x, double y);
//
//int main(void)
//{
//	double x = 2.0, y = 5.0;
//	enzan s;
//	s = sisoku(x, y); /* �\���̂̑�� */
//	printf("wa = %f sa = %f\n", s.wa, s.sa);
//	printf("seki = %f sho = %f\n", s.seki, s.sho);
//	return 0;
//}
//
//enzan sisoku(double x, double y)
//{
//	enzan p;
//	p.wa = x + y;
//	p.sa = x - y;
//	p.seki = x * y;
//	p.sho = x / y;
//	return p;	/* �߂�l���\���� */
//}