/*
 * button.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */
#include "button.h"

int KeyReg0[NUM_button] = {NORMAL_STATE};
int KeyReg1[NUM_button] = {NORMAL_STATE};
int KeyReg2[NUM_button] = {NORMAL_STATE};

int KeyReg3[NUM_button] = {NORMAL_STATE};
int TimerForKeyPress = 200;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1Pressed(){
	if(button1_flag == 1){
		button1_flag = 0;
		return 1;
	}
	return 0;
}
int isButton2Pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	return 0;
}
int isButton3Pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	return 0;
}

void getKeyInput(){
	for(int but = 0; but < 3; but ++){
		KeyReg0[but] = KeyReg1[but];
		KeyReg1[but] = KeyReg2[but];
		if(but == 0){
			KeyReg2[but] = HAL_GPIO_ReadPin(Button1_GPIO_Port, Button1_Pin);
			if((KeyReg0[but] == KeyReg1[but]) && (KeyReg1[but] == KeyReg2[but])){
				if(KeyReg3[but] != KeyReg2[but]){
					KeyReg3[but] = KeyReg2[but];
					if(KeyReg2[but] == PRESSED_STATE){
						//TODO
						button1_flag = 1;
						TimerForKeyPress = 200;
					}
				}else{
					TimerForKeyPress --;
					if(TimerForKeyPress == 0){
						if(KeyReg2[but] == PRESSED_STATE){
							KeyReg3[but] = NORMAL_STATE;
						}
						TimerForKeyPress = 200;
					}
				}
			}
		}else if(but == 1){
			KeyReg2[but] = HAL_GPIO_ReadPin(Button2_GPIO_Port, Button2_Pin);
			if((KeyReg0[but] == KeyReg1[but]) && (KeyReg1[but] == KeyReg2[but])){
				if(KeyReg3[but] != KeyReg2[but]){
					KeyReg3[but] = KeyReg2[but];
					if(KeyReg2[but] == PRESSED_STATE){
						//TODO
						button2_flag = 1;
						TimerForKeyPress = 200;
					}
				}else{
					TimerForKeyPress --;
					if(TimerForKeyPress == 0){
						if(KeyReg2[but] == PRESSED_STATE){
							KeyReg3[but] = NORMAL_STATE;
						}
						TimerForKeyPress = 200;
					}
				}
			}
		}else{
			KeyReg2[but] = HAL_GPIO_ReadPin(Button3_GPIO_Port, Button3_Pin);
			if((KeyReg0[but] == KeyReg1[but]) && (KeyReg1[but] == KeyReg2[but])){
				if(KeyReg3[but] != KeyReg2[but]){
					KeyReg3[but] = KeyReg2[but];
					if(KeyReg2[but] == PRESSED_STATE){
						//TODO
						button3_flag = 1;
						TimerForKeyPress = 200;
					}
				}else{
					TimerForKeyPress --;
					if(TimerForKeyPress == 0){
						if(KeyReg2[but] == PRESSED_STATE){
							KeyReg3[but] = NORMAL_STATE;
						}
						TimerForKeyPress = 200;
					}
				}
			}
		}
	}
}
