# Keymap specific
## Old defines? Were they replaced?
# SERIAL_LINK_ENABLE = yes
# VISUALIZER_ENABLE = yes
# LCD_ENABLE = yes
# LED_ENABLE = no
# LCD_BACKLIGHT_ENABLE = yes

# global
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE = no         # Commands for debug and configuration
UNICODE_ENABLE = no         # Unicode

SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
TAP_DANCE_ENABLE = yes      # Tap dance
# TERMINAL_ENABLE = no
LED_MATRIX_ENABLE = no

LAYOUT_ergodox_VERSION = $(shell \
 if [ -d "${LAYOUT_ergodox_PATH}/.git" ]; then \
  cd "${LAYOUT_ergodox_PATH}" && git describe --abbrev=6 --dirty --always --tags --match 'v*' 2>/dev/null; \
 else echo QMK; fi)

LAYOUT_ergodox_BRANCH = $(shell \
 if [ -d "${LAYOUT_ergodox_PATH}/.git" ]; then \
  cd "${LAYOUT_ergodox_PATH}"; \
 fi; \
 git rev-parse --abbrev-ref HEAD 2>/dev/null)

OPT_DEFS += -DLAYOUT_ergodox_VERSION=\"$(LAYOUT_ergodox_VERSION)\\\#$(LAYOUT_ergodox_BRANCH)\"
