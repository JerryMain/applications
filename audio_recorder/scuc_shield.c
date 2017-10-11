// Implementation of Scintilla uC course shield device interface

#include <stdio.h>

#include "scuc_shield.h"

#ifdef __cplusplus
extern "C" {
#endif

#if defined(CPU_NATIVE)
// ADC functions are not defined for native
int adc_init(adc_t line)
{
    (void)line;
    return -1;
}

int adc_sample(adc_t line, adc_res_t res)
{
    (void)line;
    (void)res;
    return -1;
}
#endif

char count = 0;

void scuc_shield_button0(void *arg){
    printf("button0\n");
    if (count == 7) {
        count = 0;
    }
    else {
        count++;
    }
    scuc_shield_set_led_color((scuc_shield_t *)arg, count);
}

void scuc_shield_button1(void *arg){
    printf("button1\n");
    if (count == 0) {
        count = 7;
    }
    else {
        count--;
    }
    scuc_shield_set_led_color((scuc_shield_t *)arg, count);
}

void scuc_shield_setup(scuc_shield_t *dev, const scuc_shield_params_t *params)
{
    // LEDs
    dev->led.red = params->led.red;
    dev->led.green = params->led.green;
    dev->led.blue = params->led.blue;
    gpio_init(dev->led.red, GPIO_OD);
    gpio_set(dev->led.red); // LED is low active, so set initially to HIGH
    gpio_init(dev->led.green, GPIO_OD);
    gpio_set(dev->led.green); // LED is low active, so set initially to HIGH
    gpio_init(dev->led.blue, GPIO_OD);
    gpio_set(dev->led.blue); // LED is low active, so set initially to HIGH

    // Buttons
    dev->buttons[0] = params->buttons[0];
    dev->buttons[1] = params->buttons[1];
    gpio_init_int(dev->buttons[0], GPIO_IN_PU, GPIO_FALLING, scuc_shield_button0, dev);
    gpio_init_int(dev->buttons[1], GPIO_IN_PU, GPIO_FALLING, scuc_shield_button1, dev);

    // ADC
    dev->adc = params->adc;
    adc_init(dev->adc);
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
