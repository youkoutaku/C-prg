/* ���K1�F�����̃f�[�^�̍��v�A���ϒl�A�ő�l���v�Z����v���O���� */
#include <stdio.h>

int main( void ){

  int i, n;
  double height[5] = {172.9, 167.3, 184.5, 176.9, 170.1};  /* �v�f��5�̔z��̐錾�Ə����l��� */
  double sum, avr, max;

  n = 5; /* �f�[�^�̌����� */

  sum = 0.0;
  for (i=0; i<n; i++)  {
    printf("%f\n", height[i]); /* i�Ԗڂ̔z��v�f�̒��g���m�F�̂��ߏo�� */
    sum += height[i];          /* i�Ԗڂ̃f�[�^�����ɉ��Z���Ă��� */
  }
  avr = sum / (double) n;  /* ���ϒl�̌v�Z */
  printf("���a = %f ���ϒl = %f\n", sum, avr);

  max = height[0];       /* �ő�l�̌��max�ɍŏ��̔z��̃f�[�^�������Ă��� */
  for (i=1; i<n; i++)  { /* 2�Ԗڈȍ~�̃f�[�^���r���Ă��� */
    if(height[i] > max)  max = height[i];  /* ����i�Ԗڂ̃f�[�^��max�̒��g���傫����΁A���̒l��max�ɕۑ� */
  }
  printf("�ő�l = %f\n", max);

  return 0;
}

