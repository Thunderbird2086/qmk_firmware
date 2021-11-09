# Thunderbird2086's custom 3x5/3x6 keyboards Layout

Mac and **pinky** friendly keymap.


## Custom OLED
This keymap includes custom OLED font and code. The font contains some logos and status indidcators from [gotham](https://github.com/qmk/qmk_firmware/tree/master/keyboards/crkbd/keymaps/gotham) and [soundmonster](https://github.com/qmk/qmk_firmware/tree/master/keyboards/crkbd/keymaps/soundmonster) including my own CAPS LOCK icon.  Enable OLED in rukes.mk to check it out. Feel free to reuse the font or parts of it.

## Flashing
Flash using `make unicorne/3x5:default:avrdude` for Pro Micro and `make unicorne/3x5:default:dfu` for Elite-C.
