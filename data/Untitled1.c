#include <stdio.h>

int main(){
    int i,j,**pont,nl,nc;

    pont = (int**) malloc (nl*(sizeof(int*)));
    for (i=0; i<nl;i++){
            pont [i][j] = (int *) malloc (nc*(sizeof(int)));
    }
    for (j=0;j<1;j++){
        pont[0][j] = 2;
    }

    printf ("%d", pont[0][0]);
    return 0;
}
