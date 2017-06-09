#include"TrainHeadfile.h"
/*命令行输出*/
/*
1）当前时间
2）当前策略
3）3辆火车运行方向
4） 3辆火车运行状态，至少包含运行-非公共轨道，运行-公共轨道、暂停-等待公共轨道、停靠-占用公共轨道（显示停靠倒计时时间）、接受命令暂停等状态
5）3辆火车当前位置
6）公共轨道的状态（空闲、被X车占用）
*/
void PrintTrainInfo(TrainInfo* train,int OutputTime,int caidan) {
	/*当前时间在函数外(主函数)输出*/

	/*当前策略已经输出过*/

	/*A*/
/*	printf("当前时间：%d\n",OutputTime);
	printf("[A车]\n");
	printf("运行方向:");
	if(train[0].train_direction==1)
		printf("顺时针\n");
	else
		printf("逆时针\n");

	printf("运行状态:");
	if(train[0].train_state==-1)
		printf("错误\n");
	else if(train[0].train_state==0)
		printf("运行-非公共轨道\n");
	else if(train[0].train_state==1)
		printf("暂停-等待公共轨道\n");
	else if(train[0].train_state==2)
		printf("停靠-占用公共轨道(还需等待%ds)\n",train[0].train_pause_time);
	else if(train[0].train_state==3)
		printf("运行-公共轨道\n");
	else if(train[0].train_state==4)
		printf("运行-公共轨道\n");
	else if(train[0].train_state==5)
		printf("接受命令暂停等状态\n");

	printf("当前位置:(%d,%d)\n",train[0].train_distance_2D.x,train[0].train_distance_2D.y);
    
	printf("%d\n",train[0].train_distance_1D);
	printf("%d\n",train[0].train_next); 
    printf("%d\n",train[0].train_state);
    printf("DETECT 2 %d\n",train[0].train_detect_1D_2);
    
	/*B*/
/*	printf("[B车]\n");
	printf("运行方向:");
	if(train[1].train_direction==1)
		printf("顺时针\n");
	else
		printf("逆时针\n");

	printf("运行状态:");
	if(train[1].train_state==-1)
		printf("错误\n");
	else if(train[1].train_state==0)
		printf("运行-非公共轨道\n");
	else if(train[1].train_state==1)
		printf("暂停-等待公共轨道\n");
	else if(train[1].train_state==2)
		printf("停靠-占用公共轨道(还需等待%ds)\n",train[1].train_pause_time);
	else if(train[1].train_state==3)
		printf("运行-公共轨道\n");
	else if(train[1].train_state==4)
		printf("运行-公共轨道\n");
	else if(train[1].train_state==5)
		printf("接受命令暂停等状态\n");

	printf("当前位置:(%d,%d)\n",train[1].train_distance_2D.x,train[1].train_distance_2D.y);
    
	printf("%d\n",train[1].train_distance_1D);
	printf("%d\n",train[1].train_next);
    printf("%d\n",train[1].train_state);
    printf("探测2 %d\n",train[1].train_detect_1D_2); 
    printf("2轨长度 %d\n",train[1].train_orbit_L);
    
	/*C*/
/*	printf("[C车]\n");
	printf("运行方向:");
	if(train[2].train_direction==1)
		printf("顺时针\n");
	else
		printf("逆时针\n");

	printf("运行状态:");
	if(train[2].train_state==-1)
		printf("错误\n");
	else if(train[2].train_state==0)
		printf("运行-非公共轨道\n");
	else if(train[2].train_state==1)
		printf("暂停-等待公共轨道\n");
	else if(train[2].train_state==2)
		printf("停靠-占用公共轨道(还需等待%ds)\n",train[2].train_pause_time);
	else if(train[2].train_state==3)
		printf("运行-公共轨道\n");
	else if(train[2].train_state==4)
		printf("运行-公共轨道\n");
	else if(train[2].train_state==5)
		printf("接受命令暂停等状态\n");

	printf("当前位置:(%d,%d)\n",train[2].train_distance_2D.x,train[2].train_distance_2D.y);
    
	printf("%d\n",train[2].train_distance_1D);
	printf("%d\n",train[2].train_next);
    printf("%d\n",train[2].train_state);
    
	/*是否占用公共轨道*/
/*	printf("[公共轨道状态]:");

	if(IsInPubluic(train[0])==0&&IsInPubluic(train[1])==0&&IsInPubluic(train[2])==0)
		printf("空闲\n\n\n");
	else {
		if(IsInPubluic(train[0])==1)
			printf("被A车占用 ");
		if(IsInPubluic(train[1])==1)
			printf("被B车占用 ");
		if(IsInPubluic(train[2])==1)
			printf("被C车占用 ");
		printf("\n\n\n");
	}
	if(caidan==1){
printf("                                                  MMM                         i\n");
printf("                                                OMMMMMM                  #MMMMMMM\n");
printf("                                                MMMMMMMMM  #MM#.Ii`  =MMMMMEIMMMM\n");
printf("                                                MMEMMMOMMMMMMMMMMMMMMMMMM  MMMMMM\n");
printf("                                              MMMMM    `              I   ~MM: MM\n");
printf("                                            MMMO.`.       `  .;o   .:    `:;` ~MMi\n");
printf("                                          ;MMM  +~ ;~ .;..~~`~i IMM8:oMMi .I~`; `\n");
printf("                                         MMM#   E. MMMMM+;::::;:EMMMi~EMMO:;II;;:;I=~\n");
printf("                                     MMMMMM+  E:  MMMM#MMMMI.:i#MMMMMi OME=I;:;;;~~:i++\n");
printf("                                   MMMM~`   `.` :MMMMMM :#M#I;i=MMMMM#=o#o;;;;=:;;;;;:.iMMI\n");
printf("                                  MMM;  +8:~=Oi=~MMMMMMMi~IOoI~I:=#MME+=O=;O8I;;;;;;;;;oMMMMM\n");
printf("                                 IMMM.~`   `~=OI~~MMMMMM#I;~` ```~~~.``~;i+I;I=;;;;Ii+o`. =MMM\n");
printf("                                ~MM                        `i~                              MM\n");
printf("                                 MM=                  .=oi.`~.  .EMMM:                     MMM\n");
printf("                                 :MMM                 .OMMMMoEMMMMMi.                     MMM\n");
printf("                                   MMMM                 .OMMMMMMM+                      MMM\n");
printf("                                    +MMMMMM                                         MMMMMM\n");
printf("                                       IMMMMMMMMMMMMMMMi=;~``~IEMM#MMMMMMMMMMMMMMMMMMMM\n");
printf("                                           +MM    `MMMMMMMMMMMMMMMMMMMMM;     `.     MM#\n");
printf("                                            MM    MMMMMME`           8M              `iMM\n");
printf("                               8MMM;        MM;  MMM       :I   o#. EMM`   OMMMMMMM   : MM`\n");
printf("                              MMMMMMMI    MMMMMMMMo   =MMMMMMM#`:;;:IMMMMMMMM: MMMM    ~ MM+\n");
printf("                              MMMMMMMMM 8MMM+ +MM  `MMMMM8o+MMMM .;`. =MMO~..:I= +MMM     MM#\n");
printf("                              MMMMMMMMMMMMMMMMMMMMMMMMi  MMMMMMM~i8Oo.:`~I+oiI: `   MMM  .~MMO\n");
printf("                            MMMMM`   .`            .~.``:MM` MMM                     =MM   `MM\n");
printf("                          MMM+`;  .   .~~...::.  `I.  .;:~  EMMM                      oMMM  oM~\n");
printf("                        ;MMM`  ` `. `i.~:.~I:~ioMM;=MM;~~;II.  `:~`                     MMMM MM\n");
printf("                       MMMM  i#~:MMMMM+.:~~;:;8MMMo`+MM=;;II;I=;;=+i~                 oMMMMM 8M\n");
printf("                   MMMMMM+ .EI  MMMM+;MMM+:I=MMMMMM=.=EE=;;;:~:~~:;I:                 MME=   MMM\n");
printf("                 MMMM        ``MMMMMM .MM8==:+MMMMME:iMo;~;=I;;;;;;;IOMMM            ;MM     `MM`\n");
printf("                MMM+ .O8.`+E+=OMMMMMMM~.+#+;;I:E#MM#iI+I===I;;:.IoI~~#MMMMM          MM+       MMME\n");
printf("               MMME;..    ;oI~.iMMMMMMM:~.``~~~`.~;~`.I=ii==I;;=;;=o+.  =MMM        #MM          MMM\n");
printf("               MM;                      ~MMMMM#~.~~`             `       `MMM      8MM        :MMMi\n");
printf("              `MM                        .OI                              MMM     MMM+       MMM\n");
printf("               8M8                   ~o;` `.```oMMM~                     MMM     MMM       MMM\n");
printf("                MMM                 .8MMMM#E#MMMM;                      MMM OMMMMMMMMMMMMMMM\n");
printf("                 MMMM                 `~#MMMMMMI                      MMM     .MMMMMMMMOMME\n");
printf("                 IMMMMMMM~                                        MMMMMMMMMMMMMMMMMMMMMMMMi\n");
printf("                 MMMMMMMMMMMMMMMMMMME+;`    `` o8MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM.\n");
printf("                  .;IoEMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMi++I\n");
	}        */                                       
	FILE *outputfile;
	if((outputfile=fopen("输出数据.ini","a+"))==NULL) {
		printf("Cannot open the file!");
		exit(0);
	} else
		FileWriteOut(train,outputfile,OutputTime);
	fflush(outputfile);
}

int IsInPubluic(TrainInfo a) { //1在 0不在
	if(a.train_num==1) {
		if(a.train_direction==1) { //1车顺时针
			if((a.train_distance_1D<=a.train_detect_1D_2&&a.train_distance_1D>=a.train_detect_1D_1)||(a.train_distance_1D<=a.train_detect_1D_4&&a.train_distance_1D>=a.train_detect_1D_3))
				return 1;
			else
				return 0;
		} else { //1车逆时针
			if((a.train_distance_1D<=a.train_detect_1D_1&&a.train_distance_1D>=a.train_detect_1D_2)||(a.train_distance_1D<=a.train_detect_1D_3&&a.train_distance_1D>=a.train_detect_1D_4))
				return 1;
			else
				return 0;
		}
	} else { //2或3车
		if(a.train_direction==1) { //2或3车顺时针
			if(a.train_distance_1D<=a.train_detect_1D_2||a.train_distance_1D>=a.train_detect_1D_1)
				return 1;
			else
				return 0;
		} else { //2或3车逆时针
			if(a.train_distance_1D<=a.train_detect_1D_1||a.train_distance_1D>=a.train_detect_1D_2)
				return 1;
			else
				return 0;
		}
	}
}

