/* ���K2�F�f�[�^�����������ɕ��ъ�����v���O�����@[�z��̉��p] */
#include <stdio.h>

int main( void ){

  int data[8] = {32, 55, 16, 84, 7, 22, 49, 11}; /* �f�[�^��z��Ɋi�[���� */ 
  int a, i, j, n = 8;  /* n�̓f�[�^�� */

  for (i=0; i<n; i++)  {
    printf("%d ", data[i]);  /* �z��̊e�v�f����ʂɏo�� */
  }
  printf("\n");

  for (i=0; i<n-1; i++)  {   /* i=0(�ŏ��̃f�[�^)����i=n-2�܂ŌJ��Ԃ� */
    for (j=i+1; j<n; j++)  { /* j=i+1����j=n-1(�Ō�̃f�[�^)�܂ŌJ��Ԃ� */
      if(data[i] > data[j])  {  /* ����data[i]>data[j]�Ȃ璆�g���������Adata[i]����������Ԃɂ��� */
        a = data[i];         /* data[i]�̒��g���ꎞ�Aa�ɕۑ����� */
        data[i] = data[j];   /* data[j]�̒��g��data[i]�Ɉڂ� */
        data[j] = a;         /* �ۑ����Ă���a�̒��g��data[j]�Ɉڂ� */
      }
    }
  }

  printf("���������ɕ��ъ�������̃f�[�^��\n");
  for (i=0; i<n; i++)  {
    printf("%d ", data[i]);  /* ���ʂ���ʂɏo�� */
  }
  printf("\n");

  return 0;
}

