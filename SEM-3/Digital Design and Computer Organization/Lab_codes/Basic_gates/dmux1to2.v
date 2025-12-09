module dmux1to2(d,s,y1,y0);
input d,s;
output reg y1,y0;
always @(*) begin
y0=0;
y1=0;
	if(s==0)
		y0=d;
	else
		y1=d;
end
endmodule;

