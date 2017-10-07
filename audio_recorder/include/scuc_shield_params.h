#ifndef SCUC_SHIELD_PARAMS_H
#define SCUC_SHIELD_PARAMS_H

#include "board.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifndef SCUC_SHIELD_PARAM_LED_R
#define SCUC_SHIELD_PARAM_LED_R (GPIO_PIN(2, 0))
#endif
#ifndef SCUC_SHIELD_PARAM_LED_G
#define SCUC_SHIELD_PARAM_LED_G (GPIO_PIN(2, 1))
#endif
#ifndef SCUC_SHIELD_PARAM_LED_B
#define SCUC_SHIELD_PARAM_LED_B (GPIO_PIN(2, 2))
#endif

static const scuc_shield_params_t scuc_shield_params[] = {
    {
        .led.red = SCUC_SHIELD_PARAM_LED_R,
        .led.green = SCUC_SHIELD_PARAM_LED_G,
        .led.blue = SCUC_SHIELD_PARAM_LED_B
    }
};

#ifdef __cplusplus
}
#endif

#endif /* SCUC_SHIELD_PARAMS_H */
