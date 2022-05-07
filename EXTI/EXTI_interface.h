/*
 * EXTI_interface.h
 *
 *  Created on: Mar 21, 2022
 *      Author: INTEL
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

#define INT_LINE_0   6
#define INT_LINE_1   7
#define INT_LINE_2   5

#define   LOW_LEVEL_SENSE     0
#define   FALLING_EDGE_SENSE  1
#define   RISING_EDGE_SENSE   2
#define   ON_CHANGE_SENSE     3

void EXTI_voidInit(void);
void EXTI_voidEnable(U8 Copy_u8IntLine);
void EXTI_voidDisable(U8 Copy_u8IntLine);
void EXTI_voidClearFlag(U8 Copy_u8IntLine);
U8   EXTI_u8GetFlag(U8 Copy_u8IntLine);
void EXTI_voidSetCallBack(void (*Copy_PvoidCallBack(void)),U8 Copy_u8IntLine);
void EXTI_voidSetSignal(U8 Copy_u8SenseInt,U8 Copy_u8IntLine);


#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
