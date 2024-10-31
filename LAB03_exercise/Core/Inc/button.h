/*
 * button.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#include "main.h"

#define NORMAL_STATE 	GPIO_PIN_SET
#define PRESSED_STATE 	GPIO_PIN_RESET
#define NUM_button	3

int isButton1Pressed();
int isButton2Pressed();
int isButton3Pressed();

//int isButton1LongPressed();
//int isButton2LongPressed();
//int isButton3LongPressed();

void getKeyInput();

#endif /* INC_BUTTON_H_ */
