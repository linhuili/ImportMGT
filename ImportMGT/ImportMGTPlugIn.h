/////////////////////////////////////////////////////////////////////////////
// ImportMGTPlugIn.h : main header file for the ImportMGT plug-in
//

#pragma once
#include "mgtstruct.h"
/////////////////////////////////////////////////////////////////////////////
// CImportMGTPlugIn
// See ImportMGTPlugIn.cpp for the implementation of this class
//

class CImportMGTPlugIn : public CRhinoFileImportPlugIn
{
public:
  CImportMGTPlugIn();
  ~CImportMGTPlugIn();

  // Required overrides
  const wchar_t* PlugInName() const;
  const wchar_t* PlugInVersion() const;
  GUID PlugInID() const;
  BOOL OnLoadPlugIn();
  void OnUnloadPlugIn();

  // Online help overrides
  BOOL AddToPlugInHelpMenu() const;
  BOOL OnDisplayPlugInHelp( HWND hWnd ) const;

  // File import overrides
  void AddFileType( ON_ClassArray<CRhinoFileType>& extensions, const CRhinoFileReadOptions& options );
  BOOL ReadFile( const wchar_t* filename, int index, CRhinoDoc& dox, const CRhinoFileReadOptions& options );
  BOOL ReadMgtFile( const wchar_t* file_name, CRhinoDoc& doc);
  int AddLayer( const wchar_t* layername,CRhinoDoc& doc,int parent=-1);
  bool AddNode( const NODE& Node,CRhinoDoc& doc,int layer_index,double scale=1.0);
  bool AddElement(const ELEMENT& Element,CRhinoDoc& doc,int layer_ELEMENT[4],int with_section,int layer_SECTION,double scale=1.0);
  void Check(double scale=1.0);

private:
	ON_wString m_plugin_version;
	CString m_Version;
	UNIT m_Unit;
	CArray<NODE,NODE>* m_Nodes;
	CArray<int,int>* m_iNOIndex;
	CArray<ELEMENT,ELEMENT>* m_Elements;
	CArray<BEAM_TRUSS,BEAM_TRUSS>* m_Beams;
	CArray<BEAM_TRUSS,BEAM_TRUSS>* m_Trusses;
	CArray<PLATE,PLATE>* m_Plates;
	CArray<SECTION,SECTION>* m_Section;
	CArray<int,int>* m_iSECIndex;
	CArray<DBUSER,DBUSER>* m_DBUSER;
	CArray<DATA1_1,DATA1_1>* m_DATA1_1;
	CArray<DATA1_2,DATA1_2>* m_DATA1_2;
	CArray<SRC,SRC>* m_SRC;
	CArray<TAPERED,TAPERED>* m_TAPERED;
	CArray<DIM,DIM>* m_DIM;
  // TODO: Add additional class information here
};

CImportMGTPlugIn& ImportMGTPlugIn();



