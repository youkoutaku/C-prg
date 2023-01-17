//�ۑ�6 �I���W�i���}�`�f�[�^�̃t�@�C�����o��
//20T1126N YANG GUANGZE(�k�L��)
//gccgl -o R6-20t1126n R6-20t1126n.c
	
#include <GL/freeglut.h>	
#include <stdio.h>							
#include <stdlib.h>  						
#include <math.h>								
#define MAX 	5		//�g�ݍ��킹��}�`�̐��̏��					
#define MN 		84		//�}�`�S�̂̒��_���̏��				
#define WIDTH 	500		//�E�B���h�E�̉����i�f�t�H���g�j					
#define HEIGHT 	500		//�E�B���h�E�̍����i�f�t�H���g�j					

//--------------------------------------------------------------------------- 
//�}�`���p�z��ƕϐ��̐錾
//--------------------------------------------------------------------------- 
GLenum 	mode[MAX];			//�`��^�C�v
int		Vn[MAX];			//���_��	
double 	color[MAX][3];		//�F�iRGB�j
double 	v[MN][3];			//���_���W�i�ϊ��O�j
double 	vt[MN][3];			//���_���W�i�ϊ���j
int		part_num=0;			//���i���p�̃J�E���^
//--------------------------------------------------------------------------- 
// �O���[�o���ϐ��i�ϊ��s��A�E�B���h�E�j
//--------------------------------------------------------------------------- 
// �ϊ��s��̃p�����^
double DEG=45;				//��]�p�x�i�x)�̃f�t�H���g
double THETA;				//��]�p�x�i���W�A���j�̃f�t�H���g
double TX=0.3;				//X�������ړ��ʂ̃f�t�H���g
double TY=0.5;				//Y�������ړ��ʂ̃f�t�H���g
double Sx=0.5;				//X�������g�嗦�̃f�t�H���g
double Sy=2.0;				//Y�������g�嗦�̃f�t�H���g
// �E�B���h�E���ɐݒ肳�����W 
double xmin;				// ���[ 
double xmax;				// �E�[ 
double ymin;				// ���[ 
double ymax;				// ��[ 

char	KEY;				//�ϊ��L�[

double Ts[3][3]={0};		//�ϊ��s��i�g��E�k���j
double Tr[3][3]={0};		//�ϊ��s��i��]�j
double Tt[3][3]={0};		//�ϊ��s��i���s�ړ��j
double I[3][3]={0};			//�ϊ��s��i�ϊ����j

//--------------------------------------------------------------------------- 
// �֐��̃v���g�^�C�v�錾
//--------------------------------------------------------------------------- 
void affine(void);
void init(void);
void set_vertices(double T[][3], double v[][3], double vt[][3], int n);
void load_data(void);
void draw_axis(void);
void save_data(void);
//--------------------------------------------------------------------------- 
// �ϊ��s��̐ݒ�
//--------------------------------------------------------------------------- 
void affine(void){
	THETA=2*M_PI*DEG/360;		//��]�p�x�̐ݒ�
	//scaling
	Ts[0][0]=Sx;	Ts[0][1]=0.0;	Ts[0][2]=0.0;
    Ts[1][0]=0.0;	Ts[1][1]=Sy;	Ts[1][2]=0.0;
    Ts[2][0]=0.0;	Ts[2][1]=0.0;	Ts[2][2]=1.0;

	//rotation
	Tr[0][0]=cos(THETA); 	Tr[0][1]=-sin(THETA);	Tr[0][2]=0.0;
    Tr[1][0]=sin(THETA);	Tr[1][1]=cos(THETA);	Tr[1][2]=0.0;
    Tr[2][0]=0.0;			Tr[2][1]=0.0;			Tr[2][2]=1.0;

	//translation
	Tt[0][0]=1.0;	Tt[0][1]=0.0;	Tt[0][2]=TX;
    Tt[1][0]=0.0;	Tt[1][1]=1.0;	Tt[1][2]=TY;
    Tt[2][0]=0.0;	Tt[2][1]=0.0;	Tt[2][2]=1.0;

	//�ϊ����i�P�ʍs��j
	I[0][0]=1.0;	I[0][1]=0.0;	I[0][2]=0.0;
    I[1][0]=0.0;	I[1][1]=1.0;	I[1][2]=0.0;
    I[2][0]=0.0;	I[2][1]=0.0;	I[2][2]=1.0;
}
//--------------------------------------------------------------------------- 
// ���_�ݒ�֐�
// 		T:�ϊ��s��p�z��ւ̃|�C���^, 
// 		v:���_���W�z��i�ϊ��O�j�ւ̃|�C���^
// 		vt:���_���W�z��i�ϊ���j�ւ̃|�C���^
//		n:���_��
//--------------------------------------------------------------------------- 
void set_vertices(double T[][3], double v[][3], double vt[][3], int n){
	int i,j,k;

	//N�p�`�̒��_���w��(k�Ԗڂ̒��_�̌v�Z�j
	for(k=0;k<n;k++){
		for(i=0;i<3;i++){
			vt[k][i]=0.0;
			for(j=0;j<3;j++)	vt[k][i]+=T[i][j]*v[k][j];
		}
	}
}
//--------------------------------------------------------------------------- 
// ������
//--------------------------------------------------------------------------- 
void init(void){
	affine();	//set affine transformation matrices	

	load_data(); //	�t�@�C�����璸�_���W�ƐF���̓ǂݍ���
}

//--------------------------------------------------------------------------- 
// �t�@�C������̐}�`�f�[�^�ǂݍ���
//--------------------------------------------------------------------------- 
void load_data(void){
	FILE 	*fp; 								
	char 	fname[]="R6-20t1126n_in.csv",
				ss[256],							
				md;										
	double	dt1,dt2,dt3,dt4;		
	int		vsum=0;							
 
	fp = fopen(fname, "r"); 		
	if(fp == NULL) {
			printf("Can't open %s!\n", fname);
			exit(1);
	}
	
	while(fgets(ss, 256, fp) != NULL){
		printf("%s",ss);
		sscanf(ss, "%c,%lf,%lf,%lf,%lf", &md, &dt1, &dt2, &dt3, &dt4);
		if( md=='p'||md=='l'||md=='L'||md=='s'||md=='t'||
        	md=='T'||md=='f'||md=='q'||md=='Q'||md=='P' ){
	
			switch(md){
				case 'p':	mode[part_num]=0x0000;	break;	//GL_POINTS
				case 'l':	mode[part_num]=0x0001;	break;	//GL_LINES
				case 'L':	mode[part_num]=0x0002;	break;	//GL_LINE_LOOP
				case 's':	mode[part_num]=0x0003;	break;	//GL_LINE_STRIP
				case 't':	mode[part_num]=0x0004;	break;	//GL_TRIANGLES
				case 'T':	mode[part_num]=0x0005;	break;	//GL_TRIANGLE_STRIP
				case 'f':	mode[part_num]=0x0006;	break;	//GL_TRIANGLE_FAN
				case 'q':	mode[part_num]=0x0007;	break;	//GL_QUADS
				case 'Q':	mode[part_num]=0x0008;	break;	//GL_QUAD_STRIP
				case 'P':	mode[part_num]=0x0009;	break;	//GL_POLYGON
				default: printf("Can't discriminate the mode(primitive)."); exit(0);
			}
		
		Vn[part_num]=dt1;				
		color[part_num][0]=dt2;	
		color[part_num][1]=dt3;	
		color[part_num][2]=dt4;	
		part_num++;			
		}else if(md=='v'){ 
			v[vsum][0]=dt1;	
			v[vsum][1]=dt2;	
			v[vsum][2]=dt3;	
			vsum++;					
		}else{
			printf("Can't discriminate the mode."); exit(0);
		}
	} 
	printf("\nloaded vertex data(part_num=%d vsum=%d)\n",part_num, vsum);	
}
//--------------------------------------------------------------------------- 
// ���W�ƃO���b�h���̕`��
//--------------------------------------------------------------------------- 
void draw_axis(void){
	double gd;
	glBegin(GL_LINES);
		glColor3d(0.75, 0.75, 0.75);	
		for(gd=ymin; gd<=ymax; gd+=0.1){ 
			glVertex2d( xmin, gd );
			glVertex2d( xmax, gd );
		}
		for(gd=xmin; gd<=xmax; gd+=0.1){ 
			glVertex2d( gd, ymin );
			glVertex2d( gd, ymax );
		}
		glColor3d(0.0, 0.0, 0.0);
		glVertex2d( xmin, 0.0);		glVertex2d( xmax, 0.0 );	
		glVertex2d( 0.0, ymin );	glVertex2d( 0.0, ymax );	
		glEnd();
}
//--------------------------------------------------------------------------- 
// ��ʕ\���֐��i�`��֐��j
//--------------------------------------------------------------------------- 
void display(void) {
	int	i,k,n;		
				
    glClearColor( 0, 0, 0, 1 );  		
    glClear( GL_COLOR_BUFFER_BIT );		
	draw_axis();	

	int	vsum=0;
	for(n=0;n<part_num;n++)	vsum+=Vn[n];

	if(KEY=='s' || KEY=='S') 						
    	set_vertices(Ts, v, vt, vsum);
	else if(KEY=='r' || KEY=='R')			
		set_vertices(Tr, v, vt, vsum);
	else if(KEY=='t' || KEY=='T')						
		set_vertices(Tt, v, vt, vsum);
	else	set_vertices(I, v, vt, vsum);	

	int ksum=0;
	for(n=0;n<part_num;n++){
		glColor3d(color[n][0], color[n][1], color[n][2]);
		glBegin( mode[n] );  		
		for(k=ksum;k<ksum+Vn[n];k++) glVertex2d( vt[k][0], vt[k][1] );
		ksum=k;	
  		glEnd();  						
	}

	for(k=0;k<vsum;k++){
			for(i=0;i<3;i++)	v[k][i]=vt[k][i];
	}

	glFlush(); 

	KEY='x';	
}
//--------------------------------------------------------------------------- 
// �E�B���h�E�T�C�Y�ύX��
//--------------------------------------------------------------------------- 
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

	xmin=-1.0*w/WIDTH; xmax=1.0*w/WIDTH; ymin=-1.0*h/HEIGHT; ymax=1.0*h/HEIGHT;
	gluOrtho2D(xmin, xmax, ymin, ymax);
}
//--------------------------------------------------------------------------- 
// �L�[�{�[�h�C�x���g�R�[���o�b�N�֐�
//--------------------------------------------------------------------------- 
void keyboard(unsigned char key, int x, int y){
  	switch (key) {
		case 'r':	case 'R':
			KEY=key;
			glutPostRedisplay();		
			break;
		case 's':	case 'S':
			KEY=key;
			glutPostRedisplay();		
			break;
		case 't':	case 'T':
			KEY=key;
			glutPostRedisplay();		
			break;
		case 'f': case 'F':
			save_data();
			break;
  		case 'q':	case 'Q':	case '\033':   
			exit(0);
  		default:
    		break;
  	}
}
void save_data(void){
    FILE *fp;
	char fname[]="R6-20t1126n_out.csv";
    fp =fopen(fname,"w");
    int ksum=0,n=0;
	char md[MAX]={0};
    for(n=0; n<part_num;n++){
		if (mode[n]==0x0000){
			md[n]='p';
		}else if(mode[n]== 0x0001){
			md[n]='l';
		}else if(mode[n]== 0x0002){
			md[n]='L';
		}else if(mode[n]== 0x0003){
			md[n]='s';
		}else if(mode[n]== 0x0004){
			md[n]='t';
		}else if(mode[n]== 0x0005){
			md[n]='T';
		}else if(mode[n]== 0x0006){
			md[n]='f';
		}else if(mode[n]== 0x0007){
			md[n]='q';
		}else if(mode[n]== 0x0008){
			md[n]='Q';
		}else if(mode[n]== 0x0009){
			md[n]='P';
		}else{
			printf("�`��^�C�v�̏o�͂Ɏ��s���܂���");
		}
		fprintf(fp,"%c,%d,%lf,%lf,%lf\n", md[n], Vn[n], color[n][0], color[n][1], color[n][2]);

		for(ksum=0; ksum<Vn[n]; ksum++){
				fprintf(fp,"v,%lf,%lf,%lf,0\n", v[ksum][0], v[ksum][1], v[ksum][2]);
		}
	}

	if(fp == NULL){
		printf("�o�̓t�@�C���Ɏ��s���܂���");
    	exit(1);
    }

	printf("saved data to %s\n",fname);

	fclose(fp);
}
//--------------------------------------------------------------------------- 
// ���C���֐�
//--------------------------------------------------------------------------- 
int main( int argc, char *argv[] ) {  

    glutInit(&argc, argv);					
    glutInitDisplayMode(GLUT_RGBA);   
    glutInitWindowSize(WIDTH,HEIGHT);     
    glutInitWindowPosition(100,100);  
    glutCreateWindow(argv[0]); 		

	init();		

    glutDisplayFunc(display);       

	glutReshapeFunc(reshape);		

    glutKeyboardFunc(keyboard); 	
			
    glutMainLoop(); 									

    return 0;
}

