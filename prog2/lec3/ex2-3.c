/* ���K3�F2�~2��1���ϊ����v�Z����v���O���� */
#include <stdio.h>
#define N 2 /* ��������2 */
int main( void ){

  int i, j;
  double a[2][2] = { {0.5, -0.866}, {0.866, 0.5} };   /* 2�~2�z��(�s��)A�̐錾�Ə����� */
  double x[2], y[2];  /* 2�����z��(�x�N�g��)x��y�̐錾 */

  x[0] = 3.3;  /* �z��x�̑�0�����̐ݒ� */
  x[1] = 5.8;  /* �z��x�̑�1�����̐ݒ� */

  for (i=0; i<N; i++)  {
    y[i] = 0.0;
    for (j=0; j<N; j++)  {
      y[i] += a[i][j] * x[j];  /* �z��y�̑�i�����̌v�Z(�v�����g�̎�(4)�Q��) */
    }
    printf("y[%d] = %f\n", i, y[i]);
  }

  /*
  double A[2][3]={};
  double B[3][2]={};
  double C[2][2];
  
  for(i=0; i<2; i++){
    for(j=0; j<2;j++){
      for(int k=0;k<3;k++){
        c[i][j]+=a[i][k]*b[k][j];
      }
    }
  }


  */
  return 0;
}

