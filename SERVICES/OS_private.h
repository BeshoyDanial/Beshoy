/*****************************************/
/* Name  :  Beshoy Danial                */
/* Version :  V01                        */
/* Date    :  6 /9/2020         	     */
/*****************************************/
#ifndef OS_PRIVATE_H_
#define OS_PRIVATE_H_


#define TASK_READY  	1
#define TASK_SUSPENDED 	2



typedef struct
{
	u16 periodicity ;
	void (*Fptr) (void) ;
	u16 FirstDelay;
	u8 State;
		
}Task;


/* Array of Structure */
#define NULL	(void*)0

static Task OS_Tasks[NUMBER_OF_TASKS] = { NULL }; // static Cause it is only used in OS_prog.c


/*
static void Scheduler(void)
{
	for(u8 i = 0; i<NUMBER_OF_TASKS; i++)
	{
		if((TickCounts % OS_Tasks[i].periodicity) ==0)
		{
			OS_Tasks[i].Fptr( ); // Task Takes its Action
		}
	}
	TickCounts++;
}
 */


static void Scheduler_FirstDelay(void)
{
	for(u8 i = 0; i<NUMBER_OF_TASKS; i++)
	{
		if((OS_Tasks[i].Fptr != NULL) && (OS_Tasks[i].State == TASK_READY)) //for confirmation and Can be Deleted
		{
			if(OS_Tasks[i].FirstDelay == 0 )
			{
				OS_Tasks[i].FirstDelay = OS_Tasks[i].periodicity-1; /// FirstDelay will be the NEW Periodicity
				OS_Tasks[i].Fptr( ); // Task Takes its Action
			}
			else
			{
				OS_Tasks[i].FirstDelay--;
			}
		}
	}

}


#endif
