#ifndef FSEMU_ACTION_H_
#define FSEMU_ACTION_H_

#include <stdint.h>

#include "fsemu-config.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef uint16_t fsemu_action_t;
typedef int16_t fsemu_action_state_t;
typedef int32_t fsemu_action_and_state_t;

#define FSEMU_ACTION_STATE_MIN -0x7fff
#define FSEMU_ACTION_STATE_MAX 0x7fff

// FIXME: Changed so that EMU flag is invert to NONEMU
#define FSEMU_ACTION_EMU_FLAG 0
#define FSEMU_ACTION_NONEMU_FLAG 0x8000

// Sync for netplay
#define FSEMU_ACTION_SYNC_FLAG 0x4000

#define FSEMU_ACTION_COMMAND_FLAG 0x2000

// FAAA SSSS

// FIXME: EMU should imply SYNC

// #define FSEMU_ACTION_NONE 0x0000
// #define FSEMU_ACTION_OSKEYBOARD 0x0001
// #define FSEMU_ACTION_OSMENU 0x0002

// #define FSEMU_DEFINE_ACTION()

void fsemu_action_post_from_main(uint16_t action);
void fsemu_action_post_from_main_with_state(uint16_t action, int16_t state);

void fsemu_action_process_non_emu(fsemu_action_t action,
                                  fsemu_action_state_t state);

void fsemu_action_process_command_in_main(fsemu_action_t action,
                                          int16_t state);

#define fsemu_action_log(format, ...) \
    fsemu_log("[FSEMU] [ACTION] " format, ##__VA_ARGS__)

#ifdef __cplusplus
}
#endif

#include "fsemu-actions.h"

#endif  // FSEMU_ACTION_H_
