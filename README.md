
# QMK firmware for business-card-keyboard

## Install

```
$ git clone https://github.com/qmk/qmk_firmware.git
$ cd qmk_firmware
$ make git-submodule
$ git submodule add https://github.com/yskoht/business-card-keyboard.git keyboards/business_card_keyboard
```

## Usage

```
$ make business_card_keyboard:rev1
$ make business_card_keyboard:rev1:avrdude
```

