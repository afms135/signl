EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
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
L Connector:AudioJack3_Switch J1
U 1 1 5E4D6844
P 1700 1300
F 0 "J1" H 1682 1725 50  0000 C CNN
F 1 "AudioJack3_Switch" H 1682 1634 50  0000 C CNN
F 2 "Connector_Audio:Jack_3.5mm_Neutrik_NMJ6HCD2_Horizontal" H 1700 1300 50  0001 C CNN
F 3 "~" H 1700 1300 50  0001 C CNN
	1    1700 1300
	1    0    0    -1  
$EndComp
$Comp
L Jumper:SolderJumper_2_Open JP1
U 1 1 5E4D8A21
P 2350 1350
F 0 "JP1" V 2304 1418 50  0000 L CNN
F 1 "SolderJumper_2_Open" V 2395 1418 50  0000 L CNN
F 2 "Jumper:SolderJumper-2_P1.3mm_Open_RoundedPad1.0x1.5mm" H 2350 1350 50  0001 C CNN
F 3 "~" H 2350 1350 50  0001 C CNN
	1    2350 1350
	0    1    1    0   
$EndComp
Wire Wire Line
	1900 1500 2350 1500
Wire Wire Line
	1900 1300 2200 1300
Wire Wire Line
	2200 1300 2200 1200
Wire Wire Line
	2200 1200 2350 1200
NoConn ~ 1900 1600
NoConn ~ 1900 1400
NoConn ~ 1900 1200
Wire Wire Line
	2350 1500 2850 1500
Wire Wire Line
	2850 1500 2850 1300
Connection ~ 2350 1500
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5E4D8113
P 3150 1200
F 0 "J2" H 3230 1242 50  0000 L CNN
F 1 "Conn_01x03" H 3230 1151 50  0000 L CNN
F 2 "Connector_Molex:Molex_KK-254_AE-6410-03A_1x03_P2.54mm_Vertical" H 3150 1200 50  0001 C CNN
F 3 "~" H 3150 1200 50  0001 C CNN
	1    3150 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 1100 1900 1100
Wire Wire Line
	2350 1200 2950 1200
Connection ~ 2350 1200
Wire Wire Line
	2850 1300 2950 1300
$EndSCHEMATC
