
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// --- Function Declarations ---

// C kernel function 
void dot_product_c(int n, float* vec_a, float* vec_b, float* result);

// ASM kernel function 
extern float dot_product_asm(float* vec_a, float* vec_b, int n);

int main() {
    int vector_sizes[] = {1 << 20, 1 << 24, 1 << 26}; 
    int num_sizes = sizeof(vector_sizes) / sizeof(vector_sizes[0]);
    int num_runs = 20;

    srand(time(NULL));

    for (int i = 0; i < num_sizes; i++) {
        int n = vector_sizes[i];
        printf("------------------------------------------\n");
        printf("Testing with vector size n = %d\n", n);
        printf("------------------------------------------\n");

        float* vec_a = (float*)malloc(n * sizeof(float));
        float* vec_b = (float*)malloc(n * sizeof(float));
        if (vec_a == NULL || vec_b == NULL) {
            fprintf(stderr, "Failed to allocate memory for vectors.\n");
            return 1;
        }

        for (int j = 0; j < n; j++) {
            vec_a[j] = (float)rand() / (float)RAND_MAX;
            vec_b[j] = (float)rand() / (float)RAND_MAX;
        }

        float c_result = 0.0f;
        float asm_result = 0.0f; 
        
        struct timespec start, end;
        double c_total_time = 0.0;
        double asm_total_time = 0.0;

        // --- Time the C Kernel ---
        for (int run = 0; run < num_runs; run++) {
            clock_gettime(CLOCK_MONOTONIC, &start);
            dot_product_c(n, vec_a, vec_b, &c_result);
            clock_gettime(CLOCK_MONOTONIC, &end);
            c_total_time += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        }

        // --- Time the ASM Kernel ---
        for (int run = 0; run < num_runs; run++) {
            clock_gettime(CLOCK_MONOTONIC, &start);
            asm_result = dot_product_asm(vec_a, vec_b, n);
            clock_gettime(CLOCK_MONOTONIC, &end);
            asm_total_time += (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1e9;
        }

        printf("C Kernel Result:       %f\n", c_result);
        printf("ASM Kernel Result:     %f\n", asm_result);
        
        printf("\nAverage Execution Times (%d runs):\n", num_runs);
        printf("C Kernel:        %f seconds\n", c_total_time / num_runs);
        printf("x86-64 Kernel:   %f seconds\n\n", asm_total_time / num_runs);
        
        // --- Cleanup ---
        free(vec_a);
        free(vec_b);
    }

    return 0;
}