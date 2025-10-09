# QMK Keyboards

This directory contains QMK firmware configurations for various keyboards.

## Structure

```
qmk/
└── keyboards/           # Keyboard-specific configurations
    ├── reviung/        # Reviung41 keyboard
    │   └── reviung41/
    │       ├── keyboard.json  # Hardware configuration
    │       └── keymaps/
    │           └── chiefmikey/
    │               └── keymap.c  # Keymap definition
    └── boardsource/    # Unicorne keyboard
        └── unicorne/
            ├── keyboard.json  # Hardware configuration
            ├── config.h       # Additional hardware config
            ├── rules.mk       # Build rules
            ├── unicorne.c     # Keyboard-specific code
            └── keymaps/
                └── chiefmikey/
                    └── keymap.c  # Keymap definition
```

## Reviung41

The Reviung41 configuration mirrors the Unicorne keymap as closely as possible while respecting the Reviung41's hardware constraints.

### Features

- **4-layer layout**: Base, Lower, Raise, Adjust
- **App launchers**: iTerm2, VS Code, Chrome, Slack, Spotify
- **Screenshot utilities**: Selection and area capture
- **Email macro**: Quick insertion of wolfemikl@gmail.com
- **RGB lighting**: Uses `rgblight` (11 LEDs)
- **Tap dance**: Mouse button functionality
- **macOS optimized**: All shortcuts work with macOS

### Hardware Constraints

- **No audio**: Reviung41 doesn't support audio features
- **No encoder**: No rotary encoder support
- **No OLED**: No display support
- **No pointing device**: No trackball/trackpad support
- **Single board**: Not a split keyboard
- **41 keys**: 5-key bottom row (vs Unicorne's 6-key)

### Usage

1. **Sync configs**:
   ```bash
   ./sync_reviung41.sh
   ```

2. **Build and flash**:
   ```bash
   qmk compile -kb reviung/reviung41 -km chiefmikey
   qmk flash -kb reviung/reviung41 -km chiefmikey
   ```

## Unicorne

The Unicorne is a full-featured split keyboard with advanced capabilities.

### Features

- **4-layer layout**: Base, Lower, Raise, Adjust
- **App launchers**: iTerm2, VS Code, Chrome, Slack, Spotify
- **Screenshot utilities**: Selection and area capture
- **Email macro**: Quick insertion of wolfemikl@gmail.com
- **Audio support**: Click sounds and startup melodies
- **RGB matrix**: 54 LEDs with advanced animations
- **Encoder**: Rotary encoder support
- **OLED**: Display support
- **Pointing device**: Trackball/trackpad support
- **Split keyboard**: Left and right halves
- **42 keys**: 6-key bottom row

### Usage

1. **Sync configs**:
   ```bash
   ./sync_unicorne.sh
   ```

2. **Build and flash**:
   ```bash
   qmk compile -kb boardsource/unicorne -km chiefmikey
   qmk flash -kb boardsource/unicorne -km chiefmikey
   ```

## Key Differences

| Feature | Reviung41 | Unicorne |
|---------|-----------|----------|
| **Layout** | Single board, 41 keys | Split board, 42 keys |
| **RGB** | `rgblight` (11 LEDs) | `rgb_matrix` (54 LEDs) |
| **Audio** | ❌ Not supported | ✅ Full support |
| **Encoder** | ❌ Not supported | ✅ Rotary encoder |
| **OLED** | ❌ Not supported | ✅ Display support |
| **Pointing Device** | ❌ Not supported | ✅ Trackball/trackpad |
| **Bottom Row** | 5 keys | 6 keys |

## Adding New Keyboards

To add a new keyboard:

1. Create a new directory under `keyboards/`
2. Add the keyboard configuration files:
   - `keyboard.json` (required)
   - `config.h` (if needed)
   - `rules.mk` (if needed)
   - `*.c` files (if needed)
3. Create a `keymaps/chiefmikey/` directory
4. Add `keymap.c` with the keymap definition
5. Create a sync script in the root directory
6. Update this README

## Sync Scripts

The repository uses sync scripts to copy configurations to the global QMK directory (`~/qmk_firmware/`). This approach:

- Keeps the global QMK directory clean
- Allows all configurations to be tracked in this repository
- Makes it easy to manage multiple keyboards
- Enables version control for all keymaps

### Creating a Sync Script

```bash
#!/bin/bash
# Sync [Keyboard] configs to QMK firmware directory

QMK_DIR="$HOME/qmk_firmware/keyboards/[vendor]/[keyboard]"
PROJECT_DIR="/Users/mikl/Dropbox/dev/reviung41"

echo "Syncing [Keyboard] configs to QMK..."

# Create directory if it doesn't exist
mkdir -p "$QMK_DIR/keymaps"

# Copy keyboard config
cp "$PROJECT_DIR/qmk/keyboards/[vendor]/[keyboard]/keyboard.json" "$QMK_DIR/"

# Copy additional files if they exist
[ -f "$PROJECT_DIR/qmk/keyboards/[vendor]/[keyboard]/config.h" ] && \
    cp "$PROJECT_DIR/qmk/keyboards/[vendor]/[keyboard]/config.h" "$QMK_DIR/"

[ -f "$PROJECT_DIR/qmk/keyboards/[vendor]/[keyboard]/rules.mk" ] && \
    cp "$PROJECT_DIR/qmk/keyboards/[vendor]/[keyboard]/rules.mk" "$QMK_DIR/"

# Copy keymaps
cp -r "$PROJECT_DIR/qmk/keyboards/[vendor]/[keyboard]/keymaps/chiefmikey" "$QMK_DIR/keymaps/"

echo "✅ [Keyboard] configs synced to QMK directory"
echo "You can now run: qmk compile -kb [vendor]/[keyboard] -km chiefmikey"
```

## Configuration Files

- **`keyboard.json`**: Hardware configuration (processor, pins, features, etc.)
- **`config.h`**: Additional hardware configuration (if needed)
- **`rules.mk`**: Build rules and feature flags (if needed)
- **`*.c`**: Keyboard-specific code (if needed)
- **`keymap.c`**: Keymap definition with layers and behaviors
