/*
 * Ledblink is an example hack for the BitLoom framework.  It implements a
 * simple task that blinks with a LED.  The LED can be controlled using
 * commands sent over UART.
 *
 * Copyright (c) 2020. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "framebuffer.h"
#include "blinktask.h"
#include "snow.h"
#include "ssd1306.h"
#include "graphics.h"
#include "hal/i2c.h"
#include "hal/timer.h"
#include "core/scheduler.h"
#include "core/uart.h"
#include "config/port_config.h"

int main(void)
{
    timer_init();
    schedule_init();
    port_init();
    uart_init();
    i2c_init();
    framebuffer_init();

    // Task initializations
    blink_task_init(schedule_add_task(240, 0, blink_task_run));
    snow_init(schedule_add_task(10, 0, snow_run));
    ssd1306_init(schedule_add_task(1, 1, ssd1306_run));
    graphics_init(schedule_add_task(10, 0, graphics_run));

    schedule_start();
    blink_task_enable_blink();

    uart_write((uint8_t*)"Welcome to the BitLoom Snowglobe\r", 34);

    while(1)
    {
        schedule_run();
    }

    return(0);
}
