`ifndef VX_DECODE_IF
`define VX_DECODE_IF

`include "VX_define.vh"

interface VX_decode_if ();

    wire                    valid;    
    wire [`UUID_BITS-1:0]   uuid;
    wire [`NW_BITS-1:0]     wid;
    wire [`NUM_THREADS-1:0] tmask;
    wire [31:0]             PC;
    wire [`EX_BITS-1:0]     ex_type;    
    wire [`INST_OP_BITS-1:0] op_type; 
    wire [`INST_MOD_BITS-1:0] op_mod;    
    wire                    wb;
    wire                    use_PC;
    wire                    use_imm;
    wire [31:0]             imm;
    wire [`NR_BITS-1:0]     rd;
    wire [`NR_BITS-1:0]     rs1;
    wire [`NR_BITS-1:0]     rs2;
    wire [`NR_BITS-1:0]     rs3;
    wire                    ready;

    wire [6:0] func7; 
    wire [2:0] func3; 
    wire [11:0] u_12; 
    modport master (
        output valid,
        output uuid,
        output wid,
        output tmask,
        output PC,
        output ex_type,  
        output op_type,
        output op_mod,   
        output wb,
        output use_PC,
        output use_imm,
        output imm,
        output rd,
        output rs1,
        output rs2,
        output rs3,
        output func3, 
        output func7, 
        output u_12, 
        input  ready
    );

    modport slave (
        input  valid,
        input  uuid,
        input  wid,
        input  tmask,
        input  PC,
        input  ex_type,  
        input  op_type,
        input  op_mod,   
        input  wb,
        input  use_PC,
        input  use_imm,
        input  imm,
        input  rd,
        input  rs1,
        input  rs2,
        input  rs3,
        input func3, 
        input func7,
        input u_12, 
        output ready
    );

endinterface

`endif