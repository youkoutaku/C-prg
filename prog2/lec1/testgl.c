//----------------------------------------------------------------------------
//														<testgl.c>
//
//													������̕`��(�^�u2�j
//
//          gcc -o testgl testgl.c -lfreeglut -lglu32 -lopengl32
//                           �܂���
//					gccgl -o testgl testgl.c
//--------------------------------------------------------------------------- 

#include <GL/freeglut.h>	//freeglut�̃w�b�_�t�@�C���̓ǂݍ���

// �������`�悷��֐� 
void drawString2D( double x, double y, char *str )
{
  glRasterPos2d( x, y );   // ������̐擪�̕`��ʒu��(x,y)�ɐݒ�

  while( *str != '\0' ) {  // �������I���R�[�h�łȂ����
		 // 24�|�C���g��Times Roman�r�b�g�}�b�v�t�H���g��1�������`��
    glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *str ); 
    str++;  //�|�C���^��1��������ɐi�߂�
  }
}

void display(void) {  // ��ʕ`��֐�
 
    glClearColor( 0, 0, 0, 1 );  		// �E�B���h�E�̔w�i�F�����ɐݒ�
    glClear( GL_COLOR_BUFFER_BIT );	// �J���[�o�b�t�@���N���A�i�w�i�̓h��Ԃ��j    
		drawString2D(-0.7,  0.0, "Mechanical Systems Engineering" ); 
		drawString2D(-0.7, -0.1, "Programming Excercises II" );

    glFlush(); 					// �����s�̖��߂�S�Ď��s
 
}

int main( int argc, char *argv[] ) {  

    glutInit(&argc, argv);						// GLUT���̏�����
    glutInitDisplayMode(GLUT_RGBA);   // �f�B�X�v���C���[�h�̐ݒ�
    glutInitWindowSize(500,500);      // �E�B���h�E�T�C�Y�̐ݒ�i�P�ʂ�pixel)
    glutInitWindowPosition(100,100);  // �E�B���h�E�̈ʒu�i���j�^���ォ��(100,100)pixel�̈ʒu)
    glutCreateWindow(argv[0]); 				// �E�B���h�E�����i�E�B���h�E�̃^�C�g���ݒ�j

    glutDisplayFunc(display);       	// �R�[���o�b�N�֐��̓o�^�i��ʕ`��)
    
    glutMainLoop(); 									//�C�x���g�҂��̖������[�v

    return 0;
}

