# antikeimena
Autonomous Robot

## Compile hex file
Use the docker image
   ```bash
docker run -it --rm -v ${PWD}:/host ansi/antikeimena
cd /host/sisyphus/scripts
./build_arduino_firmware.sh
```

## Upload hex file to arduino from desktop
```bash
platformio run --target upload
```
or
```bash
/Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega2560 -cwiring -P/dev/cu.wchusbserial1410 -b115200 -D -Uflash:w:/Users/ansi/development/antikeimena/arduino/firmware/sisyphus.hex:i
```

## Upload hex file to arduino from raspi
```bash
cd /host/sisyphus/scripts
check_and_update_arduino.sh
```

## IP setup
antikeimena.onthewifi.com
