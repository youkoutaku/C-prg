/*------------------------------------------------------------------*/
/*                      <ex12-2.c> ���C���֐�	�^�u4                 */
/*           ���w���ԍ��̏����Ƀ`�F�[�����q���ς���                 */
/*           ���t�@�C������f�[�^����`���X�g�ɓǂݍ���             */
/*           �������@�\�F�w���ԍ��A���O                             */
/*-----------------------------------------------------------------	*/
#include "myhead\ex12-2.h"

int main(void)
{
	Prog2 	dmy={NULL};		//NULL�ŏ��������ďI�[�}�[�N�ɂ���
	Prog2	*start=&dmy;	//�擪�Ǘ��p�̍\����
	int		choice;			//�I�����ڔԍ�

	load_data(start);
	
	do{
		choice=menu();
		switch(choice){
			case 1:
				ID_Search(start);
				break;
			case 2:
				name_Search(start);
				break;
		}
	}while(choice!=3); 	//choice��3�łȂ��Ԃ͎��s���J��Ԃ�

	return 0;
}