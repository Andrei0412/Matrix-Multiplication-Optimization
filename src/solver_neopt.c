/*
 * Tema 2 ASC
 * 2024 Spring
 */
#include "utils.h"

/*
 * Program below computes the following formula:
 * C = (A_transposed × B + B × A) × B_transposed.
 * Where A is an upper triangular matrix.
 */
double* my_solver(int N, double *A, double* B) {
	double *A_transposed = calloc(N * N, sizeof(double));
	double *B_transposed = calloc(N * N, sizeof(double));
	double *A_transposed_X_B = calloc(N * N, sizeof(double));
	double *B_X_A = calloc(N * N, sizeof(double));
	double *paranthesis_result = calloc(N * N, sizeof(double));
	double *final_result = calloc(N * N, sizeof(double));


	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			A_transposed[i * N + j] = A[j * N + i];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B_transposed[i * N + j] = B[j * N + i];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= i; k++) {
				A_transposed_X_B[i * N + j] += A_transposed[i * N + k] * B[k * N + j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k <= j; k++) {
				B_X_A[i * N + j] += B[i * N + k] * A[k * N + j];
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			paranthesis_result[i * N + j] = A_transposed_X_B[i * N + j] + B_X_A[i * N + j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				final_result[i * N + j] += paranthesis_result[i * N + k] * B_transposed[k * N + j];
			}
		}
	}

	free(A_transposed);
	free(B_transposed);
	free(A_transposed_X_B);
	free(B_X_A);
	free(paranthesis_result);
	return final_result;
}
