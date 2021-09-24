library ieee;
use ieee.std_logic_1164.all;

entity va3 is 
  port (
    A : in std_logic_vector(2 downto 0); -- Summand A
    B : in std_logic_vector(2 downto 0); -- Summand B
    S : out std_logic_vector(3 downto 0) -- Summe S mit C_4 als MSB
  );
end va3;

architecture verhalten of va3 is
  
  component va is
    port (
      e1, e2, ci : in std_logic;
      ci1, f	 : out std_logic);
  end component va;
  
  signal C0, C1, C2 : std_logic;
  
begin
  va0 : va
    port map (
      e1 => A(0), e2 => B(0), ci => '0',
      ci1 => C0, f => S(0));
      
  va1 : va
    port map (
      e1 => A(1), e2 => B(1), ci => C0,
      ci1 => C1, f => S(1));
      
  va2 : va
    port map (
      e1 => A(2), e2 => B(2), ci => C1,
      ci1 => S(3), f => S(2));
      
end verhalten;