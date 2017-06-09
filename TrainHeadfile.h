/*
罗
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

	/*车号*/
	int train_num;
	/*快慢与方向*/
	int train_type;//快车是1,慢车是2
	int train_direction;//顺时针1,逆时针2
	/*基准点*/
	Position train_datum_point;//该车基准点坐标(二维)(轨道原点)(左上)
	/*启动位置*/
	int train_start_1D; //启动位置(一维)
	Position train_start_2D;//启动位置(二维)
	/*探测点*/
	int train_detect_1D_1;//探测点1(一维)//计算
	Position train_detect_2D_1;//探测点1(二维)//输出
	int train_detect_1D_2;//探测点2(一维)//计算
	Position train_detect_2D_2;//探测点2(二维)//输出
	int train_detect_1D_3;//探测点3(一维)//计算(Orbit 1)
	Position train_detect_2D_3;//探测点3(二维)//输出
	int train_detect_1D_4;//探测点4(一维)//计算(Orbit 1)
	Position train_detect_2D_4;//探测点4(二维)//输出
	/*启动时间*/
	int train_start_time;//只能大于等于0
	/*运行速度*/
	int train_speed;//只能大于等于1,有上限的
	/*停靠*/
	int train_pause_time;//大于等于0
	/*车当前位置*/
	int train_distance_1D;//1D,别忘加启动位置(走了多少)
	Position train_distance_2D;//2D
	/*车下一秒位置*/
	int train_next;
	/*轨道参数*/
	int train_orbit_L;
	int train_orbit_W;
	/*车的状态*/
	int train_state;//0运行中 1等待进站 2在站台等待 3进站 4出站 5shabi用户要停止
	/*站台*/
	int station1;
	int station2;
	/*当前时间*/
    int time; 
 	int before;
	int timeofkey;
	struct Traininfo *tptr1;
	struct Traininfo *tptr2;
};//只有三辆哦~
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
