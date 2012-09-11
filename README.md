# Universal Controller Converter (UCC)

## About

**UCC** is an Arduino-based retro game controller converter.

The purpose of the project is to read the native output from retro game controllers (such as NES, SNES, and Genesis) and convert that output to button presses that can be used as an integrated USB game controller or alternatively, wired to an external controller (like Xbox 360).


## Wiring

### Connecting a retro controller

Each controller that can be connected provides a set of 12 common input wires. The amount of wires that are used for reading the controller varies depending on the controller (7 for NES or SNES, 9 for Genesis). Any pins that aren't used for data get used for identifying which system the controller belongs to.

Generally, an adapter cable should be made to route the native controller wires to a common 12-pin connector.


## Supported systems

#### Supported
- _None_

#### In Progress
- NES + Power Pad

#### Future
- SNES
- Genesis
- Cobalt Flux (DDR)

#### Reference
- [Gaming pinouts](http://pinouts.ru/Game/)
- [NES pinout](http://wiki.nesdev.com/w/index.php/Standard_controller)
- [NES: Power Pad overview](http://wiki.nesdev.com/w/index.php/Power_Pad)
- [NES: Power Pad detailed info](http://nesdev.com/powerpad.txt)
- [SNES pinout](http://pinouts.ru/Game/snescontroller_pinout.shtml)

## Copyright

Copyright © 2012 Andy Kant. See LICENSE for details.