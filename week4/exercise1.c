#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 1000

int main(int argc, char *argv[]){
    double mat[N][N];
    double s[N][N];
    int v[N];

    double start, end;
    double vtab[N];

    for(int i=0; i<N; i++){
        double val = fmod(v[i], 256);
        vtab[i] = -cos(2*val);
    }

    start = (double)(clock() / CLOCKS_PER_SEC);

    for(int j = 0; j < N; j++){
        for(int i = 0; i < N; i++){
            mat[i][j] = s[i][j] * vtab[i];
        }
    }

    end = (double)(clock() / CLOCKS_PER_SEC);
    printf("time: %f\n", end - start);

    return 0;
}