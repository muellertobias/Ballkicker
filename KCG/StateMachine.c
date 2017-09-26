/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** Command: kcg66.exe -config D:/Development/Scadet/RobotTar/KCG/config.txt
** Generation date: 2017-09-26T15:13:06
*************************************************************$ */

#include "kcg_consts.h"
#include "kcg_sensors.h"
#include "StateMachine.h"

/* StateMachine/ */
void StateMachine(inC_StateMachine *inC, outC_StateMachine *outC)
{
  /* @2/IRIO_Output/, @2/_L10/, OnBallSignal/, _L14/ */
  kcg_bool _L14;
  /* @1/IROI_Output/, @1/_L29/, OffBallSignal/, _L9/ */
  kcg_bool _L9;
  /* _kicks/ */
  kcg_int16 _kicks;
  /* Speed/ */
  kcg_int16 Speed;
  /* SM3: */
  SSM_TR_SM3 SM3_fired_strong;
  /* SM3: */
  kcg_bool SM3_reset_act;
  /* SM3: */
  SSM_ST_SM3 SM3_state_act;
  /* SM3:Kick: */
  kcg_bool Kick_weakb_clock_SM3;
  /* SM3:Kick:Kicking: */
  SSM_ST_Kicking_Kick_SM3 Kicking_state_sel_Kick_SM3;
  /* SM3:Kick:Kicking: */
  SSM_ST_Kicking_Kick_SM3 Kicking_state_act_Kick_SM3;
  /* SM3:, SM3:DriveAndCount:, SM3:Free:<1> */
  kcg_bool DriveAndCount_weakb_clock_SM3;
  /* SM3:DriveAndCount:CountSM: */
  SSM_ST_CountSM_DriveAndCount_SM3 CountSM_state_sel_DriveAndCount_SM3;
  /* SM3:DriveAndCount:CountSM: */
  SSM_ST_CountSM_DriveAndCount_SM3 CountSM_state_act_DriveAndCount_SM3;

  _L14 = (kcg_lit_int16(256) > inC->AverageSonar) & (inC->AverageSonar >=
      kcg_lit_int16(16));
  _L9 = (kcg_lit_int16(15) >= inC->AverageSonar) & (inC->AverageSonar >
      kcg_lit_int16(0));
  /* SM3: */
  switch (outC->SM3_state_nxt) {
    case SSM_st_Free_SM3 :
      DriveAndCount_weakb_clock_SM3 = !inC->Stop;
      SM3_reset_act = DriveAndCount_weakb_clock_SM3;
      /* SM3:Free:<1> */
      if (DriveAndCount_weakb_clock_SM3) {
        SM3_state_act = SSM_st_Kicking_SM3;
        SM3_fired_strong = SSM_TR_Free_Kicking_1_Free_SM3;
        _kicks = kcg_lit_int16(0);
      }
      else {
        SM3_state_act = SSM_st_Free_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
        _kicks = outC->_kicks;
      }
      Speed = outC->Speed;
      break;
    case SSM_st_Kicking_SM3 :
      SM3_reset_act = _L14 | inC->Stop;
      _kicks = outC->_kicks;
      /* SM3:Kicking:<1> */
      if (_L14) {
        SM3_state_act = SSM_st_Kick_SM3;
        SM3_fired_strong = SSM_TR_Kicking_Kick_1_Kicking_SM3;
        Speed = kcg_lit_int16(0);
      }
      else /* SM3:Kicking:<2> */
      if (inC->Stop) {
        SM3_state_act = SSM_st_Stop_SM3;
        SM3_fired_strong = SSM_TR_Kicking_Stop_2_Kicking_SM3;
        Speed = kcg_lit_int16(0);
      }
      else {
        SM3_state_act = SSM_st_Kicking_SM3;
        SM3_fired_strong = SSM_TR_no_trans_SM3;
        Speed = outC->Speed;
      }
      break;
    case SSM_st_Kick_SM3 :
      SM3_reset_act = kcg_false;
      SM3_state_act = SSM_st_Kick_SM3;
      SM3_fired_strong = SSM_TR_no_trans_SM3;
      _kicks = outC->_kicks;
      Speed = outC->Speed;
      break;
    case SSM_st_Stop_SM3 :
      SM3_reset_act = inC->Start;
      _kicks = outC->_kicks;
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
      _kicks = outC->_kicks;
      Speed = outC->Speed;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  /* SM3: */
  switch (SM3_state_act) {
    case SSM_st_Free_SM3 :
      outC->_kicks = _kicks;
      outC->CountValue = outC->Counting;
      outC->ArmSpeedValue = outC->ArmSpeed;
      outC->SM3_state_nxt = SSM_st_Free_SM3;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Kicking_SM3 :
      outC->_kicks = _kicks;
      outC->CountValue = outC->Counting;
      outC->ArmSpeedValue = outC->ArmSpeed;
      outC->SM3_state_nxt = SSM_st_Kicking_SM3;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_Kick_SM3 :
      if (SM3_reset_act) {
        outC->init = kcg_true;
      }
      Kick_weakb_clock_SM3 = SM3_fired_strong != SSM_TR_no_trans_SM3;
      /* SM3:Kick:Kicking: */
      if (outC->init) {
        Kicking_state_sel_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
      }
      else {
        Kicking_state_sel_Kick_SM3 = outC->Kicking_state_nxt_Kick_SM3;
      }
      /* SM3:Kick: */
      if (Kick_weakb_clock_SM3) {
        outC->_kicks = _kicks;
        outC->SM3_state_nxt = SSM_st_Kick_SM3;
        outC->SpeedValue = Speed;
      }
      else {
        if (_L9) {
          outC->SM3_state_nxt = SSM_st_Kicking_SM3;
        }
        else {
          outC->SM3_state_nxt = SSM_st_Kick_SM3;
        }
        /* SM3:Kick:<1> */
        if (_L9) {
          outC->_kicks = outC->_kicks + kcg_lit_int16(1);
          outC->SpeedValue = kcg_lit_int16(-20);
        }
        else {
          outC->_kicks = _kicks;
          outC->SpeedValue = Speed;
        }
      }
      /* SM3:Kick:Kicking: */
      switch (Kicking_state_sel_Kick_SM3) {
        case SSM_st_Finish_Kicking_Kick_SM3 :
          Kicking_state_act_Kick_SM3 = SSM_st_Finish_Kicking_Kick_SM3;
          outC->ArmSpeedValue = outC->ArmSpeed;
          break;
        case SSM_st_Backward_Kicking_Kick_SM3 :
          if (_L9) {
            Kicking_state_act_Kick_SM3 = SSM_st_Finish_Kicking_Kick_SM3;
          }
          else {
            Kicking_state_act_Kick_SM3 = SSM_st_Backward_Kicking_Kick_SM3;
          }
          /* SM3:Kick:Kicking:Backward:<1> */
          if (_L9) {
            outC->ArmSpeedValue = kcg_lit_int16(0);
          }
          else {
            outC->ArmSpeedValue = outC->ArmSpeed;
          }
          break;
        case SSM_st_Forward_Kicking_Kick_SM3 :
          if (inC->KickMoveBackward) {
            Kicking_state_act_Kick_SM3 = SSM_st_Backward_Kicking_Kick_SM3;
          }
          else {
            Kicking_state_act_Kick_SM3 = SSM_st_Forward_Kicking_Kick_SM3;
          }
          /* SM3:Kick:Kicking:Forward:<1> */
          if (inC->KickMoveBackward) {
            outC->ArmSpeedValue = kcg_lit_int16(-50);
          }
          else {
            outC->ArmSpeedValue = outC->ArmSpeed;
          }
          break;
        case SSM_st_DriveBack_Kicking_Kick_SM3 :
          if (_L14) {
            Kicking_state_act_Kick_SM3 = SSM_st_Forward_Kicking_Kick_SM3;
          }
          else if (outC->_kicks >= inC->KickCountValue) {
            Kicking_state_act_Kick_SM3 = SSM_st_Finish_Kicking_Kick_SM3;
          }
          else {
            Kicking_state_act_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
          }
          /* SM3:Kick:Kicking:DriveBack:<1> */
          if (_L14) {
            outC->ArmSpeedValue = kcg_lit_int16(50);
          }
          else {
            outC->ArmSpeedValue = outC->ArmSpeed;
          }
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* SM3:Kick:Kicking: */
      switch (Kicking_state_act_Kick_SM3) {
        case SSM_st_Finish_Kicking_Kick_SM3 :
          outC->Kicking_state_nxt_Kick_SM3 = SSM_st_Finish_Kicking_Kick_SM3;
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
      outC->CountValue = outC->Counting;
      outC->init = kcg_false;
      break;
    case SSM_st_Stop_SM3 :
      outC->_kicks = _kicks;
      outC->CountValue = outC->Counting;
      outC->ArmSpeedValue = outC->ArmSpeed;
      outC->SM3_state_nxt = SSM_st_Stop_SM3;
      outC->SpeedValue = Speed;
      break;
    case SSM_st_DriveAndCount_SM3 :
      if (SM3_reset_act) {
        outC->init1 = kcg_true;
      }
      outC->_kicks = _kicks;
      DriveAndCount_weakb_clock_SM3 = SM3_fired_strong != SSM_TR_no_trans_SM3;
      /* SM3:DriveAndCount:CountSM: */
      if (outC->init1) {
        CountSM_state_sel_DriveAndCount_SM3 = SSM_st_Init_CountSM_DriveAndCount_SM3;
      }
      else {
        CountSM_state_sel_DriveAndCount_SM3 = outC->CountSM_state_nxt_DriveAndCount_SM3;
      }
      /* SM3:DriveAndCount:CountSM: */
      switch (CountSM_state_sel_DriveAndCount_SM3) {
        case SSM_st_Init_CountSM_DriveAndCount_SM3 :
          /* SM3:DriveAndCount:CountSM:Init:<1> */
          if (inC->Start) {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
            outC->CountValue = kcg_lit_uint32(0);
          }
          else {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Init_CountSM_DriveAndCount_SM3;
            outC->CountValue = outC->Counting;
          }
          break;
        case SSM_st_Count_CountSM_DriveAndCount_SM3 :
          /* SM3:DriveAndCount:CountSM:Count:<1> */
          if (_L9) {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
            outC->CountValue = outC->Counting + kcg_lit_uint32(1);
          }
          else {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Count_CountSM_DriveAndCount_SM3;
            outC->CountValue = outC->Counting;
          }
          break;
        case SSM_st_Wait_CountSM_DriveAndCount_SM3 :
          if (_L14) {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Count_CountSM_DriveAndCount_SM3;
          }
          else {
            CountSM_state_act_DriveAndCount_SM3 = SSM_st_Wait_CountSM_DriveAndCount_SM3;
          }
          outC->CountValue = outC->Counting;
          break;
        default :
          /* this default branch is unreachable */
          break;
      }
      /* SM3:DriveAndCount:CountSM: */
      switch (CountSM_state_act_DriveAndCount_SM3) {
        case SSM_st_Init_CountSM_DriveAndCount_SM3 :
          outC->CountSM_state_nxt_DriveAndCount_SM3 =
            SSM_st_Init_CountSM_DriveAndCount_SM3;
          break;
        case SSM_st_Count_CountSM_DriveAndCount_SM3 :
          outC->CountSM_state_nxt_DriveAndCount_SM3 =
            SSM_st_Count_CountSM_DriveAndCount_SM3;
          break;
        case SSM_st_Wait_CountSM_DriveAndCount_SM3 :
          outC->CountSM_state_nxt_DriveAndCount_SM3 =
            SSM_st_Wait_CountSM_DriveAndCount_SM3;
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
        if (inC->Stop) {
          outC->SM3_state_nxt = SSM_st_Free_SM3;
        }
        else {
          outC->SM3_state_nxt = SSM_st_DriveAndCount_SM3;
        }
        /* SM3:DriveAndCount:<1> */
        if (inC->Stop) {
          outC->SpeedValue = kcg_lit_int16(-20);
        }
        else {
          outC->SpeedValue = Speed;
        }
      }
      outC->init1 = kcg_false;
      break;
    default :
      /* this default branch is unreachable */
      break;
  }
  outC->ArmSpeed = outC->ArmSpeedValue;
  outC->Speed = outC->SpeedValue;
  outC->Counting = outC->CountValue;
}

#ifndef KCG_USER_DEFINED_INIT
void StateMachine_init(outC_StateMachine *outC)
{
  outC->init = kcg_true;
  outC->init1 = kcg_true;
  outC->CountSM_state_nxt_DriveAndCount_SM3 =
    SSM_st_Wait_CountSM_DriveAndCount_SM3;
  outC->Kicking_state_nxt_Kick_SM3 = SSM_st_DriveBack_Kicking_Kick_SM3;
  outC->ArmSpeedValue = kcg_lit_int16(0);
  outC->SpeedValue = kcg_lit_int16(0);
  outC->CountValue = kcg_lit_uint32(0);
  outC->Speed = kcg_lit_int16(0);
  outC->ArmSpeed = kcg_lit_int16(0);
  outC->Counting = kcg_lit_uint32(0);
  outC->_kicks = kcg_lit_int16(0);
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
  outC->Counting = kcg_lit_uint32(0);
  outC->_kicks = kcg_lit_int16(0);
  outC->SM3_state_nxt = SSM_st_Stop_SM3;
}
#endif /* KCG_NO_EXTERN_CALL_TO_RESET */

/*
  Expanded instances for: StateMachine/
  @2: (math::InRangeInOut#1)
  @1: (math::InRangeOutIn#1)
*/

/* $********** SCADE Suite KCG 32-bit 6.6 (build i15) ***********
** StateMachine.c
** Generation date: 2017-09-26T15:13:06
*************************************************************$ */

