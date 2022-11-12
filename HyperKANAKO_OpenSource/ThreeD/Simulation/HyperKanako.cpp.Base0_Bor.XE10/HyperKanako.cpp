//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

//---------------------------------------------------------------------------
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <tchar.h>

#pragma argsused


//#include "png.h"

using namespace std;

//#include "Iwa_Utility.h"
#include <windows.h>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
//#include <IniFiles.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <io.h>
#include <winsock.h>


using namespace std;

//---------------------------------------------------------------------------
typedef vector<string> VS;

VS split( string s, string c );

void logwrite(char *str,char *filename);

/* ������ "���N���������i���j���j 00:00:00" �Ƀt�H�[�}�b�g
		 ���� : buf...������̊i�[�ꏊ�Ast...�Q�Ƃ���tm�\���̂ւ̃|�C���^
		 �߂�l : �i�[����������ւ̃|�C���^        */
char *fmttm(char *buf);

//�����Ɏw�肳�ꂽ�f�B���N�g�������݂��邩�𒲂ׂ�֐��ł��B���j�R�[�h�t�@�C�����ɑΉ����Ă��܂��B
//bool __fastcall DirectoryExistsW(WideString WFilename);
bool __fastcall DirectoryExists(char *Filename);

//�t�H���_�쐬
bool FolderCreate(char *FileName);

//�t�H���_�폜
bool FolderDelete(char *FileName);

//�t�H���_�[���폜����
//��łȂ��ꍇ���폜
//bool DeleteDir(AnsiString Dir);
bool DeleteDir( LPCTSTR lpPathName );

//�R�Ԗڂ̈�����true�ɂ����ꍇ�A�R�s�[��̃t�@�C�������݂���ꍇCopyFile�͎��s���܂��B
//false���w�肵���ꍇ�͏㏑�����܂��B
bool FileCopy(char *src,char *dest);

string StringChangeFileExt(string filename,string ext);

char *GetIp(char *ip);

double string2double(const std::string& str);
std::string double2string(double d,long lpre);

void CreateProcessWait(string appl);

VS SearchFile(string sSearchFile);

/* �����񒆂̉p�啶�����������ɕϊ� */
char *StrToLower(char *s);
/* �����񒆂̉p��������啶���ɕϊ� */
char *StrToUpper(char *s);

/* �����񒆂̉p�啶�����������ɕϊ� */
string StrToLower(string s);
/* �����񒆂̉p��������啶���ɕϊ� */
string StrToUpper(string s);

//  �������u������
string StrReplace( string String1, string String2, string String3 );

//�t�@�C���̃T�C�Y���v�Z
long GetFileSize(string sFileName);

std::string trim(const std::string& string, const char* trimCharacterList = " \t\v\r\n");


























#pragma hdrstop

//!---------------------------------------------------------------------------
//!      wadako      ketugou moderu        shisakuhin     (2007/8/28)
//!---------------------------------------------------------------------------

double f_time;   // C++���傤�����̂��߁@time -> f_time �ɂւ񂱂�

double dxk;
double dx;
double dy;
double dt;
double rho;
double s;
double g;
double hlimk;
double hlim;
double hmin;
double csta;
double nm;
double deltae;
double deltad;
double pi;
double timemax;
double d;
double pai;
double hok;
double slmax;

double muki;
double hbar;
double zbar;
double cbar;
double hashi;
double b0;
double dx0;

//140514  1�����̂݌v�Z�����@��Q
bool bNiji = true;

double zssum;
double zsum;
double hsum;
double csum;
double usum;
double eetsum;

double qinkk;
double cinkk;
double qinkkall;
double cinkkall;
double qinkkout;
double cinkkout;
double qinkkallold;
double cinkkallold;
double hkmax;

int iend;
int jend;
int kend;
int jc;
int jr;
int hkmaxk;
//int mstep;
long long mstep;
int qinstep;
int qoutstep;
int qdatastep;
//int count;
//int count0;
int secstep;
int minstep;
int tminstep;
int nhaba;



//!-----------------------------ichijigen de tukaumono------------------------
//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
double *zk;
double *hk;
double *uk;
double *ck;
double *zsk;
double *zk0;
double *hk0;
double *uk0;
double *ck0;
double *zmotok;
double qink[200000]; //���ŏI�I�ɂ͓��I�ɃA���P�[�g
double qink1;
double cink[200000]; //���ŏI�I�ɂ͓��I�ɃA���P�[�g
double cink1; //?�Ȃ�������
double *bbk;
double *bmk;
double *uak;
double *thek;
double *eetk;
double *cmugk;
double *tanck;
double *sinck;
double *uck;
double *kanseik;

double *flxk; //'kanako07.9.16:wadako�ł�sub HHH�Ő錾flx�Ƃ��Đ錾����Ă� *double��OK�H
double *cflxk; //'kanako07.9.16:wadako�ł�sub CCC�Ő錾cflx�Ƃ��Đ錾����Ă�  *double��OK�H
//'2�����œ���������̂ŁAflxk()�Acflxk()�ɕύX�I

double *zorigk; //'07.9.22:kanako�ǉ�

// �����܂Ł@��1�����f�[�^������1�����z�����قǃA���P�[�g

//'!-----------------------nijigen de tukaumono--------------------------------
//'!�Q�����v�Z�Ŏg�p����ϐ�  ��2�����f�[�^������2�����z�����قǃA���P�[�g�@����(300,300)

double **z;
double **h;
double **u;
double **v;
double **c;
double **zs;
double **z0;
double **h0;
double **u0;
double **v0;
double **c0;

double **zmoto;

double **ua;
double **va;
double **uL;

double qin;
double qinh;
double qinv;
double qinvh;
double hin;
double cin_w;   // C++���傤�����̂��߁@cin -> cin_w �ɂւ񂱂�
double cinh;
double cinv;
double cinvh;

	 //�ȉ��܂Ō^�Ȃ��@double��OK�H
double **r1;

double **dzdn;

double **eet;
double **cmug;
double **tanc;
double **sinc;
double **uc;
double **kansei;

double **flx;
double **fly;
//�����܂�

int **id;

//�ȉ��܂Ō^�Ȃ��@double��OK�H
double **vr; //'kanako07.9.17�O���[�o���ϐ��Ƃ��Đ錾;�ȉ��̂��̑S��
double **cflx;
double **cfly;

double **vm_NIUUU; //'2010.6.11Nakatani�ǉ�
double **um_NIVVV; //'2010.6.11Nakatani�ǉ�
//�����܂�

//'kanako07.9.19�O���[�o���ϐ��Ƃ��Đ錾;
int mode; //0:���́i�ҋ@�j��,1:�v�Z��,2:�_�ړ���,3:���ʃt�@�C���ǂݍ���,4:���ʂ���`��o��
//'kanako1.__�V���[�Y�ł� mode �قȂ���
//' 0:�ҋ@���
//' 1:�n�`���͒�
//' 2:�_�ړ���
//' 5:�V�~�����[�V������


//Public Shared ichiji_dat(1000, 100, 10) As Single '090428test
double ***ichiji_dat; //'090428test
int ichiji_counter;

//'Public Shared niji_dat(999, 60, 60, 10) As Single'090403:�z�񐔕ύX
//    'Public Shared niji_dat(999, 100, 100, 10) As Single

//Public Shared niji_dat(1000, 200, 200, 10) As Single '090428test
double ****niji_dat; //090428test
//'Public Shared niji_dat(1000, 100, 100, 10) As Single '090428test
int niji_counter;



//Dim screensize_x = 775
//Dim screensize_y = 250
//'  Dim gradx = 20
//Dim gradx = 10 '0871�ύX

//Dim grady = 10
//'�n�`�f�[�^�̍��W��(0,0)�̂Ƃ��̉�ʏ�ł̃s�N�Z�����W�l
//Dim basex As Integer = 30
//Dim basey As Integer = 180 '08.2.4����250'08.2.5;200
//Dim hydrobasex As Integer = 20
//Dim hydrobasey As Integer = 640
//Dim xscale As Single = 2.5
//Dim yscale As Single = 3
//double tscale;
//double vscale;
//Dim width_base As Single = -30
//Dim taiseki_slide As Integer = 6

//Dim hyouji_dy As Single '07.9.25:�\���p��dy��ύX�Ady�͌v�Z�Ɏg�p
//Dim hyoji_dx As Single '07.10.23:�\���p��dx��ύX�Adx�͌v�Z�Ɏg�p


//Dim NiD_basex As Integer = 30 '08.2.5�ǉ�
//Dim NiD_basey As Integer = 325 '08.2.5�ǉ�


//Dim anime_taiseki(100, 100) As Single '���ʃt�@�C������̕`��p�u�͐ό��F�ϐ��v


int *flag1; //'�v�Z�t���O1����'07.10.17;hmin�Ŕ���ih��hmin�̂Ƃ�0,hmin��h�̂Ƃ�1 �j*1�����f�[�^�����z��A���P�[�g(100)
//'Dim flag2(300, 300) As Integer '�v�Z�t���O2����'090403�z�񐔕ύX
int **flag2; //'�v�Z�t���O2���� *2�����f�[�^�����z��A���P�[�g(100,100)
int **flag2_Ruiseki; // 20190212 Iwanami



//' Dim ni_energy; '07.10.17;�^���G�l���M�[ '090403�z�񐔕ύX
double **ni_energy; //'�v�Z�t���O2���� *2�����f�[�^�����z��A���P�[�g(100,100)


int kakunin; //'07.10.12


int moving; //'07.12.14-17

//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
int *inputflag_zorigk;
int *inputflag_bbk0;
int *inputflag_zsk;
//' Public Shared zorigk(300) As Single
double *bbk0;
double *zzs;
//�����܂�

double moveivent;

//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
double *tmp_zorigk; //'07.12.17 �ǉ��itmp_inputflag_zs�܂Łj
double *tmp_bbk0;
double *tmp_zsk;
int *tmp_inputflag_zorigk;
int *tmp_inputflag_bbk0;
int *tmp_inputflag_zsk;
//�����܂�

int detect_1D_i; //'07.12.17���l���͗p�p�����[�^

/*
		Public Shared dam_type() As Integer       ' 0:�s����  1:�X���b�g�@2:�i�q�^
		Public Shared dam_idam() As Integer
		Public Shared dam_nzd() As Single
		Public Shared dam_zd() As Single
		Public Shared dam_slit_width() As Single

		Public Shared ndam As Integer

		Public Shared cdam() As Single
		Public Shared hdam() As Single
*/
//���_���̌��ŃA���P�[�g
int *dam_type;   //' 0:�s����  1:�X���b�g�@2:�i�q�^
int *dam_idam;
double *dam_nzd;
double *dam_zd;
double *dam_slit_width;

int ndam;

double *cdam;
double *hdam;
//�����܂�

int dam_flag; //' dam_flag{0:�_������, 1:�_���L��}

int initial_dam_place, initial_out_place;


int dnum;

double inflow_time; // 'Form2�̕ϐ�
double peak_time;

// �����̓n�C�h���f�[�^�_����1�����z��A���P�[�g
double *qin0; //'�����y�Η��̗���
int *qin0_time; //'�����y�Η��̊�_�ƂȂ鎞��
double *chin0;

double chin0_1, chin0_2; //'�����y�Η��̓y���Z�x

int c_change_flag; //'0:�Z�x�ύX�����i���j,1:�Z�x�ύX����
int c_change_time; //'08728�ǉ��F�Z�x���ς�鎞��


double csin, t, chin, dtime;


int nout;
//�ϑ��_�̐�+1��1�����z��A���P�[�g
int *iout;

double hydroout_dt;

//    (timemax(�V�~�����[�g����(�b)) / hydroout_dt(�o�̓n�C�h���O���t�f�[�^�̏����o���Ԋu(�b)), nout(�ϑ��_�̐�) + 1,2)  ��3�����z��A���P�[�g
float ***hydroout_dat; // 190402 float�Ɋi����
int hydro_counter;

int hydro_flag;
double tm_w;     // C++���傤�����̂��߁@tm -> tm_w �ɂւ񂱂�

//�ϑ��_�̐�+1��1�����z��A���P�[�g
double *qsum;
double *qhsum;
double *qssum;
double *qsum0;
double *qhsum0;
double *qssum0;
double *q;
double *qh;
double *qs;
//�����܂�

double qqq;

//*1�����f�[�^�̌���1�����z��A���P�[�g(100)
double *chk;
double *csk;


//150216 ��Q�@�C��
double *pxk;
double *havk;
double *ustark;


double t0;
double time2D; //'08.1.15
int display_2Dmode; //'08.2.7�ǉ��i���ʐ}���ʕ\��0;���͉�ʂȂ̂Ŕ�\��,1;���[,2;�͐ό��j

//*2�����f�[�^�̌���2�����z��A���P�[�g(100,100)
double **tmp_z0; //'08.2.7�ǉ�
double **tmp_zs0;

int save_1ddata_flag; // '0:no,1:yes'081113�ǉ�
int save_1ddata_okcancel_flag; // '0:ok,1:cancel'081113�ǉ�

//'090422�ǉ�
double result_output_dt;
// 20130628�ǉ�
double rad_muki;  //20130613�C��:��������deg�̂܂�muki�������̂�radian�\���ɏC���I
double fai;  //20130507�ǉ�:���I�̓������C�p��ύX�ł���悤�C���i����܂�37�x���j


//�G�C�g����X�y�V����
double RyusyutuA;
double RyusyutuB;
double RyusyutuC;
double *bbksabun;

//�v�Z���[�h
int iCalcMode = 0; //Processing mode : 0=To the two dimensions 1=Only the one dimension
int iHydroOutput = 1; //Result Q output : 0=No 1=Yes


// �ȉ� 140202 ��Q�@�ǉ�
long landslide_dam_number;  //20131211�ǉ�:�V�R�_���ݒ�n�_�̐�
long *landslide_dam_position;  //20131211�ǉ�:�V�R�_���ݒ�n�_�̔ԍ�
double *landslide_dam_height;  //20131211�ǉ�:�V�R�_���̍���
double *landslide_dam_width;  //20131211�ǉ�:�V�R�_���̒J���i�ő�j
double sokugan_koubai; //20131211�ǉ�:���݌��z
double delta_se; //20131211�ǉ�:���ݐN�H�W��
double *sokugan_eetk; //20131217���ݐN�H���x�p�̃p�����[�^
int landslide_dam_flag; //' landslide_dam_flag{0:�_������, 1:�_���L��}
void f1_landslidedam_reconfig(int landslide_dam_number); //�@140202 �V�R�_���̌���1�����z��A���P�[�g(100) ��Q�@�ǉ�
void landslide_dam_position_keikoku(); // 20131211�ǉ�
void landslide_dam_position_reset();  //'20131211�ǉ� 140202 ��Q�@�ǉ�

//�ȏ�


//AnsiString file_version;
//AnsiString file_kind;
//AnsiString FPath_Base;
string file_version;
string file_kind;
string FPath_Base;
FILE *logout;
ofstream ichiji_fout;
ofstream niji_0_fout;
ofstream niji_1_fout;
ofstream niji_2_fout;
ofstream niji_3_fout;
ofstream niji_4_fout;
ofstream niji_5_fout;
//unsigned char **image;
int PixcelPerByte;
//int LookUp[256][3];
int errnum;
string errmsg;
int iMapDirection;
double dDummy;
double dHmax = 0.0;

char FolderName[FILENAME_MAX];
char DriveName[FILENAME_MAX];
char LogName[FILENAME_MAX];
char WorkBuff[FILENAME_MAX];
char Locale[FILENAME_MAX];

//�ȉ��֐��錾
int InitialSetting();
int setup_data(char *FPath);
string effective_line(string aContent,char * FPath,string sDef = "");
string effective_line2(string aContent,std::ifstream &ifs);
void setup_data_2_1D(char * FPath);
void split(vector<string>& v, char separator, const string& s);
void init1ji(int kend);
void delete1ji();
void f1_dam_reconfig(int ndam); //'07.7.30:Max��iend�œ�����H
void delete_dam(); //'07.7.30:Max��iend�œ�����H
void sokuteiten_reconfig(int num); //'Public Shared�ɕύX
void delete_sokuteiten();
void inputhydro_reconfig(int num); //'Public Shared�ɕύX
void delete_inputhydro();
void outputhydro_reconfig(int num1, int num2); //'Public Shared�ɕύX
void delete_outputhydro(int num1, int num2);
void setup_wadakanako();
void init_simulation_1D();
void initial_1D();
void NIinitial(); //'(hmin,iend,jend)
void init2ji(int iend,int jend);
void delete2ji(int iend);
void init_niji_dat(int num1, int num2);
void delete_niji_dat(int num1, int num2);
void init_ichiji_dat(int num);
void delete_ichiji_dat(int num);
void Simulation();
//void save_result();
void kansokuten_position_keikoku();
void dam_position_keikoku();
void dam_position_reset();
void observation_position_reset();
void dam_position_keikoku2();

void width_keikoku(); //140409 �ǉ��@��Q
void landslide_dam_width_keikoku(); //20140606 �ǉ� ��Q

//void save_result();
void form1_hyouji_keisan_2D1D();
void setup_keisan_wadakanako();
void keisan_NIinitial();
void Replacement_Timer1_Tick();
void ichijigen();
void result_file_open();
void result_file_close();
void save_result_each_time(double ftime);
void save_result_debug_niji(double **niji);
void errlogout();

//�ȉ��f�o�b�O���[�`��
void Debug_Memory();
void Debug_2ji_data();
void Debug_1ji_data();
void Debug_Default_data();

VS split( string s, string c );
void logwrite(char *str,char *filename);
char *fmttm(char *buf);
string ChangeFileExt(string filename,string ext);
bool FileCopy(char *src,char *dest);


void save_result_Q();


//#define	PIXCELPERBYTE (3) //RGB
#define	PIXCELPERBYTE (4) //RGBA
#define NONCALC -9999.9

int main(int argc, char* argv[])
{
	int iRet;
	LONGLONG t1,t2,fr;
	char buff[FILENAME_MAX];

//	strcpy(FolderName,argv[2]);
//	strcpy(DriveName,argv[3]);
	strcpy(FolderName,argv[1]);
	strcpy(DriveName,argv[2]);

//	sprintf(LogName,"%sThreeD\\Simulation\\%s\\log.txt",DriveName,FolderName);
	sprintf(LogName,"%s\\log.txt",FolderName);

	FPath_Base = FolderName;
//	FPath_Base = FPath_Base + "\\";
//	FPath_Base = FPath_Base + argv[1];
	FPath_Base = FPath_Base + "\\result";


//	ifstream ifsLu("SimulationColorTable.txt");
//	for (int i=0; i < 256; i++)
//	{
//		ifsLu >> LookUp[i][0];
//		ifsLu >> LookUp[i][1];
//		ifsLu >> LookUp[i][2];
//	}
//	ifsLu.close();

	QueryPerformanceFrequency((LARGE_INTEGER *)&fr);
	QueryPerformanceCounter((LARGE_INTEGER *)&t1);

	iRet = InitialSetting();
	if(iRet == -9000)
	{
		errnum = iRet;
		errmsg = "defaultwk.dat�̃o�[�W�������Ⴂ�܂��B";
		sprintf(buff,"%d : %s",iRet,errmsg);
		logwrite(buff,LogName);
		//errlogout();
		goto JUMPEND;
	}

	mode = 0;    //120711�ǉ�

	Simulation();

	printf("Calclation Finish.\n");

	result_file_close();

	printf("Simulation Complete.\n");


	delete1ji();
	delete_dam();
	delete_sokuteiten();
	delete_inputhydro();

	if(iHydroOutput == 1)
	{
		delete_outputhydro(timemax / hydroout_dt, nout + 1);
	}

	delete2ji(iend);

	kakunin = 0; //'07.10.12;
	mode = 0;

	QueryPerformanceCounter((LARGE_INTEGER *)&t2);

	sprintf(buff,"%lf sec\n", (double)((t2-t1) / fr));
	logwrite(buff,LogName);

JUMPEND:

	return(kakunin*10 + mode);
}

void Simulation()
{
	int i, j;

	if(mode == 0) //'081113�ǉ�
	{
		//140408 �S�_�o�͂̂��߃_���ʒu�͊ϑ��_���珜��
						//'08827�ǉ�
//		for(i = 0;i < ndam;i++)  //Base0 ����
//		{
//			for(j = 0;j < nout;j++)  //Base0 ����
//			{
//				if(dam_idam[i] == iout[j])
//				{
//					kansokuten_position_keikoku();
//					return; //Exit Sub
//				}
//			}
//		}
		for(i = 0;i < ndam;i++)  //Base0 ����
		{
			iout[dam_idam[i]] = -1;
		}

		for(i = 0;i < landslide_dam_number;i++)  //Base0 ����
		{
			iout[landslide_dam_position[i]] = -2;
		}


		//20131211�ǉ��F���h�_���ƓV�R�_���𓯂��_�ɒu���Ȃ��悤��  140202 ��Q�@�ǉ�
		for(i = 0;i < ndam;i++)  //Base0 ����
		{
			for(j = 0;j < landslide_dam_number;j++)  //Base0 ����
			{
				if(dam_idam[i] == landslide_dam_position[j])
				{
					landslide_dam_position_keikoku();
					return; //Exit Sub
				}
			}
		}
		//20131211�ǉ�

		//'0893:�_����kend-1�ɂ͒u���Ȃ��悤�ɁI

		//20140409�ǉ� ��Q  Base 0 ����
		for(i = 0;i < kend;i++)
		{
			if(bbk0[i] <= 0)
			{
				width_keikoku();
				return;
			}

//				'20140606�V�R�_���݂������͍ő�ŒJ���i�J�����傫���Ƃ��͌x�����o���j
//				If landslide_dam_number <> 0 Then
//					For j = 1 To landslide_dam_number
//						If (i = landslide_dam_position(j)) And (bbk0(i) > landslide_dam_width(j)) Then
//							Call landslide_dam_width_keikoku()
//							Exit Sub
//						End If
//					Next
//				End If
//				'20140606�ǉ������܂�
			//20140606�V�R�_���݂������͍ő�ŒJ���i�J�����傫���Ƃ��͌x�����o���j
			if(landslide_dam_number > 0)
			{
				//140823 �o�O�����@J = 0��j == 0�ɂȂ��Ă����B
				for(j = 0;j < landslide_dam_number;j++)
				{
					if((i == landslide_dam_position[j]) && (bbk0[i] > landslide_dam_width[j]))
					{
						landslide_dam_width_keikoku();
						return;
					}
				}
			}
			//20140606�ǉ������܂�
		}
		//20140409�ǉ������܂�


		for(i = 0;i < ndam;i++)  //Base0 ����
		{
			//if(dam_idam[i] >= kend - 1) //Base0 ����
			if(dam_idam[i] >= kend - 2) //Base0 ����
			{
				dam_position_keikoku2();
				return; //Exit Sub
			}
		}

		//140408 �S�_�o�͂̂��ߏ����ɕ���ł���
		//'08929�ǉ�
		//'�ϑ��_��ԍ����ɏ㗬������ёւ�
//		if(nout > 0)
//		{
//			observation_position_reset();
//		}

		//'�_����ԍ����ɏ㗬������ёւ�
		if(ndam > 0)
		{
			dam_position_reset();
		}
		//'08929�ǉ������܂�
		//'08827�ǉ������܂�

		//'�V�R�_����ԍ����ɏ㗬������ёւ�:20131211�ǉ� 140202 ��Q�@�ǉ�
		if(landslide_dam_number > 0)
		{
			landslide_dam_position_reset();
		}
		//':20131211�ǉ������܂�

		//''''If mode = 0 Then '081113�ǉ�

		form1_hyouji_keisan_2D1D();

	} //'081113�ǉ������܂�

/*
				'2�����̌v�Z���[�v����̃^�C���X�e�b�v�I����Ɍv�Z��~�B������Ǝ��Ԃ�����B07.9.21
				If mode = 1 Then
						''Timer1.Enabled = False
						mode = 0
						Button1.Text = "Start"

						''form_instance_8.mode_2D = 0

						''form_instance_8.Visible = False '08.6.4:Close��Ɖ������������I

						display_2Dmode = 0 '08.2.7�ǉ�

						'081113�ǉ�:2D�̏����͏��i�ړ���z�j���L�������Ă���
						For i = 1 To iend
								For j = 1 To jend

										z(i, j) = zmoto(i, j)
								Next
						Next
						'081113�ǉ�



						Call setup_keisan_wadakanako() '08.2.7�G������ɂ��Ȃ���2�����n�`�����Z�b�g����Ă��܂�

						Exit Sub

				End If
*/

//	mstep = 7200000;
	mstep = 0;
	f_time = 0;

	setup_keisan_wadakanako(); //'07.12.17�ǉ�'08.1.16�ύX

	mode = 1;

	////while(mode == 1)
	////{
	////	Replacement_Timer1_Tick();
	////}
	Replacement_Timer1_Tick();

	if(iHydroOutput == 1)
	{
		save_result_Q();
	}


	return;
}

void setup_keisan_wadakanako() // '08.1.16�ǉ�
{
	qinkkall = 0;
	cinkkall = 0;
	qinkkout = 0;
	cinkkout = 0;
	qinkkallold = 0;
	cinkkallold = 0;


	init_simulation_1D();

	initial_1D();

	keisan_NIinitial(); //'(hmin,iend,jend)

	//'!------------------haba jouken------------------------
	//'!�P�����͓����̕␳
// 130628 �C��
//	b0 = bmk[kend - 2] / cos(muki); //Base0 ����
//	dx0 = dx * cos(muki);
	b0 = bmk[kend - 2] / cos(rad_muki); //20130507�C��:muki��rad_muki��
	dx0 = dx * cos(rad_muki); //20130507�C��:muki��rad_muki��

	//nhaba = 2 * Int(b0 / (2.0 * dy) + 0.5) + 1;
	nhaba = 2 * int(b0 / (2.0 * dy) + 0.5) + 1;
	hashi = (b0 - dy * double(nhaba - 2)) / 2.0; //'07.9.16:double��CDbl�ɑΉ��I
	if(b0 <= dy)
	{
		hashi = 0.0;
	}

	return;
}


//'08.1.16:�ݒ肵��2�����n�`�����Z�b�g�����̂�h��
void keisan_NIinitial() //'(hmin,iend,jend)
{
	int i,j;

	//'!--------------------initial value---------------------
	for(i = 0;i < iend;i++) //Base0 ����
	{
		for(j = 0;j < jend;j++) //Base0 ����
		{
			h[i][j] = hmin;
			u[i][j] = 0;
			v[i][j] = 0;
			c[i][j] = 0;

			flag2[i][j] = 0; //'07.10.17�ǉ��F�v�Z�t���O

			//'081113:���Z�b�g�����Ă����I�I�I�I�I
			ua[i][j] = 0;
			va[i][j] = 0;
			uL[i][j] = 0;
			r1[i][j] = 0;

			dzdn[i][j] = 0;

			eet[i][j] = 0;
			cmug[i][j] = 0;
			tanc[i][j] = 0;
			sinc[i][j] = 0;
			uc[i][j] = 0;
			kansei[i][j] = 0;

			flx[i][j] = 0;
			fly[i][j] = 0;

			vr[i][j] = 0;
			cflx[i][j] = 0;
			cfly[i][j] = 0;
			//'081113:���Z�b�g�����Ă����I�I�I�I�I�����܂ŏC��

			zmoto[i][j] = z[i][j]; //'081112�R�����g

		}
	}

	return;
}

void form1_hyouji_keisan_2D1D() //'08.2.8;1D��2D�����̂��߂ɒǉ�'081113:1D�����[����2D�㗬�[���̕␳�p�ɒǉ��I�I�I
{

	double hosei_zorigk_kend, hosei_zsk_kend; // '081113:kend�͏��̕␳�l�p�����[�^
	double tmp_zorigk_kend, tmp_zsk_kend; // '081113:kend�͏��̊i�[�p�����[�^

	double zbar2, zsbar2;

	tmp_zorigk_kend = zorigk[kend -1 ]; //Base0 ����
	tmp_zsk_kend = zsk[kend - 2]; //Base0 ����


	//'!------------------jouken 2---------------------------
	//'!�Q�����͏��̂P�����ւ̊Ҍ�

	zbar2 = 0;
	zsbar2 = 0;

	int j;

	if(nhaba >= 3)
	{
		//for(j = (jc - (nhaba - 3) / 2);j <= (jc + (nhaba - 3) / 2);j++) //Base0 ����
		for(j = (jc - (nhaba - 3) / 2) - 1;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
		{
			zbar2 = zbar2 + z[1][j] * dy / b0; //Base0 ����
			zsbar2 = zsbar2 + zs[1][j] * dy / b0; //Base0 ����
		}

		zbar2 = zbar2 + z[1][jc - (nhaba - 1) / 2 - 1] * hashi / b0; //Base0 ����
		zbar2 = zbar2 + z[1][jc - (nhaba - 1) / 2 - 1] * hashi / b0; //Base0 ����

		zsbar2 = zsbar2 + zs[1][jc - (nhaba - 1) / 2 - 1] * hashi / b0; //Base0 ����
		zsbar2 = zsbar2 + zs[1][jc - (nhaba - 1) / 2 - 1] * hashi / b0; //Base0 ����
	}
	else
	{
		zbar2 = z[1][jc - 1]; //Base0 ����
		zsbar2 = zs[1][jc - 1]; //Base0 ����
	}

	hosei_zorigk_kend = ((dx0 - dxk) * zorigk[kend - 2] + 2.0 * dxk * zbar2) / (dxk + dx0);  //Base0 ����
	hosei_zsk_kend = ((dx0 - dxk) * zsk[kend - 2] + 2.0 * dxk * zbar2) / (dxk + dx0);  //Base0 ����

/*
	If save_1ddata_flag = 1 Then '081113�͏��ۑ���


			If (tmp_zorigk_kend <> hosei_zorigk_kend) And (tmp_zsk_kend <> hosei_zsk_kend) Then

		'081116�R�����g2�s�AMsgbox�Ȃ�
		'  Dim response As MsgBoxResult = MsgBox("�ꎟ���͏��̍ŉ����[���̕W�����A�������f���ɓK���Ă��܂���I" + vbCrLf + vbCrLf + "�������f���ɓK����W���֎����C��������A1D�͏��f�[�^��ۑ����܂��B", MsgBoxStyle.OKCancel)


		' If response = MsgBoxResult.OK Then

		zorigk(kend) = hosei_zorigk_kend
		zsk(kend) = hosei_zsk_kend


		'081116�R�����g4�s�AMsgbox�Ȃ�
		'Else
		'    save_1ddata_okcancel_flag = 1
		'    Exit Sub

		'End If

			Else
		Exit Sub

			End If

	Else '081113�v�Z�J�n��
*/
	if((tmp_zorigk_kend != hosei_zorigk_kend) && (tmp_zsk_kend != hosei_zsk_kend))
	{
		zorigk[kend - 1] = hosei_zorigk_kend; //Base0 ����
		zsk[kend - 1] = hosei_zsk_kend; //Base0 ����
	}
	else
	{
		return; //	Exit Sub
	}

	//End If

	return;
}

int InitialSetting() // '08.1.7�ǉ�
{
	mode = 0;


//	sprintf(WorkBuff,"%sThreeD\\Simulation\\%s\\defaultwk_%s.dat",DriveName,FolderName, Locale);
//	sprintf(WorkBuff,"%sThreeD\\Simulation\\%s\\defaultwk.dat",DriveName,FolderName);
	sprintf(WorkBuff,"%s\\defaultwk.dat",FolderName);
	mode = setup_data(WorkBuff);
	if(mode < 0)
	{
		goto JUMPEND;
	}

	result_file_open();

	hydro_flag = 1;

	setup_wadakanako();

	//init_niji_dat(iend,jend);
	//init_ichiji_dat(kend);

//#ifdef _DEBUG_IWA1
	//Debug_Memory();
	//Debug_2ji_data();
	//Debug_1ji_data();
	//Debug_Default_data();
//#endif


JUMPEND:

	return(mode);
}

void setup_wadakanako()
{
	qinkkall = 0;
	cinkkall = 0;
	qinkkout = 0;
	cinkkout = 0;
	qinkkallold = 0;
	cinkkallold = 0;

	init_simulation_1D();

	initial_1D();

	init2ji(iend,jend);
	NIinitial(); //'(hmin,iend,jend)

	//'!------------------haba jouken------------------------
	//'!�P�����͓����̕␳
// 130628 �C��
//	b0 = bmk[kend - 2] / cos(muki);
//	dx0 = dx * cos(muki);
	b0 = bmk[kend - 2] / cos(rad_muki); //20130507�C��:muki��rad_muki��
	dx0 = dx * cos(rad_muki); //20130507�C��:muki��rad_muki��

	//nhaba = 2 * Int(b0 / (2.0 * dy) + 0.5) + 1;
	nhaba = 2 * int(b0 / (2.0 * dy) + 0.5) + 1;
	hashi = (b0 - dy * double(nhaba - 2)) / 2.0; //'07.9.16:double��CDbl�ɑΉ��I
	if(b0 <= dy)
	{
		hashi = 0.0;
	}

	return;
}

int setup_data(char *FPath)
{
	int iRet = 1;

	file_version = effective_line(";Version",FPath);
	file_kind = effective_line(";file_kind(1;parameters and 1D data,2;2D data)",FPath);

//	if((file_version == "2.03") || (file_version == "2.031")) //   '090422:Ver2.03�݂̂ɁI  '2010.6.11Nakatani
	if((file_version == "2.06")) //  '1�����͏��̕ۑ��p''20131211Version�ύX
	{
		if(file_kind == "1")
		{
			setup_data_2_1D(FPath);
		}
		else
		{
			//MsgBox("�ǂݍ��񂾃t�@�C���o�[�W�������قȂ�܂��I")
			iRet = -9001;
			goto JUMPEND;
		}
	}
	else
	{
		//MsgBox("�ǂݍ��񂾃t�@�C���o�[�W�������قȂ�܂��I")
		iRet = -9000;
		goto JUMPEND;
	}

JUMPEND:
//	ifs.close();

	return(iRet);
}


//AnsiString effective_line(AnsiString aContent,std::ifstream &ifs,int mode)
//{
//	char str[FILENAME_MAX];
//	AnsiString aRet;
//
//	errnum = -9100;
//	errmsg = "\"" + aContent + "\"" + " ��������܂���B";
//
//	ifs.seekg(0, ios::beg);
//	while(!ifs.eof())
//	{
//			ifs.getline(str,sizeof(str));
//			aRet = str;
//			if(aRet == aContent)
//			{
//				if(mode == 1)
//				{
//					ifs.getline(str,sizeof(str));
//				}
//				aRet = str;
//
//				errmsg = "";
//				errnum = 0;
//				break;
//			}
//	}
//
//	if(errnum < 0)
//	{
//		logwrite("",LogName);
//		//errlogout();
//		exit(-1);
//	}
//
//	return(aRet);
//}

string effective_line(string aContent,char * FPath,string sDef)
{
	char str[FILENAME_MAX];
	string aRet = sDef;
	string wStr;

	errnum = -9100;
	errmsg = "\"" + aContent + "\"" + " is not found.";

	std::ifstream ifs( FPath );

	while(!ifs.eof())
	{
		ifs.getline(str,sizeof(str));
		wStr = str;
		if(wStr == aContent)
		{
			ifs.getline(str,sizeof(str));
			aRet = str;

			errmsg = "";
			errnum = 0;
			break;
		}
	}

	ifs.close();

//	if((errnum < 0) && (aRet == ""))
	if(errnum < 0)
	{
		logwrite("",LogName);
		//errlogout();
		exit(-1);
	}

	return(aRet);
}

string effective_line2(string aContent,std::ifstream &ifs)
{
	char str[FILENAME_MAX];
	string aRet = "";
	string wStr;

	errnum = -9100;
	errmsg = "\"" + aContent + "\"" + " is not found.";

	while(!ifs.eof())
	{
		ifs.getline(str,sizeof(str));
		wStr = str;
		if(wStr == aContent)
		{
			aRet = str;

			errmsg = "";
			errnum = 0;
			break;
		}
	}

//	if((errnum < 0) && (aRet == ""))
	if(errnum < 0)
	{
		logwrite("",LogName);
		//errlogout();
		exit(-1);
	}

	return(aRet);
}

void setup_data_2_1D(char *FPath)
{
	double dqt,dq,dc;
	errnum = 0;

	// 120801�ǉ��E�C��
	dt = atof(effective_line(";Time interval of calculation(sec)",FPath,"0.01").c_str());
	s = atof(effective_line(";Mass density of sediment(kg/m^3) MKS",FPath,"2650").c_str());
	rho = atof(effective_line(";Mass density of fluide phase[water and mud,silt](kg/m^3) MKS",FPath,"1000").c_str());
	g = atof(effective_line(";Gravity acceleration(m/s^2)",FPath,"9.8").c_str());
	hmin = atof(effective_line(";Minimum flow depth(m)",FPath,"0.01").c_str());
	csta = atof(effective_line(";Concentration of movable bed",FPath,"0.65").c_str());
	nm = atof(effective_line(";Manning's roughness coefficient",FPath,"0.03").c_str());
	deltae = atof(effective_line(";Coefficient of erosion velocity",FPath,"0.0007").c_str());
	deltad = atof(effective_line(";Coefficient of deposition velocity",FPath,"0.05").c_str());
	pi = atof(effective_line(";Coefficient of deposition velocity considering inertial force",FPath,"0.9").c_str());
	timemax = atol(effective_line(";Simulation continuance time(sec)",FPath,"1800").c_str());
	d = atof(effective_line(";Diameter of material(m)",FPath,"0.2").c_str());
	pai = atof(effective_line(";pai",FPath,"3.14159265358").c_str());

//130628�ǉ�
//        fai = Val(effective_line(handle)) '20130507:���̓������C�p��ݒ�ł���悤�ǉ�
	fai = atof(effective_line(";Internal friction angle(deg)",FPath,"37").c_str());
	hydroout_dt = atol(effective_line(";Time interval of output hydrograph data(sec)",FPath,"4").c_str()); //07.12.26�ǉ�
	result_output_dt = atol(effective_line(";Time interval of output result data(sec)",FPath,"10").c_str()); //090422�ǉ�
	muki = atol(effective_line(";Parameter using in 2D area; inflow direction[muki](deg)",FPath,"0").c_str());

	//temporary measures
	jc = atol(effective_line(";inflow center X axis in 2D area[jc]",FPath).c_str());
	jr = atol(effective_line(";inflow center Y axis in 2D area[jr]",FPath).c_str());
	if(jc == 0)
	{
		jc = jr;
	}

	dx = atof(effective_line(";Interval of 2D-x calculation points(m)",FPath).c_str());
	dy = atof(effective_line(";Interval of 2D-y calculation points(m)",FPath).c_str());
	hlim = atof(effective_line(";Minimum depth at the front of debris flow in 2D(m)",FPath,"0.01").c_str());
	iend = atol(effective_line(";Number of calculation points in 2D-x direction",FPath).c_str());
	jend = atol(effective_line(";Number of calculation points in 2D-y direction",FPath).c_str());
	delta_se = atof(effective_line(";Side Bank Erosion Velocity",FPath,"1.00").c_str());  //20131211�ǉ�
	sokugan_koubai = atof(effective_line(";Side Bank Gradient(deg)",FPath,"37.00").c_str());  //20131211�ǉ�

	//�͏��`��f�[�^
	kend = atol(effective_line(";Number of calculation points in 1D",FPath).c_str());
	dxk = atol(effective_line(";Interval of calculation points in 1D(m)",FPath).c_str());
	hlimk = atof(effective_line(";Minimum depth at the front of debris flow in 1D(m)",FPath,"0.05").c_str());

	//�G�C�g����X�y�V����
	RyusyutuA = atof(effective_line(";Outflow Coefficient(a)",FPath,"1425.0").c_str());
	RyusyutuB = atof(effective_line(";Outflow Coefficient(b)",FPath,"-1000000.0").c_str());
	RyusyutuC = atof(effective_line(";Outflow Coefficient(c)",FPath,"400000000.0").c_str());

	//�v�Z���[�h
	iCalcMode = atol(effective_line(";Processing mode : 0=To the two dimensions 1=Only the one dimension",FPath,"0").c_str());
	iHydroOutput = atol(effective_line(";Result Q output : 0=No 1=Yes",FPath,"1").c_str());

	init1ji(kend);

	vector<string> strVector;
	std::ifstream ifs( FPath );
	effective_line2(";River shape(fixed bed,movable bed,river width,fixed bed input flag,movable bed input flag,river width input flag)",ifs);

	int i;
	char tmpline[FILENAME_MAX];

	for(i = 0;i < kend;i++) //Base0 ����
	{
		ifs.getline( tmpline, sizeof(tmpline));
		split(strVector, ',',tmpline); //'08.6.5�t�@�C���ǂݍ��݋L�q��ύX�F��������I

		zsk[i] = atof(strVector[0].c_str());
		zorigk[i] = atof(strVector[1].c_str());
		bbk0[i] = atof(strVector[2].c_str());
		inputflag_zsk[i] = atoi(strVector[3].c_str());
		inputflag_zorigk[i] =  atoi(strVector[4].c_str());
		inputflag_bbk0[i] = atoi(strVector[5].c_str());
	}

	ifs.close();

	dam_flag = atol(effective_line(";Existance of dam[0:No 1:Yes]",FPath,"0").c_str());

	if(dam_flag == 0)
	{
		ndam = 0;
	}
	else
	{
		ndam = atof(effective_line(";Numbers of sabo dam",FPath).c_str());

		f1_dam_reconfig(ndam); //'07.7.30:Max��iend�œ�����H

		std::ifstream ifs( FPath );
		effective_line2(";Dam parameters(type[0:closed type,1:slit type,2:grid type],installation,height,slit width,griddam input flag[0;deafault,1:edited])",ifs);

		for(i = 0;i < ndam;i++) //Base0 ����
		{
			ifs.getline( tmpline, sizeof(tmpline));
			split(strVector, ',',tmpline); //'08.6.5�t�@�C���ǂݍ��݋L�q��ύX�F��������I
			//tmpline = Split(effective_line(handle), ",", -1, CompareMethod.Binary)
			dam_type[i] = atoi(strVector[0].c_str());
			dam_idam[i] = atoi(strVector[1].c_str()) - 1;  //140203 Base0�̂��߁@-1�@��Q�C��;
			dam_nzd[i] = atof(strVector[2].c_str());
			dam_slit_width[i] = atof(strVector[3].c_str());
		}
		ifs.close();

		//  For���[�v��Sub�̍Ō�ցFzhd(1)�͌ォ��ǂݍ��ނ̂�
		for(i = 0;i < ndam;i++) //Base0 ����
		{
			if(dam_type[i] != 2)
			{
				dam_zd[i] = (zsk[dam_idam[i]] + zsk[dam_idam[i] + 1]) * 0.5 + dam_nzd[i];
			}
			//									'Else
			//						'    dam_zd(i) = (zsk(dam_idam(i)) + zsk(dam_idam(i) + 1)) * 0.5 + zhd(1)
		}
	}

	//140408 �Ƃ肠�����@�ϑ��_���㗬�[�m�[�h�Ȃ��đS�_�o��
//	sWork = ";�ϑ��_�̐�";
//	nout = atol(effective_line(sWork,FPath,1).c_str());
	nout = kend - 1;
	sokuteiten_reconfig(nout + 1);


	long lend1;
	if((long)timemax % (long)result_output_dt == 0)
	{
		lend1 = long(timemax / result_output_dt);
		lend1 = lend1 * result_output_dt;
	}
	else
	{
		lend1 = long(timemax / result_output_dt) + 1;
		lend1 = lend1 * result_output_dt;
	}

	if(iHydroOutput == 1)
	{
		//outputhydro_reconfig(timemax / hydroout_dt, nout + 1);  //'06.2.10�����n�C�h�������[�ɒǉ�(nout��nout+1�j��
		outputhydro_reconfig(lend1 / hydroout_dt, nout + 1);  //'06.2.10�����n�C�h�������[�ɒǉ�(nout��nout+1�j��
	}

	//140408 �Ƃ肠�����@�ϑ��_���㗬�[�m�[�h�Ȃ��đS�_�o��
//	sWork = ";�ϑ��_�̃p�����[�^(�ʒu)";
//	effective_line(sWork,FPath,0);
//	for(i = 1;i <= nout;i++) //Base0 ����
//	{
//		FPath.getline( tmpline, sizeof(tmpline));
//		iout[i] = atoi(tmpline);
//	}

	for(i = 1;i <= nout;i++) //Base0 ����
	{
		iout[i] = i;
	}

	//�@140202 �ȉ��V�R�_���Ή��@��Q�@�ǉ�
	landslide_dam_number = atol(effective_line(";The number of landslide dams",FPath,"0").c_str());

	if(landslide_dam_number > 0)
	{
		landslide_dam_flag = 1;

		f1_landslidedam_reconfig(landslide_dam_number);

		std::ifstream ifs( FPath );
		effective_line2(";Specifications of landslide dam(Location, Height, Width)",ifs);

		for(i = 0;i < landslide_dam_number;i++) //Base0 ����
		{
			ifs.getline( tmpline, sizeof(tmpline));
			split(strVector, ',',tmpline); //'08.6.5�t�@�C���ǂݍ��݋L�q��ύX�F��������I
			landslide_dam_position[i] = atol(strVector[0].c_str()) - 1;  //140203 Base0�̂��߁@-1�@��Q�C��
			landslide_dam_height[i] = atof(strVector[1].c_str());
			landslide_dam_width[i] = atof(strVector[2].c_str());
		}
		ifs.close();
	}
	else
	{
		landslide_dam_flag = 0;
	}

	// 140202 zorigk zsk�̔z��Base0�v�m�F
	for(i = 0;i < landslide_dam_number;i++)
	{
		if((zorigk[landslide_dam_position[i]] - zsk[landslide_dam_position[i]]) != landslide_dam_height[i]) //'�����獂�����ݒ肳��Ă����炻�̂܂�
		{
			zorigk[landslide_dam_position[i]] = zsk[landslide_dam_position[i]] + landslide_dam_height[i];
		}
	}
	//�ȏ�



















	dnum = 	atoi(effective_line(";Numbers of value point in hydrograph setting",FPath).c_str());
	inputhydro_reconfig(dnum);

//140408 �ȉ�����Ȃ��@��Q
//	sWork = ";�y���Z�x�̕ύX�̗L���i0;�����C1�F�L��j";
//	c_change_flag = atoi(effective_line(sWork,FPath,1).c_str()); //'08728�ύX��������
//
//	if(c_change_flag == 1)
//	{
//		sWork = ";�y���Z�x�̕ύX����[�ύX�L��̏ꍇ�̂�]�i�b�j";
//		c_change_time = atoi(effective_line(sWork,FPath,1).c_str());
//	}
//
//	sWork = ";�y���Z�x";
//	chin0_1 = atof(effective_line(sWork,FPath,1).c_str());
//
//
//	if(c_change_flag == 1)
//	{
//		sWork = ";�Z�x�ύX��̑嗱�a�Z�x��";
//		chin0_2 = atof(effective_line(sWork,FPath,1).c_str());
//	}

				//'08728�ύX�����܂�
				//'08730�����܂�
	ifs.open( FPath );
	effective_line2(";time(second), discharge(m^3/s), Concentration",ifs);
	for(i = 0;i < dnum;i++) //Base0 ����
	{
		ifs.getline( tmpline, sizeof(tmpline));
		//split(strVector, ',',tmpline);
		sscanf(tmpline,"%lf %lf %lf",&dqt,&dq,&dc);

		qin0_time[i] = atoi(strVector[0].c_str());
		qin0[i] = atof(strVector[1].c_str());

		qin0_time[i] = dqt;
		qin0[i] = dq;
		chin0[i] = dc;

	}
	ifs.close();

	qink[0] = 0; ////Base0 ���� //'08.1.7�ǉ��F�����n�C�h����0�b����0�ŌŒ�I
				//'cink(1) = 0

				//'08.6.5�t�@�C���ǂݍ��݋L�q��ύX�F�����܂ŁI

//#ifdef _DEBUG_IWA1
	//Debug_Default_data();
	//Debug_1ji_data();

//#endif

	return;
}

void split(vector<string>& v, char separator, const string& s)
{
		int i = 0, j = s.find_first_of(separator);

		v.clear();
		while(j != -1)
		{
				v.push_back(s.substr(i, j - i));
				i = j + 1;
				j = s.find_first_of(separator, i);
		}
		v.push_back(s.substr(i, -1));
}

//*1�����f�[�^�̌���1�����z��A���P�[�g(100)
void init1ji(int kend)
{
	//Base0 ����

	//int wKend;

	//wKend = kend + 1;

	chk = new double[kend];
	csk = new double[kend];
	zk = new double[kend];
	hk = new double[kend];
	uk = new double[kend];
	ck = new double[kend];
	zsk = new double[kend];
	zk0 = new double[kend];
	hk0 = new double[kend];
	uk0 = new double[kend];
	ck0 = new double[kend];
	zmotok = new double[kend];
	bbk = new double[kend];
	bmk = new double[kend];
	uak = new double[kend];
	thek = new double[kend];
	eetk = new double[kend];
	cmugk = new double[kend];
	tanck = new double[kend];
	sinck = new double[kend];
	uck = new double[kend];
	kanseik = new double[kend];

	flxk = new double[kend]; //'kanako07.9.16:wadako�ł�sub HHH�Ő錾flx�Ƃ��Đ錾����Ă� *double��OK�H
	cflxk = new double[kend]; //'kanako07.9.16:wadako�ł�sub CCC�Ő錾cflx�Ƃ��Đ錾����Ă�  *double��OK�H
//'2�����œ���������̂ŁAflxk()�Acflxk()�ɕύX�I

	zorigk = new double[kend]; //'07.9.22:kanako�ǉ�

	flag1 = new int[kend]; //'�v�Z�t���O1����'07.10.17;hmin�Ŕ���ih��hmin�̂Ƃ�0,hmin��h�̂Ƃ�1 �j*1�����f�[�^�����z��A���P�[�g(100)
//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
	inputflag_zorigk = new int[kend];
	inputflag_bbk0 = new int[kend];
	inputflag_zsk = new int[kend];
//' Public Shared zorigk(300) As Single
	bbk0 = new double[kend];
	zzs = new double[kend];
//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
	tmp_zorigk = new double[kend]; //'07.12.17 �ǉ��itmp_inputflag_zs�܂Łj
	tmp_bbk0 = new double[kend];
	tmp_zsk = new double[kend];
	tmp_inputflag_zorigk = new int[kend];
	tmp_inputflag_bbk0 = new int[kend];
	tmp_inputflag_zsk = new int[kend];

	sokugan_eetk =  new double[kend]; //140202 �V�R�_���Ή��@��Q�ǉ�

	//150216 ��Q�@�C��
	pxk = new double[kend];
	havk = new double[kend];
	ustark = new double[kend];


	//�G�C�g����X�y�V����
	bbksabun = new double[kend];




}

void delete1ji()
{
	delete[] chk;
	delete[] csk;
	delete[] zk;
	delete[] hk;
	delete[] uk;
	delete[] ck;
	delete[] zsk;
	delete[] zk0;
	delete[] hk0;
	delete[] uk0;
	delete[] ck0;
	delete[] zmotok;
	delete[] bbk;
	delete[] bmk;
	delete[] uak;
	delete[] thek;
	delete[] eetk;
	delete[] cmugk;
	delete[] tanck;
	delete[] sinck;
	delete[] uck;
	delete[] kanseik;

	delete[] flxk; //'kanako07.9.16:wadako�ł�sub HHH�Ő錾flx�Ƃ��Đ錾����Ă� *double��OK�H
	delete[] cflxk; //'kanako07.9.16:wadako�ł�sub CCC�Ő錾cflx�Ƃ��Đ錾����Ă�  *double��OK�H
//'2�����œ���������̂ŁAflxk()�Acflxk()�ɕύX�I

	delete[] zorigk;; //'07.9.22:kanako�ǉ�

	delete[] flag1; //'�v�Z�t���O1����'07.10.17;hmin�Ŕ���ih��hmin�̂Ƃ�0,hmin��h�̂Ƃ�1 �j*1�����f�[�^�����z��A���P�[�g(100)
//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
	delete[] inputflag_zorigk;
	delete[] inputflag_bbk0;
	delete[] inputflag_zsk;
//' Public Shared zorigk(300) As Single
	delete[] bbk0;
	delete[] zzs;
//!�P�����v�Z�Ŏg�p����ϐ��i�`k�̕t�����́j ��1�����f�[�^������1�����z�����قǃA���P�[�g�@����(300)
	delete[] tmp_zorigk; //'07.12.17 �ǉ��itmp_inputflag_zs�܂Łj
	delete[] tmp_bbk0;
	delete[] tmp_zsk;
	delete[] tmp_inputflag_zorigk;
	delete[] tmp_inputflag_bbk0;
	delete[] tmp_inputflag_zsk;

	delete[] landslide_dam_position;  //20131211�ǉ�:�V�R�_���ݒ�n�_�̔ԍ�
	delete[] landslide_dam_height;  //20131211�ǉ�:�V�R�_���̍���
	delete[] landslide_dam_width;  //20131211�ǉ�:�V�R�_���̒J���i�ő�j
	delete[] sokugan_eetk; //20131217���ݐN�H���x�p�̃p�����[�^

	//150216 ��Q�@�C��
	delete[] pxk;
	delete[] havk;
	delete[] ustark;

	delete[] bbksabun;
}

//�@140202 �V�R�_���̌���1�����z��A���P�[�g(100) ��Q�@�ǉ�
void f1_landslidedam_reconfig(int landslide_dam_number)
{
	landslide_dam_position = new long[landslide_dam_number];
	landslide_dam_height = new double[landslide_dam_number];
	landslide_dam_width = new double[landslide_dam_number];
}

//*�_���̌���1�����z��A���P�[�g(100)
void f1_dam_reconfig(int ndam)
{
	//Base0 ����

	//int wNdam;

	//wNdam = ndam + 1;

//140508 ndam + 1�ɂ��Ȃ���delete[] dam_zd�ŃG���[�@�Ȃ��@�v����
	dam_type = new int[ndam + 1]; //        ' 0:�s����  1:�X���b�g�@2�F�i�q�^
	dam_idam = new int[ndam + 1];
	dam_nzd = new double[ndam + 1];
	dam_zd = new double[ndam + 1];
	dam_slit_width = new double[ndam + 1];
	//			'   ReDim zd0(num)   '�K�v���ǂ����킩��Ȃ�

	hdam = new double[ndam]; //'06.6.16�ȉ���ǉ�
	cdam = new double[ndam];

				//'  ReDim Preserve griddam_flag(num)        ' 0:���ҏW  1:�ҏW��
}

void delete_dam()
{
	delete[] dam_type;
	delete[] dam_idam;
	delete[] dam_nzd;
	delete[] dam_zd;
	delete[] dam_slit_width;
	delete[] hdam;
	delete[] cdam;
}

void sokuteiten_reconfig(int num) //'Public Shared�ɕύX
{
	//Base0 ����

	//int wNum;

	//wNum = num + 1;

	qsum = new double[num];
	qhsum = new double[num];
	qssum = new double[num];
	qsum0 = new double[num];
	qhsum0 = new double[num];
	qssum0 = new double[num];
	q = new double[num];
	qh = new double[num];
	qs = new double[num];
	iout = new int[num];
}

void delete_sokuteiten()
{
	delete[] qsum;
	delete[] qhsum;
	delete[] qssum;
	delete[] qsum0;
	delete[] qhsum0;
	delete[] qssum0;
	delete[] q;
	delete[] qh;
	delete[] qs;
	delete[] iout;
}

void inputhydro_reconfig(int num) //'Public Shared�ɕύX
{
	//Base0 ����

	//int wNum;

	//wNum = num + 1;

	qin0 = new double[num];
	qin0_time = new int[num];
	chin0 = new double[num];

				//'       ReDim inputflag_qin0(num)

}

void delete_inputhydro()
{
	delete[] qin0;
	delete[] qin0_time;
	delete[] chin0;
}

void outputhydro_reconfig(int num1, int num2)
{
//	//Base0 ����
//
//	//int wNum1,wNum2;
//	int wNum1;
//
//	wNum1 = num1 + 1;
//	//wNum2 = num2 + 1;
//
//	// 3�����z��̍쐬.
//	hydroout_dat = new double**[wNum1];
//	for(int i = 0; i < wNum1; i++)
//	{
//		hydroout_dat[i] = new double*[num2];
//		for(int j = 0; j < num2; j++)
//		{
//			hydroout_dat[i][j] = new double[3];
//		}
//	}

	try
	{
		//Base0 ����

		//int wNum1,wNum2;
		int wNum1;

		wNum1 = num1 + 1;
		//wNum2 = num2 + 1;

		// 3�����z��̍쐬.
		hydroout_dat = new float**[wNum1];
		for(int i = 0; i < wNum1; i++)
		{
			hydroout_dat[i] = new float*[num2];
			for(int j = 0; j < num2; j++)
			{
				hydroout_dat[i][j] = new float[3];
			}
		}

	}
	catch(bad_alloc)
	{ // ��O bad_alloc �������Ŏ󂯎��
		cerr << "bad_alloc ��O���󂯎��܂����B" << endl;
		abort();
	}
	catch(...)
	{ // ����ȊO�̗�O�͂����Ŏ󂯎��
		cerr << "���̑��̗�O���󂯎��܂����B" << endl;
		abort();
	}



//	hydroout_dat = new double**[num1];
//	for(int i = 0; i < num1; i++)
//	{
//		hydroout_dat[i] = new double*[num2];
//		for(int j = 0; j < num2; j++)
//		{
//			hydroout_dat[i][j] = new double[3];
//		}
//	}
}

void delete_outputhydro(int num1, int num2)
{
	//Base0 ����

	//int wNum1,wNum2;

	//wNum1 = num1 + 1;
	//wNum2 = num2 + 1;

	for(int i=0; i < num1; i++)
	{
		for(int j=0; j < num2; j++)
		{
			delete[] hydroout_dat[i][j];
		}
		delete[] hydroout_dat[i];
	}
	delete[] hydroout_dat;
}








void init_simulation_1D()
{
	//'       ********************************
	//'       ������
	//'       ********************************

	int i, k;

	for(i = 0;i < kend;i++) //Base0 ����
	{
		zk[i] = zorigk[i];

		zmotok[i] = zorigk[i];
		//'!zmotok�����̑͐ό��izk-zmotok�ő͐ό��ω��j


		hk[i] = hmin; //'08.1.7hmin�ɏ������炵�ĂĂ����H0�̕����������A�m�F�I
/*
		uk[k] = 0;
		ck[k] = 0;

		flag1[k] = 0; //'07.10.17�ǉ��F�v�Z�t���O
*/
		uk[i] = 0;   //////
		ck[i] = 0;

		flag1[i] = 0; //'07.10.17�ǉ��F�v�Z�t���O

		hk0[i] = hk[i];
		uk0[i] = uk[i];
		ck0[i] = ck[i];

		//'   eetk(i) = 0 '20131219:������͊m�F���������Z�b�g�����i������������E������0�Ƀ��Z�b�g����̂Łj
		sokugan_eetk[i] = 0; //20131219�ǉ�  140202 ��Q�@�C��
	}

	for(i = 0;i < nout;i++) //Base0 ����
	{
		qsum[i] = 0;
		qhsum[i] = 0;
		qssum[i] = 0;
		q[i] = 0;
		qh[i] = 0;
		qs[i] = 0;
	}

	for(i = 0;i < kend;i++) //Base0 ����
	{
		bbk[i] = bbk0[i];
	}

	for(i = 0;i < kend - 1;i++) //Base0 ����
 	{
		bmk[i] = (bbk[i] + bbk[i + 1]) * 0.5;
	}

	bmk[kend - 1] = bmk[kend - 2]; //Base0 ����



	//'DAM�̍���
	for(k = 0;k < ndam;k++) //Base0 ����
	{
		if(dam_type[k] != 2)
		{
			dam_zd[k] = (zsk[dam_idam[k]] + zsk[dam_idam[k] + 1]) * 0.5 + dam_nzd[k];
			//'Else
			//'    dam_zd[k] = (zs(dam_idam[k]) + zs(dam_idam[k] + 1)) * 0.5 + zhd(0, 1)
		}
	}

	hydro_counter = 0; //'08.1.6�ǉ�

	ichiji_counter = 0;
	niji_counter = 0;

 //////Call sokuteiten_reconfig(10) '07.12.28�֋X�I�ɒǉ�

	return;
}

void initial_1D()
{
	qinstep = int(1.0 / dt); // '!�����ʂ����b���Ƃɓǂނ�       it's new
	qoutstep = int(2.0 / dt); //'!���o�ʂ����b���Ƃɏo����       it's new
	qdatastep = int(1.0 / dt); //'!�����ʂ̃f�[�^�͉��b�����̂��̂�    it's new
	secstep = int(1.0 / dt); //'!�P�b�Ԃ�dt�̌�        it's new
	minstep = int(60.0 / dt); //'!�P���Ԃ�dt�̌�       it's new
	tminstep = int(1800.0 / dt); //'!�P�O���Ԃ�dt�̌�     it's new

// 130628 �C��
//	hok = 35.0 / 180.0 * pai;
//	slmax = tan(hok) * 0.99;
	hok = 35.0 / 180.0 * pai; //SERMOW�ł����p����Ă���񎟌��n�`�̈����p�ȏ�������p(35�x���j�ɂ��鏈���B�ύX�����I20130507�m�F
	slmax = tan(hok) * 0.99;

// 130628 �C��
	rad_muki = muki / 180.0 * pai; //20130507�C��:��������deg�̂܂�muki�������̂�radian�\���ɏC���I�����̏����������킹�āB

	int k;
	for(k = 0;k < kend;k++) //Base0 ����
	{
		//'       do 10 k=1,kend
		hk[k] = hmin; //  ' !it's new
		uk[k] = 0;
		ck[k] = 0;

		flag1[k] = 0; //'07.10.17�ǉ��F�v�Z�t���O
	}
	//'	10 continue

	for(k = 0;k < kend;k++) // '07.9.22:kanako�ǉ� //Base0 ����
	{
		zorigk[k] = zk[k];
	}

	//'!zsk�N�H���E����
	//'!----------------------zmotok----------------------------
	for(k = 0;k < kend;k++) //Base0 ����
	{
		zmotok[k] = zk[k];
	}

	//'!zmotok�����̑͐ό��izk-zmotok�ő͐ό��ω��j
	//'!---------------------haba heikin-----------------------

	for(k = 0;k < kend;k++) //Base0 ����
	{
		//bbk0[k] = bbk[k]; //'07.12.17�ǉ�
		bbk[k] = bbk0[k]; //'20131219�C���F�C���O�̏������ł��e���͂��Ȃ������i�m�F�ρj
	}
		 //'!bbk�͓���

	for(k = 0;k < kend - 1;k++) //Base0 ����
	{
		bmk[k] = (bbk[k] + bbk[k + 1]) * 0.5;
	}

	bmk[kend - 1] = bbk[kend - 1];


	ichiji_counter = 0; //'07.10.1�ǉ�
	niji_counter = 0; //'07.10.1�ǉ�

	return;
}


//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
//'!      initial condition--------nijigen
//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
void NIinitial() //'(hmin,iend,jend)
{
	int i,j;
	string str;

	//'!--------------------initial value---------------------
	//'   do 10 i=1,iend
	//'do 20 j=1,jend
	for(i = 0;i < iend;i++) //Base0 ����
	{
		for(j = 0;j < jend;j++) //Base0 ����
		{
			h[i][j] = hmin; //  ' !it's new
			u[i][j] = 0;
			v[i][j] = 0;
			c[i][j] = 0;

			flag2[i][j] = 0; //'07.10.17�ǉ��F�v�Z�t���O

			//'081113:���Z�b�g�����Ă����I�I�I�I�I
			ua[i][j] = 0;
			va[i][j] = 0;
			uL[i][j] = 0;
			r1[i][j] = 0;

			dzdn[i][j] = 0;

			eet[i][j] = 0;
			cmug[i][j] = 0;
			tanc[i][j] = 0;
			sinc[i][j] = 0;
			uc[i][j] = 0;
			kansei[i][j] = 0;

			flx[i][j] = 0;
			fly[i][j] = 0;

			vr[i][j] = 0;
			cflx[i][j] = 0;
			cfly[i][j] = 0;
			//'081113:���Z�b�g�����Ă����I�I�I�I�I�����܂ŏC��

		}
	}
	//'20:     continue()
	//'10:     continue()

	//'!---------------------- z ------------------------------
	//'  do 30 i=1,iend

//	sprintf(WorkBuff,"%sThreeD\\Simulation\\%s\\wadako2-z.dat",DriveName,FolderName);
	sprintf(WorkBuff,"%s\\wadako2-z.dat",FolderName);
	std::ifstream zifs( WorkBuff );
//	sprintf(WorkBuff,"%sThreeD\\Simulation\\%s\\wadako2-zs.dat",DriveName,FolderName);
	sprintf(WorkBuff,"%s\\wadako2-zs.dat",FolderName);
	std::ifstream zsifs( WorkBuff );
//	sprintf(WorkBuff,"%sThreeD\\Simulation\\%s\\wadako2-id.dat",DriveName,FolderName);
	sprintf(WorkBuff,"%s\\wadako2-id.dat",FolderName);
	std::ifstream idifs( WorkBuff );

	for(i = 0;i < iend;i++)  //Base0 ����
	{
		for(j = 0;j < jend;j++)  //Base0 ����
		{
			zifs >> str;
			z[i][j] = atof(str.c_str());
			zsifs >> str;
			zs[i][j] = atof(str.c_str());
			idifs >> str;
			id[i][j] = atoi(str.c_str());
		}
	}

	zifs.close();
	zsifs.close();
	idifs.close();

	//'30:     continue()
	//'!----------------------zmoto----------------------------
	//'  do 40 i=1,iend
	//'do 50 j=1,jend
	for(i = 0;i < iend;i++) //Base0 ����
	{
		for(j = 0;j < jend;j++)  //Base0 ����
		{
			zmoto[i][j] = z[i][j];
		}
	}

	//'50:     continue()
	//'40:     continue()

	//' Return

	return;
}


//'!-----------------------nijigen de tukaumono--------------------------------
//'!�Q�����v�Z�Ŏg�p����ϐ�  ��2�����f�[�^������2�����z�����قǃA���P�[�g�@����(300,300)
void init2ji(int iend,int jend)
{
	 //Base0 ����

	//int wIend,wJend;

	//wIend = iend + 1;
	//wJend = jend + 1;

	z = new double*[iend];
	h = new double*[iend];
	u = new double*[iend];
	v = new double*[iend];
	c = new double*[iend];
	zs = new double*[iend];
	z0 = new double*[iend];
	h0 = new double*[iend];
	u0 = new double*[iend];
	v0 = new double*[iend];
	c0 = new double*[iend];
	zmoto = new double*[iend];
	ua = new double*[iend];
	va = new double*[iend];
	uL = new double*[iend];
	flag2 = new int*[iend];
	flag2_Ruiseki = new int*[iend]; // 20190212 Iwanami


	tmp_z0 = new double*[iend];
	tmp_zs0 = new double*[iend];
	r1 = new double*[iend];
	dzdn = new double*[iend];
	eet = new double*[iend];
	cmug = new double*[iend];
	tanc = new double*[iend];
	sinc = new double*[iend];
	uc = new double*[iend];
	kansei = new double*[iend];
	flx = new double*[iend];
	fly = new double*[iend];
	vr = new double*[iend];
	cflx = new double*[iend];
	cfly = new double*[iend];
	vm_NIUUU = new double*[iend];
	um_NIVVV = new double*[iend];
	ni_energy = new double*[iend];
	id = new int*[iend];

	//image = new unsigned char*[iend];

	for(int i=0;i<iend;i++)
	{
		z[i] = new double[jend];
		h[i] = new double[jend];
		u[i] = new double[jend];
		v[i] = new double[jend];
		c[i] = new double[jend];
		zs[i] = new double[jend];
		z0[i] = new double[jend];
		h0[i] = new double[jend];
		u0[i] = new double[jend];
		v0[i] = new double[jend];
		c0[i] = new double[jend];
		zmoto[i] = new double[jend];
		ua[i] = new double[jend];
		va[i] = new double[jend];
		uL[i] = new double[jend];
		flag2[i] = new int[jend];
		flag2_Ruiseki[i] = new int[jend]; // 20190212 Iwanami

		tmp_z0[i] = new double[jend];
		tmp_zs0[i] = new double[jend];
		r1[i] = new double[jend];
		dzdn[i] = new double[jend];
		eet[i] = new double[jend];
		cmug[i] = new double[jend];
		tanc[i] = new double[jend];
		sinc[i] = new double[jend];
		uc[i] = new double[jend];
		kansei[i] = new double[jend];
		flx[i] = new double[jend];
		fly[i] = new double[jend];
		vr[i] = new double[jend];
		cflx[i] = new double[jend];
		cfly[i] = new double[jend];
		vm_NIUUU[i] = new double[jend];
		um_NIVVV[i] = new double[jend];
		ni_energy[i] = new double[jend];
		id[i] = new int[jend];
	}

	//for(int i=0;i<iend;i++)
	//{
	//	image[i] = new unsigned char[jend * PIXCELPERBYTE];
	//}

	return;
}

void delete2ji(int iend)
{
	//Base0 ����
	//int wIend;

	//wIend = iend + 1;

	for(int i=0;i<iend;i++)
	{
		delete[] z[i];
		delete[] h[i];
		delete[] u[i];
		delete[] v[i];
		delete[] c[i];
		delete[] zs[i];
		delete[] z0[i];
		delete[] h0[i];
		delete[] u0[i];
		delete[] v0[i];
		delete[] c0[i];
		delete[] zmoto[i];
		delete[] ua[i];
		delete[] va[i];
		delete[] uL[i];
		delete[] flag2[i];
		delete[] flag2_Ruiseki; // 20190212 Iwanami

		delete[] tmp_z0[i];
		delete[] tmp_zs0[i];
		delete[] r1[i];
		delete[] dzdn[i];
		delete[] eet[i];
		delete[] cmug[i];
		delete[] tanc[i];
		delete[] sinc[i];
		delete[] uc[i];
		delete[] kansei[i];
		delete[] flx[i];
		delete[] fly[i];
		delete[] vr[i];
		delete[] cflx[i];
		delete[] cfly[i];
		delete[] vm_NIUUU[i];
		delete[] um_NIVVV[i];
		delete[] ni_energy[i];
		delete[] id[i];
	}

	//for(int i=0;i<iend;i++)
	//{
	//	delete[] image[i];
	//}

	delete[] z;
	delete[] h;
	delete[] u;
	delete[] v;
	delete[] c;
	delete[] zs;
	delete[] z0;
	delete[] h0;
	delete[] u0;
	delete[] v0;
	delete[] c0;
	delete[] zmoto;
	delete[] ua;
	delete[] va;
	delete[] uL;
	delete[] flag2;
	delete[] flag2_Ruiseki; // 20190212 Iwanami


	delete[] tmp_z0;
	delete[] tmp_zs0;
	delete[] r1;
	delete[] dzdn;
	delete[] eet;
	delete[] cmug;
	delete[] tanc;
	delete[] sinc;
	delete[] uc;
	delete[] kansei;
	delete[] flx;
	delete[] fly;
	delete[] vr;
	delete[] cflx;
	delete[] cfly;
	delete[] vm_NIUUU;
	delete[] um_NIVVV;
	delete[] ni_energy;
	delete[] id;

	//delete[] image;
}

void init_niji_dat(int num1, int num2)
{
	int wNum1,wNum2;

	wNum1 = num1 + 1;
	wNum2 = num2 + 1;

	// 4�����z��̍쐬.
	niji_dat = new double***[1000];
	for(int i = 0; i < 1000; i++)
	{
		niji_dat[i] = new double**[wNum1];
		for(int j = 0; j < wNum1; j++)
		{
			niji_dat[i][j] = new double*[wNum2];
			for(int k = 0; k < wNum2; k++)
			{
				niji_dat[i][j][k] = new double[6];
			}
		}
	}
}

void delete_niji_dat(int num1, int num2)
{
	int wNum1,wNum2;

	wNum1 = num1 + 1;
	wNum2 = num2 + 1;

	for(int i=0; i < 1000; i++)
	{
		for(int j=0; j < wNum1; j++)
		{
			for(int k=0; k < wNum2; k++)
			{
				delete[] niji_dat[i][j][k];
			}
			delete[] niji_dat[i][j];
		}
		delete[] niji_dat[i];
	}
	delete[] niji_dat;
}

void init_ichiji_dat(int num)
{
	int wNum;

	wNum = num + 1;

	// 3�����z��̍쐬.
	ichiji_dat = new double**[1000];
	for(int i = 0; i < 1000; i++)
	{
		ichiji_dat[i] = new double*[wNum];
		for(int j = 0; j < wNum; j++)
		{
			ichiji_dat[i][j] = new double[11];
		}
	}
}

void delete_ichiji_dat(int num)
{
	int wNum;

	wNum = num + 1;

	for(int i=0; i < 1000; i++)
	{
		for(int j=0; j < wNum; j++)
		{
			delete[] ichiji_dat[i][j];
		}
		delete[] ichiji_dat[i];
	}
	delete[] ichiji_dat;
}

void Debug_Memory()
{
	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < iend + 1; j++)
		{
			for(int k = 0; k < jend + 1; k++)
			{
				for(int l = 0; l < 6; l++)
				{
					niji_dat[i][j][k][l] = 0.0;
				}
			}
		}
	}

	for(int i = 0; i < 1000; i++)
	{
		for(int j = 0; j < kend + 1; j++)
		{
			for(int k = 0; k < 11; k++)
			{
				ichiji_dat[i][j][k] = 0.0;
			}
		}
	}

	return;
}

void Debug_2ji_data()
{
	ofstream zfout( "Debug_z.dat", ios::out );
	ofstream zsfout( "Debug_zs.dat", ios::out );
	ofstream idfout( "Debug_id.dat", ios::out );

	for(int i = 0;i < iend;i++) //Base0 ����
	{
		for(int j = 0;j < jend;j++) //Base0 ����
		{
			zfout << z[i][j] << " ";
			zsfout << zs[i][j] << " ";
			idfout << id[i][j] << " ";
		}
		zfout << endl;
		zsfout << endl;
		idfout << endl;
	}

	zfout.close();
	zsfout.close();
	idfout.close();

	return;
}

void Debug_1ji_data()
{
	ofstream fout( "Debug_1ji.dat", ios::out );

	for(int i = 0;i < kend;i++) //Base0 ����
	{
		fout << zsk[i] << " ";
		fout << zorigk[i] << " ";
		fout << bbk0[i] << " ";
		fout << inputflag_zsk[i] << " ";
		fout << inputflag_zorigk[i] << " ";
		fout << inputflag_bbk0[i] << " ";
		fout << endl;
	}

	fout.close();

	return;
}

void Debug_Default_data()
{
	int i;

	ofstream fout( "Debug_Default.dat", ios::out );

	fout << ";Version" << " " << file_version.c_str() << endl;
	fout << ";file_kind(1;Coefficient and 1D topography,2;2D topography)" << " " << file_kind.c_str() << endl;

	fout << ";Calculate Time(sec)" << " " << dt  << endl;
	fout << ";Density of SAREKI(small particle diameter)(Kg/m3)" << " " << s << endl;
	fout << ";Density of water(kg/m^3)" << " " << rho << endl;
	fout << ";Gravitational acceleration" << " " << g << endl;
	fout << ";Minimum depth of water" << " " << hmin << endl;
	fout << ";Volume density of riverbed" << " " << csta << endl;
	fout << ";Maning coefficient of roughness" << " " << nm << endl;
	fout << ";Encroachment rate coefficient" << " " << deltae << endl;
	fout << ";Heap rate coefficient" << " " << deltad << endl;
	fout << ";Heap rate coefficient with inertial force" << " " << pi << endl;
	fout << ";Simulate Time(sec)" << " " << timemax << endl;
	fout << ";Soil diameter(m)" << " " << d << endl;
	fout << ";Pai" << " " << pai << endl;
	fout << ";Interval time of hydoro data display(sec)" << " " << hydroout_dt << endl;
	fout << ";Interval time of result output(sec)" << " " << result_output_dt << endl;
	fout << ";Use 2D:Direction of input flow" << " " << muki << endl;
	fout << ";Central X axis of input flow on 2D plane" << " " << jc << endl;
	fout << ";Central Y axis of input flow on 2D plane" << " " << jr << endl;
	fout << ";Inteval of Caluculate(2D x axis)(m)" << " " << dx << endl;
	fout << ";Inteval of Caluculate(2D y axis)(m)" << " " << dy << endl;
	fout << ";Water depth threshold by flow of 2D caluculate" << " " << hlim << endl;
	fout << ";Number of Caluculate(2D x axis)" << " " << iend << endl;
	fout << ";Number of Caluculate(2D y axis)" << " " << jend << endl;
	fout << ";All number of Caluculate(1D)" << " " << kend << endl;
	fout << ";Inteval of Caluculate(1D)(m)" << " " << dxk << endl;
	fout << ";Water depth threshold by flow of 1D caluculate(m)" << " " << hlimk << endl;

	fout << endl;
	fout << ";Presence of dam[0:no,1:yes]" << " " << dam_flag << endl;
	fout << ";Number of dam" << " " << ndam << endl;
	fout << ";Parameter of dam(Type[0:Impermeant,1:Slit,2:Grid],Location,Height,Slit width" << endl;
	for(i = 0;i < ndam;i++) //Base0 ����
	{
		fout << dam_type[i] << " ";
		fout << dam_idam[i] << " ";
		fout << dam_nzd[i] << " ";
		fout << dam_slit_width[i] << " ";
		fout << endl;
	}

	fout << endl;
	fout << ";Number of observation point" << " " << nout << endl;
	fout << ";Parameter of observation point(location)" << endl;
	for(i = 0;i < nout;i++) //Base0 ����
	{
		fout << iout[i] << endl;
	}

	fout << endl;
	fout << ";Point number of input hydro" << " " << dnum << endl;
	fout << ";Change of soil density(0:no,1:yes)" << " " << c_change_flag << endl;
	if(c_change_flag == 1)
	{
		fout << ";Change tilme of soil density(sec)" << " " << c_change_time << endl;
	}

	fout << ";Soil Density" << " " << chin0_1 << endl;

	if(c_change_flag == 1)
	{
		fout << ";Big diameter density of after density change" << " " << chin0_2 << endl;
	}

	fout << ";Data(Time,Amount of flowing)" << endl;
	for(i = 0;i < dnum;i++) //Base0 ����
	{
		fout << qin0_time[i] << " ";
		fout << qin0[i] << " ";
		fout << endl;
	}

	fout.close();

	return;
}

void kansokuten_position_keikoku() //'08827�ǉ�
{
	cout << "Observation point is set just upstream to the dam!" << endl << "After changing the observation point position, please start simulation." << endl;
}

void landslide_dam_position_keikoku() // 20131211�ǉ�
{
	cout << "Landslide dam and sabo dam can not be set on the same point!" << endl << "After changing the any dam position, please start simulation." << endl;
}

void dam_position_keikoku() //'08827�ǉ�
{
	cout << "Dams are not set in numerical order from the upstream!" << endl << "After changing the dam position, please start simulation." << endl;
}

void dam_position_reset()
{
				//'08929:�_���ԍ��̕��ёւ�
	int *temp_dam_type;
	int *temp_dam_idam;
	double *temp_dam_nzd;
	double *temp_dam_slit_width;

	int i,j;

	int t_dam_type;
	int t_dam_idam;
	double t_dam_nzd;
	double t_dam_slit_width;

	temp_dam_type = new int[ndam + 1];
	temp_dam_idam = new int[ndam + 1];
	temp_dam_nzd = new double[ndam + 1];
	temp_dam_slit_width = new double[ndam + 1];

	for(i = 0;i < ndam;i++) //Base0 ����
	{
		temp_dam_type[i] = dam_type[i];
		temp_dam_idam[i] = dam_idam[i];
		temp_dam_nzd[i] = dam_nzd[i];
		temp_dam_slit_width[i] = dam_slit_width[i];
	}

	if(ndam == 1)
	{
		i = ndam;
		dam_type[i] = temp_dam_type[i];
		dam_idam[i] = temp_dam_idam[i];
		dam_nzd[i] = temp_dam_nzd[i];
		dam_slit_width[i] = temp_dam_slit_width[i];
	}
	else
	{
		for(i = 0;i < ndam - 1;i++) // '�������ёւ����[�v:0885 //Base0 ����
		{
			for(j = ndam - 2;j >= i;j--) //Base0 �����@
			{
				if(temp_dam_idam[j] > temp_dam_idam[j + 1])
				{
					t_dam_idam = temp_dam_idam[j];
					t_dam_type = temp_dam_type[j];
					t_dam_nzd = temp_dam_nzd[j];
					t_dam_slit_width = temp_dam_slit_width[j];

					temp_dam_idam[j] = temp_dam_idam[j + 1];
					temp_dam_type[j] = temp_dam_type[j + 1];
					temp_dam_nzd[j] = temp_dam_nzd[j + 1];
					temp_dam_slit_width[j] = temp_dam_slit_width[j + 1];

					temp_dam_idam[j + 1] = t_dam_idam;
					temp_dam_type[j + 1] = t_dam_type;
					temp_dam_nzd[j + 1] = t_dam_nzd;
					temp_dam_slit_width[j + 1] = t_dam_slit_width;
				}
			}
		}
	}

	for(i = 0;i < ndam;i++) //Base0 ����
	{
		dam_idam[i] = temp_dam_idam[i];
		dam_type[i] = temp_dam_type[i];
		dam_nzd[i] = temp_dam_nzd[i];
		dam_slit_width[i] = temp_dam_slit_width[i];
	}

	delete[] temp_dam_type;
	delete[] temp_dam_idam;
	delete[] temp_dam_nzd;
	delete[] temp_dam_slit_width;

	return;
}

void landslide_dam_position_reset()  //'20131211�ǉ� 140202 ��Q�@�ǉ�
{
	//'�V�R�_���ԍ��̕��ёւ�
	int *temp_landslide_dam_position = new int[landslide_dam_number + 1];
	double *temp_landslide_dam_height = new double[landslide_dam_number + 1];
	double *temp_landslide_dam_width = new double[landslide_dam_number + 1];

	for(int i = 0;i < landslide_dam_number;i++) //Base0 ����
	{
		temp_landslide_dam_position[i] = landslide_dam_position[i];
		temp_landslide_dam_height[i] = landslide_dam_height[i];
		temp_landslide_dam_width[i] = landslide_dam_width[i];
	}

	int t_landslide_dam_position;
	double t_landslide_dam_height;
	double t_landslide_dam_width;

	if(landslide_dam_number == 1)
	{
		landslide_dam_position[0] = temp_landslide_dam_position[0];
		landslide_dam_height[0] = temp_landslide_dam_height[0];
		landslide_dam_width[0] = temp_landslide_dam_width[0];
	}
	else
	{
		for(int i = 0;i < landslide_dam_number - 1;i++) // '�������ёւ����[�v:0885 //Base0 ����
		{
			for(int j = landslide_dam_number - 2;j >= i;j--) //Base0 �����@
			{
				if(temp_landslide_dam_position[j] > temp_landslide_dam_position[j + 1])
				{
					t_landslide_dam_position = temp_landslide_dam_position[j];
					t_landslide_dam_height = temp_landslide_dam_height[j];
					t_landslide_dam_width = temp_landslide_dam_width[j];

					temp_landslide_dam_position[j] = temp_landslide_dam_position[j + 1];
					temp_landslide_dam_height[j] = temp_landslide_dam_height[j + 1];
					temp_landslide_dam_width[j] = temp_landslide_dam_width[j + 1];

					temp_landslide_dam_position[j + 1] = t_landslide_dam_position;
					temp_landslide_dam_height[j + 1] = t_landslide_dam_height;
					temp_landslide_dam_width[j + 1] = t_landslide_dam_width;
				}
			}
		}
	}

	for(int i = 0;i < landslide_dam_number;i++) //Base0 ����
	{
		landslide_dam_position[i] = temp_landslide_dam_position[i];
		landslide_dam_height[i] = temp_landslide_dam_height[i];
		landslide_dam_width[i] = temp_landslide_dam_width[i];
	}

	delete[] temp_landslide_dam_position;
	delete[] temp_landslide_dam_height;
	delete[] temp_landslide_dam_width;

	return;
}
//'20131211�ǉ������܂�



void observation_position_reset() //'08929
{
	int i, j,t_iout;
	int tmp_iout[101]; //tmp_iout(100)

	for(i = 0;i < nout;i++) //Base0 ����
	{
		tmp_iout[i] = iout[i];
	}

	if(nout == 1)
	{
		i = nout;
		iout[i] = tmp_iout[i];
		return;
	}
	else
	{
		for(i = 0;i < nout - 1;i++) //Base0 ���� // '�������ёւ����[�v:0885
		{
			for(j = nout - 2;j >= i;j--) //Base0 ����
			{
				if(tmp_iout[j] > tmp_iout[j + 1])
				{
					t_iout = tmp_iout[j];
					tmp_iout[j] = tmp_iout[j + 1];
					tmp_iout[j + 1] = t_iout;
				}
			}
		}

		for(i = 0;i < nout;i++) //Base0 ����
		{
			iout[i] = tmp_iout[i];
		}
	}

	return;
}

void dam_position_keikoku2() //'0893�ǉ�
{
	cout << "Dam can not be set at the downstream end and above of 1D area !" << endl << "After changing the dam position, please start simulation." << endl;

	return;
}

//20140409�ǉ�  ��Q
void width_keikoku() //1400409 �ǉ� ��Q
{
	cout << "The value of the river width is not appropriate!" << endl << "Please set river width larger than 0." << endl;

	return;
}

//20140606 �ǉ� ��Q
void landslide_dam_width_keikoku()
{
	cout << "Landslide dam width smaller than river width (Initial stream width) can not be set!" << endl;

	return;
}

void Replacement_Timer1_Tick()
{
	//' timemax = 65
	long l; // '07.9.19:i��l�ɕύX
	//long l_time;
	long long l_time;
	int i, j, k;

	long l1,l2,lend1,lend2;

	lend2 = long(ceil(result_output_dt / dt));
	if((long)timemax % (long)result_output_dt == 0)
	{
		lend1 = long(timemax / result_output_dt);
	}
	else
	{
		lend1 = long(timemax / result_output_dt) + 1;
	}


	//0�b�ǉ�
	printf("%0.2fsec\n",mstep * dt);
	save_result_each_time(mstep * dt);

	for(l1 = 0;l1 < lend1;l1++)
	{
		for(l = 0;l < lend2;l++) //Base0 ����
		{
			f_time = mstep * dt;
			l_time = ceil(f_time * 1000);

			////ichijigen();
			//'!***************************************************************************
			//'!      main program
			//'!***************************************************************************

			////inflow(); // '07.12.26�ǉ�'08.1.7������̌`�œ���I
			for(i = 0;i < dnum - 1;i++) //Base0 ����
			{
				if((f_time >= qin0_time[i]) && (f_time < qin0_time[i + 1]))
				{
					qink1 = (qin0[i + 1] - qin0[i]) / (qin0_time[i + 1] - qin0_time[i]) * (f_time - qin0_time[i]) + qin0[i]; //'08.1.6qin��wadako�ł�qink1!

					//'08730��������
//					if(c_change_flag == 1) //'08728�ύX
//					{
//						if(f_time <= c_change_time) //'08730:2Dkanako�ł�t�ł͂Ȃ�time�I
//						{
//							chin = chin0_1;
//						}
//						else
//						{
//							chin = chin0_2;
//						}
//					}
//					else
//					{
//						chin = chin0_1;
//					}

					//'2012 02 15 �Z�x�������ɂ���Čv�Z  ���̃v���O�����͔��z������Ȃ�
					//chin = (chin0[i + 1] - chin0[i]) / (qin0_time[i + 1] - qin0_time[i]) * (f_time - qin0_time[i]) + chin0[i];
					chin = chin0[i+1];     //�Ƃ肠�����I���W�i���ɍ��킹�� 120712�C��

					if(qink1 <= 0) //'08.1.6:�����y���ʂł̐��`�⊮:�P���ɂ����邾���ł̓_���I
					{
						cink1 = 0;
					}
					else
					{
						cink1 = ((chin * qin0[i + 1] - chin * qin0[i]) / (qin0_time[i + 1] - qin0_time[i]) * (f_time - qin0_time[i]) + (chin * qin0[i])) / qink1;
					}
				}
			}


			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      kosin
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////kosin();
			for(k = 0;k < kend;k++) //Base0 ����
			{
				zk0[k] = zk[k];
				hk0[k] = hk[k];
				uk0[k] = uk[k];
				ck0[k] = ck[k];
				bbk0[k] = bbk[k]; //'20131217�ǉ�  140202 ��Q�@�ǉ�
			}

			for(k = 0;k < kend - 1;k++) //'20131217�ǉ�    140202 ��Q�@�ǉ�
			{
				bmk[k] = (bbk[k] + bbk[k + 1]) * 0.5;
			}
			//'20131217�ǉ�:����܂ł�initial�ŌĂ񂾂���B���h�_���ɂ��Ă�HHH,CCC��If�ŏ����킯���Ă����B

			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      sub uk heikin-------------uak
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////uave(); //'(hmin,kend)
			for(k = 1;k < kend;k++) //Base0 ���� ���Ӂ@���� k = 2
			{
				if(hk0[k] <= hmin) // '!it's new �ϐ���0�t���Ƃ��܂���
				{
					uak[k] = 0.0;
				}
				else
				{
					uak[k] = (uk0[k - 1] + uk0[k]) * 0.5;
				}
			}

		//''!---------------boundary conditions 1---------------
			uak[0] = uk[0]; //Base0 ����
		//''!---------------------------------------------------

			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      sub sinsyokusokudo---------eetk
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////erosion(); //'(kend,rho,s,g,d,hmin,deltae,deltad,pi,csta,dxk,dt)
			double tanf;
			double f1, f2, f3, f4, f5;
			double al, al2, ts, tsc;

// 130628 �C��
//			tanf = tan(37.0 / 180.0 * 3.14159265358); //'!kanako�ł�tanf=0.7
				tanf = tan(fai / 180.0 * 3.14159265358); // '20130507�C���O
//				'   tanf = Math.Tan(37.0 / 180.0 * 3.14159265358) '!kanako�ł�tanf=0.7'20130507�C���O�i37�x�ŌŒ�j


			f1 = rho / (s - rho);
			f2 = 6.7 * f1 * f1;
			f3 = s / (s - rho);

			//''!-------------------------------koubai keisan-------------------------------
			//'       do 20 k=1,kend-1
			for(k = 0;k < kend - 1;k++) //Base0 ����
			{
				thek[k] = (hk0[k] + zk0[k] - hk0[k + 1] - zk0[k + 1]) / dxk;

				if (thek[k] < 0.0)
				{
					thek[k] = 0.0;
				}

				if(ndam != 0) //'�_�������ǉ�07.12.20
				{
					for(j = 0;j <  ndam;j++) //Base0 ����
					{
						if((k == dam_idam[j]) && (dam_type[j] == 0)) //'�s���ߌ^�_���̂Ƃ�()
						{
							if(dam_zd[j] > zk0[k + 1]) //'08.6.6wadako�ɕ�����:!�_���������̉͏������V�[�������������߂�(8 / 5 / 27)
							{
								thek[k] = 2 * (hk0[k] + zk0[k] - dam_zd[j]) / dxk;
							}
						}
					}
				}
			}

			for(k = 0;k < kend - 1;k++) //Base0 ����
			{
				if(thek[k] >= tanf * 0.99)
				{
					cmugk[k] = csta * 0.9;
										//'!	    cmugk[k]=csta*0.999        '!it's new'kanako07.9.16�����*0.9�ɂ���
				}
				else
				{
					if(thek[k] > 0.138)
					{
						cmugk[k] = f1 * thek[k] / (tanf - thek[k]);
					}
					else
					{
						if(thek[k] > 0.03)
						{
							cmugk[k] = f2 * thek[k] * thek[k] / pow((tanf - thek[k]),2);
						}
						else
						{
							tsc = 0.04 * pow(10.0, (1.72 * thek[k]));
							ts = hk0[k] * thek[k] * f1 / d;
							if(ts <= tsc)
							{
								cmugk[k] = 0.0;
							}
							else
							{
								al2 = 2.0 * (0.425 - f3 * thek[k]) / (1.0 - f3 * thek[k]);
								al = sqrt(al2); //al = std::pow(al2,0.5);
								f4 = (1.0 + 5.0 * thek[k]) * thek[k] * f1;
								f5 = (1.0 - al2 * tsc / ts) * (1.0 - al * sqrt(tsc / ts)); //f5 = (1.0 - al2 * tsc / ts) * (1.0 - al * pow((tsc / ts),0.5));
								cmugk[k] = f4 * f5;
							}
						}
					}
				}

				if(cmugk[k] < 0.0)
				{
					cmugk[k] = 0.0;
				}
				if(cmugk[k] > csta * 0.9)
				{
					cmugk[k] = csta * 0.9;
										//' cmugk[k] = csta * 0.999     '!it's new
				}
				if((uak[k] <= 0.01) || (hk0[k] <= hmin))
				{
					cmugk[k] = 0.0;
				}

				//'08.6.6wadako�ɕ�����:�i�q���s���߃_�����㗬�͑S���͐ς���(08/05/27)
				if(ndam != 0)
				{
					for(j = 0;j < ndam;j++) //Base0 ���� //Base0 ����
					{
						if ((k == dam_idam[j]) && ((dam_type[j] == 0) || (dam_type[j] == 2)))
						{
							if(zk0[k] < dam_zd[k])
							{
								cmugk[k] = 0;
							}
						}
					}
				}
								//'08.6.6�����܂�


				//'!------------------------------sinsyoku taiseki----------------------------------
				if(cmugk[k] >= ck0[k])
				{
					eetk[k] = deltae * (cmugk[k] - ck0[k]) / (csta - cmugk[k]) * fabs(uak[k]) * hk0[k] / d;
					if(eetk[k] > (zk0[k] - zsk[k]) / dt)
					{
						eetk[k] = (zk0[k] - zsk[k]) / dt;
					}
					if (zk0[k] <= zsk[k])
					{
						eetk[k] = 0.0;
					}
				}
				else
				{
										//'0892:wadako�����a��1����kanako�ɍ��킹���I* hk0[k] / d��͐ςɂ�������
										//' eetk[k] = deltad * (cmugk[k] - ck0[k]) / csta * Math.Abs(uak[k])

					eetk[k] = deltad * (cmugk[k] - ck0[k]) / csta * fabs(uak[k]) * hk0[k] / d;
										//'!�ȉ��͑͐ϑ��x���Ɋ����I�^�����l����������
										//'!        tanck[k]=(ck0[k]*(s-rho)*0.75)/(ck0[k]*(s-rho)+rho)
										//'!		sinck[k]=tanck[k]/(1.0+tanck[k]^2.0)^0.5
										//'!		uck[k]=(0.4/d)*(g*sinck[k]*(ck0[k]+(1.0-ck0[k])*rho/s)/(0.04*0.6))^0.5*((csta/ck0[k])^0.3333333-1.0)*hk0[k]^1.5
										//'!       kanseik[k]=1.0-Math.Abs(uak[k])/(pi*uck[k])
										//'!	    eetk[k]=deltad*kanseik[k]*(cmugk[k]-ck0[k])/csta*Math.Abs(uak[k])
										//'!        if(kanseik[k]=<0.0)then
										//'!         eetk[k]=0.0
										//'!		end if
				}
			}

			//Call sokugan_erosion() '20131217�ǉ� 140202 ��Q�@�ǉ�
//			double SS, sgd;
//			double *ustark(500) As Double
//
//			Dim k As Integer, j As Integer

			double SS = (s / rho) - 1;
			double sgd = SS * g * d;


			//!-------------------------------koubai keisan-------------------------------
//150216�@��Q�@�C��
			//double *ustark = new double[kend];

			//�ȉ�Base0�l��
			for(int k = 0;k < kend - 1;k++) // '���ݐN�H�l����ہA�G�l���M�[���z�iu*)�̑���ɐ��ʌ��z���g��
			{
				//'���h�_���͑��ݐN�H�Ȃ��Ȃ̂ŁA�ʏ�̐��ʌ��z�݂̂�

				thek[k] = (hk0[k] + zk0[k] - hk0[k + 1] - zk0[k + 1]) / dxk;

				if(thek[k] < 0.0)
				{
					thek[k] = 0.0;
				}

				if(landslide_dam_number > 0)
				{
					for(int j = 0;j < landslide_dam_number;j++)
					{
						if((k == landslide_dam_position[j]) && (bbk0[k] < landslide_dam_width[j]))
						{
							if(eetk[k] > 0)
							{
								ustark[k] = pow((g * hk[k] * thek[k]),0.5);
								sokugan_eetk[k] = delta_se * (0.005 * pow(ustark[k],2)) / (pow(sgd,0.5));
								if(sokugan_eetk[k] < 0)
								{
									sokugan_eetk[k] = 0;
								}

								//20140606�␳��ǉ�
								if(sokugan_eetk[k] > (landslide_dam_width[j] - bbk0[k]) / (2.0 * dt))
								{
									sokugan_eetk[k] = (landslide_dam_width[j] - bbk0[k]) / (2.0 * dt);
								}

								if(landslide_dam_width[j] <= bbk0[k])
								{
									sokugan_eetk[k] = 0;
								}
								//20140606�␳��ǉ������܂�
							}
						}
					}
				}
				else
				{
					sokugan_eetk[k] = 0;
				}
			}

//150216�@��Q�@�C��
			//delete[] ustark;

			//'20131217���ݐN�H��ǉ������܂�

			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      sub ryusoku---------------uk
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////UU(); //'(kend,dxk,g,hlimk,csta,dt,qink1,nm,rho,s,d)

			////UUU(); //'(kend,dxk,g,hlimk,csta,dt,nm,rho,s,d)
			double covex1,  p2, p1, fricx; //'���� px As Single'07.12.20:px��z��
//150216 ��Q�C��
//			double *pxk; //'07.12.20
//			double *havk; //'07.12.20
			double ca, ksum, sita; //'kanako07.9.16:ca�錾�Ȃ��H

//150216 ��Q�C��
//			pxk = new double[kend]; //Base0 ���� //Dim pxk(300) As Single '07.12.20
//			havk = new double[kend]; //Base0 ���� //Dim havk(300) As Single '07.12.20

//140408 Debug�p ��Q
//			if(mstep == 32000)
//			{
//				printf("%ld\n",mstep);
//			}

			for(k = 1;k < kend - 1;k++) //Base0 �����@���Ӂ@���� k = 2
			{
				//''!------------------------- CONVECT TERM -----------henbibun-----------------
				if(uk0[k] > 0.0)
				{
					covex1 = uk0[k] * (uk0[k] - uk0[k - 1]) / dxk;
				}
				else
				{
					covex1 = uk0[k] * (uk0[k + 1] - uk0[k]) / dxk;
				}

				//''!------------------------ PRESSURE TERM ------------atsuryokukou------------
				p2 = g * (hk0[k + 1] + zk0[k + 1]);
				p1 = g * (hk0[k] + zk0[k]);
				pxk[k] = (p2 - p1) / dxk;

				if(ndam != 0)
				{
					for(j = 0;j < ndam;j++) //Base0 ����
					{
						if((k == dam_idam[j]) && (dam_type[j] == 0))
						{
							if(dam_zd[k] > zk0[k + 1]) //'08.6.6wadako������F!�_���������̉͏������V�[�������������߂�(8 / 5 / 27)
							{
								pxk[k] = g * (2 * (dam_zd[j] - hk0[k] - zk0[k]) / dxk); //'08.1.7�C���i�j�������Ă�
							}
						}
					}
				}

				if(pxk[k] > g) //'!it's new
				{
					pxk[k] = g;
				}

				if(pxk[k] < -g)
				{
					pxk[k] = -g;
				}

				//''!------------------------ BOTOM FRICTION ---------------masatsukou----------
				//''!       ca=(ck0(k+1)+ck0[k])*0.5
				if(uk0[k] >= 0.0)  //'!it's new
				{
					ca = ck0[k];
				}
				else
				{
					ca = ck0[k + 1];
				}

				//'!       hav=(hk0(k+1)+hk0[k])*0.5
				if(uk0[k] >= 0.0)
				{
					havk[k] = hk0[k];
				}
				else
				{
					havk[k] = hk0[k + 1];
				}

				if(ndam != 0)
				{
					for(j = 0;j < ndam;j++) //Base0 ����
					{
						if(k == dam_idam[j])
						{
							if((dam_type[j] == 0) || (dam_type[j] == 2))
							{
								if(zk0[k] >= dam_zd[j])
								{
									havk[k] = hk0[k];
								}
								else
								{
									if((hk0[k] + zk0[k]) >= (dam_zd[j] + hlimk))
									{
										havk[k] = hk0[k] + zk0[k] - dam_zd[j];
									}
									else
									{
										havk[k] = hmin;
									}
								}
							}
						}
					}
				}

				if(havk[k] <= hlimk)
				{
					fricx = 0.0;
				}
				else
				{
					if((ca <= 0.01) || (havk[k] / d >= 30.0))
					{
						fricx = g * nm * nm * uk0[k] * fabs(uk0[k]) / pow((double)(havk[k]), (double)(1.333333333)); // '!it's new  ��ΒlMath.Abs(uk0[k])
					}
					else
					{
						if(ca < csta * 0.4)
						{
							fricx = uk0[k] * fabs(uk0[k]) * d * d / (0.49 * havk[k] * havk[k] * havk[k]);
						}
						else
						{
							sita = 8.0 * (havk[k] * havk[k] * havk[k]) * (ca + (1.0 - ca) * rho / s) * pow((pow((double)(csta / ca), (double)(0.3333333)) - 1.0), 2);
							fricx = d * d * uk0[k] * fabs(uk0[k]) / sita;
						}
					}
				}

				//'!------------------------ NEW U CALCULATION --------------------------------
				ksum = -covex1 - pxk[k] - fricx;
				if(ksum > 2.0 * g)
				{
					ksum = 2.0 * g;
				}
				if(ksum < -2.0 * g)
				{
					ksum = -2.0 * g;
				}

				uk[k] = uk0[k] + dt * ksum;



				//'08.6.6wadako�ɕ�����
				if(ndam != 0)
				{
					for(j = 0;j < ndam;j++) //Base0 ����  ���̃v���O���������Ă���̂ł́H
					{
						if((k != dam_idam[j]) || ((k == dam_idam[j]) && (dam_type[j] == 1)))
						{
							if((uk[k] >= 0.0) && (hk0[k] <= hlimk))
							{
								uk[k] = 0.0;
							}
							if((uk[k] < 0.0) && (hk0[k + 1] <= hlimk))
							{
								uk[k] = 0.0;
							}
						}
						else
						{
							if(uk[k] < 0)
							{
								uk[k] = 0;
							}

							if(havk[k] < hlimk)
							{
								uk[k] = 0;
							}
						}
					}
				}
				else
				{
					if((uk[k] >= 0.0) && (hk0[k] <= hlimk))
					{
						uk[k] = 0.0;
					}

					if((uk[k] < 0.0) && (hk0[k + 1] <= hlimk))
					{
						uk[k] = 0.0;
					}
				}
			 //         '08.6.6�����܂�

				if(uk[k] > 50.0)
				{
					uk[k] = 50.0;
				}

				if(uk[k] < -50.0)
				{
					uk[k] = -50.0;
				}
			}

//150216 ��Q�C��
//			delete[] pxk;
//			delete[] havk;

			////UIN(); //'(qink1,dt,hlimk,kend)
			uk[0] = qink1 / (hk0[1] * bmk[0]); //Base0 ����


				//''! ------------------------ boundary conditions------------------------------
//			uk[kend - 2] = uk[kend - 2]; //Base0 ����
//			if(uk[kend - 2] < 0.0) //Base0 ����
//			{
//				uk[kend - 2] = 0.0; //Base0 ����
//			}

			//120720�C���@�|��~�X
			uk[kend - 1] = uk[kend - 2]; //Base0 ����
			if(uk[kend - 1] < 0.0) //Base0 ����
			{
				uk[kend - 1] = 0.0; //Base0 ����
			}


			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      sub suisin----------------hk
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////HHH(); //'(kend,dt,dxk,hlimk,hmin,qink1) '20131217:bmk��kosin��bbk���X�V����悤�ݒ�
			double dhdt, aa;

//140408 Debug�p ��Q
//			if(mstep == 32000)
//			{
//				printf("%ld\n",mstep);
//			}
			//'20131219�ǉ���������
			SS = (s / rho) - 1;
			sgd = SS * g * d;
//150216 ��Q�@�C��
			//ustark = new double[kend];
			//'20131219�ǉ������܂�

			for(k = 1;k < kend - 1;k++) //Base0 ���� ���Ӂ@���� k = 2
			{
				if(uk[k] >= 0.0)
				{
					if(hk0[k] <= hlimk)  //'!it's new    hlimk�P������̗�����臐��[
					{
						flxk[k] = 0.0;
					}
					else
					{
						flxk[k] = uk[k] * hk0[k] * bmk[k];
					}
				}
				else
				{
					if(hk0[k + 1] <= hlimk)
					{
						flxk[k] = 0.0;
					}
					else
					{
						flxk[k] = uk[k] * hk0[k + 1] * bmk[k];
					}
				}

				if(ndam != 0)
				{
					for(j = 0;j < ndam;j++) //Base0 ���� //' �_���t���b�N�X����
					{
						if(k == dam_idam[j])
						{
							if((dam_type[j] == 0) || (dam_type[j] == 2))
							{
								if(zk0[k] > dam_zd[j])
								{
									flxk[k] = uk[k] * hk0[k] * bmk[k];
								}
								else if((hk0[k] + zk0[k]) > (dam_zd[j] + hlimk))	//ElseIf ((hk0[k] + zk0[k]) > (dam_zd[j] + hlimk)) Then
								{
									flxk[k] = uk[k] * (hk0[k] + zk0[k] - dam_zd[j]) * bmk[k];
								}
								else
								{
									flxk[k] = 0;
								}
							}
							else if(dam_type[j] == 1) //'07.12.20;�a�c�N�Ɋm�F�I   //ElseIf dam_type[j] = 1 Then '07.12.20;�a�c�N�Ɋm�F�I
							{
								if((hk0[k] + zk0[k]) < dam_zd[j]) //'�_��kanako�ł̓_���͓����͂����Őݒ肷��
								{
									bmk[k] = dam_slit_width[j];
								}
								else
								{
									bmk[k] = (bbk[k] + bbk[k + 1]) * 0.5;
								}

								if(zk0[k] > dam_zd[j])
								{
									flxk[k] = uk[k] * hk0[k] * bmk[k];
								}
								else if((hk0[k] + zk0[k]) > (dam_zd[j] + hlimk)) //ElseIf ((hk0[k] + zk0[k]) > (dam_zd[j] + hlimk)) Then
								{
									flxk[k] = uk[k] * ((hk0[k] + zk0[k] - dam_zd[j]) * bmk[k] + (dam_zd[j] - zk0[k]) * bmk[k]); //'    !�_���������ς���
								}
								else
								{
									flxk[k] = uk[k] * hk0[k] * bmk[k];
								}
							} //'07.12.20;�a�c�N�Ɋm�F�I
						}
					}
				}
			}

			//''!------------------------boundary condition-----------------------------
			//140926���炩�ȊԈႢ����  [kend - 2] -> [kend - 1]
			flxk[0] = qink1; //Base0 ����
			if((uk[kend - 1] >= 0.0) && (hk[kend - 1] > hlimk)) //Base0 ����
			{
				flxk[kend - 1] = uk[kend - 1] * hk0[kend - 1] * bmk[kend - 1]; //Base0 ����
			}
			else
			{
				flxk[kend - 1] = 0.0; //Base0 ����
			}

			//''!-----------------------------------------------------------------------
			//'       do 30 k=2,kend-1     '!hk(kend)�͂Q��������������炤�̂Ōv�Z����K�v�Ȃ�
			for(k = 1;k < kend - 1;k++) //Base0 ���� ���Ӂ@���� k = 2
			{
				aa = dt / (dxk * bbk[k]);
				dhdt = aa * (flxk[k - 1] - flxk[k]);

				if((hk0[k] <= hmin) && ((dhdt + eetk[k] * dt) < 0.0))
				{
					hk[k] = hk0[k];
										//'!        if(zk[k]<zsk[k])then        '!����܂���
										//'!          zk[k]=zsk[k]
										//'!        end if
					eetk[k] = (hk[k] - hk0[k] - dhdt) / dt; //'!eetk�̍Čv�Z

					//'20131219�ǉ���������'!sokugan_eetk�̍Čv�Z
					if(landslide_dam_number > 0)
					{
						for(int j = 0;j < landslide_dam_number;j++)
						{
							if((k == landslide_dam_position[j]) && (bbk0[k] < landslide_dam_width[j]))
							{
								if(eetk[k] > 0)
								{
									ustark[k] = pow((g * hk[k] * thek[k]),0.5);
									sokugan_eetk[k] = delta_se * (0.005 * pow(ustark[k],2)) / (pow(sgd, 0.5));
									// 	sokugan_eetk(k) = delta_se * (0.005 * (ustark(k) ^ 2) / (sgd ^ 0.5))

									if(sokugan_eetk[k] < 0)
									{
										sokugan_eetk[k] = 0;
									}

									//20140606�␳��ǉ�
									if(sokugan_eetk[k] > (landslide_dam_width[j] - bbk0[k]) / (2.0 * dt))
									{
										sokugan_eetk[k] = (landslide_dam_width[j] - bbk0[k]) / (2.0 * dt);
									}

									if(landslide_dam_width[j] <= bbk0[k])
									{
										sokugan_eetk[k] = 0;
									}
									//20140606�␳��ǉ������܂�
								}
								else
								{
								//20140409�ǉ� ��Q
									sokugan_eetk[k] = 0;
								//20140409�ǉ������܂�
								}
							}
						}
					}
					else
					{
						sokugan_eetk[k] = 0;
					}
					//'20131219�ǉ������܂�
				}
				else
				{
					if((eetk[k] > 0) && (sokugan_eetk[k] > 0) && ((zk0[k] - zk[k]) > 0)) //'20131217�ǉ�
					{
						hk[k] = hk0[k] + dhdt + eetk[k] * dt + 2 * (zk0[k] - zk[k]) / bbk[k] * sokugan_eetk[k] * dt;   //20131217�F���ݐN�H����̑S�̘̂A����:
					}
					else
					{
						hk[k] = hk0[k] + dhdt + eetk[k] * dt; //'20131217�F���ݐN�H�Ȃ��̂Ƃ��̑S�̘̂A����
					}
					// '20131217�ǉ������܂�

					if(hk[k] <= hmin)
					{
						hk[k] = hmin;
												//'!        if(zk[k]<zsk[k])then         '!����܂���
												//'!         zk[k]=zsk[k]
											 //'!        end if
						eetk[k] = (hk[k] - hk0[k] - dhdt) / dt; //'!eetk�̍Čv�Z

						//'20131219�ǉ���������'!sokugan_eetk�̍Čv�Z
						if(landslide_dam_number > 0)
						{
							for(int j = 0;j < landslide_dam_number;j++)
							{
								if((k == landslide_dam_position[j]) && (bbk0[k] < landslide_dam_width[j]))
								{
									if(eetk[k] > 0)
									{
										ustark[k] = pow((g * hk[k] * thek[k]),0.5);
										sokugan_eetk[k] = delta_se * (0.005 * pow(ustark[k],2)) / (pow(sgd, 0.5));
										if(sokugan_eetk[k] < 0)
										{
											sokugan_eetk[k] = 0;
										}
									}
								}
							}
						}
						else
						{
							sokugan_eetk[k] = 0;
						}
						//'20131219�ǉ������܂�
					}
				}
			}

			//''!---------------------------boundary conditions-----------------------------
			hk[0] = hk[1]; //Base0 ����
			//''!---------------------------------------------------------------------------
			//'       return

			for(i = 0;i < kend;i++) //Base0 ����
			{
				if(hk[i] > hmin)
				{
					flag1[i] = 1; //'hk��hmin��������t���O��1�ɏ��������i���̂Ƃ��냊�Z�b�g�͖����I�j
				}
			}

			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      sub nodo---------------ck
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////CCC(); //'(kend,csta,dt,dxk,hlimk,hmin,qink1,cink1)  '20131217:bmk��kosin��bbk���X�V����悤�ݒ�
			double dcc;

			for(k = 1;k < kend - 1;k++) //Base0 ���� ���Ӂ@���� k = 2
			{
				if(uk[k] >= 0.0)
				{
					if(hk[k] <= hlimk)   // '!it's new   hlimk
					{
						cflxk[k] = 0.0;
					}
					else
					{
						cflxk[k] = ck0[k] * uk[k] * hk[k] * bmk[k];
					}
				}
				else
				{
					if(hk[k + 1] <= hlimk)
					{
						cflxk[k] = 0.0;
					}
					else
					{
						cflxk[k] = ck0[k + 1] * uk[k] * hk[k + 1] * bmk[k];
					}
				}

				//'07.12.20�ǉ��i�a�c�N�Ɋm�F�I�j
				if(ndam != 0)
				{
					for(j = 0;j < ndam;j++) //Base0 ���� //'                        !�_��c�t���b�N�X����
					{
						if(k == dam_idam[j])
						{
							if((dam_type[j] == 0) || (dam_type[j] == 2))
							{
								if(zk0[k] > dam_zd[j])
								{
									cflxk[k] = ck0[k] * uk[k] * hk[k] * bmk[k];
								}
								else if((hk[k] + zk0[k]) > (dam_zd[j] + hlimk)) //ElseIf ((hk[k] + zk0[k]) > (dam_zd[j] + hlimk)) Then
								{
									cflxk[k] = ck0[k] * uk[k] * (hk[k] + zk0[k] - dam_zd[j]) * bmk[k];
								}
								else
								{
									cflxk[k] = 0.0;
								}
							}
							else if(dam_type[j] == 1)			 //ElseIf dam_type[j] = 1 Then
							{
								if((hk[k] + zk0[k]) < dam_zd[j]) //'!�_��kanako�ł̓_���͓����͂����Őݒ�()
								{
									bmk[k] = dam_slit_width[j];
								}
								else
								{
									bmk[k] = (bbk[k] + bbk[k + 1]) * 0.5;
								}

								if(zk0[k] > dam_zd[j])
								{
									cflxk[k] = ck0[k] * uk[k] * hk[k] * bmk[k];
								}
								else if((hk[k] + zk0[k]) > (dam_zd[j] + hlimk)) //ElseIf ((hk[k] + zk0[k]) > (dam_zd[j] + hlimk)) Then
								{
									cflxk[k] = ck0[k] * uk[k] * ((hk[k] + zk0[k] - dam_zd[j]) * bmk[k] + (dam_zd[j] - zk0[k]) * bmk[k]); //!�_���������ς���
								}
								else
								{
									cflxk[k] = ck0[k] * uk[k] * hk[k] * bmk[k];
								}
							}
						}
					}
				}
			}

			//''!------------------------boundary condition-----------------------------
			cflxk[0] = qink1 * cink1; //Base0 ����
// 140326�@��Q�@�C���@���S�ȃo�O
			if((uk[kend - 1] >= 0.0) && (hk[kend - 1] > hlimk)) //Base0 ����
			{
				cflxk[kend - 1] = ck0[kend - 1] * uk[kend - 1] * hk[kend - 1] * bmk[kend - 1]; //Base0 ����
			}
			else
			{
				cflxk[kend - 1] = 0.0; //Base0 ����
			}
			//''!-----------------------------------------------------------------------
			//'       do 30 k=2,kend      '!it's new   ck(kend)�͌v�Z����ׂ�
			for(k = 1;k < kend;k++) //Base0 ���� ���Ӂ@���� k = 2
			{
				dcc = (cflxk[k - 1] - cflxk[k]) / (dxk * bbk[k]);
				if(hk[k] <= hmin)
				{
										//'  If (hk[k] <= 0.0100000001) Then'07.10.11���̕��������H
					ck[k] = 0.0;
					if(ck[kend - 2] == 0.0) //Base0 ����
					{
						kakunin = 1; // '07.10.12
					}
					eetk[k] = (ck[k] * hk[k] - ck0[k] * hk0[k] - dcc * dt) / (csta * dt); //'!eetk�̍Čv�Z
				}
				else
				{
					if((eetk[k] > 0) && (sokugan_eetk[k] > 0) && ((zk0[k] - zk[k]) > 0)) // '20131217�ǉ�
					{
						ck[k] = (ck0[k] * hk0[k] + (dcc + eetk[k] * csta + 2 * (zk0[k] - zk[k]) / bbk[k] * sokugan_eetk[k] * csta) * dt) / hk[k]; // '20131217�F���ݐN�H����̑S�̘̂A����
					}
					else
					{
						ck[k] = (ck0[k] * hk0[k] + (dcc + eetk[k] * csta) * dt) / hk[k]; //'20131217�F���ݐN�H�Ȃ��̂Ƃ��̑S�̘̂A����
					}
					// '20131217�ǉ������܂�

					if(ck[k] < 0.0)
					{
						ck[k] = 0.0;
						if(ck[kend - 1] == 0.0) //Base0 ����
						{
							kakunin = 2; //'07.10.12
						}
						eetk[k] = (ck[k] * hk[k] - ck0[k] * hk0[k] - dcc * dt) / (csta * dt); //'!eetk�̍Čv�Z
					}

					if(ck[k] > csta * 0.9) //'!it's new  �Z�x�̏��csta*0.999
					{
						ck[k] = csta * 0.9;
						eetk[k] = (ck[k] * hk[k] - ck0[k] * hk0[k] - dcc * dt) / (csta * dt); //'!eetk�̍Čv�Z
					}
				}
			}

			//''!---------------------------boundary conditions-----------------------------
			ck[0] = ck[1]; //Base0 ����

			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      sub kasyo--------------zk
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////ZZZ(); //'(kend,dt)     '20131217:�앝�̕ω���ǉ�
			//'       do 10 k=1,kend-1      '!z(kend)�͂Q��������������炤�̂Ōv�Z����K�v�Ȃ�
			for(k = 0;k < kend - 1;k++) //Base0 ����
			{
				zk[k] = zk0[k] - eetk[k] * dt;
				if(zsk[k] > zk[k])
				{
					zk[k] = zsk[k];
				}

				//'20131217�ǉ�
				if(landslide_dam_number > 0)
				{
					for(int j = 0;j < landslide_dam_number;j++)
					{
// 150609 �C��
//						if((landslide_dam_position[j] == k) && (landslide_dam_width[j] > bbk[k]) && (sokugan_eetk[k] > 0))
//						{
//							bbk[k] = bbk0[k] + (2 * sokugan_eetk[k] * dt); //'�N�H���͂����ɂ���Ȃ����H(/(zk0(k)) - zk(k)) )
//						}
//						else
//						{
//							bbk[k] = bbk0[k];
//						}

						if(landslide_dam_position[j] == k)
						{
							if((landslide_dam_width[j] > bbk[k]) && (sokugan_eetk[k] > 0))
							{
									bbk[k] = bbk0[k] + (2 * sokugan_eetk[k] * dt); //'�N�H���͂����ɂ���Ȃ����H(/(zk0(k)) - zk(k)) )

									if(bbk0[k] > bbk[k])
									{
										double d1 = RyusyutuA * bbk[k] * bbk[k] + RyusyutuB * bbk[k] + RyusyutuC;
										double d2 = RyusyutuA * bbk0[k] * bbk0[k] + RyusyutuB * bbk0[k] + RyusyutuC;

										bbksabun[k] = d2 - d1;
									}
									else
									{
										bbksabun[k] = 0.0;
									}
							}
							else
							{
//								bbk[k] = 0.0;
								bbk[k] = bbk0[k];
							}
						}
					}
				}
				//'20131217�ǉ������܂�
			}





			////keisan_2D()
			//'!-------------------jouken 1--------------------------
			//'!�Q�����v�Z�ł̗��������i�P������iend-1�j����������

//			if(nhaba >= 3)
//			{
//				//Base0 ����
//				qin = hk[kend - 2] * uk[kend - 2] * dy * cos(muki) * abs(cos(muki)); //'08.6.6wadako�C���ɕ����ĕύX
//				qinh = hk[kend - 2] * uk[kend - 2] * hashi * cos(muki) * abs(cos(muki));
//				qinv = -hk[kend - 2] * uk[kend - 2] * dy * sin(muki) * abs(sin(muki)); //'08.6.6�����܂�
//				cin_w = ck[kend - 2] * qin / dy;
//				cinh = ck[kend - 2] * qinh / dy;
//				cinv = ck[kend - 2] * qinv / dx;
//			}
//			else
//			{
//				//Base0 ����
//				qin = hk[kend - 2] * uk[kend - 2] * b0 * cos(muki) * abs(cos(muki)); //'08.6.6wadako�C���ɕ����ĕύX
//				qinv = -hk[kend - 2] * uk[kend - 2] * b0 * sin(muki) * abs(sin(muki)); // 2.0;'08.6.6�����܂�
//				cin_w = ck[kend - 2] * qin / dy;
//				cinv = ck[kend - 2] * qinv / dx;
//			}

				//20130507�C��:muki��rad_muki�ɁF��������
			if(nhaba >= 3)
			{
				//Base0 ����
				qin = hk[kend - 2] * uk[kend - 2] * dy * cos(rad_muki) * fabs(cos(rad_muki)); //'08.6.6wadako�C���ɕ����ĕύX
				qinh = hk[kend - 2] * uk[kend - 2] * hashi * cos(rad_muki) * fabs(cos(rad_muki));
				qinv = -hk[kend - 2] * uk[kend - 2] * dy * sin(rad_muki) * fabs(sin(rad_muki)); //'08.6.6�����܂�
				cin_w = ck[kend - 2] * qin / dy;
				cinh = ck[kend - 2] * qinh / dy;
				cinv = ck[kend - 2] * qinv / dx;
			}
			else
			{
				//Base0 ����
				qin = hk[kend - 2] * uk[kend - 2] * b0 * cos(rad_muki) * fabs(cos(rad_muki)); //'08.6.6wadako�C���ɕ����ĕύX
				qinv = -hk[kend - 2] * uk[kend - 2] * b0 * sin(rad_muki) * fabs(sin(rad_muki)); // 2.0;'08.6.6�����܂�
				cin_w = ck[kend - 2] * qin / dy;
				cinv = ck[kend - 2] * qinv / dx;
			}
//				If nhaba >= 3 Then
//						qin = hk(kend - 1) * uk(kend - 1) * dy * Math.Cos(rad_muki) * Math.Abs(Math.Cos(rad_muki)) '08.6.6wadako�C���ɕ����ĕύX
//						qinh = hk(kend - 1) * uk(kend - 1) * hashi * Math.Cos(rad_muki) * Math.Abs(Math.Cos(rad_muki))
//						qinv = -hk(kend - 1) * uk(kend - 1) * dy * Math.Sin(rad_muki) * Math.Abs(Math.Sin(rad_muki)) '08.6.6�����܂�
//						cin = ck(kend - 1) * qin / dy
//						cinh = ck(kend - 1) * qinh / dy
//						cinv = ck(kend - 1) * qinv / dx
//				Else
//						qin = hk(kend - 1) * uk(kend - 1) * b0 * Math.Cos(rad_muki) * Math.Abs(Math.Cos(rad_muki)) '08.6.6wadako�C���ɕ����ĕύX
//						qinv = -hk(kend - 1) * uk(kend - 1) * b0 * Math.Sin(rad_muki) * Math.Abs(Math.Sin(rad_muki)) / 2 '08.6.6�����܂�
//						cin = ck(kend - 1) * qin / dy
//						cinv = ck(kend - 1) * qinv / dx
//				End If
				//20130507�C��:muki��rad_muki�ɁF�����܂�


			if(uk[kend - 2] <= 0) //Base0 ����
			{
				qin = 0;
				qinh = 0;
				qinv = 0;
				cin_w = 0;
				cinh = 0;
				cinv = 0;
			}

			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//'!      hmax & ruiseki qout keisan
			//'!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			hkmax = 0;
			for(k = 0;k < kend;k++) //Base0 ����
			{
				if(hk[k] > hkmax)
				{
					hkmax = hk[k];
					hkmaxk = k;
				}
			}

			if(uk[kend - 2] >= 0) //Base0 ���� ���Ӂ@���� [kend - 1]
			{
				qinkk = uk[kend - 2] * hk[kend - 2]; //Base0 ���� ���Ӂ@���� [kend - 1]
				cinkk = uk[kend - 2] * hk[kend - 2] * ck[kend - 2]; //Base0 ���� ���Ӂ@���� [kend - 1]
			}
			else
			{
				qinkk = 0;
				cinkk = 0;
			}
			qinkkall = qinkkall + qinkk * bmk[kend - 2] * dt; //Base0 ���� ���Ӂ@���� [kend - 1]
			cinkkall = cinkkall + cinkk * bmk[kend - 2] * dt; //Base0 ���� ���Ӂ@���� [kend - 1]

			if((mstep + qoutstep / 2) % (qoutstep) == 0)
			{
				qinkkout = (qinkkall - qinkkallold) / (dt * double(qoutstep));
				cinkkout = (cinkkall - cinkkallold) / (dt * double(qoutstep));
				qinkkallold = qinkkall;
				cinkkallold = cinkkall;
			}

			//140514 1�����̂݌v�Z�����@��Q
			if(bNiji == false)
			{
				goto KEISAN_2D1D;
			}

			//nijigen();
			if(mode == 0)
			{
				goto KEISAN_2D1D;
			}

			if(flag1[kend - 2] != 1) //Base0 ���� ���Ӂ@���� [kend - 1] //'07.10.17�ǉ��iflag1��2�������[�v�ɓ��邩�ۂ�������j
			{
				goto KEISAN_2D1D;
			}

			////niji_counter++;

			//''!***************************************************************************
			//''!      main program
			//''!***************************************************************************

			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      kosin
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			for(i = 0;i < iend;i++) //Base0 ����
			{
				for(j = 0;j < jend;j++) //Base0 ����
				{
					z0[i][j] = z[i][j];
					h0[i][j] = h[i][j];
					u0[i][j] = u[i][j];
					v0[i][j] = v[i][j];
					c0[i][j] = c[i][j];
				}
			}


			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(h[i][j] > hmin) //'07.10.17�ǉ��Fhmin��������flag��1�ɁAhmin�̂Ƃ���0��
					{
						//'07.10.17�ǉ��Fflag2(i,j)�����łȂ��A������͂�4�_��flag��1�ɕύX
						flag2[i][j] = 1;
						flag2[i + 1][j] = 1;
						flag2[i][j - 1] = 1;
						flag2[i][j + 1] = 1;
						flag2[i - 1][j] = 1;
					}
					else
					{
						flag2[i][j] = 0;
					}
				}
			}

			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub u,v heikin-------------ua,va,uL
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NIuvave(); //'(hmin,iend,jend,nhaba,jc)
			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0) //' goto 20�ɑΉ������邽��if���ς���
						{
							if(h0[i][j] <= hmin)  //'!it's new  �Q������ł�hmin��hlim�Ɠ���
							{
								ua[i][j] = 0.0;
								va[i][j] = 0.0;
							}
							else
							{
								ua[i][j] = (u0[i - 1][j] + u0[i][j]) * 0.5;
								va[i][j] = (v0[i][j - 1] + v0[i][j]) * 0.5;
							}
						}
					}
				}
			}

			//''!---------------boundary conditions ---------------
			for(j = 0;j < jend;j++) //Base0 ����
			{
				ua[0][j] = 0.0; //Base0 ����
				ua[iend - 1][j] = ua[iend - 2][j]; //Base0 ����
				va[0][j] = 0.0; //Base0 ����
				va[iend - 1][j] = 0.0; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				ua[i][0] = 0.0; //Base0 ����
				ua[i][jend - 1] = 0.0; //Base0 ����
				va[i][0] = va[i][1]; //Base0 ����
				va[i][jend - 1] = va[i][jend - 2]; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				for(j = 0;j < jend;j++) //Base0 ����
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag21�Ŕ���j
					{
						if(id[i][j] != 0)
						{
								uL[i][j] = sqrt((ua[i][j] * ua[i][j] + va[i][j] * va[i][j])); //uL[i][j] = (ua[i][j] * ua[i][j] + va[i][j] * va[i][j]) ^ 0.5
						}
					}
				}
			}

			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub oudankobai-----------dzdn
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NIdzdncal(); //'(dx,dy,slmax,iend,jend,nhaba,jc)
			double beta1, dzdy, dzdx;

			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							if((uL[i][j] > -0.00000000001) && (uL[i][j] < 0.00000000001))
							{
								dzdn[i][j] = 0.0;
							}
							else
							{
								if(ua[i][j] >= 0.0)
								{
									beta1 = asin(va[i][j] / uL[i][j]);
								}
								else
								{
									beta1 = -asin(va[i][j] / uL[i][j]) + 3.14159265359;
								}

								if(va[i][j] == 0.0)
								{
									dzdy = (z0[i][j - 1] + h0[i][j - 1] - z0[i][j + 1] - h0[i][j + 1]) / (dy * 2.0);
								}
								else
								{
									if(va[i][j] < 0.0)
									{
										dzdy = (z0[i][j - 1] + h0[i][j - 1] - z0[i][j] - h0[i][j]) / dy;
									}
									else
									{
										dzdy = (z0[i][j] + h0[i][j] - z0[i][j + 1] - h0[i][j + 1]) / dy;
									}
								}

								if(dzdy > slmax)
								{
									dzdy = slmax;
								}
								if(dzdy < -slmax)
								{
									dzdy = -slmax;
								}

								if(ua[i][j] == 0.0)
								{
									dzdx = (z0[i - 1][j] + h0[i - 1][j] - z0[i + 1][j] - h0[i + 1][j]) / (2.0 * dx);
								}
								else
								{
									if(ua[i][j] < 0.0)
									{
										dzdx = (z0[i - 1][j] + h0[i - 1][j] - z0[i][j] - h0[i][j]) / dx;
									}
									else
									{
										dzdx = (z0[i][j] + h0[i][j] - z0[i + 1][j] - h0[i + 1][j]) / dx;
									}
								}

								if(dzdx > slmax)
								{
									dzdx = slmax;
								}
								if(dzdx < -slmax)
								{
									dzdx = -slmax;
								}

								dzdn[i][j] = cos(beta1) * dzdx + sin(beta1) * dzdy;

								if(dzdn[i][j] > slmax)
								{
									dzdn[i][j] = slmax;
								}
								if(dzdn[i][j] < -slmax)
								{
									dzdn[i][j] = -slmax;
								}
							}
						}
					}
				}
			}


			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub sinsyokusokudo---------eet
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NIerosion(); //'(iend,jend,rho,s,g,d,hmin,deltae,deltad,pi,csta,dx,dy,nhaba,jc,dt)

// 130628 �C��
//			tanf = tan(37.0 / 180.0 * 3.14159265358);
				tanf = tan(fai / 180.0 * 3.14159265358); // '20130507�C���O
//				'   tanf = Math.Tan(37.0 / 180.0 * 3.14159265358) '!kanako�ł�tanf=0.7'20130507�C���O�i37�x�ŌŒ�j

			f1 = rho / (s - rho);
			f2 = 6.7 * f1 * f1;
			f3 = s / (s - rho);

			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							//''!----------------------------cmug keisan----------------------------------------
							if(dzdn[i][j] >= tanf * 0.99)
							{
								cmug[i][j] = csta * 0.9;
							}
							else
							{
								if(dzdn[i][j] > 0.138)
								{
									cmug[i][j] = f1 * dzdn[i][j] / (tanf - dzdn[i][j]);
								}
								else
								{
									if(dzdn[i][j] > 0.03)
									{
										cmug[i][j] = f2 * dzdn[i][j] * dzdn[i][j] / ((tanf - dzdn[i][j]) * (tanf - dzdn[i][j]));    //cmug[i][j] = f2 * dzdn[i][j] * dzdn[i][j] / (tanf - dzdn[i][j]) ^ 2
									}
									else
									{
										tsc = 0.04 * pow(10.0,1.72 * dzdn[i][j]);  //
										ts = h0[i][j] * dzdn[i][j] * f1 / d;
										if(ts <= tsc)
										{
											cmug[i][j] = 0.0;
										}
										else
										{
											al2 = 2.0 * (0.425 - f3 * dzdn[i][j]) / (1.0 - f3 * dzdn[i][j]);
											al = sqrt(al2);  //al = al2 ^ 0.5
											f4 = (1.0 + 5.0 * dzdn[i][j]) * dzdn[i][j] * f1;
											f5 = (1.0 - al2 * tsc / ts) * (1.0 - al * sqrt(tsc / ts));   //f5 = (1.0 - al2 * tsc / ts) * (1.0 - al * (tsc / ts) ^ 0.5)
											cmug[i][j] = f4 * f5;
										}
									}
								}
							}

							if(cmug[i][j] < 0.0)
							{
								cmug[i][j] = 0.0;
							}
							if(cmug[i][j] > csta * 0.9)
							{
								cmug[i][j] = csta * 0.9;
							}
							if((uL[i][j] <= 0.01) || (h0[i][j] <= hmin))
							{
								cmug[i][j] = 0.0;
							}

							//''!------------------------------sinsyoku taiseki----------------------------------
							if(cmug[i][j] >= c0[i][j])
							{
								eet[i][j] = deltae * (cmug[i][j] - c0[i][j]) / (csta - cmug[i][j]) * fabs(uL[i][j]) * h0[i][j] / d;
								if(eet[i][j] > (z0[i][j] - zs[i][j]) / dt) // '08.1.18;�s�����t�������iwadako�ɂāj�̂��C���I�I
								{
									eet[i][j] = (z0[i][j] - zs[i][j]) / dt;
								}
								if(z0[i][j] <= zs[i][j])
								{
									eet[i][j] = 0.0;
								}
							}
							else
							{
								eet[i][j] = deltad * (cmug[i][j] - c0[i][j]) / csta * fabs(uL[i][j]);
							}
						}
					} //End If '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			//''! ------------------ boundary conditions ---------------------------
			for(j = 0;j < jend;j++) //Base0 ����
			{
				eet[0][j] = 0.0; //Base0 ����
				eet[iend - 1][j] = eet[iend - 2][j]; //Base0 ����
			}

			//for(j = (jc - (nhaba - 1) / 2);j <= (jc + (nhaba - 1) / 2);j++)
			for(j = (jc - (nhaba - 1) / 2) - 1;j < (jc + (nhaba - 1) / 2);j++) //Base0 ����
			{
				//''!�����ʂ����i�����P�̗�j�ɗ���邩��
				eet[0][j] = eet[1][j]; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				eet[i][0] = eet[i][1];
				eet[i][jend - 1] = eet[i][jend - 2]; //Base0 ����
			}

			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub ryusoku---------------u,v
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NIUV(); //'(iend,jend,nhaba,jc,csta,dx,dy,g,hlim,dt,qin,qinh,qinv,qinvh,nm,rho,s,d)	//''! -------------------------------------u&v cal------------------------------

			////NIUUU(); //'(iend,jend,dx,dy,g,hlim,csta,dt,nm,rho,s,d)
			double covex2, px;
			double hav, bunbo;

			//'2010.6.11Nakatani�ǉ���������F������
			for(i = 0;i < iend;i++) //Base0 ����
			{
				for(j = 0;j < jend;j++) //Base0 ����
				{
					vm_NIUUU[i][j] = 0.0;
				}
			}

			//'2010.6.11Nakatani�ǉ������܂ŁF������

			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							vm_NIUUU[i][j] = (v0[i][j] + v0[i + 1][j] + v0[i + 1][j - 1] + v0[i][j - 1]) * 0.25;  //'2010.6.11Nakatani���̍s�ύX�Fvm(300, 300)�� vm_NIUUU[i][j]
						}
					} //End if'07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			//for(i = 2;i <= iend - 2;i++)
			for(i = 1;i < iend - 2;i++)  //Base0 ����
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
					//''!------------------------- CONVECT TERM -----------henbibun-----------------
						if(u0[i][j] > 0.0)
						{
							covex1 = u0[i][j] * (u0[i][j] - u0[i - 1][j]) / dx;
						}
						else
						{
							covex1 = u0[i][j] * (u0[i + 1][j] - u0[i][j]) / dx;
						}

						if(vm_NIUUU[i][j] > 0.0)   //'2010.6.11Nakatani���̍s�ύX�Fvm(300, 300)�� vm_NIUUU[i][j]
						{
							covex2 = vm_NIUUU[i][j] * (u0[i][j] - u0[i][j - 1]) / dy; //'2010.6.11Nakatani���̍s�ύX�Fvm(300, 300)�� vm_NIUUU[i][j]
						}
						else
						{
							covex2 = vm_NIUUU[i][j] * (u0[i][j + 1] - u0[i][j]) / dy; //'2010.6.11Nakatani���̍s�ύX�Fvm(300, 300)�� vm_NIUUU[i][j]
						}

						//''!------------------------ PRESSURE TERM ------------atsuryokukou------------
						p2 = g * (h0[i + 1][j] + z0[i + 1][j]);
						p1 = g * (h0[i][j] + z0[i][j]);
						px = (p2 - p1) / dx;
						if(px > g)
						{
							px = g;
						}
						if(px < -g)
						{
							px = -g;
						}

						//''!------------------------ BOTOM FRICTION ---------------masatsukou----------
						ca = (c0[i][j] + c0[i + 1][j]) * 0.5;
						bunbo = sqrt(u0[i][j] * u0[i][j] + vm_NIUUU[i][j] * vm_NIUUU[i][j]);  //bunbo = (u0[i][j] * u0[i][j] + vm_NIUUU[i][j] * vm_NIUUU[i][j]) ^ 0.5'2010.6.11Nakatani���̍s�ύX�Fvm(300, 300)�� vm_NIUUU[i][j]
						hav = (h0[i + 1][j] + h0[i][j]) * 0.5; //hav = (h0[i + 1][j] + h0[i][j]) * 0.5

						if(hav <= hlim)
						{
							fricx = 0.0;
						}
						else
						{
							if((ca <= 0.01) || (hav / d >= 30.0))
							{
								fricx = g * nm * nm * u0[i][j] * bunbo / pow((double)hav,(double)(1.333333333));
							}
							else
							{
								if(ca < csta * 0.4)
								{
									fricx = u0[i][j] * bunbo * d * d / (0.49 * hav * hav * hav);
								}
								else
								{
									sita = 8.0 * (hav * hav * hav) * (ca + (1.0 - ca) * rho / s) * pow((pow((double)(csta / ca),(double)(0.3333333)) - 1.0),2.0);  //sita = 8.0 * (hav * hav * hav) * (ca + (1.0 - ca) * rho / s) * ((csta / ca) ^ 0.3333333 - 1.0) ^ 2
									fricx = d * d * u0[i][j] * bunbo / sita;
								}
							}
						}

						//''!------------------------ NEW U CALCULATION --------------------------------
						ksum = -covex1 - covex2 - px - fricx;
						if(ksum > 2.0 * g)
						{
							ksum = 2.0 * g;
						}
						if(ksum < -2.0 * g)
						{
							ksum = -2.0 * g;
						}

						u[i][j] = u0[i][j] + dt * ksum;

						if((u[i][j] >= 0.0) && (h0[i][j] <= hlim))
						{
							u[i][j] = 0.0;
						}
						if((u[i][j] < 0.0) && (h0[i + 1][j] <= hlim))
						{
							u[i][j] = 0.0;
						}
						if(u[i][j] > 50.0)
						{
							u[i][j] = 50.0;
						}
						if(u[i][j] < -50.0)
						{
							u[i][j] = -50.0;
						}
					}		//End if '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			////NIVVV(); //'(iend,jend,dx,dy,g,hlim,csta,dt,nm,rho,s,d)
			double py;

			//'2010.6.11Nakatani�ǉ���������F������
			for(i = 0;i < iend;i++) //Base0 ����
			{
				for(j = 0;j < jend;j++) //Base0 ����
				{
					um_NIVVV[i][j] = 0.0;
				}
			}
			//'2010.6.11Nakatani�ǉ������܂ŁF������

			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							um_NIVVV[i][j] = (u0[i][j] + u0[i][j + 1] + u0[i - 1][j] + u0[i - 1][j + 1]) * 0.25;  //'2010.6.11Nakatani���̍s�ύX�Fum(300, 300)�� um_NIVVV[i][j]
						}
					}		//End if '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				//for(j = 2;j <= jend - 2;j++)
				for(j = 1;j < jend - 2;j++)  //Base0 ����
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						//''!------------------------- CONVECT TERM -----------henbibun-----------------
						if(um_NIVVV[i][j] > 0.0) //'2010.6.11Nakatani���̍s�ύX�Fum(300, 300)�� um_NIVVV[i][j]
						{
							covex1 = um_NIVVV[i][j] * (v0[i][j] - v0[i - 1][j]) / dx; //'2010.6.11Nakatani���̍s�ύX�Fum(300, 300)�� um_NIVVV[i][j]
						}
						else
						{
							covex1 = um_NIVVV[i][j] * (v0[i + 1][j] - v0[i][j]) / dx; //'2010.6.11Nakatani���̍s�ύX�Fum(300, 300)�� um_NIVVV[i][j]
						}
						if(v0[i][j] > 0.0)
						{
							covex2 = v0[i][j] * (v0[i][j] - v0[i][j - 1]) / dy;
						}
						else
						{
							covex2 = v0[i][j] * (v0[i][j + 1] - v0[i][j]) / dy;
						}

						//''!------------------------ PRESSURE TERM ------------atsuryokukou------------
						p2 = g * (h0[i][j + 1] + z0[i][j + 1]);
						p1 = g * (h0[i][j] + z0[i][j]);
						py = (p2 - p1) / dy;
						if(py > g)
						{
							py = g;
						}
						if(py < -g)
						{
							py = -g;
						}

						//''!------------------------ BOTOM FRICTION ---------------masatsukou----------
						ca = (c0[i][j + 1] + c0[i][j]) * 0.5;
						bunbo = sqrt(um_NIVVV[i][j] * um_NIVVV[i][j] + v0[i][j] * v0[i][j]); //bunbo = (um_NIVVV[i][j] * um_NIVVV[i][j] + v0[i][j] * v0[i][j]) ^ 0.5  '2010.6.11Nakatani���̍s�ύX�Fum(300, 300)�� um_NIVVV[i][j]
						hav = (h0[i][j + 1] + h0[i][j]) * 0.5;

						if(hav <= hlim)
						{
							fricx = 0.0;
						}
						else
						{
							if((ca <= 0.01) || (hav / d >= 30.0))
							{
								fricx = g * nm * nm * v0[i][j] * bunbo / pow((double)hav,(double)(1.333333333));
							}
							else
							{
								if(ca < csta * 0.4)
								{
									fricx = v0[i][j] * bunbo * d * d / (0.49 * hav * hav * hav);
								}
								else
								{
									sita = 8.0 * (hav * hav * hav) * (ca + (1.0 - ca) * rho / s) * pow((pow((double)(csta / ca),(double)(0.3333333)) - 1.0),2.0); //sita = 8.0 * (hav * hav * hav) * (ca + (1.0 - ca) * rho / s) * ((csta / ca) ^ 0.3333333 - 1.0) ^ 2
									fricx = d * d * v0[i][j] * bunbo / sita;
								}
							}
						}

						//''!------------------------ NEW V CALCULATION --------------------------------
						ksum = -covex1 - covex2 - py - fricx;
						if(ksum > 2.0 * g)
						{
							ksum = 2.0 * g;
						}
						if(ksum < -2.0 * g)
						{
							ksum = -2.0 * g;
						}

						v[i][j] = v0[i][j] + dt * ksum;

						if((v[i][j] >= 0.0) && (h0[i][j] <= hlim))
						{
							v[i][j] = 0.0;
						}
						if((v[i][j] < 0.0) && (h0[i][j + 1] <= hlim))
						{
							v[i][j] = 0.0;
						}
						if(v[i][j] > 200.0)
						{
							v[i][j] = 200.0;
						}
						if(v[i][j] < -200.0)
						{
							v[i][j] = -200.0;
						}
					} //End if  '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			////NIUIN(); //'(iend,jend,nhaba,jc,dx,dy,g,hlim,csta,dt,nm,rho,s,d,qin,qinh,qinv,qinvh)
			if(nhaba >= 3)
			{
				//for(j = (jc - (nhaba - 3) / 2);j <= (jc + (nhaba - 3) / 2);j++)
				for(j = (jc - (nhaba - 3) / 2) - 1;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
				{
					u[0][j] = qin / h0[1][j] / dy; //Base0 ����
				}

				u[0][(jc - (nhaba - 1) / 2) - 1] = qinh / h0[1][(jc - (nhaba - 1) / 2) - 1] / dy; //Base0 ����
				u[0][(jc + (nhaba - 1) / 2) - 1] = qinh / h0[1][(jc + (nhaba - 1) / 2) - 1] / dy; /////????? //Base0 ����

				if(qinv <= 0.0)
				{
					//for(j = (jc - (nhaba - 3) / 2) - 1;j <= jc + (nhaba - 3) / 2;j++)
					for(j = (jc - (nhaba - 3) / 2) - 2;j < jc + (nhaba - 3) / 2;j++)  //Base0 ����
					{
						//''!	  v(2,j)=qinv/h0(2,j)/dx
						vr[1][j] = v[1][j] + qinv / h0[1][j] / dx;  //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
					}
				}
				else
				{
					//for(j = (jc - (nhaba - 3) / 2) - 1;j <= jc + (nhaba - 3) / 2;j++)
					for(j = (jc - (nhaba - 3) / 2) - 2;j < jc + (nhaba - 3) / 2;j++) //Base0 ����  190813 ��Q�@�C��
					{
						//''!	  v(2,j)=qinv/h0(2,j+1)/dx
						vr[1][j] = v[1][j] + qinv / h0[1][j + 1] / dx; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
					}
				}
			}
			else
			{
				u[0][jc - 1] = qin / h0[1][jc - 1] / dy; //Base0 ����
				if(qinv <= 0.0)
				{
					//''!	  v(2,jc-1)=qinv/h0(2,jc-1)/dx
					//''!	  v(2,jc)=qinv/h0(2,jc)/dx
					vr[1][jc - 2] = v[1][jc - 2] + qinv / h0[1][jc - 2] / dx; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
					vr[1][jc - 1] = v[1][jc - 1] + qinv / h0[1][jc - 1] / dx; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
				}
				else
				{
					//''!	 v(2,jc-1)=qinv/h0(2,jc)/dx
					//''!	  v(2,jc)=qinv/h0(2,jc+1)/dx
					vr[1][jc - 2] = v[1][jc - 2] + qinv / h0[1][jc - 1] / dx; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
					vr[1][jc - 1] = v[1][jc - 1] + qinv / h0[1][jc] / dx; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
				}
			}


			//''! ------------------------ boundary conditions------------------------------
			for(j = 0;j < jend;j++) //Base0 ����
			{
				if(u[iend - 3][j] > 0.0) //Base0 ���� ���Ӂ@�����@[iend - 2]
				{
					u[iend - 2][j] = u[iend - 3][j]; //Base0 ����
				}
				else
				{
					u[iend - 3][j] = 0.0; //Base0 ���� ���Ӂ@�����@[iend - 2]
					u[iend - 2][j] = 0.0; //Base0 ����
				}
			}

			for(j = 0;j < ((jc - 1) - (nhaba - 1) / 2);j++) //Base0 ����
			{
				u[0][j] = 0.0; //Base0 ����
			}

			for(j = ((jc + 1) + (nhaba - 1) / 2) - 1;j < jend;j++) //Base0 ����
			{
				u[0][j] = 0.0; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				u[i][0] = 0.0; //Base0 ����
				u[i][jend - 1] = 0.0; //Base0 ����
			}

			for(j = 0;j < jend;j++) //Base0 ����
			{
				v[iend - 1][j] = 0.0; //Base0 ����
				v[0][j] = 0.0; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				if(v[i][1] < 0.0) //Base0 ����
				{
					v[i][0] = v[i][1]; //Base0 ����
				}
				else
				{
					v[i][1] = 0.0; //Base0 ����
					v[i][0] = 0.0; //Base0 ����
				}
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				if(v[i][jend - 3] > 0.0) //Base0 ����
				{
					v[i][jend - 2] = v[i][jend - 3]; //Base0 ����
				}
				else
				{
					v[i][jend - 3] = 0.0; //Base0 ����
					v[i][jend - 2] = 0.0; //Base0 ����
				}
			}


			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub suisin----------------h
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NIHHH(); //'(iend,jend,nhaba,jc,dt,dx,dy,hlim,hmin,qin,qinh,qinv,qinvh)
			aa = dt / (dx * dy);

			for(i = 0;i < iend - 1;i++) //Base0 ����
			{
				for(j = 0;j < jend - 1;j++) //Base0 ����
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							if(u[i][j] >= 0.0)
							{
								if(h[i][j] <= hlim)
								{
									flx[i][j] = 0.0;
								}
								else
								{
									flx[i][j] = u[i][j] * h0[i][j] * dy; //''08.6.6wadako�ɕ�����!h����h0��(08/05/27)
								}
							}
							else
							{
								if(h[i + 1][j] <= hlim)
								{
									flx[i][j] = 0.0;
								}
								else
								{
									flx[i][j] = u[i][j] * h0[i + 1][j] * dy; //''08.6.6wadako�ɕ�����!h����h0��(08/05/27)
								}
							}

							if(v[i][j] >= 0.0)
							{
								if(h[i][j] <= hlim)
								{
									fly[i][j] = 0.0;
								}
								else
								{
									fly[i][j] = v[i][j] * h0[i][j] * dx; //''08.6.6wadako�ɕ�����!h����h0��(08/05/27)
								}
							}
							else
							{
								if(h[i][j + 1] <= hlim)
								{
									fly[i][j] = 0.0;
								}
								else
								{
									fly[i][j] = v[i][j] * h0[i][j + 1] * dx; //''08.6.6wadako�ɕ�����!h����h0��(08/05/27)
								}
							}
						}
					}  //End if '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			//''!------------------------------- hin ---------------------------
			if(nhaba >= 3)
			{
				for(j = (jc - (nhaba - 3) / 2) - 1;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
				{
					flx[0][j] = qin; //Base0 ����
				}

				flx[0][jc - (nhaba - 1) / 2 - 1] = qinh; //Base0 ����
				flx[0][jc + (nhaba - 1) / 2 - 1] = qinh;  /////??????? //Base0 ����

				//for(j = (jc - (nhaba - 3) / 2) - 1;j <= (jc + (nhaba - 3) / 2);j++)
				for(j = (jc - (nhaba - 3) / 2) - 2;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
				{
					if(vr[1][j] >= 0.0) //Base0 ����
					{
						fly[1][j] = vr[1][j] * h0[1][j] * dx; //Base0 ����
					}
					else
					{
						fly[1][j] = vr[1][j] * h0[1][j + 1] * dx; //Base0 ����
					}
					fly[1][j] = fly[1][j] + qinv; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
				}
			}
			else
			{
				flx[0][jc - 1] = qin; //Base0 ����

				for(j = jc - 2;j < jc;j++) //Base0 ���� ���Ӂ@���� jc - 2
				{
					if(vr[1][j] >= 0.0) //Base0 ����
					{
						fly[1][j] = vr[1][j] * h0[2][j] * dx; //Base0 ����
					}
					else
					{
						fly[1][j] = vr[1][j] * h0[1][j + 1] * dx; //Base0 ����
					}
				}
				fly[1][jc - 2] = fly[1][jc - 2] + qinv; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
				fly[1][jc - 1] = fly[1][jc - 1] + qinv; //Base0 ����
			}

			//''!---------------------------------------------------------------
			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					//''      ifflag2[i][j] = 1 Then '07.10.17�ǉ��iflag2�Ŕ���j;������flag2�Ɋ֌W�Ȃ��v�Z�I'07.10.19
					//'�������Ȃ��ƁA�t���b�N�X���z�����܂�Ȃ��H�I

					if(id[i][j] != 0)
					{
						dhdt = aa * (flx[i - 1][j] - flx[i][j] + fly[i][j - 1] - fly[i][j]);
						if((h0[i][j] <= hmin) && ((dhdt + eet[i][j] * dt) < 0.0))
						{
							h[i][j] = h0[i][j];
							eet[i][j] = (h[i][j] - h0[i][j] - dhdt) / dt; //'!eet�̍Čv�Z
						}
						else
						{
							h[i][j] = h0[i][j] + dhdt + eet[i][j] * dt;

							if(h[i][j] <= hmin)
							{
								h[i][j] = hmin;
								eet[i][j] = (h[i][j] - h0[i][j] - dhdt) / dt; //'!eet�̍Čv�Z
							}
						}
					}
				//''  End if'07.10.17�ǉ��iflag2�Ŕ���j������flag2�Ɋ֌W�Ȃ��v�Z�I'07.10.19
				}
			}

			//''!---------------------------boundary conditions-----------------------------
			for(j = 0;j < jend;j++) //Base0 ����
			{
				h[iend - 1][j] = h[iend - 2][j]; //Base0 ����
			}

			for(j = 0;j < ((jc - 1) - (nhaba - 1) / 2);j++) //Base0 ����
			{
				h[0][j] = hmin; //Base0 ����
			}

			for(j = ((jc + 1) + (nhaba - 1) / 2) - 1;j < jend;j++) //Base0 ����
			{
				h[0][j] = hmin; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				h[i][0] = h[i][1]; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				h[i][jend - 1] = h[i][jend - 2]; //Base0 ����
			}


			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub nodo---------------c
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NICCC(); //'(iend,jend,nhaba,jc,csta,dt,dx,dy,hlim,hmin,cin,cinh,cinv,cinvh,qinv)
			for(i = 0;i < iend - 1;i++) //Base0 ����
			{
				for(j = 0;j < jend - 1;j++) //Base0 ����
				{
					if(flag2[i][j] == 1)  //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							if(u[i][j] >= 0.0)
							{
								if(h[i][j] <= hlim)
								{
									cflx[i][j] = 0.0;
								}
								else
								{
									cflx[i][j] = c0[i][j] * u[i][j] * h[i][j];
								}
							}
							else
							{
								if(h[i + 1][j] <= hlim)
								{
									cflx[i][j] = 0.0;
								}
								else
								{
									cflx[i][j] = c0[i + 1][j] * u[i][j] * h[i + 1][j];
								}
							}

							if(v[i][j] >= 0.0)
							{
								if(h[i][j] <= hlim)
								{
									cfly[i][j] = 0.0;
								}
								else
								{
									cfly[i][j] = c0[i][j] * v[i][j] * h[i][j];
								}
							}
							else
							{
								if(h[i][j + 1] <= hlim)
								{
									cfly[i][j] = 0.0;
								}
								else
								{
									cfly[i][j] = c0[i][j + 1] * v[i][j] * h[i][j + 1];
								}
							}
						}  //	End if'go to20�ɑΉ�
					} //End if '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			//''!---------------------------- cin ------------------------------
			if(nhaba >= 3)
			{
				for(j = (jc - (nhaba - 3) / 2) - 1;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
				{
					cflx[0][j] = cin_w; //Base0 ����
				}

				cflx[0][(jc - (nhaba - 1) / 2) - 1] = cinh; //Base0 ����
 				cflx[0][(jc + (nhaba - 1) / 2) - 1] = cinh; //Base0 ���� /////??????

				for(j = (jc - (nhaba - 3) / 2) - 2;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
				{
					if(vr[1][j] >= 0.0) //Base0 ����
					{
						if(h[1][j] <= hlim) //Base0 ����
						{
							cfly[1][j] = 0.0; //Base0 ����
						}
						else
						{
							cfly[1][j] = c0[1][j] * vr[1][j] * h[1][j]; //Base0 ����
						}
					}
					else
					{
						if(h[1][j + 1] <= hlim) //Base0 ����
						{
							cfly[1][j] = 0.0; //Base0 ����
						}
						else
						{
							cfly[1][j] = c0[1][j + 1] * vr[1][j] * h[1][j + 1]; //Base0 ����
						}
					}
					cfly[1][j] = cfly[1][j] + cinv; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
				}
			}
			else
			{
				cflx[0][jc - 1] = cin_w; //Base0 ����

				for(j = jc - 2;j < jc;j++) //Base0 ����
				{
					if(vr[1][j] >= 0.0) //Base0 ����
					{
						if(h[1][j] <= hlim) //Base0 ����
						{
							cfly[1][j] = 0.0; //Base0 ����
						}
						else
						{
							cfly[1][j] = c0[1][j] * vr[1][j] * h[1][j]; //Base0 ����
						}
					}
					else
					{
						if(h[1][j + 1] <= hlim) //Base0 ����
						{
							cfly[1][j] = 0.0; //Base0 ����
						}
						else
						{
							cfly[1][j] = c0[1][j + 1] * vr[1][j] * h[1][j + 1]; //Base0 ����
						}
					}
				}

				cfly[1][jc - 2] = cfly[1][jc - 2] + cinv; //Base0 ���� //'08.6.6wadako�ɕ�����!�ꉞ�̑[�u(08/05/27)
				cfly[1][jc - 1] = cfly[1][jc - 1] + cinv; //Base0 ����
			}

			//''!---------------------------------------------------------------
			for(i = 1;i < iend - 1;i++) //Base0 ���� ���Ӂ@���� i = 2
			{
				for(j = 1;j < jend - 1;j++) //Base0 ���� ���Ӂ@���� j = 2
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							dcc = (cflx[i - 1][j] - cflx[i][j]) / dx + (cfly[i][j - 1] - cfly[i][j]) / dy;
							if(h[i][j] <= hmin)
							{
								c[i][j] = 0.0;
								eet[i][j] = (c[i][j] * h[i][j] - c0[i][j] * h0[i][j] - dcc * dt) / (csta * dt); //'!eet�̍Čv�Z
							}
							else
							{
								c[i][j] = (c0[i][j] * h0[i][j] + (dcc + eet[i][j] * csta) * dt) / h[i][j];
								if(c[i][j] < 0.0)
								{
									c[i][j] = 0.0;
									eet[i][j] = (c[i][j] * h[i][j] - c0[i][j] * h0[i][j] - dcc * dt) / (csta * dt); //'!eet�̍Čv�Z
								}

								if(c[i][j] > csta * 0.9)
								{
									c[i][j] = csta * 0.9;
									eet[i][j] = (c[i][j] * h[i][j] - c0[i][j] * h0[i][j] - dcc * dt) / (csta * dt); //'!eet�̍Čv�Z
								}
							}
						}
					} //End if  '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}

			//''!--------------------------------boundary condition-------------------------
			for(j = 0;j < jend;j++) //Base0 ����
			{
				c[iend - 1][j] = c[iend - 2][j]; //Base0 ����
				c[0][j] = 0.0; //Base0 ����
			}

			for(j = (jc - (nhaba - 1) / 2) - 1;j < (jc + (nhaba - 1) / 2);j++) //Base0 ����
			{
				c[0][j] = c[1][j]; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				c[i][0] = c[i][1]; //Base0 ����
			}

			for(i = 0;i < iend;i++) //Base0 ����
			{
				c[i][jend - 1] = c[i][jend - 2]; //Base0 ����
			}


			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			//''!      sub kasyo-------------z
			//''!<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
			////NIZZZ(); //'(iend,jend,dt)
			for(i = 0;i < iend;i++) //Base0 ����
			{
				//for(j = 0;j < iend;j++) //Base0 ���� /////????? iend��OK????? �`�F�b�N�@�`�F�b�N
//						For j = 1 To jend '20130507�C��
//								' For j = 1 To iend'20130507�C���O��iend�ɂȂ��Ă����I
				for(j = 0;j < jend;j++) //Base0 ���� /////????? iend��OK?????
				{
					if(flag2[i][j] == 1) //'07.10.17�ǉ��iflag2�Ŕ���j
					{
						if(id[i][j] != 0)
						{
							z[i][j] = z0[i][j] - eet[i][j] * dt;
							if(zs[i][j] > z[i][j])
							{
								z[i][j] = zs[i][j];
							}
						}
					} //End if   '07.10.17�ǉ��iflag2�Ŕ���j
				}
			}


			////NIenergy(); //'07.10.17�ǉ�
			for(i = 0;i < iend;i++) //Base0 ����
			{
				for(j = 0;j < jend;j++) //Base0 ����
				{
					if(flag2[i][j] == 1)
					{
						ni_energy[i][j] = h[i][j] * sqrt((u[i][j] * u[i][j]) + (v[i][j] * v[i][j])); //ni_energy[i][j] = h[i][j] * Math.Sqrt(u[i][j] ^ 2 + v[i][j] ^ 2)
					}
				}
			}





			KEISAN_2D1D:


			//keisan_2D1D();
			//'!------------------jouken 2---------------------------
			//'!�Q�����͏��̂P�����ւ̊Ҍ�
			//140514 1�����̂݌v�Z�����@��Q
//			if(bNiji)
//			{
				hbar = 0;
				zbar = 0;
				cbar = 0;

				if(nhaba >= 3)
				{
					//'	do 88 j=(jc-(nhaba-3)/2),(jc+(nhaba-3)/2)
					for(j = (jc - (nhaba - 3) / 2) - 1;j < (jc + (nhaba - 3) / 2);j++) //Base0 ����
					{
						hbar = hbar + h[1][j] * dy / b0; //Base0 ����
						zbar = zbar + z[1][j] * dy / b0; //Base0 ����
						cbar = cbar + c[1][j] * dy / b0; //Base0 ����
					}

					hbar = hbar + h[1][(jc - (nhaba - 1) / 2) - 1] * hashi / b0; //Base0 ����
					hbar = hbar + h[1][(jc + (nhaba - 1) / 2) - 1] * hashi / b0; //Base0 ����
					zbar = zbar + z[1][(jc - (nhaba - 1) / 2) - 1] * hashi / b0; //Base0 ����
					zbar = zbar + z[1][(jc + (nhaba - 1) / 2) - 1] * hashi / b0; //Base0 ����
					cbar = cbar + c[1][(jc - (nhaba - 1) / 2) - 1] * hashi / b0; //Base0 ����
					cbar = cbar + c[1][(jc + (nhaba - 1) / 2) - 1] * hashi / b0; //Base0 ����
				}
				else
				{
					hbar = h[1][jc - 1]; //Base0 ����
					zbar = z[1][jc - 1]; //Base0 ����
					cbar = c[1][jc - 1]; //Base0 ����
				}

				//hk[kend] = ((dx0 - dxk) * hk[kend - 2] + 2.0 * dxk * hbar) / (dxk + dx0);
				hk[kend - 1] = ((dx0 - dxk) * hk[kend - 2] + 2.0 * dxk * hbar) / (dxk + dx0); //Base0 ����
				//zk[kend] = ((dx0 - dxk) * zk[kend - 2] + 2.0 * dxk * zbar) / (dxk + dx0);
				zk[kend - 1] = ((dx0 - dxk) * zk[kend - 2] + 2.0 * dxk * zbar) / (dxk + dx0); //Base0 ����
//			}
//			else
//			{
//				hk[kend - 1] = hk[kend - 2]; //Base0 ����
//				zk[kend - 1] = zk[kend - 2]; //Base0 ����
//			}

			if((zk[kend - 1] - zsk[kend - 1]) < 0) //Base0 ����
			{
				zk[kend - 1] = zsk[kend - 1]; //Base0 ����
			}

			if(hk[kend - 1] < hmin) //Base0 ����
			{
				hk[kend - 1] = hmin; //Base0 ����
			}




			//'If time Mod 60 = 0 Then '07.9.25:�����ɕۑ�'07.10.1:60�b���Ɋ���iminstep�Ƃ͕ʁI�j
			////if(l_time % (long)(result_output_dt * 1000) == 0) //'090422��default����Ԋu��ύX�\�ɂ���
			////{
			////	printf("%0.2f�b\n",f_time);
			////	save_result_each_time();
			////	//save_image_each_time();
			////}

			//'     ruisekichi keisan
			////RUISEKI();
// 140407 0�ɂ͓��̓n�C�h�������邽�ߏC��
			for(i = 1;i <= nout;i++) //Base0 ����
			{
				if(uk[iout[i] - 1] >= 0)
				{
					qqq = uk[iout[i] - 1] * hk[iout[i] - 1] * bmk[iout[i] - 1];
					qsum[i] = qsum[i] + qqq * dt;
					qhsum[i] = qhsum[i] + qqq * ck[iout[i] - 1] * dt;
					qssum[i] = 0; //'qssum[i] + qqq * csk(iout[i]) * dt
				}
				else
				{
					qqq = uk[iout[i] - 1] * hk[iout[i] - 1 + 1] * bmk[iout[i] - 1];
					qsum[i] = qsum[i] + qqq * dt;
					qhsum[i] = qhsum[i] + qqq * ck[iout[i] - 1 + 1] * dt;
					qssum[i] = 0; //'qssum[i] + qqq * csk(iout[i] + 1) * dt
				}
			}

			////ryunyu_qout();  //'�����n�C�h���̗���(q,qh,qs)���Z�o
			q[0] = qink1; //Base0 ����
			qh[0] = qink1 * cink1; //Base0 ����
			qs[0] = 0; //Base0 ���� //'qin * csin

			////current_qout();  //'����n�_�ł̗���(q,qh,qs)���Z�o
			if(f_time > 0)
			{
				for(i = 1;i <= nout;i++) //Base0 ����
				{
					//140408 �S�_�o�͂̂��߃_���ʒu�͊ϑ��_���珜��
					if(iout[i] == -1)
					{
						q[i] = qh[i] = qs[i] = -1;
					}
					else
					{
						q[i] = (qsum[i] - qsum0[i]) / (f_time - t0);
						qh[i] = (qhsum[i] - qhsum0[i]) / (f_time - t0);
						qs[i] = (qssum[i] - qssum0[i]) / (f_time - t0);
					}
				}

				tm_w = (f_time + t0) * 0.5;
			}

			t0 = f_time;
			for(i = 1;i <= nout;i++) //Base0 ����
			{
				qsum0[i] = qsum[i];
				qhsum0[i] = qhsum[i];
				qssum0[i] = qssum[i];
			}

			if(iHydroOutput == 1)
			{
				if(l_time % (long)(hydroout_dt * 1000) == 0) // '07.12.26�ǉ�
				{
					for(j = 0;j <= nout;j++) //'�i0�������n�C�h���j
					{
						hydroout_dat[hydro_counter][j][0] = q[j];
						hydroout_dat[hydro_counter][j][1] = qh[j];
						hydroout_dat[hydro_counter][j][2] = qs[j];
					}
					hydro_counter = hydro_counter + 1;
					//printf("hydro_counter = %ld\n",hydro_counter);
				} // '07.12.26�ǉ������܂�
			}

			mstep = mstep + 1;

		}

		printf("%0.2fsec\n",mstep * dt);
		save_result_each_time(mstep * dt);

	}

	mode = 0;

	for(int j = 0;j < iend;j++) //Base0 ����
	{
		for(int k = 0;k < jend;k++) //Base0 ����
		{
			z[j][k] = zmoto[j][k];
		}
	}

	return;
}



void result_file_open()
{
	//AnsiString FPath;
	string FPath;
	string FPath_Base2;

//	FPath_Base2 = "ThreeD\\Simulation\\" + FPath_Base;
//	FPath_Base2 = DriveName + FPath_Base2;
	FPath_Base2 = FPath_Base;

	FPath = FPath_Base2 + "_1ji.dat";
	ichiji_fout.open( FPath.c_str(), ios::out );
	ichiji_fout.setf(ios_base::fixed, ios_base::floatfield);
	ichiji_fout << ";1D calculation result(No,Flow depth,Concentration,Flow verocity,River bed,River width)" << endl; //'20131217�F�V�R�_���g���̂��߁A�o�͂Ŋm�F�ł���悤�ǉ�

	FPath = FPath_Base2 + "_2ji_h.dat";
	niji_0_fout.open( FPath.c_str(), ios::out );
	niji_0_fout.setf(ios_base::fixed, ios_base::floatfield);
	niji_0_fout.precision(2);
	niji_0_fout << ";2D calculation result : Flow depth" << endl;

	FPath = FPath_Base2 + "_2ji_c.dat";
	niji_1_fout.open( FPath.c_str(), ios::out );
	niji_1_fout.setf(ios_base::fixed, ios_base::floatfield);
	niji_1_fout.precision(2);
	niji_1_fout << ";2D calculation result : Concentration" << endl;

	FPath = FPath_Base2 + "_2ji_u.dat";
	niji_2_fout.open( FPath.c_str(), ios::out );
	niji_2_fout.setf(ios_base::fixed, ios_base::floatfield);
	niji_2_fout.precision(2);
	niji_2_fout << ";;2D calculation result : Flow verocity(flow direction)" << endl;

	FPath = FPath_Base2 + "_2ji_v.dat";
	niji_3_fout.open( FPath.c_str(), ios::out );
	niji_3_fout.setf(ios_base::fixed, ios_base::floatfield);
	niji_3_fout.precision(2);
	niji_3_fout << ";2D calculation result : Flow verocity(cross direction)" << endl;

	FPath = FPath_Base2 + "_2ji_z.dat";
	niji_4_fout.open( FPath.c_str(), ios::out );
	niji_4_fout.setf(ios_base::fixed, ios_base::floatfield);
	niji_4_fout.precision(2);
	niji_4_fout << ";2D calculation result : River bed" << endl;

	FPath = FPath_Base2 + "_2ji_zs.dat";
	niji_5_fout.open( FPath.c_str(), ios::out );
	niji_5_fout.setf(ios_base::fixed, ios_base::floatfield);
	niji_5_fout.precision(2);
	niji_5_fout << ";2D calculation result : Deposition thickness" << endl;
}

void result_file_close()
{
	ichiji_fout.flush();
	ichiji_fout.close();

	niji_0_fout.flush();
	niji_0_fout.close();

	niji_1_fout.flush();
	niji_1_fout.close();

	niji_2_fout.flush();
	niji_2_fout.close();

	niji_3_fout.flush();
	niji_3_fout.close();

	niji_4_fout.flush();
	niji_4_fout.close();

	niji_5_fout.flush();
	niji_5_fout.close();
}

void save_result_each_time(double ftime)
{
	int j,k;
//	long ldata;
//	char pngname[FILENAME_MAX];
//	long hn;

	ichiji_fout.precision(2); ichiji_fout << ftime << "sec" << endl;
//	ichiji_fout << mstep << endl;
	for(j = 0;j < kend;j++) //Base0 ����
	{
		ichiji_fout.width(3); ichiji_fout.precision(0); ichiji_fout << j+1 << ";";

		ichiji_fout.precision(3); ichiji_fout << hk[j] << ",";
		ichiji_fout.precision(3); ichiji_fout << ck[j] << ",";
		ichiji_fout.precision(3); ichiji_fout << uk[j] << ",";
		ichiji_fout.precision(3); ichiji_fout << zk[j] << ",";
		ichiji_fout.precision(3); ichiji_fout << zk[j] - zorigk[j] << ",";
		ichiji_fout.precision(3); ichiji_fout << bbk[j] << endl; //'20131217�ǉ��F�͓����i�V�R�_���̏ꍇ�݂͂������j 140202 ��Q�@�C�� '20131217�F�V�R�_���g���̂��߁A�o�͂Ŋm�F�ł���悤�ǉ�

	}
	ichiji_fout << endl;

//	niji_0_fout.precision(3);niji_0_fout << ftime << gettext("sec") << endl;
//	//niji_0_fout << mstep << endl;
//	for(j = 0;j < iend;j++) //Base0 ����
//	{
//		for(k = 0;k < jend;k++) //Base0 ����
//		{
//			if(k == jend - 1)
//			{
//				niji_0_fout << h[j][k] << endl;
//			}
//			else
//			{
//				niji_0_fout << h[j][k] << ",";
//			}
//
//			if(h[j][k] > dHmax) dHmax =  h[j][k];  //Vrml�̂���
//		}
//	}
//	niji_0_fout << endl;
//
//	niji_1_fout.precision(3);niji_1_fout << ftime << gettext("sec") << endl;
//	//niji_1_fout << mstep << endl;
//	for(j = 0;j < iend;j++) //Base0 ����
//	{
//		for(k = 0;k < jend;k++) //Base0 ����
//		{
//			if(k == jend - 1)
//			{
//				niji_1_fout << c[j][k] << endl;
//			}
//			else
//			{
//				niji_1_fout << c[j][k] << ",";
//			}
//		}
//	}
//	niji_1_fout << endl;
//
//	niji_2_fout.precision(3);niji_2_fout << ftime << gettext("sec") << endl;
//	//niji_2_fout << mstep << endl;
//	for(j = 0;j < iend;j++) //Base0 ����
//	{
//		for(k = 0;k < jend;k++) //Base0 ����
//		{
//			if(k == jend - 1)
//			{
//				niji_2_fout << u[j][k] << endl;
//			}
//			else
//			{
//				niji_2_fout << u[j][k] << ",";
//			}
//		}
//	}
//	niji_2_fout << endl;
//
//	niji_3_fout.precision(3);niji_3_fout << ftime << gettext("sec") << endl;
//	//niji_3_fout << mstep << endl;
//	for(j = 0;j < iend;j++) //Base0 ����
//	{
//		for(k = 0;k < jend;k++) //Base0 ����
//		{
//			if(k == jend - 1)
//			{
//				niji_3_fout << v[j][k] << endl;
//			}
//			else
//			{
//				niji_3_fout << v[j][k] << ",";
//			}
//		}
//	}
//	niji_3_fout << endl;
//
//	niji_4_fout.precision(3);niji_4_fout << ftime << gettext("sec") << endl;
//	//niji_4_fout << mstep << endl;
//	for(j = 0;j < iend;j++) //Base0 ����
//	{
//		for(k = 0;k < jend;k++) //Base0 ����
//		{
//			if(k == jend - 1)
//			{
//				niji_4_fout << z[j][k] << endl;
//			}
//			else
//			{
//				niji_4_fout << z[j][k] << ",";
//			}
//		}
//	}
//	niji_4_fout << endl;
//
//	niji_5_fout.precision(3);niji_5_fout << ftime << gettext("sec") << endl;
//	//niji_5_fout << mstep << endl;
//	for(j = 0;j < iend;j++) //Base0 ����
//	{
//		for(k = 0;k < jend;k++) //Base0 ����
//		{
//			if(k == jend - 1)
//			{
//				niji_5_fout << z[j][k] - zmoto[j][k] << endl;
//			}
//			else
//			{
//				niji_5_fout << z[j][k] - zmoto[j][k] << ",";
//			}
//		}
//	}
//	niji_5_fout << endl;

	niji_0_fout.precision(3);niji_0_fout << ftime << "sec" << endl;
	niji_1_fout.precision(3);niji_1_fout << ftime << "sec" << endl;
	niji_2_fout.precision(3);niji_2_fout << ftime << "sec" << endl;
	niji_3_fout.precision(3);niji_3_fout << ftime << "sec" << endl;
	niji_4_fout.precision(3);niji_4_fout << ftime << "sec" << endl;
	niji_5_fout.precision(3);niji_5_fout << ftime << "sec" << endl;
	for(j = 0;j < iend;j++) //Base0 ����
	{
		for(k = 0;k < jend;k++) //Base0 ����
		{
			if(flag2_Ruiseki[j][k] == 0)
			{
				flag2_Ruiseki[j][k] = flag2[j][k];
			}

//			if(flag2[j][k] == 1)
			if(flag2_Ruiseki[j][k] == 1)
			{
				if(k == jend - 1)
				{
					niji_0_fout << h[j][k] << endl;
					niji_1_fout << c[j][k] << endl;
					niji_2_fout << u[j][k] << endl;
					niji_3_fout << v[j][k] << endl;
					niji_5_fout << z[j][k] - zmoto[j][k] << endl;
				}
				else
				{
					niji_0_fout << h[j][k] << ",";
					niji_1_fout << c[j][k] << ",";
					niji_2_fout << u[j][k] << ",";
					niji_3_fout << v[j][k] << ",";
					niji_5_fout << z[j][k] - zmoto[j][k] << ",";
				}
			}
			else
			{
				if(k == jend - 1)
				{
					niji_0_fout << NONCALC << endl;
					niji_1_fout << NONCALC << endl;
					niji_2_fout << NONCALC << endl;
					niji_3_fout << NONCALC << endl;
					niji_5_fout << NONCALC << endl;
				}
				else
				{
					niji_0_fout << NONCALC << ",";
					niji_1_fout << NONCALC << ",";
					niji_2_fout << NONCALC << ",";
					niji_3_fout << NONCALC << ",";
					niji_5_fout << NONCALC << ",";
				}
			}

			if(k == jend - 1)
			{
				niji_4_fout << z[j][k] << endl;
			}
			else
			{
				niji_4_fout << z[j][k] << ",";
			}

			if(h[j][k] > dHmax) dHmax =  h[j][k];  //Vrml�̂���
		}
	}
	niji_0_fout << endl;
	niji_1_fout << endl;
	niji_2_fout << endl;
	niji_3_fout << endl;
	niji_4_fout << endl;
	niji_5_fout << endl;

	return;
}


//void save_result()
//{
//	int i,j,k;
//	//AnsiString FPath;
//	string FPath;
//
//	FPath = FPath_Base + "_1Ji.dat";
//	ofstream fout( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//
//	fout << ";1D calculation result(No,Flow depth,Concentration,Flow verocity,River bed,River width)" << endl;
//
//	for(i = 0;i <= ichiji_counter - 1;i++)
//	{
//		fout.precision(2); fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < kend;j++) //Base0 ����
//		{
//			fout.width(3); fout.precision(0); fout << j << ";";
//
//			fout.precision(2); fout << ichiji_dat[i][j][0] << ",";
//			fout.precision(2); fout << ichiji_dat[i][j][1] << ",";
//			fout.precision(2); fout << ichiji_dat[i][j][2] << ",";
//			fout.precision(2); fout << ichiji_dat[i][j][3] << ",";
//			fout.precision(2); fout << ichiji_dat[i][j][4] << endl;
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//
//	FPath = FPath_Base + "_2Ji_0.dat";
//	fout.open( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//	fout.precision(2);
//	fout << ";2D calculation result 0" << endl;
//	for(i = 0;i <= niji_counter - 1;i++)
//	{
//		fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < iend;j++) //Base0 ����
//		{
//			for(k = 0;k < jend;k++) //Base0 ����
//			{
//				if(k == jend - 1) //Base0 ����
//				{
//					fout << niji_dat[i][j][k][0] << endl;
//				}
//				else
//				{
//					fout << niji_dat[i][j][k][0] << ",";
//				}
//			}
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//	FPath = FPath_Base + "_2Ji_1.dat";
//	fout.open( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//	fout.precision(2);
//	fout << ";2D calculation result 1" << endl;
//	for(i = 0;i <= niji_counter - 1;i++)
//	{
//		fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < iend;j++) //Base0 ����
//		{
//			for(k = 0;k < jend;k++) //Base0 ����
//			{
//				if(k == jend - 1) //Base0 ����
//				{
//					fout << niji_dat[i][j][k][0] << endl;
//				}
//				else
//				{
//					fout << niji_dat[i][j][k][0] << ",";
//				}
//			}
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//	FPath = FPath_Base + "_2Ji_2.dat";
//	fout.open( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//	fout.precision(2);
//	fout << ";2D calculation result 2" << endl;
//	for(i = 0;i <= niji_counter - 1;i++)
//	{
//		fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < iend;j++) //Base0 ����
//		{
//			for(k = 0;k < jend;k++) //Base0 ����
//			{
//				if(k == jend - 1) //Base0 ����
//				{
//					fout << niji_dat[i][j][k][1] << endl;
//				}
//				else
//				{
//					fout << niji_dat[i][j][k][1] << ",";
//				}
//			}
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//	FPath = FPath_Base + "_2Ji_3.dat";
//	fout.open( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//	fout.precision(2);
//	fout << ";2D calculation result 3" << endl;
//	for(i = 0;i <= niji_counter - 1;i++)
//	{
//		fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < iend;j++) //Base0 ����
//		{
//			for(k = 0;k < jend;k++) //Base0 ����
//			{
//				if(k == jend - 1) //Base0 ����
//				{
//					fout << niji_dat[i][j][k][2] << endl;
//				}
//				else
//				{
//					fout << niji_dat[i][j][k][2] << ",";
//				}
//			}
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//	FPath = FPath_Base + "_2Ji_4.dat";
//	fout.open( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//	fout.precision(2);
//	fout << ";2D calculation result 4" << endl;
//	for(i = 0;i <= niji_counter - 1;i++)
//	{
//		fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < iend;j++) //Base0 ����
//		{
//			for(k = 0;k < jend;k++) //Base0 ����
//			{
//				if(k == jend - 1) //Base0 ����
//				{
//					fout << niji_dat[i][j][k][3] << endl;
//				}
//				else
//				{
//					fout << niji_dat[i][j][k][3] << ",";
//				}
//			}
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//	FPath = FPath_Base + "_2Ji_5.dat";
//	fout.open( FPath.c_str(), ios::out );
//	fout.setf(ios_base::fixed, ios_base::floatfield);
//	fout.precision(2);
//	fout << ";2D calculation result 5" << endl;
//	for(i = 0;i <= niji_counter - 1;i++)
//	{
//		fout << i * result_output_dt << "Time (sec)" << endl; // '090422�ύX�F���͉��s�̗l��60�b���Œ肾����
//
//		for(j = 0;j < iend;j++) //Base0 ����
//		{
//			for(k = 0;k < jend;k++) //Base0 ����
//			{
//				if(k == jend - 1) //Base0 ����
//				{
//					fout << niji_dat[i][j][k][4] << endl;
//				}
//				else
//				{
//					fout << niji_dat[i][j][k][4] << ",";
//				}
//			}
//		}
//		fout << endl;
//	}
//	fout.flush();
//	fout.close();
//
//	return;
//}

void save_result_debug_niji(float **niji)
{
	int j,k;
	char buff[FILENAME_MAX];

	sprintf(buff,"%ld\n",mstep);
	logwrite(buff,LogName);
	//fprintf(logout,"%ld\n",mstep);

		for(j = 0;j < iend;j++) //Base0 ����
		{
			for(k = 0;k < jend;k++) //Base0 ����
			{
				if(k == jend - 1) //Base0 ����
			{
				sprintf(buff,"%.4lf \n",niji[j][k]);
				logwrite(buff,LogName);
			}
			else
			{
				sprintf(buff,"%.4lf ",niji[j][k]);
				logwrite(buff,LogName);
			}
		}
	}
	logwrite("\n\n",LogName);
	//fprintf(logout,"\n\n");

	return;
}



//---------------------------------------------------------------------------

void errlogout()
{
	struct tm *date;
	time_t now;
	int year, month, day;
	int hour, minute, second;

	time(&now);
	date = localtime(&now);
	year = date->tm_year + 1900;
	month = date->tm_mon + 1;
	day = date->tm_mday;
	hour = date->tm_hour;
	minute = date->tm_min;
	second = date->tm_sec;

	fprintf(logout,"%04d/%02d/%02d %02d:%02d:%02d : %d %s\n", year, month, day, hour, minute, second, errnum, errmsg);
	return;
}


string ChangeFileExt(string filename,string ext)
{
	string filename2 = "";
	string filename3 = "";
	VS vs;
	VS vs2;

	vs = split(filename,"\\");
	filename2 = vs[vs.size() - 1];

	vs2 = split(filename2,".");

	for(int i = 0;i < vs.size() - 1;i++)
	{
		filename3 = filename3 + vs[i];
		filename3 = filename3 + "\\";
	}

	if(vs2.size() < 2)
	{
		filename3 = filename3 + vs2[0];
	}
	else
	{
		for(int i = 0;i < vs2.size() - 1;i++)
		{
			filename3 = filename3 + vs2[i];
			if(i < vs2.size() - 1) filename3 = filename3 + ".";
		}
	}

	filename3 = filename3 + ext;

	return filename3;
}

//VS split( string s, string c )
//{
//	VS ret;
//
//	for( int i=0, n; i <= s.length(); i=n+1 )
//	{
//		n = s.find_first_of( c, i );
//		if( n == string::npos ) n = s.length();
//		string tmp = s.substr( i, n-i );
//		ret.push_back(tmp);
//	}
//	return ret;
//}



void logwrite(char *str,char *filename)
{
	FILE *fpout;
//	char namebuff[FILENAME_MAX];
	char s[50];

//	sprintf(namebuff,"%s_log.txt",filename);
	if(NULL == (fpout = fopen(filename,"at")))
	{
		return;
	}

	fmttm(s);             // ������֕ϊ�

	fprintf(fpout,"%s : %s\n", s,str);        // ���@"2005�N8��3���i���j_03:44:35"

	fclose(fpout);

	return;
}


char *fmttm(char *buf)
{
	time_t t;
	struct tm *st;

	t = time(NULL);
	st = localtime(&t);  // ���[�J�����Ԃ� tm�\���̂ɕϊ�

	//sprintf(buf, "%d�N%d��%d��(%s)_%02dh%02dm%02ds",
	sprintf(buf, "%d-%d-%d_%02dh%02dm%02ds",
						st->tm_year + 1900,  /* �N�� +1900 ���K�v */
						st->tm_mon + 1,       /* ���� +1 ���K�v */
						st->tm_mday,            /* ���� 1...31 */
						//a[st->tm_wday],         /* �T�� 0...6 �� �z�� *a[7] �̕�����ɕϊ� */
						st->tm_hour,            /* ���� 0...23 �i0�l�߂̓񌅂ŕ\���j */
						st->tm_min,             /* ���� 0...59 �i0�l�߂̓񌅂ŕ\���j */
						st->tm_sec);            /* �b�� 0...59 �i0�l�߂̓񌅂ŕ\���j */
	return buf;
}

//�R�Ԗڂ̈�����true�ɂ����ꍇ�A�R�s�[��̃t�@�C�������݂���ꍇCopyFile�͎��s���܂��B
//false���w�肵���ꍇ�͏㏑�����܂��B
bool FileCopy(char *src,char *dest)
{
	bool bRet = CopyFile(src,dest,false);
	if (bRet == false)
	{
		return false;
	}

	return true;
}

//	'2010.6.11���ʃf�[�^�ۑ�Sub�ǉ�
void save_result_Q()
{
//		Dim i As Integer, j As Integer, k As Integer
//		Dim str1 As System.IO.StreamWriter

//		Dim dlg As New Windows.Forms.SaveFileDialog

//		Dim FPath As String

//		dlg.Filter = "�n�C�h���f�[�^�t�@�C�� (*.csv)|*.csv|���ׂẴt�@�C�� (*.*)|*.*" '090813�ύX
//
//		dlg.FilterIndex = 1
//
//		If dlg.ShowDialog() = DialogResult.OK Then
//
//			FPath = dlg.FileName
//
//		Else
//
//			Exit Sub
//
//		End If

	char cFilename[FILENAME_MAX];
//	sprintf(cFilename,"%sThreeD\\Simulation\\%s\\result_Q.csv",DriveName,FolderName);
	sprintf(cFilename,"%s\\result_Q.csv",FolderName);
	FILE *fpout = fopen(cFilename,"wt");

	//140408 �^�C�g���@��Q
	fprintf(fpout,"Time,");
	fprintf(fpout,"0-q,");
	fprintf(fpout,"0-qh,");
	for(int j = 1;j <= nout;j++) //06.2.7 j��1����0�ɕύX�i0�������n�C�h���j
	{
		if(iout[j] == -1)
		{
			fprintf(fpout,"Dam,");
			fprintf(fpout,"Dam,");
		}
		else if(iout[j] == -2)
		{
			fprintf(fpout,"Landslide Dam,");
			fprintf(fpout,"Landslide Dam,");
		}
		else
		{
			fprintf(fpout,"%d-q,",iout[j]);
			fprintf(fpout,"%d-qh,",iout[j]);
		}
	}
	fprintf(fpout,"\n");

//	For i = 0 To hydro_counter - 1
	for(int i = 0;i <= hydro_counter - 1;i++)
	{
//		str1.Write(Format(i * hydroout_dt, "#####0.00") + ",")
//		For j = 0 To nout '06.2.7 j��1����0�ɕύX�i0�������n�C�h���j
//			str1.Write(Format(hydroout_dat(i, j, 0), "#####0.00") + ",")
//			str1.Write(Format(hydroout_dat(i, j, 1), "#####0.00") + ",")
//
//
//			Next
//			str1.Write(vbCrLf)
//		Next

		fprintf(fpout,"%9.2lf,",i * hydroout_dt);
		for(int j = 0;j <= nout;j++) //06.2.7 j��1����0�ɕύX�i0�������n�C�h���j
		{
//			if(iout[j] == -1)
//			{
//				fprintf(fpout,",",hydroout_dat[i][j][0]);
//				fprintf(fpout,",",hydroout_dat[i][j][1]);
//			}
//			else if(iout[j] == -2)
//			{
//				fprintf(fpout,",",hydroout_dat[i][j][0]);
//				fprintf(fpout,",",hydroout_dat[i][j][1]);
//			}
//			else
//			{
//				fprintf(fpout,"%9.2lf,",hydroout_dat[i][j][0]);
//				fprintf(fpout,"%9.2lf,",hydroout_dat[i][j][1]);
//			}

			if(iout[j] == -1)
			{
				fprintf(fpout,",");
				fprintf(fpout,",");
			}
			else if(iout[j] == -2)
			{
				fprintf(fpout,",");
				fprintf(fpout,",");
			}
			else
			{
				fprintf(fpout,"%9.2f,",hydroout_dat[i][j][0]);
				fprintf(fpout,"%9.2f,",hydroout_dat[i][j][1]);
			}
		}

		fprintf(fpout,"\n");
	}

////		'06.2.8�ǉ��F����CSV�t�@�C���ɍ��h�_���E�ϑ��_�̃p�����[�^��ǉ�
//////	if(dam_flag == 1) //06.11.28if���ǉ�
//////	{
//	fprintf(fpout,"\n");
//	fprintf(fpout,"number of sabo dam = %d\n", ndam);
////		fprintf(fpout,"dam type[0:closed type,1:slit type],installation,height,slit width\n");
//
//	if(ndam > 0)
//	{
//		fprintf(fpout,"�_���̎��[0:�s���߁A1:�X���b�g],�ʒu,����,�X���b�g��\n");
//
//		for(int i = 0;i < ndam;i++)
//		{
//			fprintf(fpout,"%d, %d, %lf, %lf\n",dam_type[i],dam_idam[i],dam_nzd[i],dam_slit_width[i]);
//		}
//	}
////		Else '0��̏ꍇ�������L��
////			str1.Write(vbCrLf)
////			numwrite_line(str1, "number of sabo dam", ndam - 1)
////		End If
//
//	fprintf(fpout,"\n");
//	fprintf(fpout,"number of observation point = %d\n", nout);
//	if(nout > 0)
//	{
//		fprintf(fpout,"observation point installation\n");
//		for(int i = 1;i <= nout;i++)
//		{
//			fprintf(fpout,"%d\n",iout[i]);
//		}
//	}
//		//'06.2.8�ǉ������܂�

	fclose(fpout);
}
//---------------------------------------------------------------------------

