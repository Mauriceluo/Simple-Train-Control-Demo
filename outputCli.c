#include"TrainHeadfile.h"
/*���������*/
/*
1����ǰʱ��
2����ǰ����
3��3�������з���
4�� 3��������״̬�����ٰ�������-�ǹ������������-�����������ͣ-�ȴ����������ͣ��-ռ�ù����������ʾͣ������ʱʱ�䣩������������ͣ��״̬
5��3���𳵵�ǰλ��
6�����������״̬�����С���X��ռ�ã�
*/
void PrintTrainInfo(TrainInfo* train,int OutputTime,int caidan) {
	/*��ǰʱ���ں�����(������)���*/

	/*��ǰ�����Ѿ������*/

	/*A*/
/*	printf("��ǰʱ�䣺%d\n",OutputTime);
	printf("[A��]\n");
	printf("���з���:");
	if(train[0].train_direction==1)
		printf("˳ʱ��\n");
	else
		printf("��ʱ��\n");

	printf("����״̬:");
	if(train[0].train_state==-1)
		printf("����\n");
	else if(train[0].train_state==0)
		printf("����-�ǹ������\n");
	else if(train[0].train_state==1)
		printf("��ͣ-�ȴ��������\n");
	else if(train[0].train_state==2)
		printf("ͣ��-ռ�ù������(����ȴ�%ds)\n",train[0].train_pause_time);
	else if(train[0].train_state==3)
		printf("����-�������\n");
	else if(train[0].train_state==4)
		printf("����-�������\n");
	else if(train[0].train_state==5)
		printf("����������ͣ��״̬\n");

	printf("��ǰλ��:(%d,%d)\n",train[0].train_distance_2D.x,train[0].train_distance_2D.y);
    
	printf("%d\n",train[0].train_distance_1D);
	printf("%d\n",train[0].train_next); 
    printf("%d\n",train[0].train_state);
    printf("DETECT 2 %d\n",train[0].train_detect_1D_2);
    
	/*B*/
/*	printf("[B��]\n");
	printf("���з���:");
	if(train[1].train_direction==1)
		printf("˳ʱ��\n");
	else
		printf("��ʱ��\n");

	printf("����״̬:");
	if(train[1].train_state==-1)
		printf("����\n");
	else if(train[1].train_state==0)
		printf("����-�ǹ������\n");
	else if(train[1].train_state==1)
		printf("��ͣ-�ȴ��������\n");
	else if(train[1].train_state==2)
		printf("ͣ��-ռ�ù������(����ȴ�%ds)\n",train[1].train_pause_time);
	else if(train[1].train_state==3)
		printf("����-�������\n");
	else if(train[1].train_state==4)
		printf("����-�������\n");
	else if(train[1].train_state==5)
		printf("����������ͣ��״̬\n");

	printf("��ǰλ��:(%d,%d)\n",train[1].train_distance_2D.x,train[1].train_distance_2D.y);
    
	printf("%d\n",train[1].train_distance_1D);
	printf("%d\n",train[1].train_next);
    printf("%d\n",train[1].train_state);
    printf("̽��2 %d\n",train[1].train_detect_1D_2); 
    printf("2�쳤�� %d\n",train[1].train_orbit_L);
    
	/*C*/
/*	printf("[C��]\n");
	printf("���з���:");
	if(train[2].train_direction==1)
		printf("˳ʱ��\n");
	else
		printf("��ʱ��\n");

	printf("����״̬:");
	if(train[2].train_state==-1)
		printf("����\n");
	else if(train[2].train_state==0)
		printf("����-�ǹ������\n");
	else if(train[2].train_state==1)
		printf("��ͣ-�ȴ��������\n");
	else if(train[2].train_state==2)
		printf("ͣ��-ռ�ù������(����ȴ�%ds)\n",train[2].train_pause_time);
	else if(train[2].train_state==3)
		printf("����-�������\n");
	else if(train[2].train_state==4)
		printf("����-�������\n");
	else if(train[2].train_state==5)
		printf("����������ͣ��״̬\n");

	printf("��ǰλ��:(%d,%d)\n",train[2].train_distance_2D.x,train[2].train_distance_2D.y);
    
	printf("%d\n",train[2].train_distance_1D);
	printf("%d\n",train[2].train_next);
    printf("%d\n",train[2].train_state);
    
	/*�Ƿ�ռ�ù������*/
/*	printf("[�������״̬]:");

	if(IsInPubluic(train[0])==0&&IsInPubluic(train[1])==0&&IsInPubluic(train[2])==0)
		printf("����\n\n\n");
	else {
		if(IsInPubluic(train[0])==1)
			printf("��A��ռ�� ");
		if(IsInPubluic(train[1])==1)
			printf("��B��ռ�� ");
		if(IsInPubluic(train[2])==1)
			printf("��C��ռ�� ");
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
	if((outputfile=fopen("�������.ini","a+"))==NULL) {
		printf("Cannot open the file!");
		exit(0);
	} else
		FileWriteOut(train,outputfile,OutputTime);
	fflush(outputfile);
}

int IsInPubluic(TrainInfo a) { //1�� 0����
	if(a.train_num==1) {
		if(a.train_direction==1) { //1��˳ʱ��
			if((a.train_distance_1D<=a.train_detect_1D_2&&a.train_distance_1D>=a.train_detect_1D_1)||(a.train_distance_1D<=a.train_detect_1D_4&&a.train_distance_1D>=a.train_detect_1D_3))
				return 1;
			else
				return 0;
		} else { //1����ʱ��
			if((a.train_distance_1D<=a.train_detect_1D_1&&a.train_distance_1D>=a.train_detect_1D_2)||(a.train_distance_1D<=a.train_detect_1D_3&&a.train_distance_1D>=a.train_detect_1D_4))
				return 1;
			else
				return 0;
		}
	} else { //2��3��
		if(a.train_direction==1) { //2��3��˳ʱ��
			if(a.train_distance_1D<=a.train_detect_1D_2||a.train_distance_1D>=a.train_detect_1D_1)
				return 1;
			else
				return 0;
		} else { //2��3����ʱ��
			if(a.train_distance_1D<=a.train_detect_1D_1||a.train_distance_1D>=a.train_detect_1D_2)
				return 1;
			else
				return 0;
		}
	}
}

