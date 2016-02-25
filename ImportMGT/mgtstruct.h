#pragma once
#include "stdafx.h"

//定义Unit System结构体
struct UNIT
{
	CString FORCE;
	CString LENGTH;
	CString HEAT;
	CString TEMPER;
};
//定义Nodes结构体
struct NODE
{
	int iNO;
	double X;
	double Y;
	double Z;
};
//定义ELEMENT结构体
struct BEAM_TRUSS
{
	int iN1;
	int iN2;
	double ANGLE;
	int CHECK;
};
struct PLATE
{
	int iN1;
	int iN2;
	int iN3;
	int iN4;
};
struct ELEMENT
{
	int iEL;
	CString TYPE;
	int iMAT;
	int iPRO;
	INT_PTR index;
};
//定义SECTION结构体
struct DATA1_1
{
	CString DB;
	CString NAME;
};
struct DATA1_2
{
	double D1;
	double D2;
	double D3;
	double D4;
	double D5;
	double D6;
	double D7;
	double D8;
	double D9;
	double D10;
};
struct DBUSER
{
	int DATA1SIGN;
	INT_PTR index;
};
struct SRC
{
	CString ELAST;
};
struct DIM
{
	double D11;
	double D12;
	double D13;
	double D14;
	double D15;
	double D16;
	double D17;
	double D18;
	double D21;
	double D22;
	double D23;
	double D24;
	double D25;
	double D26;
	double D27;
	double D28;
};
struct TAPERED
{
	CString STYPE;
	INT_PTR index;
};
struct SECTION
{
	int iSEC;
	CString TYPE;
	CString SNAME;
	CString SHAPE;
	INT_PTR index;
};
//定义角度检验用结构
struct CHECK
{
	INT_PTR index;
	int End;
};