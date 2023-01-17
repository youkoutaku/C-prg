/*------------------------------------------------------------------*/
/*      		 			�@�@<ex5-5.c>	�@�@					*/
/*�@�@�@�@�@�\���̂̔z���n���֐��̃v���O������i�|�C���^�\���j�@�@*/
/*          �t�@�C�����瓾�_�f�[�^��ǂݍ��݁A���ѕ]���Ƌ���        */
/*          ��ʂɏo�͂���i���т̍~���ɕ��ёւ�:�|�C���^�z��)      */
/* �i���Ӂj�G�f�B�^�̃^�u�̕��������u�S�v�ɐݒ肷��Ƃ���܂���     */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h>
#define SNUM 5

//Prog2�^�̐錾�i�֐��̃v���g�^�C�v�錾�̑O�ɍs���j
typedef struct{
	int 	ID;			//�w���ԍ�
	char    name[20];	//���O
	int		final;		//�����������_
	double	mini;		//���e�X�g���_
	double	rpt;		//���|�[�g���_
	double	score;		//�������_
	char	grade[3];	//���ѕ]��
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
	while(fscanf(fp,"%d%s%lf%lf%d", &(obj+i)->ID, (obj+i)->name,
		&(obj+i)->mini, &(obj+i)->rpt, &(obj+i)->final)!=EOF){ i++; }

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
		(obj+i)->score=(obj+i)->mini+(obj+i)->rpt+(obj+i)->final;	//�������_

		//���є���iA+�`D)
		if((obj+i)->score>=90)	strcpy((obj+i)->grade, "A+");
		else if((obj+i)->score>=80) strcpy((obj+i)->grade, "A");
		else if((obj+i)->score>=70) strcpy((obj+i)->grade, "B");
		else if((obj+i)->score>=60) strcpy((obj+i)->grade, "C");
		else	strcpy((obj+i)->grade, "D");	
	}
}
/*----------------------------------------------------------------------*/
/*      �֐����Fsort_data                                               */
/*		��  ���FPrgog2�^�ւ̃|�C���^obj�@�@�@ �@�@�@�@�@�@�@�@�@�@�@�@�@*/
/*		�߂�l: �Ȃ�             �@�@�@�@�@�@�@�@�@�@�@�@�@ �@�@�@�@�@�@*/
/*      �@�\�F�������_�̍~���Ƀf�[�^�̕��ёւ��v�Z�i�|�C���^�z�񗘗p�j�A*/
/*            ���ʂ̕\��        �@                                      */
/*----------------------------------------------------------------------*/
void sort_data(Prog2 *obj)
{
	int		i,j;				//�J�E���^
	Prog2	*wkp,				//�ꎞ�ۑ��p�|�C���^
			*p[SNUM]={NULL};	//�\�[�g�����i�[����|�C���^�z��

	//i�Ԗڂ̔z��v�f�̐擪�̃A�h���X��p[i]�Ɋi�[����
	for(i=0;i<SNUM;i++)	p[i]=obj+i;

	//���т̍~���ɕ��ёւ�
	for(i=0;i<SNUM-1;i++){		/* i=0(�ŏ��̃f�[�^)����i=SNUM-2�܂ŌJ��Ԃ� */
		for(j=i+1;j<SNUM;j++){/* j=i+1����j=SNUM-1(�Ō�̃f�[�^)�܂ŌJ��Ԃ� */
			if(p[i]->score<p[j]->score){	//����p[i]->score<p[j]->score�Ȃ�
				//�|�C���^�z��v�fp[i]��p[j]�̌���
				wkp=p[i];
				p[i]=p[j];
				p[j]=wkp;
			}
		}
	}

	//�w���ԍ��A���ڕʓ��_�A�������_�A�]���̕\��
	printf("%-10s%-19s%10s%10s%10s%10s%10s\n","ID", "Name",
           "Mini", "Report", "Final", "Total", "Grade");

	for(i=0;i<SNUM;i++){
		//���ѕ]���o��
		printf("%-10d%-19s%10.1f%10.1f%10d%10.1f%10s\n", p[i]->ID,
        	p[i]->name, p[i]->mini, p[i]->rpt, p[i]->final,
			p[i]->score, p[i]->grade);
	}
}

