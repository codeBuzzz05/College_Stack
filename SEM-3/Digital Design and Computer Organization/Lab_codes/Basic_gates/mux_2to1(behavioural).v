module sample1(d0,d1,s,y);
input d1,d0,s;
output reg y;

always @(*) begin
	case(s)
		0:y=d0;
		1:y=d1;
	endcase
end
endmodule
 