EESchema Schematic File Version 4
LIBS:Hardware-cache
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Analog_ADC:MCP3004 U?
U 1 1 5E447D3D
P 1850 5400
F 0 "U?" H 2300 5750 50  0000 C CNN
F 1 "MCP3004" H 2150 5650 50  0000 C CNN
F 2 "Package_SO:SOIC-14_3.9x8.7mm_P1.27mm" H 2750 5100 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/devicedoc/21295c.pdf" H 2750 5100 50  0001 C CNN
	1    1850 5400
	1    0    0    -1  
$EndComp
$Comp
L signl:JS5208 SW?
U 1 1 5E44885A
P 6850 1100
F 0 "SW?" H 7250 1150 50  0000 C CNN
F 1 "JS5208" H 7000 1050 50  0000 C CNN
F 2 "" H 6850 1150 50  0001 C CNN
F 3 "" H 6850 1150 50  0001 C CNN
	1    6850 1100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Raspberry_Pi_2_3 J?
U 1 1 5E448C27
P 2000 2600
F 0 "J?" H 2650 3850 50  0000 C CNN
F 1 "Raspberry_Pi_2_3" H 2000 3300 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x20_P2.54mm_Vertical" H 2000 2600 50  0001 C CNN
F 3 "https://www.raspberrypi.org/documentation/hardware/raspberrypi/schematics/rpi_SCH_3bplus_1p0_reduced.pdf" H 2000 2600 50  0001 C CNN
	1    2000 2600
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5E450475
P 2150 1100
F 0 "#PWR?" H 2150 950 50  0001 C CNN
F 1 "+3V3" H 2165 1273 50  0000 C CNN
F 2 "" H 2150 1100 50  0001 C CNN
F 3 "" H 2150 1100 50  0001 C CNN
	1    2150 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	2150 1100 2200 1100
Wire Wire Line
	2200 1100 2200 1300
Wire Wire Line
	2150 1100 2100 1100
Wire Wire Line
	2100 1100 2100 1300
Connection ~ 2150 1100
$Comp
L power:GNDD #PWR?
U 1 1 5E45448B
P 1850 5950
F 0 "#PWR?" H 1850 5700 50  0001 C CNN
F 1 "GNDD" H 1854 5795 50  0000 C CNN
F 2 "" H 1850 5950 50  0001 C CNN
F 3 "" H 1850 5950 50  0001 C CNN
	1    1850 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	1850 5900 1850 5950
$Comp
L power:GNDA #PWR?
U 1 1 5E455051
P 1750 6200
F 0 "#PWR?" H 1750 5950 50  0001 C CNN
F 1 "GNDA" H 1755 6027 50  0000 C CNN
F 2 "" H 1750 6200 50  0001 C CNN
F 3 "" H 1750 6200 50  0001 C CNN
	1    1750 6200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1750 5900 1750 6200
$Comp
L power:+3V3 #PWR?
U 1 1 5E4583C1
P 1800 4650
F 0 "#PWR?" H 1800 4500 50  0001 C CNN
F 1 "+3V3" H 1815 4823 50  0000 C CNN
F 2 "" H 1800 4650 50  0001 C CNN
F 3 "" H 1800 4650 50  0001 C CNN
	1    1800 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 4650 1800 4750
Wire Wire Line
	1800 4750 1750 4750
Wire Wire Line
	1800 4750 1850 4750
Wire Wire Line
	1850 4750 1850 5000
Connection ~ 1800 4750
Wire Wire Line
	1750 4750 1750 5000
$Comp
L Device:CP C?
U 1 1 5E46178E
P 2200 4500
F 0 "C?" H 2318 4546 50  0000 L CNN
F 1 "1u" H 2318 4455 50  0000 L CNN
F 2 "" H 2238 4350 50  0001 C CNN
F 3 "~" H 2200 4500 50  0001 C CNN
	1    2200 4500
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5E464071
P 2200 4300
F 0 "#PWR?" H 2200 4150 50  0001 C CNN
F 1 "+3V3" H 2215 4473 50  0000 C CNN
F 2 "" H 2200 4300 50  0001 C CNN
F 3 "" H 2200 4300 50  0001 C CNN
	1    2200 4300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4300 2200 4350
$Comp
L power:GNDA #PWR?
U 1 1 5E465106
P 2200 4700
F 0 "#PWR?" H 2200 4450 50  0001 C CNN
F 1 "GNDA" H 2205 4527 50  0000 C CNN
F 2 "" H 2200 4700 50  0001 C CNN
F 3 "" H 2200 4700 50  0001 C CNN
	1    2200 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4650 2200 4700
$Comp
L Device:R_POT RV?
U 1 1 5E46EB8B
P 3300 1450
F 0 "RV?" H 3230 1496 50  0000 R CNN
F 1 "10k" H 3230 1405 50  0000 R CNN
F 2 "" H 3300 1450 50  0001 C CNN
F 3 "~" H 3300 1450 50  0001 C CNN
	1    3300 1450
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR?
U 1 1 5E471980
P 4300 1150
F 0 "#PWR?" H 4300 1000 50  0001 C CNN
F 1 "+3V3" H 4315 1323 50  0000 C CNN
F 2 "" H 4300 1150 50  0001 C CNN
F 3 "" H 4300 1150 50  0001 C CNN
	1    4300 1150
	1    0    0    -1  
$EndComp
Text Label 3700 1450 2    50   ~ 0
CTRLA
Wire Wire Line
	3700 1450 3450 1450
$Comp
L Device:R_POT RV?
U 1 1 5E478762
P 3950 1450
F 0 "RV?" H 3880 1496 50  0000 R CNN
F 1 "10k" H 3880 1405 50  0000 R CNN
F 2 "" H 3950 1450 50  0001 C CNN
F 3 "~" H 3950 1450 50  0001 C CNN
	1    3950 1450
	1    0    0    -1  
$EndComp
Text Label 4350 1450 2    50   ~ 0
CTRLB
Wire Wire Line
	4350 1450 4100 1450
$Comp
L Device:R_POT RV?
U 1 1 5E47AED3
P 4650 1450
F 0 "RV?" H 4580 1496 50  0000 R CNN
F 1 "10k" H 4580 1405 50  0000 R CNN
F 2 "" H 4650 1450 50  0001 C CNN
F 3 "~" H 4650 1450 50  0001 C CNN
	1    4650 1450
	1    0    0    -1  
$EndComp
Text Label 5050 1450 2    50   ~ 0
CTRLC
Wire Wire Line
	5050 1450 4800 1450
$Comp
L Device:R_POT RV?
U 1 1 5E47AEDB
P 5300 1450
F 0 "RV?" H 5230 1496 50  0000 R CNN
F 1 "10k" H 5230 1405 50  0000 R CNN
F 2 "" H 5300 1450 50  0001 C CNN
F 3 "~" H 5300 1450 50  0001 C CNN
	1    5300 1450
	1    0    0    -1  
$EndComp
Text Label 5700 1450 2    50   ~ 0
CTRLD
Wire Wire Line
	5700 1450 5450 1450
Wire Wire Line
	3300 1300 3300 1150
Wire Wire Line
	3300 1150 3950 1150
Wire Wire Line
	3950 1300 3950 1150
Connection ~ 3950 1150
Wire Wire Line
	3950 1150 4300 1150
Wire Wire Line
	4300 1150 4650 1150
Wire Wire Line
	4650 1150 4650 1300
Connection ~ 4300 1150
Wire Wire Line
	4650 1150 5300 1150
Wire Wire Line
	5300 1150 5300 1300
Connection ~ 4650 1150
$Comp
L power:GNDA #PWR?
U 1 1 5E484401
P 4300 1700
F 0 "#PWR?" H 4300 1450 50  0001 C CNN
F 1 "GNDA" H 4305 1527 50  0000 C CNN
F 2 "" H 4300 1700 50  0001 C CNN
F 3 "" H 4300 1700 50  0001 C CNN
	1    4300 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 1700 3950 1700
Wire Wire Line
	3300 1700 3300 1600
Wire Wire Line
	3950 1600 3950 1700
Connection ~ 3950 1700
Wire Wire Line
	3950 1700 3300 1700
Wire Wire Line
	4300 1700 4650 1700
Wire Wire Line
	4650 1700 4650 1600
Connection ~ 4300 1700
Wire Wire Line
	4650 1700 5300 1700
Wire Wire Line
	5300 1700 5300 1600
Connection ~ 4650 1700
Text Label 1000 5300 0    50   ~ 0
CTRLA
Text Label 1000 5400 0    50   ~ 0
CTRLB
Text Label 1000 5500 0    50   ~ 0
CTRLC
Text Label 1000 5600 0    50   ~ 0
CTRLD
Wire Wire Line
	1250 5300 1000 5300
Wire Wire Line
	1000 5400 1250 5400
Wire Wire Line
	1000 5500 1250 5500
Wire Wire Line
	1000 5600 1250 5600
Text Label 3000 3000 2    50   ~ 0
MOSI
Text Label 3000 2900 2    50   ~ 0
MISO
Text Label 2950 2800 2    50   ~ 0
~CS~
Text Label 3000 3100 2    50   ~ 0
SCLK
Wire Wire Line
	3000 3100 2800 3100
Wire Wire Line
	3000 3000 2800 3000
Wire Wire Line
	3000 2900 2800 2900
Wire Wire Line
	2950 2800 2800 2800
Text Label 2650 5300 2    50   ~ 0
SCLK
Wire Wire Line
	2650 5300 2450 5300
Text Label 2650 5500 2    50   ~ 0
MOSI
Wire Wire Line
	2650 5500 2450 5500
Text Label 2650 5400 2    50   ~ 0
MISO
Wire Wire Line
	2650 5400 2450 5400
Text Label 2600 5600 2    50   ~ 0
~CS~
Wire Wire Line
	2600 5600 2450 5600
$Comp
L Device:R R?
U 1 1 5E4A1A87
P 7900 1100
F 0 "R?" H 7970 1146 50  0000 L CNN
F 1 "10k" H 7970 1055 50  0000 L CNN
F 2 "" V 7830 1100 50  0001 C CNN
F 3 "~" H 7900 1100 50  0001 C CNN
	1    7900 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7400 1250 7900 1250
$Comp
L power:GNDD #PWR?
U 1 1 5E4A38F6
P 6200 1300
F 0 "#PWR?" H 6200 1050 50  0001 C CNN
F 1 "GNDD" H 6204 1145 50  0000 C CNN
F 2 "" H 6200 1300 50  0001 C CNN
F 3 "" H 6200 1300 50  0001 C CNN
	1    6200 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 1300 6200 1250
Wire Wire Line
	6200 1250 6600 1250
Text Label 7850 1250 2    50   ~ 0
CTRLDOWN
Text Label 7850 1400 2    50   ~ 0
CTRLRIGHT
Text Label 7450 1550 0    50   ~ 0
CTRLUP
$Comp
L Device:R R?
U 1 1 5E4A71CC
P 8150 1100
F 0 "R?" H 8220 1146 50  0000 L CNN
F 1 "10k" H 8220 1055 50  0000 L CNN
F 2 "" V 8080 1100 50  0001 C CNN
F 3 "~" H 8150 1100 50  0001 C CNN
	1    8150 1100
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E4A75AC
P 8400 1100
F 0 "R?" H 8470 1146 50  0000 L CNN
F 1 "10k" H 8470 1055 50  0000 L CNN
F 2 "" V 8330 1100 50  0001 C CNN
F 3 "~" H 8400 1100 50  0001 C CNN
	1    8400 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8150 1250 8150 1400
Wire Wire Line
	8150 1400 7400 1400
Wire Wire Line
	8400 1250 8400 1550
Wire Wire Line
	8400 1550 7400 1550
$Comp
L Device:R R?
U 1 1 5E4CAEA9
P 8650 1100
F 0 "R?" H 8720 1146 50  0000 L CNN
F 1 "10k" H 8720 1055 50  0000 L CNN
F 2 "" V 8580 1100 50  0001 C CNN
F 3 "~" H 8650 1100 50  0001 C CNN
	1    8650 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8650 1250 8650 1750
Wire Wire Line
	8650 1750 6500 1750
Wire Wire Line
	6500 1750 6500 1550
Wire Wire Line
	6500 1550 6600 1550
$Comp
L Device:R R?
U 1 1 5E4CC618
P 8900 1100
F 0 "R?" H 8970 1146 50  0000 L CNN
F 1 "10k" H 8970 1055 50  0000 L CNN
F 2 "" V 8830 1100 50  0001 C CNN
F 3 "~" H 8900 1100 50  0001 C CNN
	1    8900 1100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 1250 8900 1900
Wire Wire Line
	8900 1900 6400 1900
Wire Wire Line
	6400 1900 6400 1400
Wire Wire Line
	6400 1400 6600 1400
Text Label 7450 1750 0    50   ~ 0
CTRLPUSH
Text Label 7450 1900 0    50   ~ 0
CTRLLEFT
$Comp
L power:+3V3 #PWR?
U 1 1 5E4D887D
P 8400 850
F 0 "#PWR?" H 8400 700 50  0001 C CNN
F 1 "+3V3" H 8415 1023 50  0000 C CNN
F 2 "" H 8400 850 50  0001 C CNN
F 3 "" H 8400 850 50  0001 C CNN
	1    8400 850 
	1    0    0    -1  
$EndComp
Wire Wire Line
	8400 850  8150 850 
Wire Wire Line
	7900 850  7900 950 
Wire Wire Line
	8400 850  8400 950 
Connection ~ 8400 850 
Wire Wire Line
	8400 850  8650 850 
Wire Wire Line
	8900 850  8900 950 
Wire Wire Line
	8650 950  8650 850 
Connection ~ 8650 850 
Wire Wire Line
	8650 850  8900 850 
Wire Wire Line
	8150 950  8150 850 
Connection ~ 8150 850 
Wire Wire Line
	8150 850  7900 850 
Text Label 800  2800 0    50   ~ 0
CTRLLEFT
Text Label 800  2900 0    50   ~ 0
CTRLPUSH
Text Label 800  3000 0    50   ~ 0
CTRLUP
Text Label 800  3100 0    50   ~ 0
CTRLRIGHT
Text Label 800  3200 0    50   ~ 0
CTRLDOWN
Wire Wire Line
	1200 2800 800  2800
Wire Wire Line
	800  2900 1200 2900
Wire Wire Line
	800  3000 1200 3000
Wire Wire Line
	800  3100 1200 3100
Wire Wire Line
	800  3200 1200 3200
$Comp
L signl:WM8731SEDS U?
U 1 1 5E4709CA
P 6400 3100
F 0 "U?" H 6400 3215 50  0000 C CNN
F 1 "WM8731SEDS" H 6400 3124 50  0000 C CNN
F 2 "Package_SO:SSOP-28_5.3x10.2mm_P0.65mm" H 6400 3100 50  0001 C CNN
F 3 "https://www.mouser.co.uk/datasheet/2/76/WM8731_v4.9-1141834.pdf" H 6400 3100 50  0001 C CNN
	1    6400 3100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5E4A86BA
P 4600 4350
F 0 "C?" V 4850 4350 50  0000 C CNN
F 1 "1u" V 4750 4350 50  0000 C CNN
F 2 "" H 4638 4200 50  0001 C CNN
F 3 "~" H 4600 4350 50  0001 C CNN
	1    4600 4350
	0    1    -1   0   
$EndComp
Wire Wire Line
	5150 4350 4750 4350
$Comp
L Device:C C?
U 1 1 5E4B5C73
P 4350 4550
F 0 "C?" H 4450 4600 50  0000 L CNN
F 1 "220p" H 4450 4500 50  0000 L CNN
F 2 "" H 4388 4400 50  0001 C CNN
F 3 "~" H 4350 4550 50  0001 C CNN
	1    4350 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E4B664C
P 4050 4550
F 0 "R?" H 4100 4600 50  0000 L CNN
F 1 "5.6k" H 4100 4500 50  0000 L CNN
F 2 "" V 3980 4550 50  0001 C CNN
F 3 "~" H 4050 4550 50  0001 C CNN
	1    4050 4550
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E4B6965
P 3800 4350
F 0 "R?" V 3900 4350 50  0000 C CNN
F 1 "5.6k" V 4000 4350 50  0000 C CNN
F 2 "" V 3730 4350 50  0001 C CNN
F 3 "~" H 3800 4350 50  0001 C CNN
	1    3800 4350
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 4350 4350 4350
Wire Wire Line
	4050 4400 4050 4350
Connection ~ 4050 4350
Wire Wire Line
	4050 4350 3950 4350
Wire Wire Line
	4350 4400 4350 4350
Connection ~ 4350 4350
Wire Wire Line
	4350 4350 4050 4350
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E4C7648
P 3400 4350
F 0 "J?" H 3328 4588 50  0000 C CNN
F 1 "LLINEIN" H 3328 4497 50  0000 C CNN
F 2 "" H 3400 4350 50  0001 C CNN
F 3 " ~" H 3400 4350 50  0001 C CNN
	1    3400 4350
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3600 4350 3650 4350
$Comp
L power:GNDA #PWR?
U 1 1 5E4CE7C8
P 3400 4600
F 0 "#PWR?" H 3400 4350 50  0001 C CNN
F 1 "GNDA" H 3405 4427 50  0000 C CNN
F 2 "" H 3400 4600 50  0001 C CNN
F 3 "" H 3400 4600 50  0001 C CNN
	1    3400 4600
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 4550 3400 4600
$Comp
L power:GNDA #PWR?
U 1 1 5E4D8F09
P 4200 4750
F 0 "#PWR?" H 4200 4500 50  0001 C CNN
F 1 "GNDA" H 4205 4577 50  0000 C CNN
F 2 "" H 4200 4750 50  0001 C CNN
F 3 "" H 4200 4750 50  0001 C CNN
	1    4200 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 4700 4050 4750
Wire Wire Line
	4050 4750 4200 4750
Wire Wire Line
	4350 4750 4350 4700
Connection ~ 4200 4750
Wire Wire Line
	4200 4750 4350 4750
$Comp
L Device:CP C?
U 1 1 5E4F18FD
P 4600 5150
F 0 "C?" V 4500 5350 50  0000 C CNN
F 1 "1u" V 4400 5350 50  0000 C CNN
F 2 "" H 4638 5000 50  0001 C CNN
F 3 "~" H 4600 5150 50  0001 C CNN
	1    4600 5150
	0    1    -1   0   
$EndComp
Wire Wire Line
	5150 5150 4750 5150
$Comp
L Device:C C?
U 1 1 5E4F1905
P 4350 5350
F 0 "C?" H 4465 5396 50  0000 L CNN
F 1 "220p" H 4465 5305 50  0000 L CNN
F 2 "" H 4388 5200 50  0001 C CNN
F 3 "~" H 4350 5350 50  0001 C CNN
	1    4350 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E4F190B
P 4050 5350
F 0 "R?" H 4100 5400 50  0000 L CNN
F 1 "5.6k" H 4100 5300 50  0000 L CNN
F 2 "" V 3980 5350 50  0001 C CNN
F 3 "~" H 4050 5350 50  0001 C CNN
	1    4050 5350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E4F1911
P 3800 5150
F 0 "R?" V 3900 5150 50  0000 C CNN
F 1 "5.6k" V 4000 5150 50  0000 C CNN
F 2 "" V 3730 5150 50  0001 C CNN
F 3 "~" H 3800 5150 50  0001 C CNN
	1    3800 5150
	0    1    1    0   
$EndComp
Wire Wire Line
	4450 5150 4350 5150
Wire Wire Line
	4050 5200 4050 5150
Connection ~ 4050 5150
Wire Wire Line
	4050 5150 3950 5150
Wire Wire Line
	4350 5200 4350 5150
Connection ~ 4350 5150
Wire Wire Line
	4350 5150 4050 5150
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E4F191E
P 3400 5150
F 0 "J?" H 3328 5388 50  0000 C CNN
F 1 "RLINEIN" H 3328 5297 50  0000 C CNN
F 2 "" H 3400 5150 50  0001 C CNN
F 3 " ~" H 3400 5150 50  0001 C CNN
	1    3400 5150
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3600 5150 3650 5150
$Comp
L power:GNDA #PWR?
U 1 1 5E4F1925
P 3400 5400
F 0 "#PWR?" H 3400 5150 50  0001 C CNN
F 1 "GNDA" H 3405 5227 50  0000 C CNN
F 2 "" H 3400 5400 50  0001 C CNN
F 3 "" H 3400 5400 50  0001 C CNN
	1    3400 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 5350 3400 5400
$Comp
L power:GNDA #PWR?
U 1 1 5E4F192C
P 4200 5550
F 0 "#PWR?" H 4200 5300 50  0001 C CNN
F 1 "GNDA" H 4205 5377 50  0000 C CNN
F 2 "" H 4200 5550 50  0001 C CNN
F 3 "" H 4200 5550 50  0001 C CNN
	1    4200 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 5500 4050 5550
Wire Wire Line
	4050 5550 4200 5550
Wire Wire Line
	4350 5550 4350 5500
Connection ~ 4200 5550
Wire Wire Line
	4200 5550 4350 5550
$Comp
L Device:R R?
U 1 1 5E4FCD2A
P 4700 5850
F 0 "R?" V 4800 5850 50  0000 C CNN
F 1 "680" V 4900 5850 50  0000 C CNN
F 2 "" V 4630 5850 50  0001 C CNN
F 3 "~" H 4700 5850 50  0001 C CNN
	1    4700 5850
	0    -1   -1   0   
$EndComp
$Comp
L Device:CP C?
U 1 1 5E50C9FA
P 4300 6050
F 0 "C?" V 4450 6050 50  0000 C CNN
F 1 "1u" V 4550 6050 50  0000 C CNN
F 2 "" H 4338 5900 50  0001 C CNN
F 3 "~" H 4300 6050 50  0001 C CNN
	1    4300 6050
	0    1    1    0   
$EndComp
Wire Wire Line
	4550 6050 4450 6050
$Comp
L Device:C C?
U 1 1 5E527D8D
P 4100 6250
F 0 "C?" H 3850 6300 50  0000 L CNN
F 1 "220p" H 3800 6200 50  0000 L CNN
F 2 "" H 4138 6100 50  0001 C CNN
F 3 "~" H 4100 6250 50  0001 C CNN
	1    4100 6250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4100 6100 4100 6050
Wire Wire Line
	4100 6050 4150 6050
$Comp
L Device:R R?
U 1 1 5E52CB4E
P 3700 6250
F 0 "R?" H 3850 6300 50  0000 C CNN
F 1 "47k" H 3850 6200 50  0000 C CNN
F 2 "" V 3630 6250 50  0001 C CNN
F 3 "~" H 3700 6250 50  0001 C CNN
	1    3700 6250
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3700 6100 3700 6050
Wire Wire Line
	3700 6050 4100 6050
Connection ~ 4100 6050
Wire Wire Line
	4550 5850 4100 5850
Wire Wire Line
	4100 5850 4100 6050
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E5360A1
P 3400 6050
F 0 "J?" H 3328 6288 50  0000 C CNN
F 1 "MICIN" H 3328 6197 50  0000 C CNN
F 2 "" H 3400 6050 50  0001 C CNN
F 3 " ~" H 3400 6050 50  0001 C CNN
	1    3400 6050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	3600 6050 3700 6050
Connection ~ 3700 6050
Wire Wire Line
	3400 6450 3400 6250
Wire Wire Line
	4100 6450 4100 6400
Wire Wire Line
	4850 5850 5150 5850
Wire Wire Line
	5150 6050 4850 6050
$Comp
L Device:C C?
U 1 1 5E5CB6A1
P 7150 3300
F 0 "C?" H 7265 3346 50  0000 L CNN
F 1 "0.1u" H 7265 3255 50  0000 L CNN
F 2 "" H 7188 3150 50  0001 C CNN
F 3 "~" H 7150 3300 50  0001 C CNN
	1    7150 3300
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5E5CC5A1
P 7550 3300
F 0 "C?" H 7668 3346 50  0000 L CNN
F 1 "10u" H 7668 3255 50  0000 L CNN
F 2 "" H 7588 3150 50  0001 C CNN
F 3 "~" H 7550 3300 50  0001 C CNN
	1    7550 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3150 7350 3150
Wire Wire Line
	7150 3450 7350 3450
Wire Wire Line
	7150 3450 6900 3450
Connection ~ 7150 3450
$Comp
L power:GNDA #PWR?
U 1 1 5E5DE031
P 7350 3450
F 0 "#PWR?" H 7350 3200 50  0001 C CNN
F 1 "GNDA" H 7355 3277 50  0000 C CNN
F 2 "" H 7350 3450 50  0001 C CNN
F 3 "" H 7350 3450 50  0001 C CNN
	1    7350 3450
	1    0    0    -1  
$EndComp
Connection ~ 7350 3450
Wire Wire Line
	7350 3450 7550 3450
$Comp
L power:+3V3 #PWR?
U 1 1 5E5E4307
P 7350 3150
F 0 "#PWR?" H 7350 3000 50  0001 C CNN
F 1 "+3V3" H 7365 3323 50  0000 C CNN
F 2 "" H 7350 3150 50  0001 C CNN
F 3 "" H 7350 3150 50  0001 C CNN
	1    7350 3150
	1    0    0    -1  
$EndComp
Connection ~ 7350 3150
Wire Wire Line
	7350 3150 7150 3150
Wire Wire Line
	7150 3150 7000 3150
Wire Wire Line
	7000 3150 7000 3350
Wire Wire Line
	7000 3350 6900 3350
Connection ~ 7150 3150
$Comp
L Device:C C?
U 1 1 5E631EF3
P 7150 4100
F 0 "C?" H 7265 4146 50  0000 L CNN
F 1 "0.1u" H 7265 4055 50  0000 L CNN
F 2 "" H 7188 3950 50  0001 C CNN
F 3 "~" H 7150 4100 50  0001 C CNN
	1    7150 4100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5E631EF9
P 7550 4100
F 0 "C?" H 7668 4146 50  0000 L CNN
F 1 "10u" H 7668 4055 50  0000 L CNN
F 2 "" H 7588 3950 50  0001 C CNN
F 3 "~" H 7550 4100 50  0001 C CNN
	1    7550 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 3950 7350 3950
Wire Wire Line
	7150 4250 7350 4250
Wire Wire Line
	7150 4250 6900 4250
Connection ~ 7150 4250
$Comp
L power:GNDA #PWR?
U 1 1 5E631F03
P 7350 4250
F 0 "#PWR?" H 7350 4000 50  0001 C CNN
F 1 "GNDA" H 7355 4077 50  0000 C CNN
F 2 "" H 7350 4250 50  0001 C CNN
F 3 "" H 7350 4250 50  0001 C CNN
	1    7350 4250
	1    0    0    -1  
$EndComp
Connection ~ 7350 4250
Wire Wire Line
	7350 4250 7550 4250
$Comp
L power:+3V3 #PWR?
U 1 1 5E631F0B
P 7350 3950
F 0 "#PWR?" H 7350 3800 50  0001 C CNN
F 1 "+3V3" H 7365 4123 50  0000 C CNN
F 2 "" H 7350 3950 50  0001 C CNN
F 3 "" H 7350 3950 50  0001 C CNN
	1    7350 3950
	1    0    0    -1  
$EndComp
Connection ~ 7350 3950
Wire Wire Line
	7350 3950 7150 3950
Wire Wire Line
	7150 3950 7000 3950
Connection ~ 7150 3950
Wire Wire Line
	7000 3950 7000 4150
Wire Wire Line
	6900 4150 7000 4150
$Comp
L Device:CP C?
U 1 1 5E63EB82
P 9450 3250
F 0 "C?" V 9705 3250 50  0000 C CNN
F 1 "1u" V 9614 3250 50  0000 C CNN
F 2 "" H 9488 3100 50  0001 C CNN
F 3 "~" H 9450 3250 50  0001 C CNN
	1    9450 3250
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E63FE9D
P 9700 3400
F 0 "R?" H 9770 3446 50  0000 L CNN
F 1 "47k" H 9770 3355 50  0000 L CNN
F 2 "" V 9630 3400 50  0001 C CNN
F 3 "~" H 9700 3400 50  0001 C CNN
	1    9700 3400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E640239
P 9950 3250
F 0 "R?" V 9743 3250 50  0000 C CNN
F 1 "100" V 9834 3250 50  0000 C CNN
F 2 "" V 9880 3250 50  0001 C CNN
F 3 "~" H 9950 3250 50  0001 C CNN
	1    9950 3250
	0    1    1    0   
$EndComp
Wire Wire Line
	9800 3250 9700 3250
Connection ~ 9700 3250
Wire Wire Line
	9700 3250 9600 3250
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E6473B4
P 10350 3250
F 0 "J?" H 10450 3225 50  0000 L CNN
F 1 "LOUT" H 10450 3134 50  0000 L CNN
F 2 "" H 10350 3250 50  0001 C CNN
F 3 " ~" H 10350 3250 50  0001 C CNN
	1    10350 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 3250 10100 3250
$Comp
L power:GNDA #PWR?
U 1 1 5E64E5EB
P 10350 3550
F 0 "#PWR?" H 10350 3300 50  0001 C CNN
F 1 "GNDA" H 10355 3377 50  0000 C CNN
F 2 "" H 10350 3550 50  0001 C CNN
F 3 "" H 10350 3550 50  0001 C CNN
	1    10350 3550
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5E64E7D2
P 9700 3550
F 0 "#PWR?" H 9700 3300 50  0001 C CNN
F 1 "GNDA" H 9705 3377 50  0000 C CNN
F 2 "" H 9700 3550 50  0001 C CNN
F 3 "" H 9700 3550 50  0001 C CNN
	1    9700 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 3550 10350 3450
$Comp
L Device:CP C?
U 1 1 5E669922
P 9450 3900
F 0 "C?" V 9705 3900 50  0000 C CNN
F 1 "1u" V 9614 3900 50  0000 C CNN
F 2 "" H 9488 3750 50  0001 C CNN
F 3 "~" H 9450 3900 50  0001 C CNN
	1    9450 3900
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E669928
P 9700 4050
F 0 "R?" H 9770 4096 50  0000 L CNN
F 1 "47k" H 9770 4005 50  0000 L CNN
F 2 "" V 9630 4050 50  0001 C CNN
F 3 "~" H 9700 4050 50  0001 C CNN
	1    9700 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E66992E
P 9950 3900
F 0 "R?" V 9743 3900 50  0000 C CNN
F 1 "100" V 9834 3900 50  0000 C CNN
F 2 "" V 9880 3900 50  0001 C CNN
F 3 "~" H 9950 3900 50  0001 C CNN
	1    9950 3900
	0    1    1    0   
$EndComp
Wire Wire Line
	9800 3900 9700 3900
Connection ~ 9700 3900
Wire Wire Line
	9700 3900 9600 3900
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E669937
P 10350 3900
F 0 "J?" H 10450 3875 50  0000 L CNN
F 1 "ROUT" H 10450 3784 50  0000 L CNN
F 2 "" H 10350 3900 50  0001 C CNN
F 3 " ~" H 10350 3900 50  0001 C CNN
	1    10350 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 3900 10100 3900
$Comp
L power:GNDA #PWR?
U 1 1 5E66993E
P 10350 4200
F 0 "#PWR?" H 10350 3950 50  0001 C CNN
F 1 "GNDA" H 10355 4027 50  0000 C CNN
F 2 "" H 10350 4200 50  0001 C CNN
F 3 "" H 10350 4200 50  0001 C CNN
	1    10350 4200
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5E669944
P 9700 4200
F 0 "#PWR?" H 9700 3950 50  0001 C CNN
F 1 "GNDA" H 9705 4027 50  0000 C CNN
F 2 "" H 9700 4200 50  0001 C CNN
F 3 "" H 9700 4200 50  0001 C CNN
	1    9700 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 4200 10350 4100
Text Label 9000 3250 0    50   ~ 0
LOUT
Wire Wire Line
	9300 3250 9000 3250
Text Label 9000 3900 0    50   ~ 0
ROUT
Wire Wire Line
	9300 3900 9000 3900
Text Label 7200 4400 2    50   ~ 0
LOUT
Wire Wire Line
	7200 4400 6900 4400
Text Label 7200 4500 2    50   ~ 0
ROUT
Wire Wire Line
	7200 4500 6900 4500
Text Label 7200 4650 2    50   ~ 0
LHPOUT
Wire Wire Line
	7200 4650 6900 4650
Text Label 7200 4750 2    50   ~ 0
RHPOUT
Wire Wire Line
	7200 4750 6900 4750
$Comp
L Device:C C?
U 1 1 5E6B6DE4
P 7150 5200
F 0 "C?" H 7265 5246 50  0000 L CNN
F 1 "0.1u" H 7265 5155 50  0000 L CNN
F 2 "" H 7188 5050 50  0001 C CNN
F 3 "~" H 7150 5200 50  0001 C CNN
	1    7150 5200
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C?
U 1 1 5E6B777B
P 7550 5200
F 0 "C?" H 7668 5246 50  0000 L CNN
F 1 "10u" H 7668 5155 50  0000 L CNN
F 2 "" H 7588 5050 50  0001 C CNN
F 3 "~" H 7550 5200 50  0001 C CNN
	1    7550 5200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7550 5350 7350 5350
Wire Wire Line
	6900 5050 7150 5050
Connection ~ 7150 5050
Wire Wire Line
	7150 5050 7550 5050
$Comp
L power:GNDA #PWR?
U 1 1 5E6C73D4
P 7350 5350
F 0 "#PWR?" H 7350 5100 50  0001 C CNN
F 1 "GNDA" H 7355 5177 50  0000 C CNN
F 2 "" H 7350 5350 50  0001 C CNN
F 3 "" H 7350 5350 50  0001 C CNN
	1    7350 5350
	1    0    0    -1  
$EndComp
Connection ~ 7350 5350
Wire Wire Line
	7350 5350 7150 5350
$Comp
L Device:CP C?
U 1 1 5E6C75CE
P 9450 4550
F 0 "C?" V 9705 4550 50  0000 C CNN
F 1 "220u" V 9614 4550 50  0000 C CNN
F 2 "" H 9488 4400 50  0001 C CNN
F 3 "~" H 9450 4550 50  0001 C CNN
	1    9450 4550
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E6C7DE3
P 9700 4700
F 0 "R?" H 9770 4746 50  0000 L CNN
F 1 "47k" H 9770 4655 50  0000 L CNN
F 2 "" V 9630 4700 50  0001 C CNN
F 3 "~" H 9700 4700 50  0001 C CNN
	1    9700 4700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 4550 9600 4550
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E6D00C6
P 10350 4550
F 0 "J?" H 10450 4525 50  0000 L CNN
F 1 "LHPOUT" H 10450 4434 50  0000 L CNN
F 2 "" H 10350 4550 50  0001 C CNN
F 3 " ~" H 10350 4550 50  0001 C CNN
	1    10350 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	10150 4550 9700 4550
Connection ~ 9700 4550
$Comp
L power:GNDA #PWR?
U 1 1 5E6D8D3F
P 9700 4850
F 0 "#PWR?" H 9700 4600 50  0001 C CNN
F 1 "GNDA" H 9705 4677 50  0000 C CNN
F 2 "" H 9700 4850 50  0001 C CNN
F 3 "" H 9700 4850 50  0001 C CNN
	1    9700 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5E6D8F85
P 10350 4850
F 0 "#PWR?" H 10350 4600 50  0001 C CNN
F 1 "GNDA" H 10355 4677 50  0000 C CNN
F 2 "" H 10350 4850 50  0001 C CNN
F 3 "" H 10350 4850 50  0001 C CNN
	1    10350 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 4750 10350 4850
Text Label 9000 4550 0    50   ~ 0
LHPOUT
Wire Wire Line
	9000 4550 9300 4550
$Comp
L Device:CP C?
U 1 1 5E6EAE8B
P 9450 5200
F 0 "C?" V 9705 5200 50  0000 C CNN
F 1 "220u" V 9614 5200 50  0000 C CNN
F 2 "" H 9488 5050 50  0001 C CNN
F 3 "~" H 9450 5200 50  0001 C CNN
	1    9450 5200
	0    -1   -1   0   
$EndComp
$Comp
L Device:R R?
U 1 1 5E6EAE91
P 9700 5350
F 0 "R?" H 9770 5396 50  0000 L CNN
F 1 "47k" H 9770 5305 50  0000 L CNN
F 2 "" V 9630 5350 50  0001 C CNN
F 3 "~" H 9700 5350 50  0001 C CNN
	1    9700 5350
	1    0    0    -1  
$EndComp
Wire Wire Line
	9700 5200 9600 5200
Wire Wire Line
	10150 5200 9700 5200
Connection ~ 9700 5200
$Comp
L power:GNDA #PWR?
U 1 1 5E6EAEA0
P 9700 5500
F 0 "#PWR?" H 9700 5250 50  0001 C CNN
F 1 "GNDA" H 9705 5327 50  0000 C CNN
F 2 "" H 9700 5500 50  0001 C CNN
F 3 "" H 9700 5500 50  0001 C CNN
	1    9700 5500
	1    0    0    -1  
$EndComp
$Comp
L power:GNDA #PWR?
U 1 1 5E6EAEA6
P 10350 5500
F 0 "#PWR?" H 10350 5250 50  0001 C CNN
F 1 "GNDA" H 10355 5327 50  0000 C CNN
F 2 "" H 10350 5500 50  0001 C CNN
F 3 "" H 10350 5500 50  0001 C CNN
	1    10350 5500
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 5400 10350 5500
Text Label 9000 5200 0    50   ~ 0
RHPOUT
Wire Wire Line
	9000 5200 9300 5200
Text Label 5600 3700 0    50   ~ 0
LLINEIN
Wire Wire Line
	5600 3700 5900 3700
Text Label 5600 3800 0    50   ~ 0
RLINEIN
Wire Wire Line
	5600 3800 5900 3800
Wire Wire Line
	5600 3950 5900 3950
Text Label 5600 3950 0    50   ~ 0
MICBIAS
Text Label 5600 4050 0    50   ~ 0
MICIN
Wire Wire Line
	5600 4050 5900 4050
Text Label 5150 4350 2    50   ~ 0
LLINEIN
Text Label 5150 5150 2    50   ~ 0
RLINEIN
Wire Wire Line
	3400 6450 3700 6450
Connection ~ 3400 6450
$Comp
L power:GNDA #PWR?
U 1 1 5E53B276
P 3400 6450
F 0 "#PWR?" H 3400 6200 50  0001 C CNN
F 1 "GNDA" H 3405 6277 50  0000 C CNN
F 2 "" H 3400 6450 50  0001 C CNN
F 3 "" H 3400 6450 50  0001 C CNN
	1    3400 6450
	1    0    0    -1  
$EndComp
Wire Wire Line
	3700 6400 3700 6450
Connection ~ 3700 6450
Wire Wire Line
	3700 6450 4100 6450
Text Label 5150 5850 2    50   ~ 0
MICBIAS
Text Label 5150 6050 2    50   ~ 0
MICIN
Wire Wire Line
	5450 3150 5450 3350
Wire Wire Line
	5450 3350 5900 3350
Connection ~ 4750 3750
Wire Wire Line
	4200 3750 4200 3700
Wire Wire Line
	4750 3750 4200 3750
Wire Wire Line
	4750 3750 5100 3750
$Comp
L power:+3V3 #PWR?
U 1 1 5E48E79B
P 4200 3700
F 0 "#PWR?" H 4200 3550 50  0001 C CNN
F 1 "+3V3" H 4215 3873 50  0000 C CNN
F 2 "" H 4200 3700 50  0001 C CNN
F 3 "" H 4200 3700 50  0001 C CNN
	1    4200 3700
	1    0    0    -1  
$EndComp
Connection ~ 5100 3750
Wire Wire Line
	5450 3750 5100 3750
Wire Wire Line
	5450 3550 5450 3750
Wire Wire Line
	5900 3550 5450 3550
$Comp
L Device:CP C?
U 1 1 5E4857DF
P 4750 3600
F 0 "C?" H 4632 3554 50  0000 R CNN
F 1 "10u" H 4632 3645 50  0000 R CNN
F 2 "" H 4788 3450 50  0001 C CNN
F 3 "~" H 4750 3600 50  0001 C CNN
	1    4750 3600
	-1   0    0    1   
$EndComp
$Comp
L Device:C C?
U 1 1 5E485382
P 5100 3600
F 0 "C?" H 5215 3646 50  0000 L CNN
F 1 "0.1u" H 5215 3555 50  0000 L CNN
F 2 "" H 5138 3450 50  0001 C CNN
F 3 "~" H 5100 3600 50  0001 C CNN
	1    5100 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 3150 4750 3150
Connection ~ 4950 3150
$Comp
L power:+3V3 #PWR?
U 1 1 5E484C55
P 4950 3150
F 0 "#PWR?" H 4950 3000 50  0001 C CNN
F 1 "+3V3" H 4965 3323 50  0000 C CNN
F 2 "" H 4950 3150 50  0001 C CNN
F 3 "" H 4950 3150 50  0001 C CNN
	1    4950 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 3150 4950 3150
Connection ~ 5100 3150
Wire Wire Line
	5450 3150 5100 3150
Wire Wire Line
	4750 3450 5100 3450
Connection ~ 4750 3450
$Comp
L Device:CP C?
U 1 1 5E47B4E6
P 4750 3300
F 0 "C?" H 4868 3346 50  0000 L CNN
F 1 "10u" H 4868 3255 50  0000 L CNN
F 2 "" H 4788 3150 50  0001 C CNN
F 3 "~" H 4750 3300 50  0001 C CNN
	1    4750 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4500 3450 4750 3450
Connection ~ 5100 3450
$Comp
L Device:C C?
U 1 1 5E477F0B
P 5100 3300
F 0 "C?" H 5215 3346 50  0000 L CNN
F 1 "0.1u" H 5215 3255 50  0000 L CNN
F 2 "" H 5138 3150 50  0001 C CNN
F 3 "~" H 5100 3300 50  0001 C CNN
	1    5100 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 3450 5100 3450
$Comp
L power:GNDD #PWR?
U 1 1 5E473086
P 4500 3450
F 0 "#PWR?" H 4500 3200 50  0001 C CNN
F 1 "GNDD" H 4504 3295 50  0000 C CNN
F 2 "" H 4500 3450 50  0001 C CNN
F 3 "" H 4500 3450 50  0001 C CNN
	1    4500 3450
	1    0    0    -1  
$EndComp
$Comp
L Device:R R?
U 1 1 5E87B495
P 7350 4900
F 0 "R?" V 7143 4900 50  0000 C CNN
F 1 "100" V 7234 4900 50  0000 C CNN
F 2 "" V 7280 4900 50  0001 C CNN
F 3 "~" H 7350 4900 50  0001 C CNN
	1    7350 4900
	0    1    1    0   
$EndComp
Wire Wire Line
	7200 4900 6900 4900
Text Label 7800 4900 2    50   ~ 0
CLKOUT
Wire Wire Line
	7500 4900 7800 4900
$Comp
L Connector:Conn_Coaxial J?
U 1 1 5E6EAE98
P 10350 5200
F 0 "J?" H 10450 5175 50  0000 L CNN
F 1 "RHPOUT" H 10450 5084 50  0000 L CNN
F 2 "" H 10350 5200 50  0001 C CNN
F 3 " ~" H 10350 5200 50  0001 C CNN
	1    10350 5200
	1    0    0    -1  
$EndComp
Wire Notes Line
	8950 2900 10800 2900
Wire Notes Line
	10800 2900 10800 5800
Wire Notes Line
	10800 5800 8950 5800
Wire Notes Line
	8950 5800 8950 2900
Text Notes 9600 5900 0    50   ~ 0
OUTPUT STAGE
Wire Notes Line
	3250 4000 5200 4000
Wire Notes Line
	5200 4000 5200 6750
Wire Notes Line
	5200 6750 3250 6750
Wire Notes Line
	3250 6750 3250 4000
Text Notes 3950 6850 0    50   ~ 0
INPUT STAGE
Text Label 800  2200 0    50   ~ 0
BCLK
Wire Wire Line
	800  2200 1200 2200
Text Label 800  2600 0    50   ~ 0
DACDAT
Wire Wire Line
	800  2600 1200 2600
Text Label 800  2400 0    50   ~ 0
LRC
Wire Wire Line
	800  2400 1200 2400
Text Label 800  2500 0    50   ~ 0
ADCDAT
Wire Wire Line
	800  2500 1200 2500
Text Label 5600 4600 0    50   ~ 0
BCLK
Wire Wire Line
	5600 4600 5900 4600
Text Label 5600 4500 0    50   ~ 0
LRC
Wire Wire Line
	5600 4500 5900 4500
Text Label 5600 4200 0    50   ~ 0
LRC
Wire Wire Line
	5600 4200 5900 4200
Text Label 5600 4400 0    50   ~ 0
ADCDAT
Wire Wire Line
	5600 4400 5900 4400
Text Label 5600 4300 0    50   ~ 0
DACDAT
Wire Wire Line
	5600 4300 5900 4300
$Comp
L Device:R_POT RV?
U 1 1 5E50B9EA
P 4850 6200
F 0 "RV?" H 4780 6154 50  0000 R CNN
F 1 "R_POT" H 4780 6245 50  0000 R CNN
F 2 "" H 4850 6200 50  0001 C CNN
F 3 "~" H 4850 6200 50  0001 C CNN
	1    4850 6200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4700 6200 4550 6200
Wire Wire Line
	4550 6200 4550 6050
NoConn ~ 4850 6350
NoConn ~ 6350 5500
NoConn ~ 6500 5500
$EndSCHEMATC
