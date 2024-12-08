/*
 * timer.h
 *
 *  Created on: Nov 28, 2024
 *      Author: BASAVARAJ
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#define TIM_COUNTERMODE_UP                 0x00000000U
#define TIM_CLOCKDIVISION_DIV1             0x00000000U                          /*!< Clock division: tDTS=tCK_INT   */



void Timer1_init(void);
void TIM1_UP_TIM10_IRQHandler(void) ;

#endif



