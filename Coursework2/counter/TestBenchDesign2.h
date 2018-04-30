#include "systemc.h"

SC_MODULE(TestBenchDesign2){
	sc_out<bool> reset, enable;

	void testprocess(){
		enable.write(false);
		reset.write(false);
		wait(10, SC_NS);
		
		enable.write(true);
		reset.write(true);
		wait(10, SC_NS);
		
		enable.write(true);
		reset.write(false);
		wait(10, SC_NS);
		
		enable.write(false);
		reset.write(true);
		wait(10, SC_NS);

		enable.write(false);
		reset.write(false);
		wait(10, SC_NS);
		
		}
	
	SC_CTOR(TestBenchDesign2) { 
		SC_THREAD(testprocess);
	} 
};

