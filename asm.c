#include "asm.h"

int asm_mov(char *inst[3], FILE *f) {
	if (inst[1][0] == 'a') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_AA, f); break;
		case 'b': fputc(MOV_AB, f); break;
		case 'c': fputc(MOV_AC, f); break;
		case 'd': fputc(MOV_AD, f); break;
		case 'e': fputc(MOV_AE, f); break;
		case 'h': fputc(MOV_AH, f); break;
		case 'l': fputc(MOV_AL, f); break;
		case 'm': fputc(MOV_AM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'b') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_BA, f); break;
		case 'b': fputc(MOV_BB, f); break;
		case 'c': fputc(MOV_BC, f); break;
		case 'd': fputc(MOV_BD, f); break;
		case 'e': fputc(MOV_BE, f); break;
		case 'h': fputc(MOV_BH, f); break;
		case 'l': fputc(MOV_BL, f); break;
		case 'm': fputc(MOV_BM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'c') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_CA, f); break;
		case 'b': fputc(MOV_CB, f); break;
		case 'c': fputc(MOV_CC, f); break;
		case 'd': fputc(MOV_CD, f); break;
		case 'e': fputc(MOV_CE, f); break;
		case 'h': fputc(MOV_CH, f); break;
		case 'l': fputc(MOV_CL, f); break;
		case 'm': fputc(MOV_CM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'd') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_DA, f); break;
		case 'b': fputc(MOV_DB, f); break;
		case 'c': fputc(MOV_DC, f); break;
		case 'd': fputc(MOV_DD, f); break;
		case 'e': fputc(MOV_DE, f); break;
		case 'h': fputc(MOV_DH, f); break;
		case 'l': fputc(MOV_DL, f); break;
		case 'm': fputc(MOV_DM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'e') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_EA, f); break;
		case 'b': fputc(MOV_EB, f); break;
		case 'c': fputc(MOV_EC, f); break;
		case 'd': fputc(MOV_ED, f); break;
		case 'e': fputc(MOV_EE, f); break;
		case 'h': fputc(MOV_EH, f); break;
		case 'l': fputc(MOV_EL, f); break;
		case 'm': fputc(MOV_EM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'h') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_HA, f); break;
		case 'b': fputc(MOV_HB, f); break;
		case 'c': fputc(MOV_HC, f); break;
		case 'd': fputc(MOV_HD, f); break;
		case 'e': fputc(MOV_HE, f); break;
		case 'h': fputc(MOV_HH, f); break;
		case 'l': fputc(MOV_HL, f); break;
		case 'm': fputc(MOV_HM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'l') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_LA, f); break;
		case 'b': fputc(MOV_LB, f); break;
		case 'c': fputc(MOV_LC, f); break;
		case 'd': fputc(MOV_LD, f); break;
		case 'e': fputc(MOV_LE, f); break;
		case 'h': fputc(MOV_LH, f); break;
		case 'l': fputc(MOV_LL, f); break;
		case 'm': fputc(MOV_LM, f); break;
		//default: printf("error: bad source register.\n"); return -1;
		}
	}
	else if (inst[1][0] == 'm') {
		switch (inst[2][0]) {
		case 'a': fputc(MOV_MA, f); break;
		case 'b': fputc(MOV_MB, f); break;
		case 'c': fputc(MOV_MC, f); break;
		case 'd': fputc(MOV_MD, f); break;
		case 'e': fputc(MOV_ME, f); break;
		case 'h': fputc(MOV_MH, f); break;
		case 'l': fputc(MOV_ML, f); break;
		}
	}
	return 0;
}

int asm_mvi(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(MVI_A, f); break;
	case 'b': fputc(MVI_B, f); break;
	case 'c': fputc(MVI_C, f); break;
	case 'd': fputc(MVI_D, f); break;
	case 'e': fputc(MVI_E, f); break;
	case 'h': fputc(MVI_H, f); break;
	case 'l': fputc(MVI_L, f); break;
	case 'm': fputc(MVI_M, f); break;
	//default: printf("error: bad destination register.\n"); return -1;
	}
	fputc(atoi(inst[2]), f);
	return 0;
}

int asm_add(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(ADD_A, f); break;
	case 'b': fputc(ADD_B, f); break;
	case 'c': fputc(ADD_C, f); break;
	case 'd': fputc(ADD_D, f); break;
	case 'e': fputc(ADD_E, f); break;
	case 'h': fputc(ADD_H, f); break;
	case 'l': fputc(ADD_L, f); break;
	case 'm': fputc(ADD_M, f); break;
	}
	return 0;
}

int asm_adi(char *inst[3], FILE *f) {
	fputc(ADI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_adc(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(ADC_A, f); break;
	case 'b': fputc(ADC_B, f); break;
	case 'c': fputc(ADC_C, f); break;
	case 'd': fputc(ADC_D, f); break;
	case 'e': fputc(ADC_E, f); break;
	case 'h': fputc(ADC_H, f); break;
	case 'l': fputc(ADC_L, f); break;
	case 'm': fputc(ADC_M, f); break;
	}
	return 0;
}

int asm_aci(char *inst[3], FILE *f) {
	fputc(ACI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_sub(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(SUB_A, f); break;
	case 'b': fputc(SUB_B, f); break;
	case 'c': fputc(SUB_C, f); break;
	case 'd': fputc(SUB_D, f); break;
	case 'e': fputc(SUB_E, f); break;
	case 'h': fputc(SUB_H, f); break;
	case 'l': fputc(SUB_L, f); break;
	case 'm': fputc(SUB_M, f); break;
	}
	return 0;
}

int asm_sui(char *inst[3], FILE *f) {
	fputc(SUI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_sbb(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(SBB_A, f); break;
	case 'b': fputc(SBB_B, f); break;
	case 'c': fputc(SBB_C, f); break;
	case 'd': fputc(SBB_D, f); break;
	case 'e': fputc(SBB_E, f); break;
	case 'h': fputc(SBB_H, f); break;
	case 'l': fputc(SBB_L, f); break;
	case 'm': fputc(SBB_M, f); break;
	}
	return 0;
}

int asm_sbi(char *inst[3], FILE *f) {
	fputc(SBI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_inr(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(INR_A, f); break;
	case 'b': fputc(INR_B, f); break;
	case 'c': fputc(INR_C, f); break;
	case 'd': fputc(INR_D, f); break;
	case 'e': fputc(INR_E, f); break;
	case 'h': fputc(INR_H, f); break;
	case 'l': fputc(INR_L, f); break;
	case 'm': fputc(INR_M, f); break;
	}
	return 0;
}

int asm_dcr(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(DCR_A, f); break;
	case 'b': fputc(DCR_B, f); break;
	case 'c': fputc(DCR_C, f); break;
	case 'd': fputc(DCR_D, f); break;
	case 'e': fputc(DCR_E, f); break;
	case 'h': fputc(DCR_H, f); break;
	case 'l': fputc(DCR_L, f); break;
	case 'm': fputc(DCR_M, f); break;
	}
	return 0;
}

int asm_ana(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(ANA_A, f); break;
	case 'b': fputc(ANA_B, f); break;
	case 'c': fputc(ANA_C, f); break;
	case 'd': fputc(ANA_D, f); break;
	case 'e': fputc(ANA_E, f); break;
	case 'h': fputc(ANA_H, f); break;
	case 'l': fputc(ANA_L, f); break;
	case 'm': fputc(ANA_M, f); break;
	}
	return 0;
}

int asm_ani(char *inst[3], FILE *f) {
	fputc(ANI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_xra(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(XRA_A, f); break;
	case 'b': fputc(XRA_B, f); break;
	case 'c': fputc(XRA_C, f); break;
	case 'd': fputc(XRA_D, f); break;
	case 'e': fputc(XRA_E, f); break;
	case 'h': fputc(XRA_H, f); break;
	case 'l': fputc(XRA_L, f); break;
	case 'm': fputc(XRA_M, f); break;
	}
	return 0;
}

int asm_xri(char *inst[3], FILE *f) {
	fputc(XRI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_ora(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(ORA_A, f); break;
	case 'b': fputc(ORA_B, f); break;
	case 'c': fputc(ORA_C, f); break;
	case 'd': fputc(ORA_D, f); break;
	case 'e': fputc(ORA_E, f); break;
	case 'h': fputc(ORA_H, f); break;
	case 'l': fputc(ORA_L, f); break;
	case 'm': fputc(ORA_M, f); break;
	}
	return 0;
}

int asm_ori(char *inst[3], FILE *f) {
	fputc(ORI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_cmp(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case 'a': fputc(CMP_A, f); break;
	case 'b': fputc(CMP_B, f); break;
	case 'c': fputc(CMP_C, f); break;
	case 'd': fputc(CMP_D, f); break;
	case 'e': fputc(CMP_E, f); break;
	case 'h': fputc(CMP_H, f); break;
	case 'l': fputc(CMP_L, f); break;
	case 'm': fputc(CMP_M, f); break;
	}
	return 0;
}

int asm_cpi(char *inst[3], FILE *f) {
	fputc(CPI, f);
	fputc(atoi(inst[1]), f);
	return 0;
}

int asm_jmp(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JMP, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jnz(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JNZ, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jz(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JZ, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jnc(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JNC, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jc(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JC, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jpo(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JPO, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jpe(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JPE, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jp(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JP, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_jm(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(JM, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_call(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CALL, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cnz(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CNZ, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cz(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CZ, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cnc(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CNC, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cc(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CC, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cpo(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CPO, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cpe(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CPE, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cp(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CP, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_cm(char *inst[3], char *file, FILE *f) {
	FILE *fp = fopen(file, "r");

	if (fp) {
		fputc(CM, f);
		fputc(find_label(inst[1], fp), f);
	}

	return 0;
}

int asm_rst(char *inst[3], FILE *f) {
	switch (inst[1][0]) {
	case '0': fputc(RST_0, f); break;
	case '1': fputc(RST_1, f); break;
	case '2': fputc(RST_2, f); break;
	case '3': fputc(RST_3, f); break;
	case '4': fputc(RST_4, f); break;
	case '5': fputc(RST_5, f); break;
	case '6': fputc(RST_6, f); break;
	case '7': fputc(RST_7, f); break;
	}
	return 0;
}

int asm_push(char *inst[3], FILE *f) {
	if (strcmp(inst[1], "b") == 0) fputc(PUSH_B, f);
	else if (strcmp(inst[1], "d") == 0) fputc(PUSH_D, f);
	else if (strcmp(inst[1], "h") == 0) fputc(PUSH_H, f);
	else if (strcmp(inst[1], "psw") == 0) fputc(PUSH_PSW, f);
	
	return 0;
}

int asm_pop(char *inst[3], FILE *f) {
	if (strcmp(inst[1], "b") == 0) fputc(POP_B, f);
	else if (strcmp(inst[1], "d") == 0) fputc(POP_D, f);
	else if (strcmp(inst[1], "h") == 0) fputc(POP_H, f);
	else if (strcmp(inst[1], "psw") == 0) fputc(POP_PSW, f);

	return 0;
}