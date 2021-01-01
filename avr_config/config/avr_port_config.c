/*
 * Port configuration for the AVR for the BitLoom snowglobe.
 *
 * Copyright (c) 2020-2021. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "port_config.h"

void port_init(void)
{
    PORTB |= 0u << PB1;
    DDRB |= 1u << PB1;
}
