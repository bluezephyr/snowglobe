/*
 * Port configuration for the Bluepill board for the ledblink hack
 *
 * Copyright (c) 2021. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include <stm32f1xx.h>
#include "port_config.h"

void port_init(void)
{
    // 7.3.7 APB2 peripheral clock enable register (RCC_APB2ENR) in [1]
    // Enable APB2 peripheral clock for PORTB (I2C_1, etc) and PORTC (Internal
    // LED, etc).
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPBEN);
    SET_BIT(RCC->APB2ENR, RCC_APB2ENR_IOPCEN);

    // PC 13 (Internal LED)
    // 9.2.2 Port configuration register high (GPIOx_CRH) (x=A..G) in [1]
    // CNF1=0, CNF0=0: General Purpose output Push-Pull
    // MODE1=1, MODE0=1: Maximum output speed 50 MHz
    MODIFY_REG(GPIOC->CRH, GPIO_CRH_CNF13, GPIO_CRH_MODE13);
    // Active low - disable LED at startup
    WRITE_REG(GPIOC->BSRR, GPIO_BSRR_BS13);

    // PB6 (I2C1_SCL) and PB7 (I2C1_SDA)
    // 9.2.1 Port configuration register low (GPIOx_CRL) (x=A..G)
    //   CNF7  = 11 (Alternate function output, open-drain)
    //   MODE7 = 11 (Maximum output speed 50 MHz)
    //   CNF6  = 11 (Alternate function output, open-drain)
    //   MODE6 = 11 (Maximum output speed 50 MHz)
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_CNF6, GPIO_CRL_CNF6);
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_MODE6, GPIO_CRL_MODE6);
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_CNF7, GPIO_CRL_CNF7);
    MODIFY_REG(GPIOB->CRL, GPIO_CRL_MODE7, GPIO_CRL_MODE7);
}
