#ifdef _WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#include "asm.h"
#include "utils.h"

/*
TODO:
	Make an asm_error function to handle errors
	Fix find_label function to count bytes instead of lines
	use formula ceil(Ic/2) Ic = instruction count
*/

void asm_line(FILE *f, char *src, char *line) {
	char *tok;
	char *inst[3] = { NULL, NULL, NULL };
	int i = 0;

	/* don't waste our time on a comment or an empty line */
	if (line[0] == ';' || strlen(line) == 0) return;

	tok = strtok(strdup(line), ", ");
	while (tok != NULL) {
		if (i == 3) break; /* max of 3 tokens, more means its an inline comment */
		inst[i] = tok;
		tok = strtok(NULL, ", ");
		i++;
	}

	if      (strcmp(inst[0], "mov") == 0) asm_mov(inst, f);
	else if (strcmp(inst[0], "mvi") == 0) asm_mvi(inst, f);
	else if (strcmp(inst[0], "add") == 0) asm_add(inst, f);
	else if (strcmp(inst[0], "adi") == 0) asm_adi(inst, f);
	else if (strcmp(inst[0], "adc") == 0) asm_adc(inst, f);
	else if (strcmp(inst[0], "aci") == 0) asm_aci(inst, f);
	else if (strcmp(inst[0], "sub") == 0) asm_sub(inst, f);
	else if (strcmp(inst[0], "sui") == 0) asm_sui(inst, f);
	else if (strcmp(inst[0], "sbb") == 0) asm_sbb(inst, f);
	else if (strcmp(inst[0], "sbi") == 0) asm_sbi(inst, f);
	else if (strcmp(inst[0], "di") == 0) fputc(DI, f);
	else if (strcmp(inst[0], "ei") == 0) fputc(EI, f);
	else if (strcmp(inst[0], "nop") == 0) fputc(NOP, f);
	else if (strcmp(inst[0], "hlt") == 0) fputc(HLT, f);
	else if (strcmp(inst[0], "inr") == 0) asm_inr(inst, f);
	else if (strcmp(inst[0], "dcr") == 0) asm_dcr(inst, f);
	else if (strcmp(inst[0], "ana") == 0) asm_ana(inst, f);
	else if (strcmp(inst[0], "ani") == 0) asm_ani(inst, f);
	else if (strcmp(inst[0], "xra") == 0) asm_xra(inst, f);
	else if (strcmp(inst[0], "xri") == 0) asm_xri(inst, f);
	else if (strcmp(inst[0], "ora") == 0) asm_ora(inst, f);
	else if (strcmp(inst[0], "ori") == 0) asm_ori(inst, f);
	else if (strcmp(inst[0], "cmp") == 0) asm_cmp(inst, f);
	else if (strcmp(inst[0], "cpi") == 0) asm_cpi(inst, f);
	else if (strcmp(inst[0], "jmp") == 0) asm_jmp(inst, src, f);
	else if (strcmp(inst[0], "jnz") == 0) asm_jnz(inst, src, f);
	else if (strcmp(inst[0], "jz") == 0) asm_jz(inst, src, f);
	else if (strcmp(inst[0], "jnc") == 0) asm_jnc(inst, src, f);
	else if (strcmp(inst[0], "jc") == 0) asm_jc(inst, src, f);
	else if (strcmp(inst[0], "jpo") == 0) asm_jpo(inst, src, f);
	else if (strcmp(inst[0], "jpe") == 0) asm_jpe(inst, src, f);
	else if (strcmp(inst[0], "jp") == 0) asm_jp(inst, src, f);
	else if (strcmp(inst[0], "jm") == 0) asm_jm(inst, src, f);
	else if (strcmp(inst[0], "pchl") == 0) fputc(PCHL, f);
	else if (strcmp(inst[0], "call") == 0) asm_call(inst, src, f);
	else if (strcmp(inst[0], "cnz") == 0) asm_cnz(inst, src, f);
	else if (strcmp(inst[0], "cz") == 0) asm_cz(inst, src, f);
	else if (strcmp(inst[0], "cnc") == 0) asm_cnc(inst, src, f);
	else if (strcmp(inst[0], "cc") == 0) asm_cc(inst, src, f);
	else if (strcmp(inst[0], "cpo") == 0) asm_cpo(inst, src, f);
	else if (strcmp(inst[0], "cpe") == 0) asm_cpe(inst, src, f);
	else if (strcmp(inst[0], "cp") == 0) asm_cp(inst, src, f);
	else if (strcmp(inst[0], "cm") == 0) asm_cm(inst, src, f);
	else if (strcmp(inst[0], "ret") == 0) fputc(RET, f);
	else if (strcmp(inst[0], "rnz") == 0) fputc(RNZ, f);
	else if (strcmp(inst[0], "rz") == 0) fputc(RZ, f);
	else if (strcmp(inst[0], "rnc") == 0) fputc(RNC, f);
	else if (strcmp(inst[0], "rc") == 0) fputc(RC, f);
	else if (strcmp(inst[0], "rpo") == 0) fputc(RPO, f);
	else if (strcmp(inst[0], "rpe") == 0) fputc(RPE, f);
	else if (strcmp(inst[0], "rp") == 0) fputc(RP, f);
	else if (strcmp(inst[0], "rm") == 0) fputc(RM, f);
	else if (strcmp(inst[0], "rst") == 0) asm_rst(inst, f);
	else if (strcmp(inst[0], "push") == 0) asm_push(inst, f);
	else if (strcmp(inst[0], "pop") == 0) asm_pop(inst, f);

	return;
}

void assemble(FILE *fout, FILE *fin) {

}

int main(int argc, char **argv) {
	if (argc == 1) {
		printf("Tiny Assembler  Copyright (c) 2018 Marin Bizov\n\n");
		printf("Usage: %s [-o binfile] srcfile\n", argv[0]);
		return 0;
	}
	char *line;
	FILE *fi = NULL, *fo = NULL;

	int opt;
	while ((opt = getopt(argc, argv, "o:")) != -1) {
		switch (opt) {
		case 'o': fo = fopen(optarg, "wb"); break;
		}
	}

	if (fo == NULL) fo = fopen("a.com", "wb");

	fi = fopen(argv[optind], "r");

	if (fi) {
		while ((line = getline(fi)) != NULL) {
			chomp(line);
			asm_line(fo, argv[optind], line);
		}
		//assemble(fo, fi);
	}

	return 0;
}