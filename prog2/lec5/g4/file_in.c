//----------------------------------------------------------------------------
//									         <file_in.c>(�^�u2�j
//
//						�� 2�����̍��W�ϊ��i�������W��p�����A�t�B���ϊ��j
//						�� �E�B���h�E�T�C�Y�ύX���̍��W���̍Đݒ�
//						�� �L�[�{�[�h���͂ɂ��ϊ��s��̑I��
//            �� �A���L�[���͂ɂ�鍇���ϊ�
//            �� ���W�ϊ��s��̐ݒ�ƍ��W�ϊ��̏������֐���
//            �� �}�`�f�[�^�i�`��^�C�v�E�F�iRGB)�E���_���W�j�̃t�@�C������̓ǂݍ���
//              
// (Windows �}�N�������jgcc -o file_in file_in.c -lfreeglut -lglu32 -lopengl32
// (Windows �}�N���g�p)	gccgl -o file_in file_in.c
// (Mac OS �̏ꍇ)			gcc -o file_in file_in.c -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION
//--------------------------------------------------------------------------- 
#ifndef __APPLE__  				// OS��Mac�łȂ� (Windows�̏ꍇ)
#include <GL/freeglut.h>	//freeglut�̃w�b�_�t�@�C���̓ǂݍ���
#else
#include <GLUT/glut.h>  	// Mac�̏ꍇ�̃w�b�_
#endif

#include <stdio.h>							//printf()�p
#include <stdlib.h>  						//exit()�p
#include <math.h>								//���w�֐�
#define MAX 		5								//�g�ݍ��킹��}�`�̐��̏��
#define MN 			20							//�}�`�S�̂̒��_���̏��
#define WIDTH 	500							//�E�B���h�E�̉����i�f�t�H���g�j
#define HEIGHT 	500							//�E�B���h�E�̍����i�f�t�H���g�j

//--------------------------------------------------------------------------- 
//�}�`���p�z��ƕϐ��̐錾
//--------------------------------------------------------------------------- 
GLenum 	mode[MAX];			//�`��^�C�v
int			Vn[MAX];				//���_��
double 	color[MAX][3];	//�F�iRGB�j
double 	v[MN][3];				//���_���W�i�ϊ��O�j
double 	vt[MN][3];			//���_���W�i�ϊ���j
int			part_num=0;			//���i���p�̃J�E���^
//--------------------------------------------------------------------------- 
// �O���[�o���ϐ��i�ϊ��s��A�E�B���h�E�j
//--------------------------------------------------------------------------- 
// �ϊ��s��̃p�����^
double DEG=45;							//��]�p�x�i�x)�̃f�t�H���g
double THETA;								//��]�p�x�i���W�A���j�̃f�t�H���g
double TX=0.3;							//X�������ړ��ʂ̃f�t�H���g
double TY=0.5;							//Y�������ړ��ʂ̃f�t�H���g
double Sx=0.5;							//X�������g�嗦�̃f�t�H���g
double Sy=2.0;							//Y�������g�嗦�̃f�t�H���g

// �E�B���h�E���ɐݒ肳�����W 
double xmin;							// ���[ 
double xmax;							// �E�[ 
double ymin;							// ���[ 
double ymax;							// ��[ 

char	KEY;								//�ϊ��L�[

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
//--------------------------------------------------------------------------- 
// �ϊ��s��̐ݒ�
//--------------------------------------------------------------------------- 
void affine(void)
{
	THETA=2*M_PI*DEG/360;		//��]�p�x�̐ݒ�
	//scaling
	Ts[0][0]=Sx;	Ts[0][1]=0.0;	Ts[0][2]=0.0;
  Ts[1][0]=0.0;	Ts[1][1]=Sy;	Ts[1][2]=0.0;
  Ts[2][0]=0.0;	Ts[2][1]=0.0;	Ts[2][2]=1.0;

	//rotation
	Tr[0][0]=cos(THETA); 	Tr[0][1]=-sin(THETA);	Tr[0][2]=0.0;
  Tr[1][0]=sin(THETA);	Tr[1][1]=cos(THETA);	Tr[1][2]=0.0;
  Tr[2][0]=0.0;					Tr[2][1]=0.0;					Tr[2][2]=1.0;

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
void set_vertices(double T[][3], double v[][3], double vt[][3], int n)
{
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
void init(void)
{
		affine();		//set affine transformation matrices

		load_data(); //	�t�@�C�����璸�_���W�ƐF���̓ǂݍ���
}

//--------------------------------------------------------------------------- 
// �t�@�C������̐}�`�f�[�^�ǂݍ���
//--------------------------------------------------------------------------- 
void load_data(void)
{
	FILE 	*fp; 									//�t�@�C���|�C���^
	char 	fname[]="file_in.csv",//�ǂݍ��݃t�@�C����
				ss[256],							//�ǂݍ��ݕ�����i�[�p
				md;										//�}�`�̃^�C�v(v�i���_���W�j,p,l,L,s,t,T,f,q,Q,P)
	double	dt1,dt2,dt3,dt4;		//�ǂݍ��݃f�[�^�ꎞ�i�[�p�ϐ�
	int		vsum=0;								//�ǂݍ��񂾒��_�f�[�^�̐�
 
	fp = fopen(fname, "r"); 		//�t�@�C���I�[�v��
	if(fp == NULL) {
			printf("Can't open %s!\n", fname);
			exit(1);
	}
	
	while(fgets(ss, 256, fp) != NULL){
			printf("%s",ss);
			sscanf(ss, "%c,%lf,%lf,%lf,%lf", &md, &dt1, &dt2, &dt3, &dt4);
#if 0
			printf("md=%c dt1=%.2f dt2=%.2f dt3=%.2f dt4=%.2f\n", md, dt1, dt2, dt3, dt4);
#endif
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

					Vn[part_num]=dt1;				//���_��
					color[part_num][0]=dt2;	//R
					color[part_num][1]=dt3;	//G
					color[part_num][2]=dt4;	//B
					part_num++;			//���͂������i�̐��̃J�E���g
			}
			else if(md=='v'){ //���_���W�f�[�^
					v[vsum][0]=dt1;	//x���W
					v[vsum][1]=dt2;	//y���W
					v[vsum][2]=dt3;	//1
					vsum++;					//���͂������_�f�[�^�̐��̃J�E���g
			}
			else{
					printf("Can't discriminate the mode."); exit(0);
			}
	} //the end of while loop

	//�ǂݍ��񂾕��i�̐��ƒ��_�����̏o��
	printf("\nloaded vertex data(part_num=%d vsum=%d)\n",part_num, vsum);	
}
//--------------------------------------------------------------------------- 
// ���W�ƃO���b�h���̕`��
//--------------------------------------------------------------------------- 
void draw_axis(void)
{
		double gd;
		//���W�ƃO���b�h���̕`��
		glBegin(GL_LINES);
			glColor3d(0.75, 0.75, 0.75);	//�O���[
			for(gd=ymin; gd<=ymax; gd+=0.1){ //���O���b�h��
				glVertex2d( xmin, gd );
				glVertex2d( xmax, gd );
			}
			for(gd=xmin; gd<=xmax; gd+=0.1){ //�c�O���b�h��
				glVertex2d( gd, ymin );
				glVertex2d( gd, ymax );
			}
			glColor3d(0.0, 0.0, 0.0);			//��
			glVertex2d( xmin, 0.0);		glVertex2d( xmax, 0.0 );	//x��
			glVertex2d( 0.0, ymin );	glVertex2d( 0.0, ymax );	//y��
		glEnd();
}
//--------------------------------------------------------------------------- 
// ��ʕ\���֐��i�`��֐��j
//--------------------------------------------------------------------------- 
void display(void) {

		int	i,k,n;		//	�J�E���^
				
    glClearColor( 1, 1, 1, 1 );  		// �E�B���h�E�̔w�i�F�𔒂ɐݒ�
    glClear( GL_COLOR_BUFFER_BIT );	// �J���[�o�b�t�@���N���A�i�w�i�̓h��Ԃ��j
		
		draw_axis();	//���W�ƃO���b�h���̕`��

		//�����_��(vsum)�̎Z�o
		int	vsum=0;
		for(n=0;n<part_num;n++)	vsum+=Vn[n];

		//���W�ϊ�
		if(KEY=='s' || KEY=='S') 						//�g��E�k��
    	set_vertices(Ts, v, vt, vsum);
		else if(KEY=='r' || KEY=='R')				//��]�ړ�
			set_vertices(Tr, v, vt, vsum);
		else if(KEY=='t' || KEY=='T')				//���s�ړ�		
			set_vertices(Tt, v, vt, vsum);
		else	set_vertices(I, v, vt, vsum);	//�ϊ���

		//�}�`�̕`��
		int ksum=0;
		for(n=0;n<part_num;n++){
			glColor3d(color[n][0], color[n][1], color[n][2]);//�F�̐ݒ�
			glBegin( mode[n] ); 	// �}�`�`��^�C�v�̐ݒ�J�n 		
				for(k=ksum;k<ksum+Vn[n];k++) glVertex2d( vt[k][0], vt[k][1] );
				ksum=k;	//����܂łɎg�p�������_����ksum�ɑ��
  		glEnd();  						// �}�`�`��^�C�v�̐ݒ�I��
		}

		//���݂̒��_���W��v�ɐݒ�
		for(k=0;k<vsum;k++){
				for(i=0;i<3;i++)	v[k][i]=vt[k][i];
		}

		glFlush(); 	// �����s�̖��߂�S�Ď��s

		KEY='x';		//�L�[�l��ϊ��w��ɗp�������̈ȊO�ɐݒ�
}

//--------------------------------------------------------------------------- 
// �E�B���h�E�T�C�Y�ύX��
//--------------------------------------------------------------------------- 
void reshape(int w, int h) {
    // �E�B���h�E�̕`��͈͂�[0, w] x [0, h]�ƂȂ�悤�ɐݒ�
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

		//���W����(xmin, ymin)�`(xmax, ymax)�ɐݒ�
		xmin=-1.0*w/WIDTH; xmax=1.0*w/WIDTH; ymin=-1.0*h/HEIGHT; ymax=1.0*h/HEIGHT;
		gluOrtho2D(xmin, xmax, ymin, ymax);
}
//--------------------------------------------------------------------------- 
// �L�[�{�[�h�C�x���g�R�[���o�b�N�֐�
//--------------------------------------------------------------------------- 
void keyboard(unsigned char key, int x, int y)
{
  	switch (key) {
		case 'r':	case 'R':
			KEY=key;
			glutPostRedisplay();		//�f�B�X�v���C�R�[���o�b�N�̌Ăяo��
			break;
		case 's':	case 'S':
			KEY=key;
			glutPostRedisplay();		//�f�B�X�v���C�R�[���o�b�N�̌Ăяo��
			break;
		case 't':	case 'T':
			KEY=key;
			glutPostRedisplay();		//�f�B�X�v���C�R�[���o�b�N�̌Ăяo��
			break;
  	case 'q':	case 'Q':	case '\033':  // '\033' �� ESC �� ASCII �R�[�h 
			exit(0);
  	default:
    	break;
  	}
}

//--------------------------------------------------------------------------- 
// ���C���֐�
//--------------------------------------------------------------------------- 
int main( int argc, char *argv[] ) {  

    glutInit(&argc, argv);						// GLUT���̏�����
    glutInitDisplayMode(GLUT_RGBA);   // �f�B�X�v���C���[�h�̐ݒ�
    glutInitWindowSize(WIDTH,HEIGHT);      // �E�B���h�E�T�C�Y�̐ݒ�i�P�ʂ�pixel)
    glutInitWindowPosition(100,100);  // �E�B���h�E�̈ʒu�i���j�^���ォ��(100,100)pixel�̈ʒu)
    glutCreateWindow(argv[0]); 				// �E�B���h�E�����i�E�B���h�E�̃^�C�g���ݒ�j

		init();		//initialization

    glutDisplayFunc(display);       	// �R�[���o�b�N�֐��̓o�^�i��ʕ\��)

		glutReshapeFunc(reshape);					//�E�B���h�E�T�C�Y�ύX��

    glutKeyboardFunc(keyboard); 			//�L�[�{�[�h�C�x���g�R�[���o�b�N�֐�

    glutMainLoop(); 									//�C�x���g�҂��̖������[�v

    return 0;
}

