library ieee;
use ieee.std_logic_1164.all;

entity mux43 is
  port (
    d0, d1, d2, d3				   : in  std_logic_vector(2 downto 0);   -- Daten
    sel                   		   : in  std_logic_vector(1 downto 0);   -- Selektoren
    Y                              : out std_logic_vector(2 downto 0));  -- Ausgang
end mux43;

architecture verhalten of mux43 is
 
begin
	
  Y <= d0 when sel = "00" else  -- 0
       d1 when sel = "01" else  -- 1
       d2 when sel = "10" else  -- 2
       d3 when sel = "11"; --else  -- 3
  	   -- sollte nicht eintreten
end verhalten;
