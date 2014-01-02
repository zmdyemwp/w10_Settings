#ifndef		__W10_PARAMETERS_H__
#define		__W10_PARAMETERS_H__

struct W10PARAM {
	DWORD title;
	DWORD options[8];
	DWORD count;
	DWORD index;
};

extern W10PARAM	mode;
extern W10PARAM	lang;
extern W10PARAM	bktimeout;
extern W10PARAM	bklevel;
extern W10PARAM	recorddata;
extern W10PARAM	timezone1;
extern W10PARAM	position;
extern W10PARAM	autolap;
extern W10PARAM	autopause;
extern W10PARAM	autoscroll;
extern W10PARAM	antfootstep;

extern W10PARAM	antbikeweight;
extern W10PARAM	antbikeodometer;
extern W10PARAM	antbikewheel;

extern W10PARAM	gsensorstep;
extern W10PARAM	timezone2;

extern W10PARAM	btspptone;
extern W10PARAM	btsppvibration;
extern W10PARAM	metronomeInterval;
extern W10PARAM	metronomeRing;

extern W10PARAM	alarm4;

void InitParamW10(void);

#endif		//__W10_PARAMETERS_H__


