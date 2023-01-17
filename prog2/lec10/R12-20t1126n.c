//�ۑ�12 �I���W�i���}�`�f�[�^�̃A�j���[�V����
//20t1126n YANG GUANGZE

//gccgl -o R12-20t1126n R12-20t1126n.c

#include <GL/freeglut.h>	//freeglut�̃w�b�_�t�@�C���̓ǂݍ���

#include <stdio.h>							//printf()�p
#include <stdlib.h>  						//exit(),rand()�p
#include <math.h>							//���w�֐�
#include <time.h>							//time_t�^���g�p����
#define MAX 	3							//�g�ݍ��킹��}�`�̐��̏��
#define N 		36							//��̕��i�̕`��Ɏg�p�ł���ő咸�_��
#define WIDTH 	500							//�E�B���h�E�̉����i�f�t�H���g�j
#define HEIGHT 	500							//�E�B���h�E�̍����i�f�t�H���g�j
#define TIME_INTERVAL	100
//--------------------------------------------------------------------------- 
// �\���̂̐錾
//--------------------------------------------------------------------------- 
//�}�`���p
typedef struct{
		GLenum mode;		//�`��^�C�v
		int			Vn;		//���_��
		double 	color[3];	//�F�iRGB�j
		double 	v[N][3];	//���_���W�i�ϊ��O�j
		double 	vt[N][3];	//���_���W�i�ϊ���j
} Vertex;

//--------------------------------------------------------------------------- 
// �O���[�o���ϐ�
//--------------------------------------------------------------------------- 
// �ϊ��s��̃p�����^
double DEG=45;							//��]�p�x�i�x)�̃f�t�H���g
double THETA;							//��]�p�x�i���W�A���j�̃f�t�H���g
double TX=0.1;							//X�������ړ��ʂ̃f�t�H���g
double TY=0.1;							//Y�������ړ��ʂ̃f�t�H���g
double Sx=0.5;							//X�������g�嗦�̃f�t�H���g
double Sy=2.0;							//Y�������g�嗦�̃f�t�H���g

// �E�B���h�E���ɐݒ肳�����W 
double xmin;							// ���[ 
double xmax;							// �E�[ 
double ymin;							// ���[ 
double ymax;							// ��[ 

char	KEY;							//�ϊ��L�[

double Ts[3][3]={0};		//�ϊ��s��i�g��E�k���j
double Tr[3][3]={0};		//�ϊ��s��i��]�j
double Tt[3][3]={0};		//�ϊ��s��i���s�ړ��j
double I[3][3]={0};			//�ϊ��s��i�ϊ����j

Vertex 	part[MAX]={0};		//���i���p�z��			
int			part_num=0;		//���i���p�̃J�E���^

int sim_time	;			//�V�~�����[�V��������
double x;					//�E�H�[�J�[�� x ���W
double y;					//�E�H�[�J�[�� y ���W
char	move;				//�E�H�[�J�[�̈ړ�����
//--------------------------------------------------------------------------- 
// �֐��̃v���g�^�C�v�錾
//--------------------------------------------------------------------------- 
void affine(void);
void init(void);
void set_vertices(double T[][3], Vertex *part);
void load_data(void);
void draw_axis(void);
double uniform_random(void);
void timer(int value);
//--------------------------------------------------------------------------- 
//  �������`�悷��֐�
//--------------------------------------------------------------------------- 
void drawString2D( double x, double y, char *str )
{
  glRasterPos2d( x, y );   	//������̐擪�̕`��ʒu��(x,y)�ɐݒ�

  while( *str != '\0' ) {  	//�������I���R�[�h�łȂ����
    glutBitmapCharacter( GLUT_BITMAP_HELVETICA_12, *str );  //12�|�C���g��Helvetica�r�b�g�}�b�v�t�H���g��1�������`��
    str++;  				//1��������ɐi�߂�
  }
}
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
// ���W�ϊ���̒��_�ݒ�֐�
// 		T:�ϊ��s��p�z��ւ̃|�C���^, 
// 		part:�}�`���z��iVertex�^�j�ւ̃|�C���^
//--------------------------------------------------------------------------- 
void set_vertices(double T[][3], Vertex *part)
{
	int i,j,k,n;

	for(n=0;n<part_num;n++){ //n�Ԗڂ̕��i�̍��W�ϊ�
		for(k=0;k<part[n].Vn;k++){ //n�Ԗڂ̕��i��k�Ԗڂ̒��_�̌v�Z
			for(i=0;i<3;i++){
				part[n].vt[k][i]=0.0;
				for(j=0;j<3;j++)	part[n].vt[k][i]+=T[i][j]*part[n].v[k][j];
			}
		}
	}
}
//--------------------------------------------------------------------------- 
// ������
//--------------------------------------------------------------------------- 
void init(void)
{
		affine();		//set affine transformation matrices

		load_data(); 	//�t�@�C�����璸�_���W�ƐF���̓ǂݍ���

		sim_time=0;		//�V�~�����[�V�������Ԃ̏�����

		x=0; y=0;		//�E�H�[�J�̈ʒu�̏�����
}

//--------------------------------------------------------------------------- 
// �t�@�C������̐}�`�f�[�^�ǂݍ���
//--------------------------------------------------------------------------- 
void load_data(void)
{
	FILE 	*fp; 					//�t�@�C���|�C���^
	char 	fname[]="R12-20t1126n-walker.csv",	//�ǂݍ��݃t�@�C����
				ss[256],			//�ǂݍ��ݕ�����i�[�p
				mode;				//�}�`�̃^�C�v(v�i���_���W�j,p,l,L,s,t,T,f,q,Q,P)
	double	dt1,dt2,dt3,dt4;		//�ǂݍ��݃f�[�^�ꎞ�i�[�p�ϐ�
	int		n,						//�J�E���^
			vsum;					//�ǂݍ��񂾒��_�f�[�^�̐�
 
	fp = fopen(fname, "r"); 		//�t�@�C���I�[�v��
	if(fp == NULL) {
			printf("Can't open %s!\n", fname);
			exit(1);
	}
	
	while(fgets(ss, 256, fp) != NULL){
			printf("%s",ss);
			sscanf(ss, "%c,%lf,%lf,%lf,%lf", &mode, &dt1, &dt2, &dt3, &dt4);

			if( mode=='p'||mode=='l'||mode=='L'||mode=='s'||mode=='t'||
          mode=='T'||mode=='f'||mode=='q'||mode=='Q'||mode=='P' ){
				
					switch(mode){
						case 'p':	part[part_num].mode=0x0000;	break;	//GL_POINTS
						case 'l':	part[part_num].mode=0x0001;	break;	//GL_LINES
						case 'L':	part[part_num].mode=0x0002;	break;	//GL_LINE_LOOP
						case 's':	part[part_num].mode=0x0003;	break;	//GL_LINE_STRIP
						case 't':	part[part_num].mode=0x0004;	break;	//GL_TRIANGLES
						case 'T':	part[part_num].mode=0x0005;	break;	//GL_TRIANGLE_STRIP
						case 'f':	part[part_num].mode=0x0006;	break;	//GL_TRIANGLE_FAN
						case 'q':	part[part_num].mode=0x0007;	break;	//GL_QUADS
						case 'Q':	part[part_num].mode=0x0008;	break;	//GL_QUAD_STRIP
						case 'P':	part[part_num].mode=0x0009;	break;	//GL_POLYGON
						default: printf("Can't discriminate the mode(primitive)."); exit(0);
					}

					part[part_num].Vn=dt1;					//���_��
					part[part_num].color[0]=dt2;			//R
					part[part_num].color[1]=dt3;			//G
					part[part_num].color[2]=dt4;			//B
					part_num++;				//���͂������i�̐��̃J�E���g
					vsum=0;			 		//�ǂݍ��񂾒��_�f�[�^�̐��p�̃J�E���^��0�ɃZ�b�g
			}
			else if(mode=='v'){ 	//���_���W�f�[�^
					part[part_num-1].v[vsum][0]=dt1;	//x���W
					part[part_num-1].v[vsum][1]=dt2;	//y���W
					part[part_num-1].v[vsum][2]=dt3;	//1
					vsum++;			//���͂������_�f�[�^�̐��̃J�E���g
			}
			else{
					printf("Can't discriminate the mode."); exit(0);
			}
	}
	vsum=0;
	for(n=0;n<part_num;n++) vsum+=part[n].Vn;
	//�ǂݍ��񂾕��i�̐��ƒ��_�����̏o��
	printf("loaded vertex data(part_num=%d vsum=%d)\n",part_num, vsum);
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

		int	i,k,n;			//�J�E���^
		char str[100];		//�V�~�����[�V�������ԂƃE�H�[�J�[�̈ʒu�\���p
		double x1, y1;		//���W�v�Z�p	
    glClearColor( 1, 1, 1, 1 );  		// �E�B���h�E�̔w�i�F�𔒂ɐݒ�
    glClear( GL_COLOR_BUFFER_BIT );		// �J���[�o�b�t�@���N���A�i�w�i�̓h��Ԃ��j
	draw_axis();	//���W�ƃO���b�h���̕`��

		//�E�H�[�J�[�̈ړ�
		if(move=='A'){ 						//���s�ړ��i���j
			x-=TX;
			if(x<xmin){
				move = 'D';
			}else{
				Tt[0][2]=-TX; Tt[1][2]=0.0;
				set_vertices(Tt, part);			
			}
		}
		else if(move=='D'){					//���s�ړ��i�E�j
			x+=TX;
			if(x>xmax){
				move = 'A';
			}else{
				Tt[0][2]=TX; Tt[1][2]=0.0;
				set_vertices(Tt, part);			
			}
		}
		else if(move=='W'){					//���s�ړ��i��j
			y+=TY;
			if(y>ymax){
				move = 'S';
			}else{
				Tt[0][2]=0.0; Tt[1][2]=+TY;
				set_vertices(Tt, part);	
			}
		}
		else if(move=='S'){					//���s�ړ��i���j
			y-=TY;
			if(y<ymin){
				move = 'W';
			}else{
				Tt[0][2]=0.0; Tt[1][2]=-TY;
				set_vertices(Tt, part);	
			}
		}
		else if (move=='Y'){ 				 //�΂߈ړ�(����)
			y+=TY;
			x-=TX;
			if(x<xmin){
				move = 'I';
			}else if(y>ymax){
				move = 'H';
			}else if(x>xmax && x<xmin){
				move = 'K';
			}else{
				Tt[0][2]=-TX; Tt[1][2]=+TY;
				set_vertices(Tt, part);	
			}
		}
		else if (move=='I'){				//�΂߈ړ�(�E��)
			y+=TY;
			x+=TX;
			if(x>xmax){
				move = 'Y';
			}else if(y>ymax){
				move = 'K';
			}else if(x>xmax && x>xmax){
				move = 'H';
			}else{
				Tt[0][2]=TX; Tt[1][2]=+TY;
				set_vertices(Tt, part);	
			}
		}
		else if (move=='H'){				//�΂߈ړ�(����)
			y-=TY;
			x-=TX;
			if(x<xmin){
				move = 'K';
			}else if(y<ymin){
				move = 'Y';
			}else if(x<xmin && y<ymin){
				move = 'I';
			}else{
				Tt[0][2]=-TX; Tt[1][2]=-TY;
				set_vertices(Tt, part);	
			}
		}
		else if (move=='K'){				//�΂߈ړ�(�E��)
			y-=TY;
			x+=TX;
			if( y<ymin ){
				move ='I';
			}else if( x>xmax ){
				move ='H';
			}else if( y<ymin && x>xmax ){
				move ='Y';
			}else{
				Tt[0][2]=TX; Tt[1][2]=-TY;
				set_vertices(Tt, part);	
			}
		}else if(move == 'F'){				//�ꎞ��~
		}else if(move=='Q'){				//�g��
			x*=1.1;	y*=1.1;
			Ts[0][0]=1.1; Ts[1][1]=1.1;
			set_vertices(Ts,part);
		}else if(move=='E'){				//�k��
			x*=0.9; y*=0.9;
			Ts[0][0]=0.9; Ts[1][1]=0.9;		
			set_vertices(Ts,part);
		}else if(move=='Z'){				//��]�^��
			x1 = Tr[0][0]*x + Tr[0][1]*y;
			y1 = Tr[1][0]*x + Tr[1][1]*y;
			x=x1; y=y1;
			set_vertices(Tr,part);
		}else	set_vertices(I, part);		//�ϊ���

		//�E�H�[�J�[�̕`��
		for(n=0;n<part_num;n++){
			glColor3d(part[n].color[0], part[n].color[1], part[n].color[2]);//�F�̐ݒ�
			glBegin( part[n].mode ); 		// �}�`�`��^�C�v�̐ݒ�J�n 		
				for(k=0;k<part[n].Vn;k++) glVertex2d( part[n].vt[k][0], part[n].vt[k][1] );
  		glEnd();  							// �}�`�`��^�C�v�̐ݒ�I��
		}

		//part[n].v(n=0, ..., part_num-1)�ɕϊ���̒��_���W��ݒ�
		for(n=0;n<part_num;n++){
			for(k=0;k<part[n].Vn;k++){
				for(i=0;i<3;i++) part[n].v[k][i]=part[n].vt[k][i];
			}
		}

		//�t�H�[�}�b�g�ɏ]���ĕ����z��str�Ɋi�[ 
		sprintf(str,"Simulation time = %d   Position=( %.1f , %.1f )", sim_time, x, y);

  	// ������str��(xmini+10, ymax-10)�̈ʒu�ɕ`�� 
		glColor3d(0, 0, 1.0);
		drawString2D(xmin+0.1, ymax-0.1, str ); 

		glutSwapBuffers();		//��ʂ̍X�V
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
			case 'j':	case 'J':	//�J�n�E���ԉ���
				glutTimerFunc(TIME_INTERVAL, timer, 0);//TIME_INTERVAL(�~���b)��ɃR�[���o�b�N�֐�timer�����s
				break;
			case 'g':	case 'G':	case '\033':  // '\033' �� ESC �� ASCII �R�[�h 
				exit(0);
			case 'w':	case 'W':	//���s�^���i��j
				move = 'W';
				break;
			case 's':	case 'S':	//���s�ړ��i���j
				move = 'S';
				break;
			case 'a':	case 'A':	//���s�ړ��i���j
				move = 'A';
				break;
			case 'd':	case 'D':	//���s�ړ��i�E�j
				move = 'D' ;
				break;
			case 'y':	case 'Y':	//�΂߈ړ��i����j
				move = 'Y';
				break;
			case 'i':	case 'I':	//�΂߈ړ��i�E��j
				move = 'I';
				break;
			case 'h':	case 'H':	//�΂߈ړ��i�����j
				move = 'H';
				break;
			case 'k':	case 'K':	//�΂߈ړ��i�E���j
				move = 'K';
				break;
			case 'f':	case 'F':	//�ꎞ�ړ���~
				move = 'F';
				break;
			case 'q':	case 'Q':	//�g��
				move = 'Q';
				break;
			case 'e':	case 'E':	//�k��
				move = 'E';
				break;
			case 'z':	case 'Z':	//��]�^��(���_�܂��)
				move = 'Z';
				break;
  		default:
    		break;
  	}
}
//--------------------------------------------------------------------------- 
// �^�C�}�[�R�[���o�b�N�֐�
//--------------------------------------------------------------------------- 
void timer(int value)
{	
	sim_time++;	//�V�~�����[�V�������ԁi�Ăяo���񐔁j�̃J�E���g

	glutPostRedisplay();//�f�B�X�v���C�R�[���o�b�N�̌Ăяo��

	//TIME_INTERVAL�i�~���b�j���timer�֐����Ăяo��
	glutTimerFunc(TIME_INTERVAL , timer , 0);		
}
//--------------------------------------------------------------------------- 
// ���C���֐�
//--------------------------------------------------------------------------- 
int main( int argc, char *argv[] ) {  

    glutInit(&argc, argv);						// GLUT���̏�����
	// �f�B�X�v���C���[�h�̐ݒ�(RGB �J���[/ �_�u���o�b�t�@�����O���g��)
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE );   
    glutInitWindowSize(WIDTH,HEIGHT); 			// �E�B���h�E�T�C�Y�̐ݒ�i�P�ʂ�pixel)
    glutInitWindowPosition(100,100);  			// �E�B���h�E�̈ʒu�i���j�^���ォ��(100,100)pixel�̈ʒu)
    glutCreateWindow(argv[0]); 					// �E�B���h�E�����i�E�B���h�E�̃^�C�g���ݒ�j

	init();										//initialization

    glutDisplayFunc(display);       			// �R�[���o�b�N�֐��̓o�^�i��ʕ\��)

	glutReshapeFunc(reshape);					//�E�B���h�E�T�C�Y�ύX��

    glutKeyboardFunc(keyboard); 				//�L�[�{�[�h�C�x���g�R�[���o�b�N�֐�

    glutMainLoop(); 							//�C�x���g�҂��̖������[�v

    return 0;
}

