# QMK Configuration for Reviung41

This directory contains the QMK (Quantum Mechanical Keyboard) configuration for the Reviung41 split keyboard with the ChiefMikey keymap.

## 🎹 Keymap Features

- **4-Layer Layout**: Base, Lower, Raise, and Adjust layers
- **App Launching**: iTerm2, VS Code, Chrome, Slack, Spotify via Cmd+Option+key
- **Screenshot Shortcuts**: Screenshot selection and area capture
- **Email Shortcut**: Quick email insertion
- **RGB Lighting**: Full RGB Matrix support with animations
- **Audio Feedback**: Click sounds and startup melodies
- **Custom Keycodes**: Specialized functions for productivity
- **Tap Dance**: Mouse button combinations

## Key Layout

### Base Layer
Standard QWERTY layout with:
- `Ctrl+` (hold) / `` ` `` (tap) on bottom left
- `Alt+Space` (hold) / `Space` (tap) on bottom center
- `Adjust+Enter` (hold) / `Enter` (tap) on bottom right
- `Lower+Space` (hold) / `Space` (tap) on bottom right
- `Raise+Cmd` (hold) / `Cmd` (tap) on bottom right

### Lower Layer
Numbers, symbols, and special characters

### Raise Layer
Function keys, media controls, and RGB controls

### Adjust Layer
App launching, screenshot shortcuts, and system controls

## Building and Flashing

```bash
# Build the keymap
qmk compile -kb reviung41 -km chiefmikey

# Flash the keymap
qmk flash -kb reviung41 -km chiefmikey
```

## macOS Setup

For app launching to work, set up these shortcuts in macOS System Preferences > Keyboard > Shortcuts > App Shortcuts:

- iTerm2: `Cmd+Option+I`
- Visual Studio Code: `Cmd+Option+V`
- Google Chrome: `Cmd+Option+C`
- Slack: `Cmd+Option+L`
- Spotify: `Cmd+Option+S`

## Hardware

- **Controller**: RP2040 (nice!nano v2)
- **RGB**: WS2812 LEDs with RGB Matrix support
- **Audio**: Built-in speaker support with PWM audio
- **Bluetooth**: Built-in Bluetooth LE support
- **Battery**: Built-in battery monitoring
- **Layout**: 41-key single board
