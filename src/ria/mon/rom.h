
/*
 * Copyright (c) 2023 Rumbledethumps
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#ifndef _ROM_H_
#define _ROM_H_

#include <stddef.h>
#include <stdbool.h>

// Kernel events
void rom_init();
void rom_task();
void rom_reset();

// True when this module is busy with IO.
bool rom_active();

// Monitor commands
void rom_mon_load(const char *args, size_t len);
void rom_mon_info(const char *args, size_t len);
void rom_mon_install(const char *args, size_t len);
void rom_mon_remove(const char *args, size_t len);

// Begin loading an installed rom, if exists.
bool rom_load_lfs(const char *args, size_t len);

// Display help from an installed ROM.
bool rom_help_lfs(const char *args, size_t len);

#endif /* _ROM_H_ */
