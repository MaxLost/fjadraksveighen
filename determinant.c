#include <stdio.h>
#include <stdlib.h>

int next_permutation(int *permutation, int *sign, int n){
    for (int i = n - 2; i >= 0; i--){
        if (permutation[i] < permutation[i + 1]){
            int min = i + 1;
            for (int j = i + 2; j < n; j++){
                if (permutation[j] > permutation[i] && permutation[j] < permutation[min])
                    min = j;
            }
            int t = permutation[i];
            permutation[i] = permutation[min];
            permutation[min] = t;
            for (int j = i + 1; j < n - 1; j++){
                for (int k = j + 1; k < n; k++){
                    if (permutation[k] < permutation[j]){
                        int t = permutation[j];
                        permutation[j] = permutation[k];
                        permutation[k] = t;
                    }
                }
            }
            int q = 0;
            for (int j = 0; j < n - 1; j++){
                for (int k = j + 1; k < n; k++){
                    if (permutation[j] > permutation[k])
                        q++;
                }
            }
            if (q & 1)
                *sign = -1;
            else
                *sign = 1;
            return 1;
        }
    }
    return 0;
}

int determinant(int **matrix, int N){
    int d = 0;
    int *permutation = (int*) malloc(N*sizeof(int));
    for (int i = 0; i < N; i++)
        permutation[i] = i;
    int sign = 1;
    int flag = 1;
    while (flag){
        int temp = 1;
        temp *= sign;
        for (int i = 0; i < N; i++){
            temp *= matrix[i][permutation[i]];
        }
        d += temp;
        flag = next_permutation(permutation, &sign, N);
    }
    return d;
}

int main(){
    int N;
    printf("Enter N - number of matrix rows and columns: ");
    scanf("%d", &N);
    int **matrix = (int**) malloc(N*sizeof(int*));
    for (int i = 0; i < N; i++){
        *(matrix + i) = (int*) malloc(N*sizeof(int));
    }
    printf("Enter matrix: \n");
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int t = 0;
            scanf("%d", &t);
            matrix[i][j] = t;
        }
    }

    printf("\n%d", determinant(matrix, N));

    return 0;
}
