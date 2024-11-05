/*
 * traffic_light.c
 *
 *  Created on: Oct 31, 2024
 *      Author: Admin
 */
#include "traffic_light.h"

void OffAll1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
}
void OffAll2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
}
void OnLedRed1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
}
void OnLedRed2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
}
void OnLedYellow1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_RESET);
}
void OnLedYellow2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_RESET);
}
void OnLedGreen1(){
	HAL_GPIO_WritePin(RED1_GPIO_Port, RED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW1_GPIO_Port, YELLOW1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN1_GPIO_Port, GREEN1_Pin, GPIO_PIN_SET);
}
void OnLedGreen2(){
	HAL_GPIO_WritePin(RED2_GPIO_Port, RED2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(YELLOW2_GPIO_Port, YELLOW2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GREEN2_GPIO_Port, GREEN2_Pin, GPIO_PIN_SET);
}

void BlinkyLedRed1(){
	HAL_GPIO_TogglePin(RED1_GPIO_Port, RED1_Pin);
}
void BlinkyLedRed2(){
	HAL_GPIO_TogglePin(RED2_GPIO_Port, RED2_Pin);
}
void BlinkyLedYellow1(){
	HAL_GPIO_TogglePin(YELLOW1_GPIO_Port, YELLOW1_Pin);
}
void BlinkyLedGreen1(){
	HAL_GPIO_TogglePin(GREEN1_GPIO_Port, GREEN1_Pin);
}
void BlinkyLedYellow2(){
	HAL_GPIO_TogglePin(YELLOW2_GPIO_Port, YELLOW2_Pin);
}
void BlinkyLedGreen2(){
	HAL_GPIO_TogglePin(GREEN2_GPIO_Port, GREEN2_Pin);
}

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
