/*
谢 
*/ 
#include"TrainHeadfile.h"
void SetDefaultSet(TrainInfo set[]) {//默认数据输入 
	set[1].train_speed=20;
	set[1].train_start_time=0;
	set[1].train_direction=1;
	set[1].train_start_1D=0;
	set[1].train_type=2;
	set[1].train_pause_time=2; 
	set[2].train_speed=30;
	set[2].train_start_time=0;
	set[2].train_direction=1;
	set[2].train_start_1D=0;
	set[2].train_type=1;
	set[2].train_pause_time=2; 
	set[3].train_speed=45;
	set[3].train_start_time=0;
	set[3].train_direction=1;
	set[3].train_start_1D=0;
	set[3].train_type=1;
	set[3].train_pause_time=2; 
	set[1].timeofkey=set[1].train_pause_time*10;
	set[2].timeofkey=set[2].train_pause_time*10;
	set[3].timeofkey=set[3].train_pause_time*10;

}       
void OutputSet(TrainInfo set[],int order) {
	switch(order) {
		case 1:
			printf("--------\nA车运行速度:%d\nA车起始时间:%d\nA车运行方向:%d\nA车起始位置:%d\nA车停靠时间:%d\nA车类型:%d\n--------\n",set[1].train_speed,set[1].train_start_time,set[1].train_direction,set[1].train_start_1D,set[1].train_pause_time,set[1].train_type);
			break;
		case 2:
			printf("--------\nB车运行速度:%d\nB车起始时间:%d\nB车运行方向:%d\nB车起始位置:%d\nB车停靠时间:%d\nB车类型:%d\n--------\n",set[2].train_speed,set[2].train_start_time,set[2].train_direction,set[2].train_start_1D,set[2].train_pause_time,set[2].train_type);
			break;
		case 3:
			printf("--------\nC车运行速度:%d\nC车起始时间:%d\nC车运行方向:%d\nC车起始位置:%d\nC车停靠时间:%d\nC车类型:%d\n--------\n",set[3].train_speed,set[3].train_start_time,set[3].train_direction,set[3].train_start_1D,set[3].train_pause_time,set[3].train_type);
			break;
	}
}
void InputSet(TrainInfo set[],int order) {
	char carname,tempinput;
	int fasttypeset[3],slowtypeset[3];
	int fasttype=0,slowtype=0,a;
	if(order==1)
		carname='A';
	else if(order==2)
		carname='B';
	else
		carname='C';
	int tempinputflag=0;
	for(; tempinputflag==0;) {
		printf("请输入%c车类型(1代表快车，2代表慢车):",carname);
		scanf("%d",&set[order].train_type);
		if(set[order].train_type==2) {
			slowtypeset[slowtype]=order;//慢车储存
			slowtype++;
		}
		if(set[order].train_type==1) {
			fasttypeset[slowtype]=order;//快车储存
			fasttype++;
		}

		if(set[order].train_type!=1&&set[order].train_type!=2) {
			printf("Error Input!\n");
			continue;
		}
		printf("请输入%c车运行速度(快车速度需大于2,慢车速度需小于快车,速度不可大于等于轨道长度:%d):",carname,2*(set[order].train_orbit_L+set[order].train_orbit_W));
		scanf("%d",&set[order].train_speed);
		if(set[order].train_speed<=0||set[order].train_speed>=2*(set[order].train_orbit_L+set[order].train_orbit_W)) {
			printf("Error Input!");
			continue;
		} else {
			if(set[order].train_type==1) { //判断快车速度是否快于慢车
				if(set[order].train_speed<2) {
					printf("Error Input!");
					continue;
				}
				for(a=0; a<slowtype; a++) {
					if(set[order].train_speed<=set[slowtypeset[a]].train_speed) {
						printf("Error Input!");
						continue;
					}
				}
			} else {
				if(set[order].train_type==2) { //判断慢车速度是否慢于快车
					for(a=0; a<fasttype; a++) {
						if(set[order].train_speed>=set[fasttypeset[a]].train_speed) {
							printf("Error Input!");
							continue;
						}
					}
				}
			}
		}
		printf("请输入%c车起始时间:",carname);
		scanf("%d",&set[order].train_start_time);
		if(set[order].train_start_time<0) {
			printf("Error Input!\n");
			continue;
		}
		printf("请输入%c车运行方向(顺时针为1,逆时针为2):",carname);
		scanf("%d",&set[order].train_direction);
		if(set[order].train_direction!=1&&set[order].train_direction!=2) {
			printf("Error Input!\n");
			continue;
		}
		printf("请输入%c车起始位置(相对于参考点的位移,顺时针为正,且小于轨道总长度:%d):",carname,2*(set[order].train_orbit_L+set[order].train_orbit_W));
		scanf("%d",&set[order].train_start_1D);
		if(set[order].train_start_1D<0||set[order].train_start_1D>=2*(set[order].train_orbit_L+set[order].train_orbit_W)) {
			printf("Error Input!\n");
			continue;
		}
		printf("请输入%c车停靠时间:",carname);
		scanf("%d",&set[order].train_pause_time);
		if(set[order].train_pause_time<0) {
			printf("Error Input!\n");
			continue;
		}
		OutputSet(set,order);
		printf("是否输入正确?(Y/N)\n");
		getchar();
		scanf("%c",&tempinput);
		if(tempinput=='Y')
			tempinputflag=1;
	}
}
