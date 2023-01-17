//----------------------------------------------------------------------------
//									         <triangle.c>
//
//													�O�p�`�̕`��(�^�u2�j
//
// (Windows �}�N�������jgcc -o triangle triangle.c -lfreeglut -lglu32 -lopengl32
// (Windows �}�N���g�p)	gccgl -o triangle triangle.c
// (Mac OS �̏ꍇ)			gcc -o triangle triangle.c -framework OpenGL -framework GLUT -DGL_SILENCE_DEPRECATION
//--------------------------------------------------------------------------- 

#ifndef __APPLE__  				// OS��Mac�łȂ� (Windows�̏ꍇ)
#include <GL/freeglut.h>	//freeglut�̃w�b�_�t�@�C���̓ǂݍ���
#else
#include <GLUT/glut.h>  	// Mac�̏ꍇ�̃w�b�_
#endif

void display(void) {  // ��ʕ\���֐�
 
    glClearColor( 0, 0, 0, 1 );  		// �E�B���h�E�̔w�i�F�����ɐݒ�
    glClear( GL_COLOR_BUFFER_BIT );	// �J���[�o�b�t�@���N���A�i�w�i�̓h��Ԃ��j
    
		/* �����ɐ��̑����̐ݒ���L�q */
		glColor3d( 1, 0, 0 ); 			// �F�̐ݒ�(��)
		glBegin( GL_TRIANGLES ); 		// �}�`�`��^�C�v�̐ݒ�J�n: �O�p�`(�h��Ԃ�) 
    	//�O�p�`��3���_���w�� 
    	glVertex2d( -0.8, -0.8 );
    	glVertex2d(  0.8, -0.8 );
    	glVertex2d(  0.0,  0.8 );
  	glEnd( );  									// �}�`�`��^�C�v�̐ݒ�I��

		/* ������2�Ԗڂ̎O�p�`�̕`����L�q */

    glFlush(); 					        // �����s�̖��߂�S�Ď��s
 
}

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

