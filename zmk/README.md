# ZMK Configuration

This directory contains the ZMK (Zephyr-based keyboard firmware) configuration for the Reviung41.

## Files

- `config/` - ZMK configuration files
  - `boards/reviung41.keymap` - Main keymap definition
  - `reviung41.conf` - ZMK configuration settings
  - `west.yml` - Zephyr workspace configuration
- `build.yaml` - GitHub Actions build matrix
- `.github/` - GitHub Actions workflows for automated builds

## Building

The firmware is automatically built via GitHub Actions when changes are pushed to the repository. You can also build locally using the ZMK build system.

## Usage

1. Clone the repository
2. Navigate to the `zmk/` directory
3. Follow ZMK's build instructions for your specific board
