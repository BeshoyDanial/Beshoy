/*****************************************/
/* Name  :  Beshoy Danial                */
/* Version :  V01                        */
/* Date    :  6 /9/2020         	     */
/*****************************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Periodicity , void (*Copy_ptr) (void) , u8 Copy_u8FirstDelay );
void SOS_voidStart(void);
void SOS_VoidSuspend_Task(u8 Copy_u8ID);
void SOS_VoidResume_Task(u8 Copy_u8ID);
void SOS_VoidKill_Task(u8 Copy_u8ID);



#endif
