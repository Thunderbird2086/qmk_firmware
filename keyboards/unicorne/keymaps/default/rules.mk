RGB_MATRIX_ENABLE = yes
OLED_ENABLE = yes

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += ./lib/keylogger.c
	SRC += ./lib/layer_state_reader.c
	SRC += ./lib/logo_reader.c
	SRC += ./lib/mode_icon_reader.c
	SRC += oled.c
endif
