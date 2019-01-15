/*(Ver.=0.9~)(Beg.=0.9)
* OSLW_tool.h
*
*  Created on: 2017-7-25
*      Author: slw
*/

#ifndef OSLW_TOOL_BASIC_MATH_H_
#define OSLW_TOOL_BASIC_MATH_H_


#include "OSLW_define.h"
#include "OSLW_tool_define.h"
#include "OSLW_parameter.h"

#if !(OSLW_SIMPLE_LEVEL >= 4)

#if OSLW_TOOL_IMPORT_MATH || OSLW_TOOL_IMPORT_ALL

typedef lw_u32 LwMatRowType;
typedef lw_u16 LwMatColType;
typedef lw_u16 LwMatLenType;

typedef struct OSLW_TOOL_MATRIX_STRUCT {
	ParaType *a;
	LwMatLenType length;
	LwMatRowType row;
	LwMatColType col;

}OSlwToolMatrixSTU;

typedef OSlwToolMatrixSTU OSlwMat;

typedef enum
{
	OSlwMartixRes_Find = 0,
	OSlwMartixRes_NoFind,
	OSlwMartixRes_Over,
	OSlwMartixRes_Error

}OSlwMartixResNum;

void OSlwToolMatrixInitial(OSlwToolMatrixSTU *m, LwMatRowType row, LwMatColType col, ParaType *a);

//OSlwToolMatrixSTU* OSlwToolMatrixAdd(OSlwToolMatrixSTU *s,OSlwToolMatrixSTU *m1,OSlwToolMatrixSTU *m2);
//typedef OSlwToolMatrixSTU* (*pOSlwToolMatrixAddFunType)(OSlwToolMatrixSTU *s,OSlwToolMatrixSTU *m1,OSlwToolMatrixSTU *m2);

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixAdd,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m1, OSlwToolMatrixSTU *m2));

//OSlwToolMatrixSTU* OSlwToolMatrixSub(OSlwToolMatrixSTU *s,OSlwToolMatrixSTU *m1,OSlwToolMatrixSTU *m2);
//typedef OSlwToolMatrixSTU* (*pOSlwToolMatrixSubFunType)(OSlwToolMatrixSTU *s,OSlwToolMatrixSTU *m1,OSlwToolMatrixSTU *m2);
OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixSub,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m1, OSlwToolMatrixSTU *m2));


OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixDot,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m1, OSlwToolMatrixSTU *m2));

//OSlwToolMatrixSTU* OSlwToolMatrixMpy(OSlwToolMatrixSTU *s,OSlwToolMatrixSTU *m1,OSlwToolMatrixSTU *m2);
//typedef OSlwToolMatrixSTU* (*pOSlwToolMatrixMpyFunType)(OSlwToolMatrixSTU *s,OSlwToolMatrixSTU *m1,OSlwToolMatrixSTU *m2);
OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixMpy,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m1, OSlwToolMatrixSTU *m2));

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixTurn,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *buf));

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixReSize,
(OSlwToolMatrixSTU *s, lw_u16 row, lw_u16 col));


OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixMaxMin,
(OSlwToolMatrixSTU *s, ParaType *pMax, lw_u16 *pMaxIndex, ParaType *pMin, lw_u16 *pMinIndex));

OSLW_TOOL_FUN_STATEMENT(OSlwMartixResNum, OSlwToolMatrixIndex,
(OSlwToolMatrixSTU *s, ParaType data, lw_u16 *pindex, lw_u16 *pmaxlen));

OSLW_TOOL_FUN_STATEMENT(OSlwMartixResNum, OSlwToolMatrixFind,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m, lw_u16 SpacingLen, lw_u16 First, lw_u16 *pres));


OSLW_TOOL_FUN_STATEMENT(OSlwMartixResNum, OSlwToolMatrixCmp,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m, lw_u8 *pbuf));


OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixSet,
(OSlwToolMatrixSTU *s, ParaType data, OSlwToolMatrixSTU *a));

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixJoin,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m1, OSlwToolMatrixSTU *m2));

OSLW_TOOL_FUN_STATEMENT(ParaType, OSlwToolMatrixLossSquare,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *ref, OSlwToolMatrixSTU *pre));

OSLW_TOOL_FUN_STATEMENT(ParaType, OSlwToolMatrixLossCrossEntropyForSoftMax,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *ref, OSlwToolMatrixSTU *pre));

OSLW_TOOL_FUN_STATEMENT(ParaType, OSlwToolMatrixSum,
(OSlwToolMatrixSTU *s));

OSLW_TOOL_FUN_STATEMENT(ParaType, OSlwToolMatrixVar,
(OSlwToolMatrixSTU *s, ParaType *pMean, OSlwToolMatrixSTU *_normal_res, ParaType epsi));


OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixMPYA,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *x, OSlwToolMatrixSTU *we, OSlwToolMatrixSTU *bi));

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixWeXBi,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *we, OSlwToolMatrixSTU *x, OSlwToolMatrixSTU *bi));

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*, OSlwToolMatrixXWeBi,
(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *we, OSlwToolMatrixSTU *x, OSlwToolMatrixSTU *bi));

OSLW_TOOL_FUN_STATEMENT(OSlwToolMatrixSTU*,OSlwToolMatrixTurnMpy,
	(OSlwToolMatrixSTU *s, OSlwToolMatrixSTU *m1, OSlwToolMatrixSTU *m2, lw_u8 flag));


OSLW_TOOL_FUN_STATEMENT(void*, OSlwToolMatrixConv2,
(
	OSlwToolMatrixSTU *s, //Ŀ���
	OSlwToolMatrixSTU *m_kernal, //������
	OSlwToolMatrixSTU *m2,//������ 
	lw_u16 move_x,lw_u16 move_y,//���������ƶ�����
	lw_u8 EqualModel, //��ֵģʽ 1:ֱ�Ӹ��� 0:���
	lw_u8 MoveModel, //�ƶ�ģʽ 's'/'f'
	lw_u8 KernalModel, //��ģʽ 0/180 180+��f��=��ѧ��ά����
	ParaType *fast_buf//���پ����ڴ���
	));

//ֻ����һ��batch
OSLW_TOOL_FUN_STATEMENT(void*, OSlwToolMatrixConvFastMultCh,
(
	OSlwToolMatrixSTU *m_out, //��� row-col ����һ��ͨ�� length����������С
	OSlwToolMatrixSTU *m_kernal, //������ row-col ����һ��ͨ��
	OSlwToolMatrixSTU *m_in,//������ row-col ����һ��ͨ��
	OSlwToolMatrixSTU *bias,//ƫ�� row-col-length ����ν
	lw_u16 in_high,//����߶� 
	lw_u16 out_high,//����߶�
	lw_u16 move_x, lw_u16 move_y,//���������ƶ�����
	lw_u8 FD_1_or_BK_0,//ǰ�򴫵ݻ��߷��򴫵�
	ParaType *fast_buf//�� ����
	));

OSLW_TOOL_FUN_STATEMENT(
	OSlwToolMatrixSTU*,
	OSlwToolMatrix_RATIO_ADD,
	(OSlwToolMatrixSTU *s, ParaType a, OSlwToolMatrixSTU *m1, ParaType b, OSlwToolMatrixSTU *m2)
);


#define OSLW_TOOL_M_SIZE_EQU(A,B) ((A)->length == (B)->length)

#define OSLW_TOOL_M_GET(M,R,C) (*((M).a+(R)*(M).col+(C)))

#define OSLW_TOOL_M_GET_R(M,R) ((M).a+(R)*(M).col)

#define OSlwMatGet(M,R,C) ((M).a+(R)*(M).col+(C))

#define OSlwMatAt(M,R,C) (*((M).a+(R)*(M).col+(C)))

#define OSlwMatGetR(M,R) ((M).a+(R)*(M).col)

#define OSLW_TOOL_M_DY_INIT(M,R,C,PMEM) do{OSlwToolMatrixInitial(&(M),(R),(C),(PMEM)->Malloc((PMEM) , PARA_MEM_CAL((R)*(C))));}while(0)

#define OSlwMatInit OSlwToolMatrixInitial

#define OSlwMatNew OSLW_TOOL_M_DY_INIT


#if PARA_LEN==8
#define LW_MAT_CLR(A) do{\
	register lw_u32 *_pCLR_D=(void *)((A)->a);\
	register lw_u32 _CLR_len=((A)->length<<1);\
	while (_CLR_len--) *_pCLR_D++=0;\
}while(0)
#elif PARA_LEN==4
#define LW_MAT_CLR(A) do{\
	register lw_u32 *_pCLR_D=(void *)((A)->a);\
	register lw_u32 _CLR_len=(A)->length;\
	while (_CLR_len--) *_pCLR_D++=0;\
}while(0)

#endif


#endif //OSLW_TOOL_IMPORT_MATH || OSLW_TOOL_IMPORT_ALL

#endif // !(OSLW_SIMPLE_LEVEL >= 4)
#endif