#include "head.h"
using namespace std;



gsl_matrix* GetInverse(gsl_matrix *A)
{
	int n = A->size1;
	int sign = 0;
	gsl_matrix *inverse;

	gsl_matrix *tmpA = gsl_matrix_alloc(n, n);
	gsl_matrix_memcpy(tmpA, A);
	gsl_permutation *p = gsl_permutation_alloc(n);

	gsl_linalg_LU_decomp(tmpA, p, &sign);
	inverse = gsl_matrix_alloc(n, n);
	gsl_linalg_LU_invert(tmpA, p, inverse);
	gsl_permutation_free(p);
	gsl_matrix_free(tmpA);
	return inverse;
}	// inverse of A
inline void GetRand(gsl_matrix * m)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			// gsl_matrix_set( m, i, j, 0.23 + 100*i + j );
			gsl_matrix_set(m, i, j, 10 * rand() / (double)RAND_MAX);
		}
	}

}
inline void Show_matrix(gsl_matrix * m)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << std::left << setw(12) << setprecision(6) <<
				gsl_matrix_get(m, i, j) << std::right << setw(2);
		}
		cout << endl;
	}
}


int main(void)
{
	gsl_matrix * m = gsl_matrix_alloc(N, N);
	gsl_matrix * m_inv;
	GetRand(m);										//获得随机数组。
	cout << "随机矩阵: " << endl;
	Show_matrix(m);									//显示随机数组。	
	cout << "随机矩阵的逆: " << endl;
	m_inv = GetInverse(m);							//随机数组求逆。
	Show_matrix(m_inv);								//显示随机数组的逆。

	gsl_matrix_free(m);
	gsl_matrix_free(m_inv);
	system("pause");
	return 0;
}