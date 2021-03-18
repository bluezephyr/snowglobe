/*
 * This task toggles a LED each time the task's run function is called.
 *
 * Copyright (c) 2020. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 *
 */
#ifndef BLINK_TASK_H
#define BLINK_TASK_H

#include <stdint.h>

/*
 * Init function. Must be called before the scheduler is started.
 */
void blink_task_init (uint8_t taskId);

/*
 * Functions to enable and disable blinking
 */
void blink_task_enable_blink (void);
void blink_task_disable_blink (void);

/*
 * Run function for the task. Called by the scheduler.
 */
void blink_task_run (void);

#endif // BLINK_TASK_H
