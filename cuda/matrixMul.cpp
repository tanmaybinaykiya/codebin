#include <stdio.h>
// Kernel definition
__global__ void MatAdd(float A[N][N], float B[N][N], float C[N][N])
{
    int i = threadIdx.x;
    int j = threadIdx.y;
    C[i][j] = A[i][j] + B[i][j];
}

int main()
{
    // ...
    // Kernel invocation with one block of N * N * 1 threads
    int N=3;
    int A[3][3]={{0,0,1},{0,1,0},{0,0,1}};
    int B[3][3]={{0,0,1},{0,1,0},{0,0,1}};
    int C[3][3]={{0,0,1},{0,1,0},{0,0,1}};
    int numBlocks = 1;
    int dim3;
    dim3 threadsPerBlock(N, N);
    MatAdd<<<numBlocks, threadsPerBlock>>>(A, B, C);
    return 1;
    // ...
}