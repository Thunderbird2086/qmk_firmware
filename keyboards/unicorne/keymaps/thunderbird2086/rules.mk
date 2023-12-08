MOUSEKEY_ENABLE = no
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
OLED_ENABLE = yes

TAP_DANCE_ENABLE = yes

APPLE_FN_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += ./lib/layer_state_reader.c
	SRC += ./lib/logo_reader.c
	SRC += ./lib/mode_icon_reader.c
	SRC += oled.c
endif

SRC += process_records.c
SRC += rgb.c
SRC += tap_dances.c

ifneq ("$(wildcard keyboards/unicorne/keymaps/thunderbird2086/secrets.h)","")
	OPT_DEFS += -DSECRETS_ENABLE
endif
