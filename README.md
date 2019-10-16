# USB 2.0 HID stack on stm32f407
##  overview

### Spec :
https://www.usb.org/sites/default/files/usb_20_20190524.zip
[USB PROTOCOLs](https://beyondlogic.org/usbnutshell/usb1.shtml)

### Dev Kit : 

[stm32f407_discovery](https://www.st.com/content/ccc/resource/technical/document/user_manual/70/fe/4a/3f/e7/e1/4f/7d/DM00039084.pdf/files/DM00039084.pdf/jcr:content/translations/en.DM00039084.pdf)
[stm32f407VG](https://www.st.com/content/st_com/en/products/microcontrollers-microprocessors/stm32-32-bit-arm-cortex-mcus/stm32-high-performance-mcus/stm32f4-series/stm32f407-417/stm32f407vg.html)

### Toolchain :
[Gnu Arm embedded toolchain](https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm/downloads)
[Zadig USB DRIVE](https://zadig.akeo.ie/)
[STlink Driver](https://www.st.com/en/development-tools/stsw-link009.html)

### Programer and Debugger :
[OpenOCD Tutorial](https://ithelp.ithome.com.tw/articles/10192744)
[OpenOCD 4 Windows](https://gnutoolchains.com/arm-eabi/openocd/)

### Repo : 

[GitURL](https://github.com/a910184/JFF.git)

### before main() :need review 

[build code reference]
(https://github.com/jserv/mini-arm-os)
底層的C語言世界
https://ccckmit.gitbooks.io/lowlevelc/content/io.html
### uart_debug (eznob ongoing)


## Openocd / Telnet / GDB
### Openocd
載入寫好之cfg File
```
openocd -f ./xxx.cfg
```
![cfg file](https://i.imgur.com/8K05Cfa.jpg)

載入完成後會告知當前晶片型號、Debug接口類型與GDB/Telnet Port Number

![openocd inform.](https://i.imgur.com/vSfY5C8.jpg)
### Telnet
接著必須維持此CMD開啟，並開一新CMD連上TelnetServer(Port 4444)
之後可輸入help、targets等指令觀察晶片狀態，輸入exit即結束
```
telnet localhost 4444
```
成功連上會顯示Open On-Chip Debugger
![telnet server](https://i.imgur.com/ZHNpbdG.jpg)
```
targets
```
顯示當前狀態
![targets](https://i.imgur.com/Vde4t6n.jpg)
### GDB
輸入arm-none-eabi-gdb會顯示版本號等資訊
```
arm-none-eabi-gdb
```
![GDB infrom.](https://i.imgur.com/3UPpkBW.jpg)
接著連上GDB Srver、成功會顯示當前記憶體位置
```
target remote :3333
```
![gdb server](https://i.imgur.com/O6EiErU.jpg)
欲使用Openocd指令須加上monitor關鍵字
```
monitor targets
```
![monitor targets](https://i.imgur.com/ZWEEcvz.jpg)
之後可開始載入檔案(elf、bin)
```
file ./xxx.elf (開檔 類似 C FILE)
monitor reset 
monitor halt
monitor load (下載程式至Flash)
```

