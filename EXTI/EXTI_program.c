/*
 * EXTI_program.c
 *
 *  Created on: Mar 21, 2022
 *      Author: INTEL
 */
#include"../../LIB/STD_TYPES.h"
#include"../../LIB/BIT_MATH.h"
#include"EXTI_interface.h"
#include"EXTI_privet.h"
#include "EXTI_config.h"

void (*EXTI_PtrCallBack[3]) (void) = {NULL};

void EXTI_voidInit(void){
#ifdef EXTI_INT_LINE
#if  EXTI_INT_LINE==INT_LINE_0
         #if  EXTI_INT_SENSE==LOW_LEVEL_SENSE
	        CLR_BIT(MCUCR,0);     CLR_BIT(MCUCR,1);
        #elif  EXTI_INT_SENSE==FALLING_EDGE_SENSE
         	CLR_BIT(MCUCR,0);     SET_BIT(MCUCR,1);
        #elif  EXTI_INT_SENSE==RISING_EDGE_SENSE
	        SET_BIT(MCUCR,0);     SET_BIT(MCUCR,1);
        #elif  EXTI_INT_SENSE==ON_CHANGE_SENSE
	        SET_BIT(MCUCR,0);     CLR_BIT(MCUCR,1);
        #endif
#elif  EXTI_INT_LINE==INT_LINE_1
        #if  EXTI_INT_SENSE==LOW_LEVEL_SENSE
	          CLR_BIT(MCUCR,2);    CLR_BIT(MCUCR,3);
       #elif  EXTI_INT_SENSE==FALLING_EDGE_SENSE
	           CLR_BIT(MCUCR,2);    SET_BIT(MCUCR,3);
       #elif  EXTI_INT_SENSE==RISING_EDGE_SENSE
	         SET_BIT(MCUCR,2);    SET_BIT(MCUCR,3);
       #elif  EXTI_INT_SENSE==ON_CHANGE_SENSE
	        SET_BIT(MCUCR,2);    CLR_BIT(MCUCR,3);
       #endif
#elif  EXTI_INT_LINE==INT_LINE_2

      #if  EXTI_INT_SENSE==FALLING_EDGE_SENSE
	        CLR_BIT(MCUCSR,6);

        #elif  EXTI_INT_SENSE==RISING_EDGE_SENSE
	        SET_BIT(MCUCSR,6);
        #endif
#endif
#endif

}

void EXTI_voidEnable(U8 Copy_u8IntLine){
	SET_BIT(GICR,Copy_u8IntLine);
}

void EXTI_voidDisable(U8 Copy_u8IntLine){
	CLR_BIT(GICR,Copy_u8IntLine);
}

void EXTI_voidClearFlag(U8 Copy_u8IntLine){
	SET_BIT(GIFR,Copy_u8IntLine);
}

U8   EXTI_u8GetFlag(U8 Copy_u8IntLine){
	return GET_BIT(GIFR,Copy_u8IntLine);
}

void EXTI_voidSetSignal(U8 Copy_u8SenseInt,U8 Copy_u8IntLine){
	if((Copy_u8IntLine>=INT_LINE_0)&&(Copy_u8IntLine<=INT_LINE_1)){
		Copy_u8IntLine=(6-Copy_u8IntLine)*-2;
		switch(Copy_u8SenseInt){
		case LOW_LEVEL_SENSE:CLR_BIT(MCUCR,Copy_u8IntLine); CLR_BIT(MCUCR,Copy_u8IntLine+1);break;
		case ON_CHANGE_SENSE:SET_BIT(MCUCR,Copy_u8IntLine); CLR_BIT(MCUCR,Copy_u8IntLine+1);break;
		case FALLING_EDGE_SENSE:CLR_BIT(MCUCR,Copy_u8IntLine); SET_BIT(MCUCR,Copy_u8IntLine+1);break;
		case RISING_EDGE_SENSE:SET_BIT(MCUCR,Copy_u8IntLine);  SET_BIT(MCUCR,Copy_u8IntLine+1);break;
		}
	}else{
		switch(Copy_u8SenseInt){
		case RISING_EDGE_SENSE:SET_BIT(MCUCSR,6); break;
		case FALLING_EDGE_SENSE:SET_BIT(MCUCSR,6);break;
		}
	}
}

void EXTI_voidSetCallBack(void (*Copy_PvoidCallBack(void)),U8 Copy_u8IntLine){
	if(Copy_PvoidCallBack!=NULL){
		if(Copy_u8IntLine==INT_LINE_2){
			EXTI_PtrCallBack[(Copy_u8IntLine+3)-6]=Copy_PvoidCallBack;
		}else{
			EXTI_PtrCallBack[Copy_u8IntLine-6]=Copy_PvoidCallBack;
		}

	}
}

void __vector_1(void) __attribute__((signal));
void __vector_1(void){
	if(EXTI_PtrCallBack[0]!=NULL){
		EXTI_PtrCallBack[0]();
		EXTI_voidClearFlag(INT_LINE_0);
	}
}
void __vector_2(void) __attribute__((signal));
void __vector_2(void){
	if(EXTI_PtrCallBack[1]!=NULL){
		EXTI_PtrCallBack[1]();
		EXTI_voidClearFlag(INT_LINE_1);
	}
}
void __vector_3(void) __attribute__((signal));
void __vector_3(void){
	if(EXTI_PtrCallBack[2]!=NULL){
		EXTI_PtrCallBack[2]();
		EXTI_voidClearFlag(INT_LINE_2);
	}
}

