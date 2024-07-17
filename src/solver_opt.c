/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"

/*
 * Program below computes the following formula:
 * C = (A_transposed × B + B × A) × B_transposed.
 * Where A is an upper triangular matrix.
 * This time with an emphasis on speed.
 */
double* my_solver(int N, double *A, double* B) {
	double *A_transposed = calloc(N * N, sizeof(double));
	double *B_transposed = calloc(N * N, sizeof(double));
	double *A_transposed_X_B = calloc(N * N, sizeof(double));
	double *B_X_A = calloc(N * N, sizeof(double));
	double *paranthesis_result = calloc(N * N, sizeof(double));
	double *final_result = calloc(N * N, sizeof(double));

	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			if (j <= i) {
				A_transposed[i * N + j] = A[j * N + i];
			}

			B_transposed[i * N + j] = B[j * N + i];
		}
	}

	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			register double *pa = &A_transposed[i * N];
    		register double *pb = &B[j];

    		register double sum = 0.0;
			for (register int k = 0; k <= i; k++) {
				sum += *pa * *pb;
				pa++;
				pb += N;
			}

			A_transposed_X_B[i * N + j] = sum;
		}
	}

	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			register double *pa = &B[i * N];
    		register double *pb = &A[j];

    		register double sum = 0.0;
			for (register int k = 0; k <= j; k++) {
				sum += *pa * *pb;
				pa++;
				pb += N;
			}

			B_X_A[i * N + j] = sum;
		}
	}

	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			paranthesis_result[i * N + j] = A_transposed_X_B[i * N + j] + B_X_A[i * N + j];
		}
	}

	for (register int i = 0; i < N; i++) {
		for (register int j = 0; j < N; j++) {
			register double *pa = &paranthesis_result[i * N];
    		register double *pb = &B_transposed[j];

    		register double sum = 0.0;
			for (register int k = 0; k < N; k++) {
				sum += *pa * *pb;
				pa++;
				pb += N;
			}

			final_result[i * N + j] = sum;
		}
	}

	free(A_transposed);
	free(B_transposed);
	free(A_transposed_X_B);
	free(B_X_A);
	free(paranthesis_result);
	return final_result;	
}
