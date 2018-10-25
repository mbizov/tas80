#ifndef _ASM_H_
#define _ASM_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opcodes.h"
#include "utils.h"

int asm_mov(char *inst[3], FILE *f);
int asm_mvi(char *inst[3], FILE *f);
int asm_add(char *inst[3], FILE *f);
int asm_adi(char *inst[3], FILE *f);
int asm_adc(char *inst[3], FILE *f);
int asm_aci(char *inst[3], FILE *f);
int asm_sub(char *inst[3], FILE *f);
int asm_sui(char *inst[3], FILE *f);
int asm_sbb(char *inst[3], FILE *f);
int asm_sbi(char *inst[3], FILE *f);
int asm_inr(char *inst[3], FILE *f);
int asm_dcr(char *inst[3], FILE *f);
int asm_ana(char *inst[3], FILE *f);
int asm_ani(char *inst[3], FILE *f);
int asm_xra(char *inst[3], FILE *f);
int asm_xri(char *inst[3], FILE *f);
int asm_ora(char *inst[3], FILE *f);
int asm_ori(char *inst[3], FILE *f);
int asm_cmp(char *inst[3], FILE *f);
int asm_cpi(char *inst[3], FILE *f);
int asm_jmp(char *inst[3], char *file, FILE *f);
int asm_jnz(char *inst[3], char *file, FILE *f);
int asm_jz(char *inst[3], char *file, FILE *f);
int asm_jnc(char *inst[3], char *file, FILE *f);
int asm_jc(char *inst[3], char *file, FILE *f);
int asm_jpo(char *inst[3], char *file, FILE *f);
int asm_jpe(char *inst[3], char *file, FILE *f);
int asm_jp(char *inst[3], char *file, FILE *f);
int asm_jm(char *inst[3], char *file, FILE *f);
int asm_call(char *inst[3], char *file, FILE *f);
int asm_cnz(char *inst[3], char *file, FILE *f);
int asm_cz(char *inst[3], char *file, FILE *f);
int asm_cnc(char *inst[3], char *file, FILE *f);
int asm_cc(char *inst[3], char *file, FILE *f);
int asm_cpo(char *inst[3], char *file, FILE *f);
int asm_cpe(char *inst[3], char *file, FILE *f);
int asm_cp(char *inst[3], char *file, FILE *f);
int asm_cm(char *inst[3], char *file, FILE *f);
int asm_rst(char *inst[3], FILE *f);
int asm_push(char *inst[3], FILE *f);
int asm_pop(char *inst[3], FILE *f);

#endif