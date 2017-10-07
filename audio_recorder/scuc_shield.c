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
    gpio_set(dev->led.red);
    gpio_init(dev->led.green, GPIO_OD);
    gpio_set(dev->led.green);
    gpio_init(dev->led.blue, GPIO_OD);
    gpio_set(dev->led.blue);
}

void scuc_shield_toggle_led_red(scuc_shield_t *dev)
{
    gpio_toggle(dev->led.red);
    printf("Red LED toggled\n");
}

#ifdef __cplusplus
}
#endif
