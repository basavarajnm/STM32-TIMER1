/*
 * timer.c
 *
 *  Created on: Nov 28, 2024
 *      Author: BASAVARAJ
 */

#include "timer.h"


#include "stm32f407xx.h"
extern int k;

void Timer1_init(void) {

    // Enable clock for TIM1
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN; // Peripheral clock enable

    // Pre-scaler to get 1MHz as counter clock
    TIM1->PSC = 55079; // Pre-scaler value (SystemCoreClock / 1000000) - 1

    // Configure TIM1
    TIM1->CR1 &= ~(TIM_CR1_DIR | TIM_CR1_CMS); // Select the up counter mode
    TIM1->CR1 |= TIM_COUNTERMODE_UP; // Up counting
    TIM1->CR1 &= ~TIM_CR1_CKD; // Clear clock division
    TIM1->CR1 |= TIM_CLOCKDIVISION_DIV1; // Set clock division to 1
    TIM1->ARR = 65358; // Set the auto-reload value

    // Enable the update interrupt
    TIM1->DIER |= TIM_DIER_UIE; // Enable update interrupt

    // Start the timer
    TIM1->CR1 |= TIM_CR1_CEN; // Enable the timer

    // Set up NVIC for TIM1
    NVIC_SetPriority(TIM1_UP_TIM10_IRQn, 1); // Set interrupt priority
    NVIC_EnableIRQ(TIM1_UP_TIM10_IRQn); // Enable TIM1 interrupt in NVIC
}

void TIM1_UP_TIM10_IRQHandler(void) {
    if (TIM1->SR & TIM_SR_UIF) { // Check for update interrupt flag
        TIM1->SR &= ~TIM_SR_UIF; // Clear the interrupt flag
        k=k+1;
        // check for 12min interrupt
        //increment global counter variable
        //counter_value += 1;// Read the  counter value
    }
}







