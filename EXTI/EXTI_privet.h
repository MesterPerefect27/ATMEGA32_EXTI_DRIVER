/*
 * EXTI_privet.h
 *
 *  Created on: Mar 21, 2022
 *      Author: INTEL
 */

#ifndef MCAL_EXTI_EXTI_PRIVET_H_
#define MCAL_EXTI_EXTI_PRIVET_H_


#define MCUCR  *((volatile U8*)0X55)
#define MCUCSR *((volatile U8*)0X54)
#define GICR   *((volatile U8*)0X5B)
#define GIFR   *((volatile U8*)0X5A)

#define NULL 0

#endif /* MCAL_EXTI_EXTI_PRIVET_H_ */
