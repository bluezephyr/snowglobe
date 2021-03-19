/*
 * This task simulates a snowfall on a display using the graphics library.
 *
 * Copyright (c) 2021. BlueZephyr
 *
 * This software may be modified and distributed under the terms
 * of the MIT license.  See the LICENSE file for details.
 *
 */

#include "snow.h"
#include "framebuffer.h"
#include "graphics.h"

#define EDGE_LEFT   10u
#define EDGE_RIGHT  FRAMEBUFFER_X_PIXELS-10
#define EDGE_TOP    10u
#define EDGE_BOTTOM FRAMEBUFFER_Y_PIXELS-10

#define BLOB_SIZE_PIXELS    20u

static struct snow_t
{
    uint8_t taskId;
    uint8_t curX;
    uint8_t curY;
    uint8_t prevX;
    uint8_t prevY;
    int8_t deltaX;
    int8_t deltaY;
} self;

/*
 * Local function prototypes
 */
static void calculateDelta(void);

static void setBlob(uint8_t x, uint8_t y);
static void clearBlob(uint8_t x, uint8_t y);

void snow_init (uint8_t taskId)
{
    self.taskId = taskId;
    self.curX = EDGE_LEFT;
    self.curY = EDGE_TOP;
    self.prevX = EDGE_LEFT;
    self.prevY = EDGE_TOP;
    self.deltaX = 1;
    self.deltaY = 0;
}

// Move a pixel in a rectangle
void snow_run (void)
{
    if (!framebuffer_isLocked())
    {
        clearBlob(self.prevX, self.prevY);
        setBlob(self.curX, self.curY);
        self.prevX = self.curX;
        self.prevY = self.curY;
        calculateDelta();
        self.curX += self.deltaX;
        self.curY += self.deltaY;
        graphics_show();
    }
}

static void setBlob(uint8_t x, uint8_t y)
{
    for(uint8_t i=0; i<BLOB_SIZE_PIXELS; i++)
    {
        for(uint8_t j=0; j<BLOB_SIZE_PIXELS; j++)
        {
            framebuffer_setPixel(x + i, y + j);
        }
    }
}

static void clearBlob(uint8_t x, uint8_t y)
{
    for(uint8_t i=0; i<BLOB_SIZE_PIXELS; i++)
    {
        for(uint8_t j=0; j<BLOB_SIZE_PIXELS; j++)
        {
            framebuffer_clearPixel(x + i, y + j);
        }
    }
}

static void calculateDelta(void)
{
    if ((self.deltaX == 1) && (self.curX == EDGE_RIGHT))
    {
        self.deltaX = 0;
        self.deltaY = 1;
    }
    if ((self.deltaY == 1) && (self.curY == EDGE_BOTTOM))
    {
        self.deltaX = -1;
        self.deltaY = 0;
    }
    if ((self.deltaX == -1) && (self.curX == EDGE_LEFT))
    {
        self.deltaX = 0;
        self.deltaY = -1;
    }
    if ((self.deltaY == -1) && (self.curY == EDGE_TOP))
    {
        self.deltaX = 1;
        self.deltaY = 0;
    }
}
