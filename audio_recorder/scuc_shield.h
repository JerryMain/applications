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

typedef enum {   // RGB binary coded
    black = 0,   // 000
    blue = 1,    // 001
    green = 2,   // 010
    cyan = 3,    // 011
    red = 4,     // 100
    magenta = 5, // 101
    yellow = 6,  // 110
    white = 7,   // 111
} scuc_shield_led_color_t;

void scuc_shield_setup(scuc_shield_t *dev, const scuc_shield_params_t *params);

void scuc_shield_set_led_color(scuc_shield_t *dev, scuc_shield_led_color_t led_color);

#ifdef __cplusplus
}
#endif

#endif /* SCUC_SHIELD_H */
