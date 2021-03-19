/*
 * This task simulates a snowfall on a display using the graphics library.
 *
 * Copyright (c) 2021. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */
#ifndef SNOW_TASK_H
#define SNOW_TASK_H

#include <stdint.h>

/*
 * Init function. Must be called before the scheduler is started.
 */
void snow_init (uint8_t taskId);

/*
 * Run function for the task. Called by the scheduler.
 */
void snow_run (void);

#endif // SNOW_TASK_H
