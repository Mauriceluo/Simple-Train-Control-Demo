/*
��
*/
#ifndef _TRAINHEADFILE_H_
#define	_TRAINHEADFILE_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include"egg.h"

struct POSITION {
	int x;
	int y;
};
typedef struct POSITION Position;
struct Traininfo {

	/*����*/
	int train_num;
	/*�����뷽��*/
	int train_type;//�쳵��1,������2
	int train_direction;//˳ʱ��1,��ʱ��2
	/*��׼��*/
	Position train_datum_point;//�ó���׼������(��ά)(���ԭ��)(����)
	/*����λ��*/
	int train_start_1D; //����λ��(һά)
	Position train_start_2D;//����λ��(��ά)
	/*̽���*/
	int train_detect_1D_1;//̽���1(һά)//����
	Position train_detect_2D_1;//̽���1(��ά)//���
	int train_detect_1D_2;//̽���2(һά)//����
	Position train_detect_2D_2;//̽���2(��ά)//���
	int train_detect_1D_3;//̽���3(һά)//����(Orbit 1)
	Position train_detect_2D_3;//̽���3(��ά)//���
	int train_detect_1D_4;//̽���4(һά)//����(Orbit 1)
	Position train_detect_2D_4;//̽���4(��ά)//���
	/*����ʱ��*/
	int train_start_time;//ֻ�ܴ��ڵ���0
	/*�����ٶ�*/
	int train_speed;//ֻ�ܴ��ڵ���1,�����޵�
	/*ͣ��*/
	int train_pause_time;//���ڵ���0
	/*����ǰλ��*/
	int train_distance_1D;//1D,����������λ��(���˶���)
	Position train_distance_2D;//2D
	/*����һ��λ��*/
	int train_next;
	/*�������*/
	int train_orbit_L;
	int train_orbit_W;
	/*����״̬*/
	int train_state;//0������ 1�ȴ���վ 2��վ̨�ȴ� 3��վ 4��վ 5shabi�û�Ҫֹͣ
	/*վ̨*/
	int station1;
	int station2;
	/*��ǰʱ��*/
    int time; 
 	int before;
	int timeofkey;
	struct Traininfo *tptr1;
	struct Traininfo *tptr2;
};//ֻ������Ŷ~
typedef struct Traininfo TrainInfo;
int time_temp1,time_temp2,time_temp3;
int speed_temp1,speed_temp2,speed_temp3;
int state_temp1,state_temp2,state_temp3;
int run_method;

void LoadInfo(TrainInfo* train1,TrainInfo* train2,TrainInfo* train3,int CreatMap);
Position Length_To_Coordinate(TrainInfo a);
void SetDefaultSet(TrainInfo train1[]);
void OutputSet(TrainInfo set[],int temp) ;
void InputSet(TrainInfo set[],int temp);
void CompleteInfo(TrainInfo* train1,TrainInfo* train2,TrainInfo* train3);
void EnsureInfo(TrainInfo* train);
int ReadytoJudge(TrainInfo a);
void ControlTrain(TrainInfo* train);
void FileWrite(TrainInfo set[],FILE *fp,int temp);
void AllControl(TrainInfo train[4]);
void PrintTrainInfo(TrainInfo* train,int OutputTime,int caidan);
int IsInPubluic(TrainInfo a);
int isBothInPub(TrainInfo a,TrainInfo b); 
int IsNextInPubluic(TrainInfo a);
void FileWriteOut(TrainInfo* train,FILE *fp,int OutputTime);
int patten;
HEGG TA;
HEGG TB;
HEGG TC;
HEGG rail;
HEGG backdrop;
HEGG lightG1;
HEGG lightR1; 
HEGG lightG2;
HEGG lightR2; 

void Creatmap(TrainInfo train[4]);


#endif
