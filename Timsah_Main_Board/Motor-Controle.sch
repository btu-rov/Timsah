EESchema Schematic File Version 4
LIBS:Timsah_Main_Board-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title "Timsah: Main Control"
Date "2019-08-24"
Rev "v1.1"
Comp "BTU-ROV"
Comment1 "Designer: Bahtiyar Bayram"
Comment2 "https://creativecommons.org/licenses/by-sa/4.0/"
Comment3 "Attribution-ShareAlike 4.0 International"
Comment4 "Released under the Creative Commons"
$EndDescr
Wire Wire Line
	1700 3350 1850 3350
Wire Wire Line
	1850 3250 1700 3250
Wire Wire Line
	1700 2850 1850 2850
Wire Wire Line
	1850 2750 1700 2750
Text Notes 1250 3650 0    100  ~ 20
BLDC Control
Text GLabel 1850 3350 2    50   Input ~ 0
BR-R
Text GLabel 1850 3250 2    50   Input ~ 0
BL-R
Text GLabel 1850 2850 2    50   Input ~ 0
UR-R
Text GLabel 1850 2750 2    50   Input ~ 0
UL-R
Wire Wire Line
	1800 2350 1700 2350
$Comp
L power:+12V #PWR052
U 1 1 5D6D2155
P 1800 2350
F 0 "#PWR052" H 1800 2200 50  0001 C CNN
F 1 "+12V" V 1815 2478 50  0000 L CNN
F 2 "" H 1800 2350 50  0001 C CNN
F 3 "" H 1800 2350 50  0001 C CNN
	1    1800 2350
	0    1    1    0   
$EndComp
Wire Wire Line
	1800 2250 1700 2250
$Comp
L power:GND #PWR051
U 1 1 5D6D0630
P 1800 2250
F 0 "#PWR051" H 1800 2000 50  0001 C CNN
F 1 "GND" V 1805 2122 50  0000 R CNN
F 2 "" H 1800 2250 50  0001 C CNN
F 3 "" H 1800 2250 50  0001 C CNN
	1    1800 2250
	0    -1   -1   0   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J14
U 1 1 5D6B9829
P 1500 2350
F 0 "J14" H 1418 2025 50  0000 C CNN
F 1 "Power" H 1418 2116 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 1500 2350 50  0001 C CNN
F 3 "~" H 1500 2350 50  0001 C CNN
	1    1500 2350
	-1   0    0    1   
$EndComp
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 5D3B5D6E
P 2750 1000
AR Path="/5D3B5D6E" Ref="J?"  Part="1" 
AR Path="/5D2E6747/5D3B5D6E" Ref="J18"  Part="1" 
F 0 "J18" H 2550 1350 50  0000 L CNN
F 1 "JSN-SR04T" H 2450 1200 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2750 1000 50  0001 C CNN
F 3 "~" H 2750 1000 50  0001 C CNN
	1    2750 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5D3B5D68
P 2350 900
AR Path="/5D3B5D68" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D3B5D68" Ref="#PWR053"  Part="1" 
F 0 "#PWR053" H 2350 750 50  0001 C CNN
F 1 "+5V" H 2365 1073 50  0000 C CNN
F 2 "" H 2350 900 50  0001 C CNN
F 3 "" H 2350 900 50  0001 C CNN
	1    2350 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 900  2550 900 
$Comp
L power:GND #PWR?
U 1 1 5D3B5D61
P 2350 1200
AR Path="/5D3B5D61" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D3B5D61" Ref="#PWR054"  Part="1" 
F 0 "#PWR054" H 2350 950 50  0001 C CNN
F 1 "GND" H 2355 1027 50  0000 C CNN
F 2 "" H 2350 1200 50  0001 C CNN
F 3 "" H 2350 1200 50  0001 C CNN
	1    2350 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	2350 1200 2550 1200
Text GLabel 2450 1000 0    50   Input ~ 0
TRIG3
Text GLabel 2450 1100 0    50   Input ~ 0
ECHO3
Wire Wire Line
	2450 1000 2550 1000
Wire Wire Line
	2450 1100 2550 1100
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 5D3B5D56
P 2000 1000
AR Path="/5D3B5D56" Ref="J?"  Part="1" 
AR Path="/5D2E6747/5D3B5D56" Ref="J17"  Part="1" 
F 0 "J17" H 1800 1350 50  0000 L CNN
F 1 "JSN-SR04T" H 1700 1200 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 2000 1000 50  0001 C CNN
F 3 "~" H 2000 1000 50  0001 C CNN
	1    2000 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5D3B5D50
P 1600 900
AR Path="/5D3B5D50" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D3B5D50" Ref="#PWR049"  Part="1" 
F 0 "#PWR049" H 1600 750 50  0001 C CNN
F 1 "+5V" H 1615 1073 50  0000 C CNN
F 2 "" H 1600 900 50  0001 C CNN
F 3 "" H 1600 900 50  0001 C CNN
	1    1600 900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 900  1800 900 
$Comp
L power:GND #PWR?
U 1 1 5D3B5D49
P 1600 1200
AR Path="/5D3B5D49" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D3B5D49" Ref="#PWR050"  Part="1" 
F 0 "#PWR050" H 1600 950 50  0001 C CNN
F 1 "GND" H 1605 1027 50  0000 C CNN
F 2 "" H 1600 1200 50  0001 C CNN
F 3 "" H 1600 1200 50  0001 C CNN
	1    1600 1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1200 1800 1200
Text GLabel 1700 1000 0    50   Input ~ 0
TRIG2
Text GLabel 1700 1100 0    50   Input ~ 0
ECHO2
Wire Wire Line
	1700 1000 1800 1000
Wire Wire Line
	1700 1100 1800 1100
$Comp
L Connector:Conn_01x04_Female J?
U 1 1 5D3B5D3E
P 1250 1000
AR Path="/5D3B5D3E" Ref="J?"  Part="1" 
AR Path="/5D2E6747/5D3B5D3E" Ref="J13"  Part="1" 
F 0 "J13" H 1050 1350 50  0000 L CNN
F 1 "JSN-SR04T" H 950 1200 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x04_P2.54mm_Vertical" H 1250 1000 50  0001 C CNN
F 3 "~" H 1250 1000 50  0001 C CNN
	1    1250 1000
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR?
U 1 1 5D3B5D38
P 850 900
AR Path="/5D3B5D38" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D3B5D38" Ref="#PWR047"  Part="1" 
F 0 "#PWR047" H 850 750 50  0001 C CNN
F 1 "+5V" H 865 1073 50  0000 C CNN
F 2 "" H 850 900 50  0001 C CNN
F 3 "" H 850 900 50  0001 C CNN
	1    850  900 
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  900  1050 900 
$Comp
L power:GND #PWR?
U 1 1 5D3B5D31
P 850 1200
AR Path="/5D3B5D31" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D3B5D31" Ref="#PWR048"  Part="1" 
F 0 "#PWR048" H 850 950 50  0001 C CNN
F 1 "GND" H 855 1027 50  0000 C CNN
F 2 "" H 850 1200 50  0001 C CNN
F 3 "" H 850 1200 50  0001 C CNN
	1    850  1200
	1    0    0    -1  
$EndComp
Wire Wire Line
	850  1200 1050 1200
Text GLabel 950  1000 0    50   Input ~ 0
TRIG1
Text GLabel 950  1100 0    50   Input ~ 0
ECHO1
Wire Wire Line
	950  1000 1050 1000
Wire Wire Line
	950  1100 1050 1100
Text Notes 1000 1650 0    100  ~ 20
Ultrasonic Sensor
$Comp
L Connector:Screw_Terminal_01x02 J15
U 1 1 5D66EB03
P 1500 2850
F 0 "J15" H 1418 2525 50  0000 C CNN
F 1 "Relay Up" H 1418 2616 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 1500 2850 50  0001 C CNN
F 3 "~" H 1500 2850 50  0001 C CNN
	1    1500 2850
	-1   0    0    1   
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J16
U 1 1 5D66F09C
P 1500 3350
F 0 "J16" H 1418 3025 50  0000 C CNN
F 1 "Relay Back" H 1418 3116 50  0000 C CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x02_P2.54mm_Vertical" H 1500 3350 50  0001 C CNN
F 3 "~" H 1500 3350 50  0001 C CNN
	1    1500 3350
	-1   0    0    1   
$EndComp
Wire Notes Line
	3000 3750 500  3750
Wire Notes Line
	3000 500  3000 3750
$Comp
L Connector:Conn_01x06_Female J20
U 1 1 5D714BE6
P 3800 750
F 0 "J20" V 3738 362 50  0000 R CNN
F 1 "PCA9685" V 3647 362 50  0000 R CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x06_P2.54mm_Vertical" H 3800 750 50  0001 C CNN
F 3 "~" H 3800 750 50  0001 C CNN
	1    3800 750 
	0    -1   -1   0   
$EndComp
$Comp
L power:GND #PWR055
U 1 1 5D715F08
P 3500 1050
F 0 "#PWR055" H 3500 800 50  0001 C CNN
F 1 "GND" V 3505 922 50  0000 R CNN
F 2 "" H 3500 1050 50  0001 C CNN
F 3 "" H 3500 1050 50  0001 C CNN
	1    3500 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	3500 1050 3600 1050
Wire Wire Line
	3600 1050 3600 950 
Wire Wire Line
	3700 950  3700 1050
Wire Wire Line
	3700 1050 3600 1050
Connection ~ 3600 1050
Wire Wire Line
	3800 950  3800 1050
Wire Wire Line
	3900 950  3900 1050
Wire Wire Line
	4000 950  4000 1050
Wire Wire Line
	4000 1050 4050 1050
Wire Wire Line
	4100 1050 4100 950 
Text GLabel 4050 1100 3    50   Input ~ 0
BEC
Wire Wire Line
	4050 1100 4050 1050
Connection ~ 4050 1050
Wire Wire Line
	4050 1050 4100 1050
Text HLabel 3800 1050 3    50   Input ~ 0
SCL
Text HLabel 3900 1050 3    50   Input ~ 0
SDA
$Comp
L Connector:Screw_Terminal_01x02 J19
U 1 1 5D719E57
P 3700 2500
F 0 "J19" H 3618 2175 50  0000 C CNN
F 1 "BEC" H 3618 2266 50  0000 C CNN
F 2 "TerminalBlock_4Ucon:TerminalBlock_4Ucon_1x02_P3.50mm_Vertical" H 3700 2500 50  0001 C CNN
F 3 "~" H 3700 2500 50  0001 C CNN
	1    3700 2500
	-1   0    0    1   
$EndComp
$Comp
L power:GND #PWR057
U 1 1 5D71A40F
P 4050 2500
F 0 "#PWR057" H 4050 2250 50  0001 C CNN
F 1 "GND" V 4055 2372 50  0000 R CNN
F 2 "" H 4050 2500 50  0001 C CNN
F 3 "" H 4050 2500 50  0001 C CNN
	1    4050 2500
	0    -1   -1   0   
$EndComp
Text GLabel 4050 2400 2    50   Input ~ 0
BEC
Wire Wire Line
	3900 2400 3950 2400
Wire Wire Line
	4050 2500 3900 2500
$Comp
L power:+5V #PWR?
U 1 1 5D71C9D0
P 4400 1050
AR Path="/5D71C9D0" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D71C9D0" Ref="#PWR058"  Part="1" 
F 0 "#PWR058" H 4400 900 50  0001 C CNN
F 1 "+5V" H 4415 1223 50  0000 C CNN
F 2 "" H 4400 1050 50  0001 C CNN
F 3 "" H 4400 1050 50  0001 C CNN
	1    4400 1050
	0    1    1    0   
$EndComp
Wire Wire Line
	4400 1050 4300 1050
Connection ~ 4100 1050
$Comp
L power:PWR_FLAG #FLG04
U 1 1 5D71E018
P 4300 1200
F 0 "#FLG04" H 4300 1275 50  0001 C CNN
F 1 "PWR_FLAG" H 4300 1373 50  0000 C CNN
F 2 "" H 4300 1200 50  0001 C CNN
F 3 "~" H 4300 1200 50  0001 C CNN
	1    4300 1200
	-1   0    0    1   
$EndComp
Wire Wire Line
	4300 1200 4300 1050
Connection ~ 4300 1050
Wire Wire Line
	4300 1050 4100 1050
$Comp
L power:+5V #PWR?
U 1 1 5D71EE22
P 3950 2250
AR Path="/5D71EE22" Ref="#PWR?"  Part="1" 
AR Path="/5D2E6747/5D71EE22" Ref="#PWR056"  Part="1" 
F 0 "#PWR056" H 3950 2100 50  0001 C CNN
F 1 "+5V" H 3965 2423 50  0000 C CNN
F 2 "" H 3950 2250 50  0001 C CNN
F 3 "" H 3950 2250 50  0001 C CNN
	1    3950 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3950 2250 3950 2400
Connection ~ 3950 2400
Wire Wire Line
	3950 2400 4050 2400
Text Notes 3400 1650 0    100  ~ 20
PCA9685 Module
Text Notes 3600 2850 0    100  ~ 20
BEC Power
Wire Notes Line
	500  1900 4900 1900
Wire Notes Line
	4900 3050 3000 3050
Wire Notes Line
	4900 500  4900 3050
$EndSCHEMATC
