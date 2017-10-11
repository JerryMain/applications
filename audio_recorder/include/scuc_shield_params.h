#ifndef SCUC_SHIELD_PARAMS_H
#define SCUC_SHIELD_PARAMS_H

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SCUC_SHIELD_PARAM_LED_R
#define SCUC_SHIELD_PARAM_LED_R (GPIO_PIN(PORT_C, 0))
#endif
#ifndef SCUC_SHIELD_PARAM_LED_G
#define SCUC_SHIELD_PARAM_LED_G (GPIO_PIN(PORT_C, 1))
#endif
#ifndef SCUC_SHIELD_PARAM_LED_B
#define SCUC_SHIELD_PARAM_LED_B (GPIO_PIN(PORT_C, 2))
#endif
#ifndef SCUC_SHIELD_BUTTON0
#define SCUC_SHIELD_BUTTON0 (GPIO_PIN(PORT_A, 0))
#endif
#ifndef SCUC_SHIELD_BUTTON1
#define SCUC_SHIELD_BUTTON1 (GPIO_PIN(PORT_A, 1))
#endif
#ifndef SCUC_SHIELD_ADC
#define SCUC_SHIELD_ADC (ADC_LINE(0))
#endif

static const scuc_shield_params_t scuc_shield_params[] = {
    {
        .led.red = SCUC_SHIELD_PARAM_LED_R,
        .led.green = SCUC_SHIELD_PARAM_LED_G,
        .led.blue = SCUC_SHIELD_PARAM_LED_B,
        .buttons[0] = SCUC_SHIELD_BUTTON0,
        .buttons[1] = SCUC_SHIELD_BUTTON1,
        .adc = SCUC_SHIELD_ADC
    }
};

#ifdef __cplusplus
}
#endif

#endif /* SCUC_SHIELD_PARAMS_H */
