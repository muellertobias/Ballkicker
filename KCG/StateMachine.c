/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-21T15:37:53
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "StateMachine.h"

/* StateMachine/ */
void StateMachine(inC_StateMachine *inC, outC_StateMachine *outC)
{
  /* SM3:DriveAndCount:CountSM: */
  SSM_ST_CountSM_DriveAndCount_SM3 CountSM_state_act_DriveAndCount_SM3;
  /* SM3:DriveAndCount:CountSM: */
  SSM_ST_CountSM_DriveAndCount_SM3 CountSM_state_sel_DriveAndCount_SM3;
  /* SM3:DriveAndCount: */
  kcg_bool DriveAndCount_weakb_clock_SM3;
  /* SM3:Kick:Kicking: */
  SSM_ST_Kicking_Kick_SM3 Kicking_state_act_Kick_SM3;
  /* SM3:Kick:Kicking: */
  SSM_ST_Kicking_Kick_SM3 Kicking_state_sel_Kick_SM3;
  /* SM3:, SM3:Free:<1>, SM3:State9: */
  kcg_bool State9_weakb_clock_SM3;
  /* @3/IRIO_Output/, @3/_L10/, StopSignal/, _L18/ */
  kcg_bool StopSignal;
  /* SM3: */
  SSM_ST_SM3 SM3_state_act;
  /* SM3: */
  kcg_bool SM3_reset_act;
  /* SM3: */
  SSM_TR_SM3 SM3_fired_strong;
  /* Speed/ */
  kcg_int16 Speed;
  /* @1/IROI_Output/, @1/_L29/, OffBallSignal/, _L9/ */
  kcg_bool _L9;
  /* @2/IRIO_Output/, @2/_L10/, OnBallSignal/, _L14/ */
  kcg_bool _L14;

  StopSignal = (kcg_lit_int16(1024) > inC->ColorSensor) & (inC->ColorSensor >=
      kcg_lit_int16(570));
  _L14 = (kcg_lit_int16(256) > inC->AverageSonar) & (inC->AverageSonar >=
      kcg_lit_int16(13));
  _L9 = (kcg_lit_int16(12) >= inC->AverageSonar) & (inC->AverageSonar >
      kcg_lit_int16(0));
  /* SM3: */
  switch (outC->SM3_state_nxt) {
    case SSM_st_Free_SM3 :
      State9_weakb_clock_SM3 = !StopSignal;
      SM3_reset_act = State9_weakb_clock_SM3;
      if (State9_weakb_clock_SM3) {
        SM3_state_act = SSM_st_State9_SM3;
        SM3_fired_strong = SSM_TR_Free_State9_1_Free_SM3;
      }
      else {
        SM3_state_act = SSM_st_Free_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
      }
      Speed = outC->Speed;
      break;
    case SSM_st_State9_SM3 :
      SM3_reset_act = _L14;
      /* SM3:State9:<1> */
      if (_L14) {
        SM3_state_act = SSM_st_Kick_SM3;
        SM3_fired_strong = SSM_TR_State9_Kick_1_State9_SM3;
        Speed = kcg_lit_int16(0);
      }
      else {
        SM3_state_act = SSM_st_State9_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Kick_SM3 :
      SM3_reset_act = _L9;
      /* SM3:Kick:<1> */
      if (_L9) {
        SM3_state_act = SSM_st_State9_SM3;
        SM3_fired_strong = SSM_TR_Kick_State9_1_Kick_SM3;
        Speed = kcg_lit_int16(-20);
      }
      else {
        SM3_state_act = SSM_st_Kick_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Stop_SM3 :
      SM3_reset_act = inC->Start;
      /* SM3:Stop:<1> */
      if (inC->Start) {
        SM3_state_act = SSM_st_DriveAndCount_SM3;
        SM3_fired_strong = SSM_TR_Stop_DriveAndCount_1_Stop_SM3;
        Speed = kcg_lit_int16(20);
      }
      else {
        SM3_state_act = SSM_st_Stop_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
        Speed = outC->Speed;
      }
      break;
    case SSM_st_DriveAndCount_SM3 :
      SM3_reset_act = kcg_false;
      SM3_state_act = SSM_st_DriveAndCount_SM3;
      SM3_fired_strong = SSM_TR_no_trans_SM3;
      Speed = outC->Speed;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM3: */
  switch (SM3_state_act) {
    case SSM_st_Free_SM3 :
      outC->ArmSpeedValue = outC->ArmSpeed;
      outC->SM3_state_nxt = SSM_st_Free_SM3;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_State9_SM3 :
      State9_weakb_clock_SM3 = SM3_fired_strong != SSM_TR_no_trans_SM3;
      outC->ArmSpeedValue = outC->ArmSpeed;
      /* SM3:State9: */
      if (State9_weakb_clock_SM3) {
        outC->SM3_state_nxt = SSM_st_State9_SM3;
        outC->SpeedValue = Speed;
      }
      else {
        if (StopSignal) {
          outC->SM3_state_nxt = SSM_st_Stop_SM3;
        }
        else {
          outC->SM3_state_nxt = SSM_st_State9_SM3;
        }
        /* SM3:State9:<2> */
        if (StopSignal) {
          outC->SpeedValue = kcg_lit_int16(0);
        }
        else {
          outC->SpeedValue = Speed;
        }
      }
      break;
    case SSM_st_Kick_SM3 :
      if (SM3_reset_act) {
        outC->init1 = kcg_true;
      }
      /* SM3:Kick:Kicking: */
      if (outC->init1) {
        Kicking_state_sel_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
      }
      else {
        Kicking_state_sel_Kick_SM3 = outC->Kicking_state_nxt_Kick_SM3;
      }
      /* SM3:Kick:Kicking: */
      switch (Kicking_state_sel_Kick_SM3) {
        case SSM_st_State11_Kicking_Kick_SM3 :
          Kicking_state_act_Kick_SM3 = SSM_st_State11_Kicking_Kick_SM3;
          outC->ArmSpeedValue = outC->ArmSpeed;
          break;
        case SSM_st_Backward_Kicking_Kick_SM3 :
          /* SM3:Kick:Kicking:Backward:<1> */
          if (inC->KickFinished) {
            Kicking_state_act_Kick_SM3 = SSM_st_State11_Kicking_Kick_SM3;
            outC->ArmSpeedValue = kcg_lit_int16(0);
          }
          else {
            Kicking_state_act_Kick_SM3 = SSM_st_Backward_Kicking_Kick_SM3;
            outC->ArmSpeedValue = outC->ArmSpeed;
          }
          break;
        case SSM_st_Forward_Kicking_Kick_SM3 :
          /* SM3:Kick:Kicking:Forward:<1> */
          if (inC->KickBackward) {
            Kicking_state_act_Kick_SM3 = SSM_st_Backward_Kicking_Kick_SM3;
            outC->ArmSpeedValue = kcg_lit_int16(-50);
          }
          else {
            Kicking_state_act_Kick_SM3 = SSM_st_Forward_Kicking_Kick_SM3;
            outC->ArmSpeedValue = outC->ArmSpeed;
          }
          break;
        case SSM_st_DriveBack_Kicking_Kick_SM3 :
          /* SM3:Kick:Kicking:DriveBack:<1> */
          if (_L14) {
            Kicking_state_act_Kick_SM3 = SSM_st_Forward_Kicking_Kick_SM3;
            outC->ArmSpeedValue = kcg_lit_int16(50);
          }
          else {
            Kicking_state_act_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
            outC->ArmSpeedValue = outC->ArmSpeed;
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* SM3:Kick:Kicking: */
      switch (Kicking_state_act_Kick_SM3) {
        case SSM_st_State11_Kicking_Kick_SM3 :
          outC->Kicking_state_nxt_Kick_SM3 = SSM_st_State11_Kicking_Kick_SM3;
          break;
        case SSM_st_Backward_Kicking_Kick_SM3 :
          outC->Kicking_state_nxt_Kick_SM3 = SSM_st_Backward_Kicking_Kick_SM3;
          break;
        case SSM_st_Forward_Kicking_Kick_SM3 :
          outC->Kicking_state_nxt_Kick_SM3 = SSM_st_Forward_Kicking_Kick_SM3;
          break;
        case SSM_st_DriveBack_Kicking_Kick_SM3 :
          outC->Kicking_state_nxt_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      outC->SM3_state_nxt = SSM_st_Kick_SM3;
      outC->SpeedValue = Speed;
      outC->init1 = kcg_false;
      break;
    case SSM_st_Stop_SM3 :
      outC->ArmSpeedValue = outC->ArmSpeed;
      outC->SM3_state_nxt = SSM_st_Stop_SM3;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_DriveAndCount_SM3 :
      if (SM3_reset_act) {
        outC->init = kcg_true;
      }
      DriveAndCount_weakb_clock_SM3 = SM3_fired_strong != SSM_TR_no_trans_SM3;
      /* SM3:DriveAndCount:CountSM: */
      if (outC->init) {
        CountSM_state_sel_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
      }
      else {
        CountSM_state_sel_DriveAndCount_SM3 = outC->CountSM_state_nxt_DriveAndCount_SM3;
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
          if (_L14) {
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
      outC->ArmSpeedValue = outC->ArmSpeed;
      /* SM3:DriveAndCount: */
      if (DriveAndCount_weakb_clock_SM3) {
        outC->SM3_state_nxt = SSM_st_DriveAndCount_SM3;
        outC->SpeedValue = Speed;
      }
      else {
        if (StopSignal) {
          outC->SM3_state_nxt = SSM_st_Free_SM3;
        }
        else {
          outC->SM3_state_nxt = SSM_st_DriveAndCount_SM3;
        }
        /* SM3:DriveAndCount:<1> */
        if (StopSignal) {
          outC->SpeedValue = kcg_lit_int16(-20);
        }
        else {
          outC->SpeedValue = Speed;
        }
      }
      outC->init = kcg_false;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  outC->ArmSpeed = outC->ArmSpeedValue;
  outC->Speed = outC->SpeedValue;
}

#ifndef KCG_USER_DEFINED_INIT
void StateMachine_init(outC_StateMachine *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->Kicking_state_nxt_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
  outC->CountSM_state_nxt_DriveAndCount_SM3 =
    SSM_st_Wait_CountSM_DriveAndCount_SM3;
  outC->ArmSpeedValue = kcg_lit_int16(0);
  outC->SpeedValue = kcg_lit_int16(0);
  outC->Speed = kcg_lit_int16(0);
  outC->ArmSpeed = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->SM3_state_nxt = SSM_st_Stop_SM3;
}
#endif /* KCG_USER_DEFINED_INIT */


#ifndef KCG_NO_EXTERN_CALL_TO_RESET
void StateMachine_reset(outC_StateMachine *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->Speed = kcg_lit_int16(0);
  outC->ArmSpeed = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->SM3_state_nxt = SSM_st_Stop_SM3;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/*
  Expanded instances for: StateMachine/
  @3: (math::InRangeInOut#2)
  @1: (math::InRangeOutIn#1)
  @2: (math::InRangeInOut#1)
*/

/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** StateMachine.c
** Generation date: 2017-09-21T15:37:53
*************************************************************$ */

