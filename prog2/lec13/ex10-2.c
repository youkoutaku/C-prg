/*------------------------------------------------------------------*/
/*      		 	<ex10-2.c> ���`���X�g�A	�^�u4			�@�@    */
/*           ���w���ԍ��̏����Ƀ`�F�[�����q���ς���@�@			�@�@*/
/*           ���t�@�C������f�[�^����`���X�g�ɓǂݍ���             */
/*�@�@�@�@�@ �������@�\�F�w���ԍ��A���O �@�@�@�@�@�@�@�@�@�@�@ �@�@ */
/*-----------------------------------------------------------------	*/
#include <stdio.h>
#include <stdlib.h>	
#include <string.h>

//Seiseki�^�̐錾
typedef struct{
	int		final;
	double	mini;
	double	rpt;
} Seiseki;

//Prog2�^�̐錾
typedef struct prog2{
	struct prog2	*next;		//���̃m�[�h�ւ̃|�C���^
	int				ID; 		//�w���ԍ�
	char			name[20];	//���O
	Seiseki			sc;			//���уf�[�^
} Prog2;

//�֐��̃v���g�^�C�v�錾
Prog2 *Alloc_Node(void);
void print_list(Prog2 *start);
void print_node(Prog2 *node);
void load_data(Prog2 *start);
void name_Search(Prog2 *start);
void ID_Search(Prog2 *start);
int menu(void);

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
//------------------------------------------------------------------------------
//							  menu�֐�									�@  	
//																			�@  
//	��  ���Fvoid                                                 �@�@�@ 		
//�@�߂�l�Fint														        	
//	�@  �\�F�I����ʂ�\�����āA���͂��ꂽ�I�����ڂ̔ԍ���Ԃ��@�@ 				
//------------------------------------------------------------------------------
int menu(void)
{
	int ch;

	printf("/--------------------------/\n");
	printf("/ 1.Search by ID Number    /\n");
	printf("/ 2.Search by Name         /\n");
	printf("/ 3.End                    /\n");
	printf("/--------------------------/\n");

	do{
		printf("Please enter your choice�F"); scanf("%d", &ch);
	}while( ch<1 || ch >3);

	return ch;
}
//------------------------------------------------------------------------------
//							  ID_Search�֐�									�@  
//																			�@  
//	��  ���FProg2 *start                                                 �@�@�@ 
//�@�߂�l�Fvoid														        
//	�@  �\�F���X�g����ID�������L�[key�Ɉ�v����m�[�h���������A�@�@�@�@ 		
//�@�@�@�@�@�m�[�h�̃f�[�^���o�͂���				                            
//------------------------------------------------------------------------------
void ID_Search(Prog2 *start)
{
	Prog2 	*ip;
	int		key;

	printf("ID Number:");	scanf("%d", &key);

	//�`�F�[�������ǂ��ăm�[�h����������
	for(ip=start->next; ip!=NULL; ip=ip->next){
		if(ip->ID==key){
			print_node(ip);	
			break;
		}
	}
	if(ip==NULL) printf("Not found!\n");
}
//------------------------------------------------------------------------------
//							  name_Search�֐�									
//																			�@  
//	��  ���FProg2 *start                                                 �@�@�@ 
//�@�߂�l�Fvoid														        
//	�@  �\�F���X�g����name�������L�[key�Ɉ�v����m�[�h���������A�@�@�@�@ 		
//�@�@�@�@�@�m�[�h�̃f�[�^���o�͂���				                            
//------------------------------------------------------------------------------
void name_Search(Prog2 *start)
{
	Prog2 	*ip;
	char 	key[20];
	int		found=0;

	printf("Name:");	scanf("%s", key);

	//�`�F�[�������ǂ��ăm�[�h����������
	for(ip=start->next; ip!=NULL; ip=ip->next){
		if(strcmp(ip->name,key)==0){
			print_node(ip);
			found++;
		}
	}
	if(found==0) printf("Not found!");
}
//------------------------------------------------------------------------------
//							load_data�֐�									�@  
//																			�@  
//	��  ���FProg2 *start                                                        
//�@�߂�l�Fvoid															    
//	�@�\�F�t�@�C������f�[�^��ǂݍ��݁A���`���X�g�𐶐�����			        
//------------------------------------------------------------------------------
void load_data(Prog2 *start)
{
	FILE	*fp;		//�t�@�C���|�C���^
	char	fname[20],	//���̓t�@�C����
			temp[256];	//�C���f�b�N�X���p
	Prog2	*node, *ip, wk;

	//���̓t�@�C�����̓���
	printf("Input file name:");	scanf("%s",fname);

	//���̓t�@�C���̃I�[�v���i�ǂݍ��݃��[�h�j
	fp=fopen(fname,"r");
	if(fp==NULL){
		printf("Can't open %s!\n",fname);
		exit(1);
	}

	//���̓t�@�C������f�[�^�̓ǂݍ���
	fgets(temp,256,fp);		//�C���f�b�N�X����s��z��temp�ɓf���o��

	while(fscanf(fp,"%d%s%lf%lf%d", &wk.ID, wk.name, &wk.sc.mini, &wk.sc.rpt, &wk.sc.final)!=EOF){
			
			//�m�[�h1���̃������̈���m��
			node=Alloc_Node();
	
			//�m�[�h�Ƀf�[�^��ݒ肷��
			*node=wk;

			//���������m�[�h���`�F�[���ɂ͂ߍ���(�w���ԍ��̏���)
			for(ip=start;ip->next!=NULL;ip=ip->next){
				if( node->ID < ip->next->ID){ 
					node->next=ip->next;
					ip->next=node;
					break;
				}
			}
			
			//�ł��w���ԍ����ő�̏ꍇ�`�F�[���̍Ō�ɂȂ�
			if(ip->next==NULL){	//�`�F�[����NULL�ɍs��������
				ip->next=node;		//�Ō����node����������
				node->next=NULL;	//�V���ɍŌ���̃}�[�N(NULL)
			}
	}

	fclose(fp);	//�t�@�C���̃N���[�Y
}
//------------------------------------------------------------------------------
//							print_list�֐�									�@  
//																			�@  
//	��  ���FProg2 *start                                                        
//�@�߂�l�Fvoid															    
//	�@�\�F���X�glist�̑S�m�[�h����ʂɏo��									    
//------------------------------------------------------------------------------
void print_list(Prog2 *start)
{
	Prog2 *ip;

	//�`�F�[�������ǂ��ăm�[�h�̓��e��\������
	for(ip=start->next; ip!=NULL; ip=ip->next){
		printf("%-10d%-10s%10.1f%10.1f%10d\n",
			ip->ID,ip->name, ip->sc.mini, ip->sc.rpt, ip->sc.final);
	}
}
//------------------------------------------------------------------------------
//							print_node�֐�									�@  
//																			�@  
//	��  ���FProg2 *node                                                         
//�@�߂�l�Fvoid															    
//	�@  �\�Fnode���w���m�[�h�f�[�^����ʂɏo��									    
//------------------------------------------------------------------------------
void print_node(Prog2 *node)
{
	printf("%-10d%-10s%10.1f%10.1f%10d\n",
			node->ID, node->name, node->sc.mini, node->sc.rpt, node->sc.final);
}
//------------------------------------------------------------------------------
//							   Alloc_Node�֐�									
//																			�@  
//	��  ���Fvoid                                                                
//�@�߂�l�FProg2 *												            
//	�@  �\�F�m�[�h1���̋L���̈�̊m�ۂ��A�m�ۂ����̈�ւ̃|�C���^��Ԃ�       
//------------------------------------------------------------------------------
Prog2 *Alloc_Node(void)
{
	Prog2 *pt;

	pt=(Prog2 *)calloc(1, sizeof(Prog2));	//Prog2�^1�����I�Ɋm��
	if(pt==NULL){
		printf("�L���̈�̊m�ۂɎ��s���܂���\n");
		exit(1);
	}

	return pt;
}