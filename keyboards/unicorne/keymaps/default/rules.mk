OLED_ENABLE = yes

SRC += ./lib/keylogger.c
SRC += ./lib/layer_state_reader.c
SRC += ./lib/logo_reader.c
SRC += ./lib/mode_icon_reader.c
SRC += oled.c
SRC += process_records.c

#OPT_DEFS += -DQWERTY_ENABLE
