//�ۑ�15 �񎟌��z��̓��I�������m�ۂɂ��s��v�Z
//20t1126n YANG GUANGZE

#include <stdio.h>
#include <stdlib.h>

#define N 3

int main (){
    int i, j, k,
        m, l;
    double (*A)[N], (*B)[N];

    printf("������(m) :");
    scanf("%d",&m);
    printf("������(l) :");
    scanf("%d",&l);

    A=(double (*)[N])calloc(m*N, sizeof(double));	
	if(A==NULL){								//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

    B=(double (*)[N])calloc(l*N, sizeof(double));	
	if(B==NULL){								//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

    double (*C)[l]=(double (*)[l])calloc(m*l, sizeof(double));	
	if(C==NULL){								//�G���[����
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

    printf("----------�f�[�^�̓���----------\n");

    for(i=0; i<m; i++){
        for(j=0; j<N; j++){
            printf("A[%d][%d]=", i, j);
            scanf("%lf",&A[i][j]);
        }
    }

    for(i=0; i<N; i++){
        for(j=0; j<l; j++){
            printf("B'[%d][%d]=", j, i);
            scanf("%lf",&B[j][i]);
        }
    }

    printf("----------A x B �̌���----------\n");

    printf("C=\n");   

    for(i=0; i<m; i++){
        for(j=0; j<l; j++){
            for (k=0; k<N; k++){
                C[i][j] += A[i][k] * B[j][k];
            }
            printf("\t%.1lf",C[i][j]);    
        }
        printf("\n");
    }

    free(A);
    free(B);
    free(C);

    return 0;
}