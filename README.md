
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

## Fix me

For master.
```diff
diff --git a/split_util.c b/split_util.c
index 9d0f647..e3a4673 100644
--- a/split_util.c
+++ b/split_util.c
@@ -49,10 +49,10 @@ static void keyboard_slave_setup(void) {
 }

 bool has_usb(void) {
+   // USBCON |= (1 << OTGPADE); //enables VBUS pad
+   // _delay_us(5);
+   // return (USBSTA & (1<<VBUS));  //checks state of VBUS
+   return 1;
 }
```

For slave.
```diff
diff --git a/split_util.c b/split_util.c
index 9d0f647..e3a4673 100644
--- a/split_util.c
+++ b/split_util.c
@@ -49,10 +49,10 @@ static void keyboard_slave_setup(void) {
 }

 bool has_usb(void) {
+   // USBCON |= (1 << OTGPADE); //enables VBUS pad
+   // _delay_us(5);
+   // return (USBSTA & (1<<VBUS));  //checks state of VBUS
+   return 0;
 }
```

