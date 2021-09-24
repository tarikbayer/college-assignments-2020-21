library ieee;
use ieee.std_logic_1164.all;

entity va is 
  port (
    e1 : in std_logic; -- Summand A
    e2 : in std_logic; -- Summand B
    ci : in std_logic; -- Carry-Bit
    ci1 : out std_logic;
    f : out std_logic -- Summe S mit C_4 als MSB
  );
end va;

architecture verhalten of va is
begin
  f <= (not(e1) and not(e2) and ci) or (not(e1) and e2 and not(ci)) or (e1 and not(e2) and not(ci)) or (e1 and e2 and ci);
  ci1 <= (not(e1) and e2 and ci) or (e1 and not(e2) and ci) or (e1 and e2 and not(ci)) or (e1 and e2 and ci);
end verhalten;