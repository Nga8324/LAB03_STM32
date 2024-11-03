/*
 * fsm_manual.c
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */
#include "fsm_manual.h"

void BlinkyLed(int led){
	switch(STATUS_BLINKY){
	case INIT:
		OffAll1();
		OffAll2();
		setTimer5(250);
		if(led == RED) STATUS_BLINKY = RED;
		if(led == YELLOW) STATUS_BLINKY = YELLOW;
		if(led == GREEN) STATUS_BLINKY = GREEN;
		break;
	case RED:
		if(timer5_flag == 1){
			setTimer5(250);
			BlinkyLedRed1();
			BlinkyLedRed2();
		}
		break;
	case YELLOW:
		if(timer5_flag == 1){
			setTimer5(250);
			BlinkyLedYellow1();
			BlinkyLedYellow2();
		}
		break;
	case GREEN:
		if(timer5_flag == 1){
			setTimer5(250);
			BlinkyLedGreen1();
			BlinkyLedGreen2();
		}
		break;
	default:
		break;
	}
}
void fsm_manual_run(){
	switch(STATUS_MODE){
	case INIT:	// Trang thái thông thường
		updateBuffer(MODE1);
		display_led7seg();
		STATUS_MODE = MODE1;
		break;
	case MODE1:
		if(TimeRed != TimeYellow + TimeGreen){
			OffAll1();
			OffAll2();
			updateBuffer(FAIL);
		}
		else fsm_automatic_run();
		updateBuffer(STATUS_MODE);
		display_led7seg();

		if(isButton1Pressed()){
			STATUS_MODE = MODE2;
			value = TimeRed;
			STATUS_BLINKY = INIT;
		}
		break;
	case MODE2:
		BlinkyLed(RED);
		updateBuffer(STATUS_MODE);
		display_led7seg();
		if(isButton1Pressed()){
			STATUS_MODE = MODE3;
			value = TimeYellow;
			STATUS_BLINKY = INIT;
		}
		else if(isButton2Pressed()){
			value++;
			if(value > 99){
				value = 1;
			}
		}
		else if(isButton3Pressed()){
			TimeRed = value;
			STATUS_MODE = MODE1;
		}
		break;
	case MODE3:
		BlinkyLed(YELLOW);
		updateBuffer(STATUS_MODE);
		display_led7seg();
		if(isButton1Pressed()){
			STATUS_MODE = MODE4;
			value = TimeGreen;
			STATUS_BLINKY = INIT;
		}
		else if(isButton2Pressed()){
			value++;
			if(value > 99){
				value = 1;
			}
		}
		else if(isButton3Pressed()){
			TimeYellow = value;
			STATUS_MODE = MODE1;
		}
		break;
	case MODE4:
		BlinkyLed(GREEN);
		updateBuffer(STATUS_MODE);
		display_led7seg();
		if(isButton1Pressed()){
			STATUS_MODE = MODE1;
		}
		else if(isButton2Pressed()){
			value++;
			if(value > 99){
				value = 1;
			}
		}
		else if(isButton3Pressed()){
			TimeGreen = value;
			STATUS_MODE = MODE1;
		}
		break;
	default:
		break;
	}
}
