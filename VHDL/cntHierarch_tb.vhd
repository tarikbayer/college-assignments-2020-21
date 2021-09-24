library ieee;
use ieee.std_logic_1164.all;

-------------------------------------------------------------------------------

entity cntHierarch_tb is

end entity cntHierarch_tb;

-------------------------------------------------------------------------------

architecture dut of cntHierarch_tb is

  -- component ports
  signal CLRN 		: std_logic;
  signal CLK 		: std_logic;
  signal UP 		: std_logic;
  signal HOLD 		: std_logic;
  
  
  signal zustandsvektor : std_logic_vector(2 downto 0);

  
begin  -- architecture dut

  -- component instantiation
--  cntHierarch_dut : entity work.cntHierarch
--    port map (
--      	CLRN 	=> 	CLRN,
--      	CLK    	=> 	CLK,
--     	UP     	=> 	UP,
--		HOLD	=> 	HOLD,
--		d1		=>  d1,
--		d3		=>	d3,
--		zustandsvektor => zustandsvektor);

  -- waveform generation
  WaveGen_Proc : process
  begin
    CLK <= '0'; wait for 4 ns;
    CLK <= '1'; wait for 4 ns;
  end process WaveGen_Proc;
  
  WaveGen_Proc1 : process
  begin
    UP <= '1'; wait for 128 ns;
    UP <= '0'; wait for 128 ns;
  end process WaveGen_Proc1;
  
  WaveGen_Proc2 : process
  begin
    HOLD <= '1'; wait for 8 ns;
    HOLD <= '0'; wait for 8 ns;
  end process WaveGen_Proc2;
  
  WaveGen_Proc3 : process
  begin
    CLRN <= '1'; wait for 248 ns;
    CLRN <= '0'; wait for 8 ns;
  end process WaveGen_Proc3;

--  WaveGen_Proc1 : process
--  begin
--    async_reset <= '0';
--    wait for 8 ns;
--    async_reset <= '1'; wait for 5 ns;
--    async_reset <= '0';
--    wait;
--  end process WaveGen_Proc1;


end architecture dut;
