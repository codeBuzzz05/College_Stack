module p5(a,b,cin,cout,s);
input a,b,cin;
output s,cout;
assign s=a^b^cin;
assign cout=(cin&(a^b))|(a&b);
endmodule
