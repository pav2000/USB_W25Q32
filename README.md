# USB_W25Q32
Example USB Mass Storage Device Class stm32f103 + w25q32 <br>
<br>
An example Mass Storage Device Class to stm32f103.
SPI flash memory chip w25q32 with a capacity of 4 MB is used as storage.
When the board is connected to the computer via USB, a flash drive appears on it.
<img src="https://github.com/pav2000/USB_W25Q32/blob/main/Picture/001.jpg" width="480"/> <br>
As an example, the developer board described here is used: https://github.com/pav2000/DevBoardSTM32F103CBT<br>
<img src="https://github.com/pav2000/USB_W25Q32/blob/main/Picture/002.jpg" width="480"/> <br>
The function of the device is as follows.
Device is plugged into USB on a computer.
Device identifies as a MASS STORAGE DEVICE.
Files can be created by the device that the computer can read.
Files can be placed onto the drive that the device can read. A config file for example.
<br>
