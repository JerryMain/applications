// Implementation of Scintilla uC course shield device interface

#include <stdio.h>

#include "scuc_shield.h"

#ifdef __cplusplus
extern "C" {
#endif

void scuc_shield_setup(scuc_shield_t *dev, const scuc_shield_params_t *params)
{
    dev->led.red = params->led.red;
    dev->led.green = params->led.green;
    dev->led.blue = params->led.blue;
    gpio_init(dev->led.red, GPIO_OD);
    // LED is low active, so set initially to HIGH
    gpio_set(dev->led.red);
    gpio_init(dev->led.green, GPIO_OD);
    // LED is low active, so set initially to HIGH
    gpio_set(dev->led.green);
    gpio_init(dev->led.blue, GPIO_OD);
    // LED is low active, so set initially to HIGH
    gpio_set(dev->led.blue);
}

void scuc_shield_set_led_color(scuc_shield_t *dev, scuc_shield_led_color_t led_color)
{
    switch (led_color) {
    case white:
        gpio_clear(dev->led.red);
        gpio_clear(dev->led.green);
        gpio_clear(dev->led.blue);
        break;
    case red:
        gpio_clear(dev->led.red);
        gpio_set(dev->led.green);
        gpio_set(dev->led.blue);
        break;
    case green:
        gpio_set(dev->led.red);
        gpio_clear(dev->led.green);
        gpio_set(dev->led.blue);
        break;
    case blue:
        gpio_set(dev->led.red);
        gpio_set(dev->led.green);
        gpio_clear(dev->led.blue);
        break;
    case yellow:
        gpio_clear(dev->led.red);
        gpio_clear(dev->led.green);
        gpio_set(dev->led.blue);
        break;
    case cyan:
        gpio_set(dev->led.red);
        gpio_clear(dev->led.green);
        gpio_clear(dev->led.blue);
        break;
    case magenta:
        gpio_clear(dev->led.red);
        gpio_set(dev->led.green);
        gpio_clear(dev->led.blue);
        break;
    case black:
    default:
        gpio_set(dev->led.red);
        gpio_set(dev->led.green);
        gpio_set(dev->led.blue);
    }
}

#ifdef __cplusplus
}
#endif
