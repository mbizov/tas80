#ifndef _OPCODES_H_
#define _OPCODES_H_

/* transfer instructions */
#define MOV_AA 0x7f
#define MOV_AB 0x78
#define MOV_AC 0x79
#define MOV_AD 0x7a
#define MOV_AE 0x7b
#define MOV_AH 0x7c
#define MOV_AL 0x7d
#define MOV_AM 0x7e
#define MOV_BA 0x47
#define MOV_BB 0x40
#define MOV_BC 0x41
#define MOV_BD 0x42
#define MOV_BE 0x43
#define MOV_BH 0x44
#define MOV_BL 0x45
#define MOV_BM 0x46
#define MOV_CA 0x4f
#define MOV_CB 0x48
#define MOV_CC 0x49
#define MOV_CD 0x4a
#define MOV_CE 0x4b
#define MOV_CH 0x4c
#define MOV_CL 0x4d
#define MOV_CM 0x4e
#define MOV_DA 0x57
#define MOV_DB 0x50
#define MOV_DC 0x51
#define MOV_DD 0x52
#define MOV_DE 0x53
#define MOV_DH 0x54
#define MOV_DL 0x55
#define MOV_DM 0x56
#define MOV_EA 0x5f
#define MOV_EB 0x58
#define MOV_EC 0x59
#define MOV_ED 0x5a
#define MOV_EE 0x5b
#define MOV_EH 0x5c
#define MOV_EL 0x5d
#define MOV_EM 0x5e
#define MOV_HA 0x67
#define MOV_HB 0x60
#define MOV_HC 0x61
#define MOV_HD 0x62
#define MOV_HE 0x63
#define MOV_HH 0x64
#define MOV_HL 0x65
#define MOV_HM 0x66
#define MOV_LA 0x6f
#define MOV_LB 0x68
#define MOV_LC 0x69
#define MOV_LD 0x6a
#define MOV_LE 0x6b
#define MOV_LH 0x6c
#define MOV_LL 0x6d
#define MOV_LM 0x6e
#define MOV_MA 0x77
#define MOV_MB 0x70
#define MOV_MC 0x71
#define MOV_MD 0x72
#define MOV_ME 0x73
#define MOV_MH 0x74
#define MOV_ML 0x75
#define MVI_A 0x3e
#define MVI_B 0x06
#define MVI_C 0x0e
#define MVI_D 0x16
#define MVI_E 0x1e
#define MVI_H 0x26
#define MVI_L 0x2e
#define MVI_M 0x36

/* add byte instructions */
#define ADD_A 0x87
#define ADD_B 0x80
#define ADD_C 0x81
#define ADD_D 0x82
#define ADD_E 0x83
#define ADD_H 0x84
#define ADD_L 0x85
#define ADD_M 0x86
#define ADI 0xc6

/* add byte with carry-in instructions */
#define ADC_A 0x8f
#define ADC_B 0x88
#define ADC_C 0x89
#define ADC_D 0x8a
#define ADC_E 0x8b
#define ADC_H 0x8c
#define ADC_L 0x8d
#define ADC_M 0x8e
#define ACI 0xce

/* subtract byte instructions */
#define SUB_A 0x97
#define SUB_B 0x90
#define SUB_C 0x91
#define SUB_D 0x92
#define SUB_E 0x93
#define SUB_H 0x94
#define SUB_L 0x95
#define SUB_M 0x96
#define SUI 0xd6

/* subtract byte with borrow-in instructions */
#define SBB_A 0x9f
#define SBB_B 0x98
#define SBB_C 0x99
#define SBB_D 0x9a
#define SBB_E 0x9b
#define SBB_H 0x9c
#define SBB_L 0x9d
#define SBB_M 0x9e
#define SBI 0xde

/* control instructions */
#define DI 0xf3
#define EI 0xfb
#define NOP 0x00
#define HLT 0x76

/* increment byte instructions */
#define INR_A 0x3c
#define INR_B 0x04
#define INR_C 0x0c
#define INR_D 0x14
#define INR_E 0x1c
#define INR_H 0x24
#define INR_L 0x2c
#define INR_M 0x34

/* decrement byte instructions */
#define DCR_A 0x3d
#define DCR_B 0x05
#define DCR_C 0x0d
#define DCR_D 0x15
#define DCR_E 0x1d
#define DCR_H 0x25
#define DCR_L 0x2d
#define DCR_M 0x35

/* logical byte instructions */
#define ANA_A 0xa7
#define ANA_B 0xa0
#define ANA_C 0xa1
#define ANA_D 0xa2
#define ANA_E 0xa3
#define ANA_H 0xa4
#define ANA_L 0xa5
#define ANA_M 0xa6
#define ANI 0xe6
#define XRA_A 0xaf
#define XRA_B 0xa8
#define XRA_C 0xa9
#define XRA_D 0xaa
#define XRA_E 0xab
#define XRA_H 0xac
#define XRA_L 0xad
#define XRA_M 0xae
#define XRI 0xee
#define ORA_A 0xb7
#define ORA_B 0xb0
#define ORA_C 0xb1
#define ORA_D 0xb2
#define ORA_E 0xb3
#define ORA_H 0xb4
#define ORA_L 0xb5
#define ORA_M 0xb6
#define ORI 0xf6
#define CMP_A 0xbf
#define CMP_B 0xb8
#define CMP_C 0xb9
#define CMP_D 0xba
#define CMP_E 0xbb
#define CMP_H 0xbc
#define CMP_L 0xbd
#define CMP_M 0xbe
#define CPI 0xfe

/* branch control/program counter load instructions */
#define JMP 0xc3
#define JNZ 0xc2
#define JZ 0xca
#define JNC 0xd2
#define JC 0xda
#define JPO 0xe2
#define JPE 0xea
#define JP 0xf2
#define JM 0xfa
#define PCHL 0xe9
#define CALL 0xcd
#define CNZ 0xc4
#define CZ 0xcc
#define CNC 0xd4
#define CC 0xdc
#define CPO 0xe4
#define CPE 0xec
#define CP 0xf4
#define CM 0xfc
#define RET 0xc9
#define RNZ 0xc0
#define RZ 0xc8
#define RNC 0xd0
#define RC 0xd8
#define RPO 0xe0
#define RPE 0xe8
#define RP 0xf0
#define RM 0xf8
#define RST_0 0xc7
#define RST_1 0xcf
#define RST_2 0xd7
#define RST_3 0xdf
#define RST_4 0xe7
#define RST_5 0xef
#define RST_6 0xf7
#define RST_7 0xff

/* stack operation instructions */
#define PUSH_B 0xc5
#define PUSH_D 0xd5
#define PUSH_H 0xe5
#define PUSH_PSW 0xf5
#define POP_B 0xc1
#define POP_D 0xd1
#define POP_H 0xe1
#define POP_PSW 0xf1

/* input/output instructions */
//#define IN 0xdb
//#define OUT 0xd320

#endif