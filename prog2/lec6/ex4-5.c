/*------------------------------------------------------------------*/
/*      		 			�@�@<ex4-5.c>	�@�@					*/
/*�@�@�@�@�@�\���̂̔z��̃����o�̃A�h���X�Q�Ƃ̃v���O������@�@�@�@*/
/*          �t�@�C�����瓾�_�f�[�^��ǂݍ��݁A���ѕ]���Ƌ���        */
/*          ��ʂɏo�͂���@�@�@�@�@�@                              */
/* �i���Ӂj�G�f�B�^�̃^�u�̕��������u�S�v�ɐݒ肷��Ƃ���܂���     */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h> //for exit()
#include <string.h>
#define SNUM 5

//struct prog2�^�̐錾
struct prog2{
	int 	ID;			//�w���ԍ�
	char    name[20];	//���O
	int		final;		//�����������_
	double	mini;		//���e�X�g���_
	double	rpt;		//���|�[�g���_
	char	grade[3];	//���ѕ]��
};

int main(void)
{
	int		i=0;					//�J�E���^
	FILE	*fp;					//�t�@�C���|�C���^
	double	score;					//�������_
	char	fname[]="record_25.txt",//���̓t�@�C����
			temp[256];				//�C���f�b�N�X�s�ǂݍ��݃o�b�t�@�p�z��
	struct prog2 Mech[SNUM]={0};

	//���̓t�@�C���̃I�[�v���i�ǂݍ��݃��[�h�j
	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("Can't open %s!\n",fname);
		exit(1);	//�����I��
	}
	
	fgets(temp,256,fp);//�C���f�b�N�X����s��z��temp�ɓf���o��
	
	//���̓t�@�C������f�[�^�̓ǂݍ���
	while(fscanf(fp,"%d%s%lf%lf%d",&Mech[i].ID,Mech[i].name,
		&Mech[i].mini,&Mech[i].rpt,&Mech[i].final)!=EOF){ i++; }

	fclose(fp);	//���̓t�@�C���̃N���[�Y

	//�w���ԍ��A���ڕʓ��_�A�������_�A�]���̕\��
	printf("%-10s%-19s%10s%10s%10s%10s%10s\n","ID", "Name",
           "Mini", "Report", "Final", "Total", "Grade");

	for(i=0;i<SNUM;i++){
		score=Mech[i].mini+Mech[i].rpt+Mech[i].final;	//�������_

		//���є���iA+�`D)
		if(score>=90)	strcpy(Mech[i].grade, "A+");
		else if(score>=80) strcpy(Mech[i].grade, "A");
		else if(score>=70) strcpy(Mech[i].grade, "B");
		else if(score>=60) strcpy(Mech[i].grade, "C");
		else	strcpy(Mech[i].grade, "D");

		//���ѕ]���o��
		printf("%-10d%-19s%10.1f%10.1f%10d%10.1f%10s\n",Mech[i].ID,
        	Mech[i].name, Mech[i].mini, Mech[i].rpt, Mech[i].final,
			score, Mech[i].grade);
	}

	return 0;
}
