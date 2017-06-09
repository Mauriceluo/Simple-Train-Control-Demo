/*
罗 0运行中 1等待进站 2在站台等待 3进站 4出站 5用户想停下
*/
#include"TrainHeadfile.h"
//(*((*train).tptr2))
void ControlTrain(TrainInfo* train) 
{	
	if((*train).train_distance_1D<0)
		(*train).train_distance_1D+=2*(*train).train_orbit_L+2*(*train).train_orbit_W;
	
	(*train).train_next=(*train).train_distance_1D+(*train).train_speed*0.1;//不断更新next
    


/*零 运行中*/
	if((*train).train_state==0) 
	{ //车在公共轨道外行驶
		if(ReadytoJudge(*train)==1) 
		{ //要进入
			if((*train).train_num==1) 
				{
				if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
					{
					if(ReadytoJudge((*((*train).tptr2)))==1) 
					{ //也要进入（3车）
						if(run_method==1)
						{//快车先行 
							if((*train).train_speed>(*((*train).tptr2)).train_speed)
						    { //1比3快
							    (*train).train_state=3;//1车进站
							    (*((*train).tptr2)).train_state=1;//3车等待进站
						    } 
							else 
							{ //包括相等
							    (*train).train_state=1;//1车等待进站
							    (*((*train).tptr2)).train_state=3;
							}//3车进站
						}
						else
						{//交替
							if((*train).before==0)
							{
								(*train).train_state=3;//1车进站
							    (*((*train).tptr2)).train_state=1;//3车等待进站
							    (*train).before=1;
							    (*((*train).tptr2)).before=0;
							}
							else
							{
								(*train).train_state=1;//1车等待进站
							    (*((*train).tptr2)).train_state=3;
							    (*train).before=0;
							    (*((*train).tptr2)).before=1;
							}
						} 
					} 
					else 
					{ //3车不进入
						(*train).train_state=3;//1车进站
					}
				} 
				else if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
				{
					if(ReadytoJudge((*((*train).tptr1)))==1) 
					{ //2车也要进入
						if(run_method==1)
						{
							if((*train).train_speed>(*((*train).tptr1)).train_speed) 
							{ //1车比2车快
							    (*train).train_state=3;//1车进站
							    (*((*train).tptr1)).train_state=1;//2车等待进站
						    } 
							else 
							{ //包括相等
							    (*train).train_state=1;//1车等待进站
							    (*((*train).tptr1)).train_state=3;//2车进站
						    }
						}
						else
						{
							if((*train).before==0)
							{
								(*train).train_state=3;//1车进站
							    (*((*train).tptr1)).train_state=1;//2车等待进站
							    (*train).before=1;
							    (*((*train).tptr1)).before=0;
							}
							else
							{
								(*train).train_state=1;//1车等待进站
							    (*((*train).tptr1)).train_state=3;
							    (*train).before=0;
							    (*((*train).tptr1)).before=1;
							}
						}
	
					} 
					else 
					{ //2车不进入
						(*train).train_state=3;//1车进站
					}
				}
			} 
			else 
	        { //车号不是1
				if(ReadytoJudge((*((*train).tptr1)))==1) 
				{ //1车也要进入
					if(run_method==1)
					{
						if((*((*train).tptr1)).train_distance_1D<=(*((*train).tptr1)).train_orbit_L+(*((*train).tptr1)).train_orbit_W)
		                {
            			    if((*train).train_num==2)
            			    {
			            	    if((*train).train_speed>(*((*train).tptr1)).train_speed) 
					            { //2车比1车快
				                    (*train).train_state=3;//2车进站
						            (*((*train).tptr1)).train_state=1;//1车等待进站
					            }
					            else 
					            {
						            (*train).train_state=1;//2车等待进站
						            (*((*train).tptr1)).train_state=3;//1车进站
					            }
			                }
			                else//是3车 
			                {
            				    (*train).train_state=3;//3车正常进站
            			    } 
            		    }
            	  	    else//在下半部分
					    {
						    if((*train).train_num==3)
            			    {
			            	    if((*train).train_speed>(*((*train).tptr1)).train_speed) 
					            { //3车比1车快
				                    (*train).train_state=3;//3车进站
						            (*((*train).tptr1)).train_state=1;//1车等待进站
					            }
					            else 
					            {
						            (*train).train_state=1;//3车等待进站
						            (*((*train).tptr1)).train_state=3;//1车进站
					            }
			                }
			                else//是2车 
			                {
            				    (*train).train_state=3;//2车正常进站
            			    } 
					    }
		            }
					else
					{//交替
					    if((*((*train).tptr1)).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W)
		                {
            			    if((*train).train_num==2)
            			    {
			            	    if((*train).before==0)
		  	                    {
							        (*train).train_state=3;//2车进站
						    		(*((*train).tptr1)).train_state=1;//1车等待进站
						    		(*train).before=1;
						    		(*((*train).tptr1)).before=0;
								}
								else
								{
									(*train).train_state=1;//2车等待进站
						    		(*((*train).tptr1)).train_state=3;
						    		(*train).before=0;
						    		(*((*train).tptr1)).before=1;
								}
			                }
			                else//是3车 
			                {
            				    (*train).train_state=3;//3车正常进站
							    (*((*train).tptr1)).train_state=3;//1也正常进站 
            			    } 
            		    }
            	  	    else//在下半部分
					    {
						    if((*train).train_num==3)
            			    {
			            	    if((*train).before==0)
		  	            		{
									(*train).train_state=3;//3车进站
						    		(*((*train).tptr1)).train_state=1;//1车等待进站
						    		(*train).before=1;
						    		(*((*train).tptr1)).before=0;
								}
								else
								{
									(*train).train_state=1;//3车等待进站
						    		(*((*train).tptr1)).train_state=3;
						    		(*train).before=0;
						    		(*((*train).tptr1)).before=1;
								}
			                }
			                else//是2车 
			                {
            				    (*train).train_state=3;//2车正常进站
							    (*((*train).tptr1)).train_state=3;//1也正常进站 
            			    } 
					    }
					}
				} 
				else 
				{ //1车不进入
					(*train).train_state=3;//2或3车进站
				}
			}
		}
	}

	/*一 等待进站*/
	else if((*train).train_state==1) 
	{
		if((*train).train_num==1) 
		{ //是1车等待
			if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
			{
				if((*((*train).tptr2)).train_state==0)//3车已经进入非公共轨道
					(*train).train_state=3;
			}
			else if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
			{
				if((*((*train).tptr1)).train_state==0)//2车已经进入非公共轨道
					(*train).train_state=3;
			}
		} 
		else 
		{ //2或3车在等待
			if((*((*train).tptr1)).train_state==0)//1车进入公共轨道
				(*train).train_state=0;
		}
	}

	/*二 在站台等待*/
	else if((*train).train_state==2) 
	{
		if((*train).timeofkey<=0)
			(*train).train_state=4;
	}

	/*三 进站*/
	else if((*train).train_state==3) 
	{
		if((*train).train_next+(*train).train_speed*0.1>=2*(*train).train_orbit_L+2*(*train).train_orbit_W)
        {
        	(*train).train_next-=2*(*train).train_orbit_L+2*(*train).train_orbit_W;
        	(*train).train_next+=(*train).train_speed*0.1;
        }
		//printf("next %d\n",(*train).train_next);
		if((*train).train_direction==1)
	    { //顺时针
			if((*train).train_num==1) 
			{ //1车
				if((*train).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W)//上半面 
				{
					if((*train).train_next>=(*train).station1)
					(*train).train_state=2;
				}
				else
				{
					if((*train).train_next>=(*train).station2)
					(*train).train_state=2;
				}
			} 
			else 
			{ //2或3车
				if((*train).train_next>=(*train).station1) 
				{
					(*train).train_state=2;
				}
			}
		} 
		else 
		{ //逆时针
			if((*train).train_num==1) 
			{ //1车
				if((*train).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W)//上半面 
			    {
			    	if((*train).train_next<=(*train).station1)
					(*train).train_state=2;
				}
				else
				{
					if((*train).train_next<=(*train).station2)
					(*train).train_state=2;
				}
			} 
			else 
			{ //2或3车
				if((*train).train_next<=(*train).station1) 
				{
					(*train).train_state=2;
				}
			}
		}
	}

	/*四 出站*/
	else if((*train).train_state==4) 
	{
		if((*train).train_num==1)
	    { //1车
			if((*train).train_direction==1) 
			{ //1车顺时针
				if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //下半部分
					if((*train).train_distance_1D+(*train).train_speed*0.1>(*train).train_detect_1D_4)
					{
						(*train).train_state=0;
					}	
					else
					{
						(*train).train_state=4;
					} 
				} 
				else if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //上半部分
					if((*train).train_distance_1D+(*train).train_speed*0.1>(*train).train_detect_1D_2)
					{
						(*train).train_state=0;
					}	
					else
					{
						(*train).train_state=4;
					} 
				}
			} 
			else if((*train).train_direction==2) 
			{ //1车逆时针
				if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //上半部分
					if((*train).train_distance_1D+(*train).train_speed*0.1<(*train).train_detect_1D_4)
						(*train).train_state=0;
				}
			    else if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //下半部分
					if((*train).train_distance_1D+(*train).train_speed*0.1<(*train).train_detect_1D_2)
						(*train).train_state=0;
				}
			}

		} 
		else if((*train).train_num==2)
		{ //二车
			if((*train).train_direction==1) 
			{ //2顺时针
				if(((*train).train_distance_1D>(*train).train_detect_1D_2)&&((*train).train_distance_1D<(*train).train_orbit_L))
					(*train).train_state=0;
			} 
			else if((*train).train_direction==2) 
			{ //2逆时针
				if((*train).train_distance_1D<(*train).train_detect_1D_2&&(*train).train_distance_1D>(*train).train_orbit_L+(*train).train_orbit_W)
					(*train).train_state=0;
			}
		}
		else//三车 
		{
			if((*train).train_direction==1)//2顺时针
			{
				if((*train).train_distance_1D>(*train).train_detect_1D_2&&(*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W)
				(*train).train_state=0;
			}
			else if((*train).train_direction==2)//2逆时针
			{
				if((*train).train_distance_1D<(*train).train_detect_1D_2&&(*train).train_distance_1D>2*(*train).train_orbit_L+(*train).train_orbit_W)
				(*train).train_state=0;
			}
		} 
	}

	/*执行操作*/
	if((*train).train_state==0) 
	{ //公共外运行
		//好像没什么要写的
	} 
	else if((*train).train_state==1) 
	{ //等待进站
		(*train).train_speed=0;
		if((*train).train_num==1) 
		{ //1车
			if((*train).train_direction==1) 
			{ //1车顺时针
				if((*train).train_next<=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //1车上
					(*train).train_distance_1D=(*train).train_detect_1D_1;
				} 
				else 
				{ //1车下
					(*train).train_distance_1D=(*train).train_detect_1D_3;
				}
			} 
			else 
			{ //1车逆时针
				if((*train).train_next<=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //1车上
					(*train).train_distance_1D=(*train).train_detect_1D_3;
				} 
				else 
				{ //1车下
					(*train).train_distance_1D=(*train).train_detect_1D_1;
				}
			}
		} 
		else 
		{ //2或3车
			(*train).train_distance_1D=(*train).train_detect_1D_1;
		}

	} 
	else if((*train).train_state==2) 
	{ //在站台停着
		if((*train).train_num==1) 
		{
			if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
			{
				(*train).train_distance_1D=(*train).station2;
			} 
			else 
			{
				(*train).train_distance_1D=(*train).station1;
			}
		} 
		else 
		{
			(*train).train_distance_1D=(*train).station1;
		}
		(*train).train_speed=0;
		if(patten==0)
		{	(*train).timeofkey=(*train).train_pause_time*10;
			patten=1;
		}
		(*train).timeofkey-=1;
	} 
	else if((*train).train_state==3) 
	{ //进站？
		if((*train).train_num==1)
			(*train).train_speed=speed_temp1;
		else if((*train).train_num==2)
			(*train).train_speed=speed_temp2;
		else if((*train).train_num==3){
			(*train).train_speed=speed_temp3;
			
		}
			
	} 
	
	else if((*train).train_state==4)
    { //出站
        patten=0;
		if((*train).train_num==1)
			(*train).train_speed=speed_temp1;
		else if((*train).train_num==2)
			(*train).train_speed=speed_temp2;
		else if((*train).train_num==3)
			(*train).train_speed=speed_temp3;

		if((*train).train_num==1)
			(*train).timeofkey=time_temp1;
		else if((*train).train_num==2)
			(*train).timeofkey=time_temp2;
		else if((*train).train_num==3){
			(*train).timeofkey=time_temp3;
		}
			
	}
	
	(*train).train_distance_1D+=(*train).train_speed*0.1;
	(*train).train_next=(*train).train_distance_1D+(*train).train_speed*0.1;//不断更新next
	

	if((*train).train_distance_1D<0)
		(*train).train_distance_1D+=2*(*train).train_orbit_L+2*(*train).train_orbit_W;
    
    if((*train).train_speed==0)
    {
    	if((*train).train_num==1)
    	(*train).train_next=(*train).train_distance_1D+speed_temp1*0.1;
    	if((*train).train_num==2)
    	(*train).train_next=(*train).train_distance_1D+speed_temp2*0.1;
    	if((*train).train_num==3)
    	(*train).train_next=(*train).train_distance_1D+speed_temp3*0.1;
    }
    
    
    
	/*更新2维坐标*/
	(*train).train_distance_2D=Length_To_Coordinate((*train));
    (*train).time++;
}

int ReadytoJudge(TrainInfo a)
//判断下一秒是否进入探测区,是返回1，不是返回0
{

		
	
	if(a.train_num==1) 
	{
		if(a.train_direction==1) 
		{
			if((a.train_next>=a.train_detect_1D_1&&a.train_next<=a.train_detect_1D_2)||(a.train_next>=a.train_detect_1D_3&&a.train_next<=a.train_detect_1D_4))
				return 1;
			else
				return 0;
		} 
		else if(a.train_direction==2) 
		{
			if((a.train_next>=a.train_detect_1D_4&&a.train_next<=a.train_detect_1D_3)||(a.train_next>=a.train_detect_1D_2&&a.train_next<=a.train_detect_1D_1))
				return 1;
			else
				return 0;
		}

	} 
	else if(a.train_num==2||a.train_num==3) 
	{
		if(a.train_direction==1) 
		{
			if(a.train_next>=a.train_detect_1D_1||a.train_next<=a.train_detect_1D_2)
				return 1;
			else
				return 0;
		} 
		else if(a.train_direction==2) 
		{
			if(a.train_next>=a.train_detect_1D_2||a.train_next<=a.train_detect_1D_1)
				return 1;
			else
				return 0;
		}
	}
	
}
