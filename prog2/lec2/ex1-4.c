/*------------------------------------------------------------------*/
/*      		 			�@<ex1-4.c>	(�^�u4�j				    */
/*�@�@�@�@�@�@�v���O���~���O���K�U�̐��т̌v�Z���\��     �@�@�@�@�@	*/
/*-----------------------------------------------------------------	*/
#include <stdio.h>

int main(void)
{
	int		ID,		//�w���ԍ�
			final,	//��������
			retry;	//�J��Ԃ�����(0:���s���Ȃ� 1:���s)
	double	mini,	//���e�X�g
			rpt,	//���|�[�g
			score;  //�������_

	do{
		//�w���ԍ��ƍ��ڕʓ��_�̓���
		printf("ID Number :");	scanf("%d",&ID);
		printf("Mini Test :");	scanf("%lf",&mini);
		printf("Report    :");	scanf("%lf",&rpt);
		printf("Final Exam:");	scanf("%d",&final);
	
		score=mini+rpt+final;	//�������_�̌v�Z

		//�f�[�^���x���̕\��
    	printf("%-8s%10s%10s\n", "ID NUMBER","SCORE","GRADE");
	
		//�w���ԍ��A�������_�̕\��
		printf("%-8d%10.1f",ID,score);

		//���є���iA+�`D)�ƕ\��
		if(score>=90)	printf("%10s\n","A+");
		else if(score>=80) printf("%10s\n","A");
		else if(score>=70) printf("%10s\n","B");
		else if(score>=60) printf("%10s\n","C");
		else	printf("%10s\n","D");
		printf("�J��Ԃ��܂����H0-������/1-�͂�:");
		scanf("%d", &retry);

	}while(retry==1);	//retry���P�̊Ԃ͎��s���J��Ԃ�
	
	return 0;
}
