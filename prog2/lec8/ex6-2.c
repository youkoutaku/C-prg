/*------------------------------------------------------------------*/
/*      		 			�@�@<ex6-2.c>	�@�@					*/
/*����q�̍\���̕ϐ��������ɂƂ�֐��̗�i�|�C���^�n���A�߂�l�Ȃ��j*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

//Seiseki�^�̐錾
typedef struct{
	int		final;
	double	mini;
	double	rpt;
} Seiseki;

//Prog2�^�̐錾
typedef struct {
	int		ID;
	char	name[20];
	Seiseki	sc;
} Prog2;

//�֐��̃v���g�^�C�v�錾
void TotalScore2(Prog2 *obj);

int main(void)
{
	//Prog2�^�̃I�u�W�F�N�g�̐錾�Ə�����
	Prog2 stdt1={251001,"sasaki", {40,30,30}};
	
	TotalScore2(&stdt1);	//�������_�̌v�Z�ƕ\��
		
	return 0;
}

void TotalScore2(Prog2 *obj)
{
	double score;

	score=obj->sc.final+obj->sc.mini+obj->sc.rpt;

	printf("%d %s %.1f\n",obj->ID, obj->name, score);
}