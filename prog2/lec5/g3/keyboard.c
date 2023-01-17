//----------------------------------------------------------------------------
//									         <keybord.c>(�^�u2�j
//
//						�� 2�����̍��W�ϊ��i�������W��p�����A�t�B���ϊ��j
//						�� N�p�`�̕`��iPOLYGON)
//						�� �E�B���h�E�T�C�Y�ύX���̍��W���̍Đݒ�
//						�� �L�[�{�[�h���͂ɂ��ϊ��s��̑I��
//            �� �A���L�[���͂ɂ�鍇���ϊ�
//              
// (Windows �}�N�������jgcc -o keybord keybord.c -lfreeglut -lglu32 -lopengl32
// (Windows �}�N���g�p)	gccgl -o keybord keybord.c
// (Mac OS �̏ꍇ)			gcc -o keybord keybord.c -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION
//--------------------------------------------------------------------------- 
#ifndef __APPLE__  				// OS��Mac�łȂ� (Windows�̏ꍇ)
#include <GL/freeglut.h>	//freeglut�̃w�b�_�t�@�C���̓ǂݍ���
#else
#include <GLUT/glut.h>  	// Mac�̏ꍇ�̃w�b�_
#endif

#include <stdlib.h>  						//exit()�p
#include <math.h>								//���w�֐�
#define N 4											//���_�̐�
#define DEG 60									//��]�p�x�i�x)
#define THETA (2*M_PI*DEG/360)	//��]�p�x�i���W�A���j
#define TX 0.3									//X�������ړ���
#define TY 0.5									//Y�������ړ���
#define Sx 0.5									//X�������g�嗦
#define Sy 2.0									//Y�������g�嗦
#define WIDTH 	500							//�E�B���h�E�̉����i�f�t�H���g�j
#define HEIGHT 	500							//�E�B���h�E�̍����i�f�t�H���g�j
//--------------------------------------------------------------------------- 
// �O���[�o���ϐ�
//--------------------------------------------------------------------------- 
// �E�B���h�E���ɐݒ肳�����W 
double xmin;							// ���[ 
double xmax;							// �E�[ 
double ymin;							// ���[ 
double ymax;							// ��[ 

char	KEY;								//�ϊ��L�[

//�ϊ��s��i�g��E�k���j
double Ts[3][3]={{Sx,  0.0, 0.0},
								 {0.0, Sy,  0.0},
								 {0.0, 0.0, 1.0}};
//�ϊ��s��i��]�j
double Tr[3][3]={{cos(THETA), -sin(THETA), 0.0},
								 {sin(THETA),  cos(THETA), 0.0},
								 {0.0,				 0.0, 			 1.0}};
//�ϊ��s��i���s�ړ��j
double Tt[3][3]={{1.0, 0.0, TX },
								 {0.0, 1.0, TY },
								 {0.0, 0.0, 1.0}};
//���_���W(�ϊ��O�j
double	v[N][3]={{ 0.0,  0.0, 1.0},
								 { 0.3,  0.0, 1.0},
								 { 0.3,  0.3, 1.0},
								 { 0.0,  0.3, 1.0}};
double	vt[N][3]={0}; 	//���_���W�i�ϊ���j
//--------------------------------------------------------------------------- 
// ��ʕ\���֐��i�`��֐��j
//--------------------------------------------------------------------------- 
void display(void) {

		int	i,j,k;		//	�J�E���^

    glClearColor( 1, 1, 1, 1 );  		// �E�B���h�E�̔w�i�F�𔒂ɐݒ�
    glClear( GL_COLOR_BUFFER_BIT );	// �J���[�o�b�t�@���N���A�i�w�i�̓h��Ԃ��j
    
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
			//x��
			glVertex2d( xmin, 0.0);
			glVertex2d( xmax, 0.0 );
			//y��
			glVertex2d( 0.0, ymin );
			glVertex2d( 0.0, ymax );
		glEnd();
    
		if(KEY=='s' || KEY=='S'){ //�g��E�k��
    	for(k=0;k<N;k++){
				for(i=0;i<3;i++){
					vt[k][i]=0.0;
					for(j=0;j<3;j++)	vt[k][i]+=Ts[i][j]*v[k][j];
				}
			}
		}
		else if(KEY=='r' || KEY=='R'){	//��]�ړ�
			for(k=0;k<N;k++){
				for(i=0;i<3;i++){
					vt[k][i]=0.0;
					for(j=0;j<3;j++)	vt[k][i]+=Tr[i][j]*v[k][j];
				}
			}
		}
		else if(KEY=='t' || KEY=='T'){	//���s�ړ�		
			for(k=0;k<N;k++){
				for(i=0;i<3;i++){
					vt[k][i]=0.0;
					for(j=0;j<3;j++)	vt[k][i]+=Tt[i][j]*v[k][j];
				}
			}
		}
		else{		//�ϊ���
			for(k=0;k<N;k++)
				for(i=0;i<3;i++)	vt[k][i]=v[k][i];
		}

		glColor3d( 0, 0, 1 ); 		// �F�̐ݒ�(��)
		glBegin( GL_POLYGON ); 		// �}�`�`��^�C�v�̐ݒ�J�n: N�p�`(�h��Ԃ�) 		
			for(k=0;k<N;k++)	glVertex2d( vt[k][0], vt[k][1] );
  	glEnd( );  									// �}�`�`��^�C�v�̐ݒ�I��

		//���݂̒��_���W��v�ɐݒ�
		for(k=0;k<N;k++)
				for(i=0;i<3;i++)	v[k][i]=vt[k][i];

    glFlush(); 					        // �����s�̖��߂�S�Ď��s

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

    glutDisplayFunc(display);       	// �R�[���o�b�N�֐��̓o�^�i��ʕ\��)

		glutReshapeFunc(reshape);					//�E�B���h�E�T�C�Y�ύX��

    glutKeyboardFunc(keyboard); 			//�L�[�{�[�h�C�x���g�R�[���o�b�N�֐�

    glutMainLoop(); 									//�C�x���g�҂��̖������[�v

    return 0;
}
