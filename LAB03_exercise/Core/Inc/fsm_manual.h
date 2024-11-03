/*
 * fsm_manual.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_FSM_MANUAL_H_
#define INC_FSM_MANUAL_H_

#include "global.h"
#include "main.h"
#include "led7_segment.h"
#include "fsm_automatic.h"

#define RED		40
#define YELLOW	41
#define GREEN 	42

void fsm_manual_run();
void BlinkyLed();
#endif /* INC_FSM_MANUAL_H_ */
