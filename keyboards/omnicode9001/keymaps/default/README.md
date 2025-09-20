# OmniCode:9001 Default Keymap

The default keymap for OmniCode:9001 is designed to provide a powerful and intuitive typing experience across all three modules.

## Layer Overview

### Layer 0: QWERTY Layer
![Base Layer](https://imgur.com/i5GKNq0.png)

Standard ANSI layout with function keys and media controls:
- Volume controls in the top right (Mute, Vol-, Vol+)
- Brightness controls on F-row right side
- Standard navigation cluster
- Full numpad

### Layer 1: Colemak-DH Layer
![Colemak Layer](https://imgur.com/Z7oEj8a.png)

Alternative Colemak-DH layout for ergonomic typing, maintaining same function keys and media controls as Layer 0.

### Layer 2: Navigation Layer (MO(2))
![Navigation Layer](https://imgur.com/nKKRhwv.png)

Enhanced navigation and Zoom controls:
- WASD-style navigation cluster:
  - E: Up, D: Down, S: Left, F: Right
  - W: Home, R: End, T: PgUp, G: PgDn
- Backspace: Delete key
- Zoom meeting controls:
  - ZL (Esc): Leave meeting
  - ZR (F1): Start/Stop recording
  - ZU (Tab): Show/Hide participants
  - ZC (CapsLock): Open chat
  - ZH (LShift): Raise/Lower hand
  - ZA (LCtrl): Toggle audio
  - ZV (LOpt): Toggle video
  - ZS (LCmd): Start/Stop screen sharing
- Media Control
  - X: Volume Down
  - C: Volume Up
  - V: Mute
  - B: Play/Pause
- Space triggers Settings Layer

### Layer 3: Settings Layer (via Navigation Layer + Space)
![Function Layer](https://imgur.com/YZrU3nn.png)

System functions and RGB controls:
- QK_BOOT in ESC position for firmware flashing
- Layout selection (F1: QWERTY, F2: Colemak)
- QK_RBT (CapsLock): Reset keyboard
- EE_CLR (LCtrl): Clear EEPROM
- RGB Matrix controls:
  - Top Row(right): Hue Up, Saturation Up, Value Up, Speed Up
  - Home Row(right): Previous Mode, Toggle On/Off, Next Mode
  - Bottom Row(right): Hue Down, Saturation Down, Value Down, Speed Down

## Special Features

### OS-Specific Key Mapping
- On Windows: Command (⌘) and Option (⌥) keys are automatically swapped in both QWERTY and Colemak layouts
- On macOS: Keys maintain their standard positions
  - Left side: Option (⌥) then Command (⌘)
  - Right side: Command (⌘) then Option (⌥)

## Customization

To customize this keymap:

1. Edit `keymap.c` in this directory
2. Compile with:
   ```bash
   qmk compile -kb omnicode9001 -km default
   ```
3. Flash using:
   ```bash
   qmk flash -kb omnicode9001 -km default
   ```

For more advanced customization options, check the [QMK Documentation](https://docs.qmk.fm/).
