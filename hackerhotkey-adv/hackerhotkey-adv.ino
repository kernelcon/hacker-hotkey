
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

  //***  Hacker HotKey advanced firmware ***//
   /*   
   *  Copyright 2021 Kernelcon
   *  SPDX-License-Identifier: Apache-2.0
   *   
   */

  //** Host OS Detection **//
  /*
     Hacker Hotkey attempts to determine the Host OS by using the FingerPrintUSBHost Library.
     If you want to force Hacker Hotkey to act as if it's connected to a specific OS, set it here.  
     Valid options are "Windows", "MacOS", "Linux", "Other". Example:  String OS = "Linux";
     Otherwise, for auto-detection leave it blank.

     You may also use the global varialbe "OS" within your hotkey definitions.
  */

String OS = ""; 
     
   /*
     You can also dynamically set the HostOS at boot time by holding down one of the top 4 keys when the device powers on.
     [1] = Windows, [2] = MacOS, [3] = Linux, [4] = Other
   */   

  //** HOTKEY SETUP **//
  /* Define your hotkeys below.  Use the Hotkey Formatting Guide as a reference. */

void defineHotkeys() {

  //**These are the default hotkeys, and may be a bit complicated for noobs.  Read reference beow. **//
  
  String key1[] = { //This is the first key, top left.
                    osCondition("[#]r", "[#] ", F("[!]\xC3"), ""),  //send a keystroke to open a run dialog (varies per OS, Win+r, Command+Space, Alt+F2)
                    osCondition("", "", F("[100]xdg-open "), ""),   //if it's Linux, delays 100ms and types xdg-open
                    F("https://kernelcon.org"),                     //Types this URL
                    F("[250]\n")                                    //Delays 250ms and hits return
                  };                                                //Note: The F() macro around strings saves ram, see Memory Considerations section.

  String key2[] = {   
                    osCondition("[#]r", "[#] ", F("[!]\xC3"), ""),
                    osCondition("", "", F("[100]xdg-open "), ""),
                    F("https://twitch.kernelcon.org"),
                    F("[250]\n")
                  };
                  
  String key3[] = { 
                    osCondition("[#]r", "[#] ", F("[!]\xC3"), ""),
                    osCondition("", "", F("[100]xdg-open "), ""),
                    F("https://discord.kernelcon.org"),
                    F("[250]\n")
                  };
  String key4[] = {
                    osCondition("[#]r", "[#] ", F("[!]\xC3"), ""),
                    osCondition("", "", F("[100]xdg-open "), ""),
                    F("http://github.com/kernelcon/hacker-hotkey"),
                    F("[250]\n")
                  };
                    
  String key5[] = {F("!vote 4\n")}; //sends the text !vote 4 and then hits return
  String key6[] = {F("!vote 3\n")};
  String key7[] = {F("!vote 2\n")};
  String key8[] = {F("!vote 1\n")};

  //****** HOTKEY FORMATTING GUIDE *******//
  /*
     Each Hotkey is defined as a String Array.  There are a few primary parts of this array:
     
       _________________________________________________________________________________________________
      | String key1[] = {"[mods go between brackets]text comes after","additional actions come next"};  |
      '-------------------------------------------------------------------------------------------------'     
               ^ Key Num   ^ Modifier Keys          ^ Hotkey Text      ^ up to 9 actions can be performed
     
   */
  //** Simple Examples **//
  /*
     String key1[] = {"You pressed the first top row key!"}; //types the line of text shown
     String key2[] = {"You pressed the second top row key!"};
     String key3[] = {"You pressed the third top row key!\xB0"}; //types the line of text shown and then Enter
     String key4[] = {"You pressed the fourth top key!\xB0"};
     String key5[] = {"[^]z"}; // This presses Control-z (undo on windows)
     String key6[] = {"[^]c"}; // This presses Control-c (copy on windows)
     String key7[] = {"[^+]v"}; // This presses Control-Shift-v (paste without formatting in some apps)
     String key8[] = {"[^]c","[1000]","[^]v"}; // This copies, waits for one second, and then pastes.  
   */

  //** Modifier Keys **//
  /*
     Modifier keys will remain pressed until all other keys are pressed and released.
     You enable them by placing them within square brackets at the beginning of your string
     Modifier Keys are not required, if left off your text will be written normally.
     Spaces are allowed between Modifier Keys for clarity.
     
     Example: "[^!]HACK" would type [Control Key]+[Alt Key]+HACK - release

     Shortcuts have been made for these Modifier Keys to make writing hotkeys simpler:

        # = LEFT_GUI = Left Windows Key / GUI Key (Linux) / Command Key (Mac)
        ^ = LEFT_CTRL = Left Control Key
        ! = LEFT_ALT = Left Alt Key / Option Key (Mac)
        + = LEFT_SHIFT = Left Shift Key

     Please note:  If you use uppercase letters/symbols the hotkey will push shift also, so
     [^]c and [^]C act differently.  The first acts as Control+c and the second acts as Control+Shift+c

     Additionally, all modifier keys supported by Arduino can be used when added as such:
    
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
  
  */
  
  //** Delay **//
  /*
     You can enter a delay in the Modifier Keys brackets in order to delay prior to typing text.
     The delay may be combined with Modifier Keys, but will be executed after any modifier keys are pressed.
     Example: "[300]THE PLANET" would delay for 300ms and then type "THE PLANET".
     
  */

  //** Payload **//
  /*
     Sometimes you need to execute custom code, or have a large payload that you need to dump for... reasons.
     As outlined in the Memory Management section below this is difficult to include in a hotkey, so there
     is a special modifier that will trigger a payload.

     The formatting of this is "[payload]#" where # is the number of the payload you would like to trigger.
     
     ** Payloads cannot be combined with any other modifier keys **

     Define payloads in the definePayload function at the end of this guide.   

    
   */
  //** Hotkey Text **//
  /*
     Hotkey Text is any text added after the Modifier Keys brackets.  This text is typed as written, with the
     exception of the Special Hotkey Text section below.
  */
  
  //** Special Hotkey Text **//
  /*
     These keys work outside of the modifier field.  Below is a chart with hex escape sequences
     for inserting them into your hotkey.  Other characters may work also but are untested.
     See: https://en.m.wikipedia.org/wiki/Escape_sequences_in_C
     For example  "hi\xB3mom" would type "hi[tab]mom" or, "\xC2" would press the F1 button.  

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
  */

  //** Functions **//
  /*
     Functions may be used within your hotkeys, and this can provide additonal capabilities.  Currently functions are
     called when the hotkey is defined, not at each button press. A function must return a String value that can be
     inserted into the hotkey.  The string may contain Modifier Keys and Hotkey Text.

     One function is provided in this code: osCondition()

     The Hacker Hotkey attempts to identify the host OS it is connected to when plugged in.  osCondition alows you to
     return different text based on which OS it is connected to.  This is not foolproof, the code might mis-identify
     your OS, so use with caution.  The Hack Hotkey also will most likely not be able to identify a host within a VM.
     The code also does not properly identify mobile OS', and may identify them as Mac, Linux or unsure.

     Usage: osCondition("Windows Value","MacOS Value","Linux Value","Unsure")

     Example: 
       String key5[] = {
                  "I love using my hacker hotkey on "+OS+"\n",
                  osCondition("yay bill gates!\n","yay Steve Jobs!\n","yay Linus Torvalds!\n","yay!\n")
       };

     Always include each argument even if it is a blank string ("");
   
   */

  //** Additional Actions **//
  /*
     You may have noticed that some of the default hotkeys are very long, that's because each hotkey supports
     up to nine actions per key.  Each of these actions support all the modifiers, hotkey text and functions
     outlined above.  You simply add them to the array when defining it.  This allows you to add delays
     between actions, differnet modifier keys for different actions, and so on.

     Example: {"action one","action two","[+]action three with a modifier"}
   */

  //** Memory Considerations **//
  /*
     The ATMega32u4 has 32KB of program memory, and 2560B of SRAM.  This makes the Hacker Hotkey ideal
     for a number of small hotkey actions, but it can be a challege when attemping to create hotkeys
     that has a large number of actions, or use long strings of text.

     One way to combat this is to keep long strings of text out of SRAM until absolutely needed.  When
     defining your hotkeys, you can wrap the string in the F() macro.  This stores your string in
     program memory until needed.

       Example: String key1[] = {"This string is stored in the 2560B of SRAM"}; //not wrapped with F()
        vs.     String key1[] = {F("This saves some SRAM in favor of Program Memory")}; //wrapped with F()

    What this will not allow is using extremely large strings of text, such as the first page of the
    Digital Millenium Copyright Act in a macro.  It will still overwhelm the SRAM when processed and
    your hotkey will fail quietly, or do weird and funky stuff.

    If you can rewrite this mess to be more efficient, please submit a pull request.       
   */


  //PAY NO ATTENTION TO THE MAN BEHIND THE CURTAIN//
  /* This is setting up the hotkeys, and could probably be simplified if I knew how to code
     You can safely ignore this section.  */
  hkey(0, key1, sizeof(key1) / sizeof(key1[0]));
  hkey(1, key2, sizeof(key2) / sizeof(key2[0]));
  hkey(2, key3, sizeof(key3) / sizeof(key3[0]));
  hkey(3, key4, sizeof(key4) / sizeof(key4[0]));
  hkey(4, key5, sizeof(key5) / sizeof(key5[0]));
  hkey(5, key6, sizeof(key6) / sizeof(key6[0]));
  hkey(6, key7, sizeof(key7) / sizeof(key7[0]));
  hkey(7, key8, sizeof(key8) / sizeof(key8[0]));
} //end of defineHotkeys function

  //** Define Payloads here **//
  /* Remember to wrap large strings in the F() macro so you have enough RAM.
     Keep a delay(200); at the end or your button press will trigger multiple times
     Feel free to do whatever you want here, this is where you can trigger custom code */

void definePayload(int num) {
    switch (num) {
/*      case 1: // Trigger #
        //This trigger types the first page of the DMCA (because that is a useful feature) and then delays for 200 seconds.
        Keyboard.print(F("INTRODUCTION\n"
        "The Digital Millennium Copyright Act (DMCA)1 was signed into law by President Clinton on October 28, 1998. The legislation implements two 1996 World Intellectual Property Organization (WIPO) treaties: the WIPO Copyright Treaty and the WIPO Performances and Phonograms Treaty. The DMCA also addresses a number of other significant copyright-related issues.\n"
        "The DMCA is divided into five titles:\n"
        " - Title I, the \"WIPO Copyright and Performances and Phonograms Treaties Implementation Act of 1998,\" implements the WIPO treaties.\n"
        " - Title II, the \"Online Copyright Infringement Liability Limitation Act,\" creates limitations on the liability of online service providers for copyright infringement when engaging in certain types of activities.\n"
        " - Title III, the \"Computer Maintenance Competition Assurance Act,\" creates an exemption for making a copy of a computer program by activating a computer for purposes of maintenance or repair.\n"
        " - Title IV contains six miscellaneous provisions, relating to the functions of the Copyright Office, distance education, the exceptions in the Copyright Act for libraries and for making ephemeral recordings, \"webcasting\" of sound recordings on the Internet, and the applicability of collective bargaining agreement obligations in the case of transfers of rights in motion pictures.\n"
        " - Title V, the \"Vessel Hull Design Protection Act,\" creates a new form of protection for the design of vessel hulls.\n"
        "This memorandum summarizes briefly each title of the DMCA. It provides merely an overview of the law's provisions; for purposes of length and readability a significant amount of detail has been omitted. A complete understanding of any provision of the DMCA requires reference to the text of the legislation itself."));
        delay(200); //delay to avoid bounces
      break; // break at the end
*/
    }
}

  //** Serial Monitoring **//
  /* Uncomment this line if you want to print debug text over the serial monitor */

 //#define DEBUG

//************ THE END, or the beginning if you're a hacker ************************//
/* you do not need to modify anything below here */


#ifdef DEBUG
  #define DEBUG_PRINT(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
#endif

//FingerprintUSBHost library (c) Jesse Vincent sourced from https://github.com/keyboardio/FingerprintUSBHost

#include "FingerprintUSBHost.h"
#include <Keyboard.h>
#include <avr/pgmspace.h>

//prep some globals
const String hotkeys[8][10];

// set pin numbers for the buttons
#define BTN1  13
#define BTN2  5
#define BTN3  10
#define BTN4  9
#define BTN5  8
#define BTN6  6
#define BTN7  12
#define BTN8  4

//this function returns a string based on what OS we're connected to
String osCondition(String win, String mac, String nix, String oth) {
  if (OS == "MacOS") {
    return mac;
  } else if (OS == "Windows") {
    return win;
  } else if (OS == "Linux") {
    return nix;
  } else {
    return oth;
  }
}

//this function inserts up to 9 strings into each hotkey. 
void hkey(int keynum, String vals[], int arraySize) {

  if (arraySize > 9) { //9 is an artificial limit because I don't know how to code.
    arraySize = 9;
  }

  hotkeys[keynum][0] = arraySize;  //First value is the size of the array because sizeof and scope is confusing.

  //not being able to use curly brackets to update an array is stupid
  for (int i = 0; i < arraySize; i++) {
    hotkeys[keynum][i + 1] = vals[i];
  }
}

//function to tell us if a string is a whole number.  used by text parser
void checkDelay(String myStr) {

        myStr.replace(F(" "),"");
        myStr.replace(F("#"),"");
        myStr.replace(F("LEFT_GUI"),"");
        myStr.replace(F("^"),"");
        myStr.replace(F("LEFT_CTRL"),"");
        myStr.replace(F("!"),"");
        myStr.replace(F("LEFT_ALT"),"");
        myStr.replace(F("+"),"");        
        myStr.replace(F("LEFT_SHIFT"),"");
        myStr.replace(F("RIGHT_CTRL"),"");
        myStr.replace(F("RIGHT_SHIFT"),"");
        myStr.replace(F("RIGHT_ALT"),"");
        myStr.replace(F("RIGHT_GUI"),"");
        myStr.replace(F("UP_ARROW"),"");
        myStr.replace(F("DOWN_ARROW"),"");
        myStr.replace(F("LEFT_ARROW"),"");
        myStr.replace(F("RIGHT_ARROW"),"");
        myStr.replace(F("BACKSPACE"),"");
        myStr.replace(F("TAB"),"");
        myStr.replace(F("RETURN"),"");
        myStr.replace(F("ESC"),"");
        myStr.replace(F("INSERT"),"");
        myStr.replace(F("DELETE"),"");
        myStr.replace(F("PAGE_UP"),"");
        myStr.replace(F("PAGE_DOWN"),"");
        myStr.replace(F("HOME"),"");
        myStr.replace(F("END"),"");
        myStr.replace(F("CAPS_LOCK"),"");
        myStr.replace(F("F1_"),"");
        myStr.replace(F("F2"),"");
        myStr.replace(F("F3"),"");
        myStr.replace(F("F4"),"");
        myStr.replace(F("F5"),"");
        myStr.replace(F("F6"),"");
        myStr.replace(F("F7"),"");
        myStr.replace(F("F8"),"");
        myStr.replace(F("F9"),"");
        myStr.replace(F("F10"),"");
        myStr.replace(F("F11"),"");
        myStr.replace(F("F12"),"");

  int num = 0;
  for (int i = 0; i < myStr.length(); i++) {
    if (myStr[i] >= '0' && myStr[i] <= '9') {
      num ++;
    }
  }
  if (num == myStr.length()) {
    delay(myStr.toInt());
    return;
  } else {
    return;
  }
}

//parses hotkey text when a button is pressed. 
bool processBtn(int keynum) {

  String mods;

  //iterates through the array of strings for this key
  for (int action = 1; action <= hotkeys[keynum][0].toInt(); action++) {
    if ((hotkeys[keynum])[action].length() > 0) { //check to make sure there actually is text & starts parsing

    if((hotkeys[keynum])[action].substring(0,9) == "[payload]") {
      definePayload((hotkeys[keynum])[action].substring(9).toInt());      
      break;
    } else {

      //check for modifiers.
      if (((hotkeys[keynum])[action].indexOf('[') == 0) && ((hotkeys[keynum])[action].indexOf(']') > 0)) {
        DEBUG_PRINT(F("Found Bracket, checking mods..."));

        mods = (hotkeys[keynum])[action].substring(1, (hotkeys[keynum])[action].indexOf(']'));
        
        DEBUG_PRINT(F("____Mods found____"));
        DEBUG_PRINT(mods);
    
          if ((mods.indexOf(F("#")) > -1) || (mods.indexOf(F("LEFT_GUI")) > -1)) {
            Keyboard.press(KEY_LEFT_GUI); //mod is win key
          }
          if ((mods.indexOf(F("^")) > -1) || (mods.indexOf(F("LEFT_CTRL")) > -1)) {
            Keyboard.press(KEY_LEFT_CTRL); //mod is control key
          }
          if ((mods.indexOf(F("!")) > -1) || (mods.indexOf(F("LEFT_ALT")) > -1)) {
            Keyboard.press(KEY_LEFT_ALT); //mod is alt key
          }
          if ((mods.indexOf(F("+")) > -1) || (mods.indexOf(F("LEFT_SHIFT")) > -1)) {
            Keyboard.press(KEY_LEFT_SHIFT); //mod is shift key
          }
          if (mods.indexOf(F("RIGHT_CTRL")) > -1) { 
            Keyboard.press(KEY_RIGHT_CTRL); 
          }
          if (mods.indexOf(F("RIGHT_SHIFT")) > -1) { 
            Keyboard.press(KEY_RIGHT_SHIFT); 
          }
          if (mods.indexOf(F("RIGHT_ALT")) > -1) { 
            Keyboard.press(KEY_RIGHT_ALT); 
          }
          if (mods.indexOf(F("RIGHT_GUI")) > -1) { 
            Keyboard.press(KEY_RIGHT_GUI); 
          }
          if (mods.indexOf(F("UP_ARROW")) > -1) { 
            Keyboard.press(KEY_UP_ARROW); 
          }
          if (mods.indexOf(F("DOWN_ARROW")) > -1) { 
            Keyboard.press(KEY_DOWN_ARROW); 
          }
          if (mods.indexOf(F("LEFT_ARROW")) > -1) { 
            Keyboard.press(KEY_LEFT_ARROW); 
          }
          if (mods.indexOf(F("RIGHT_ARROW")) > -1) { 
            Keyboard.press(KEY_RIGHT_ARROW); 
          }
          if (mods.indexOf(F("BACKSPACE")) > -1) { 
            Keyboard.press(KEY_BACKSPACE); 
          }
          if (mods.indexOf(F("TAB")) > -1) { 
            Keyboard.press(KEY_TAB); 
          }
          if (mods.indexOf(F("RETURN")) > -1) { 
            Keyboard.press(KEY_RETURN); 
          }
          if (mods.indexOf(F("ESC")) > -1) { 
            Keyboard.press(KEY_ESC); 
          }
          if (mods.indexOf(F("INSERT")) > -1) { 
            Keyboard.press(KEY_INSERT); 
          }
          if (mods.indexOf(F("DELETE")) > -1) { 
            Keyboard.press(KEY_DELETE); 
          }
          if (mods.indexOf(F("PAGE_UP")) > -1) { 
            Keyboard.press(KEY_PAGE_UP); 
          }
          if (mods.indexOf(F("PAGE_DOWN")) > -1) { 
            Keyboard.press(KEY_PAGE_DOWN); 
          }
          if (mods.indexOf(F("HOME")) > -1) { 
            Keyboard.press(KEY_HOME); 
          }
          if (mods.indexOf(F("END")) > -1) { 
            Keyboard.press(KEY_END); 
          }
          if (mods.indexOf(F("CAPS_LOCK")) > -1) { 
            Keyboard.press(KEY_CAPS_LOCK); 
          }
          if (mods.indexOf(F("F1_")) > -1) { 
            Keyboard.press(KEY_F1); 
          }
          if (mods.indexOf(F("F2")) > -1) { 
            Keyboard.press(KEY_F2); 
          }
          if (mods.indexOf(F("F3")) > -1) { 
            Keyboard.press(KEY_F3); 
          }
          if (mods.indexOf(F("F4")) > -1) { 
            Keyboard.press(KEY_F4); 
          }
          if (mods.indexOf(F("F5")) > -1) { 
            Keyboard.press(KEY_F5); 
          }
          if (mods.indexOf(F("F6")) > -1) { 
            Keyboard.press(KEY_F6); 
          }
          if (mods.indexOf(F("F7")) > -1) { 
            Keyboard.press(KEY_F7); 
          }
          if (mods.indexOf(F("F8")) > -1) { 
            Keyboard.press(KEY_F8); 
          }
          if (mods.indexOf(F("F9")) > -1) { 
            Keyboard.press(KEY_F9); 
          }
          if (mods.indexOf(F("F10")) > -1) { 
            Keyboard.press(KEY_F10); 
          }
          if (mods.indexOf(F("F11")) > -1) { 
            Keyboard.press(KEY_F11); 
          }
          if (mods.indexOf(F("F12")) > -1) { 
            Keyboard.press(KEY_F12); 
          }

        //check if there is a delay & execute it
        checkDelay(mods);    

    
        DEBUG_PRINT(F("____Hotkey text____"));

        DEBUG_PRINT((hotkeys[keynum])[action].substring((hotkeys[keynum])[action].indexOf(']') + 1));
    
        Keyboard.print((hotkeys[keynum])[action].substring((hotkeys[keynum])[action].indexOf(']') + 1)); //print all the text.
    
    
      } else {
        //no mods, lets just send the text.
        DEBUG_PRINT(F("____Hotkey text____"));
        DEBUG_PRINT((hotkeys[keynum])[action]);    
        Keyboard.print((hotkeys[keynum])[action]); //print all the text.
      }
      
      Keyboard.releaseAll(); //release any mod keys
      delay(200); //delay to avoid bounces
      }
    }
  }

}

void setup() { 
  
  // initialize the buttons' inputs:
  pinMode(BTN1, INPUT_PULLUP); // top 1
  pinMode(BTN2, INPUT_PULLUP); // top 2
  pinMode(BTN3, INPUT_PULLUP); // top 3
  pinMode(BTN4, INPUT_PULLUP); // top 4
  pinMode(BTN5, INPUT_PULLUP); // bottom 1
  pinMode(BTN6, INPUT_PULLUP); // bottom 2
  pinMode(BTN7, INPUT_PULLUP); // bottom 3
  pinMode(BTN8, INPUT_PULLUP); // bottom 4
  #ifdef DEBUG
    Serial.begin(9600); //initialize serial communication.  we put some debug in serial monitor
  #endif
  delay(3000); //Take a moment to let things settle

if (OS.length() == 0) {
  if ((digitalRead(BTN1) == LOW) || (digitalRead(BTN2) == LOW) || (digitalRead(BTN3) == LOW) || (digitalRead(BTN4) == LOW)) {
  
    while ((digitalRead(BTN1) == LOW) || (digitalRead(BTN2) == LOW) || (digitalRead(BTN3) == LOW) || (digitalRead(BTN4) == LOW)) {
    
      if (digitalRead(BTN1) == LOW) {
        DEBUG_PRINT(F("Bypassing OS Check, forcing OS to Windows"));
        OS = "Windows";
        delay(200);
      } else   if (digitalRead(BTN2) == LOW) {
        DEBUG_PRINT(F("Bypassing OS Check, forcing OS to MacOS"));
        OS = "MacOS";
        delay(200);
      } else   if (digitalRead(BTN3) == LOW) {
        DEBUG_PRINT(F("Bypassing OS Check, forcing OS to Linux"));
        OS = "Linux";
        delay(200);
      } else   if (digitalRead(BTN4) == LOW) {
        DEBUG_PRINT(F("Bypassing OS Check, forcing OS to Other"));
        OS = "unsure";
        delay(200);
      } 
  
    }
  } else {  
    FingerprintUSBHost.guessHostOS(OS);  //fingerprint device OS
  }
}
  DEBUG_PRINT(F("____Host OS____"));
  DEBUG_PRINT(OS); 

  defineHotkeys(); //call that function where you defined the hotkeys
  
  Keyboard.begin(); //support keyboard presses
}

void loop() {
https://kernelcon.org

  // use the pushbuttons to control the keyboard
  if (digitalRead(BTN1) == LOW) {
    DEBUG_PRINT(F("Button 1 Pressed"));
    processBtn(0);
  }
  if (digitalRead(BTN2) == LOW) {
    DEBUG_PRINT(F("Button 2 Pressed"));
    processBtn(1);
  }
  if (digitalRead(BTN3) == LOW) {
    DEBUG_PRINT(F("Button 3 Pressed"));
    processBtn(2);
  }
  if (digitalRead(BTN4) == LOW) {
    DEBUG_PRINT(F("Button 4 Pressed"));
    processBtn(3);
  }
  if (digitalRead(BTN5) == LOW) {
    DEBUG_PRINT(F("Button 5 Pressed"));
    processBtn(4);
  }
  if (digitalRead(BTN6) == LOW) {
    DEBUG_PRINT(F("Button 6 Pressed"));
    processBtn(5);
  }
  if (digitalRead(BTN7) == LOW) {
    DEBUG_PRINT(F("Button 7 Pressed"));
    processBtn(6);
  }
  if (digitalRead(BTN8) == LOW) {
    DEBUG_PRINT(F("Button 8 Pressed"));
    processBtn(7);
  }

}
