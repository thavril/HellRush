#ifndef		__MACHINE_H__
#define		__MACHINE_H__

#define		STATE_MAX 8
#define		EDGE_MAX 8

enum		eState
{
	S0,
	S1,
	S2,
	S3,
	S4,
	S5,
	S6,
	S7,
	STATE_ERROR
};

enum		eAction
{
	MA,
	HR,
	ACTION_ERROR
};

extern const eState		gStateTable[STATE_MAX][EDGE_MAX];
extern const eAction	gActionTable[STATE_MAX][EDGE_MAX];

#endif		// __MACHINE_H__