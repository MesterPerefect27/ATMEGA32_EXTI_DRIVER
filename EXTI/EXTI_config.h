/*
 * EXTI_config.h
 *
 *  Created on: Mar 21, 2022
 *      Author: INTEL
 */

#ifndef MCAL_EXTI_EXTI_CONFIG_H_
#define MCAL_EXTI_EXTI_CONFIG_H_

/*OPTIONS
 *INT_LINE_0
 *INT_LINE_1
 *INT_LINE_2 */
#define EXTI_INT_LINE INT_LINE_2
/*OPTIONS
 *LOW_LEVEL_SENSE
 *FALLING_EDGE_SENSE
 *RISING_EDGE_SENSE
 *ON_CHANGE_SENSE*/
#define EXTI_INT_SENSE    ON_CHANGE_SENSE

#endif /* MCAL_EXTI_EXTI_CONFIG_H_ */
