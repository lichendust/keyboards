SRC += source.c
SRC += common/bitc_led.c
SRC += common/remote_kb.c

BOARD = GENERIC_RP_RP2040

TAP_DANCE_ENABLE     = no
BOOTMAGIC_ENABLE     = no
MOUSEKEY_ENABLE      = no
EXTRAKEY_ENABLE      = no
CONSOLE_ENABLE       = no
COMMAND_ENABLE       = no
SLEEP_LED_ENABLE     = no
AUDIO_ENABLE         = no
RGBLIGHT_ENABLE      = no
BACKLIGHT_ENABLE     = no
I2C_DRIVER_REQUIRED  = no
UART_DRIVER_REQUIRED = no
NKRO_ENABLE          = yes
ENCODER_MAP_ENABLE   = yes
