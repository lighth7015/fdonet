
# FDONet
A from-scratch AOL 3.x/4.x-compatible P3 and FDO protocol server. Run your own privately-managed walled garden from the '90s!


## Authors
- [@lighth7015](https://www.github.com/lighth7015)

## Features
- Modular server interface, enabling the serving of several client versions at once

## TODO
- System Service Manager (e.g., systemd, FreeBSD rc.d, upstart)
- AOL client 3.x compatibility
- AOL client 4.x compatibility

## Contributing

Contributions are always welcome!

See `contributing.md` for ways to get started.

Please adhere to this project's `code of conduct`.


# Acknowledgements, Sources and Thanks
## Acknowledgements
 - [ReAOL- go support them!]()

## Sources, fro which I'd never get around to writing this
 - [AOL-Files.com](https://mattmazur.com/category/aol-files/)
 - [Chfoo's "notaol" repository](https://github.com/chfoo/notaol)
 - [Archiveteam's AOL pages](https://wiki.archiveteam.org/index.php/AOL#Form_Definition_Operator_/_Form_Display_Operation_(FDO91_or_FDO))
 - [FDO91 For Beginners](http://web.archive.org/web/20020205182212/http://www.aol-files.com/fdo91/index.html)

## Thank you
*To anyone and everyone who contributes to this project!*
## Roadmap

- Design and implement client 3.x protocol
  * Initial Connection State (ICS) Engine
  * Protocol/Connection Handler for Client 3.x Protocol

- Design and implement client 4.x protocol:
  * Initial Connection State (ICS) Engine
  * Protocol/Connection Handler for Client 4.x Protocol

- Design and implement FDO rendering engine
  * FdoClientSurface
  * Fdo*Control (e.g., FdoTextControl, FdoButtonControl)
  * FDO Scripting Engine
  * FDO Forms Rendering Engine

- Services/Tool Registry: A place to store configuration for server-side tools
- Content database: A centralized place to store FDO forms

## Possible Expansion

- Implement _Mirabillis&reg; ICQ_ protocol support?
- Pidgin TOC/OSCAR support?
- Module loader? (for modularizing scripting/FDO forms)
