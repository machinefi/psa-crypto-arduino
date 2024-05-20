# PSACrypto Arduino Library

[![License](https://img.shields.io/badge/license-Apache%202.0-blue.svg)](https://opensource.org/licenses/Apache-2.0)
[![GitHub release](https://img.shields.io/github/release/machinefi/psa-crypto.svg)](https://github.com/machinefi/psa-crypto/releases)
[![Unit Tests](https://github.com/machinefi/psa-crypto/workflows/Run%20unit%20tests/badge.svg)](https://github.com/machinefi/psa-crypto/actions/workflows/ci.yml)
[![Arduino CI](https://github.com/machinefi/psa-crypto/workflows/Arduino%20CI/badge.svg)](https://github.com/machinefi/psa-crypto/actions/workflows/arduino-ci.yml)
[![Code Formatting](https://github.com/machinefi/psa-crypto/workflows/Code%20formatting/badge.svg)](https://github.com/machinefi/psa-crypto/actions/workflows/code-formatting.yml)
[![Release-please](https://github.com/machinefi/psa-crypto-arduino/workflows/release-please/badge.svg)](https://github.com/machinefi/psa-crypto/actions/workflows/release-please.yml)

PSACrypto is an Arduino library that implements the cryptography functionality of the Platform Security Architecture (PSA) API. It provides a standardized and easy-to-use interface for cryptographic operations on Arduino boards, ensuring secure communication, data integrity, and confidentiality.

PSACrypto is designed specifically for building Decentralized Infrastructure Networks ([DePIN](https://iotex.io/blog/what-are-decentralized-physical-infrastructure-networks-depin/)) projects.  
To find more examples of DePIN projects, you can visit [DePIN Scan](https://depinscan.io/)

## Features

- **Secure Key Generation**: Generate secure cryptographic keys for various algorithms.
- **Hash Functions**: Compute hash values using cryptographic hash functions.
- **Symmetric Encryption**: Encrypt and decrypt data using symmetric encryption algorithms.
- **Asymmetric Encryption**: Perform public key encryption and decryption operations.
- **Random Number Generation**: Generate random numbers for secure cryptographic operations.

## Installation

### Arduino IDE

To install the PSACrypto library using the Arduino IDE, follow these steps:

1. Open the Arduino IDE.
2. Go to **Sketch > Include Library > Manage Libraries**.
3. The Library Manager window will open, showing a list of available libraries.
4. In the search bar, type "PSACrypto" and press Enter.
5. Locate the "PSACrypto" library in the search results.
6. Click on the library entry to open its details.
7. Click the "Install" button to install the library.
8. Wait for the installation process to complete.
9. After installation, close the Library Manager window.
10. The PSACrypto library is now installed and ready to be used.

### Manual Installation

To install the PSACrypto library manually, follow these steps:

1. Download the PSACrypto library from the [GitHub repository](https://github.com/machinefi/psa-crypto-arduino).
2. Extract the downloaded ZIP file.
3. Rename the extracted folder to "PSACrypto".
4. Move the "PSACrypto" folder to your Arduino libraries directory. The default locations are:
   - **Windows**: `Documents\Arduino\libraries`
   - **Mac**: `Documents/Arduino/libraries`
   - **Linux**: `Arduino/libraries`
5. Restart the Arduino IDE.
6. The PSACrypto library should now be available under **Sketch > Include Library** menu.
7. You can now include the library in your Arduino sketches and use its features.

### PlatformIO

To install the PSACrypto library using PlatformIO, follow these steps:

1. Create a new PlatformIO project or open an existing one.
2. Open the `platformio.ini` file located in the root of your project.
3. Add the following line to the `[env:<your_board>]` section:

```ini
lib_deps =
    PSACrypto
```

Replace <your_board> with the target board/platform for your project (e.g., esp32, arduino_due, etc.).

1. Save the platformio.ini file.
2. PlatformIO will automatically install the PSACrypto library and its dependencies when you build/upload your project.

## Usage

### Arduino IDE

1. Open the Arduino IDE.
2. Go to File > Examples > PSACrypto to access the example sketches.
3. Select an example sketch to open it.
4. Modify the sketch as needed to fit your requirements.
5. Upload the sketch to your Arduino board.
6. Open the Serial Monitor to view the output.

### PlatformIO

1. Open your PlatformIO project.
2. Navigate to the src folder.
3. Create a new .cpp file or open an existing one.
4. Include the PSACrypto library by adding the following line at the top of your file:

```c++
# include <PSACrypto.h>
```

For detailed information on using the PSACrypto library, including usage examples and API reference, please refer to the [Documentation](https://machinefi.github.io/psa-crypto-arduino/index.html).

## Compatible Hardware

The PSACrypto library has been tested and is compatible with the following hardware:

- ESP32
- Arduino Nano 33 IoT

Please note that the library may also work with other Arduino-compatible boards, but it has specifically been tested and verified with the above-mentioned hardware.

It's recommended to check the official documentation of your specific board or consult the manufacturer's specifications to ensure compatibility with the PSACrypto library.

## Contributing

Contributions are welcome! Please follow the guidelines in [CONTRIBUTING.md](CONTRIBUTING.md) to contribute to this project.

## License

This library is licensed under Apache License 2.0. See the [LICENSE](LICENSE) file for more information.

## Credits

- [IoTeX](https://iotex.io/)
- [MachineFi](https://github.com/machinefi/)
