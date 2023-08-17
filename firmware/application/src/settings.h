#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdint.h>

#include "utils.h"

#define SETTINGS_CURRENT_VERSION 2

typedef enum {
    SettingsAnimationModeFull = 0,
    SettingsAnimationModeMinimal = 1,
    SettingsAnimationModeNone = 2,
} settings_animation_mode_t;

typedef enum {
    SettingsUsbCdcLogModeNone = 0,
    SettingsUsbCdcLogModeNrfLog = 1,
} settings_usbcdc_log_mode_t;

typedef struct ALIGN_U32 {
    uint16_t version;
    uint8_t animation_config : 2;
    uint8_t usbcdc_log_config : 2;
    uint16_t reserved0 : 12;
    uint32_t reserved1;
    uint32_t reserved2;
} settings_data_t;

void settings_init_config(void);
void settings_migrate(void);
void settings_load_config(void);
uint8_t settings_save_config(void);
uint8_t settings_get_animation_config(void);
void settings_set_animation_config(uint8_t value);
uint8_t settings_get_usbcdc_log_config(void);
void settings_set_usbcdc_log_config(uint8_t value);

#endif
