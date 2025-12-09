module tff(clk,t,q);

input clk,t;
output reg q;
initial begin
	q=0;
end
always @(posedge clk) begin
	if(t==1)
		q<=~q;
	else
		q<=q;
end
endmodule