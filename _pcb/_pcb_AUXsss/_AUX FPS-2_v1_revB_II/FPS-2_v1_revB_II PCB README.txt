
>> FPS-2_v1_revB_I



* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* @ March 5th 2020
>> Built 	FPS-2_v1_revB_II
	. 
	- new R-pull-up 		R3 100k  rail clock-in
	- new C on C_5V.5V	C129 		
	- some components moved

	- new C129 => 100uF-16V	tantalum 		Mouser	581-TPSC107M016S0200
		&
	-moved C106
	
	- new R3=100k ; Mouser 603-RC0603FR-07100KL
			&
	- moved R5

		

* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* @ March 5th 2020

>> changes from last fabrication outputs @February 27th
	- Removed Components - DNI
			- U7 gets to DNI
			- Cs gets to DNI		C97, C103, C96, C102, C87, C85, C33, C123, C126, C122, C125, C119, C124, 
			- Rs gets to DNI		R16, R61, R57, R34, R55, R90, R43, 
			
	- New Components or Modified
			.R3 
				. Modified - gets to be a Ferrite 
					.FB3=100R/100MHz; 
					.ref	81-BLM18KG601SN1D
					. same footprint
			- J4, J16, J11, J10  
					. New components 
						. manufacturer code M80-8820242
						. through hole
			- U33 
					. Modified - changes code:	
						.WAS TCR2LF18LMCT; 
						. IS TCR2EF18LMCT; 
						. same footprint
			- J12, J15, J24, J25, 	
					. New Components
						. Fan plugs; 
					. 	FAN plugs still to decide manufaturer code; 
						.through hole
						. same footprint

			