SRC += source.c
SRC += common/bitc_led.c
SRC += common/remote_kb.c

BOARD = GENERIC_RP_RP2040

# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

WS2812_DRIVER = vendor
# CONSOLE_ENABLE = yes        # Console for debug

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
NKRO_ENABLE          = no
I2C_DRIVER_REQUIRED  = yes
UART_DRIVER_REQUIRED = yes
ENCODER_MAP_ENABLE   = yes
