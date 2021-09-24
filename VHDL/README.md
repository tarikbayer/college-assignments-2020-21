VHDL Tasks

* Create a counter with the difference that it does not count BCD (i.e. 0..9 with a 4-bit register), but from 0 to 7, i.e. the complete dual scope of a 3-bit counter.

* Design a test bench that tests all cases up to and including counter overflow and counter underflow. So with all four possible combinations of HOLD = 0/1 and UP = 0/1. You may have to extend the simulation time: You can change the ghdl parameter --stop-time = 200ns in makescript.sh. 
*Attention: Long simulation times lead to large vcd files and high CPU utilization!

* Create a counter that implements exactly the same function as in 1), but as a hierarchical design with an adder that adds 1 to the register output and another adder that subtracts 1. In order to implement the various counting functions (UP / HOLD), create another component: a multiplexer on which the select inputs can be used to select whether the output of the register +1, -1 or unchanged (HOLD) is forwarded to the register input will. Select the input assignment of the multiplexer so that you can apply the signals HOLD and UP directly to the select input as std_logic_vector. The multiplexer must of course always be able to switch 3-bit-wide vectors. With 2 selectors it has 2 ^ 2 = 4 inputs.
