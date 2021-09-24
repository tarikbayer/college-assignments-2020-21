VHDL Tasks

* Create a counter with the difference that it does not count BCD (i.e. 0..9 with a 4-bit register), but from 0 to 7, i.e. the complete dual scope of a 3-bit counter.

* Design a test bench that tests all cases up to and including counter overflow and counter underflow. So with all four possible combinations of HOLD = 0/1 and UP = 0/1. You may have to extend the simulation time: You can change the ghdl parameter --stop-time = 200ns in makescript.sh. 

*Attention: Long simulation times lead to large vcd files and high CPU utilization!
