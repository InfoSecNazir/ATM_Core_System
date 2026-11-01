# ATM_Core_System

[English](README.md) · [العربية](README_AR.md) · [File index](docs/INDEX.md)

Educational C++ console ATM simulation with withdrawals, deposits, and text-file persistence.

## Repository contents

- [ATM-CLI.cpp](ATM-CLI.cpp)

## Setup and use

From a Visual Studio Developer Command Prompt:

```bat
cl /EHsc /std:c++17 ATM-CLI.cpp /Fe:atm.exe
atm.exe
```

The source reads `Cilent.txt` from its working directory. Supply fictional account records matching the parser before attempting to log in.

The console code uses Windows commands such as `cls` or `pause`; Windows is the intended environment. Build commands below describe the source entry point and have not been compiled as part of this documentation update.

## Notes

This is a learning simulation with text-file account storage, not a production banking system.

[Previous documentation and additional details](README_DETAILS.md)

## License

The repository currently has no root license file. This documentation does not assign a new license.

## Contributing and navigation

[CONTRIBUTING.md](CONTRIBUTING.md) · [Documentation index](docs/INDEX.md) · [Public project index](https://github.com/InfoSecNazir/InfoSecNazir/blob/main/PROJECTS.md)

## Verification scope

Repository organization checked file paths, documentation links, and available dependency manifests. This update did not run or deploy the application.
