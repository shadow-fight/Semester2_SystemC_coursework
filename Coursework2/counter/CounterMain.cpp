#include "Counter8bit.h"
#include "TestBenchDesign2.h"

SC_MODULE(CounterMain) {
	sc_clock clock;
	sc_signal<bool> reset_s,enable_s;
	sc_signal<sc_uint<8> > counter_out_s;

	Counter8bit counter;
	TestBenchDesign2 test1;

	SC_CTOR(CounterMain): clock("SystemClock",2,0.5,true),counter("Counter8bit"),test1("TestBenchDesign2") {
		counter.clock(clock);
		counter.enable(enable_s);
		counter.reset(reset_s);
		counter.counter_out(counter_out_s);
		test1.reset(reset_s);
		test1.enable(enable_s);
		}
};

SC_MODULE_EXPORT(CounterMain);
