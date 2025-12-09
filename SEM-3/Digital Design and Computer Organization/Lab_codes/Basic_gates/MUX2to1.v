module mux2to1(d0,d1,s,y);
input d0,d1,s;
output y;
assign y=(d0&~s)|(d1&s);
endmodule