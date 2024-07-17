/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"
#include <cblas.h>
#include <string.h>

/*
 * Program below computes the following formula:
 * C = (A_transposed × B + B × A) × B_transposed.
 * Where A is an upper triangular matrix.
 * This time while only using functions from the BLAS library.
 */
double* my_solver(int N, double *A, double *B) {
	double *A_tranposed_X_B = calloc(N * N, sizeof(double));
	double *B_X_A = calloc(N * N, sizeof(double));
	double *paranthesis_result = calloc(N * N, sizeof(double));
    double *final_result = calloc(N * N, sizeof(double));

	cblas_dcopy(N * N, B, 1, A_tranposed_X_B, 1);
	cblas_dtrmm(CblasRowMajor, CblasLeft, CblasUpper, CblasTrans, CblasNonUnit,
                N, N, 1, A, N, A_tranposed_X_B, N);

	cblas_dcopy(N * N, B, 1, B_X_A, 1);
	cblas_dtrmm(CblasRowMajor, CblasRight, CblasUpper, CblasNoTrans, CblasNonUnit,
                N, N, 1, A, N, B_X_A, N);

	cblas_dcopy(N * N, B_X_A, 1, paranthesis_result, 1);
	cblas_daxpy(N * N, 1, A_tranposed_X_B, 1, paranthesis_result, 1);

    cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasTrans, N, N, N,
                1, paranthesis_result, N, B, N, 1, final_result, N);

    free(A_tranposed_X_B);
	free(B_X_A);
	free(paranthesis_result);

	return final_result;
}
