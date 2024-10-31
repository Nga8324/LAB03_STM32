/*
 * global.h
 *
 *  Created on: Oct 26, 2024
 *      Author: Admin
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "traffic_light.h"
#include "software_timer.h"
#include "button.h"
#include "main.h"
#define INIT		1
#define AUTO_RED	2
#define AUTO_YELLOW	3
#define AUTO_GREEN	4


#define MAN_RED 	12
#define MAN_YELLOW	13
#define MAN_GREEN 	14

extern int status;
extern int buffer_7seg[4];

#endif /* INC_GLOBAL_H_ */
