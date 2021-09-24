library ieee;
use ieee.std_logic_1164.all;

entity dff3 is
  port (
    clk   : in  std_logic;
    async_reset : in  std_logic;
    D   : in std_logic_vector(2 downto 0);          
    Q  	: out std_logic_vector(2 downto 0));          
end dff3;

architecture behv of dff3 is
  signal internes_Q : std_logic_vector(2 downto 0);
begin

process (clk, D, async_reset) is
  begin
  
	if async_reset = '0' then
		internes_Q <= "000";
    elsif clk'event and clk='1' then
      internes_Q <= D;
    end if;
end process;
  
Q  <= internes_Q;
	
end behv;
