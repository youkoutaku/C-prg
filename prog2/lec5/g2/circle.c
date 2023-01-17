//----------------------------------------------------------------------------
//									         <circle.c>
//
//						2�����̍��W�ϊ��i�������W��p�����A�t�B���ϊ��j
//													�~�̕`��iPOLYGON)(�^�u2�j
//
// (Windows �}�N�������jgcc -o circle circle.c -lfreeglut -lglu32 -lopengl32
// (Windows �}�N���g�p)	gccgl -o circle circle.c
// (Mac OS �̏ꍇ)			gcc -o circle circle.c -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION
//--------------------------------------------------------------------------- 
#ifndef __APPLE__  				// OS��Mac�łȂ� (Windows�̏ꍇ)
#include <GL/freeglut.h>	//freeglut�̃w�b�_�t�@�C���̓ǂݍ���
#else
#include <GLUT/glut.h>  	// Mac�̏ꍇ�̃w�b�_
#endif

#include <math.h>								//���w�֐�
#define N 360										//���_�̐�
#define DEG 45									//��]�p�x�i�x)
#define THETA (2*M_PI*DEG/360)	//��]�p�x�i���W�A���j
#define TX 0.3									//X�������ړ���
#define TY 0.5									//Y�������ړ���
#define Sx 0.5									//X�������g�嗦
#define Sy 2.0									//Y�������g�嗦
//--------------------------------------------------------------------------- 
// �O���[�o���ϐ�
//--------------------------------------------------------------------------- 
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
//�ϊ��s��i���ϊ��j
double I[3][3]={{1.0, 0.0, 0.0 },
								 {0.0, 1.0, 0.0 },
								 {0.0, 0.0, 1.0}};
//--------------------------------------------------------------------------- 
// �~�̒��_�ݒ�֐�:���S( xc, yc ), ���ar�̉~
//--------------------------------------------------------------------------- 
void set_circle_vertices(double xc, double yc, double r, double v[][3])
{
		int i;
		//���_���W�̐ݒ�
		for( i = 0; i < N; i++ ) {  // �~����̒��_��360/N�x���݂�N�ݒ� 
      	v[i][0] = xc + r * cos( 2.0 * M_PI * i / N ); // ���_��x���W 
      	v[i][1] = yc + r * sin( 2.0 * M_PI * i / N ); // ���_��y���W 
				v[i][2] = 1.0;
    }
}
//--------------------------------------------------------------------------- 
// ��ʕ\���֐��i�`��֐��j
//--------------------------------------------------------------------------- 
void display(void) {

		int	i,j,k;		//	�J�E���^

 		//���_���W(�ϊ��O�j
		double	v[N][3];
		double 	vt[N][3]={0};	//���_���W�i�ϊ���j
				
		set_circle_vertices(0.5, 0.0, 0.3, v); //�~�̒��_���W�̐ݒ�

    glClearColor( 1, 1, 1, 1 );  		// �E�B���h�E�̔w�i�F�𔒂ɐݒ�
    glClear( GL_COLOR_BUFFER_BIT );	// �J���[�o�b�t�@���N���A�i�w�i�̓h��Ԃ��j
    
		//���W�ƃO���b�h���̕`��
		glBegin(GL_LINES);
			for(i=-9;i<=9;i++){ //X���Ɖ��O���b�h��
				if(i==0) 	glColor3d(0.0, 0.0, 0.0);			//��
				else			glColor3d(0.75, 0.75, 0.75);	//�O���[
				glVertex2d( -1.0, i*0.1 );
				glVertex2d(  1.0, i*0.1 );
			}
			for(i=-9;i<=9;i++){ //Y���Əc�O���b�h��
				if(i==0) 	glColor3d(0.0, 0.0, 0.0);			//��
				else			glColor3d(0.75, 0.75, 0.75);	//�O���[
				glVertex2d( i*0.1, -1.0 );
				glVertex2d( i*0.1,  1.0 );
			}
		glEnd();
    
#if 1
    //�A�t�B���ϊ��i�g��E�k���j
		for(k=0;k<N;k++){
			for(i=0;i<3;i++){
				vt[k][i]=0.0;
				for(j=0;j<3;j++)	vt[k][i]+=Ts[i][j]*v[k][j];
			}
		}
#endif

#if 0
		//�A�t�B���ϊ��i��]�j
		for(k=0;k<N;k++){
			for(i=0;i<3;i++){
				vt[k][i]=0.0;
				for(j=0;j<3;j++)	vt[k][i]+=Tr[i][j]*v[k][j];
			}
		}
#endif

#if 0
		//�A�t�B���ϊ��i���s�ړ��j
		for(k=0;k<N;k++){
			for(i=0;i<3;i++){
				vt[k][i]=0.0;
				for(j=0;j<3;j++)	vt[k][i]+=Tt[i][j]*v[k][j];
			}
		}
#endif

#if 0
		//�A�t�B���ϊ��i���ϊ��j
		for(k=0;k<N;k++){
			for(i=0;i<3;i++){
				vt[k][i]=0.0;
				for(j=0;j<3;j++)	vt[k][i]+=I[i][j]*v[k][j];
			}
		}
#endif

		glColor3d( 0, 0, 1 ); 		// �F�̐ݒ�(��)
		glBegin( GL_POLYGON ); 		// �}�`�`��^�C�v�̐ݒ�J�n: N�p�`(�h��Ԃ�) 		
			for(k=0;k<N;k++)	glVertex2d( vt[k][0], vt[k][1] );
  	glEnd( );  								// �}�`�`��^�C�v�̐ݒ�I��

    glFlush(); 					      // �����s�̖��߂�S�Ď��s
 
}
//--------------------------------------------------------------------------- 
// ���C���֐�
//--------------------------------------------------------------------------- 
int main( int argc, char *argv[] ) {  

    glutInit(&argc, argv);						// GLUT���̏�����
    glutInitDisplayMode(GLUT_RGBA);   // �f�B�X�v���C���[�h�̐ݒ�
    glutInitWindowSize(500,500);      // �E�B���h�E�T�C�Y�̐ݒ�i�P�ʂ�pixel)
    glutInitWindowPosition(100,100);  // �E�B���h�E�̈ʒu�i���j�^���ォ��(100,100)pixel�̈ʒu)
    glutCreateWindow(argv[0]); 				// �E�B���h�E�����i�E�B���h�E�̃^�C�g���ݒ�j

    glutDisplayFunc(display);       	// �R�[���o�b�N�֐��̓o�^�i��ʕ\��)
    
    glutMainLoop(); 									//�C�x���g�҂��̖������[�v

    return 0;
}

