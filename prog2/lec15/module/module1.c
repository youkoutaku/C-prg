/*------------------------------------------------------------------*/
/*                              <module1.c>                         */
/*                        ���ȏ��VP74(�}�U�|�Q�j                    */
/*                  extern�L���N���X�w��q�i�O����`�j              */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
void func(void);
int glb=1234;

int main(void)
{
	printf("main:glb=%d\n",glb);
	func();
	return 0;
}
