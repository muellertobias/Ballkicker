/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-11T14:21:06
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "StateMachine.h"

/* StateMachine/ */
void StateMachine(inC_StateMachine *inC, outC_StateMachine *outC)
{
  /* SM2: */
  SSM_ST_SM2 SM2_state_act;
  /* CountSM: */
  SSM_ST_CountSM CountSM_state_act;
  /* @1/IROI_Output/, @1/_L29/, OnBallSignal/, SM2:, SM2:Drive:<1>, _L9/ */
  kcg_bool tr_1_clock_Drive_SM2;

  tr_1_clock_Drive_SM2 = (kcg_lit_int16(100) >= inC->AverageSonar) &
    (inC->AverageSonar > kcg_lit_int16(0));
  /* CountSM: */
  switch (outC->CountSM_state_nxt) {
    case SSM_st_Count_CountSM :
      if ((kcg_lit_int16(256) > inC->AverageSonar) & (inC->AverageSonar >=
          kcg_lit_int16(101))) {
        CountSM_state_act = SSM_st_Wait_CountSM;
      }
      else {
        CountSM_state_act = SSM_st_Count_CountSM;
      }
      break;
    case SSM_st_Wait_CountSM :
      /* CountSM:Wait:<1> */
      if (tr_1_clock_Drive_SM2) {
        CountSM_state_act = SSM_st_Count_CountSM;
        outC->Counting = outC->Counting + kcg_lit_uint32(1);
      }
      else {
        CountSM_state_act = SSM_st_Wait_CountSM;
      }
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* CountSM: */
  switch (CountSM_state_act) {
    case SSM_st_Count_CountSM :
      outC->CountValue = outC->Counting;
      outC->CountSM_state_nxt = SSM_st_Count_CountSM;
      break;
    case SSM_st_Wait_CountSM :
      outC->CountSM_state_nxt = SSM_st_Wait_CountSM;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM2: */
  switch (outC->SM2_state_nxt) {
    case SSM_st_Init_SM2 :
      /* SM2:Init:<1> */
      if (inC->Start) {
        SM2_state_act = SSM_st_Drive_SM2;
        outC->Speed = kcg_lit_int16(20);
      }
      else {
        SM2_state_act = SSM_st_Init_SM2;
      }
      break;
    case SSM_st_Drive_SM2 :
      tr_1_clock_Drive_SM2 = outC->CountValue == kcg_lit_uint32(3);
      /* SM2:Drive:<1> */
      if (tr_1_clock_Drive_SM2) {
        SM2_state_act = SSM_st_Init_SM2;
        outC->Speed = kcg_lit_int16(0);
      }
      else {
        SM2_state_act = SSM_st_Drive_SM2;
      }
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM2: */
  switch (SM2_state_act) {
    case SSM_st_Init_SM2 :
      outC->SpeedValue = outC->Speed;
      outC->SM2_state_nxt = SSM_st_Init_SM2;
      break;
    case SSM_st_Drive_SM2 :
      outC->SpeedValue = outC->Speed;
      outC->SM2_state_nxt = SSM_st_Drive_SM2;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void StateMachine_init(outC_StateMachine *outC)
{
  outC->SpeedValue = kcg_lit_int16(0);
  outC->Speed = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->CountSM_state_nxt = SSM_st_Wait_CountSM;
  outC->SM2_state_nxt = SSM_st_Init_SM2;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void StateMachine_reset(outC_StateMachine *outC)
{
  outC->Speed = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->CountSM_state_nxt = SSM_st_Wait_CountSM;
  outC->SM2_state_nxt = SSM_st_Init_SM2;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/*
  Expanded instances for: StateMachine/
  @1: (math::InRangeOutIn#1)
*/

/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** StateMachine.c
** Generation date: 2017-09-11T14:21:06
*************************************************************$ */

