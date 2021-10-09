/*
 * free_RTOS.c
 *name : Abdelrahman salem
 * Created: 9/28/2021 5:31:24 PM
 * Author : Qaiaty
 */ 

#include "FreeRTOS.h"
#include "task.h"
#include "DIO.h"


TaskHandle_t task1_Handle=NULL;
TaskHandle_t task2_Handle=NULL;
TaskHandle_t task3_Handle=NULL;


void inti_task1(void* ptr)
{
	while(1)
	{
		/* led0 */
		DIO_SET_BIN_DIR(DIO_PORTC,DIO_PIN2,DIO_BIN_OUTPUT);
		DIO_SET_BIN_VAL(DIO_PORTC,DIO_PIN2,DIO_BIN_HIGT);
		
		/* led1  */
		DIO_SET_BIN_DIR(DIO_PORTC,DIO_PIN7,DIO_BIN_OUTPUT);
		DIO_SET_BIN_VAL(DIO_PORTC,DIO_PIN7,DIO_BIN_HIGT);
		
		
	   vTaskSuspend(task1_Handle);
	}
}
/////////////
void led0_toggel_task2(void* ptr)
{
	while(1)
	{
		DIO_TOGGLE_BIN(DIO_PORTC,DIO_PIN2);
		vTaskDelay(1000);
	}
}
/////////////
void led1_toggel_task3(void* ptr)
{
	while(1)
	{
		DIO_TOGGLE_BIN(DIO_PORTC,DIO_PIN7);
		vTaskDelay(500);
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////
int main(void)
{
    
	xTaskCreate(    inti_task1,
	"inti",
	200,
	NULL,
	3,
	task1_Handle
	);
	/////////////////////////////
	 xTaskCreate(    led0_toggel_task2,
	 "toggel1",
	 200,
	 NULL,
	 2,
	 task2_Handle
	 );
	 ////////////////////////
	  xTaskCreate(    led1_toggel_task3,
	  "toggel2",
	  200,
	  NULL,
	  1,
	  task3_Handle
	  );
	
	
	vTaskStartScheduler(); 
    while (1)  
    {
    }
}

