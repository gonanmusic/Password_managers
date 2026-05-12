# Password Manager

A secure command-line password manager written in C, featuring AES encryption for credential storage and a simple master password authentication system.

## Features

- **Secure Credential Storage**: Store website URLs, usernames, and passwords
- **AES Encryption**: All passwords are encrypted using OpenSSL cryptographic libraries
- **Master Password Protection**: Single master password protects access to all stored credentials
- **Credential Management**:
  - Add new credentials
  - List all stored credentials
  - Modify existing credentials
- **Lightweight**: Minimal dependencies, portable C implementation
- **Command-line Interface**: Simple and intuitive text-based menu system

## Requirements

- GCC compiler
- OpenSSL 3.x (installed via Homebrew)
- UNIX-like environment (macOS, Linux)

## Installation

### Prerequisites

Install OpenSSL 3.x using Homebrew:

```bash
brew install openssl@3
```

### Building

Clone the repository and navigate to the BUILD directory:

```bash
cd main/BUILD
```

Compile the project:

```bash
make
```

To clean build artifacts:

```bash
make clean
```

To rebuild from scratch:

```bash
make re
```

## Usage

Run the password manager:

```bash
./password_manager
```

### First Launch

On first launch, you will be prompted to set up a master password. This password will be required to access your credentials in future sessions.

### Main Menu Options

1. **Add Credential** (Option 0): Create and store a new password entry
2. **List Credentials** (Option 1): Display all stored credentials
3. **Modify Credential** (Option 2): Update an existing credential entry

## Architecture

The project is organized into modular components:

- **main.c**: Application entry point and master password authentication
- **ui.c**: User interface and menu system
- **add_credential.c**: Credential creation and validation
- **list_credential.c**: Credential retrieval and display
- **encrypted_credential.c**: Encryption operations
- **decrypted_credential.c**: Decryption operations
- **connexion.c**: Master password verification
- **write_credential.c**: Persistent storage handling
- **basic_function.h**: Core utility functions and data structures

## Security Considerations

- Master passwords are hashed and compared during authentication
- Individual passwords are encrypted before storage
- No plaintext passwords are stored on disk
- The application performs input validation on URLs and credentials

## Compilation Flags

The project compiles with strict safety flags:

- `-Wall -Wextra -Werror`: Enable all warnings and treat them as errors
- Links against OpenSSL cryptographic library

## Contributing

This is a personal project. For bug reports or suggestions, please open an issue.

## License

This project is provided as-is for educational and personal use.

## Author

Created by Guillaume-Ronan NOVELLA
