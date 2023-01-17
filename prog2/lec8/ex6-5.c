/*------------------------------------------------------------------*/
/*      		 			�@�@<ex6-5.c>	�@�@					*/
/*�@�@����q�̍\���̂̔z���n���֐��̃v���O������i�z��\�L�j�@�@�@*/
/*          �t�@�C�����瓾�_�f�[�^��ǂݍ��݁A���ѕ]���Ƌ���        */
/*          ��ʂɏo�͂���i���т̍~���ɕ��ёւ��j                  */
/* �i���Ӂj�G�f�B�^�̃^�u�̕��������u�S�v�ɐݒ肷��Ƃ���܂���     */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h>
#define SNUM 5

//Seiseki�^�̐錾
typedef struct{
	int		final;		//�����������_
	double	mini;		//���e�X�g���_
	double	rpt;		//���|�[�g���_
	double	score;		//�������_
	char	grade[3];	//���ѕ]��
} Seiseki;

//Prog2�^�̐錾�i�֐��̃v���g�^�C�v�錾�̑O�ɍs���j
typedef struct{
	int 	ID;			//�w���ԍ�
	char    name[20];	//���O
	Seiseki	sc;			//���уf�[�^
} Prog2;

//�֐��̃v���g�^�C�v�錾
void load_data(char *fname, Prog2 *obj);
void grade_eval(Prog2 *obj);
void sort_data(Prog2 *obj);

int main(void)
{
	char	fname[]="record_25.txt";//���̓t�@�C����
	Prog2 Mech[SNUM]={0};			//�w���f�[�^�p�z��
	
	load_data(fname, Mech);	//���уf�[�^�̓ǂݍ���

	grade_eval(Mech);	//���ѕ]��

	sort_data(Mech);	//���т̍~���ɕ��ёւ��ĕ\��
	
	return 0;
}
/*----------------------------------------------------------------------*/
/*      �֐����Fload_data                                               */
/*		�������Fchar�^�ւ̃|�C���^fname, Prog2�^�ւ̃|�C���^obj�@�@   �@*/
/*		�߂�l:�Ȃ��@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@�@ �@�@�@�@�@�@*/
/*      �@�@�\�Ffname�Ŏw�肳�ꂽ�t�@�C������f�[�^��ǂݍ��ݔz�� Mech  */
/*            �@�̊e�����o�Ɋi�[����                                    */
/*----------------------------------------------------------------------*/
void load_data(char *fname, Prog2 *obj)
{
	FILE	*fp;		//�t�@�C���|�C���^
	int		i=0;		//�J�E���^
	char	temp[256];	//�C���f�b�N�X�s�ǂݍ��݃o�b�t�@�p�z��

	//���̓t�@�C���̃I�[�v���i�ǂݍ��݃��[�h�j
	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("Can't open %s!\n",fname);
		exit(1);	//�����I��
	}
	
	fgets(temp,256,fp);//�C���f�b�N�X����s��z��temp�ɓf���o��
	
	//���̓t�@�C������f�[�^�̓ǂݍ���
	while(fscanf(fp,"%d%s%lf%lf%d", &obj[i].ID, obj[i].name,
	  &obj[i].sc.mini, &obj[i].sc.rpt, &obj[i].sc.final)!=EOF){ i++; }

	fclose(fp);	//���̓t�@�C���̃N���[�Y
}
/*----------------------------------------------------------------------*/
/*      �֐����Fgrade_eval                                              */
/*		��  ���FPrgog2�^�ւ̃|�C���^obj�@�@�@ �@�@�@�@�@�@�@�@�@�@�@�@�@*/
/*		�߂�l: �Ȃ�             �@�@�@�@�@�@�@�@�@�@�@�@�@ �@�@�@�@�@�@*/
/*      �@�\�F�e�w���̑������_�̌v�Z�A���ѕ]��                        �@*/
/*----------------------------------------------------------------------*/
void grade_eval(Prog2 *obj)
{
	int		i;			//�J�E���^

	for(i=0;i<SNUM;i++){
		obj[i].sc.score=obj[i].sc.mini+obj[i].sc.rpt+obj[i].sc.final;//�������_

		//���є���iA+�`D)
		if(obj[i].sc.score>=90)	strcpy(obj[i].sc.grade, "A+");
		else if(obj[i].sc.score>=80) strcpy(obj[i].sc.grade, "A");
		else if(obj[i].sc.score>=70) strcpy(obj[i].sc.grade, "B");
		else if(obj[i].sc.score>=60) strcpy(obj[i].sc.grade, "C");
		else	strcpy(obj[i].sc.grade, "D");	
	}
}
/*----------------------------------------------------------------------*/
/*      �֐����Fsort_data                                               */
/*		��  ���FPrgog2�^�ւ̃|�C���^obj�@�@�@ �@�@�@�@�@�@�@�@�@�@�@�@�@*/
/*		�߂�l: �Ȃ�             �@�@�@�@�@�@�@�@�@�@�@�@�@ �@�@�@�@�@�@*/
/*      �@�\�F�������_�̍~���Ƀf�[�^�̕��ёւ��v�Z�A���ʂ̕\��        �@*/
/*----------------------------------------------------------------------*/
void sort_data(Prog2 *obj)
{
	int		i,j;	//�J�E���^
	Prog2	wk;		//�ꎞ�ۑ��p

	//���т̍~���ɕ��ёւ�
	for(i=0;i<SNUM-1;i++){		/* i=0(�ŏ��̃f�[�^)����i=SNUM-2�܂ŌJ��Ԃ� */
		for(j=i+1;j<SNUM;j++){/* j=i+1����j=SNUM-1(�Ō�̃f�[�^)�܂ŌJ��Ԃ� */
			if(obj[i].sc.score<obj[j].sc.score){
				//obj[i]��obj[j]�̌���
				wk=obj[i];
				obj[i]=obj[j];
				obj[j]=wk;
			}
		}
	}

	//�w���ԍ��A���ڕʓ��_�A�������_�A�]���̕\��
	printf("%-10s%-19s%10s%10s%10s%10s%10s\n","ID", "Name",
           "Mini", "Report", "Final", "Total", "Grade");

	for(i=0;i<SNUM;i++){
		//���ѕ]���o��
		printf("%-10d%-19s%10.1f%10.1f%10d%10.1f%10s\n",obj[i].ID,
        	obj[i].name, obj[i].sc.mini, obj[i].sc.rpt, obj[i].sc.final,
			obj[i].sc.score, obj[i].sc.grade);
	}
}
