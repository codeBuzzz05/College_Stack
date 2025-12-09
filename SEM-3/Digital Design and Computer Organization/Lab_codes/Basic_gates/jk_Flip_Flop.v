module jk_flipflop(clk, j, k, q);
input clk, j, k;
output reg q;

initial begin
    q = 0;   
end

always @(posedge clk) begin
    case({j, k})
        2'b00: q <= q; 
        2'b01: q <= 0;      
        2'b10: q <= 1;      
        2'b11: q <= ~q;     
    endcase
end

endmodule