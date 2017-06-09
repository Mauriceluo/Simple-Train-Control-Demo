/*
л 
*/ 
#include"TrainHeadfile.h"
void SetDefaultSet(TrainInfo set[]) {//Ĭ���������� 
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
			printf("--------\nA�������ٶ�:%d\nA����ʼʱ��:%d\nA�����з���:%d\nA����ʼλ��:%d\nA��ͣ��ʱ��:%d\nA������:%d\n--------\n",set[1].train_speed,set[1].train_start_time,set[1].train_direction,set[1].train_start_1D,set[1].train_pause_time,set[1].train_type);
			break;
		case 2:
			printf("--------\nB�������ٶ�:%d\nB����ʼʱ��:%d\nB�����з���:%d\nB����ʼλ��:%d\nB��ͣ��ʱ��:%d\nB������:%d\n--------\n",set[2].train_speed,set[2].train_start_time,set[2].train_direction,set[2].train_start_1D,set[2].train_pause_time,set[2].train_type);
			break;
		case 3:
			printf("--------\nC�������ٶ�:%d\nC����ʼʱ��:%d\nC�����з���:%d\nC����ʼλ��:%d\nC��ͣ��ʱ��:%d\nC������:%d\n--------\n",set[3].train_speed,set[3].train_start_time,set[3].train_direction,set[3].train_start_1D,set[3].train_pause_time,set[3].train_type);
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
		printf("������%c������(1����쳵��2��������):",carname);
		scanf("%d",&set[order].train_type);
		if(set[order].train_type==2) {
			slowtypeset[slowtype]=order;//��������
			slowtype++;
		}
		if(set[order].train_type==1) {
			fasttypeset[slowtype]=order;//�쳵����
			fasttype++;
		}

		if(set[order].train_type!=1&&set[order].train_type!=2) {
			printf("Error Input!\n");
			continue;
		}
		printf("������%c�������ٶ�(�쳵�ٶ������2,�����ٶ���С�ڿ쳵,�ٶȲ��ɴ��ڵ��ڹ������:%d):",carname,2*(set[order].train_orbit_L+set[order].train_orbit_W));
		scanf("%d",&set[order].train_speed);
		if(set[order].train_speed<=0||set[order].train_speed>=2*(set[order].train_orbit_L+set[order].train_orbit_W)) {
			printf("Error Input!");
			continue;
		} else {
			if(set[order].train_type==1) { //�жϿ쳵�ٶ��Ƿ��������
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
				if(set[order].train_type==2) { //�ж������ٶ��Ƿ����ڿ쳵
					for(a=0; a<fasttype; a++) {
						if(set[order].train_speed>=set[fasttypeset[a]].train_speed) {
							printf("Error Input!");
							continue;
						}
					}
				}
			}
		}
		printf("������%c����ʼʱ��:",carname);
		scanf("%d",&set[order].train_start_time);
		if(set[order].train_start_time<0) {
			printf("Error Input!\n");
			continue;
		}
		printf("������%c�����з���(˳ʱ��Ϊ1,��ʱ��Ϊ2):",carname);
		scanf("%d",&set[order].train_direction);
		if(set[order].train_direction!=1&&set[order].train_direction!=2) {
			printf("Error Input!\n");
			continue;
		}
		printf("������%c����ʼλ��(����ڲο����λ��,˳ʱ��Ϊ��,��С�ڹ���ܳ���:%d):",carname,2*(set[order].train_orbit_L+set[order].train_orbit_W));
		scanf("%d",&set[order].train_start_1D);
		if(set[order].train_start_1D<0||set[order].train_start_1D>=2*(set[order].train_orbit_L+set[order].train_orbit_W)) {
			printf("Error Input!\n");
			continue;
		}
		printf("������%c��ͣ��ʱ��:",carname);
		scanf("%d",&set[order].train_pause_time);
		if(set[order].train_pause_time<0) {
			printf("Error Input!\n");
			continue;
		}
		OutputSet(set,order);
		printf("�Ƿ�������ȷ?(Y/N)\n");
		getchar();
		scanf("%c",&tempinput);
		if(tempinput=='Y')
			tempinputflag=1;
	}
}
