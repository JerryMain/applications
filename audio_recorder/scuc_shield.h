// Interface declaration of Scintilla uC course shield

#ifndef SCUC_SHIELD_H
#define SCUC_SHIELD_H

#include "periph/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    struct {
        gpio_t red;
        gpio_t green;
        gpio_t blue;
    } led;
} scuc_shield_params_t;

typedef struct {
    struct {
        gpio_t red;
        gpio_t green;
        gpio_t blue;
    } led;
} scuc_shield_t;

void scuc_shield_setup(scuc_shield_t *dev, const scuc_shield_params_t *params);

void scuc_shield_toggle_led_red(scuc_shield_t *dev);

#ifdef __cplusplus
}
#endif

#endif /* SCUC_SHIELD_H */
