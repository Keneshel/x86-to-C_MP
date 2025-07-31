
void dot_product_c(int n, float* vec_a, float* vec_b, float* result) {
    float sum = 0.0f; // temporary variable to accumulate the sum.
    
    // loop through each element of the vectors.
    for (int i = 0; i < n; i++) {
        sum += vec_a[i] * vec_b[i]; // multiply corresponding elements and add to sum.
    }
    
    // store the final sum in the memory location pointed to by 'result'.
    *result = sum;
    
}