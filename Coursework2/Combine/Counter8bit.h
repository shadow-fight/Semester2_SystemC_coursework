#include "systemc.h"

SC_MODULE(Counter8bit) {
	sc_in_clk clock;
	sc_in<sc_logic> reset,enable;
	sc_out<sc_uint<8> > counter_out;
	sc_uint<8> count;

	void incr_count() {
		while(true){
			if(enable.read()==1) {
				if(reset.read()==1) {
					count=0;
					counter_out.write(count);
					}
				else {
					count=count+1;
					counter_out.write(count);
					}
				}
			wait();
		}
	}

	SC_CTOR(Counter8bit) {
		SC_THREAD (incr_count);
		sensitive << clock.pos();
		count=0;
		}
};
