#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <immintrin.h>

#define MAX_RAND 10000

#ifndef M_PI
#    define M_PI 3.14159265358979323846
#endif

typedef struct sphere_t{
    double *x;
    double *y;
    double *z;
    double *r;
} spheres;

double random_number(){
    return fmod(rand() * ((double) rand() / RAND_MAX), MAX_RAND);
}

int main(int argc, char *argv[]) {
	// read N from the first command line argument
	int N = atoi(argv[1]);

	clock_t start_t, end_t;
	start_t = clock();

	fprintf(stderr, "start time: %ld\n", start_t);

	spheres sphere;
	sphere.x = _mm_malloc(sizeof(spheres) * N, 64);
	sphere.y = _mm_malloc(sizeof(spheres) * N, 64);
	sphere.z = _mm_malloc(sizeof(spheres) * N, 64);
	sphere.r = _mm_malloc(sizeof(spheres) * N, 64);

	// fill with random numbers
	for (int i = 0; i < N; i++) {
		sphere.x[i] = random_number();
		sphere.y[i] = random_number();
		sphere.z[i] = random_number();
		sphere.r[i] = random_number() / 4.0;
	}

	// calculate areas
	double * area = _mm_malloc(sizeof(double), 64);
	double tmp = 4.0 * M_PI; 
	for (int i = 0; i < N; i+=8){
		__m256d r_v = _mm256_load_pd(sphere.r + i);
		__m256d area_v = _mm256_mul_pd(tmp, r_v);
		//area[i] = tmp * sphere.r[i] * sphere.r[i];
	}

	// calculate volume
	double * volume = calloc(N, sizeof(double));
	tmp = tmp / 3.0;
	for (int i = 0; i < N; i++){
		volume[i] = tmp * sphere.r[i] * sphere.r[i] * sphere.r[i];
	}

	// calculate the number of spheres each sphere intersects
	int * intersects = calloc(N, sizeof(int));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue; // same circle

			// calculate distance between two spheres
			double d = sqrt((sphere.x[i] - sphere.x[i]) * (sphere.x[i] - sphere.x[i]) +(sphere.y[j] - sphere.y[j]) * (sphere.y[j] - sphere.y[j]) + (sphere.z[j] - sphere.z[j]) * (sphere.z[j] - sphere.z[j]));
			// if the distance is less than the sum of the radii, they intersect
			if (d < (sphere.r[i] + sphere.r[i])) intersects[i]++;
		}
		fprintf(stderr, "%lf, %lf, %lf, %lf, %lf, %lf, %d\n", sphere.x[i], sphere.y[i], sphere.z[i], sphere.r[i], area[i], volume[i], intersects[i]);
		
	}

	end_t = clock();
	double total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	fprintf(stderr, "end time: %ld\n", end_t);
	fprintf(stderr, "Total time taken by CPU: %lf\n", total_t); 
	
	free(sphere.x);
	free(sphere.y);
	free(sphere.z);
	free(sphere.r);
}