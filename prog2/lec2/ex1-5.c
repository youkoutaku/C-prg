#include <stdio.h>

int main( void )
{
  int i, j;
  
  for( i=-20; i<=20; i=i+2 )  { /* i��-20�`20�܂�2�����₷ */
    printf("%d ", i);
  }
  printf("\n------\n");

  for( i=1; i<10; i++ )  {   /* i=1�`9�܂Ń��[�v������ */
    for( j=1; j<10; j++ )  { /* j=1�`9�܂Ń��[�v������ */
      printf("%d ", i*j);    /* i*j���v�Z���A���̒l���o�� */
    } 
    printf("\n");  /* j�̃��[�v���I���x�ɉ��s(\n)���� */
  }

  return 0;
}

