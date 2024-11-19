# Weather Station

## Introduction
The purpose of this project was to make a weather station (Figure 1), which will read and send the measurements to a server.

![kuva](https://github.com/user-attachments/assets/366bfe75-2a3b-430f-b9d2-ed4753e13c82 "Figure 1: Weather station")

## Objectives
The basic aim was to make a functional weather station, which would send the data to a server, that could then be read from a computer.
Our secondary aim was to make the weather station rechargeable, using a LiFePO4 battery (Figure 2). Using a battery to power the station allows it to work without being connected to a computer or a power outlet.

![kuva](https://github.com/user-attachments/assets/4bbedb08-86ff-4444-b481-dccd094d78ef "Figure 2: LiFePO4 battery")


## Methods
The microcontroller we used in the project was ESP32-WROOM-32E (Figure 3). The microcontroller has built-in Wi-Fi that allows it to send the data to a server. There are two sensors which measure the temperature, humidity and air pressure.

![kuva](https://github.com/user-attachments/assets/56ac4c72-d674-4552-a20c-27fbb3ae43b8 "Figure 3: ESP32-WROOM-32E")

## Results
We achieved our primary goal of gathering and tranfering data (via Wi-Fi) from the stations sensors to a server, wherefrom it can be viewed through a web browser. We also partially achieved our secondary goal of powering the device with a rechargeable battery, however due to an error in the pcb design phase we were unable to get the recharging feature of the charging circuit functional.

## Refrences
ESP-32WROOM-32E datasheet Source:

esp32-wroom-32e_esp32-wroom-32ue_datasheet_en.pdf ([espressif.com](https://www.espressif.com/en/support/documents/technical-documents))
