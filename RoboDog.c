/* RoboDog.c */ 
#include "kernel/kernel.h"
#include "kernel_id.h"
#include "c/ecrobot_interface.h"
#include "KCG/StateMachine.h"
#include "KCG/kcg_types.h"


/* 
 * Functions to return sensor values  

	x = ecrobot_get_sonar_sensor(NXT_PORT_S1); // 0 -> 255 (255 - Distance in CM)
	y = ecrobot_get_light_sensor(NXT_PORT_S2); // 0 (dark) -> 1024 (bright)
	z = ecrobot_get_touch_sensor(NXT_PORT_S3); // 0 -> untouched, 1 -> Touched
	w= ecrobot_get_sound_sensor(NXT_PORT_S4); // 1024 (quiet) -> 0 (loud) 

	w,x,y,z have to be integers
*/

/* 
 * Functions to set motor values: 

	nxt_motor_set_speed(NXT_PORT_A, RightValue, 1); // sets right motor t0 RightValue 
	nxt_motor_set_speed(NXT_PORT_B, LeftValue, 1); // sets left motor to LeftValue

	RightValue and LeftValue have to be integers
*/


/* 
 * Functions to output something on the display 

	display_clear(0); // clears the display
	display_goto_xy(0, 0); // moves pointer to a certain position on the this display 
	                          0,0 => first line, 0,1 => second line etc.
	display_string("some sting"); // display string at the current position
	display_int(someInt, 0); // display some int at the current position 
	display_update(); // updates display, mandatory to commit changes

	// example:
	display_clear(0);
	display_goto_xy(0, 0);
   	display_string("Hello World!");
	display_update();

*/



/* nxtOSEK hook to be invoked from an ISR in category 2 
 * this function is mandatory, do not change it */
void user_1ms_isr_type2(void){ /* do nothing */ }

void addValue(S32* array, int index, S32 value) 
{
	array[index] = value;
}

S32 average(S32* array, int size) 
{
	S32 average = 0;
	
	for (int i = 0; i < size; i++) 
	{
		average += array[i] / size;
	}
	
	return average;
}

/* Rover MainTask */
TASK(OSEK_Task_Background)
{
	/* result stores the outputs of the statemachine */
	outC_StateMachine result;
	inC_StateMachine input;

	/* Reset StateMachine */
	StateMachine_reset(&result);

	/* Init LightSensor, also mandatory */		
	//ecrobot_set_light_sensor_inactive(NXT_PORT_S1);
	ecrobot_init_sonar_sensor(NXT_PORT_S2);
	ecrobot_set_light_sensor_active(NXT_PORT_S3);
	
	int lastCount = 0;
	
	int size = 10;
	S32 values[size];
	for (int i = 0; i < size; i++) 
	{
		values[i] = 255;
	}
	
	int index = 0;
	
	int armcount = 0;
	
	kcg_bool isCounting = kcg_true;
	
	while(1)
	{
		//input.ColorSenser = ecrobot_get_sonar_sensor(NXT_PORT_S2);
		//U16 light = ecrobot_get_light_sensor(NXT_PORT_S1);
		S32 sonar = ecrobot_get_sonar_sensor(NXT_PORT_S2);
		addValue(values, index, sonar);
		
		input.AverageSonar = average(values, size);
		input.Start = ecrobot_get_touch_sensor(NXT_PORT_S1);
		int colorSensor = ecrobot_get_light_sensor(NXT_PORT_S3);
		input.Stop = colorSensor > 570;
		
		if (input.Stop) 
		{
			ecrobot_sound_tone(100, 250, 100);
		}
		
		
		/* this function computes next step, returns current outputs */
		StateMachine(&input, &result);
		
		index = (index + 1) % size;
		
		display_clear(0);
		display_goto_xy(0, 0);
		display_string("Sonar: ");
		display_int(input.AverageSonar, 7);
		
		display_goto_xy(0, 1);
		display_string("Count: ");
		display_int(result.CountValue, 7);
		
		display_goto_xy(0, 2);
		display_string("Speed: ");
		display_int(result.SpeedValue / 4, 7);
		
		display_goto_xy(0, 3);
		display_string("Color: ");
		display_int(colorSensor, 7);
		
		display_goto_xy(0, 4);
		display_string("Stop: ");
		
		display_goto_xy(0, 5);
		display_string("Kicks: ");
		//display_int(input.KickCountValue, 7);
		
		ecrobot_set_motor_speed(NXT_PORT_A, result.SpeedValue);

		display_update();
		
		// Pieper!
		if (lastCount != result.CountValue) 
		{
			lastCount = result.CountValue;
			ecrobot_sound_tone(500, 250, 100);
		}
		
		//ecrobot_set_motor_speed(NXT_PORT_B, result.ArmSpeedValue);
		
		switch (result.RobotTar_state_nxt) {
			case SSM_st_Free_RobotTar: 
				ecrobot_sound_tone(1000, 250, 100);
				break;
			case SSM_st_Search_RobotTar:
				break;
			case SSM_st_Kick_RobotTar:
				for (int i = 0; i < size; i++) 
				{
					values[i] = 10;
				}
				ecrobot_set_motor_speed(NXT_PORT_B, 80);
				systick_wait_ms(400);
				ecrobot_set_motor_speed(NXT_PORT_B, -80);
				systick_wait_ms(400);
				ecrobot_set_motor_speed(NXT_PORT_B, 0);
				//systick_wait_ms(900);
				break;
			default:
				break;
		}
		
		/* wait for sone_int_value msec */
		systick_wait_ms(50); 				
	}
}


