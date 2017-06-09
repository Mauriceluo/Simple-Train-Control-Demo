/*
罗 
*/
#include"TrainHeadfile.h"
void LoadInfo(TrainInfo* train1,TrainInfo* train2,TrainInfo* train3,int CreatMap)
{
	int Y2=50,X3=50;
    int L1=250,W1=250,L2=150,W2=150,L3=150,W3=150;
//    int a[251][251]={0};
    int i,j,k;
    int state;
	
	if(CreatMap==1){
		/*轨道1*/
	printf("轨道1参数:\n**请输入轨道1的长和宽:"); 
    scanf("%d %d",&L1,&W1);
    while(L1<0||W1<0||L1>=1000||W1>=1000)
    {
    	printf("输入错误!\n**请重新输入长和宽:");
    	scanf("%d %d",&L1,&W1);
    }
    
    /*轨道2*/ 
    printf("轨道2参数:\n**请输入轨道2左上角点的纵坐标(探测点):");
    scanf("%d",&Y2);
	while(Y2<0||Y2>W1-1)
	{
		printf("输入错误!\n**请重新输入纵坐标:");
		scanf("%d",&Y2);
	} 
	printf("**请输入轨道2的长和宽:");
	scanf("%d %d",&L2,&W2);
	while(Y2+W2>W1)
	{
		printf("输入错误!\n**现在有如下选择\n  1--重新输入长和宽\n  2--重新输入纵坐标并输入长宽\n");
		
		printf("**输入选择:");
		scanf("%d",&state);
		while(state!=0&&state!=1)
		{
			printf("**输入错误!\n**重新输入选择:");
			scanf("%d",&state);
		}
		if(state==0)
		{
     		printf("**请输入轨道2的长和宽:");
	        scanf("%d %d",&L2,&W2);
		}
		else if(state==1)
		{
			printf("**请输入轨道2左上角点纵坐标:");
            scanf("%d",&Y2);
            while(Y2<0||Y2>W1-1)
            {
	            printf("输入错误!\n**请重新输入纵坐标:");
	            scanf("%d",&Y2);
            }
            printf("**请输入轨道2的长和宽:");
            scanf("%d %d",&L2,&W2);
		}
	}
	
	/*轨道3*/
	printf("轨道3参数:\n**请输入轨道3左上角点的横坐标(探测点):");
    scanf("%d",&X3);
	while(X3<0||X3>L1-1)
	{
		printf("输入错误!\n**请重新输入纵坐标:");
		scanf("%d",&X3);
	} 
	printf("**请输入轨道3的长和宽:");
	scanf("%d %d",&L3,&W3);
	while(X3+L3>L1)
	{
		printf("输入错误!\n**现在有如下选择\n  1--重新输入长和宽\n  2--重新输入横坐标并输入长宽\n");
		printf("**输入选择:");
		scanf("%d",&state);
		while(state!=0&&state!=1)
		{
			printf("**输入错误!\n**重新输入选择:");
			scanf("%d",&state);
		}
		if(state==0)
		{
     		printf("**请输入轨道3的长和宽:");
	        scanf("%d %d",&L3,&W3);
		}
		else if(state==1)
		{
			printf("**请输入轨道3左上角点横坐标:");
            scanf("%d",&X3);
            while(X3<0||X3>L1-1)
            {
	            printf("输入错误!\n**请重新输入横坐标:");
	            scanf("%d",&X3);
            }
            printf("**请输入轨道2的长和宽:");
            scanf("%d %d",&L3,&W3);
		}
	} 
	}
	
/*if(CreatMap==0){
	L1=(*train1).train_orbit_L;
    W1=(*train1).train_orbit_W;
    
	L2=(*train2).train_orbit_L;
    W2=(*train2).train_orbit_W;
    
	L3=(*train3).train_orbit_L;
    W3=(*train3).train_orbit_W;
    Y2=(*train2).train_datum_point.y;
    X3=(*train3).train_detect_2D_1.x;
}	
	/*作图*/
/*	printf("\n\n");
	for(j=0;j<=L1;j++)
	{
		a[j][0]=1;
		a[j][W1]=1;
	}
	for(j=L1;j<=L1+L2;j++)
	{
		a[j][Y2]=1;
		a[j][Y2+W2]=1;
	}
	for(j=X3;j<=X3+L3;j++)
	{
		a[j][W1+W3]=1;
	}
	j=0;
	for(k=0;k<=W1;k++)
	{
		a[0][k]=1;
		a[L1][k]=1;
	}
	for(k=Y2;k<=Y2+W2;k++)
	{
		a[L1+L2][k]=1;
	}
	for(k=W1;k<=W1+W3;k++)
	{
		a[X3][k]=1;
		a[X3+L3][k]=1;
	}
	for(j=0;j<=L1+L2;j++)
	{
		for(k=0;k<=W1+W3;k++)
		{
			if(a[j][k]==0)
			{
				printf("  ");
			}
			else if(a[j][k]==1)
			{
				printf("□");
			}
		}
		printf("\n");
	}
	
	/*数据*/
	printf("因为不考虑车的加速度,故探测点是重合轨道两端点\n\n"); 
	printf("\n\n\n轨道1:\n**长:%d\n**宽:%d\n**基准点:(0,0)\n",L1,W1);
	printf("**探测点1:(%d,%d)  探测点2:(%d,%d)\n**探测点3:(%d,%d)  探测点4:(%d,%d)\n\n",L1,Y2,L1,Y2+W2,X3,W1,X3+L3,W1); 
	
	printf("轨道2:\n**长:%d\n**宽:%d\n**基准点:(%d,%d)\n",L2,W2,L1,Y2);
	printf("**探测点1:(%d,%d)  探测点2:(%d,%d)\n\n",L1,Y2,L1,Y2+W2);
	
	printf("轨道3:\n**长:%d\n**宽:%d\n**基准点:(%d,%d)\n",L3,W3,X3,W1);
    printf("**探测点1:(%d,%d)  探测点2:(%d,%d)\n\n",X3,W1,X3+L3,W1);

    /*赋值*/
    (*train1).train_num=1;
    (*train2).train_num=2;
    (*train3).train_num=3;
    
    (*train1).train_orbit_L=L1;
    (*train1).train_orbit_W=W1;
    
	(*train2).train_orbit_L=L2;
    (*train2).train_orbit_W=W2;
    
	(*train3).train_orbit_L=L3;
    (*train3).train_orbit_W=W3;
    
	(*train1).train_datum_point.x=0;
    (*train1).train_datum_point.y=0;
    
	(*train2).train_datum_point.x=L1;
    (*train2).train_datum_point.y=Y2;
    
	(*train3).train_datum_point.x=X3;
    (*train3).train_datum_point.y=W1;
    
	
}
