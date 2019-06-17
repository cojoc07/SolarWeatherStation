# Solar Weather Station

The weather station is based on the WeMos D1 mini pro. The WeMos D1 mini PRO is a miniature wireless 802.11 (Wifi) microcontroller development board, based on the popular ESP8266. It turns the very popular ESP8266 wireless microcontroller module into a fully fledged development board. 

A solar panel provides continuous power delivery to a 18650 battery which in turn powers the WeMos.

The deep sleep capabilities of the ESP8266 were used in order to be able to reduce the power consumption even further.

## Sensors used

The sensor used is a Bosch BME280. BME280 is a sophisticated sensor that very accurately measures temperature, humidity and barometric pressure with reasonable accuracy. The BME280 is the next-generation of sensors from Bosch and is the upgrade to the BMP085/BMP180/BMP183 - with a low altitude noise of 0.25m and the same fast conversion time.



## Wiring

The solar panel used delivers a maximum of ~180ma @ 5.5v. When booting up and reading sensor data, the ESP module needs around 80ma, however when in deep sleep (RTC only), only ~20μa are needed. The module could also be powered using AA batteries for months.

The battery is charged from a Solar panel through a TP4056 charging module. The TP4056 module comes with battery protection chip or without the protection chip.

The TP4056 module is perfect for charging single cell 3.7V 1 Ah or higher LiPo cells. Based around the TP4056 charger IC and DW01 battery protection IC this module will offer 1000 mA charge current then cut off when charging is finished. Furthermore, when the battery voltage drops below 2.4V the protection IC will cut off the load to protect the cell from under voltage. It also protects against overvoltage and reverse polarity connection.

<img src="https://i.ibb.co/zn3ksDY/F7-LCJXJJ20-PCE1-T-LARGE.jpg" />

## What it does

- the station wakes up from deep sleep every 10 minutes
- it connects to wifi
- reads the data from the BME280 sensor
- uploads data to a remote database

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[APACHE](https://www.apache.org/licenses/LICENSE-2.0)
