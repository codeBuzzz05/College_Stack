module p3(a,b,c,y,e);
input a,b,c;
output y,e;
assign y=(a&b)|~c;
assign e=~c;
endmodule
