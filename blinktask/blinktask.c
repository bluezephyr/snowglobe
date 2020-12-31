/*
 * This task toggles a led each time the task's run function is called.
 *
 * Copyright (c) 2020. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include <stdbool.h>
#include "config/port_config.h"
#include "hal/pin_digital_io.h"
#include "blinktask.h"

static struct blink_task_t
{
    uint8_t taskId;
    bool ledActivated;
    bool blinkingEnabled;
} self;

void blink_task_init (uint8_t taskId)
{
    self.taskId = taskId;
    self.ledActivated = false;
    self.blinkingEnabled = false;
}

void blink_task_enable_blink (void)
{
    self.blinkingEnabled = true;
    self.ledActivated = true;
}

void blink_task_disable_blink (void)
{
    self.blinkingEnabled = false;
    self.ledActivated = false;
}

void blink_task_run (void)
{
    if (self.blinkingEnabled)
    {
        self.ledActivated = !self.ledActivated;
    }

    if (self.ledActivated)
    {
        pin_digital_io_write_high(LED_GREEN);
    }
    else
    {
        pin_digital_io_write_low(LED_GREEN);
    }
}
