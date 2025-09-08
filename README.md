# Reviung41 Keymaps

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
[![ZMK](https://img.shields.io/badge/ZMK-Config-blue)](https://zmk.dev/)
[![QMK](https://img.shields.io/badge/QMK-Config-green)](https://qmk.fm/)

Professional keyboard firmware configurations for the [Reviung41](https://github.com/gtips/reviung41) split keyboard, supporting both ZMK and QMK firmware ecosystems.

## 🚀 Features

- **Dual Firmware Support**: Both ZMK and QMK configurations
- **Production Ready**: Clean, well-documented code
- **Custom Keymaps**: Optimized layouts with advanced features
- **Audio Support**: Click sounds and startup melodies
- **RGB Lighting**: Full RGB Matrix support with animations
- **Bluetooth**: Wireless support for compatible controllers
- **macOS Optimized**: App launching and screenshot shortcuts

## 📁 Repository Structure

```
reviung41/
├── zmk/                 # ZMK (Zephyr-based) configuration
│   ├── config/         # ZMK config files
│   ├── .github/        # GitHub Actions workflows
│   └── README.md       # ZMK-specific documentation
├── qmk/                # QMK configuration
│   ├── keymaps/        # QMK keymaps
│   ├── config.h        # Hardware configuration
│   └── README.md       # QMK-specific documentation
├── LICENSE             # MIT License
└── README.md           # This file
```

## 🎹 Keymaps

### ZMK Configuration
- **Location**: `zmk/config/boards/reviung41.keymap`
- **Features**: 4-layer layout with macros and RGB support
- **Controller**: nice!nano v2 (Bluetooth LE)

### QMK Configuration
- **Location**: `qmk/keymaps/chiefmikey/`
- **Features**: Advanced keymap with app launching, audio, and RGB
- **Controller**: RP2040 (nice!nano v2)

## 🛠️ Quick Start

### ZMK
```bash
# Clone the repository
git clone https://github.com/chiefmikey/reviung41.git
cd reviung41/zmk

# Follow ZMK build instructions
# See zmk/README.md for details
```

### QMK
```bash
# Clone the repository
git clone https://github.com/chiefmikey/reviung41.git
cd reviung41/qmk

# Build and flash
qmk compile -kb reviung41 -km chiefmikey
qmk flash -kb reviung41 -km chiefmikey
```

## 📖 Documentation

- **[ZMK Documentation](zmk/README.md)** - ZMK-specific setup and usage
- **[QMK Documentation](qmk/README.md)** - QMK-specific setup and usage

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
