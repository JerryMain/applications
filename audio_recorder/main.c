#include <stdio.h>

#include "shell.h"

#include "scuc_shield.h"
#include "include/scuc_shield_params.h"

scuc_shield_t shield;

int set_led_color(int argc, char **argv)
{
    if (argc != 2){
        printf("incorrect number of arguments\n");
        return -1;
    }
    scuc_shield_set_led_color(&shield, (argv[1][0] - '0'));
    return 0;
}

int get_adc_sample(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    printf("Value: %d\n", adc_sample(shield.adc, ADC_RES_10BIT));
    return 0;
}

static const shell_command_t commands[] = {
    {"set_led", "Set LED to specified color", set_led_color},
    {"sample", "Print sample from ADC", get_adc_sample},
    {NULL, NULL, NULL}
};

int main(void)
{
    printf("Scintilla uC course application, running on a(n) %s board.\n", RIOT_BOARD);

    scuc_shield_setup(&shield, scuc_shield_params);

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
