/*------------------------------------------------------------------*/
/*      		 			�@�@<ex5-3.c>	�@�@					*/
/*�@    �\���̕ϐ��������ɂƂ�֐��̗�i�|�C���^�n���A�߂�l�Ȃ��j  */
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//Prog2�^�̐錾
typedef struct {
	int		ID;
	char	name[20];
	int		final;
	double	mini;
	double	rpt;
} Prog2;

//�֐��̃v���g�^�C�v�錾
void TotalScore2(Prog2 *obj);

int main(void)
{
	//Prog2�^�̃I�u�W�F�N�g�̐錾�Ə�����
	Prog2 stdt1={251001,"sasaki", 40,30,30};
	
	TotalScore2(&stdt1);	//�������_�̌v�Z�ƕ\��
		
	return 0;
}

void TotalScore2(Prog2 *obj)
{
	double score;

	score=obj->final+obj->mini+obj->rpt;

	printf("%d %s %.1f\n",obj->ID, obj->name, score);
}