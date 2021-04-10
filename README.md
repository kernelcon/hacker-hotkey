# Hacker HotKey
This repos contains example software for the [Kernelcon](https://kernelcon.org/) 2021 Hack Live! badge - the Hacker HotKey.

[![hacker hotkey hotkey image](./hackerhotkey-sm-white.png)](https://kernelcon.square.site/)

## Compiling and uploading firmware

1. connect micro USB cable  
   * needs to be a data cable, not just a charging/power cable
2. open aduino IDE  
   * install if necessary 
       * https://www.arduino.cc/en/Guide
   * install keyboard library if necessary:
       * tools -> Manage Libraries -> search "keyboard" -> install
   ```sh
    arduino hackerHotKey.ino
   ```
3. select "Arduino Leonardo" board type
   * install Arduino boards if necessary:
      * tools -> Boards Manager -> search "Arduino AVR Boards" -> install 
4. select com port
   * tools -> port
5. Verify port comms work
   * tools -> "Get Board Info"
   * should return something like
      ```sh
      BN: Arduino Leonardo
      VID: 0x2341
      PID: 0x8036
      SN: Upload any sketch to obtain it
      ```
5. upload code
   * sketch -> upload
   * Arduino IDE will compile and upload firmware to the Hacker Hotkey, which you can use immediately after upload (no unplugging, reseting, etc required)


