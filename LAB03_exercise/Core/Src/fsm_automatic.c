/*
 * fsm_automatic.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#include "fsm_automatic.h"

void fsm_automatic_run(){
	//
	switch(STATUS_LED1){
	case INIT:
		OffAll1();

		STATUS_LED1 = AUTO_RED1;
		TimeForLed1 = TimeRed;
		setTimer3(1000);
		break;
	case AUTO_RED1:
		OnLedRed1();

		if(timer3_flag == 1){
			setTimer3(1000);
			TimeForLed1 --;
			if(TimeForLed1 <= 0){
				TimeForLed1 = TimeGreen;
				STATUS_LED1 = AUTO_GREEN1;
			}
		}
		break;
	case AUTO_GREEN1:
		OnLedGreen1();

		if(timer3_flag == 1){
			setTimer3(1000);
			TimeForLed1 --;
			if(TimeForLed1 <= 0){
				TimeForLed1 = TimeYellow;
				STATUS_LED1 = AUTO_YELLOW1;
			}
		}
		break;
	case AUTO_YELLOW1:
		OnLedYellow1();

		if(timer3_flag == 1){
			setTimer3(1000);
			TimeForLed1 --;
			if(TimeForLed1 <= 0){
				TimeForLed1 = TimeRed;
				STATUS_LED1 = AUTO_RED1;
			}
		}
		break;
	default:
		break;
	}
	//
	switch(STATUS_LED2){
	case INIT:
		OffAll2();

		STATUS_LED2 = AUTO_GREEN2;
		TimeForLed2 = TimeGreen;
		setTimer4(1000);
		break;
	case AUTO_RED2:
		OnLedRed2();

		if(timer4_flag == 1){
			setTimer4(1000);
			TimeForLed2 --;
			if(TimeForLed2 <= 0){
				TimeForLed2 = TimeGreen;
				STATUS_LED2 = AUTO_GREEN2;
			}
		}
		break;
	case AUTO_GREEN2:
		OnLedGreen2();

		if(timer4_flag == 1){
			setTimer4(1000);
			TimeForLed2 --;
			if(TimeForLed2 <= 0){
				TimeForLed2 = TimeYellow;
				STATUS_LED2 = AUTO_YELLOW2;
			}
		}
		break;
	case AUTO_YELLOW2:
		OnLedYellow2();

		if(timer4_flag == 1){
			setTimer4(1000);
			TimeForLed2 --;
			if(TimeForLed2 <= 0){
				TimeForLed2 = TimeRed;
				STATUS_LED2 = AUTO_RED2;
			}
		}
		break;
	default:
		break;
	}
}

