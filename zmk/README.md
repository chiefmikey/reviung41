# ZMK Keyboards

This directory contains ZMK firmware configurations for various keyboards.

## Structure

```
zmk/
├── keyboards/           # Keyboard-specific configurations
│   └── reviung41/      # Reviung41 keyboard
│       └── keymap.dtsi # Keymap definition
├── config/             # Global ZMK configuration
│   ├── reviung41.conf  # Reviung41-specific config
│   └── west.yml        # ZMK dependencies
└── build.yaml          # GitHub Actions build configuration
```

## Reviung41

The Reviung41 configuration mirrors the QMK keymap as closely as possible while respecting ZMK's capabilities and the Reviung41's hardware constraints.

### Features

- **4-layer layout**: Base, Lower, Raise, Adjust
- **App launchers**: iTerm2, VS Code, Chrome, Slack, Spotify
- **Screenshot utilities**: Selection and area capture
- **Email macro**: Quick insertion of wolfemikl@gmail.com
- **RGB controls**: Lighting and mode cycling
- **Bluetooth support**: Wireless operation
- **macOS optimized**: All shortcuts work with macOS

### Usage

1. **Build locally**:
   ```bash
   cd zmk
   west build -p -d build/reviung41 -b nice_nano_v2 -- -DZMK_CONFIG="$(pwd)/config" -DKEYMAP_FILE="$(pwd)/keyboards/reviung41/keymap.dtsi"
   ```

2. **Build via GitHub Actions**:
   - Push changes to trigger automatic builds
   - Download firmware from Actions artifacts

### Key Differences from QMK

- **ZMK syntax**: Uses DeviceTree syntax instead of C macros
- **Macro definitions**: Defined in DeviceTree format
- **Layer naming**: Uses `default_layer`, `lower_layer`, etc.
- **RGB controls**: Uses ZMK-specific RGB keycodes
- **No audio**: Reviung41 doesn't support audio in ZMK

## Adding New Keyboards

To add a new keyboard:

1. Create a new directory under `keyboards/`
2. Add the keymap file (`.dtsi` format)
3. Create a corresponding config file in `config/`
4. Update `build.yaml` to include the new keyboard
5. Update this README

## Configuration Files

- **`keymap.dtsi`**: Defines the keymap, macros, and behaviors
- **`*.conf`**: Hardware-specific configuration (RGB, Bluetooth, etc.)
- **`west.yml`**: ZMK dependencies and versions
- **`build.yaml`**: GitHub Actions build matrix
