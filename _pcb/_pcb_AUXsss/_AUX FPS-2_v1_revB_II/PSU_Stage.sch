EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A3 16535 11693
encoding utf-8
Sheet 2 5
Title "FPS-2: Fiber Photometry System"
Date "February 2020"
Rev "v1_revB-I"
Comp "Neurophotometric"
Comment1 ""
Comment2 ""
Comment3 "FPS-2"
Comment4 "OpenEhys"
$EndDescr
Wire Wire Line
	11840 4580 11840 4730
Connection ~ 11840 4580
Wire Wire Line
	10440 5080 10440 4930
Wire Wire Line
	8860 5080 8860 5000
Wire Wire Line
	11840 5080 11840 5030
$Comp
L Device:D_Schottky D?
U 1 1 5D3B6B6D
P 11840 4880
AR Path="/5D3B6B6D" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5D3B6B6D" Ref="D13"  Part="1" 
F 0 "D13" V 11820 4950 50  0000 L CNN
F 1 "ESD9X3.3ST5G" V 11960 4790 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-523" H 11840 4880 50  0001 C CNN
F 3 "~" H 11840 4880 50  0001 C CNN
F 4 "Low Voltage Transil =3V3" V 12030 4810 25  0000 L CNN "Comment"
F 5 "-" H 11840 4880 50  0001 C CNN "Comment2"
F 6 "ESD9X3.3ST5G" H 11840 4880 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 11840 4880 50  0001 C CNN "Provider"
F 8 "863-ESD9X3.3ST5G" H 11840 4880 50  0001 C CNN "ProviderCode"
F 9 "ON Semiconductor" H 11840 4880 50  0001 C CNN "Mnfct"
F 10 "" H 11840 4880 50  0001 C CNN "_footprint"
F 11 "ESD Suppressors / TVS Diodes SOD-923 ESD PROT" H 11840 4880 50  0001 C CNN "Description"
	1    11840 4880
	0    1    1    0   
$EndComp
$Comp
L Regulator_Linear:LD1117S33TR_SOT223 U?
U 1 1 5D3B6B83
P 10990 4580
AR Path="/5D3B6B83" Ref="U?"  Part="1" 
AR Path="/5CC3408E/5D3B6B83" Ref="U24"  Part="1" 
F 0 "U24" H 10840 4830 50  0000 C CNN
F 1 "LD1117S33TR" H 11040 4730 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 10990 4780 50  0001 C CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000544.pdf" H 11090 4330 50  0001 C CNN
F 4 "LDO Vout=3V3; Iout=800mA" H 11215 4955 50  0001 C CNN "Comment"
F 5 "-" H 10990 4580 50  0001 C CNN "Comment2"
F 6 "LD1117S33TR " H 10990 4580 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10990 4580 50  0001 C CNN "Provider"
F 8 "511-LD1117S33" H 10990 4580 50  0001 C CNN "ProviderCode"
F 9 "STMicroelectronics" H 10990 4580 50  0001 C CNN "Mnfct"
F 10 "" H 10990 4580 50  0001 C CNN "_footprint"
F 11 "LDO Voltage Regulators 3.3V 0.8A Positive" H 10990 4580 50  0001 C CNN "Description"
	1    10990 4580
	1    0    0    -1  
$EndComp
Wire Wire Line
	11490 5080 11490 4930
$Comp
L power:+3V3 #PWR?
U 1 1 5D3B6B90
P 12440 4400
AR Path="/5D3B6B90" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5D3B6B90" Ref="#PWR0161"  Part="1" 
F 0 "#PWR0161" H 12440 4250 50  0001 C CNN
F 1 "+3V3" H 12340 4550 50  0000 C CNN
F 2 "" H 12440 4400 50  0001 C CNN
F 3 "" H 12440 4400 50  0001 C CNN
	1    12440 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	11490 4730 11490 4580
$Comp
L Device:CP1_Small C?
U 1 1 5D3B6B9C
P 11490 4830
AR Path="/5D3B6B9C" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D3B6B9C" Ref="C60"  Part="1" 
F 0 "C60" H 11260 4800 50  0000 L CNN
F 1 "10u 10V" H 11250 4690 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-18_Kemet-A" H 11490 4830 50  0001 C CNN
F 3 "~" H 11490 4830 50  0001 C CNN
F 4 "Tantalum Capacitors - 10uF 10volts 20% A Case" H 2940 2880 50  0001 C CNN "Comment"
F 5 "-" H 11490 4830 50  0001 C CNN "Comment2"
F 6 "T55A106M010C0300 " H 11490 4830 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 11490 4830 50  0001 C CNN "Provider"
F 8 "74-T55A106M010C0300" H 11490 4830 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 11490 4830 50  0001 C CNN "Mnfct"
F 10 "" H 11490 4830 50  0001 C CNN "_footprint"
F 11 "Tantalum Capacitors - Polymer SMD 10uF 10volts 20% A Case 300 Max. ESR" H 11490 4830 50  0001 C CNN "Description"
	1    11490 4830
	1    0    0    -1  
$EndComp
$Comp
L Device:CP1_Small C?
U 1 1 5D3B6BAF
P 8860 4900
AR Path="/5D3B6BAF" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D3B6BAF" Ref="C57"  Part="1" 
F 0 "C57" H 8880 4990 50  0000 L CNN
F 1 "10u 10V" H 8710 4820 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-18_Kemet-A" H 8860 4900 50  0001 C CNN
F 3 "~" H 8860 4900 50  0001 C CNN
F 4 "Tantalum Capacitors - 10uF 10volts 20% A Case" H 1810 3000 50  0001 C CNN "Comment"
F 5 "-" H 8860 4900 50  0001 C CNN "Comment2"
F 6 "T55A106M010C0300 " H 8860 4900 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 8860 4900 50  0001 C CNN "Provider"
F 8 "74-T55A106M010C0300" H 8860 4900 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 8860 4900 50  0001 C CNN "Mnfct"
F 10 "" H 8860 4900 50  0001 C CNN "_footprint"
F 11 "Tantalum Capacitors - Polymer SMD 10uF 10volts 20% A Case 300 Max. ESR" H 8860 4900 50  0001 C CNN "Description"
	1    8860 4900
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 5D4485A7
P 4900 3110
AR Path="/5D4485A7" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5D4485A7" Ref="D7"  Part="1" 
F 0 "D7" H 4900 2894 50  0000 C CNN
F 1 "SS14FL" H 4900 2985 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 4900 3110 50  0001 C CNN
F 3 "~" H 4900 3110 50  0001 C CNN
F 4 "-" H 4900 3110 50  0001 C CNN "Comment2"
F 5 "-" H 4900 3110 50  0001 C CNN "Comment"
F 6 "SS14FL " H 4900 3110 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 4900 3110 50  0001 C CNN "Provider"
F 8 "512-SS14FL" H 4900 3110 50  0001 C CNN "ProviderCode"
F 9 "ON Semiconductor" H 4900 3110 50  0001 C CNN "Mnfct"
F 10 "" H 4900 3110 50  0001 C CNN "_footprint"
F 11 "Schottky Diodes & Rectifiers 40V, 1A SCHOTTKY " H 4900 3110 50  0001 C CNN "Description"
	1    4900 3110
	-1   0    0    1   
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5D4485C1
P 8520 5770
AR Path="/5D4485C1" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5D4485C1" Ref="R63"  Part="1" 
F 0 "R63" H 8588 5816 50  0000 L CNN
F 1 "10k" H 8588 5725 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8520 5770 50  0001 C CNN
F 3 "~" H 8520 5770 50  0001 C CNN
F 4 "-" H 8520 5770 50  0001 C CNN "Comment2"
F 5 "-" H 8520 5770 50  0001 C CNN "Comment"
F 6 "RC0603FR-0710KL" H 8520 5770 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 8520 5770 50  0001 C CNN "Provider"
F 8 "603-RC0603FR-0710KL" H 8520 5770 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 8520 5770 50  0001 C CNN "Mnfct"
F 10 "" H 8520 5770 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 10K OHM 1%" H 8520 5770 50  0001 C CNN "Description"
	1    8520 5770
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5D4485C7
P 8520 5320
AR Path="/5D4485C7" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5D4485C7" Ref="R62"  Part="1" 
F 0 "R62" H 8570 5295 50  0000 L CNN
F 1 "52.3k" H 8595 5195 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 8520 5320 50  0001 C CNN
F 3 "~" H 8520 5320 50  0001 C CNN
F 4 "-" H 8520 5320 50  0001 C CNN "Comment2"
F 5 "-" H 8520 5320 50  0001 C CNN "Comment"
F 6 "RC0603FR-0752K3L" H 8520 5320 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 8520 5320 50  0001 C CNN "Provider"
F 8 "603-RC0603FR-0752K3L" H 8520 5320 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 8520 5320 50  0001 C CNN "Mnfct"
F 10 "" H 8520 5320 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 52.3K OHM 1%" H 8520 5320 50  0001 C CNN "Description"
	1    8520 5320
	1    0    0    -1  
$EndComp
Text Notes 3930 5760 2    71   ~ 14
V_In min >8V\n
Text Notes 9360 4460 0    39   ~ 0
Vout=5.0V \nIout=600mA
$Comp
L Device:CP1_Small C?
U 1 1 5D448602
P 5980 5330
AR Path="/5D448602" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D448602" Ref="C51"  Part="1" 
F 0 "C51" H 5750 5360 50  0000 L CNN
F 1 "10u 50V" H 5830 5250 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-7343-20_Kemet-V_Pad2.25x2.55mm_HandSolder" H 5980 5330 50  0001 C CNN
F 3 "~" H 5980 5330 50  0001 C CNN
F 4 "10u 50V 20%" H 1730 3330 50  0001 C CNN "Comment"
F 5 "-" H 5980 5330 50  0001 C CNN "Comment2"
F 6 "T521D106M050ATE090 " H 5980 5330 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 5980 5330 50  0001 C CNN "Provider"
F 8 "80-T521D106M50ATE90" H 5980 5330 50  0001 C CNN "ProviderCode"
F 9 "AVX" H 5980 5330 50  0001 C CNN "Mnfct"
F 10 "" H 5980 5330 50  0001 C CNN "_footprint"
F 11 "Tantalum Capacitors - Polymer SMD 50V 10uF 2917 20% ESR=90mOhms" H 5980 5330 50  0001 C CNN "Description"
	1    5980 5330
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5D448608
P 6330 5330
AR Path="/5D448608" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D448608" Ref="C52"  Part="1" 
F 0 "C52" H 6422 5376 50  0000 L CNN
F 1 "100n" H 6422 5285 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 6330 5330 50  0001 C CNN
F 3 "~" H 6330 5330 50  0001 C CNN
F 4 "-" H 6330 5330 50  0001 C CNN "Comment2"
F 5 "100n 50V" H 6330 5330 50  0001 C CNN "Comment"
F 6 "CC603KRX7R9BB104" H 6330 5330 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 6330 5330 50  0001 C CNN "Provider"
F 8 "603-CC603KRX7R9BB104" H 6330 5330 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 6330 5330 50  0001 C CNN "Mnfct"
F 10 "" H 6330 5330 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 100nF 50V X7R 10%" H 6330 5330 50  0001 C CNN "Description"
F 12 "" H 6330 5330 50  0001 C CNN "PartNumb"
	1    6330 5330
	1    0    0    -1  
$EndComp
$Comp
L Device:L_Small L?
U 1 1 5D44860E
P 8180 5080
AR Path="/5D44860E" Ref="L?"  Part="1" 
AR Path="/5CC3408E/5D44860E" Ref="L1"  Part="1" 
F 0 "L1" V 8270 5110 50  0000 C CNN
F 1 "22uL" V 8260 4940 50  0000 C CNN
F 2 "Inductor_SMD:L_Coilcraft_XAL5030" H 8180 5080 50  0001 C CNN
F 3 "~" H 8180 5080 50  0001 C CNN
F 4 "Fixed Inductors 22uH 20% 830mA" V 8180 5080 50  0001 C CNN "Comment"
F 5 "-" H 8180 5080 50  0001 C CNN "Comment2"
F 6 "IFSC1515AHER220M01 " H 8180 5080 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 8180 5080 50  0001 C CNN "Provider"
F 8 "70-IFSC1515AHER220M0" H 8180 5080 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 8180 5080 50  0001 C CNN "Mnfct"
F 10 "" H 8180 5080 50  0001 C CNN "_footprint"
F 11 "-" H 8180 5080 50  0001 C CNN "Description"
	1    8180 5080
	0    -1   -1   0   
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 5D44861B
P 7940 5260
AR Path="/5D44861B" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5D44861B" Ref="D10"  Part="1" 
F 0 "D10" V 7930 5320 50  0000 L CNN
F 1 "BAT42W-V" V 8050 5290 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-123" H 7940 5260 50  0001 C CNN
F 3 "~" H 7940 5260 50  0001 C CNN
F 4 "ESD Protection Diode" V 7915 5310 25  0001 L CNN "Comment"
F 5 "-" H 7940 5260 50  0001 C CNN "Comment2"
F 6 "BAT42W-G3-08" H 7940 5260 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 7940 5260 50  0001 C CNN "Provider"
F 8 "78-BAT42W-G3-08" H 7940 5260 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 7940 5260 50  0001 C CNN "Mnfct"
F 10 "" H 7940 5260 50  0001 C CNN "_footprint"
F 11 "Schottky Diodes & Rectifiers 30Volt 200mA 4A IFSM" H 7940 5260 50  0001 C CNN "Description"
	1    7940 5260
	0    1    1    0   
$EndComp
$Comp
L Device:D D?
U 1 1 5D448624
P 7850 4550
AR Path="/5D448624" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5D448624" Ref="D9"  Part="1" 
F 0 "D9" H 7850 4766 50  0000 C CNN
F 1 "1N4148W" H 7850 4675 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-123" H 7850 4550 50  0001 C CNN
F 3 "~" H 7850 4550 50  0001 C CNN
F 4 "-" H 7850 4550 50  0001 C CNN "Comment2"
F 5 "Diodes - General Purpose, Power, Switching 100 Volt 500mA 4ns" H 7850 4550 50  0001 C CNN "Comment"
F 6 "1N4148W-E3-18" H 7850 4550 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 7850 4550 50  0001 C CNN "Provider"
F 8 "78-1N4148W-E3-18" H 7850 4550 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 7850 4550 50  0001 C CNN "Mnfct"
F 10 "" H 7850 4550 50  0001 C CNN "_footprint"
F 11 "Diodes - General Purpose, Power, Switching 100 Volt 500mA 4ns" H 7850 4550 50  0001 C CNN "Description"
	1    7850 4550
	1    0    0    -1  
$EndComp
Text Notes 2360 2480 0    118  ~ 24
>>Power Supply Stage
Text GLabel 12110 7350 2    50   Input ~ 0
5V5_LEDS_POWER
Text Label 6100 3100 0    50   ~ 0
FAN_POWER
Text Label 5740 3110 2    50   ~ 0
FAN_POWER
$Comp
L Connector:TestPoint_Probe TP?
U 1 1 5CF53ED6
P 13540 5160
AR Path="/5CF53ED6" Ref="TP?"  Part="1" 
AR Path="/5CC3408E/5CF53ED6" Ref="TP20"  Part="1" 
F 0 "TP20" H 13692 5215 50  0000 L CNN
F 1 "TestPoint_Probe" H 13693 5170 50  0001 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 13740 5160 50  0001 C CNN
F 3 "~" H 13740 5160 50  0001 C CNN
F 4 "-" H 13540 5160 50  0001 C CNN "Comment2"
F 5 "TestPoint" H 13540 5160 50  0001 C CNN "Comment"
F 6 "-" H 13540 5160 50  0001 C CNN "MnfctCode"
F 7 "-" H 13540 5160 50  0001 C CNN "Provider"
F 8 "-" H 13540 5160 50  0001 C CNN "ProviderCode"
F 9 "-" H 13540 5160 50  0001 C CNN "Mnfct"
F 10 "TestPoint" H 13540 5160 50  0001 C CNN "Description"
	1    13540 5160
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_Probe TP?
U 1 1 5CF692B1
P 13940 5160
AR Path="/5CF692B1" Ref="TP?"  Part="1" 
AR Path="/5CC3408E/5CF692B1" Ref="TP22"  Part="1" 
F 0 "TP22" H 14093 5215 50  0000 L CNN
F 1 "TestPoint_Probe" H 14093 5170 50  0001 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 14140 5160 50  0001 C CNN
F 3 "~" H 14140 5160 50  0001 C CNN
F 4 "-" H 13940 5160 50  0001 C CNN "Comment2"
F 5 "GND TP" H 13940 5160 50  0001 C CNN "Comment"
F 6 "-" H 13940 5160 50  0001 C CNN "MnfctCode"
F 7 "-" H 13940 5160 50  0001 C CNN "Provider"
F 8 "-" H 13940 5160 50  0001 C CNN "ProviderCode"
F 9 "-" H 13940 5160 50  0001 C CNN "Mnfct"
F 10 "TestPoint" H 13940 5160 50  0001 C CNN "Description"
	1    13940 5160
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_Probe TP?
U 1 1 5CF69560
P 14340 5160
AR Path="/5CF69560" Ref="TP?"  Part="1" 
AR Path="/5CC3408E/5CF69560" Ref="TP23"  Part="1" 
F 0 "TP23" H 14493 5215 50  0000 L CNN
F 1 "TestPoint_Probe" H 14493 5170 50  0001 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 14540 5160 50  0001 C CNN
F 3 "~" H 14540 5160 50  0001 C CNN
F 4 "-" H 14535 5120 50  0000 C CNN "Comment2"
F 5 "GND TP" H 14340 5160 50  0001 C CNN "Comment"
F 6 "-" H 14340 5160 50  0001 C CNN "MnfctCode"
F 7 "-" H 14340 5160 50  0001 C CNN "Provider"
F 8 "-" H 14340 5160 50  0001 C CNN "ProviderCode"
F 9 "-" H 14340 5160 50  0001 C CNN "Mnfct"
F 10 "TestPoint" H 14340 5160 50  0001 C CNN "Description"
	1    14340 5160
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_Probe TP?
U 1 1 5CF69D48
P 11975 4505
AR Path="/5CF69D48" Ref="TP?"  Part="1" 
AR Path="/5CC3408E/5CF69D48" Ref="TP24"  Part="1" 
F 0 "TP24" H 12000 4500 50  0000 L CNN
F 1 "TestPoint_Probe" H 12128 4515 50  0001 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 12175 4505 50  0001 C CNN
F 3 "~" H 12175 4505 50  0001 C CNN
F 4 "-" H 11930 4630 50  0000 C CNN "Comment2"
F 5 "3V3 TP" H 11975 4505 50  0001 C CNN "Comment"
F 6 "-" H 11975 4505 50  0001 C CNN "MnfctCode"
F 7 "-" H 11975 4505 50  0001 C CNN "Provider"
F 8 "-" H 11975 4505 50  0001 C CNN "ProviderCode"
F 9 "-" H 11975 4505 50  0001 C CNN "Mnfct"
F 10 "TestPoint" H 11975 4505 50  0001 C CNN "Description"
	1    11975 4505
	1    0    0    -1  
$EndComp
Wire Wire Line
	11975 4505 11975 4580
$Comp
L Connector:TestPoint_Probe TP?
U 1 1 5CF7F2A6
P 8970 4430
AR Path="/5CF7F2A6" Ref="TP?"  Part="1" 
AR Path="/5CC3408E/5CF7F2A6" Ref="TP21"  Part="1" 
F 0 "TP21" H 8690 4450 50  0000 L CNN
F 1 "TestPoint_Probe" H 9123 4440 50  0001 L CNN
F 2 "TestPoint:TestPoint_THTPad_D1.0mm_Drill0.5mm" H 9170 4430 50  0001 C CNN
F 3 "~" H 9170 4430 50  0001 C CNN
F 4 "-" H 8850 4530 50  0000 C CNN "Comment2"
F 5 "5V TP" H 8970 4430 50  0001 C CNN "Comment"
F 6 "-" H 8970 4430 50  0001 C CNN "MnfctCode"
F 7 "-" H 8970 4430 50  0001 C CNN "Provider"
F 8 "-" H 8970 4430 50  0001 C CNN "ProviderCode"
F 9 "-" H 8970 4430 50  0001 C CNN "Mnfct"
F 10 "TestPoint" H 8970 4430 50  0001 C CNN "Description"
	1    8970 4430
	1    0    0    -1  
$EndComp
$Comp
L Device:R_Small_US R?
U 1 1 5D3B6B05
P 12440 4770
AR Path="/5D3B6B05" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5D3B6B05" Ref="R66"  Part="1" 
F 0 "R66" H 12500 4770 50  0000 L CNN
F 1 "330R" H 12500 4690 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 12440 4770 50  0001 C CNN
F 3 "~" H 12440 4770 50  0001 C CNN
F 4 "-" H 12440 4770 50  0001 C CNN "Comment2"
F 5 "-" H 12440 4770 50  0001 C CNN "Comment"
F 6 "031-6575" H 12440 4770 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 12440 4770 50  0001 C CNN "Provider"
F 8 "71-CRCW0603330RFKEAC" H 12440 4770 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 12440 4770 50  0001 C CNN "Mnfct"
F 10 "" H 12440 4770 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 220 OHM 1% " H 12440 4770 50  0001 C CNN "Description"
	1    12440 4770
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5D3B6B59
P 10440 4830
AR Path="/5D3B6B59" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D3B6B59" Ref="C59"  Part="1" 
F 0 "C59" H 10210 4820 50  0000 L CNN
F 1 "4.7nF" H 10190 4710 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10440 4830 50  0001 C CNN
F 3 "~" H 10440 4830 50  0001 C CNN
F 4 "-" H 10440 4830 50  0001 C CNN "Comment2"
F 5 "4.7nF 50V X7R 10%" H 10440 4830 50  0001 C CNN "Comment"
F 6 "06035C472KAT2A" H 10440 4830 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10440 4830 50  0001 C CNN "Provider"
F 8 "581-06035C472K" H 10440 4830 50  0001 C CNN "ProviderCode"
F 9 "AVX" H 10440 4830 50  0001 C CNN "Mnfct"
F 10 "" H 10440 4830 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 50V 4700pF X7R 0603 10%" H 10440 4830 50  0001 C CNN "Description"
F 12 "" H 10440 4830 50  0001 C CNN "PartNumb"
	1    10440 4830
	1    0    0    -1  
$EndComp
Wire Wire Line
	11290 4580 11490 4580
Connection ~ 11490 4580
Text Notes 12630 4460 0    39   ~ 0
Vout=3V3\nIout=950mA
Wire Wire Line
	4280 3110 4750 3110
Wire Wire Line
	5050 3110 5740 3110
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5CFE99A6
P 6900 3200
AR Path="/5CFE99A6" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5CFE99A6" Ref="J?"  Part="1" 
AR Path="/61A08F45/5CFE99A6" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5CFE99A6" Ref="J13"  Part="1" 
F 0 "J13" H 6860 3350 50  0000 L CNN
F 1 "DNI" H 6980 3101 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_1x02_P2.54mm_Vertical" H 6900 3200 50  0001 C CNN
F 3 "~" H 6900 3200 50  0001 C CNN
F 4 "Fan extra Power plug" H 6900 3200 50  0001 C CNN "Comment2"
F 5 "1x02_P2.54mm_Vertical; different pitch" H 6900 3200 50  0001 C CNN "Comment"
F 6 "-" H 6900 3200 50  0001 C CNN "MnfctCode"
F 7 "-" H 6900 3200 50  0001 C CNN "Provider"
F 8 "-" H 6900 3200 50  0001 C CNN "ProviderCode"
F 9 "-" H 6900 3200 50  0001 C CNN "Mnfct"
F 10 "" H 6900 3200 50  0001 C CNN "_footprint"
F 11 "-" H 6900 3200 50  0001 C CNN "Description"
	1    6900 3200
	1    0    0    1   
$EndComp
Wire Wire Line
	6600 3260 6600 3200
Text Label 6100 3660 0    50   ~ 0
FAN_POWER
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5D022018
P 6910 3760
AR Path="/5D022018" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5D022018" Ref="J?"  Part="1" 
AR Path="/61A08F45/5D022018" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5D022018" Ref="J14"  Part="1" 
F 0 "J14" H 6850 3910 50  0000 L CNN
F 1 "DNI" H 6990 3661 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_1x02_P2.54mm_Vertical" H 6910 3760 50  0001 C CNN
F 3 "~" H 6910 3760 50  0001 C CNN
F 4 "Fan extra Power plug" H 6910 3760 50  0001 C CNN "Comment2"
F 5 "1x02_P2.54mm_Vertical; different pitch" H 6910 3760 50  0001 C CNN "Comment"
F 6 "-" H 6910 3760 50  0001 C CNN "MnfctCode"
F 7 "-" H 6910 3760 50  0001 C CNN "Provider"
F 8 "-" H 6910 3760 50  0001 C CNN "ProviderCode"
F 9 "-" H 6910 3760 50  0001 C CNN "Mnfct"
F 10 "" H 6910 3760 50  0001 C CNN "_footprint"
F 11 "-" H 6910 3760 50  0001 C CNN "Description"
	1    6910 3760
	1    0    0    1   
$EndComp
Wire Wire Line
	6600 3820 6600 3760
Text Notes 3460 6750 0    50   ~ 0
I_Fans@Vin= 52m*4= 208mA\n\nI_Leds@5V5_LEDs(Vin)=3A max\n\nI_LASER@5V=<200mA <=200mA\nI_LCD@5V=100mA\nI_3V3_Max =  200m uATMEL +15m*2 LEDs+ 35 FTDI ¨= 265mA \n   I@5V=200m+100m+265m=465mA\n\nI_Tot=I_Fans+I_Leds@+I@5V\n        =0.25+3+0.865= 4.1A\n\n
Connection ~ 12440 4580
Wire Wire Line
	11840 4580 11975 4580
Wire Wire Line
	11490 4580 11840 4580
$Comp
L Device:R_Small_US R?
U 1 1 5D1F08B3
P 7550 4730
AR Path="/5D1F08B3" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5D1F08B3" Ref="R67"  Part="1" 
F 0 "R67" V 7620 4780 50  0000 L CNN
F 1 "100R" V 7440 4660 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 7550 4730 50  0001 C CNN
F 3 "~" H 7550 4730 50  0001 C CNN
F 4 "-" H 7550 4730 50  0001 C CNN "Comment2"
F 5 "-" H 7550 4730 50  0001 C CNN "Comment"
F 6 "AC0603FR-13100RL" H 7550 4730 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 7550 4730 50  0001 C CNN "Provider"
F 8 "603-AC0603FR-13100RL" H 7550 4730 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 7550 4730 50  0001 C CNN "Mnfct"
F 10 "" H 7550 4730 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 100 ohm 1% 1/10W AEC-Q200" H 7550 4730 50  0001 C CNN "Description"
	1    7550 4730
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5D1EE465
P 7810 4730
AR Path="/5D1EE465" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D1EE465" Ref="C63"  Part="1" 
F 0 "C63" V 7750 4790 50  0000 L CNN
F 1 "100n" V 7950 4620 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 7810 4730 50  0001 C CNN
F 3 "~" H 7810 4730 50  0001 C CNN
F 4 "-" H 7810 4730 50  0001 C CNN "Comment2"
F 5 "100n 50V" H 7810 4730 50  0001 C CNN "Comment"
F 6 "CC603KRX7R9BB104" H 7810 4730 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 7810 4730 50  0001 C CNN "Provider"
F 8 "603-CC603KRX7R9BB104" H 7810 4730 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 7810 4730 50  0001 C CNN "Mnfct"
F 10 "" H 7810 4730 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 100nF 50V X7R 10%" H 7810 4730 50  0001 C CNN "Description"
F 12 "" H 7810 4730 50  0001 C CNN "PartNumb"
	1    7810 4730
	0    1    1    0   
$EndComp
Wire Wire Line
	7710 4730 7650 4730
Wire Wire Line
	7280 4880 7280 4730
Wire Wire Line
	7280 4550 7700 4550
Wire Wire Line
	7450 4730 7280 4730
Connection ~ 7280 4730
Wire Wire Line
	7280 4730 7280 4550
Wire Wire Line
	8520 5220 8520 5080
Wire Wire Line
	8520 5920 8520 5870
Wire Wire Line
	8520 5580 8520 5420
Wire Wire Line
	8520 5670 8520 5580
Connection ~ 8520 5580
Wire Wire Line
	6330 5470 6330 5430
Wire Wire Line
	5980 5470 5980 5430
Wire Wire Line
	5980 5230 5980 5080
Text Notes 8590 5620 0    39   ~ 0
Vref=0.8V
Wire Wire Line
	9250 4550 9250 4800
Wire Wire Line
	8860 4550 8860 4800
Wire Wire Line
	9250 5000 9250 5080
Connection ~ 8860 4550
Wire Wire Line
	6330 5230 6330 5080
Wire Wire Line
	7180 5830 7180 5730
Wire Wire Line
	7680 5080 7940 5080
Wire Wire Line
	7940 5110 7940 5080
Connection ~ 7940 5080
Wire Wire Line
	7940 5080 8080 5080
Wire Wire Line
	7910 4730 7940 4730
Wire Wire Line
	7940 4730 7940 5080
Wire Wire Line
	8970 4430 8970 4550
Wire Wire Line
	8860 4550 8970 4550
Connection ~ 8970 4550
Wire Wire Line
	8970 4550 9250 4550
Wire Wire Line
	8280 5080 8520 5080
Wire Wire Line
	7680 5580 8520 5580
$Comp
L Device:R_Small_US R?
U 1 1 5F310961
P 6730 5260
AR Path="/5F310961" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5F310961" Ref="R15"  Part="1" 
F 0 "R15" H 6780 5380 50  0000 L CNN
F 1 "1M" H 6790 5270 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 6730 5260 50  0001 C CNN
F 3 "~" H 6730 5260 50  0001 C CNN
F 4 "-" H 6730 5260 50  0001 C CNN "Comment2"
F 5 "-" H 6730 5260 50  0001 C CNN "Comment"
F 6 "RC0603FR-071ML" H 6730 5260 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 6730 5260 50  0001 C CNN "Provider"
F 8 "603-RC0603FR-071ML" H 6730 5260 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 6730 5260 50  0001 C CNN "Mnfct"
F 10 "" H 6730 5260 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 1M OHM 1%" H 6730 5260 50  0001 C CNN "Description"
	1    6730 5260
	1    0    0    -1  
$EndComp
Connection ~ 5980 5080
Connection ~ 6330 5080
Wire Wire Line
	5980 5080 6330 5080
Wire Wire Line
	6330 5080 6730 5080
Wire Wire Line
	6880 5460 6730 5460
Wire Wire Line
	6730 5460 6730 5360
Wire Wire Line
	6730 5160 6730 5080
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5D4BFDEE
P 7300 3200
AR Path="/5D4BFDEE" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5D4BFDEE" Ref="J?"  Part="1" 
AR Path="/61A08F45/5D4BFDEE" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5D4BFDEE" Ref="J12"  Part="1" 
F 0 "J12" H 7250 3320 50  0000 L CNN
F 1 "B2B plug" H 7380 3101 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_M80_1x2_2mmP" H 7300 3200 50  0001 C CNN
F 3 "~" H 7300 3200 50  0001 C CNN
F 4 "-" H 7300 3200 50  0001 C CNN "Comment2"
F 5 "-" H 7300 3200 50  0001 C CNN "Comment"
F 6 "B2B-XH-A-GU" H 7300 3200 50  0001 C CNN "MnfctCode"
F 7 "Digikey" H 7300 3200 50  0001 C CNN "Provider"
F 8 "455-2946-ND" H 7300 3200 50  0001 C CNN "ProviderCode"
F 9 "JST Sales America" H 7300 3200 50  0001 C CNN "Mnfct"
F 10 "" H 7300 3200 50  0001 C CNN "_footprint"
F 11 "CONN HEADER VERT 2POS 2.5MM" H 7300 3200 50  0001 C CNN "Description"
	1    7300 3200
	1    0    0    1   
$EndComp
Wire Wire Line
	6600 3200 6700 3200
Connection ~ 6700 3200
Wire Wire Line
	6700 3200 7100 3200
Wire Wire Line
	6100 3100 6700 3100
Connection ~ 6700 3100
Wire Wire Line
	6700 3100 7100 3100
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5D4E554D
P 7300 3760
AR Path="/5D4E554D" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5D4E554D" Ref="J?"  Part="1" 
AR Path="/61A08F45/5D4E554D" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5D4E554D" Ref="J15"  Part="1" 
F 0 "J15" H 7260 3910 50  0000 L CNN
F 1 "B2B plug" H 7380 3661 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_M80_1x2_2mmP" H 7300 3760 50  0001 C CNN
F 3 "~" H 7300 3760 50  0001 C CNN
F 4 "-" H 7300 3760 50  0001 C CNN "Comment2"
F 5 "-" H 7300 3760 50  0001 C CNN "Comment"
F 6 "B2B-XH-A-GU" H 7300 3760 50  0001 C CNN "MnfctCode"
F 7 "Digikey" H 7300 3760 50  0001 C CNN "Provider"
F 8 "455-2946-ND" H 7300 3760 50  0001 C CNN "ProviderCode"
F 9 "JST Sales America" H 7300 3760 50  0001 C CNN "Mnfct"
F 10 "" H 7300 3760 50  0001 C CNN "_footprint"
F 11 "CONN HEADER VERT 2POS 2.5MM" H 7300 3760 50  0001 C CNN "Description"
	1    7300 3760
	1    0    0    1   
$EndComp
Wire Wire Line
	12440 4580 12440 4670
Wire Wire Line
	12440 4910 12440 4870
$Comp
L Device:LED_ALT D?
U 1 1 5D3B6B0B
P 12440 5060
AR Path="/5D3B6B0B" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5D3B6B0B" Ref="D14"  Part="1" 
F 0 "D14" V 12495 4940 50  0000 R CNN
F 1 "GREEN LED" V 12190 4960 50  0001 R CNN
F 2 "LED_SMD:LED_0603_1608Metric" H 12440 5060 50  0001 C CNN
F 3 "~" H 12440 5060 50  0001 C CNN
F 4 "-" H 12440 5060 50  0001 C CNN "Comment2"
F 5 "Power On LED" V 12395 4670 50  0000 C CNN "Comment"
F 6 "TLMP1100-GS08" H 12440 5060 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 12440 5060 50  0001 C CNN "Provider"
F 8 "78-TLMP1100-GS08" H 12440 5060 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 12440 5060 50  0001 C CNN "Mnfct"
F 10 "" H 12440 5060 50  0001 C CNN "_footprint"
F 11 "-" H 12440 5060 50  0001 C CNN "Description"
	1    12440 5060
	0    -1   -1   0   
$EndComp
Wire Wire Line
	12440 5300 12440 5210
Wire Wire Line
	12440 4400 12440 4580
Connection ~ 11975 4580
Wire Wire Line
	11975 4580 12440 4580
Wire Wire Line
	13540 5260 13540 5160
Wire Wire Line
	13940 5260 13940 5160
Wire Wire Line
	14340 5260 14340 5160
Wire Wire Line
	7940 5410 7940 5430
$Comp
L Device:CP1_Small C?
U 1 1 5D45201F
P 9250 4900
AR Path="/5D45201F" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5D45201F" Ref="C64"  Part="1" 
F 0 "C64" H 9270 5000 50  0000 L CNN
F 1 "10u 10V" H 9100 4825 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-3216-18_Kemet-A" H 9250 4900 50  0001 C CNN
F 3 "~" H 9250 4900 50  0001 C CNN
F 4 "Tantalum Capacitors - 10uF 10volts 20% A Case" H 2200 3000 50  0001 C CNN "Comment"
F 5 "-" H 9250 4900 50  0001 C CNN "Comment2"
F 6 "T55A106M010C0300 " H 9250 4900 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 9250 4900 50  0001 C CNN "Provider"
F 8 "74-T55A106M010C0300" H 9250 4900 50  0001 C CNN "ProviderCode"
F 9 "Vishay" H 9250 4900 50  0001 C CNN "Mnfct"
F 10 "" H 9250 4900 50  0001 C CNN "_footprint"
F 11 "Tantalum Capacitors - Polymer SMD 10uF 10volts 20% A Case 300 Max. ESR" H 9250 4900 50  0001 C CNN "Description"
	1    9250 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 3660 6710 3660
Connection ~ 6710 3660
Wire Wire Line
	6710 3660 7100 3660
Wire Wire Line
	6600 3760 6710 3760
Connection ~ 6710 3760
Wire Wire Line
	6710 3760 7100 3760
Wire Wire Line
	9250 4310 9250 4550
Connection ~ 9250 4550
Wire Wire Line
	6880 5080 6730 5080
Connection ~ 6730 5080
Wire Wire Line
	10990 4880 10990 5080
$Comp
L FPS-2_v1:LT1765 U36
U 1 1 5EBEC5B1
P 9200 7900
F 0 "U36" H 9200 8481 50  0000 C CNN
F 1 "LT1765" H 9200 8390 50  0000 C CNN
F 2 "Package_SO:TSSOP-16-1EP_4.4x5mm_P0.65mm" H 9150 7200 25  0001 C CNN
F 3 "" H 9000 8100 50  0001 C CNN
F 4 "3A Step-Down Regulator ; to LED stage" H 9700 7250 30  0001 C CNN "Comment"
F 5 "Switching Voltage Regulators 3A 1.25 MHz Step-dn Converter" H 9200 7900 50  0001 C CNN "Description"
F 6 "-" H 9200 7900 50  0001 C CNN "Comment2"
F 7 "LT1765EFE#TRPBF" H 9200 7900 50  0001 C CNN "MnfctCode"
F 8 "Mouser" H 9200 7900 50  0001 C CNN "Provider"
F 9 "584-LT1765EFE#TRPBF" H 9200 7900 50  0001 C CNN "ProviderCode"
F 10 "Analog Devices" H 9200 7900 50  0001 C CNN "Mnfct"
	1    9200 7900
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EBEFB29
P 8150 7900
AR Path="/5EBEFB29" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5EBEFB29" Ref="C44"  Part="1" 
F 0 "C44" H 8242 7946 50  0000 L CNN
F 1 "2.2u" H 8242 7855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 8150 7900 50  0001 C CNN
F 3 "~" H 8150 7900 50  0001 C CNN
F 4 "-" H 8150 7900 50  0001 C CNN "Comment2"
F 5 "2.2uF" H 8150 7900 50  0001 C CNN "Comment"
F 6 "GRM188R61E225MA12D " H 8150 7900 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 8150 7900 50  0001 C CNN "Provider"
F 8 "81-GRM188R61E225MA2D" H 8150 7900 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 8150 7900 50  0001 C CNN "Mnfct"
F 10 "" H 8150 7900 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 0603 2.2uF 25volts X5R 20%" H 8150 7900 50  0001 C CNN "Description"
	1    8150 7900
	-1   0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EBF0B7E
P 9650 8650
AR Path="/5EBF0B7E" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5EBF0B7E" Ref="C105"  Part="1" 
F 0 "C105" H 9700 8600 50  0000 L CNN
F 1 "2.2nF" H 9700 8500 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9650 8650 50  0001 C CNN
F 3 "~" H 9650 8650 50  0001 C CNN
F 4 "-" H 9650 8650 50  0001 C CNN "Comment2"
F 5 "2.2n" H 9650 8650 50  0001 C CNN "Comment"
F 6 "C0603C222K3RACTU " H 9650 8650 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 9650 8650 50  0001 C CNN "Provider"
F 8 "80-C0603C222K3R" H 9650 8650 50  0001 C CNN "ProviderCode"
F 9 "KEMET" H 9650 8650 50  0001 C CNN "Mnfct"
F 10 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 25V 2200pF 0603 X7R 10%" H 9650 8650 50  0001 C CNN "Description"
	1    9650 8650
	1    0    0    -1  
$EndComp
$Comp
L Device:L_Small L?
U 1 1 5EBF2199
P 10250 7700
AR Path="/5EBF2199" Ref="L?"  Part="1" 
AR Path="/5CC3408E/5EBF2199" Ref="L2"  Part="1" 
F 0 "L2" V 10190 7770 50  0000 C CNN
F 1 "2.6uL 1A" V 10350 7600 50  0000 C CNN
F 2 "FPS_pads_lib:L_Coilcraft_XAL5030" H 10250 7700 50  0001 C CNN
F 3 "~" H 10250 7700 50  0001 C CNN
F 4 "Low Profile, High Current Inductors" V 10250 7700 50  0001 C CNN "Comment"
F 5 "-" H 10250 7700 50  0001 C CNN "Comment2"
F 6 "SRR5028-2R6Y" H 10250 7700 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10250 7700 50  0001 C CNN "Provider"
F 8 "652-SRR5028-2R6Y" H 10250 7700 50  0001 C CNN "ProviderCode"
F 9 "Bourns" H 10250 7700 50  0001 C CNN "Mnfct"
F 10 "" H 10250 7700 50  0001 C CNN "_footprint"
F 11 "Fixed Inductors 2.6uH 30% SMD 5028" H 10250 7700 50  0001 C CNN "Description"
	1    10250 7700
	0    -1   -1   0   
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EBF8EFE
P 10000 7500
AR Path="/5EBF8EFE" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5EBF8EFE" Ref="C104"  Part="1" 
F 0 "C104" H 9750 7600 50  0000 L CNN
F 1 "180nF" H 9700 7500 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10000 7500 50  0001 C CNN
F 3 "~" H 10000 7500 50  0001 C CNN
F 4 "-" H 10000 7500 50  0001 C CNN "Comment2"
F 5 "-" H 10000 7500 50  0001 C CNN "Comment"
F 6 "GRM188R71E184KA88D" H 10000 7500 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10000 7500 50  0001 C CNN "Provider"
F 8 "81-GRM188R71E184KA8D" H 10000 7500 50  0001 C CNN "ProviderCode"
F 9 "Murata Electronics" H 10000 7500 50  0001 C CNN "Mnfct"
F 10 "" H 10000 7500 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 0.18uF 25Volts X7R 10%" H 10000 7500 50  0001 C CNN "Description"
	1    10000 7500
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5EBFAD3B
P 10950 7550
AR Path="/5EBFAD3B" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5EBFAD3B" Ref="C106"  Part="1" 
F 0 "C106" H 11042 7596 50  0000 L CNN
F 1 "4.7u 16V" H 11042 7505 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 10950 7550 50  0001 C CNN
F 3 "~" H 10950 7550 50  0001 C CNN
F 4 "-" H 10950 7550 50  0001 C CNN "Comment2"
F 5 "Multilayer Ceramic SMD 0603 16V 4.7uF X6S" H 10950 7550 50  0001 C CNN "Comment"
F 6 "C1608X6S1C475K080AC " H 10950 7550 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10950 7550 50  0001 C CNN "Provider"
F 8 "810-C1608X6S1C475K" H 10950 7550 50  0001 C CNN "ProviderCode"
F 9 "TDK" H 10950 7550 50  0001 C CNN "Mnfct"
F 10 "" H 10950 7550 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 0603 16V 4.7uF X6S 10% T: 0.8mm" H 10950 7550 50  0001 C CNN "Description"
	1    10950 7550
	1    0    0    -1  
$EndComp
$Comp
L Device:D D?
U 1 1 5EBFCC36
P 10300 7350
AR Path="/5EBFCC36" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5EBFCC36" Ref="D12"  Part="1" 
F 0 "D12" H 10300 7566 50  0000 C CNN
F 1 "CMDSH-3" H 10300 7475 50  0000 C CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 10300 7350 50  0001 C CNN
F 3 "~" H 10300 7350 50  0001 C CNN
F 4 "-" H 10300 7350 50  0001 C CNN "Comment2"
F 5 "CMDSH-3" H 10300 7350 50  0001 C CNN "Comment"
F 6 "CMDSH-3 TR" H 10300 7350 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10300 7350 50  0001 C CNN "Provider"
F 8 "610-CMDSH-3" H 10300 7350 50  0001 C CNN "ProviderCode"
F 9 "Central Semiconductor" H 10300 7350 50  0001 C CNN "Mnfct"
F 10 "" H 10300 7350 50  0001 C CNN "_footprint"
F 11 "Schottky Diodes & Rectifiers 30V Schottky " H 10300 7350 50  0001 C CNN "Description"
	1    10300 7350
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D?
U 1 1 5EBFF6C1
P 10000 8350
AR Path="/5EBFF6C1" Ref="D?"  Part="1" 
AR Path="/5CC3408E/5EBFF6C1" Ref="D5"  Part="1" 
F 0 "D5" V 9990 8410 50  0000 L CNN
F 1 "MBRM120" V 10110 8380 50  0000 L CNN
F 2 "Diode_SMD:D_Powermite_AK" H 10000 8350 50  0001 C CNN
F 3 "~" H 10000 8350 50  0001 C CNN
F 4 "ESD Protection Diode;" V 9975 8400 25  0001 L CNN "Comment"
F 5 "ref value UPS20 old; update to MBRM120LT3G" H 10000 8350 50  0001 C CNN "Comment2"
F 6 "MBRM120LT3G" H 10000 8350 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10000 8350 50  0001 C CNN "Provider"
F 8 "863-MBRM120LT3G" H 10000 8350 50  0001 C CNN "ProviderCode"
F 9 "On Semiconductor" H 10000 8350 50  0001 C CNN "Mnfct"
F 10 "" H 10000 8350 50  0001 C CNN "_footprint"
F 11 "Schottky Barrier Diodes & Rectifiers 20Volt 1A" H 10000 8350 50  0001 C CNN "Description"
	1    10000 8350
	0    1    1    0   
$EndComp
Wire Wire Line
	8600 7800 8400 7800
Wire Wire Line
	8400 7800 8400 7700
Wire Wire Line
	8400 7700 8600 7700
Wire Wire Line
	8400 7700 8150 7700
Connection ~ 8400 7700
Wire Wire Line
	8150 7800 8150 7700
Wire Wire Line
	9000 8700 9000 8600
Wire Wire Line
	9000 8600 9100 8600
Wire Wire Line
	9450 8600 9450 8500
Connection ~ 9000 8600
Wire Wire Line
	9000 8600 9000 8500
Wire Wire Line
	9100 8500 9100 8600
Connection ~ 9100 8600
Wire Wire Line
	9100 8600 9200 8600
Wire Wire Line
	9200 8500 9200 8600
Connection ~ 9200 8600
Wire Wire Line
	9200 8600 9300 8600
Wire Wire Line
	9300 8500 9300 8600
Connection ~ 9300 8600
Wire Wire Line
	9300 8600 9450 8600
Wire Wire Line
	8150 8100 8150 8000
Wire Wire Line
	9650 8550 9650 8500
Wire Wire Line
	9650 8800 9650 8750
Wire Wire Line
	8500 8350 8500 8200
Wire Wire Line
	8500 8200 8600 8200
Wire Wire Line
	9800 7700 10000 7700
Wire Wire Line
	10000 7700 10000 7800
Wire Wire Line
	10000 7800 9800 7800
Wire Wire Line
	10150 7700 10000 7700
Connection ~ 10000 7700
Wire Wire Line
	10000 7600 10000 7700
Wire Wire Line
	10000 7400 10000 7350
Wire Wire Line
	10000 7350 10150 7350
Wire Wire Line
	10350 7700 10550 7700
Wire Wire Line
	10550 7700 10550 7350
Wire Wire Line
	10550 7350 10450 7350
Wire Wire Line
	9400 7500 9400 7350
Wire Wire Line
	9400 7350 10000 7350
Connection ~ 10000 7350
$Comp
L Device:R_Small_US R?
U 1 1 5EC98BFD
P 10550 8350
AR Path="/5EC98BFD" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5EC98BFD" Ref="R46"  Part="1" 
F 0 "R46" H 10650 8300 50  0000 L CNN
F 1 "10k" H 10650 8200 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 10550 8350 50  0001 C CNN
F 3 "~" H 10550 8350 50  0001 C CNN
F 4 "-" H 10550 8350 50  0001 C CNN "Comment2"
F 5 "-" H 10550 8350 50  0001 C CNN "Comment"
F 6 "RC0603FR-0710KL" H 10550 8350 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10550 8350 50  0001 C CNN "Provider"
F 8 "603-RC0603FR-0710KL" H 10550 8350 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 10550 8350 50  0001 C CNN "Mnfct"
F 10 "" H 10550 8350 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 10K OHM 1%" H 10550 8350 50  0001 C CNN "Description"
	1    10550 8350
	1    0    0    -1  
$EndComp
Text Notes 10750 8250 0    39   ~ 0
Vref=1.2V\nR1=R2(Vout-Vref)/(1.2-R2*0.25e-6)
$Comp
L Device:R_Small_US R?
U 1 1 5ECA9A6D
P 10550 8000
AR Path="/5ECA9A6D" Ref="R?"  Part="1" 
AR Path="/5CC3408E/5ECA9A6D" Ref="R32"  Part="1" 
F 0 "R32" H 10618 8046 50  0000 L CNN
F 1 "36k" H 10618 7955 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric" H 10550 8000 50  0001 C CNN
F 3 "~" H 10550 8000 50  0001 C CNN
F 4 "-" H 10550 8000 50  0001 C CNN "Comment2"
F 5 "calculated value = 35.9k" H 10550 8000 50  0001 C CNN "Comment"
F 6 "ERJ-3EKF3602V" H 10550 8000 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 10550 8000 50  0001 C CNN "Provider"
F 8 "667-ERJ-3EKF3602V" H 10550 8000 50  0001 C CNN "ProviderCode"
F 9 "Panasonic" H 10550 8000 50  0001 C CNN "Mnfct"
F 10 "" H 10550 8000 50  0001 C CNN "_footprint"
F 11 "Thick Film Resistors - SMD 0603 36Kohms 1% AEC-Q200" H 10550 8000 50  0001 C CNN "Description"
	1    10550 8000
	1    0    0    -1  
$EndComp
Wire Wire Line
	10550 8250 10550 8200
Wire Wire Line
	10550 8200 10400 8200
Wire Wire Line
	10400 8200 10400 8050
Wire Wire Line
	10400 8050 9800 8050
Connection ~ 10550 8200
Wire Wire Line
	10550 8200 10550 8100
Wire Wire Line
	10550 8650 10550 8450
Wire Wire Line
	10550 7900 10550 7700
Connection ~ 10550 7700
Wire Wire Line
	10000 7800 10000 8200
Connection ~ 10000 7800
Wire Wire Line
	10000 8550 10000 8500
Wire Wire Line
	5030 5080 5980 5080
Wire Wire Line
	10550 7350 10950 7350
Connection ~ 10550 7350
Wire Wire Line
	10950 7450 10950 7350
Connection ~ 10950 7350
Wire Wire Line
	10950 7350 11650 7350
Wire Wire Line
	10950 7700 10950 7650
Wire Wire Line
	8150 7700 7740 7700
Connection ~ 8150 7700
Connection ~ 4280 4420
Wire Wire Line
	4280 3110 4280 4420
Wire Wire Line
	4280 4420 4280 5080
Wire Wire Line
	4160 4420 4280 4420
Text GLabel 4160 4420 0    50   Input ~ 0
POWER_IN
Text Notes 11310 7250 0    55   ~ 0
Vout=5V5\nIout=3A
$Comp
L FPS-2_v1:MCP16301 U?
U 1 1 5D4485DD
P 7280 5280
AR Path="/5D4485DD" Ref="U?"  Part="1" 
AR Path="/5CC3408E/5D4485DD" Ref="U22"  Part="1" 
F 0 "U22" H 6830 5780 50  0000 C CNN
F 1 "MCP16301" H 6930 5680 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 6830 4580 50  0001 C CNN
F 3 "" H 7080 5480 50  0001 C CNN
F 4 "Switching Controllers 30V Input buck Switching Reg 600 mA" H 7080 4730 50  0001 C CNN "Comment"
F 5 "-" H 7280 5280 50  0001 C CNN "Comment2"
F 6 "MCP16301T-I/CHY" H 7280 5280 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 7280 5280 50  0001 C CNN "Provider"
F 8 "579-MCP16301T-I/CHY" H 7280 5280 50  0001 C CNN "ProviderCode"
F 9 "Microchip" H 7280 5280 50  0001 C CNN "Mnfct"
F 10 "" H 7280 5280 50  0001 C CNN "_footprint"
F 11 "Switching Controllers 30V Input buck Switching Reg 600 mA" H 7280 5280 50  0001 C CNN "Description"
	1    7280 5280
	1    0    0    -1  
$EndComp
NoConn ~ 8600 8000
Text Notes 6850 7030 0    118  ~ 24
> LEDs DC/DC Power 
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5DEB81D3
P 3390 5080
AR Path="/5DEB81D3" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5DEB81D3" Ref="J?"  Part="1" 
AR Path="/61A08F45/5DEB81D3" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5DEB81D3" Ref="PwrIn1"  Part="1" 
F 0 "PwrIn1" H 3350 5230 50  0000 L CNN
F 1 "PowerIn" H 3470 4981 50  0001 L CNN
F 2 "Connector_Phoenix_MC:PhoenixContact_MCV_1,5_2-G-3.5_1x02_P3.50mm_Vertical" H 3390 5080 50  0001 C CNN
F 3 "~" H 3390 5080 50  0001 C CNN
F 4 "-" H 3390 5080 50  0001 C CNN "Comment2"
F 5 "Main Power In" H 3390 5080 50  0001 C CNN "Comment"
F 6 "1843606 " H 3390 5080 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 3390 5080 50  0001 C CNN "Provider"
F 8 "651-1843606" H 3390 5080 50  0001 C CNN "ProviderCode"
F 9 "Phoenix Contact " H 3390 5080 50  0001 C CNN "Mnfct"
F 10 "" H 3390 5080 50  0001 C CNN "_footprint"
F 11 "Pluggable Terminal Blocks 2 Pos 3.5mm pitch Through Hole Header" H 3390 5080 50  0001 C CNN "Description"
	1    3390 5080
	-1   0    0    -1  
$EndComp
Wire Wire Line
	4280 5080 3590 5080
Connection ~ 4280 5080
Wire Wire Line
	3590 5180 3900 5180
Wire Wire Line
	3900 5180 3900 5300
$Comp
L power:+5V #PWR0146
U 1 1 5E56E666
P 9250 4310
F 0 "#PWR0146" H 9250 4160 50  0001 C CNN
F 1 "+5V" H 9265 4483 50  0000 C CNN
F 2 "" H 9250 4310 50  0001 C CNN
F 3 "" H 9250 4310 50  0001 C CNN
	1    9250 4310
	1    0    0    -1  
$EndComp
$Comp
L power:+5V #PWR0142
U 1 1 5FE2AC64
P 10360 4350
F 0 "#PWR0142" H 10360 4200 50  0001 C CNN
F 1 "+5V" H 10375 4523 50  0000 C CNN
F 2 "" H 10360 4350 50  0001 C CNN
F 3 "" H 10360 4350 50  0001 C CNN
	1    10360 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	10360 4350 10360 4580
Wire Wire Line
	10440 4730 10440 4580
Connection ~ 10440 4580
Wire Wire Line
	10440 4580 10690 4580
Wire Wire Line
	10360 4580 10440 4580
Wire Wire Line
	8000 4550 8520 4550
Wire Wire Line
	8520 5080 8520 4550
Connection ~ 8520 5080
Connection ~ 8520 4550
Wire Wire Line
	8520 4550 8860 4550
Text Notes 4750 4390 0    50   ~ 0
>> diodo?? 1A ~ 2A? & ficha para futuro laser
Wire Wire Line
	4280 5080 4730 5080
Text GLabel 7190 7700 0    50   Input ~ 0
POWER_IN
$Comp
L FPS-2_v1:SSB43L-E3 D3
U 1 1 5ECFC07D
P 4880 5080
F 0 "D3" H 4880 4864 50  0000 C CNN
F 1 "SSB43L-E3" H 4880 4955 50  0000 C CNN
F 2 "Diode_SMD:D_SMB" H 4880 4905 50  0001 C CNN
F 3 "" H 4880 5080 50  0001 C CNN
F 4 "-" H 4880 5080 50  0001 C CNN "Comment"
F 5 "Schottky Diodes & Rectifiers 4.0 Amp 30 Volt" H 4880 5080 50  0001 C CNN "Description"
F 6 "SSB43L-E3/52T" H 4880 5080 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 4880 5080 50  0001 C CNN "Provider"
F 8 "625-SSB43L-E3" H 4880 5080 50  0001 C CNN "ProviderCode"
F 9 "-" H 4880 5080 50  0001 C CNN "Comment2"
F 10 "Vishay" H 4880 5080 50  0001 C CNN "Mnfct"
	1    4880 5080
	-1   0    0    1   
$EndComp
$Comp
L FPS-2_v1:SSB43L-E3 D4
U 1 1 5ECFD2BA
P 7590 7700
F 0 "D4" H 7590 7484 50  0000 C CNN
F 1 "SSB43L-E3" H 7590 7575 50  0000 C CNN
F 2 "Diode_SMD:D_SMB" H 7590 7525 50  0001 C CNN
F 3 "" H 7590 7700 50  0001 C CNN
F 4 "-" H 7590 7700 50  0001 C CNN "Comment"
F 5 "Schottky Diodes & Rectifiers 4.0 Amp 30 Volt" H 7590 7700 50  0001 C CNN "Description"
F 6 "SSB43L-E3/52T" H 7590 7700 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 7590 7700 50  0001 C CNN "Provider"
F 8 "625-SSB43L-E3" H 7590 7700 50  0001 C CNN "ProviderCode"
F 9 "-" H 7590 7700 50  0001 C CNN "Comment2"
F 10 "Vishay" H 7590 7700 50  0001 C CNN "Mnfct"
	1    7590 7700
	-1   0    0    1   
$EndComp
Wire Wire Line
	7440 7700 7190 7700
$Comp
L power:GNDD #PWR?
U 1 1 5FF592AD
P 3900 5300
AR Path="/5FF592AD" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF592AD" Ref="#PWR0126"  Part="1" 
AR Path="/5D861EB3/5FF592AD" Ref="#PWR?"  Part="1" 
F 0 "#PWR0126" H 3900 5050 50  0001 C CNN
F 1 "GNDD" H 3840 5160 50  0000 C CNN
F 2 "" H 3900 5300 50  0001 C CNN
F 3 "" H 3900 5300 50  0001 C CNN
	1    3900 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF5D80E
P 5980 5470
AR Path="/5FF5D80E" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF5D80E" Ref="#PWR0127"  Part="1" 
AR Path="/5D861EB3/5FF5D80E" Ref="#PWR?"  Part="1" 
F 0 "#PWR0127" H 5980 5220 50  0001 C CNN
F 1 "GNDD" H 5920 5330 50  0000 C CNN
F 2 "" H 5980 5470 50  0001 C CNN
F 3 "" H 5980 5470 50  0001 C CNN
	1    5980 5470
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF61E26
P 6330 5470
AR Path="/5FF61E26" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF61E26" Ref="#PWR0129"  Part="1" 
AR Path="/5D861EB3/5FF61E26" Ref="#PWR?"  Part="1" 
F 0 "#PWR0129" H 6330 5220 50  0001 C CNN
F 1 "GNDD" H 6270 5330 50  0000 C CNN
F 2 "" H 6330 5470 50  0001 C CNN
F 3 "" H 6330 5470 50  0001 C CNN
	1    6330 5470
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF6644A
P 7180 5830
AR Path="/5FF6644A" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF6644A" Ref="#PWR0134"  Part="1" 
AR Path="/5D861EB3/5FF6644A" Ref="#PWR?"  Part="1" 
F 0 "#PWR0134" H 7180 5580 50  0001 C CNN
F 1 "GNDD" H 7120 5690 50  0000 C CNN
F 2 "" H 7180 5830 50  0001 C CNN
F 3 "" H 7180 5830 50  0001 C CNN
	1    7180 5830
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF6AA32
P 6600 3260
AR Path="/5FF6AA32" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF6AA32" Ref="#PWR0135"  Part="1" 
AR Path="/5D861EB3/5FF6AA32" Ref="#PWR?"  Part="1" 
F 0 "#PWR0135" H 6600 3010 50  0001 C CNN
F 1 "GNDD" H 6540 3120 50  0000 C CNN
F 2 "" H 6600 3260 50  0001 C CNN
F 3 "" H 6600 3260 50  0001 C CNN
	1    6600 3260
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF6EFD5
P 6600 3820
AR Path="/5FF6EFD5" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF6EFD5" Ref="#PWR0136"  Part="1" 
AR Path="/5D861EB3/5FF6EFD5" Ref="#PWR?"  Part="1" 
F 0 "#PWR0136" H 6600 3570 50  0001 C CNN
F 1 "GNDD" H 6540 3680 50  0000 C CNN
F 2 "" H 6600 3820 50  0001 C CNN
F 3 "" H 6600 3820 50  0001 C CNN
	1    6600 3820
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF7377A
P 7940 5430
AR Path="/5FF7377A" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF7377A" Ref="#PWR0138"  Part="1" 
AR Path="/5D861EB3/5FF7377A" Ref="#PWR?"  Part="1" 
F 0 "#PWR0138" H 7940 5180 50  0001 C CNN
F 1 "GNDD" H 7880 5290 50  0000 C CNN
F 2 "" H 7940 5430 50  0001 C CNN
F 3 "" H 7940 5430 50  0001 C CNN
	1    7940 5430
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF77E37
P 8520 5920
AR Path="/5FF77E37" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF77E37" Ref="#PWR0140"  Part="1" 
AR Path="/5D861EB3/5FF77E37" Ref="#PWR?"  Part="1" 
F 0 "#PWR0140" H 8520 5670 50  0001 C CNN
F 1 "GNDD" H 8460 5780 50  0000 C CNN
F 2 "" H 8520 5920 50  0001 C CNN
F 3 "" H 8520 5920 50  0001 C CNN
	1    8520 5920
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF7C496
P 8860 5080
AR Path="/5FF7C496" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF7C496" Ref="#PWR0141"  Part="1" 
AR Path="/5D861EB3/5FF7C496" Ref="#PWR?"  Part="1" 
F 0 "#PWR0141" H 8860 4830 50  0001 C CNN
F 1 "GNDD" H 8800 4940 50  0000 C CNN
F 2 "" H 8860 5080 50  0001 C CNN
F 3 "" H 8860 5080 50  0001 C CNN
	1    8860 5080
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF80C7A
P 9250 5080
AR Path="/5FF80C7A" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF80C7A" Ref="#PWR0143"  Part="1" 
AR Path="/5D861EB3/5FF80C7A" Ref="#PWR?"  Part="1" 
F 0 "#PWR0143" H 9250 4830 50  0001 C CNN
F 1 "GNDD" H 9190 4940 50  0000 C CNN
F 2 "" H 9250 5080 50  0001 C CNN
F 3 "" H 9250 5080 50  0001 C CNN
	1    9250 5080
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF853AC
P 13540 5260
AR Path="/5FF853AC" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF853AC" Ref="#PWR0145"  Part="1" 
AR Path="/5D861EB3/5FF853AC" Ref="#PWR?"  Part="1" 
F 0 "#PWR0145" H 13540 5010 50  0001 C CNN
F 1 "GNDD" H 13480 5120 50  0000 C CNN
F 2 "" H 13540 5260 50  0001 C CNN
F 3 "" H 13540 5260 50  0001 C CNN
	1    13540 5260
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF89A2B
P 13940 5260
AR Path="/5FF89A2B" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF89A2B" Ref="#PWR0147"  Part="1" 
AR Path="/5D861EB3/5FF89A2B" Ref="#PWR?"  Part="1" 
F 0 "#PWR0147" H 13940 5010 50  0001 C CNN
F 1 "GNDD" H 13880 5120 50  0000 C CNN
F 2 "" H 13940 5260 50  0001 C CNN
F 3 "" H 13940 5260 50  0001 C CNN
	1    13940 5260
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF8E1DF
P 14340 5260
AR Path="/5FF8E1DF" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF8E1DF" Ref="#PWR0149"  Part="1" 
AR Path="/5D861EB3/5FF8E1DF" Ref="#PWR?"  Part="1" 
F 0 "#PWR0149" H 14340 5010 50  0001 C CNN
F 1 "GNDD" H 14280 5120 50  0000 C CNN
F 2 "" H 14340 5260 50  0001 C CNN
F 3 "" H 14340 5260 50  0001 C CNN
	1    14340 5260
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF929A2
P 10440 5080
AR Path="/5FF929A2" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF929A2" Ref="#PWR0150"  Part="1" 
AR Path="/5D861EB3/5FF929A2" Ref="#PWR?"  Part="1" 
F 0 "#PWR0150" H 10440 4830 50  0001 C CNN
F 1 "GNDD" H 10380 4940 50  0000 C CNN
F 2 "" H 10440 5080 50  0001 C CNN
F 3 "" H 10440 5080 50  0001 C CNN
	1    10440 5080
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF96FFD
P 10990 5080
AR Path="/5FF96FFD" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF96FFD" Ref="#PWR0153"  Part="1" 
AR Path="/5D861EB3/5FF96FFD" Ref="#PWR?"  Part="1" 
F 0 "#PWR0153" H 10990 4830 50  0001 C CNN
F 1 "GNDD" H 10930 4940 50  0000 C CNN
F 2 "" H 10990 5080 50  0001 C CNN
F 3 "" H 10990 5080 50  0001 C CNN
	1    10990 5080
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF9B629
P 11490 5080
AR Path="/5FF9B629" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF9B629" Ref="#PWR0154"  Part="1" 
AR Path="/5D861EB3/5FF9B629" Ref="#PWR?"  Part="1" 
F 0 "#PWR0154" H 11490 4830 50  0001 C CNN
F 1 "GNDD" H 11430 4940 50  0000 C CNN
F 2 "" H 11490 5080 50  0001 C CNN
F 3 "" H 11490 5080 50  0001 C CNN
	1    11490 5080
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FF9FBEB
P 11840 5080
AR Path="/5FF9FBEB" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FF9FBEB" Ref="#PWR0155"  Part="1" 
AR Path="/5D861EB3/5FF9FBEB" Ref="#PWR?"  Part="1" 
F 0 "#PWR0155" H 11840 4830 50  0001 C CNN
F 1 "GNDD" H 11780 4940 50  0000 C CNN
F 2 "" H 11840 5080 50  0001 C CNN
F 3 "" H 11840 5080 50  0001 C CNN
	1    11840 5080
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFA41A2
P 12440 5300
AR Path="/5FFA41A2" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFA41A2" Ref="#PWR0156"  Part="1" 
AR Path="/5D861EB3/5FFA41A2" Ref="#PWR?"  Part="1" 
F 0 "#PWR0156" H 12440 5050 50  0001 C CNN
F 1 "GNDD" H 12380 5160 50  0000 C CNN
F 2 "" H 12440 5300 50  0001 C CNN
F 3 "" H 12440 5300 50  0001 C CNN
	1    12440 5300
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFA9AA5
P 8150 8100
AR Path="/5FFA9AA5" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFA9AA5" Ref="#PWR0158"  Part="1" 
AR Path="/5D861EB3/5FFA9AA5" Ref="#PWR?"  Part="1" 
F 0 "#PWR0158" H 8150 7850 50  0001 C CNN
F 1 "GNDD" H 8090 7960 50  0000 C CNN
F 2 "" H 8150 8100 50  0001 C CNN
F 3 "" H 8150 8100 50  0001 C CNN
	1    8150 8100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFAE125
P 8500 8350
AR Path="/5FFAE125" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFAE125" Ref="#PWR0159"  Part="1" 
AR Path="/5D861EB3/5FFAE125" Ref="#PWR?"  Part="1" 
F 0 "#PWR0159" H 8500 8100 50  0001 C CNN
F 1 "GNDD" H 8440 8210 50  0000 C CNN
F 2 "" H 8500 8350 50  0001 C CNN
F 3 "" H 8500 8350 50  0001 C CNN
	1    8500 8350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFB289E
P 9000 8700
AR Path="/5FFB289E" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFB289E" Ref="#PWR0162"  Part="1" 
AR Path="/5D861EB3/5FFB289E" Ref="#PWR?"  Part="1" 
F 0 "#PWR0162" H 9000 8450 50  0001 C CNN
F 1 "GNDD" H 8940 8560 50  0000 C CNN
F 2 "" H 9000 8700 50  0001 C CNN
F 3 "" H 9000 8700 50  0001 C CNN
	1    9000 8700
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFB6E74
P 9650 8800
AR Path="/5FFB6E74" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFB6E74" Ref="#PWR0165"  Part="1" 
AR Path="/5D861EB3/5FFB6E74" Ref="#PWR?"  Part="1" 
F 0 "#PWR0165" H 9650 8550 50  0001 C CNN
F 1 "GNDD" H 9590 8660 50  0000 C CNN
F 2 "" H 9650 8800 50  0001 C CNN
F 3 "" H 9650 8800 50  0001 C CNN
	1    9650 8800
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFBB4B8
P 10000 8550
AR Path="/5FFBB4B8" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFBB4B8" Ref="#PWR0167"  Part="1" 
AR Path="/5D861EB3/5FFBB4B8" Ref="#PWR?"  Part="1" 
F 0 "#PWR0167" H 10000 8300 50  0001 C CNN
F 1 "GNDD" H 10080 8400 50  0000 C CNN
F 2 "" H 10000 8550 50  0001 C CNN
F 3 "" H 10000 8550 50  0001 C CNN
	1    10000 8550
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5FFBFA7E
P 10550 8650
AR Path="/5FFBFA7E" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5FFBFA7E" Ref="#PWR0168"  Part="1" 
AR Path="/5D861EB3/5FFBFA7E" Ref="#PWR?"  Part="1" 
F 0 "#PWR0168" H 10550 8400 50  0001 C CNN
F 1 "GNDD" H 10490 8510 50  0000 C CNN
F 2 "" H 10550 8650 50  0001 C CNN
F 3 "" H 10550 8650 50  0001 C CNN
	1    10550 8650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 60C76C0B
P 10950 7700
AR Path="/60C76C0B" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/60C76C0B" Ref="#PWR0347"  Part="1" 
AR Path="/5D861EB3/60C76C0B" Ref="#PWR?"  Part="1" 
F 0 "#PWR0347" H 10950 7450 50  0001 C CNN
F 1 "GNDD" H 10890 7560 50  0000 C CNN
F 2 "" H 10950 7700 50  0001 C CNN
F 3 "" H 10950 7700 50  0001 C CNN
	1    10950 7700
	1    0    0    -1  
$EndComp
$Comp
L Connector:TestPoint_Probe TP?
U 1 1 5E2552AC
P 13500 5820
AR Path="/5E2552AC" Ref="TP?"  Part="1" 
AR Path="/5CC3408E/5E2552AC" Ref="SHLD1"  Part="1" 
F 0 "SHLD1" H 13652 5875 50  0000 L CNN
F 1 "TestPoint_Probe" H 13653 5830 50  0001 L CNN
F 2 "MountingHole:MountingHole_3mm_Pad_Via" H 13700 5820 50  0001 C CNN
F 3 "~" H 13700 5820 50  0001 C CNN
F 4 "-" H 13500 5820 50  0001 C CNN "Comment2"
F 5 "-" H 13500 5820 50  0001 C CNN "Comment"
F 6 "-" H 13500 5820 50  0001 C CNN "MnfctCode"
F 7 "-" H 13500 5820 50  0001 C CNN "Provider"
F 8 "-" H 13500 5820 50  0001 C CNN "ProviderCode"
F 9 "-" H 13500 5820 50  0001 C CNN "Mnfct"
F 10 "-" H 13500 5820 50  0001 C CNN "Description"
	1    13500 5820
	1    0    0    -1  
$EndComp
Wire Wire Line
	13500 5920 13500 5820
$Comp
L power:GNDD #PWR?
U 1 1 5E2552B3
P 13500 5920
AR Path="/5E2552B3" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5E2552B3" Ref="#PWR020"  Part="1" 
AR Path="/5D861EB3/5E2552B3" Ref="#PWR?"  Part="1" 
F 0 "#PWR020" H 13500 5670 50  0001 C CNN
F 1 "GNDD" H 13440 5780 50  0000 C CNN
F 2 "MountingHole:MountingHole_3mm_Pad_Via" H 13500 5920 50  0001 C CNN
F 3 "" H 13500 5920 50  0001 C CNN
	1    13500 5920
	1    0    0    -1  
$EndComp
$Comp
L Device:C_Small C?
U 1 1 5E437A6E
P 9500 4900
AR Path="/5E437A6E" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5E437A6E" Ref="C55"  Part="1" 
F 0 "C55" H 9545 5065 50  0000 L CNN
F 1 "100n" H 9570 4840 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric" H 9500 4900 50  0001 C CNN
F 3 "~" H 9500 4900 50  0001 C CNN
F 4 "-" H 9500 4900 50  0001 C CNN "Comment2"
F 5 "100n 50V" H 9500 4900 50  0001 C CNN "Comment"
F 6 "CC603KRX7R9BB104" H 9500 4900 50  0001 C CNN "MnfctCode"
F 7 "Mouser" H 9500 4900 50  0001 C CNN "Provider"
F 8 "603-CC603KRX7R9BB104" H 9500 4900 50  0001 C CNN "ProviderCode"
F 9 "Yageo" H 9500 4900 50  0001 C CNN "Mnfct"
F 10 "" H 9500 4900 50  0001 C CNN "_footprint"
F 11 "Multilayer Ceramic Capacitors MLCC - SMD/SMT 100nF 50V X7R 10%" H 9500 4900 50  0001 C CNN "Description"
F 12 "" H 9500 4900 50  0001 C CNN "PartNumb"
	1    9500 4900
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5E43D47D
P 9500 5075
AR Path="/5E43D47D" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5E43D47D" Ref="#PWR028"  Part="1" 
AR Path="/5D861EB3/5E43D47D" Ref="#PWR?"  Part="1" 
F 0 "#PWR028" H 9500 4825 50  0001 C CNN
F 1 "GNDD" H 9440 4935 50  0000 C CNN
F 2 "" H 9500 5075 50  0001 C CNN
F 3 "" H 9500 5075 50  0001 C CNN
	1    9500 5075
	1    0    0    -1  
$EndComp
Wire Wire Line
	9500 5075 9500 5000
Wire Wire Line
	9500 4800 9500 4550
Wire Wire Line
	9500 4550 9250 4550
Text Label 7500 3100 0    50   ~ 0
FAN_POWER
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5E486C8D
P 8300 3200
AR Path="/5E486C8D" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5E486C8D" Ref="J?"  Part="1" 
AR Path="/61A08F45/5E486C8D" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5E486C8D" Ref="J22"  Part="1" 
F 0 "J22" H 8260 3350 50  0000 L CNN
F 1 "DNI" H 8380 3101 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_1x02_P2.54mm_Vertical" H 8300 3200 50  0001 C CNN
F 3 "~" H 8300 3200 50  0001 C CNN
F 4 "Fan extra Power plug" H 8300 3200 50  0001 C CNN "Comment2"
F 5 "1x02_P2.54mm_Vertical; different pitch" H 8300 3200 50  0001 C CNN "Comment"
F 6 "-" H 8300 3200 50  0001 C CNN "MnfctCode"
F 7 "-" H 8300 3200 50  0001 C CNN "Provider"
F 8 "-" H 8300 3200 50  0001 C CNN "ProviderCode"
F 9 "-" H 8300 3200 50  0001 C CNN "Mnfct"
F 10 "" H 8300 3200 50  0001 C CNN "_footprint"
F 11 "-" H 8300 3200 50  0001 C CNN "Description"
	1    8300 3200
	1    0    0    1   
$EndComp
Wire Wire Line
	8000 3260 8000 3200
Text Label 7500 3660 0    50   ~ 0
FAN_POWER
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5E486C9D
P 8310 3760
AR Path="/5E486C9D" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5E486C9D" Ref="J?"  Part="1" 
AR Path="/61A08F45/5E486C9D" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5E486C9D" Ref="J23"  Part="1" 
F 0 "J23" H 8250 3910 50  0000 L CNN
F 1 "DNI" H 8390 3661 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_1x02_P2.54mm_Vertical" H 8310 3760 50  0001 C CNN
F 3 "~" H 8310 3760 50  0001 C CNN
F 4 "Fan extra Power plug" H 8310 3760 50  0001 C CNN "Comment2"
F 5 "1x02_P2.54mm_Vertical; different pitch" H 8310 3760 50  0001 C CNN "Comment"
F 6 "-" H 8310 3760 50  0001 C CNN "MnfctCode"
F 7 "-" H 8310 3760 50  0001 C CNN "Provider"
F 8 "-" H 8310 3760 50  0001 C CNN "ProviderCode"
F 9 "-" H 8310 3760 50  0001 C CNN "Mnfct"
F 10 "" H 8310 3760 50  0001 C CNN "_footprint"
F 11 "-" H 8310 3760 50  0001 C CNN "Description"
	1    8310 3760
	1    0    0    1   
$EndComp
Wire Wire Line
	8000 3820 8000 3760
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5E486CAC
P 8700 3200
AR Path="/5E486CAC" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5E486CAC" Ref="J?"  Part="1" 
AR Path="/61A08F45/5E486CAC" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5E486CAC" Ref="J24"  Part="1" 
F 0 "J24" H 8650 3320 50  0000 L CNN
F 1 "B2B plug" H 8780 3101 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_M80_1x2_2mmP" H 8700 3200 50  0001 C CNN
F 3 "~" H 8700 3200 50  0001 C CNN
F 4 "-" H 8700 3200 50  0001 C CNN "Comment2"
F 5 "-" H 8700 3200 50  0001 C CNN "Comment"
F 6 "B2B-XH-A-GU" H 8700 3200 50  0001 C CNN "MnfctCode"
F 7 "Digikey" H 8700 3200 50  0001 C CNN "Provider"
F 8 "455-2946-ND" H 8700 3200 50  0001 C CNN "ProviderCode"
F 9 "JST Sales America" H 8700 3200 50  0001 C CNN "Mnfct"
F 10 "" H 8700 3200 50  0001 C CNN "_footprint"
F 11 "CONN HEADER VERT 2POS 2.5MM" H 8700 3200 50  0001 C CNN "Description"
	1    8700 3200
	1    0    0    1   
$EndComp
Wire Wire Line
	8000 3200 8100 3200
Connection ~ 8100 3200
Wire Wire Line
	8100 3200 8500 3200
Wire Wire Line
	7500 3100 8100 3100
Connection ~ 8100 3100
Wire Wire Line
	8100 3100 8500 3100
$Comp
L Connector_Generic:Conn_01x02 J?
U 1 1 5E486CC0
P 8700 3760
AR Path="/5E486CC0" Ref="J?"  Part="1" 
AR Path="/5DF02BCA/5E486CC0" Ref="J?"  Part="1" 
AR Path="/61A08F45/5E486CC0" Ref="J?"  Part="1" 
AR Path="/5CC3408E/5E486CC0" Ref="J25"  Part="1" 
F 0 "J25" H 8660 3910 50  0000 L CNN
F 1 "B2B plug" H 8780 3661 50  0001 L CNN
F 2 "FPS_pads_lib:my_PinHeader_M80_1x2_2mmP" H 8700 3760 50  0001 C CNN
F 3 "~" H 8700 3760 50  0001 C CNN
F 4 "-" H 8700 3760 50  0001 C CNN "Comment2"
F 5 "-" H 8700 3760 50  0001 C CNN "Comment"
F 6 "B2B-XH-A-GU" H 8700 3760 50  0001 C CNN "MnfctCode"
F 7 "Digikey" H 8700 3760 50  0001 C CNN "Provider"
F 8 "455-2946-ND" H 8700 3760 50  0001 C CNN "ProviderCode"
F 9 "JST Sales America" H 8700 3760 50  0001 C CNN "Mnfct"
F 10 "" H 8700 3760 50  0001 C CNN "_footprint"
F 11 "CONN HEADER VERT 2POS 2.5MM" H 8700 3760 50  0001 C CNN "Description"
	1    8700 3760
	1    0    0    1   
$EndComp
Wire Wire Line
	7500 3660 8110 3660
Connection ~ 8110 3660
Wire Wire Line
	8110 3660 8500 3660
Wire Wire Line
	8000 3760 8110 3760
Connection ~ 8110 3760
Wire Wire Line
	8110 3760 8500 3760
$Comp
L power:GNDD #PWR?
U 1 1 5E486CCC
P 8000 3260
AR Path="/5E486CCC" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5E486CCC" Ref="#PWR031"  Part="1" 
AR Path="/5D861EB3/5E486CCC" Ref="#PWR?"  Part="1" 
F 0 "#PWR031" H 8000 3010 50  0001 C CNN
F 1 "GNDD" H 7940 3120 50  0000 C CNN
F 2 "" H 8000 3260 50  0001 C CNN
F 3 "" H 8000 3260 50  0001 C CNN
	1    8000 3260
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5E486CD2
P 8000 3820
AR Path="/5E486CD2" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5E486CD2" Ref="#PWR032"  Part="1" 
AR Path="/5D861EB3/5E486CD2" Ref="#PWR?"  Part="1" 
F 0 "#PWR032" H 8000 3570 50  0001 C CNN
F 1 "GNDD" H 7940 3680 50  0000 C CNN
F 2 "" H 8000 3820 50  0001 C CNN
F 3 "" H 8000 3820 50  0001 C CNN
	1    8000 3820
	1    0    0    -1  
$EndComp
Text Notes 6060 2840 0    50   ~ 0
>>I_FAN\n  @6V => I_FAN=35mA\n  @9V => I_FAN=52mA
Text Notes -2650 6280 0    50   ~ 0
I_LCD@5V=100mA\nI_Leds@9V=1.5A x4 = 6A peak\nI_Fans@9V ¨= 250mA \nI_3V3_Max =  200 uATMEL +50 LEDs+ 35 FTDI ¨= 300mA \n=> I_5V ¨=300mA \n\n=> I_9V ¨= 100mA \n\n=> I_Max_@9V= 6+0.25+0.1 ¨= 6.4A   Worst-Case-Scenario!!!\n
$Comp
L Device:CP1_Small C?
U 1 1 5E8A1BD6
P 11650 7550
AR Path="/5E8A1BD6" Ref="C?"  Part="1" 
AR Path="/5CC3408E/5E8A1BD6" Ref="C129"  Part="1" 
F 0 "C129" H 11780 7570 50  0000 L CNN
F 1 "100uF 25V" H 11790 7480 50  0000 L CNN
F 2 "Capacitor_Tantalum_SMD:CP_EIA-6032-28_Kemet-C" H 11650 7550 50  0001 C CNN
F 3 "~" H 11650 7550 50  0001 C CNN
F 4 "Tantalum Capacitors - Solid SMD 16V 100uF 20% ESR=200mOhm" H 4600 5650 50  0001 C CNN "Comment"
F 5 "-" H 11650 7550 50  0001 C CNN "Comment2"
F 6 "AVX" H 11650 7550 50  0001 C CNN "Mnfct"
F 7 "TPSC107M016S0200" H 11650 7550 50  0001 C CNN "MnfctCode"
F 8 "Mouser" H 11650 7550 50  0001 C CNN "Provider"
F 9 "581-TPSC107M016S0200" H 11650 7550 50  0001 C CNN "ProviderCode"
F 10 "" H 11650 7550 50  0001 C CNN "_footprint"
F 11 "-" H 11650 7550 50  0001 C CNN "Description"
	1    11650 7550
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR?
U 1 1 5E8AF29E
P 11650 7720
AR Path="/5E8AF29E" Ref="#PWR?"  Part="1" 
AR Path="/5CC3408E/5E8AF29E" Ref="#PWR053"  Part="1" 
AR Path="/5D861EB3/5E8AF29E" Ref="#PWR?"  Part="1" 
F 0 "#PWR053" H 11650 7470 50  0001 C CNN
F 1 "GNDD" H 11590 7580 50  0000 C CNN
F 2 "" H 11650 7720 50  0001 C CNN
F 3 "" H 11650 7720 50  0001 C CNN
	1    11650 7720
	1    0    0    -1  
$EndComp
Wire Wire Line
	11650 7720 11650 7650
Wire Wire Line
	11650 7450 11650 7350
Connection ~ 11650 7350
Wire Wire Line
	11650 7350 12110 7350
$EndSCHEMATC
