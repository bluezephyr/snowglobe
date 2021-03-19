#ifndef SCHEDULER_CONFIG_H
#define SCHEDULER_CONFIG_H

/*
 * The number of tasks that will be used in the system.  For each task, memory
 * will be reserved to hold its internal state.  The maximum number of tasks
 * is 32.
 */

/*
 * Tasks:
 * - blinktask
 * - snow
 * - graphics
 * - ssd1306
 */
#define SCHEDULER_NO_TASKS      4u

#endif  // SCHEDULER_CONFIG_H
