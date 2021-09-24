VHDL Tasks

* 1) Create a counter with the difference that it does not count BCD (i.e. 0..9 with a 4-bit register), but from 0 to 7, i.e. the complete dual scope of a 3-bit counter.

* 2) Design a test bench that tests all cases up to and including counter overflow and counter underflow. So with all four possible combinations of HOLD = 0/1 and UP = 0/1. You may have to extend the simulation time: You can change the ghdl parameter --stop-time = 200ns in makescript.sh. 
*Attention: Long simulation times lead to large vcd files and high CPU utilization!

* 3) Create a counter that implements exactly the same function as in 1), but as a hierarchical design with an adder that adds 1 to the register output and another adder that subtracts 1. In order to implement the various counting functions (UP / HOLD), create another component: a multiplexer on which the select inputs can be used to select whether the output of the register +1, -1 or unchanged (HOLD) is forwarded to the register input will. Select the input assignment of the multiplexer so that you can apply the signals HOLD and UP directly to the select input as std_logic_vector. The multiplexer must of course always be able to switch 3-bit-wide vectors. With 2 selectors it has 2 ^ 2 = 4 inputs.

* 3(a) Draw the circuit diagram of the top hierarchy (entity cntHierarch), i.e. where the adders, multiplexers and registers are connected via signals and name the signals in the circuit diagram with the names they use in your VHDL implementation
* 3(b) Create the hierarchical VHDL model (entity name see below) and note that the counter is reset asynchronously if the input is '0' (CLRN).
* 3(c) Test whether the hierarchical model has the same function with the test bench from 2). To do this, instantiate both counters in the testbench so that both outputs can be observed at the same time.

  Notes and requirements:
  
• Entity name for counter task 1: cntProc

• Entity name for testbench task 2: cntTB

• Entity name for counter task 3: cntHierarch

• Entity name for multiplexer: mux43 (4: 1 with 3 bit wide vectors)


entity mux43 is
port (
d0: in std_logic_vector (2 downto 0); - d0 (sel = "00")
d1: in std_logic_vector (2 downto 0); - d1 (sel = "01")
d2: in std_logic_vector (2 downto 0); - d2 (sel = "10")
d3: in std_logic_vector (2 downto 0); - d3 (sel = "11")
sel: in std_logic_vector (1 downto 0); - 2 selector inputs
Y: out std_logic_vector (2 downto 0) - output
);
end mux43;

• Entity name for the register: dff3 (Attention: Reset of the counter is active low!)
• Entity name for the adders: va3
 
