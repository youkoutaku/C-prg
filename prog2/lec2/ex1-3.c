#include <stdio.h>

int main( void )
{
  int a;

  for (a=1; a<=5; a++)  {
    printf("------- %d\n", a);
    switch (a)  {
      case 1:   /* a==1 �̂Ƃ� */
        printf("a=1����\n");
        break;
      case 3:   /* a==3 �̂Ƃ� */
        printf("a=3����\n");
        break;
      case 5:   /* a==5 �̂Ƃ� */
        printf("a=5����\n");
        break;
      default:   /* ����ȊO */
        printf("���̑�\n");
    }
  }

  return 0;
}

