cd C:/openocd-20190828/OpenOCD-20190828-0.10.0  REM should change this path to your openocd location 
./bin/openocd.exe -f "./share/openocd/scripts/interface/stlink.cfg" -f"./share/openocd/scripts/target/stm32f4x_stlink.cfg"
