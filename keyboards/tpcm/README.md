## QMK Firmware Build Guide

This directory contains a custom QMK firmware for the HK Split (let's sync) keyboard, which is not included in the canonical QMK repository. Follow these steps to build and flash the firmware:

### Prerequisites
Ensure the following tools are installed on your system:
- **Python 3**: Required for the QMK CLI.
- **Git**: Required to clone the QMK repository.
- **QMK CLI**: Installed in Step 3 below.

### Step 1: Clone the QMK Firmware Repository
If you haven't already, clone the official QMK Firmware repository:
```bash
git clone https://github.com/qmk/qmk_firmware.git
```

### Step 2: Copy the Custom Firmware
Copy the contents of this directory (`hk-split-qmk/keyboards/tpcm/`) into the `keyboards/` directory of the cloned QMK repository:
```bash
cp -r <path-to-hk-split-qmk>/keyboards/tpcm <path-to-qmk_firmware>/keyboards/
```

### Step 3: Install QMK CLI
Ensure you have the QMK CLI installed. If not, install it using:
```bash
python3 -m pip install qmk
```
Refer to [QMK Tutorial](https://docs.qmk.fm/newbs_getting_started#setting-up-your-qmk-environment) for the details.

### Step 4: Set Up the QMK Environment
Run the following command to set up the QMK environment:
```bash
qmk setup
```

### Step 5: Build the Firmware
Navigate to the QMK firmware directory and build the firmware for the HK Split (let's sync) keyboard:
```bash
qmk compile -kb tpcm/hk_split -km default
```

### Step 6: Flash the Firmware
1. Enter bootloader mode using one of the following methods:
   - Double-tap the `RESET` button on the PCB.
   - Connect the HK Split (let's sync) keyboard while pressing the `RESET` button on the PCB.
   - Tap the `QK_BOOT` keycode.
1. Wait for the OS to detect the device.
1. Copy the `.uf2` file to the new USB disk.
1. Wait for the keyboard to become available.

### Step 7: Customize Your Keymap (Optional)
To customize your keymap:
1. Edit the `keymap.c` file located in the `keyboards/tpcm/hk_split/keymaps/` directory.
1. Repeat Steps 5 and 6 to build and flash the updated firmware.

### Troubleshooting
- **Build Errors**: Ensure all dependencies are installed and the QMK environment is set up correctly.
- **Flashing Issues**: Verify the device is in bootloader mode and recognized by the OS.

By following these steps, you can build and flash the custom QMK firmware for the HK Split (let's sync) keyboard. For more information, refer to the [QMK documentation](https://docs.qmk.fm/). If you encounter any issues, consider reaching out to the QMK community for support.
