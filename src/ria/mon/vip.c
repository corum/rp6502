/*
 * Copyright (c) 2023 Rumbledethumps
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "mon/vip.h"
#include "pico/rand.h"
#include <stdio.h>
#include <string.h>

void vip_print(void)
{
    char *vips[] = {
        "Shawn Hyam",
        "Romain Fontaine",
        "Mark Rowe",
        "Vitali Filinkou",
        "Andy Herron",
        "Sean Franklin",
        "ulften",
        "Larryvc",
        "ingmar meins",
    };
    const unsigned VIP_COUNT = sizeof(vips) / sizeof(char *);
    for (unsigned i = 0; i < VIP_COUNT; i++)
    {
        unsigned swap = (VIP_COUNT * (get_rand_32() & 0xFFFF)) >> 16;
        char *tmp = vips[i];
        vips[i] = vips[swap];
        vips[swap] = tmp;
    }
    printf("          Patrons - %s", vips[0]);
    unsigned col = 20 + strlen(vips[0]) + 2;
    for (unsigned i = 1; i < VIP_COUNT - 1; i++)
    {
        printf(", ");
        col += strlen(vips[i]) + 2;
        if (col > 78)
        {
            col = 20 + strlen(vips[i]) + 2;
            printf("\n%20s", "");
        }
        printf("%s", vips[i]);
    }
    puts(".");
}
