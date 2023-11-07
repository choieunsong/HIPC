#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <immintrin.h>

struct timeval t;

double get_time(){
    gettimeofday(&t, NULL);
    return t.tv_sec + (1e-6 * t.tv_usec);
}

int main(int argc, char *arvc[]){
    int N = 10000000;

    float *a = _mm_malloc(sizeof(float) * N, 64);
    float *b = _mm_malloc(sizeof(float) * N, 64);
    float *c = _mm_malloc(sizeof(float) * N, 64);

    int i;
    for (i = 0; i < N; i++){
        a[i] = (float)rand() / RAND_MAX;
        b[i] = (float)rand() / RAND_MAX;
    }

    double time = get_time();
    for (i = 0; i < N; i += 4){
        __m128 a_v = _mm_load_ps(a + i);
        __m128 b_v = _mm_load_ps(b + i);
        __m128 c_v = _mm_add_ps(a_v, b_v);
        _mm_store_ps(c + i, c_v);
    }
    // for (i = 0; i < N; i += 8){
    //     // c[i] = a[i] + b[i];
    //     __m256 a_v = _mm256_load_ps(a + i);
    //     __m256 b_v = _mm256_load_ps(b + i);
    //     __m256 c_v = _mm256_add_ps(a_v, b_v);
    //     _mm256_store_ps(c + i, c_v);
    // }
    time = get_time() - time;

    double sum = 0.0;
    for (i = 0; i < N; i++){
        sum += c[i];
    }

    printf("Checksum is: %1f and took: %1f secs\n", sum, time);

    // free(a);
    // free(b);
    // free(c);
    _mm_free(a);
    _mm_free(b);
    _mm_free(c);

    return 0;
}