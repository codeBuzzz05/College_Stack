module dmux1to8(d,s2,s1,s0,y0,y1,y2,y3,y4,y5,y6,y7);
input s2,s1,s0,d;
output reg y0,y1,y2,y3,y4,y5,y6,y7;

always @(*) begin
y0=0;
y1=0;
y2=0;
y3=0;
y4=0;
y5=0;
y6=0;
y7=0;
	case({s2,s1,s0})
		
		3'b000:y0=d;
		3'b001:y1=d;
		3'b010:y2=d;
		3'b011:y3=d;
		3'b100:y4=d;
		3'b101:y5=d;
		3'b110:y6=d;
		3'b111:y7=d;
	endcase
end
endmodule