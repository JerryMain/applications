#include <stdio.h>

#include "shell.h"

#include "scuc_shield.h"
#include "include/scuc_shield_params.h"

scuc_shield_t shield;

int toggle_led_r(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    printf("toggle command\n");
    scuc_shield_toggle_led_red(&shield);
    return 0;
}

static const shell_command_t commands[] = {
    {"toggle_r", "toggles the LED red color", toggle_led_r},
    {NULL, NULL, NULL}
};

int main(void)
{
    printf("Scintilla uC course application, running on a(n) %s board.\n", RIOT_BOARD);

    scuc_shield_setup(&shield, scuc_shield_params);

    scuc_shield_toggle_led_red(&shield);

    char line_buf[SHELL_DEFAULT_BUFSIZE];
    shell_run(commands, line_buf, SHELL_DEFAULT_BUFSIZE);

    return 0;
}
