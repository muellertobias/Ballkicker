# Target specific macros
TARGET = RoboDog
TARGET_SOURCES := \
	RoboDog.c \
	KCG/StateMachine.c 
TOPPERS_OSEK_OIL_SOURCE := ./RoboDog.oil

O_PATH ?= build

include ../../ecrobot/ecrobot.mak
