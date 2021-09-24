library ieee;
use ieee.std_logic_1164.all;

entity cntHierarch is 
  port (
  CLK          : in std_logic;
  CLRN          : in std_logic;
  HOLD          : in std_logic;
  UP         : in std_logic;
  zustandsvektor : out std_logic_vector(2 downto 0));
end cntHierarch;

architecture verhalten of cntHierarch is
  
  component va3 is
    port (
      A, B     : in std_logic_vector(2 downto 0);
      S        : out std_logic_vector(3 downto 0));
  end component va3;
  
  component dff3 is
    port (
      clk, async_reset  : in std_logic;
      D               	: in std_logic_vector(2 downto 0);
      Q               	: out std_logic_vector(2 downto 0));
  end component dff3;
  
  component mux43 is
    port (
      d0, d1, d2, d3     : in std_logic_vector(2 downto 0);
      sel        		 : in std_logic_vector(1 downto 0);
      Y               	 : out std_logic_vector(2 downto 0));
  end component mux43;

  signal summe4Bit_slv       :std_logic_vector(3 downto 0);
  signal summe4Bit_slv2      :std_logic_vector(3 downto 0);
  signal untere3Bit_slv  	 :std_logic_vector(2 downto 0);
  signal untere3Bit_slv2 	 :std_logic_vector(2 downto 0);
  signal zaehler        :std_logic_vector(2 downto 0);
  signal holdup              :std_logic_vector(1 downto 0);
  signal mux_output         :std_logic_vector(2 downto 0);
  
begin
  untere3Bit_slv <= summe4Bit_slv(2 downto 0);
  untere3Bit_slv2 <= summe4Bit_slv2(2 downto 0);
  holdup(0) <= UP;
  holdup(1) <= HOLD;
   
   mux : mux43
    port map (
      d0 => untere3Bit_slv2,
      d1 => untere3Bit_slv,
      d2 => zaehler,
      d3 => zaehler,
      sel => holdup,
      Y => mux_output);
   
   dff : dff3
    port map (
      clk => CLK,
      async_reset => CLRN,
      D => mux_output,
      Q => zaehler);
      
   add : va3
    port map (
      A => zaehler,
      B => "001",
      S => summe4Bit_slv);
	  
	  sub : va3
    port map (
      A => zaehler,
      B => "111",
      S => summe4Bit_slv2);
      
  zustandsvektor <= zaehler;  
end verhalten;