#include "systemc.h"

SC_MODULE(TestbenchDesign1){ 
	sc_out<sc_logic> TA, TB, TCin; 
	sc_out<sc_logic> error; 
	sc_in<sc_logic> TSum, TCout;

	void testprocess(){ 
		error.write(SC_LOGIC_0);
		//validation code for combination 000 
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_0); 
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS);
		//(checks the response against the expected response) 
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_0) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//validation code for combination 001 
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_0); 
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//Requirement 1.a: Finish the code by validating that the rest of the possible input combinations provide the expected response

		//validation code for combination 010 
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_1); 
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//validation code for combination 011 
		TA.write(SC_LOGIC_0); 
		TB.write(SC_LOGIC_1); 
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//validation code for combination 100 
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_0); 
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_0) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//validation code for combination 101 
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_0); 
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//validation code for combination 110 
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_1); 
		TCin.write(SC_LOGIC_0);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_0 && TCout.read()==SC_LOGIC_1) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);

		//validation code for combination 111 
		TA.write(SC_LOGIC_1); 
		TB.write(SC_LOGIC_1); 
		TCin.write(SC_LOGIC_1);
		wait(10, SC_NS); 
		if(TSum.read()==SC_LOGIC_1 && TCout.read()==SC_LOGIC_1) 
			error.write(SC_LOGIC_0);
		else
			error.write(SC_LOGIC_1);
		} 

	SC_CTOR(TestbenchDesign1){ 
		SC_THREAD(testprocess);
	} 
}; 
