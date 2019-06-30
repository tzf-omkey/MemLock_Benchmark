/* DO NOT EDIT!  -*- buffer-read-only: t -*- vi:set ro:  */
/* Instruction opcode header for mep.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1996-2018 Free Software Foundation, Inc.

This file is part of the GNU Binutils and/or GDB, the GNU debugger.

   This file is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3, or (at your option)
   any later version.

   It is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
   or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public
   License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street - Fifth Floor, Boston, MA 02110-1301, USA.

*/

#ifndef MEP_OPC_H
#define MEP_OPC_H

#ifdef __cplusplus
extern "C" {
#endif

/* -- opc.h */

#undef  CGEN_DIS_HASH_SIZE
#define CGEN_DIS_HASH_SIZE 1

#undef  CGEN_DIS_HASH
#define CGEN_DIS_HASH(buffer, insn) 0

#define CGEN_VERBOSE_ASSEMBLER_ERRORS

typedef struct
{
  char * name;
  int    config_enum;
  unsigned cpu_flag;
  int    big_endian;
  int    vliw_bits;
  CGEN_ATTR_VALUE_BITSET_TYPE cop16_isa;
  CGEN_ATTR_VALUE_BITSET_TYPE cop32_isa;
  CGEN_ATTR_VALUE_BITSET_TYPE cop48_isa;
  CGEN_ATTR_VALUE_BITSET_TYPE cop64_isa;
  CGEN_ATTR_VALUE_BITSET_TYPE cop_isa;
  CGEN_ATTR_VALUE_BITSET_TYPE core_isa;
  unsigned int option_mask;
} mep_config_map_struct;

extern mep_config_map_struct mep_config_map[];
extern int mep_config_index;

extern void init_mep_all_core_isas_mask (void);
extern void init_mep_all_cop_isas_mask  (void);
extern CGEN_ATTR_VALUE_BITSET_TYPE mep_cop_isa  (void);

#define MEP_CONFIG     (mep_config_map[mep_config_index].config_enum)
#define MEP_CPU        (mep_config_map[mep_config_index].cpu_flag)
#define MEP_OMASK      (mep_config_map[mep_config_index].option_mask)
#define MEP_VLIW       (mep_config_map[mep_config_index].vliw_bits > 0)
#define MEP_VLIW32     (mep_config_map[mep_config_index].vliw_bits == 32)
#define MEP_VLIW64     (mep_config_map[mep_config_index].vliw_bits == 64)
#define MEP_COP16_ISA  (mep_config_map[mep_config_index].cop16_isa)
#define MEP_COP32_ISA  (mep_config_map[mep_config_index].cop32_isa)
#define MEP_COP48_ISA  (mep_config_map[mep_config_index].cop48_isa)
#define MEP_COP64_ISA  (mep_config_map[mep_config_index].cop64_isa)
#define MEP_COP_ISA    (mep_config_map[mep_config_index].cop_isa)
#define MEP_CORE_ISA   (mep_config_map[mep_config_index].core_isa)

/* begin-cop-ip-supported-defines */
#define MEP_IVC2_SUPPORTED 1
/* end-cop-ip-supported-defines */

extern int mep_insn_supported_by_isa (const CGEN_INSN *, CGEN_ATTR_VALUE_BITSET_TYPE *);

/* A mask for all ISAs executed by the core.  */
#define MEP_ALL_CORE_ISAS_MASK mep_all_core_isas_mask
extern CGEN_ATTR_VALUE_BITSET_TYPE mep_all_core_isas_mask;

#define MEP_INSN_CORE_P(insn) ( \
  init_mep_all_core_isas_mask (), \
  mep_insn_supported_by_isa (insn, & MEP_ALL_CORE_ISAS_MASK) \
)

/* A mask for all ISAs executed by a VLIW coprocessor.  */
#define MEP_ALL_COP_ISAS_MASK mep_all_cop_isas_mask
extern CGEN_ATTR_VALUE_BITSET_TYPE mep_all_cop_isas_mask;

#define MEP_INSN_COP_P(insn) ( \
  init_mep_all_cop_isas_mask (), \
  mep_insn_supported_by_isa (insn, & MEP_ALL_COP_ISAS_MASK) \
)

extern int mep_cgen_insn_supported (CGEN_CPU_DESC, const CGEN_INSN *);
extern int mep_cgen_insn_supported_asm (CGEN_CPU_DESC, const CGEN_INSN *);

/* -- asm.c */
/* Enum declaration for mep instruction types.  */
typedef enum cgen_insn_type {
  MEP_INSN_INVALID, MEP_INSN_STCB_R, MEP_INSN_LDCB_R, MEP_INSN_PREF
 , MEP_INSN_PREFD, MEP_INSN_CASB3, MEP_INSN_CASH3, MEP_INSN_CASW3
 , MEP_INSN_SBCP, MEP_INSN_LBCP, MEP_INSN_LBUCP, MEP_INSN_SHCP
 , MEP_INSN_LHCP, MEP_INSN_LHUCP, MEP_INSN_LBUCPA, MEP_INSN_LHUCPA
 , MEP_INSN_LBUCPM0, MEP_INSN_LHUCPM0, MEP_INSN_LBUCPM1, MEP_INSN_LHUCPM1
 , MEP_INSN_UCI, MEP_INSN_DSP, MEP_INSN_DSP0, MEP_INSN_DSP1
 , MEP_INSN_SB, MEP_INSN_SH, MEP_INSN_SW, MEP_INSN_LB
 , MEP_INSN_LH, MEP_INSN_LW, MEP_INSN_LBU, MEP_INSN_LHU
 , MEP_INSN_SW_SP, MEP_INSN_LW_SP, MEP_INSN_SB_TP, MEP_INSN_SH_TP
 , MEP_INSN_SW_TP, MEP_INSN_LB_TP, MEP_INSN_LH_TP, MEP_INSN_LW_TP
 , MEP_INSN_LBU_TP, MEP_INSN_LHU_TP, MEP_INSN_SB16, MEP_INSN_SH16
 , MEP_INSN_SW16, MEP_INSN_LB16, MEP_INSN_LH16, MEP_INSN_LW16
 , MEP_INSN_LBU16, MEP_INSN_LHU16, MEP_INSN_SW24, MEP_INSN_LW24
 , MEP_INSN_EXTB, MEP_INSN_EXTH, MEP_INSN_EXTUB, MEP_INSN_EXTUH
 , MEP_INSN_SSARB, MEP_INSN_MOV, MEP_INSN_MOVI8, MEP_INSN_MOVI16
 , MEP_INSN_MOVU24, MEP_INSN_MOVU16, MEP_INSN_MOVH, MEP_INSN_ADD3
 , MEP_INSN_ADD, MEP_INSN_ADD3I, MEP_INSN_ADVCK3, MEP_INSN_SUB
 , MEP_INSN_SBVCK3, MEP_INSN_NEG, MEP_INSN_SLT3, MEP_INSN_SLTU3
 , MEP_INSN_SLT3I, MEP_INSN_SLTU3I, MEP_INSN_SL1AD3, MEP_INSN_SL2AD3
 , MEP_INSN_ADD3X, MEP_INSN_SLT3X, MEP_INSN_SLTU3X, MEP_INSN_OR
 , MEP_INSN_AND, MEP_INSN_XOR, MEP_INSN_NOR, MEP_INSN_OR3
 , MEP_INSN_AND3, MEP_INSN_XOR3, MEP_INSN_SRA, MEP_INSN_SRL
 , MEP_INSN_SLL, MEP_INSN_SRAI, MEP_INSN_SRLI, MEP_INSN_SLLI
 , MEP_INSN_SLL3, MEP_INSN_FSFT, MEP_INSN_BRA, MEP_INSN_BEQZ
 , MEP_INSN_BNEZ, MEP_INSN_BEQI, MEP_INSN_BNEI, MEP_INSN_BLTI
 , MEP_INSN_BGEI, MEP_INSN_BEQ, MEP_INSN_BNE, MEP_INSN_BSR12
 , MEP_INSN_BSR24, MEP_INSN_JMP, MEP_INSN_JMP24, MEP_INSN_JSR
 , MEP_INSN_RET, MEP_INSN_REPEAT, MEP_INSN_EREPEAT, MEP_INSN_STC_LP
 , MEP_INSN_STC_HI, MEP_INSN_STC_LO, MEP_INSN_STC, MEP_INSN_LDC_LP
 , MEP_INSN_LDC_HI, MEP_INSN_LDC_LO, MEP_INSN_LDC, MEP_INSN_DI
 , MEP_INSN_EI, MEP_INSN_RETI, MEP_INSN_HALT, MEP_INSN_SLEEP
 , MEP_INSN_SWI, MEP_INSN_BREAK, MEP_INSN_SYNCM, MEP_INSN_STCB
 , MEP_INSN_LDCB, MEP_INSN_BSETM, MEP_INSN_BCLRM, MEP_INSN_BNOTM
 , MEP_INSN_BTSTM, MEP_INSN_TAS, MEP_INSN_CACHE, MEP_INSN_MUL
 , MEP_INSN_MULU, MEP_INSN_MULR, MEP_INSN_MULRU, MEP_INSN_MADD
 , MEP_INSN_MADDU, MEP_INSN_MADDR, MEP_INSN_MADDRU, MEP_INSN_DIV
 , MEP_INSN_DIVU, MEP_INSN_DRET, MEP_INSN_DBREAK, MEP_INSN_LDZ
 , MEP_INSN_ABS, MEP_INSN_AVE, MEP_INSN_MIN, MEP_INSN_MAX
 , MEP_INSN_MINU, MEP_INSN_MAXU, MEP_INSN_CLIP, MEP_INSN_CLIPU
 , MEP_INSN_SADD, MEP_INSN_SSUB, MEP_INSN_SADDU, MEP_INSN_SSUBU
 , MEP_INSN_SWCP, MEP_INSN_LWCP, MEP_INSN_SMCP, MEP_INSN_LMCP
 , MEP_INSN_SWCPI, MEP_INSN_LWCPI, MEP_INSN_SMCPI, MEP_INSN_LMCPI
 , MEP_INSN_SWCP16, MEP_INSN_LWCP16, MEP_INSN_SMCP16, MEP_INSN_LMCP16
 , MEP_INSN_SBCPA, MEP_INSN_LBCPA, MEP_INSN_SHCPA, MEP_INSN_LHCPA
 , MEP_INSN_SWCPA, MEP_INSN_LWCPA, MEP_INSN_SMCPA, MEP_INSN_LMCPA
 , MEP_INSN_SBCPM0, MEP_INSN_LBCPM0, MEP_INSN_SHCPM0, MEP_INSN_LHCPM0
 , MEP_INSN_SWCPM0, MEP_INSN_LWCPM0, MEP_INSN_SMCPM0, MEP_INSN_LMCPM0
 , MEP_INSN_SBCPM1, MEP_INSN_LBCPM1, MEP_INSN_SHCPM1, MEP_INSN_LHCPM1
 , MEP_INSN_SWCPM1, MEP_INSN_LWCPM1, MEP_INSN_SMCPM1, MEP_INSN_LMCPM1
 , MEP_INSN_BCPEQ, MEP_INSN_BCPNE, MEP_INSN_BCPAT, MEP_INSN_BCPAF
 , MEP_INSN_SYNCCP, MEP_INSN_JSRV, MEP_INSN_BSRV, MEP_INSN_SIM_SYSCALL
 , MEP_INSN_RI_0, MEP_INSN_RI_1, MEP_INSN_RI_2, MEP_INSN_RI_3
 , MEP_INSN_RI_4, MEP_INSN_RI_5, MEP_INSN_RI_6, MEP_INSN_RI_7
 , MEP_INSN_RI_8, MEP_INSN_RI_9, MEP_INSN_RI_10, MEP_INSN_RI_11
 , MEP_INSN_RI_12, MEP_INSN_RI_13, MEP_INSN_RI_14, MEP_INSN_RI_15
 , MEP_INSN_RI_17, MEP_INSN_RI_20, MEP_INSN_RI_21, MEP_INSN_RI_22
 , MEP_INSN_RI_23, MEP_INSN_RI_26, MEP_INSN_CMOV_CRN_RM, MEP_INSN_CMOV_RN_CRM
 , MEP_INSN_CMOVC_CCRN_RM, MEP_INSN_CMOVC_RN_CCRM, MEP_INSN_CMOVH_CRN_RM, MEP_INSN_CMOVH_RN_CRM
 , MEP_INSN_CMOV_CRN_RM_P0, MEP_INSN_CMOV_RN_CRM_P0, MEP_INSN_CMOVC_CCRN_RM_P0, MEP_INSN_CMOVC_RN_CCRM_P0
 , MEP_INSN_CMOVH_CRN_RM_P0, MEP_INSN_CMOVH_RN_CRM_P0, MEP_INSN_CPADD3_B_C3, MEP_INSN_CPADD3_H_C3
 , MEP_INSN_CPADD3_W_C3, MEP_INSN_CDADD3_C3, MEP_INSN_CPSUB3_B_C3, MEP_INSN_CPSUB3_H_C3
 , MEP_INSN_CPSUB3_W_C3, MEP_INSN_CDSUB3_C3, MEP_INSN_CPAND3_C3, MEP_INSN_CPOR3_C3
 , MEP_INSN_CPNOR3_C3, MEP_INSN_CPXOR3_C3, MEP_INSN_CPSEL_C3, MEP_INSN_CPFSFTBI_C3
 , MEP_INSN_CPFSFTBS0_C3, MEP_INSN_CPFSFTBS1_C3, MEP_INSN_CPUNPACKU_B_C3, MEP_INSN_CPUNPACKU_H_C3
 , MEP_INSN_CPUNPACKU_W_C3, MEP_INSN_CPUNPACKL_B_C3, MEP_INSN_CPUNPACKL_H_C3, MEP_INSN_CPUNPACKL_W_C3
 , MEP_INSN_CPPACKU_B_C3, MEP_INSN_CPPACK_B_C3, MEP_INSN_CPPACK_H_C3, MEP_INSN_CPSRL3_B_C3
 , MEP_INSN_CPSSRL3_B_C3, MEP_INSN_CPSRL3_H_C3, MEP_INSN_CPSSRL3_H_C3, MEP_INSN_CPSRL3_W_C3
 , MEP_INSN_CPSSRL3_W_C3, MEP_INSN_CDSRL3_C3, MEP_INSN_CPSRA3_B_C3, MEP_INSN_CPSSRA3_B_C3
 , MEP_INSN_CPSRA3_H_C3, MEP_INSN_CPSSRA3_H_C3, MEP_INSN_CPSRA3_W_C3, MEP_INSN_CPSSRA3_W_C3
 , MEP_INSN_CDSRA3_C3, MEP_INSN_CPSLL3_B_C3, MEP_INSN_CPSSLL3_B_C3, MEP_INSN_CPSLL3_H_C3
 , MEP_INSN_CPSSLL3_H_C3, MEP_INSN_CPSLL3_W_C3, MEP_INSN_CPSSLL3_W_C3, MEP_INSN_CDSLL3_C3
 , MEP_INSN_CPSLA3_H_C3, MEP_INSN_CPSLA3_W_C3, MEP_INSN_CPSADD3_H_C3, MEP_INSN_CPSADD3_W_C3
 , MEP_INSN_CPSSUB3_H_C3, MEP_INSN_CPSSUB3_W_C3, MEP_INSN_CPEXTUADDU3_B_C3, MEP_INSN_CPEXTUADD3_B_C3
 , MEP_INSN_CPEXTLADDU3_B_C3, MEP_INSN_CPEXTLADD3_B_C3, MEP_INSN_CPEXTUSUBU3_B_C3, MEP_INSN_CPEXTUSUB3_B_C3
 , MEP_INSN_CPEXTLSUBU3_B_C3, MEP_INSN_CPEXTLSUB3_B_C3, MEP_INSN_CPAVEU3_B_C3, MEP_INSN_CPAVE3_B_C3
 , MEP_INSN_CPAVE3_H_C3, MEP_INSN_CPAVE3_W_C3, MEP_INSN_CPADDSRU3_B_C3, MEP_INSN_CPADDSR3_B_C3
 , MEP_INSN_CPADDSR3_H_C3, MEP_INSN_CPADDSR3_W_C3, MEP_INSN_CPABSU3_B_C3, MEP_INSN_CPABS3_B_C3
 , MEP_INSN_CPABS3_H_C3, MEP_INSN_CPMAXU3_B_C3, MEP_INSN_CPMAX3_B_C3, MEP_INSN_CPMAX3_H_C3
 , MEP_INSN_CPMAXU3_W_C3, MEP_INSN_CPMAX3_W_C3, MEP_INSN_CPMINU3_B_C3, MEP_INSN_CPMIN3_B_C3
 , MEP_INSN_CPMIN3_H_C3, MEP_INSN_CPMINU3_W_C3, MEP_INSN_CPMIN3_W_C3, MEP_INSN_CPMOVFRCSAR0_C3
 , MEP_INSN_CPMOVFRCSAR1_C3, MEP_INSN_CPMOVFRCC_C3, MEP_INSN_CPMOVTOCSAR0_C3, MEP_INSN_CPMOVTOCSAR1_C3
 , MEP_INSN_CPMOVTOCC_C3, MEP_INSN_CPMOV_C3, MEP_INSN_CPABSZ_B_C3, MEP_INSN_CPABSZ_H_C3
 , MEP_INSN_CPABSZ_W_C3, MEP_INSN_CPLDZ_H_C3, MEP_INSN_CPLDZ_W_C3, MEP_INSN_CPNORM_H_C3
 , MEP_INSN_CPNORM_W_C3, MEP_INSN_CPHADDU_B_C3, MEP_INSN_CPHADD_B_C3, MEP_INSN_CPHADD_H_C3
 , MEP_INSN_CPHADD_W_C3, MEP_INSN_CPCCADD_B_C3, MEP_INSN_CPBCAST_B_C3, MEP_INSN_CPBCAST_H_C3
 , MEP_INSN_CPBCAST_W_C3, MEP_INSN_CPEXTUU_B_C3, MEP_INSN_CPEXTU_B_C3, MEP_INSN_CPEXTUU_H_C3
 , MEP_INSN_CPEXTU_H_C3, MEP_INSN_CPEXTLU_B_C3, MEP_INSN_CPEXTL_B_C3, MEP_INSN_CPEXTLU_H_C3
 , MEP_INSN_CPEXTL_H_C3, MEP_INSN_CPCASTUB_H_C3, MEP_INSN_CPCASTB_H_C3, MEP_INSN_CPCASTUB_W_C3
 , MEP_INSN_CPCASTB_W_C3, MEP_INSN_CPCASTUH_W_C3, MEP_INSN_CPCASTH_W_C3, MEP_INSN_CDCASTUW_C3
 , MEP_INSN_CDCASTW_C3, MEP_INSN_CPCMPEQZ_B_C3, MEP_INSN_CPCMPEQ_B_C3, MEP_INSN_CPCMPEQ_H_C3
 , MEP_INSN_CPCMPEQ_W_C3, MEP_INSN_CPCMPNE_B_C3, MEP_INSN_CPCMPNE_H_C3, MEP_INSN_CPCMPNE_W_C3
 , MEP_INSN_CPCMPGTU_B_C3, MEP_INSN_CPCMPGT_B_C3, MEP_INSN_CPCMPGT_H_C3, MEP_INSN_CPCMPGTU_W_C3
 , MEP_INSN_CPCMPGT_W_C3, MEP_INSN_CPCMPGEU_B_C3, MEP_INSN_CPCMPGE_B_C3, MEP_INSN_CPCMPGE_H_C3
 , MEP_INSN_CPCMPGEU_W_C3, MEP_INSN_CPCMPGE_W_C3, MEP_INSN_CPACMPEQ_B_C3, MEP_INSN_CPACMPEQ_H_C3
 , MEP_INSN_CPACMPEQ_W_C3, MEP_INSN_CPACMPNE_B_C3, MEP_INSN_CPACMPNE_H_C3, MEP_INSN_CPACMPNE_W_C3
 , MEP_INSN_CPACMPGTU_B_C3, MEP_INSN_CPACMPGT_B_C3, MEP_INSN_CPACMPGT_H_C3, MEP_INSN_CPACMPGTU_W_C3
 , MEP_INSN_CPACMPGT_W_C3, MEP_INSN_CPACMPGEU_B_C3, MEP_INSN_CPACMPGE_B_C3, MEP_INSN_CPACMPGE_H_C3
 , MEP_INSN_CPACMPGEU_W_C3, MEP_INSN_CPACMPGE_W_C3, MEP_INSN_CPOCMPEQ_B_C3, MEP_INSN_CPOCMPEQ_H_C3
 , MEP_INSN_CPOCMPEQ_W_C3, MEP_INSN_CPOCMPNE_B_C3, MEP_INSN_CPOCMPNE_H_C3, MEP_INSN_CPOCMPNE_W_C3
 , MEP_INSN_CPOCMPGTU_B_C3, MEP_INSN_CPOCMPGT_B_C3, MEP_INSN_CPOCMPGT_H_C3, MEP_INSN_CPOCMPGTU_W_C3
 , MEP_INSN_CPOCMPGT_W_C3, MEP_INSN_CPOCMPGEU_B_C3, MEP_INSN_CPOCMPGE_B_C3, MEP_INSN_CPOCMPGE_H_C3
 , MEP_INSN_CPOCMPGEU_W_C3, MEP_INSN_CPOCMPGE_W_C3, MEP_INSN_CPSRLI3_B_C3, MEP_INSN_CPSRLI3_H_C3
 , MEP_INSN_CPSRLI3_W_C3, MEP_INSN_CDSRLI3_C3, MEP_INSN_CPSRAI3_B_C3, MEP_INSN_CPSRAI3_H_C3
 , MEP_INSN_CPSRAI3_W_C3, MEP_INSN_CDSRAI3_C3, MEP_INSN_CPSLLI3_B_C3, MEP_INSN_CPSLLI3_H_C3
 , MEP_INSN_CPSLLI3_W_C3, MEP_INSN_CDSLLI3_C3, MEP_INSN_CPSLAI3_H_C3, MEP_INSN_CPSLAI3_W_C3
 , MEP_INSN_CPCLIPIU3_W_C3, MEP_INSN_CPCLIPI3_W_C3, MEP_INSN_CDCLIPIU3_C3, MEP_INSN_CDCLIPI3_C3
 , MEP_INSN_CPMOVI_B_C3, MEP_INSN_CPMOVIU_H_C3, MEP_INSN_CPMOVI_H_C3, MEP_INSN_CPMOVIU_W_C3
 , MEP_INSN_CPMOVI_W_C3, MEP_INSN_CDMOVIU_C3, MEP_INSN_CDMOVI_C3, MEP_INSN_CPADDA1U_B_C3
 , MEP_INSN_CPADDA1_B_C3, MEP_INSN_CPADDUA1_H_C3, MEP_INSN_CPADDLA1_H_C3, MEP_INSN_CPADDACA1U_B_C3
 , MEP_INSN_CPADDACA1_B_C3, MEP_INSN_CPADDACUA1_H_C3, MEP_INSN_CPADDACLA1_H_C3, MEP_INSN_CPSUBA1U_B_C3
 , MEP_INSN_CPSUBA1_B_C3, MEP_INSN_CPSUBUA1_H_C3, MEP_INSN_CPSUBLA1_H_C3, MEP_INSN_CPSUBACA1U_B_C3
 , MEP_INSN_CPSUBACA1_B_C3, MEP_INSN_CPSUBACUA1_H_C3, MEP_INSN_CPSUBACLA1_H_C3, MEP_INSN_CPABSA1U_B_C3
 , MEP_INSN_CPABSA1_B_C3, MEP_INSN_CPABSUA1_H_C3, MEP_INSN_CPABSLA1_H_C3, MEP_INSN_CPSADA1U_B_C3
 , MEP_INSN_CPSADA1_B_C3, MEP_INSN_CPSADUA1_H_C3, MEP_INSN_CPSADLA1_H_C3, MEP_INSN_CPSETA1_H_C3
 , MEP_INSN_CPSETUA1_W_C3, MEP_INSN_CPSETLA1_W_C3, MEP_INSN_CPMOVA1_B_C3, MEP_INSN_CPMOVUA1_H_C3
 , MEP_INSN_CPMOVLA1_H_C3, MEP_INSN_CPMOVUUA1_W_C3, MEP_INSN_CPMOVULA1_W_C3, MEP_INSN_CPMOVLUA1_W_C3
 , MEP_INSN_CPMOVLLA1_W_C3, MEP_INSN_CPPACKA1U_B_C3, MEP_INSN_CPPACKA1_B_C3, MEP_INSN_CPPACKUA1_H_C3
 , MEP_INSN_CPPACKLA1_H_C3, MEP_INSN_CPPACKUA1_W_C3, MEP_INSN_CPPACKLA1_W_C3, MEP_INSN_CPMOVHUA1_W_C3
 , MEP_INSN_CPMOVHLA1_W_C3, MEP_INSN_CPSRLA1_C3, MEP_INSN_CPSRAA1_C3, MEP_INSN_CPSLLA1_C3
 , MEP_INSN_CPSRLIA1_P1, MEP_INSN_CPSRAIA1_P1, MEP_INSN_CPSLLIA1_P1, MEP_INSN_CPSSQA1U_B_C3
 , MEP_INSN_CPSSQA1_B_C3, MEP_INSN_CPSSDA1U_B_C3, MEP_INSN_CPSSDA1_B_C3, MEP_INSN_CPMULA1U_B_C3
 , MEP_INSN_CPMULA1_B_C3, MEP_INSN_CPMULUA1_H_C3, MEP_INSN_CPMULLA1_H_C3, MEP_INSN_CPMULUA1U_W_C3
 , MEP_INSN_CPMULLA1U_W_C3, MEP_INSN_CPMULUA1_W_C3, MEP_INSN_CPMULLA1_W_C3, MEP_INSN_CPMADA1U_B_C3
 , MEP_INSN_CPMADA1_B_C3, MEP_INSN_CPMADUA1_H_C3, MEP_INSN_CPMADLA1_H_C3, MEP_INSN_CPMADUA1U_W_C3
 , MEP_INSN_CPMADLA1U_W_C3, MEP_INSN_CPMADUA1_W_C3, MEP_INSN_CPMADLA1_W_C3, MEP_INSN_CPMSBUA1_H_C3
 , MEP_INSN_CPMSBLA1_H_C3, MEP_INSN_CPMSBUA1U_W_C3, MEP_INSN_CPMSBLA1U_W_C3, MEP_INSN_CPMSBUA1_W_C3
 , MEP_INSN_CPMSBLA1_W_C3, MEP_INSN_CPSMADUA1_H_C3, MEP_INSN_CPSMADLA1_H_C3, MEP_INSN_CPSMADUA1_W_C3
 , MEP_INSN_CPSMADLA1_W_C3, MEP_INSN_CPSMSBUA1_H_C3, MEP_INSN_CPSMSBLA1_H_C3, MEP_INSN_CPSMSBUA1_W_C3
 , MEP_INSN_CPSMSBLA1_W_C3, MEP_INSN_CPMULSLUA1_H_C3, MEP_INSN_CPMULSLLA1_H_C3, MEP_INSN_CPMULSLUA1_W_C3
 , MEP_INSN_CPMULSLLA1_W_C3, MEP_INSN_CPSMADSLUA1_H_C3, MEP_INSN_CPSMADSLLA1_H_C3, MEP_INSN_CPSMADSLUA1_W_C3
 , MEP_INSN_CPSMADSLLA1_W_C3, MEP_INSN_CPSMSBSLUA1_H_C3, MEP_INSN_CPSMSBSLLA1_H_C3, MEP_INSN_CPSMSBSLUA1_W_C3
 , MEP_INSN_CPSMSBSLLA1_W_C3, MEP_INSN_C0NOP_P0_P0S, MEP_INSN_CPADD3_B_P0S_P1, MEP_INSN_CPADD3_H_P0S_P1
 , MEP_INSN_CPADD3_W_P0S_P1, MEP_INSN_CPUNPACKU_B_P0S_P1, MEP_INSN_CPUNPACKU_H_P0S_P1, MEP_INSN_CPUNPACKU_W_P0S_P1
 , MEP_INSN_CPUNPACKL_B_P0S_P1, MEP_INSN_CPUNPACKL_H_P0S_P1, MEP_INSN_CPUNPACKL_W_P0S_P1, MEP_INSN_CPSEL_P0S_P1
 , MEP_INSN_CPFSFTBS0_P0S_P1, MEP_INSN_CPFSFTBS1_P0S_P1, MEP_INSN_CPMOV_P0S_P1, MEP_INSN_CPABSZ_B_P0S_P1
 , MEP_INSN_CPABSZ_H_P0S_P1, MEP_INSN_CPABSZ_W_P0S_P1, MEP_INSN_CPLDZ_H_P0S_P1, MEP_INSN_CPLDZ_W_P0S_P1
 , MEP_INSN_CPNORM_H_P0S_P1, MEP_INSN_CPNORM_W_P0S_P1, MEP_INSN_CPHADDU_B_P0S_P1, MEP_INSN_CPHADD_B_P0S_P1
 , MEP_INSN_CPHADD_H_P0S_P1, MEP_INSN_CPHADD_W_P0S_P1, MEP_INSN_CPCCADD_B_P0S_P1, MEP_INSN_CPBCAST_B_P0S_P1
 , MEP_INSN_CPBCAST_H_P0S_P1, MEP_INSN_CPBCAST_W_P0S_P1, MEP_INSN_CPEXTUU_B_P0S_P1, MEP_INSN_CPEXTU_B_P0S_P1
 , MEP_INSN_CPEXTUU_H_P0S_P1, MEP_INSN_CPEXTU_H_P0S_P1, MEP_INSN_CPEXTLU_B_P0S_P1, MEP_INSN_CPEXTL_B_P0S_P1
 , MEP_INSN_CPEXTLU_H_P0S_P1, MEP_INSN_CPEXTL_H_P0S_P1, MEP_INSN_CPCASTUB_H_P0S_P1, MEP_INSN_CPCASTB_H_P0S_P1
 , MEP_INSN_CPCASTUB_W_P0S_P1, MEP_INSN_CPCASTB_W_P0S_P1, MEP_INSN_CPCASTUH_W_P0S_P1, MEP_INSN_CPCASTH_W_P0S_P1
 , MEP_INSN_CDCASTUW_P0S_P1, MEP_INSN_CDCASTW_P0S_P1, MEP_INSN_CPMOVFRCSAR0_P0S_P1, MEP_INSN_CPMOVFRCSAR1_P0S_P1
 , MEP_INSN_CPMOVFRCC_P0S_P1, MEP_INSN_CPMOVTOCSAR0_P0S_P1, MEP_INSN_CPMOVTOCSAR1_P0S_P1, MEP_INSN_CPMOVTOCC_P0S_P1
 , MEP_INSN_CPCMPEQZ_B_P0S_P1, MEP_INSN_CPCMPEQ_B_P0S_P1, MEP_INSN_CPCMPEQ_H_P0S_P1, MEP_INSN_CPCMPEQ_W_P0S_P1
 , MEP_INSN_CPCMPNE_B_P0S_P1, MEP_INSN_CPCMPNE_H_P0S_P1, MEP_INSN_CPCMPNE_W_P0S_P1, MEP_INSN_CPCMPGTU_B_P0S_P1
 , MEP_INSN_CPCMPGT_B_P0S_P1, MEP_INSN_CPCMPGT_H_P0S_P1, MEP_INSN_CPCMPGTU_W_P0S_P1, MEP_INSN_CPCMPGT_W_P0S_P1
 , MEP_INSN_CPCMPGEU_B_P0S_P1, MEP_INSN_CPCMPGE_B_P0S_P1, MEP_INSN_CPCMPGE_H_P0S_P1, MEP_INSN_CPCMPGEU_W_P0S_P1
 , MEP_INSN_CPCMPGE_W_P0S_P1, MEP_INSN_CPADDA0U_B_P0S, MEP_INSN_CPADDA0_B_P0S, MEP_INSN_CPADDUA0_H_P0S
 , MEP_INSN_CPADDLA0_H_P0S, MEP_INSN_CPADDACA0U_B_P0S, MEP_INSN_CPADDACA0_B_P0S, MEP_INSN_CPADDACUA0_H_P0S
 , MEP_INSN_CPADDACLA0_H_P0S, MEP_INSN_CPSUBA0U_B_P0S, MEP_INSN_CPSUBA0_B_P0S, MEP_INSN_CPSUBUA0_H_P0S
 , MEP_INSN_CPSUBLA0_H_P0S, MEP_INSN_CPSUBACA0U_B_P0S, MEP_INSN_CPSUBACA0_B_P0S, MEP_INSN_CPSUBACUA0_H_P0S
 , MEP_INSN_CPSUBACLA0_H_P0S, MEP_INSN_CPABSA0U_B_P0S, MEP_INSN_CPABSA0_B_P0S, MEP_INSN_CPABSUA0_H_P0S
 , MEP_INSN_CPABSLA0_H_P0S, MEP_INSN_CPSADA0U_B_P0S, MEP_INSN_CPSADA0_B_P0S, MEP_INSN_CPSADUA0_H_P0S
 , MEP_INSN_CPSADLA0_H_P0S, MEP_INSN_CPSETA0_H_P0S, MEP_INSN_CPSETUA0_W_P0S, MEP_INSN_CPSETLA0_W_P0S
 , MEP_INSN_CPMOVA0_B_P0S, MEP_INSN_CPMOVUA0_H_P0S, MEP_INSN_CPMOVLA0_H_P0S, MEP_INSN_CPMOVUUA0_W_P0S
 , MEP_INSN_CPMOVULA0_W_P0S, MEP_INSN_CPMOVLUA0_W_P0S, MEP_INSN_CPMOVLLA0_W_P0S, MEP_INSN_CPPACKA0U_B_P0S
 , MEP_INSN_CPPACKA0_B_P0S, MEP_INSN_CPPACKUA0_H_P0S, MEP_INSN_CPPACKLA0_H_P0S, MEP_INSN_CPPACKUA0_W_P0S
 , MEP_INSN_CPPACKLA0_W_P0S, MEP_INSN_CPMOVHUA0_W_P0S, MEP_INSN_CPMOVHLA0_W_P0S, MEP_INSN_CPACSUMA0_P0S
 , MEP_INSN_CPACCPA0_P0S, MEP_INSN_CPSRLA0_P0S, MEP_INSN_CPSRAA0_P0S, MEP_INSN_CPSLLA0_P0S
 , MEP_INSN_CPSRLIA0_P0S, MEP_INSN_CPSRAIA0_P0S, MEP_INSN_CPSLLIA0_P0S, MEP_INSN_CPFSFTBA0S0U_B_P0S
 , MEP_INSN_CPFSFTBA0S0_B_P0S, MEP_INSN_CPFSFTBUA0S0_H_P0S, MEP_INSN_CPFSFTBLA0S0_H_P0S, MEP_INSN_CPFACA0S0U_B_P0S
 , MEP_INSN_CPFACA0S0_B_P0S, MEP_INSN_CPFACUA0S0_H_P0S, MEP_INSN_CPFACLA0S0_H_P0S, MEP_INSN_CPFSFTBA0S1U_B_P0S
 , MEP_INSN_CPFSFTBA0S1_B_P0S, MEP_INSN_CPFSFTBUA0S1_H_P0S, MEP_INSN_CPFSFTBLA0S1_H_P0S, MEP_INSN_CPFACA0S1U_B_P0S
 , MEP_INSN_CPFACA0S1_B_P0S, MEP_INSN_CPFACUA0S1_H_P0S, MEP_INSN_CPFACLA0S1_H_P0S, MEP_INSN_CPFSFTBI_P0_P1
 , MEP_INSN_CPACMPEQ_B_P0_P1, MEP_INSN_CPACMPEQ_H_P0_P1, MEP_INSN_CPACMPEQ_W_P0_P1, MEP_INSN_CPACMPNE_B_P0_P1
 , MEP_INSN_CPACMPNE_H_P0_P1, MEP_INSN_CPACMPNE_W_P0_P1, MEP_INSN_CPACMPGTU_B_P0_P1, MEP_INSN_CPACMPGT_B_P0_P1
 , MEP_INSN_CPACMPGT_H_P0_P1, MEP_INSN_CPACMPGTU_W_P0_P1, MEP_INSN_CPACMPGT_W_P0_P1, MEP_INSN_CPACMPGEU_B_P0_P1
 , MEP_INSN_CPACMPGE_B_P0_P1, MEP_INSN_CPACMPGE_H_P0_P1, MEP_INSN_CPACMPGEU_W_P0_P1, MEP_INSN_CPACMPGE_W_P0_P1
 , MEP_INSN_CPOCMPEQ_B_P0_P1, MEP_INSN_CPOCMPEQ_H_P0_P1, MEP_INSN_CPOCMPEQ_W_P0_P1, MEP_INSN_CPOCMPNE_B_P0_P1
 , MEP_INSN_CPOCMPNE_H_P0_P1, MEP_INSN_CPOCMPNE_W_P0_P1, MEP_INSN_CPOCMPGTU_B_P0_P1, MEP_INSN_CPOCMPGT_B_P0_P1
 , MEP_INSN_CPOCMPGT_H_P0_P1, MEP_INSN_CPOCMPGTU_W_P0_P1, MEP_INSN_CPOCMPGT_W_P0_P1, MEP_INSN_CPOCMPGEU_B_P0_P1
 , MEP_INSN_CPOCMPGE_B_P0_P1, MEP_INSN_CPOCMPGE_H_P0_P1, MEP_INSN_CPOCMPGEU_W_P0_P1, MEP_INSN_CPOCMPGE_W_P0_P1
 , MEP_INSN_CDADD3_P0_P1, MEP_INSN_CPSUB3_B_P0_P1, MEP_INSN_CPSUB3_H_P0_P1, MEP_INSN_CPSUB3_W_P0_P1
 , MEP_INSN_CDSUB3_P0_P1, MEP_INSN_CPSADD3_H_P0_P1, MEP_INSN_CPSADD3_W_P0_P1, MEP_INSN_CPSSUB3_H_P0_P1
 , MEP_INSN_CPSSUB3_W_P0_P1, MEP_INSN_CPEXTUADDU3_B_P0_P1, MEP_INSN_CPEXTUADD3_B_P0_P1, MEP_INSN_CPEXTLADDU3_B_P0_P1
 , MEP_INSN_CPEXTLADD3_B_P0_P1, MEP_INSN_CPEXTUSUBU3_B_P0_P1, MEP_INSN_CPEXTUSUB3_B_P0_P1, MEP_INSN_CPEXTLSUBU3_B_P0_P1
 , MEP_INSN_CPEXTLSUB3_B_P0_P1, MEP_INSN_CPAVEU3_B_P0_P1, MEP_INSN_CPAVE3_B_P0_P1, MEP_INSN_CPAVE3_H_P0_P1
 , MEP_INSN_CPAVE3_W_P0_P1, MEP_INSN_CPADDSRU3_B_P0_P1, MEP_INSN_CPADDSR3_B_P0_P1, MEP_INSN_CPADDSR3_H_P0_P1
 , MEP_INSN_CPADDSR3_W_P0_P1, MEP_INSN_CPABSU3_B_P0_P1, MEP_INSN_CPABS3_B_P0_P1, MEP_INSN_CPABS3_H_P0_P1
 , MEP_INSN_CPAND3_P0_P1, MEP_INSN_CPOR3_P0_P1, MEP_INSN_CPNOR3_P0_P1, MEP_INSN_CPXOR3_P0_P1
 , MEP_INSN_CPPACKU_B_P0_P1, MEP_INSN_CPPACK_B_P0_P1, MEP_INSN_CPPACK_H_P0_P1, MEP_INSN_CPMAXU3_B_P0_P1
 , MEP_INSN_CPMAX3_B_P0_P1, MEP_INSN_CPMAX3_H_P0_P1, MEP_INSN_CPMAXU3_W_P0_P1, MEP_INSN_CPMAX3_W_P0_P1
 , MEP_INSN_CPMINU3_B_P0_P1, MEP_INSN_CPMIN3_B_P0_P1, MEP_INSN_CPMIN3_H_P0_P1, MEP_INSN_CPMINU3_W_P0_P1
 , MEP_INSN_CPMIN3_W_P0_P1, MEP_INSN_CPSRL3_B_P0_P1, MEP_INSN_CPSSRL3_B_P0_P1, MEP_INSN_CPSRL3_H_P0_P1
 , MEP_INSN_CPSSRL3_H_P0_P1, MEP_INSN_CPSRL3_W_P0_P1, MEP_INSN_CPSSRL3_W_P0_P1, MEP_INSN_CDSRL3_P0_P1
 , MEP_INSN_CPSRA3_B_P0_P1, MEP_INSN_CPSSRA3_B_P0_P1, MEP_INSN_CPSRA3_H_P0_P1, MEP_INSN_CPSSRA3_H_P0_P1
 , MEP_INSN_CPSRA3_W_P0_P1, MEP_INSN_CPSSRA3_W_P0_P1, MEP_INSN_CDSRA3_P0_P1, MEP_INSN_CPSLL3_B_P0_P1
 , MEP_INSN_CPSSLL3_B_P0_P1, MEP_INSN_CPSLL3_H_P0_P1, MEP_INSN_CPSSLL3_H_P0_P1, MEP_INSN_CPSLL3_W_P0_P1
 , MEP_INSN_CPSSLL3_W_P0_P1, MEP_INSN_CDSLL3_P0_P1, MEP_INSN_CPSLA3_H_P0_P1, MEP_INSN_CPSLA3_W_P0_P1
 , MEP_INSN_CPSRLI3_B_P0_P1, MEP_INSN_CPSRLI3_H_P0_P1, MEP_INSN_CPSRLI3_W_P0_P1, MEP_INSN_CDSRLI3_P0_P1
 , MEP_INSN_CPSRAI3_B_P0_P1, MEP_INSN_CPSRAI3_H_P0_P1, MEP_INSN_CPSRAI3_W_P0_P1, MEP_INSN_CDSRAI3_P0_P1
 , MEP_INSN_CPSLLI3_B_P0_P1, MEP_INSN_CPSLLI3_H_P0_P1, MEP_INSN_CPSLLI3_W_P0_P1, MEP_INSN_CDSLLI3_P0_P1
 , MEP_INSN_CPSLAI3_H_P0_P1, MEP_INSN_CPSLAI3_W_P0_P1, MEP_INSN_CPCLIPIU3_W_P0_P1, MEP_INSN_CPCLIPI3_W_P0_P1
 , MEP_INSN_CDCLIPIU3_P0_P1, MEP_INSN_CDCLIPI3_P0_P1, MEP_INSN_CPMOVI_H_P0_P1, MEP_INSN_CPMOVIU_W_P0_P1
 , MEP_INSN_CPMOVI_W_P0_P1, MEP_INSN_CDMOVIU_P0_P1, MEP_INSN_CDMOVI_P0_P1, MEP_INSN_C1NOP_P1
 , MEP_INSN_CPMOVI_B_P0S_P1, MEP_INSN_CPADDA1U_B_P1, MEP_INSN_CPADDA1_B_P1, MEP_INSN_CPADDUA1_H_P1
 , MEP_INSN_CPADDLA1_H_P1, MEP_INSN_CPADDACA1U_B_P1, MEP_INSN_CPADDACA1_B_P1, MEP_INSN_CPADDACUA1_H_P1
 , MEP_INSN_CPADDACLA1_H_P1, MEP_INSN_CPSUBA1U_B_P1, MEP_INSN_CPSUBA1_B_P1, MEP_INSN_CPSUBUA1_H_P1
 , MEP_INSN_CPSUBLA1_H_P1, MEP_INSN_CPSUBACA1U_B_P1, MEP_INSN_CPSUBACA1_B_P1, MEP_INSN_CPSUBACUA1_H_P1
 , MEP_INSN_CPSUBACLA1_H_P1, MEP_INSN_CPABSA1U_B_P1, MEP_INSN_CPABSA1_B_P1, MEP_INSN_CPABSUA1_H_P1
 , MEP_INSN_CPABSLA1_H_P1, MEP_INSN_CPSADA1U_B_P1, MEP_INSN_CPSADA1_B_P1, MEP_INSN_CPSADUA1_H_P1
 , MEP_INSN_CPSADLA1_H_P1, MEP_INSN_CPSETA1_H_P1, MEP_INSN_CPSETUA1_W_P1, MEP_INSN_CPSETLA1_W_P1
 , MEP_INSN_CPMOVA1_B_P1, MEP_INSN_CPMOVUA1_H_P1, MEP_INSN_CPMOVLA1_H_P1, MEP_INSN_CPMOVUUA1_W_P1
 , MEP_INSN_CPMOVULA1_W_P1, MEP_INSN_CPMOVLUA1_W_P1, MEP_INSN_CPMOVLLA1_W_P1, MEP_INSN_CPPACKA1U_B_P1
 , MEP_INSN_CPPACKA1_B_P1, MEP_INSN_CPPACKUA1_H_P1, MEP_INSN_CPPACKLA1_H_P1, MEP_INSN_CPPACKUA1_W_P1
 , MEP_INSN_CPPACKLA1_W_P1, MEP_INSN_CPMOVHUA1_W_P1, MEP_INSN_CPMOVHLA1_W_P1, MEP_INSN_CPACSUMA1_P1
 , MEP_INSN_CPACCPA1_P1, MEP_INSN_CPACSWP_P1, MEP_INSN_CPSRLA1_P1, MEP_INSN_CPSRAA1_P1
 , MEP_INSN_CPSLLA1_P1, MEP_INSN_CPSRLIA1_1_P1, MEP_INSN_CPSRAIA1_1_P1, MEP_INSN_CPSLLIA1_1_P1
 , MEP_INSN_CPFMULIA1S0U_B_P1, MEP_INSN_CPFMULIA1S0_B_P1, MEP_INSN_CPFMULIUA1S0_H_P1, MEP_INSN_CPFMULILA1S0_H_P1
 , MEP_INSN_CPFMADIA1S0U_B_P1, MEP_INSN_CPFMADIA1S0_B_P1, MEP_INSN_CPFMADIUA1S0_H_P1, MEP_INSN_CPFMADILA1S0_H_P1
 , MEP_INSN_CPFMULIA1S1U_B_P1, MEP_INSN_CPFMULIA1S1_B_P1, MEP_INSN_CPFMULIUA1S1_H_P1, MEP_INSN_CPFMULILA1S1_H_P1
 , MEP_INSN_CPFMADIA1S1U_B_P1, MEP_INSN_CPFMADIA1S1_B_P1, MEP_INSN_CPFMADIUA1S1_H_P1, MEP_INSN_CPFMADILA1S1_H_P1
 , MEP_INSN_CPAMULIA1U_B_P1, MEP_INSN_CPAMULIA1_B_P1, MEP_INSN_CPAMULIUA1_H_P1, MEP_INSN_CPAMULILA1_H_P1
 , MEP_INSN_CPAMADIA1U_B_P1, MEP_INSN_CPAMADIA1_B_P1, MEP_INSN_CPAMADIUA1_H_P1, MEP_INSN_CPAMADILA1_H_P1
 , MEP_INSN_CPFMULIA1U_B_P1, MEP_INSN_CPFMULIA1_B_P1, MEP_INSN_CPFMULIUA1_H_P1, MEP_INSN_CPFMULILA1_H_P1
 , MEP_INSN_CPFMADIA1U_B_P1, MEP_INSN_CPFMADIA1_B_P1, MEP_INSN_CPFMADIUA1_H_P1, MEP_INSN_CPFMADILA1_H_P1
 , MEP_INSN_CPSSQA1U_B_P1, MEP_INSN_CPSSQA1_B_P1, MEP_INSN_CPSSDA1U_B_P1, MEP_INSN_CPSSDA1_B_P1
 , MEP_INSN_CPMULA1U_B_P1, MEP_INSN_CPMULA1_B_P1, MEP_INSN_CPMULUA1_H_P1, MEP_INSN_CPMULLA1_H_P1
 , MEP_INSN_CPMULUA1U_W_P1, MEP_INSN_CPMULLA1U_W_P1, MEP_INSN_CPMULUA1_W_P1, MEP_INSN_CPMULLA1_W_P1
 , MEP_INSN_CPMADA1U_B_P1, MEP_INSN_CPMADA1_B_P1, MEP_INSN_CPMADUA1_H_P1, MEP_INSN_CPMADLA1_H_P1
 , MEP_INSN_CPMADUA1U_W_P1, MEP_INSN_CPMADLA1U_W_P1, MEP_INSN_CPMADUA1_W_P1, MEP_INSN_CPMADLA1_W_P1
 , MEP_INSN_CPMSBUA1_H_P1, MEP_INSN_CPMSBLA1_H_P1, MEP_INSN_CPMSBUA1U_W_P1, MEP_INSN_CPMSBLA1U_W_P1
 , MEP_INSN_CPMSBUA1_W_P1, MEP_INSN_CPMSBLA1_W_P1, MEP_INSN_CPSMADUA1_H_P1, MEP_INSN_CPSMADLA1_H_P1
 , MEP_INSN_CPSMADUA1_W_P1, MEP_INSN_CPSMADLA1_W_P1, MEP_INSN_CPSMSBUA1_H_P1, MEP_INSN_CPSMSBLA1_H_P1
 , MEP_INSN_CPSMSBUA1_W_P1, MEP_INSN_CPSMSBLA1_W_P1, MEP_INSN_CPMULSLUA1_H_P1, MEP_INSN_CPMULSLLA1_H_P1
 , MEP_INSN_CPMULSLUA1_W_P1, MEP_INSN_CPMULSLLA1_W_P1, MEP_INSN_CPSMADSLUA1_H_P1, MEP_INSN_CPSMADSLLA1_H_P1
 , MEP_INSN_CPSMADSLUA1_W_P1, MEP_INSN_CPSMADSLLA1_W_P1, MEP_INSN_CPSMSBSLUA1_H_P1, MEP_INSN_CPSMSBSLLA1_H_P1
 , MEP_INSN_CPSMSBSLUA1_W_P1, MEP_INSN_CPSMSBSLLA1_W_P1
} CGEN_INSN_TYPE;

/* Index of `invalid' insn place holder.  */
#define CGEN_INSN_INVALID MEP_INSN_INVALID

/* Total number of insns in table.  */
#define MAX_INSNS ((int) MEP_INSN_CPSMSBSLLA1_W_P1 + 1)

/* This struct records data prior to insertion or after extraction.  */
struct cgen_fields
{
  int length;
  long f_nil;
  long f_anyof;
  long f_major;
  long f_rn;
  long f_rn3;
  long f_rm;
  long f_rl;
  long f_sub2;
  long f_sub3;
  long f_sub4;
  long f_ext;
  long f_ext4;
  long f_ext62;
  long f_crn;
  long f_csrn_hi;
  long f_csrn_lo;
  long f_csrn;
  long f_crnx_hi;
  long f_crnx_lo;
  long f_crnx;
  long f_0;
  long f_1;
  long f_2;
  long f_3;
  long f_4;
  long f_5;
  long f_6;
  long f_7;
  long f_8;
  long f_9;
  long f_10;
  long f_11;
  long f_12;
  long f_13;
  long f_14;
  long f_15;
  long f_16;
  long f_17;
  long f_18;
  long f_19;
  long f_20;
  long f_21;
  long f_22;
  long f_23;
  long f_24;
  long f_25;
  long f_26;
  long f_27;
  long f_28;
  long f_29;
  long f_30;
  long f_31;
  long f_8s8a2;
  long f_12s4a2;
  long f_17s16a2;
  long f_24s5a2n_hi;
  long f_24s5a2n_lo;
  long f_24s5a2n;
  long f_24u5a2n_hi;
  long f_24u5a2n_lo;
  long f_24u5a2n;
  long f_2u6;
  long f_7u9;
  long f_7u9a2;
  long f_7u9a4;
  long f_16s16;
  long f_2u10;
  long f_3u5;
  long f_4u8;
  long f_5u8;
  long f_5u24;
  long f_6s8;
  long f_8s8;
  long f_16u16;
  long f_12u16;
  long f_3u29;
  long f_cdisp10;
  long f_24u8a4n_hi;
  long f_24u8a4n_lo;
  long f_24u8a4n;
  long f_24u8n_hi;
  long f_24u8n_lo;
  long f_24u8n;
  long f_24u4n_hi;
  long f_24u4n_lo;
  long f_24u4n;
  long f_callnum;
  long f_ccrn_hi;
  long f_ccrn_lo;
  long f_ccrn;
  long f_c5n4;
  long f_c5n5;
  long f_c5n6;
  long f_c5n7;
  long f_rl5;
  long f_12s20;
  long f_c5_rnm;
  long f_c5_rm;
  long f_c5_16u16;
  long f_c5_rmuimm20;
  long f_c5_rnmuimm24;
  long f_ivc2_2u4;
  long f_ivc2_3u4;
  long f_ivc2_8u4;
  long f_ivc2_8s4;
  long f_ivc2_1u6;
  long f_ivc2_2u6;
  long f_ivc2_3u6;
  long f_ivc2_6u6;
  long f_ivc2_5u7;
  long f_ivc2_4u8;
  long f_ivc2_3u9;
  long f_ivc2_5u16;
  long f_ivc2_5u21;
  long f_ivc2_5u26;
  long f_ivc2_1u31;
  long f_ivc2_4u16;
  long f_ivc2_4u20;
  long f_ivc2_4u24;
  long f_ivc2_4u28;
  long f_ivc2_2u0;
  long f_ivc2_3u0;
  long f_ivc2_4u0;
  long f_ivc2_5u0;
  long f_ivc2_8u0;
  long f_ivc2_8s0;
  long f_ivc2_6u2;
  long f_ivc2_5u3;
  long f_ivc2_4u4;
  long f_ivc2_3u5;
  long f_ivc2_5u8;
  long f_ivc2_4u10;
  long f_ivc2_3u12;
  long f_ivc2_5u13;
  long f_ivc2_2u18;
  long f_ivc2_5u18;
  long f_ivc2_8u20;
  long f_ivc2_8s20;
  long f_ivc2_5u23;
  long f_ivc2_2u23;
  long f_ivc2_3u25;
  long f_ivc2_imm16p0;
  long f_ivc2_simm16p0;
  long f_ivc2_ccrn_c3hi;
  long f_ivc2_ccrn_c3lo;
  long f_ivc2_crn;
  long f_ivc2_crm;
  long f_ivc2_ccrn_h1;
  long f_ivc2_ccrn_h2;
  long f_ivc2_ccrn_lo;
  long f_ivc2_cmov1;
  long f_ivc2_cmov2;
  long f_ivc2_cmov3;
  long f_ivc2_ccrn_c3;
  long f_ivc2_ccrn;
  long f_ivc2_crnx;
};

#define CGEN_INIT_PARSE(od) \
{\
}
#define CGEN_INIT_INSERT(od) \
{\
}
#define CGEN_INIT_EXTRACT(od) \
{\
}
#define CGEN_INIT_PRINT(od) \
{\
}


   #ifdef __cplusplus
   }
   #endif

#endif /* MEP_OPC_H */
