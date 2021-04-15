# Hacker HotKey Advanced Firmware
```
  /**********************************************************
  *    _______ _______ _______ _______ _______ _______      *
  *   | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ |     *
  *   | | H | | | A | | | C | | | K | | | E | | | R | |     *
  *   | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ |     *
  *   |/_____\|/_____\|/_____\|/_____\|/_____\|/_____\|     *
  *       _______ _______ _______ _______ _______ _______   *
  *      | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ |  *
  *      | | H | | | O | | | T | | | K | | | E | | | Y | |  *
  *      | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ |  *
  *      |/_____\|/_____\|/_____\|/_____\|/_____\|/_____\|  *
  *                                                         *
  **********************************************************/
```
This guide is intended to help you set up hotkeys using the Hacker Hotkey Advanced Firmware
Details are also included in the hackerhotkey-adv.ino file
You will need to download all three files (hackerhotkey-adv.ino, FingerprintUSBHost.h, and FingerprintUSBHost.cpp) and include them in a hackerhotkey-adv folder to successfully compile.  Alternatively the FingerprintUSBHost Library can be downloaded and installed as a library from https://github.com/keyboardio/FingerprintUSBHost

## Host OS Detection

Hacker Hotkey attempts to determine the Host OS by using the FingerPrintUSBHost Library.
If you want to force Hacker Hotkey to act as if it's connected to a specific OS, set it in this ection
Valid options are "Windows", "MacOS", "Linux", "Other". 
```c 
Example: String OS = "Linux"; 
```
Otherwise, for auto-detection leave it blank.

You may also use the global variable ```OS``` within your hotkey definitions.

You can also dynamically set the HostOS at boot time by holding down one of the top 4 keys when the device powers on.
[1] = Windows, [2] = MacOS, [3] = Linux, [4] = Other

## Hotkey Setup
Use this section to define your hotkeys.  You will want to remove the existing hotkeys that are in the code and replace them with your own.
Use the Hotkey Formatting Guide below as a refernece

# Hotkey Formatting Guide
Each Hotkey is defined as a String Array.  There are a few primary parts of this array:
```c
String key1[] = {"[mods go between brackets]text comes after","additional actions come next"};
       ^ Key Num   ^ Modifier Keys          ^ Hotkey Text      ^ up to 9 actions can be performed
```

## Simple Examples
```c
String key1[] = {"You pressed the first top row key!"}; //types the line of text shown
String key2[] = {"You pressed the second top row key!"};
String key3[] = {"You pressed the third top row key!\xB0"}; //types the line of text shown and then Enter
String key4[] = {"You pressed the fourth top key!\xB0"};
String key5[] = {"[^]z"}; // This presses Control-z (undo on windows)
String key6[] = {"[^]c"}; // This presses Control-c (copy on windows)
String key7[] = {"[^+]v"}; // This presses Control-Shift-v (paste without formatting in some apps)
String key8[] = {"[^]c","[1000]","[^]v"}; // This copies, waits for one second, and then pastes. 
```
## Modifier Keys
Modifier keys will remain pressed until all other keys are pressed and released.
You enable them by placing them within square brackets at the beginning of your string
Modifier Keys are not required, if left off your text will be written normally.
Spaces are allowed between Modifier Keys for clarity.

```c
Example: "[^!]HACK" would type [Control Key]+[Alt Key]+HACK - release
```

Shortcuts have been made for these Modifier Keys to make writing hotkeys simpler:

```
   # = LEFT_GUI = Left Windows Key / GUI Key (Linux) / Command Key (Mac)
   ^ = LEFT_CTRL = Left Control Key
   ! = LEFT_ALT = Left Alt Key / Option Key (Mac)
   + = LEFT_SHIFT = Left Shift Key
   ```

Please note:  If you use uppercase letters/symbols the hotkey will push shift also, so
```[^]c``` and ```[^]C``` act differently.  The first acts as Control+c and the second acts as Control+Shift+c

Additionally, all modifier keys supported by Arduino can be used when added as such:

```sh
LEFT_CTRL           BACKSPACE           F1_  <-- note the underscore
LEFT_SHIFT          TAB                 F2
LEFT_ALT            RETURN              F3
LEFT_GUI            ESC                 F4
RIGHT_CTRL          INSERT              F5
RIGHT_SHIFT         DELETE              F6
RIGHT_ALT           PAGE_UP             F7
RIGHT_GUI           PAGE_DOWN           F8
UP_ARROW            HOME                F9
DOWN_ARROW          END                 F10
LEFT_ARROW          CAPS_LOCK           F11
RIGHT_ARROW                             F12

Example: "[RIGHT_SHIFT F12]" would press Shift+F12 and no additional text.
```

## Delay

You can enter a delay in the Modifier Keys brackets in order to delay prior to typing text.
The delay may be combined with Modifier Keys, but will be executed after any modifier keys are pressed.
```c
Example: "[300]THE PLANET" would delay for 300ms and then type "THE PLANET".
```

## Payload

Sometimes you need to execute custom code, or have a large payload that you need to dump for... reasons.
As outlined in the Memory Management section below this is difficult to include in a hotkey, so there
is a special modifier that will trigger a payload.

The formatting of this is ```"[payload]#"``` where # is the number of the payload you would like to trigger.
```c
Example  String key8[] = {"[payload]0"};
```
**Payloads cannot be combined with any other modifier keys**

Define payloads in the definePayload function.  See the code for an example.

Wrap large strings in the ```F()``` macro so you have enough RAM. (See Memory Considerations below)
Keep a ```delay(200);``` at the end or your button press will trigger multiple times.
Feel free to do whatever you want here, this is where you can trigger custom code


## Hotkey Text

Hotkey Text is any text added after the Modifier Keys brackets.  This text is typed as written, with the
exception of the Special Hotkey Text section below.

## Special Hotkey Text (escape codes)

These keys work outside of the modifier field.  Below is a chart with hex escape sequences
for inserting them into your hotkey.  Other characters may work also but are untested.
See: https://en.m.wikipedia.org/wiki/Escape_sequences_in_C
```c
Example  "hi\xB3mom" would type "hi[tab]mom" or, "\xC2" would press the F1 button.  
```

```
Key          Escape value                Key          Escape value
-------------------------                -------------------------
LEFT_CTRL    \x80                        PAGE_UP      \xD3
LEFT_SHIFT   \x81                        PAGE_DOWN    \xD6
LEFT_ALT     \x82                        HOME         \xD2
LEFT_GUI     \x83                        END          \xD5
RIGHT_CTRL   \x84                        CAPS_LOCK    \xC1
RIGHT_SHIFT  \x85                        F1           \xC2
RIGHT_ALT    \x86                        F2           \xC3
RIGHT_GUI    \x87                        F3           \xC4
UP_ARROW     \xDA                        F4           \xC5
DOWN_ARROW   \xD9                        F5           \xC6
LEFT_ARROW   \xD8                        F6           \xC7
RIGHT_ARROW  \xD7                        F7           \xC8
BACKSPACE    \xB2     \b                 F8           \xC9
TAB          \xB3     \t                 F9           \xCA
RETURN       \xB0     \n                 F10          \xCB
ESC          \xB1                        F11          \xCC     
INSERT       \xD1                        F12          \xCD
DELETE       \xD4
```

## Functions
Functions may be used within your hotkeys, and this can provide additonal capabilities.  Currently functions are
called when the hotkey is defined, not at each button press. A function must return a String value that can be
inserted into the hotkey.  The string may contain Modifier Keys and Hotkey Text.

One function is provided in this code: osCondition()

The Hacker Hotkey attempts to identify the host OS it is connected to when plugged in.  osCondition alows you to
return different text based on which OS it is connected to.  This is not foolproof, the code might mis-identify
your OS, so use with caution.  The Hack Hotkey also will most likely not be able to identify a host within a VM.
The code also does not properly identify mobile OS', and may identify them as Mac, Linux or unsure.
```c
Usage: osCondition("Windows Value","MacOS Value","Linux Value","Unsure");

Example: 

String key5[] = {
         "I love using my hacker hotkey on "+OS+"\n",
         osCondition("yay Bill Gates!\n","yay Steve Jobs!\n","yay Linus Torvalds!\n","yay!\n")
};

```
Always include each argument even if it is a blank string ("");

## Additional Actions
You may have noticed that some of the default hotkeys are very long, that's because each hotkey supports
up to nine actions per key.  Each of these actions support all the modifiers, hotkey text and functions
outlined above.  You simply add them to the array when defining it.  This allows you to add delays
between actions, differnet modifier keys for different actions, and so on.
```c
Example: {"action one","action two","[+]action three with a modifier"}
```
## Memory Considerations

The ATMega32u4 has 32KB of program memory, and 2560B of SRAM.  This makes the Hacker Hotkey ideal
for a number of small hotkey actions, but it can be a challege when attemping to create hotkeys
that has a large number of actions, or use long strings of text.

One way to combat this is to keep long strings of text out of SRAM until absolutely needed.  When
defining your hotkeys, you can wrap the string in the F() macro.  This stores your string in
program memory until needed.
```c
   Example: String key1[] = {F("This string is stored in the 2560B of SRAM")}; //not wrapped with F()
   vs.     String key1[] = {F("This saves some SRAM in favor of Program Memory")}; //wrapped with F()
```
What this will not allow is using extremely large strings of text, such as the first page of the
Digital Millenium Copyright Act in a macro.  It will still overwhelm the SRAM when processed and
your hotkey will fail quietly, or do weird and funky stuff.

If you can rewrite this mess to be more efficient, please submit a pull request.   

## Debug Serial Monitoring
Uncomment the ```#define DEBUG``` line to enable debug printouts via the serial monitor