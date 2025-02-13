/* $Id: gen_code_stubs.c,v 1.7 2023/03/27 16:39:12 leavens Exp $ */
#include "utilities.h"
#include "gen_code.h"

// Initialize the code generator
void gen_code_initialize()
{
    bail_with_error("gen_code_initialize not implemented yet!");
}

// Generate code for the given AST
code_seq gen_code_program(AST *prog)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_block not implemented yet!");
    return code_seq_empty();
}

// generate code for blk
code_seq gen_code_block(AST *blk)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_block not implemented yet!");
    return code_seq_empty();
}

// generate code for the declarations in cds
code_seq gen_code_constDecls(AST_list cds)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_constDecls not implemented yet!");
    return code_seq_empty();
}

// generate code for the const declaration cd
code_seq gen_code_constDecl(AST *cd)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_constDecl not implemented yet!");
    return code_seq_empty();
}

// generate code for the declarations in vds
code_seq gen_code_varDecls(AST_list vds)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_varDecls not implemented yet!");
    return code_seq_empty();
}

// generate code for the var declaration vd
code_seq gen_code_varDecl(AST *vd)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_varDecl not implemented yet!");
    return code_seq_empty();
}

// generate code for the declarations in pds
void gen_code_procDecls(AST_list pds)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_procDecls not implemented yet!");
}

// generate code for the procedure declaration pd

//nick 

void gen_code_procDecl(AST *pd)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_procDecl not implemented yet!");
}

// generate code for the statement
code_seq gen_code_stmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_stmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_assignStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_assignStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_callStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_callStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_beginStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_beginStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_ifStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_ifStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_whileStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_whileStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_readStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_readStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_writeStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_writeStmt not implemented yet!");
    return code_seq_empty();
}

// generate code for the statement
code_seq gen_code_skipStmt(AST *stmt)
{
    // Replace the following with your implementation
    bail_with_error("gen_code_skipStmt not implemented yet!");
    return code_seq_empty();
}

//here down



// generate code for the condition
code_seq gen_code_cond(AST *cond)
{
    code_seq ret = gen_code_cond(cond->data.bin_cond.leftexp);
    ret = code_seq_concat(ret, gen_code_cond(cond->data.bin_cond.rightexp));
    switch (cond->type_tag) {
        case number_ast:
	        return gen_code_number_expr(cond);
	        break;
        case ident_ast:
	        return gen_code_ident_expr(cond);
	        break;
        case bin_expr_ast:
	        return gen_code_bin_expr(cond);
	        break;
        case bin_cond_ast:
            return gen_code_bin_cond(cond);
            break;
        case odd_cond_ast:
            return gen_code_odd_cond(cond);
            break;
        default:
	        bail_with_error("gen_code_cond passed bad AST!");
	        return code_seq_empty();
	        break;
    }
}

// generate code for the condition
code_seq gen_code_odd_cond(AST *cond)
{
    code_seq ret = gen_code_expr(cond->data.odd_cond.exp);
    return (gen_code_expr(ret));

    bail_with_error("gen_code_odd_cond passed AST with bad op!");
	return code_seq_empty();
}

// generate code for the condition
code_seq gen_code_bin_cond(AST *cond)
{
    code_seq ret = gen_code_cond(cond->data.bin_cond.leftexp);
    ret = code_seq_concat(ret, gen_code_cond(cond->data.bin_cond.rightexp));

    switch(cond->data.bin_cond.relop){
        case eqop:
	        return code_seq_add_to_end(ret, code_eql());
	        break;
        case neqop:
	        return code_seq_add_to_end(ret, code_neq());
	        break;
        case ltop:
	        return code_seq_add_to_end(ret, code_lss());
	        break;
        case leqop:
	        return code_seq_add_to_end(ret, code_leq());
	        break;
        case gtop:
            return code_seq_add_to_end(ret, code_gtr());
            break;
        case geqop:
            return code_seq_add_to_end(ret, code_geq());
            break;
        case addop:
	        return code_seq_add_to_end(ret, code_add());
	        break;
        case subop:
            return code_seq_add_to_end(ret, code_sub());
            break;
        case multop:
            return code_seq_add_to_end(ret, code_mul());
            break;
        case divop:
            return code_seq_add_to_end(ret, code_div());
            break;
            default:
    }
    bail_with_error("gen_bin_cond passed AST with bad op!");
	return code_seq_empty();
}

// generate code for the expresion
code_seq gen_code_expr(AST *exp)
{
    switch (exp->type_tag) {
        case number_ast:
	        return gen_code_number_expr(exp);
	        break;
        case ident_ast:
	        return gen_code_ident_expr(exp);
	        break;
        case bin_expr_ast:
	        return gen_code_bin_expr(exp);
	        break;
        case bin_cond_ast:
            return gen_code_bin_cond(exp);
            break;
        case odd_cond_ast:
            return gen_code_odd_cond(exp);
            break;
        default:
	        bail_with_error("gen_code_expr passed bad AST!");
	        return code_seq_empty();
	        break;
    }
}

// generate code for the expression (exp)
code_seq gen_code_bin_expr(AST *exp)
{
    code_seq ret = gen_code_expr(exp->data.bin_expr.leftexp);
    ret = code_seq_concat(ret, gen_code_expr(exp->data.bin_expr.rightexp));
    switch (exp->data.bin_expr.op) {
        case eqop:
	        return code_seq_add_to_end(ret, code_eql());
	        break;
        case neqop:
	        return code_seq_add_to_end(ret, code_neq());
	        break;
        case ltop:
	        return code_seq_add_to_end(ret, code_lss());
	        break;
        case leqop:
	        return code_seq_add_to_end(ret, code_leq());
	        break;
        case gtop:
            return code_seq_add_to_end(ret, code_gtr());
            break;
        case geqop:
            return code_seq_add_to_end(ret, code_geq());
            break;
        case addop:
	        return code_seq_add_to_end(ret, code_add());
	        break;
        case subop:
            return code_seq_add_to_end(ret, code_sub());
            break;
        case multop:
            return code_seq_add_to_end(ret, code_mul());
            break;
        case divop:
            return code_seq_add_to_end(ret, code_div());
            break;
        default:
	        bail_with_error("gen_code_bin_expr passed AST with bad op!");
	        return code_seq_empty();
    }
}

// generate code for the ident expression (ident)
code_seq gen_code_ident_expr(AST *ident)
{
    id_use *idu = ident->data.ident.idu;
    lexical_address *la = lexical_address_create(idu->levelsOutward,
						 idu->attrs->loc_offset);
    return code_load_from_lexical_address(la);
}

// generate code for the number expression (num)
code_seq gen_code_number_expr(AST *num)
{
    return code_seq_singleton(code_lit(num->data.number.value));
}
