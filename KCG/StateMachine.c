/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-21T12:18:29
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "StateMachine.h"

/* StateMachine/ */
void StateMachine(inC_StateMachine *inC, outC_StateMachine *outC)
{
  /* @1/IROI_Output/, @1/_L29/, OffBallSignal/, _L9/ */
  kcg_bool _L9;
  /* Local1/ */
  kcg_bool Local1;
  /* SM3: */
  SSM_TR_SM3 SM3_fired_strong;
  /* SM3: */
  kcg_bool SM3_reset_act;
  /* SM3: */
  SSM_ST_SM3 SM3_state_act;
  /* @3/IRIO_Output/, @3/_L10/, StopSignal/, _L18/ */
  kcg_bool StopSignal;
  /* SM3:DriveAndCount: */
  kcg_bool DriveAndCount_weakb_clock_SM3;
  /* SM3:DriveAndCount:CountSM: */
  SSM_ST_CountSM_DriveAndCount_SM3 CountSM_state_sel_DriveAndCount_SM3;
  /* SM3:DriveAndCount:CountSM: */
  SSM_ST_CountSM_DriveAndCount_SM3 CountSM_state_act_DriveAndCount_SM3;
  /* SM3:DriveAndCount:Drive: */
  SSM_ST_Drive_DriveAndCount_SM3 Drive_state_sel_DriveAndCount_SM3;
  /* SM3:DriveAndCount:Drive: */
  SSM_ST_Drive_DriveAndCount_SM3 Drive_state_act_DriveAndCount_SM3;

  _L9 = (kcg_lit_int16(12) >= inC->AverageSonar) & (inC->AverageSonar >
      kcg_lit_int16(0));
  StopSignal = (kcg_lit_int16(1024) > inC->ColorSensor) & (inC->ColorSensor >=
      kcg_lit_int16(570));
  /* SM3: */
  switch (outC->SM3_state_nxt) {
    case SSM_st_Stop_SM3 :
      SM3_reset_act = inC->Start;
      /* SM3:Stop:<1> */
      if (inC->Start) {
        SM3_state_act = SSM_st_DriveAndCount_SM3;
        SM3_fired_strong = SSM_TR_Stop_DriveAndCount_1_Stop_SM3;
        Local1 = kcg_true;
      }
      else {
        SM3_state_act = SSM_st_Stop_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
        Local1 = outC->Local1;
      }
      break;
    case SSM_st_DriveAndCount_SM3 :
      SM3_reset_act = kcg_false;
      SM3_state_act = SSM_st_DriveAndCount_SM3;
      SM3_fired_strong = SSM_TR_no_trans_SM3;
      Local1 = outC->Local1;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM3: */
  switch (SM3_state_act) {
    case SSM_st_Stop_SM3 :
      outC->Local1 = Local1;
      outC->Output3 = outC->Local1;
      outC->SM3_state_nxt = SSM_st_Stop_SM3;
      break;
    case SSM_st_DriveAndCount_SM3 :
      if (SM3_reset_act) {
        outC->init = kcg_true;
      }
      DriveAndCount_weakb_clock_SM3 = SM3_fired_strong != SSM_TR_no_trans_SM3;
      /* SM3:DriveAndCount:CountSM:, SM3:DriveAndCount:Drive: */
      if (outC->init) {
        Drive_state_sel_DriveAndCount_SM3 = SSM_st_Init_Drive_DriveAndCount_SM3;
        CountSM_state_sel_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
      }
      else {
        Drive_state_sel_DriveAndCount_SM3 = outC->Drive_state_nxt_DriveAndCount_SM3;
        CountSM_state_sel_DriveAndCount_SM3 = outC->CountSM_state_nxt_DriveAndCount_SM3;
      }
      /* SM3:DriveAndCount:Drive: */
      switch (Drive_state_sel_DriveAndCount_SM3) {
        case SSM_st_Init_Drive_DriveAndCount_SM3 :
          /* SM3:DriveAndCount:Drive:Init:<1> */
          if (inC->Start) {
            Drive_state_act_DriveAndCount_SM3 = SSM_st_Drive_Drive_DriveAndCount_SM3;
            outC->Speed = kcg_lit_int16(20);
          }
          else {
            Drive_state_act_DriveAndCount_SM3 = SSM_st_Init_Drive_DriveAndCount_SM3;
          }
          break;
        case SSM_st_Drive_Drive_DriveAndCount_SM3 :
          /* SM3:DriveAndCount:Drive:Drive:<1> */
          if (StopSignal) {
            Drive_state_act_DriveAndCount_SM3 = SSM_st_Init_Drive_DriveAndCount_SM3;
            outC->Speed = kcg_lit_int16(0);
          }
          else {
            Drive_state_act_DriveAndCount_SM3 = SSM_st_Drive_Drive_DriveAndCount_SM3;
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* SM3:DriveAndCount:CountSM: */
      switch (CountSM_state_sel_DriveAndCount_SM3) {
        case SSM_st_Count_CountSM_DriveAndCount_SM3 :
          /* SM3:DriveAndCount:CountSM:Count:<1> */
          if (_L9) {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
            outC->Counting = outC->Counting + kcg_lit_uint32(1);
          }
          else {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Count_CountSM_DriveAndCount_SM3;
          }
          break;
        case SSM_st_Wait_CountSM_DriveAndCount_SM3 :
          if ((kcg_lit_int16(256) > inC->AverageSonar) & (inC->AverageSonar >=
              kcg_lit_int16(13))) {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Count_CountSM_DriveAndCount_SM3;
          }
          else {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* SM3:DriveAndCount:CountSM: */
      switch (CountSM_state_act_DriveAndCount_SM3) {
        case SSM_st_Count_CountSM_DriveAndCount_SM3 :
          outC->CountSM_state_nxt_DriveAndCount_SM3 =
            SSM_st_Count_CountSM_DriveAndCount_SM3;
          break;
        case SSM_st_Wait_CountSM_DriveAndCount_SM3 :
          outC->CountSM_state_nxt_DriveAndCount_SM3 =
            SSM_st_Wait_CountSM_DriveAndCount_SM3;
          outC->CountValue = outC->Counting;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      outC->init = kcg_false;
      /* SM3:DriveAndCount: */
      if (DriveAndCount_weakb_clock_SM3) {
        outC->Local1 = Local1;
        outC->SM3_state_nxt = SSM_st_DriveAndCount_SM3;
      }
      else {
        /* SM3:DriveAndCount:<1> */
        if (StopSignal) {
          outC->Local1 = kcg_false;
        }
        else {
          outC->Local1 = Local1;
        }
        if (StopSignal) {
          outC->SM3_state_nxt = SSM_st_Stop_SM3;
        }
        else {
          outC->SM3_state_nxt = SSM_st_DriveAndCount_SM3;
        }
      }
      /* SM3:DriveAndCount:Drive: */
      switch (Drive_state_act_DriveAndCount_SM3) {
        case SSM_st_Init_Drive_DriveAndCount_SM3 :
          outC->Drive_state_nxt_DriveAndCount_SM3 = SSM_st_Init_Drive_DriveAndCount_SM3;
          outC->SpeedValue = outC->Speed;
          break;
        case SSM_st_Drive_Drive_DriveAndCount_SM3 :
          outC->Drive_state_nxt_DriveAndCount_SM3 = SSM_st_Drive_Drive_DriveAndCount_SM3;
          outC->SpeedValue = outC->Speed;
          outC->Output3 = outC->Local1;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
}

#ifndef KCG_USER_DEFINED_INIT
void StateMachine_init(outC_StateMachine *outC)
{
  outC->Local1 = kcg_false;
  outC->Output3 = kcg_false;
  outC->init = kcg_true;
  outC->Drive_state_nxt_DriveAndCount_SM3 = SSM_st_Drive_Drive_DriveAndCount_SM3;
  outC->CountSM_state_nxt_DriveAndCount_SM3 =
    SSM_st_Wait_CountSM_DriveAndCount_SM3;
  outC->SpeedValue = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->Speed = kcg_lit_int16(0);
  outC->SM3_state_nxt = SSM_st_Stop_SM3;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void StateMachine_reset(outC_StateMachine *outC)
{
  outC->Local1 = kcg_false;
  outC->Output3 = kcg_false;
  outC->init = kcg_true;
  outC->SpeedValue = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->Speed = kcg_lit_int16(0);
  outC->SM3_state_nxt = SSM_st_Stop_SM3;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/*
  Expanded instances for: StateMachine/
  @1: (math::InRangeOutIn#1)
  @3: (math::InRangeInOut#2)
*/

/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** StateMachine.c
** Generation date: 2017-09-21T12:18:29
*************************************************************$ */

