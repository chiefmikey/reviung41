# ZMK Configuration for Reviung41

This directory contains the ZMK (Zephyr-based keyboard firmware) configuration for the Reviung41 split keyboard.

## 🎹 Keymap Features

- **4-Layer Layout**: Base, Lower, Raise, and Adjust layers
- **App Launching**: iTerm2, VS Code, Chrome, Slack, Spotify via Cmd+Option+key
- **Screenshot Shortcuts**: Screenshot selection and area capture
- **Email Shortcut**: Quick email insertion
- **RGB Lighting**: Full RGB underglow support with animations
- **Bluetooth**: Wireless support for nice!nano v2
- **Mod Taps**: Smart layer switching with hold/tap functionality
- **Custom Macros**: Specialized functions for productivity

## 📁 File Structure

```
zmk/
├── config/
│   ├── boards/
│   │   └── reviung41.keymap    # Main keymap definition
│   ├── reviung41.conf          # ZMK configuration settings
│   └── west.yml                # Zephyr workspace configuration
├── .github/
│   └── workflows/
│       └── build.yml           # GitHub Actions build workflow
├── build.yaml                  # Build matrix configuration
└── README.md                   # This file
```

## 🚀 Quick Start

### Prerequisites
- [ZMK development environment](https://zmk.dev/docs/development/setup)
- Git
- Python 3.6+

### Building Locally

1. **Clone the repository**
   ```bash
   git clone https://github.com/chiefmikey/reviung41.git
   cd reviung41/zmk
   ```

2. **Initialize Zephyr workspace**
   ```bash
   west init -l config
   west update
   west zephyr-export
   ```

3. **Build the firmware**
   ```bash
   west build -p -d build/left -b nice_nano_v2 -- -DZMK_CONFIG="$(pwd)/config" -DSHIELD=reviung41_left
   west build -p -d build/right -b nice_nano_v2 -- -DZMK_CONFIG="$(pwd)/config" -DSHIELD=reviung41_right
   ```

4. **Flash the firmware**
   ```bash
   # Flash left side
   west flash -d build/left

   # Flash right side
   west flash -d build/right
   ```

## 🔧 Configuration

### Hardware Support
- **Controller**: nice!nano v2 (RP2040)
- **Bluetooth**: Built-in Bluetooth LE support
- **RGB**: WS2812 LED strip support
- **Battery**: Built-in battery monitoring

### Keymap Layers

#### Base Layer
Standard QWERTY layout with:
- `Ctrl+` (hold) / `` ` `` (tap) on bottom left
- `Alt+Space` (hold) / `Space` (tap) on bottom center
- `Adjust+Enter` (hold) / `Enter` (tap) on bottom right
- `Lower+Space` (hold) / `Space` (tap) on bottom right
- `Raise+Cmd` (hold) / `Cmd` (tap) on bottom right

#### Lower Layer
Numbers, symbols, and special characters

#### Raise Layer
Function keys, media controls, and RGB controls

#### Adjust Layer
App launching, screenshot shortcuts, email macro, and system controls

## 🎨 Customization

### Modifying the Keymap
Edit `config/boards/reviung41.keymap` to customize your layout.

### Adding Macros
Add new macros in the `macros` section of the keymap file.

### RGB Configuration
Modify `config/reviung41.conf` to adjust RGB settings.

## 🔄 Automated Builds

The firmware is automatically built via GitHub Actions when changes are pushed to the repository. Download the latest build from the [Actions tab](https://github.com/chiefmikey/reviung41/actions).

## 📚 Documentation

- [ZMK Documentation](https://zmk.dev/docs)
- [Reviung41 Hardware](https://github.com/gtips/reviung41)
- [nice!nano Documentation](https://nicekeyboards.com/nice-nano)

## 🐛 Troubleshooting

### Common Issues
- **Build errors**: Check Zephyr environment setup
- **Flash failures**: Ensure keyboard is in bootloader mode
- **Bluetooth issues**: Check battery level and pairing

### Getting Help
- [ZMK Discord](https://discord.gg/5jeFQr2)
- [GitHub Issues](https://github.com/chiefmikey/reviung41/issues)
- [ZMK Documentation](https://zmk.dev/docs)
