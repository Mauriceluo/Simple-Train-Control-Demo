/*
�� 0������ 1�ȴ���վ 2��վ̨�ȴ� 3��վ 4��վ 5�û���ͣ��
*/
#include"TrainHeadfile.h"
//(*((*train).tptr2))
void ControlTrain(TrainInfo* train) 
{	
	if((*train).train_distance_1D<0)
		(*train).train_distance_1D+=2*(*train).train_orbit_L+2*(*train).train_orbit_W;
	
	(*train).train_next=(*train).train_distance_1D+(*train).train_speed*0.1;//���ϸ���next
    


/*�� ������*/
	if((*train).train_state==0) 
	{ //���ڹ����������ʻ
		if(ReadytoJudge(*train)==1) 
		{ //Ҫ����
			if((*train).train_num==1) 
				{
				if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
					{
					if(ReadytoJudge((*((*train).tptr2)))==1) 
					{ //ҲҪ���루3����
						if(run_method==1)
						{//�쳵���� 
							if((*train).train_speed>(*((*train).tptr2)).train_speed)
						    { //1��3��
							    (*train).train_state=3;//1����վ
							    (*((*train).tptr2)).train_state=1;//3���ȴ���վ
						    } 
							else 
							{ //�������
							    (*train).train_state=1;//1���ȴ���վ
							    (*((*train).tptr2)).train_state=3;
							}//3����վ
						}
						else
						{//����
							if((*train).before==0)
							{
								(*train).train_state=3;//1����վ
							    (*((*train).tptr2)).train_state=1;//3���ȴ���վ
							    (*train).before=1;
							    (*((*train).tptr2)).before=0;
							}
							else
							{
								(*train).train_state=1;//1���ȴ���վ
							    (*((*train).tptr2)).train_state=3;
							    (*train).before=0;
							    (*((*train).tptr2)).before=1;
							}
						} 
					} 
					else 
					{ //3��������
						(*train).train_state=3;//1����վ
					}
				} 
				else if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
				{
					if(ReadytoJudge((*((*train).tptr1)))==1) 
					{ //2��ҲҪ����
						if(run_method==1)
						{
							if((*train).train_speed>(*((*train).tptr1)).train_speed) 
							{ //1����2����
							    (*train).train_state=3;//1����վ
							    (*((*train).tptr1)).train_state=1;//2���ȴ���վ
						    } 
							else 
							{ //�������
							    (*train).train_state=1;//1���ȴ���վ
							    (*((*train).tptr1)).train_state=3;//2����վ
						    }
						}
						else
						{
							if((*train).before==0)
							{
								(*train).train_state=3;//1����վ
							    (*((*train).tptr1)).train_state=1;//2���ȴ���վ
							    (*train).before=1;
							    (*((*train).tptr1)).before=0;
							}
							else
							{
								(*train).train_state=1;//1���ȴ���վ
							    (*((*train).tptr1)).train_state=3;
							    (*train).before=0;
							    (*((*train).tptr1)).before=1;
							}
						}
	
					} 
					else 
					{ //2��������
						(*train).train_state=3;//1����վ
					}
				}
			} 
			else 
	        { //���Ų���1
				if(ReadytoJudge((*((*train).tptr1)))==1) 
				{ //1��ҲҪ����
					if(run_method==1)
					{
						if((*((*train).tptr1)).train_distance_1D<=(*((*train).tptr1)).train_orbit_L+(*((*train).tptr1)).train_orbit_W)
		                {
            			    if((*train).train_num==2)
            			    {
			            	    if((*train).train_speed>(*((*train).tptr1)).train_speed) 
					            { //2����1����
				                    (*train).train_state=3;//2����վ
						            (*((*train).tptr1)).train_state=1;//1���ȴ���վ
					            }
					            else 
					            {
						            (*train).train_state=1;//2���ȴ���վ
						            (*((*train).tptr1)).train_state=3;//1����վ
					            }
			                }
			                else//��3�� 
			                {
            				    (*train).train_state=3;//3��������վ
            			    } 
            		    }
            	  	    else//���°벿��
					    {
						    if((*train).train_num==3)
            			    {
			            	    if((*train).train_speed>(*((*train).tptr1)).train_speed) 
					            { //3����1����
				                    (*train).train_state=3;//3����վ
						            (*((*train).tptr1)).train_state=1;//1���ȴ���վ
					            }
					            else 
					            {
						            (*train).train_state=1;//3���ȴ���վ
						            (*((*train).tptr1)).train_state=3;//1����վ
					            }
			                }
			                else//��2�� 
			                {
            				    (*train).train_state=3;//2��������վ
            			    } 
					    }
		            }
					else
					{//����
					    if((*((*train).tptr1)).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W)
		                {
            			    if((*train).train_num==2)
            			    {
			            	    if((*train).before==0)
		  	                    {
							        (*train).train_state=3;//2����վ
						    		(*((*train).tptr1)).train_state=1;//1���ȴ���վ
						    		(*train).before=1;
						    		(*((*train).tptr1)).before=0;
								}
								else
								{
									(*train).train_state=1;//2���ȴ���վ
						    		(*((*train).tptr1)).train_state=3;
						    		(*train).before=0;
						    		(*((*train).tptr1)).before=1;
								}
			                }
			                else//��3�� 
			                {
            				    (*train).train_state=3;//3��������վ
							    (*((*train).tptr1)).train_state=3;//1Ҳ������վ 
            			    } 
            		    }
            	  	    else//���°벿��
					    {
						    if((*train).train_num==3)
            			    {
			            	    if((*train).before==0)
		  	            		{
									(*train).train_state=3;//3����վ
						    		(*((*train).tptr1)).train_state=1;//1���ȴ���վ
						    		(*train).before=1;
						    		(*((*train).tptr1)).before=0;
								}
								else
								{
									(*train).train_state=1;//3���ȴ���վ
						    		(*((*train).tptr1)).train_state=3;
						    		(*train).before=0;
						    		(*((*train).tptr1)).before=1;
								}
			                }
			                else//��2�� 
			                {
            				    (*train).train_state=3;//2��������վ
							    (*((*train).tptr1)).train_state=3;//1Ҳ������վ 
            			    } 
					    }
					}
				} 
				else 
				{ //1��������
					(*train).train_state=3;//2��3����վ
				}
			}
		}
	}

	/*һ �ȴ���վ*/
	else if((*train).train_state==1) 
	{
		if((*train).train_num==1) 
		{ //��1���ȴ�
			if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
			{
				if((*((*train).tptr2)).train_state==0)//3���Ѿ�����ǹ������
					(*train).train_state=3;
			}
			else if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
			{
				if((*((*train).tptr1)).train_state==0)//2���Ѿ�����ǹ������
					(*train).train_state=3;
			}
		} 
		else 
		{ //2��3���ڵȴ�
			if((*((*train).tptr1)).train_state==0)//1�����빫�����
				(*train).train_state=0;
		}
	}

	/*�� ��վ̨�ȴ�*/
	else if((*train).train_state==2) 
	{
		if((*train).timeofkey<=0)
			(*train).train_state=4;
	}

	/*�� ��վ*/
	else if((*train).train_state==3) 
	{
		if((*train).train_next+(*train).train_speed*0.1>=2*(*train).train_orbit_L+2*(*train).train_orbit_W)
        {
        	(*train).train_next-=2*(*train).train_orbit_L+2*(*train).train_orbit_W;
        	(*train).train_next+=(*train).train_speed*0.1;
        }
		//printf("next %d\n",(*train).train_next);
		if((*train).train_direction==1)
	    { //˳ʱ��
			if((*train).train_num==1) 
			{ //1��
				if((*train).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W)//�ϰ��� 
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
			{ //2��3��
				if((*train).train_next>=(*train).station1) 
				{
					(*train).train_state=2;
				}
			}
		} 
		else 
		{ //��ʱ��
			if((*train).train_num==1) 
			{ //1��
				if((*train).train_distance_1D<=(*train).train_orbit_L+(*train).train_orbit_W)//�ϰ��� 
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
			{ //2��3��
				if((*train).train_next<=(*train).station1) 
				{
					(*train).train_state=2;
				}
			}
		}
	}

	/*�� ��վ*/
	else if((*train).train_state==4) 
	{
		if((*train).train_num==1)
	    { //1��
			if((*train).train_direction==1) 
			{ //1��˳ʱ��
				if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //�°벿��
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
				{ //�ϰ벿��
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
			{ //1����ʱ��
				if((*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //�ϰ벿��
					if((*train).train_distance_1D+(*train).train_speed*0.1<(*train).train_detect_1D_4)
						(*train).train_state=0;
				}
			    else if((*train).train_distance_1D>=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //�°벿��
					if((*train).train_distance_1D+(*train).train_speed*0.1<(*train).train_detect_1D_2)
						(*train).train_state=0;
				}
			}

		} 
		else if((*train).train_num==2)
		{ //����
			if((*train).train_direction==1) 
			{ //2˳ʱ��
				if(((*train).train_distance_1D>(*train).train_detect_1D_2)&&((*train).train_distance_1D<(*train).train_orbit_L))
					(*train).train_state=0;
			} 
			else if((*train).train_direction==2) 
			{ //2��ʱ��
				if((*train).train_distance_1D<(*train).train_detect_1D_2&&(*train).train_distance_1D>(*train).train_orbit_L+(*train).train_orbit_W)
					(*train).train_state=0;
			}
		}
		else//���� 
		{
			if((*train).train_direction==1)//2˳ʱ��
			{
				if((*train).train_distance_1D>(*train).train_detect_1D_2&&(*train).train_distance_1D<(*train).train_orbit_L+(*train).train_orbit_W)
				(*train).train_state=0;
			}
			else if((*train).train_direction==2)//2��ʱ��
			{
				if((*train).train_distance_1D<(*train).train_detect_1D_2&&(*train).train_distance_1D>2*(*train).train_orbit_L+(*train).train_orbit_W)
				(*train).train_state=0;
			}
		} 
	}

	/*ִ�в���*/
	if((*train).train_state==0) 
	{ //����������
		//����ûʲôҪд��
	} 
	else if((*train).train_state==1) 
	{ //�ȴ���վ
		(*train).train_speed=0;
		if((*train).train_num==1) 
		{ //1��
			if((*train).train_direction==1) 
			{ //1��˳ʱ��
				if((*train).train_next<=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //1����
					(*train).train_distance_1D=(*train).train_detect_1D_1;
				} 
				else 
				{ //1����
					(*train).train_distance_1D=(*train).train_detect_1D_3;
				}
			} 
			else 
			{ //1����ʱ��
				if((*train).train_next<=(*train).train_orbit_L+(*train).train_orbit_W) 
				{ //1����
					(*train).train_distance_1D=(*train).train_detect_1D_3;
				} 
				else 
				{ //1����
					(*train).train_distance_1D=(*train).train_detect_1D_1;
				}
			}
		} 
		else 
		{ //2��3��
			(*train).train_distance_1D=(*train).train_detect_1D_1;
		}

	} 
	else if((*train).train_state==2) 
	{ //��վ̨ͣ��
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
	{ //��վ��
		if((*train).train_num==1)
			(*train).train_speed=speed_temp1;
		else if((*train).train_num==2)
			(*train).train_speed=speed_temp2;
		else if((*train).train_num==3){
			(*train).train_speed=speed_temp3;
			
		}
			
	} 
	
	else if((*train).train_state==4)
    { //��վ
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
	(*train).train_next=(*train).train_distance_1D+(*train).train_speed*0.1;//���ϸ���next
	

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
    
    
    
	/*����2ά����*/
	(*train).train_distance_2D=Length_To_Coordinate((*train));
    (*train).time++;
}

int ReadytoJudge(TrainInfo a)
//�ж���һ���Ƿ����̽����,�Ƿ���1�����Ƿ���0
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
