# Keyboard Keymaps Repository

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![ZMK](https://img.shields.io/badge/ZMK-Config-blue)](https://zmk.dev/)
[![QMK](https://img.shields.io/badge/QMK-Config-green)](https://qmk.fm/)

Professional keyboard firmware configurations for multiple keyboards, supporting both ZMK and QMK firmware ecosystems. This repository consolidates all keyboard keymaps in one organized location.

## 🚀 Features

- **Dual Firmware Support**: Both ZMK and QMK configurations
- **Multiple Keyboards**: Reviung41, Unicorne, and more
- **Production Ready**: Clean, well-documented code
- **Custom Keymaps**: Optimized layouts with advanced features
- **RGB Lighting**: Full RGB support with animations
- **Bluetooth**: Wireless support for compatible controllers
- **macOS Optimized**: App launching and screenshot shortcuts
- **Consolidated Management**: All keymaps in one repository

## 📁 Repository Structure

```
keyboards/
├── qmk/                    # QMK configurations
│   └── keyboards/         # Keyboard-specific configs
│       ├── reviung/       # Reviung41 keyboard
│       │   └── reviung41/
│       │       ├── keyboard.json
│       │       └── keymaps/
│       │           └── chiefmikey/
│       │               └── keymap.c
│       └── boardsource/   # Unicorne keyboard
│           └── unicorne/
│               ├── keyboard.json
│               ├── config.h
│               ├── rules.mk
│               ├── unicorne.c
│               └── keymaps/
│                   └── chiefmikey/
│                       └── keymap.c
├── zmk/                    # ZMK configurations
│   ├── keyboards/         # Keyboard-specific configs
│   │   └── reviung41/    # Reviung41 keyboard
│   │       └── keymap.dtsi
│   ├── config/           # Global ZMK configuration
│   │   ├── reviung41.conf
│   │   └── west.yml
│   ├── build.yaml        # GitHub Actions build config
│   └── README.md         # ZMK-specific documentation
├── sync_reviung41.sh     # Sync script for Reviung41
├── sync_unicorne.sh      # Sync script for Unicorne
├── LICENSE               # MIT License
└── README.md             # This file
```

## 🎹 Supported Keyboards

### Reviung41
- **QMK**: `qmk/keyboards/reviung/reviung41/`
- **ZMK**: `zmk/keyboards/reviung41/`
- **Features**: 4-layer layout, app launchers, RGB lighting
- **Controllers**: RP2040 (QMK), nice!nano v2 (ZMK)

### Unicorne
- **QMK**: `qmk/keyboards/boardsource/unicorne/`
- **Features**: Split keyboard, audio, encoder, OLED, RGB matrix
- **Controller**: RP2040

## 🛠️ Quick Start

### QMK (Reviung41)
```bash
# Sync configs to QMK directory
./sync_reviung41.sh

# Build and flash
qmk compile -kb reviung/reviung41 -km chiefmikey
qmk flash -kb reviung/reviung41 -km chiefmikey
```

### QMK (Unicorne)
```bash
# Sync configs to QMK directory
./sync_unicorne.sh

# Build and flash
qmk compile -kb boardsource/unicorne -km chiefmikey
qmk flash -kb boardsource/unicorne -km chiefmikey
```

### ZMK (Reviung41)
```bash
# Build locally
cd zmk
west build -p -d build/reviung41 -b nice_nano_v2 -- -DZMK_CONFIG="$(pwd)/config" -DKEYMAP_FILE="$(pwd)/keyboards/reviung41/keymap.dtsi"

# Or use GitHub Actions for automatic builds
```

## 📖 Documentation

- **[ZMK Documentation](zmk/README.md)** - ZMK-specific setup and usage
- **[QMK Documentation](qmk/README.md)** - QMK-specific setup and usage

## 🔄 Sync Scripts

This repository uses sync scripts to copy configurations to the global QMK directory:

- **`sync_reviung41.sh`**: Syncs Reviung41 configs to `~/qmk_firmware/keyboards/reviung/reviung41/`
- **`sync_unicorne.sh`**: Syncs Unicorne configs to `~/qmk_firmware/keyboards/boardsource/unicorne/`

This approach keeps the global QMK directory clean while allowing all configurations to be tracked in this repository.

## 🤝 Contributing

Contributions are welcome! Please see our [Contributing Guidelines](CONTRIBUTING.md) for details.

### Development Setup
1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Test both ZMK and QMK configurations
5. Submit a pull request

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🙏 Acknowledgments

- [Reviung41](https://github.com/gtips/reviung41) - Original keyboard design
- [ZMK](https://zmk.dev/) - Modern keyboard firmware
- [QMK](https://qmk.fm/) - Quantum Mechanical Keyboard firmware
- [nice!nano](https://nicekeyboards.com/nice-nano) - Wireless controller

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/chiefmikey/reviung41/issues)
- **Discussions**: [GitHub Discussions](https://github.com/chiefmikey/reviung41/discussions)
- **Documentation**: See individual README files in each directory
