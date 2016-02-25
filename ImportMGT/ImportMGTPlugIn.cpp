/////////////////////////////////////////////////////////////////////////////
// ImportMGTPlugIn.cpp : defines the initialization routines for the plug-in.
//

#include "StdAfx.h"
#include "ImportMGTPlugIn.h"

// The plug-in object must be constructed before any plug-in classes
// derived from CRhinoCommand. The #pragma init_seg(lib) ensures that
// this happens.

#pragma warning( push )
#pragma warning( disable : 4073 )
#pragma init_seg( lib )
#pragma warning( pop )

// Rhino plug-in declaration
RHINO_PLUG_IN_DECLARE

	// Rhino plug-in name
	// Provide a short, friendly name for this plug-in.
	RHINO_PLUG_IN_NAME( L"MGT Import Plug-in" );

// Rhino plug-in id
// Provide a unique uuid for this plug-in
RHINO_PLUG_IN_ID( L"974C6F9C-C82D-4BB7-8A8C-55BA33CB06F7" );

// Rhino plug-in version
// Provide a version number string for this plug-in
RHINO_PLUG_IN_VERSION( __DATE__"  "__TIME__ )

	// Rhino plug-in developer declarations
	// TODO: fill in the following developer declarations with
	// your company information. Note, all of these declarations
	// must be present or your plug-in will not load.
	//
	// When completed, delete the following #error directive.
	//#error Developer declarations block is incomplete!
	RHINO_PLUG_IN_DEVELOPER_ORGANIZATION( L"林慧立" );
RHINO_PLUG_IN_DEVELOPER_ADDRESS( L"北京市西城区 " );
RHINO_PLUG_IN_DEVELOPER_COUNTRY( L"China" );
RHINO_PLUG_IN_DEVELOPER_PHONE( L"18668608236" );
RHINO_PLUG_IN_DEVELOPER_FAX( L" " );
RHINO_PLUG_IN_DEVELOPER_EMAIL( L" " );
RHINO_PLUG_IN_DEVELOPER_WEBSITE( L" " );
RHINO_PLUG_IN_UPDATE_URL( L" " );

// The one and only CImportMGTPlugIn object
static CImportMGTPlugIn thePlugIn;

/////////////////////////////////////////////////////////////////////////////
// CImportMGTPlugIn definition

CImportMGTPlugIn& ImportMGTPlugIn()
{ 
	// Return a reference to the one and only CImportMGTPlugIn object
	return thePlugIn; 
}

CImportMGTPlugIn::CImportMGTPlugIn()
{
	// Description:
	//   CImportMGTPlugIn constructor. The constructor is called when the
	//   plug-in is loaded and "thePlugIn" is constructed. Once the plug-in
	//   is loaded, CImportMGTPlugIn::OnLoadPlugIn() is called. The 
	//   constructor should be simple and solid. Do anything that might fail in
	//   CImportMGTPlugIn::OnLoadPlugIn().

	// TODO: Add construction code here
	m_plugin_version = RhinoPlugInVersion();
}

CImportMGTPlugIn::~CImportMGTPlugIn()
{
	// Description:
	//   CImportMGTPlugIn destructor. The destructor is called to destroy
	//   "thePlugIn" when the plug-in is unloaded. Immediately before the
	//   DLL is unloaded, CImportMGTPlugIn::OnUnloadPlugin() is called. Do
	//   not do too much here. Be sure to clean up any memory you have allocated
	//   with onmalloc(), onrealloc(), oncalloc(), or onstrdup().

	// TODO: Add destruction code here
}

/////////////////////////////////////////////////////////////////////////////
// Required overrides

const wchar_t* CImportMGTPlugIn::PlugInName() const
{
	// Description:
	//   Plug-in name display string.  This name is displayed by Rhino when
	//   loading the plug-in, in the plug-in help menu, and in the Rhino 
	//   interface for managing plug-ins.

	// TODO: Return a short, friendly name for the plug-in.
	return RhinoPlugInName();
}

const wchar_t* CImportMGTPlugIn::PlugInVersion() const
{
	// Description:
	//   Plug-in version display string. This name is displayed by Rhino 
	//   when loading the plug-in and in the Rhino interface for managing
	//   plug-ins.

	// TODO: Return the version number of the plug-in.
	return m_plugin_version;
}

GUID CImportMGTPlugIn::PlugInID() const
{
	// Description:
	//   Plug-in unique identifier. The identifier is used by Rhino to
	//   manage the plug-ins.

	// TODO: Return a unique identifier for the plug-in.
	// {974C6F9C-C82D-4BB7-8A8C-55BA33CB06F7}
	return ON_UuidFromString( RhinoPlugInId() );
}

BOOL CImportMGTPlugIn::OnLoadPlugIn()
{
	// Description:
	//   Called after the plug-in is loaded and the constructor has been
	//   run. This is a good place to perform any significant initialization,
	//   license checking, and so on.  This function must return TRUE for
	//   the plug-in to continue to load.

	// TODO: Add plug-in initialization code here.
	return CRhinoFileImportPlugIn::OnLoadPlugIn();
}

void CImportMGTPlugIn::OnUnloadPlugIn()
{
	// Description:
	//   Called when the plug-in is about to be unloaded.  After
	//   this function is called, the destructor will be called.

	// TODO: Add plug-in cleanup code here.

	CRhinoFileImportPlugIn::OnUnloadPlugIn();
}

/////////////////////////////////////////////////////////////////////////////
// Online help overrides

BOOL CImportMGTPlugIn::AddToPlugInHelpMenu() const
{
	// Description:
	//   Return true to have your plug-in name added to the Rhino help menu.
	//   OnDisplayPlugInHelp will be called when to activate your plug-in help.

	return TRUE;
}

BOOL CImportMGTPlugIn::OnDisplayPlugInHelp( HWND hWnd ) const
{
	// Description:
	//   Called when the user requests help about your plug-in.
	//   It should display a standard Windows Help file (.hlp or .chm).

	// TODO: Add support for online help here.
	return CRhinoFileImportPlugIn::OnDisplayPlugInHelp( hWnd );
}

/////////////////////////////////////////////////////////////////////////////
// File import overrides

void CImportMGTPlugIn::AddFileType( ON_ClassArray<CRhinoFileType>& extensions, const CRhinoFileReadOptions& options )
{
	// Description:
	//   When Rhino gets ready to display either the open or import file dialog,
	//   it calls AddFileType() once for each loaded file import plug-in.
	// Parameters:
	//   extensions [in] Append your supported file type extensions to this list.
	//   options [in] File write options.
	// Example:
	//   If your plug-in imports "Geometry Files" that have a ".geo" extension,
	//   then your AddToFileType(....) would look like the following:
	//
	//   CImportPlugIn::AddToFileType(ON_ClassArray<CRhinoFileType>& extensions, const CRhinoFileReadOptions& options)
	//   {
	//      CRhinoFileType ft(PlugInID(), L"Geometry Files (*.geo)", L"geo");
	//      extensions.Append(ft);
	//   }

	// TODO: Add supported file extensions here.
	CRhinoFileType ft(PlugInID(),L"midas Gen Text File (*.mgt)",L"mgt");
	extensions.Append(ft);
}

BOOL CImportMGTPlugIn::ReadFile( const wchar_t* filename, int index, CRhinoDoc& doc, const CRhinoFileReadOptions& options )
{
	// Description:
	//   Rhino calls ReadFile() to create document geometry from an external file.
	// Parameters:
	//   filename [in] The name of file to read.
	//   index [in] The index of file extension added to list in AddToFileType().
	//   doc [in] If importing, then the current Rhino document. Otherwise, an empty Rhino document.
	//   options [in] File read options.
	// Remarks:
	//   The plug-in is responsible for opening the file and writing to it.
	// Return TRUE if successful, otherwise return FALSE.

	// TODO: Add file import code here.
	int with_section=RhinoMessageBox(RhinoApp().MainWnd(),L"截面？", L"截面", MB_YESNO);
	int with_check=RhinoMessageBox(RhinoApp().MainWnd(),L"长度角度检验？", L"检验", MB_YESNO);
	int i;
	ON_3dPoint on_3dpt1,on_3dpt2,on_3dpt3,on_3dpt4;
	ON_Line on_ln;
	int layer_NODE;
	int layer_ELEMENT[4];
	int layer_SECTION;
	double scale=1.0;
	if( index == 0 )
		ReadMgtFile( filename, doc );
	layer_NODE = AddLayer(L"NODE",doc);
	layer_ELEMENT[0] = AddLayer(L"ELEMENT",doc);
	layer_ELEMENT[1] = AddLayer(L"BEAM",doc,layer_ELEMENT[0]);
	layer_ELEMENT[2] = AddLayer(L"TRUSS",doc,layer_ELEMENT[0]);
	layer_ELEMENT[3] = AddLayer(L"PLATE",doc,layer_ELEMENT[0]);
	if (IDYES==with_section)
		layer_SECTION = AddLayer(L"SECTION",doc);
	if(options.Mode (CRhinoFileReadOptions::OpenMode))
	{
		CRhinoDocProperties& docprop = doc.Properties ();
		ON_3dmUnitsAndTolerances muat=docprop.ModelUnitsAndTolerances();
		if(L"M"==m_Unit.LENGTH)
			muat.m_unit_system .m_unit_system = ON::unit_system ::meters ;
		if(L"MM"==m_Unit.LENGTH )
			muat.m_unit_system .m_unit_system = ON::unit_system ::millimeters ;
		docprop.SetUnitsAndTolerances(muat);
		if (IDYES==with_check)
			Check();
		//向犀牛文件中添加Nodes
		for(i=0;i<m_Nodes->GetSize ();i++)
		{
			AddNode(m_Nodes->GetAt(i),doc,layer_NODE);
		}
		//向犀牛文件中添加Elements
		for(i=0;i<m_Elements->GetSize ();i++)
		{
			AddElement(m_Elements->GetAt (i),doc,layer_ELEMENT,with_section,layer_SECTION);
		}
	}
	if(options.Mode (CRhinoFileReadOptions::ImportMode))
	{
		CRhinoDocProperties& docprop = doc.Properties ();
		ON_3dmUnitsAndTolerances muat=docprop.ModelUnitsAndTolerances();
		switch(muat.m_unit_system .m_unit_system)
		{
		case ON::unit_system ::millimeters :
			if(L"M"==m_Unit.LENGTH)
				scale=1000.0;
			if(L"MM"==m_Unit.LENGTH )
				scale = 1.0;
			break;
		case ON::unit_system ::centimeters :
			if(L"M"==m_Unit.LENGTH)
				scale=100.0;
			if(L"MM"==m_Unit.LENGTH )
				scale = 0.1;
			break;
		case ON::unit_system ::decimeters  :
			if(L"M"==m_Unit.LENGTH)
				scale=10.0;
			if(L"MM"==m_Unit.LENGTH )
				scale = 0.01;
			break;
		case ON::unit_system ::meters :
			if(L"M"==m_Unit.LENGTH)
				scale=1.0;
			if(L"MM"==m_Unit.LENGTH )
				scale = 0.001;
			break;
		}
		if (1.0 != scale)
		{
			CString csRhino,csMGT,csScale,csAll;
			switch(muat.m_unit_system .m_unit_system)
			{
			case ON::unit_system ::millimeters :
				csRhino=L"millimeters";
				break;
			case ON::unit_system ::centimeters :
				csRhino=L"centimeters";
				break;
			case ON::unit_system ::decimeters  :
				csRhino=L"decimeters";
				break;
			case ON::unit_system ::meters :
				csRhino=L"meters";
				break;
			}
			if(L"M"==m_Unit.LENGTH)
				csMGT=L"meters";
			if(L"MM"==m_Unit.LENGTH )
				csMGT=L"millimeters";
			csScale.Format (L"%f",scale);
			csScale.TrimRight (L"0");
			csScale.TrimRight (L".");
			csAll.Format (L"Rhino units = %s\nMGT units = %s\nScale MGT geometry by %s?",csRhino,csMGT,csScale);
			int ync=RhinoMessageBox(RhinoApp().MainWnd(),csAll, L"MGT Import Scaling", MB_YESNOCANCEL);
			if (IDNO==ync)
				scale=1.0;
			if (IDCANCEL==ync)
				return FALSE;
		}
		if (IDYES==with_check)
			Check(scale);
		//向犀牛文件中添加Nodes
		for(i=0;i<m_Nodes->GetSize ();i++)
		{
			AddNode(m_Nodes->GetAt(i),doc,layer_NODE,scale);
		}
		//向犀牛文件中添加Elements
		for(i=0;i<m_Elements->GetSize ();i++)
		{
			AddElement(m_Elements->GetAt (i),doc,layer_ELEMENT,with_section,layer_SECTION,scale);
		}
	}
	delete m_Nodes;
	m_Nodes=0;
	delete m_iNOIndex;
	m_iNOIndex=0;
	delete m_Elements;
	m_Elements=0;
	delete m_Section;
	m_Section=0;
	delete m_iSECIndex;
	m_iSECIndex=0;
	delete m_Beams;
	m_Beams=0;
	delete m_Trusses;
	m_Trusses=0;
	delete m_Plates;
	m_Plates=0;
	delete m_DBUSER;
	m_DBUSER=0;
	delete m_DATA1_1;
	m_DATA1_1=0;
	delete m_DATA1_2;
	m_DATA1_2=0;
	delete m_SRC;
	m_SRC=0;
	delete m_TAPERED;
	m_TAPERED=0;
	delete m_DIM;
	m_DIM=0;
	doc.Redraw ();
	return TRUE;
	RhinoApp().Print( L"%s has encountered an unsupported file type index: %d\n", PlugInName(), index );
	return FALSE;
}

BOOL CImportMGTPlugIn::ReadMgtFile( const wchar_t* filename, CRhinoDoc& doc )
{

	int i;
	CStringArray arrLine;
	CString csLine;
	const wchar_t sep=L',';
	CString token;
	int iFind1,iFind2;

	//打开.mgt文件
	CStdioFile f1(filename,CFile::modeRead | CFile::typeText );
	//定位到Version 并读取相应数据
	f1.ReadString (csLine);
	csLine.Trim ();
	while(L"*VERSION"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim ();
	}
	f1.ReadString (csLine);
	csLine.Trim ();
	m_Version=csLine;
	//定位到Unit System并读取相应数据
	while(L"*UNIT    ; Unit System"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	while(L"; FORCE, LENGTH, HEAT, TEMPER"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	f1.ReadString (csLine);
	csLine.Trim ();
	csLine.TrimRight (L',');
	csLine=csLine + L',';
	arrLine.SetSize (0);
	iFind1=0;
	iFind2=csLine.Find (sep,iFind1);
	while(iFind2!= -1)
	{
		token=csLine.Mid (iFind1,iFind2-iFind1);
		token.Trim ();
		arrLine.Add (token);
		iFind1=iFind2+1;
		iFind2=csLine.Find (sep,iFind1);
	}
	m_Unit.FORCE=arrLine.GetAt (0);
	m_Unit.LENGTH=arrLine.GetAt (1);
	m_Unit.HEAT=arrLine.GetAt (2);
	m_Unit.TEMPER=arrLine.GetAt (3);
	//定位到Nodes并读取相应数据
	m_Nodes=new CArray<NODE,NODE>;
	m_Nodes->SetSize (0);
	NODE nodeTemp;
	f1.ReadString (csLine);
	csLine.Trim ();
	while(L"*NODE    ; Nodes"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	while(L"; iNO, X, Y, Z"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	f1.ReadString (csLine);
	csLine.Trim ();
	while(L"*"!=csLine.Left (1))
	{
		if (csLine!=L"")
		{
			csLine.TrimRight (L',');
			csLine=csLine + L',';
			arrLine.SetSize (0);
			iFind1=0;
			iFind2=csLine.Find (sep,iFind1);
			while(iFind2!= -1)
			{
				token=csLine.Mid (iFind1,iFind2-iFind1);
				token.Trim ();
				arrLine.Add (token);
				iFind1=iFind2+1;
				iFind2=csLine.Find (sep,iFind1);
			}
			nodeTemp.iNO = _wtoi(arrLine.GetAt(0));
			nodeTemp.X = _wtof(arrLine.GetAt (1));
			nodeTemp.Y = _wtof(arrLine.GetAt (2));
			nodeTemp.Z = _wtof(arrLine.GetAt (3));
			m_Nodes->Add (nodeTemp);
		}
		f1.ReadString (csLine);
		csLine.Trim ();
	}
	//为iNO建立索引
	m_iNOIndex=new CArray<int,int>;
	m_iNOIndex->SetSize (0);
	for(i=0;i<m_Nodes->GetSize();i++)
		m_iNOIndex->SetAtGrow (m_Nodes->GetAt(i).iNO,i);
	//定位到Elements部分并读取数据
	m_Elements=new CArray<ELEMENT,ELEMENT>;
	m_Beams=new CArray<BEAM_TRUSS,BEAM_TRUSS>;
	m_Trusses=new CArray<BEAM_TRUSS,BEAM_TRUSS>;
	m_Plates=new CArray<PLATE,PLATE>;
	m_Elements->SetSize (0);
	m_Beams->SetSize (0);
	m_Trusses->SetSize (0);
	m_Plates->SetSize (0);
	ELEMENT elementTemp;
	BEAM_TRUSS beam_trussTemp;
	PLATE plateTemp;
	while(L"*ELEMENT    ; Elements"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	while(L"; iEL, TYPE, iMAT, iPRO, iN1, iN2, REF, RPX, RPY, RPZ, iSUB, EXVAL  ; Frame(Ref. Point)"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	f1.ReadString (csLine);
	csLine.Trim ();
	while(L"*"!=csLine.Left (1))
	{
		if (csLine!=L"")
		{
			csLine.TrimRight (L',');
			csLine=csLine + L',';
			arrLine.SetSize (0);
			iFind1=0;
			iFind2=csLine.Find (sep,iFind1);
			while(iFind2!= -1)
			{
				token=csLine.Mid (iFind1,iFind2-iFind1);
				token.Trim ();
				arrLine.Add (token);
				iFind1=iFind2+1;
				iFind2=csLine.Find (sep,iFind1);
			}
			elementTemp.iEL = _wtoi(arrLine.GetAt (0));
			elementTemp.TYPE =arrLine.GetAt (1);
			elementTemp.iMAT = _wtoi(arrLine.GetAt (2));
			elementTemp.iPRO = _wtoi(arrLine.GetAt (3));
			if(L"BEAM"==arrLine.GetAt (1))
			{
				beam_trussTemp.iN1 = _wtoi(arrLine.GetAt (4));
				beam_trussTemp.iN2 = _wtoi(arrLine.GetAt (5));
				beam_trussTemp.ANGLE = _wtof(arrLine.GetAt (6));
				beam_trussTemp.CHECK = 0;
				elementTemp.index = m_Beams->Add (beam_trussTemp);
			}
			if(L"TRUSS"==arrLine.GetAt (1))
			{
				beam_trussTemp.iN1 = _wtoi(arrLine.GetAt (4));
				beam_trussTemp.iN2 = _wtoi(arrLine.GetAt (5));
				beam_trussTemp.ANGLE = _wtof(arrLine.GetAt (6));
				beam_trussTemp.CHECK = 0;
				elementTemp.index = m_Trusses->Add (beam_trussTemp);
			}
			if(L"PLATE"==arrLine.GetAt (1))
			{
				plateTemp.iN1 = _wtoi(arrLine.GetAt (4));
				plateTemp.iN2 = _wtoi(arrLine.GetAt (5));
				plateTemp.iN3 = _wtoi(arrLine.GetAt (6));
				plateTemp.iN4 = _wtoi(arrLine.GetAt (7));
				elementTemp.index = m_Plates->Add (plateTemp);
			}
			m_Elements->Add (elementTemp);
		}
		f1.ReadString (csLine);
		csLine.Trim ();
	}
	//定位到Section部分并读取数据
	m_Section = new CArray<SECTION,SECTION>;
	m_DBUSER = new CArray<DBUSER,DBUSER>;
	m_DATA1_1 = new CArray<DATA1_1,DATA1_1>;
	m_DATA1_2 = new CArray<DATA1_2,DATA1_2>;
	m_SRC = new CArray<SRC,SRC>;
	m_TAPERED = new CArray<TAPERED,TAPERED>;
	m_DIM = new CArray<DIM,DIM>;
	m_Section->SetSize (0);
	m_DBUSER->SetSize (0);
	m_DATA1_1->SetSize (0);
	m_DATA1_2->SetSize (0);
	m_SRC->SetSize (0);
	m_TAPERED->SetSize (0);
	m_DIM->SetSize (0);
	SECTION sectionTemp;
	DBUSER dbuserTemp;
	DATA1_1 data1_1Temp;
	DATA1_2 data1_2Temp;
	SRC srcTemp;
	TAPERED taperedTemp;
	DIM dimTemp;
	while(L"*SECTION    ; Section"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	while(L"; [OFFSET2]: OFFSET, iCENT, iREF, iHORZ, HUSERI, HUSERJ, iVERT, VUSERI, VUSERJ"!=csLine)
	{
		f1.ReadString (csLine);
		csLine.Trim();
	}
	f1.ReadString (csLine);
	csLine.Trim ();
	while(L"*"!=csLine.Left (1))
	{
		if (csLine!=L"")
		{
			csLine.TrimRight (L',');
			csLine=csLine + L',';
			arrLine.SetSize (0);
			iFind1=0;
			iFind2=csLine.Find (sep,iFind1);
			while(iFind2!= -1)
			{
				token=csLine.Mid (iFind1,iFind2-iFind1);
				token.Trim ();
				arrLine.Add (token);
				iFind1=iFind2+1;
				iFind2=csLine.Find (sep,iFind1);
			}
			sectionTemp.iSEC = _wtoi(arrLine.GetAt (0));
			sectionTemp.TYPE = arrLine.GetAt (1);
			sectionTemp.SNAME = arrLine.GetAt (2);
			if(L"DBUSER"==arrLine.GetAt (1))
			{
				sectionTemp.SHAPE = arrLine.GetAt (11);
				dbuserTemp.DATA1SIGN = _wtoi(arrLine.GetAt (12));
				if(1==_wtoi(arrLine.GetAt (12)))
				{
					data1_1Temp.DB =arrLine.GetAt (13);
					data1_1Temp.NAME =arrLine.GetAt (14);
					dbuserTemp.index =m_DATA1_1->Add (data1_1Temp);
				}
				if(2==_wtoi(arrLine.GetAt (12)))
				{
					data1_2Temp.D1 = _wtof(arrLine.GetAt (13));
					data1_2Temp.D2 = _wtof(arrLine.GetAt (14));
					data1_2Temp.D3 = _wtof(arrLine.GetAt (15));
					data1_2Temp.D4 = _wtof(arrLine.GetAt (16));
					data1_2Temp.D5 = _wtof(arrLine.GetAt (17));
					data1_2Temp.D6 = _wtof(arrLine.GetAt (18));
					data1_2Temp.D7 = _wtof(arrLine.GetAt (19));
					data1_2Temp.D8 = _wtof(arrLine.GetAt (20));
					data1_2Temp.D9 = _wtof(arrLine.GetAt (21));
					data1_2Temp.D10 = _wtof(arrLine.GetAt (22));
					dbuserTemp.index =m_DATA1_2->Add (data1_2Temp);
				}
				sectionTemp.index =m_DBUSER->Add (dbuserTemp);
			}
			if(L"SRC"==arrLine.GetAt (1))
			{
				sectionTemp.SHAPE = arrLine.GetAt (11);
				srcTemp.ELAST =arrLine.GetAt (12);
				f1.ReadString (csLine);
				csLine.Trim ();
				csLine.TrimRight (L',');
				csLine=csLine + L',';
				arrLine.SetSize (0);
				iFind1=0;
				iFind2=csLine.Find (sep,iFind1);
				while(iFind2!= -1)
				{
					token=csLine.Mid (iFind1,iFind2-iFind1);
					token.Trim ();
					arrLine.Add (token);
					iFind1=iFind2+1;
					iFind2=csLine.Find (sep,iFind1);
				}
				sectionTemp.index =m_SRC->Add (srcTemp);
			}
			if(L"TAPERED"==arrLine.GetAt (1))
			{
				sectionTemp.SHAPE =arrLine.GetAt (13);
				taperedTemp.STYPE =arrLine.GetAt (16);
				if(L"DB"==taperedTemp.STYPE)
				{
					f1.ReadString (csLine);
					taperedTemp.index =0;
				}
				if(L"USER"==taperedTemp.STYPE)
				{
					f1.ReadString (csLine);
					csLine.Trim ();
					csLine.TrimRight (L',');
					csLine=csLine + L',';
					arrLine.SetSize (0);
					iFind1=0;
					iFind2=csLine.Find (sep,iFind1);
					while(iFind2!= -1)
					{
						token=csLine.Mid (iFind1,iFind2-iFind1);
						token.Trim ();
						arrLine.Add (token);
						iFind1=iFind2+1;
						iFind2=csLine.Find (sep,iFind1);
					}
					dimTemp.D11 = _wtof(arrLine.GetAt (0));
					dimTemp.D12 = _wtof(arrLine.GetAt (1));
					dimTemp.D13 = _wtof(arrLine.GetAt (2));
					dimTemp.D14 = _wtof(arrLine.GetAt (3));
					dimTemp.D15 = _wtof(arrLine.GetAt (4));
					dimTemp.D16 = _wtof(arrLine.GetAt (5));
					dimTemp.D17 = _wtof(arrLine.GetAt (6));
					dimTemp.D18 = _wtof(arrLine.GetAt (7));
					dimTemp.D21 = _wtof(arrLine.GetAt (8));
					dimTemp.D22 = _wtof(arrLine.GetAt (9));
					dimTemp.D23 = _wtof(arrLine.GetAt (10));
					dimTemp.D24 = _wtof(arrLine.GetAt (11));
					dimTemp.D25 = _wtof(arrLine.GetAt (12));
					dimTemp.D26 = _wtof(arrLine.GetAt (13));
					dimTemp.D27 = _wtof(arrLine.GetAt (14));
					dimTemp.D28 = _wtof(arrLine.GetAt (15));
					taperedTemp.index =m_DIM->Add (dimTemp);
				}	
				if(L"VALUE"==taperedTemp.STYPE)
				{
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					f1.ReadString (csLine);
					taperedTemp.index =0;
				}
				sectionTemp.index =m_TAPERED->Add (taperedTemp);
			}
			m_Section->Add (sectionTemp);
		}
		f1.ReadString (csLine);
		csLine.Trim ();
	}
	//为iSEC建立索引
	m_iSECIndex=new CArray<int,int>;
	m_iSECIndex->SetSize (0);
	for(i=0;i<m_Section->GetSize();i++)
		m_iSECIndex->SetAtGrow (m_Section->GetAt(i).iSEC,i);
	f1.Close ();
	return TRUE;
}

int CImportMGTPlugIn::AddLayer( const wchar_t* layername,CRhinoDoc& doc,int parent)
{
	CRhinoLayerTable& layer_table = doc.m_layer_table;
	int layer_index;
	if(parent == -1)
	{
		layer_index = layer_table.FindLayer(layername);
		if( layer_index < 0 )
		{
			ON_Layer layer;
			layer.SetLayerName(layername);
			layer_index = layer_table.AddLayer(layer);
		}
	}
	else
	{
		layer_index = layer_table.FindLayer(layername);
		if( layer_index < 0 )
		{
			ON_Layer layer;
			layer.SetLayerName(layername);
			layer.m_parent_layer_id = layer_table[parent].m_layer_id ;
			layer_index = layer_table.AddLayer(layer);
		}
	}

	return layer_index;
}

bool CImportMGTPlugIn::AddNode( const NODE& Node,CRhinoDoc& doc,int layer_NODE,double scale)
{
	ON_3dPoint on_3dpt;
	CString cstr;
	on_3dpt.x = scale*Node.X ;
	on_3dpt.y = scale*Node.Y ;
	on_3dpt.z = scale*Node.Z ;
	CRhinoPointObject* pPtObj = doc.AddPointObject (on_3dpt);
	CRhinoObjectAttributes attr(pPtObj->Attributes ());
	attr.m_layer_index =layer_NODE;
	cstr.Format (L"%d",Node.iNO );
	attr.SetUserString (L"iNO",cstr );
	if("MM"==m_Unit.LENGTH )
	{
		cstr.Format (L"%.2fmm",Node.X );
		attr.SetUserString (L"X",cstr);
		cstr.Format (L"%.2fmm",Node.Y );
		attr.SetUserString (L"Y",cstr);
		cstr.Format (L"%.2fmm",Node.Z );
		attr.SetUserString (L"Z",cstr);
	}
	if("M"==m_Unit.LENGTH )
	{
		cstr.Format (L"%.2fmm",1000*Node.X );
		attr.SetUserString (L"X",cstr);
		cstr.Format (L"%.2fmm",1000*Node.Y );
		attr.SetUserString (L"Y",cstr);
		cstr.Format (L"%.2fmm",1000*Node.Z );
		attr.SetUserString (L"Z",cstr);
	}
	CRhinoObjRef ref(pPtObj);
	if( !doc.ModifyObjectAttributes(ref, attr) )
	{
		RhinoApp().Print( L"error");
		return FALSE;
	}
	return TRUE;
}
bool CImportMGTPlugIn::AddElement(const ELEMENT& Element,CRhinoDoc& doc,int layer_ELEMENT[4],int with_section,int layer_SECTION,double scale)
{
	ON_3dPoint on_3dpt1,on_3dpt2;
	ON_Line on_ln;
	CString cstr;
	if(L"BEAM"==Element.TYPE |L"TRUSS"==Element.TYPE )
	{
		if(L"BEAM"==Element.TYPE)
		{
			on_3dpt1.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).X ;
			on_3dpt1.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).Y ;
			on_3dpt1.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).Z ;
			on_3dpt2.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).X ;
			on_3dpt2.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).Y ;
			on_3dpt2.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).Z ;
			on_ln.Create (on_3dpt1,on_3dpt2);
			CRhinoCurveObject* pCrvObj=doc.AddCurveObject (on_ln);
			CRhinoObjectAttributes attr(pCrvObj->Attributes ());
			attr.m_layer_index =layer_ELEMENT[1];
			if(1==m_Beams->GetAt (Element.index).CHECK)
			{
				ON_Color on_clr(0,255,0);
				attr.SetColorSource (ON::color_from_object );
				attr.m_color =on_clr;
			}
			if(2==m_Beams->GetAt (Element.index).CHECK)
			{
				ON_Color on_clr(255,0,0);
				attr.SetColorSource (ON::color_from_object );
				attr.m_color =on_clr;
			}
			if(3==m_Beams->GetAt (Element.index).CHECK)
			{
				ON_Color on_clr(0,0,255);
				attr.SetColorSource (ON::color_from_object );
				attr.m_color =on_clr;
			}
			cstr.Format (L"%d",Element.iEL);
			attr.SetUserString (L"iEL",cstr);
			attr.SetUserString (L"TYPE",Element.TYPE );
			cstr.Format (L"%d",m_Beams->GetAt (Element.index ).iN1);
			attr.SetUserString (L"iN1",cstr );
			cstr.Format (L"%d",m_Beams->GetAt (Element.index ).iN2);
			attr.SetUserString (L"iN2",cstr );
			if("MM"==m_Unit.LENGTH )
			{
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).X );
				attr.SetUserString (L"iN1_X",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).Y );
				attr.SetUserString (L"iN1_Y",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).Z );
				attr.SetUserString (L"iN1_Z",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).X );
				attr.SetUserString (L"iN2_X",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).Y );
				attr.SetUserString (L"iN2_Y",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).Z );
				attr.SetUserString (L"iN2_Z",cstr);
				cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
				attr.SetUserString (L"Length",cstr);
			}
			if("M"==m_Unit.LENGTH )
			{
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).X );
				attr.SetUserString (L"iN1_X",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).Y );
				attr.SetUserString (L"iN1_Y",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN1) ).Z );
				attr.SetUserString (L"iN1_Z",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).X );
				attr.SetUserString (L"iN2_X",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).Y );
				attr.SetUserString (L"iN2_Y",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (Element.index ).iN2) ).Z );
				attr.SetUserString (L"iN2_Z",cstr);
				cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
				attr.SetUserString (L"Length",cstr);
			}
			CRhinoObjRef ref(pCrvObj);
			if( !doc.ModifyObjectAttributes(ref, attr) )
			{
				RhinoApp().Print( L"error");
				return FALSE;
			}
		}
		if(L"TRUSS"==Element.TYPE)
		{
			on_3dpt1.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).X ;
			on_3dpt1.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).Y ;
			on_3dpt1.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).Z ;
			on_3dpt2.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).X ;
			on_3dpt2.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).Y ;
			on_3dpt2.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).Z ;
			on_ln.Create (on_3dpt1,on_3dpt2);
			CRhinoCurveObject* pCrvObj=doc.AddCurveObject (on_ln);
			CRhinoObjectAttributes attr(pCrvObj->Attributes ());
			attr.m_layer_index =layer_ELEMENT[2];
			if(1==m_Beams->GetAt (Element.index).CHECK)
			{
				ON_Color on_clr(0,255,0);
				attr.SetColorSource (ON::color_from_object );
				attr.m_color =on_clr;
			}
			if(2==m_Beams->GetAt (Element.index).CHECK)
			{
				ON_Color on_clr(255,0,0);
				attr.SetColorSource (ON::color_from_object );
				attr.m_color =on_clr;
			}
			if(3==m_Beams->GetAt (Element.index).CHECK)
			{
				ON_Color on_clr(0,0,255);
				attr.SetColorSource (ON::color_from_object );
				attr.m_color =on_clr;
			}
			cstr.Format (L"%d",Element.iEL);
			attr.SetUserString (L"iEL",cstr);
			attr.SetUserString (L"TYPE",Element.TYPE );
			cstr.Format (L"%d",m_Trusses->GetAt (Element.index ).iN1);
			attr.SetUserString (L"iN1",cstr );
			cstr.Format (L"%d",m_Trusses->GetAt (Element.index ).iN2);
			attr.SetUserString (L"iN2",cstr );
			if("MM"==m_Unit.LENGTH )
			{
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).X );
				attr.SetUserString (L"iN1_X",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).Y );
				attr.SetUserString (L"iN1_Y",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).Z );
				attr.SetUserString (L"iN1_Z",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).X );
				attr.SetUserString (L"iN2_X",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).Y );
				attr.SetUserString (L"iN2_Y",cstr);
				cstr.Format (L"%.2fmm",m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).Z );
				attr.SetUserString (L"iN2_Z",cstr);
				cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
				attr.SetUserString (L"Length",cstr);
			}
			if("M"==m_Unit.LENGTH )
			{
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).X );
				attr.SetUserString (L"iN1_X",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).Y );
				attr.SetUserString (L"iN1_Y",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN1) ).Z );
				attr.SetUserString (L"iN1_Z",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).X );
				attr.SetUserString (L"iN2_X",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).Y );
				attr.SetUserString (L"iN2_Y",cstr);
				cstr.Format (L"%.2fmm",1000*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (Element.index ).iN2) ).Z );
				attr.SetUserString (L"iN2_Z",cstr);
				cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
				attr.SetUserString (L"Length",cstr);
			}
			CRhinoObjRef ref(pCrvObj);
			if( !doc.ModifyObjectAttributes(ref, attr) )
			{
				RhinoApp().Print( L"error");
				return FALSE;
			}
		}

		//Rhino 5.0之前没有Extrusion
#pragma region AddSectionRhino4
		/*if(IDYES==with_section)
		{
			int index=m_iSECIndex->GetAt(Element.iPRO);

			if(L"DBUSER"==m_Section->GetAt (index).TYPE )
			{
				if(2==m_DBUSER->GetAt (m_Section->GetAt (index).index ).DATA1SIGN )
				{

					if(L"P" == m_Section->GetAt (index).SHAPE)
					{

						double diameter=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						double thickness=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D2;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						ON_Circle cir_out(pln,diameter/2);
						//ON_Circle cir_in(pln,diameter/2 - thickness);
						ON_Cylinder cyl_out(cir_out,on_ln.Length ());
						//ON_Cylinder cyl_in(cir_in,on_ln.Length ());
						ON_Brep* brep=ON_BrepCylinder(cyl_out,false,false);
						//ON_Brep* brep2=ON_BrepCylinder(cyl_in,false,false);
						//brep->Append (*brep2);
						//brep2->Destroy ();
						//brep=RhinoBrepCapPlanarHoles(brep,doc.AbsoluteTolerance());
						if( brep )
						{
							CRhinoBrepObject* pBObj = new CRhinoBrepObject();
							pBObj->SetBrep( brep );
							CRhinoObjectAttributes attr(pBObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.25*sqrt(diameter*diameter+(diameter-2*thickness)*(diameter-2*thickness))));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(pBObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(pBObj) )
							{
								return TRUE;
							}
							else
							{
								delete pBObj;
								pBObj = 0;
								return FALSE;
							}
						}
					}
					if(L"SB" == m_Section->GetAt (index).SHAPE)
					{
						const double PI=3.14159265358979323846;
						double length=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						double width=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D2;
						double angle;
						if(L"BEAM"==Element.TYPE)
							angle=m_Beams->GetAt (Element.index ).ANGLE ;
						if(L"TRUSS"==Element.TYPE)
							angle=m_Trusses->GetAt (Element.index ).ANGLE ;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						ON_3dVector vecx=pln.xaxis ;
						vecx.Unitize ();
						vecx *= length/2;
						ON_3dVector vecy=pln.yaxis ;
						vecy.Unitize ();
						vecy *= width/2;
						ON_3dPoint pt;
						ON_3dPointArray corners;
						pt=on_ln.from + vecx + vecy;
						corners.Append( pt);
						pt=on_ln.from - vecx + vecy;
						corners.Append( pt);
						pt=on_ln.from - vecx - vecy;
						corners.Append( pt );
						pt=on_ln.from + vecx - vecy;
						corners.Append( pt );
						pt=on_ln.to + vecx + vecy;
						corners.Append( pt);
						pt=on_ln.to - vecx + vecy;
						corners.Append( pt);
						pt=on_ln.to - vecx - vecy;
						corners.Append( pt );
						pt=on_ln.to + vecx - vecy;
						corners.Append( pt );
						corners.Rotate(angle*PI/180,on_ln.Direction (),on_ln.from );
						ON_Brep* pBrep = ON_BrepBox( corners );
						if( pBrep )
						{
							CRhinoBrepObject* pBObj = new CRhinoBrepObject();
							pBObj->SetBrep( pBrep );
							CRhinoObjectAttributes attr(pBObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.289*min(length,width)));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(pBObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(pBObj) )
							{
								return TRUE;
							}
							else
							{
								delete pBObj;
								pBObj = 0;
								return FALSE;
							}
						}
					}
					if(L"B" == m_Section->GetAt (index).SHAPE)
					{
						double length1=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						double length2=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D2;
						double length3=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D3;
						double length4=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D4;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						ON_3dVector vecx=pln.xaxis ;
						vecx.Unitize ();
						ON_3dVector vecy=pln.yaxis ;
						vecy.Unitize ();
						ON_3dPoint pt;
						ON_3dPointArray corners;
						pt=on_ln.from + vecx * (length3/2) + vecy * (length1/2-length4);
						corners.Append( pt);
						pt=on_ln.from - vecx * (length3/2) + vecy * (length1/2-length4);
						corners.Append( pt);
						pt=on_ln.from - vecx * (length3/2) - vecy * (length1/2-length4);
						corners.Append( pt );
						pt=on_ln.from + vecx * (length3/2) - vecy * (length1/2-length4);
						corners.Append( pt );
						pt=on_ln.to + vecx * (length3/2) + vecy * (length1/2-length4);
						corners.Append( pt);
						pt=on_ln.to - vecx * (length3/2) + vecy * (length1/2-length4);
						corners.Append( pt);
						pt=on_ln.to - vecx * (length3/2) - vecy * (length1/2-length4);
						corners.Append( pt );
						pt=on_ln.to + vecx * (length3/2) - vecy * (length1/2-length4);
						corners.Append( pt );
						ON_Brep* pBrep = ON_BrepBox( corners );
						corners.Destroy ();
						pt=on_ln.from + vecx * (length2/2) + vecy * (length1/2-length4);
						corners.Append( pt);
						pt=on_ln.from + vecx * (length2/2) + vecy * (length1/2);
						corners.Append( pt);
						pt=on_ln.from - vecx * (length2/2) + vecy * (length1/2);
						corners.Append( pt );
						pt=on_ln.from - vecx * (length2/2) + vecy * (length1/2-length4);
						corners.Append( pt );
						pt=on_ln.to + vecx * (length2/2) + vecy * (length1/2-length4);
						corners.Append( pt);
						pt=on_ln.to + vecx * (length2/2) + vecy * (length1/2);
						corners.Append( pt);
						pt=on_ln.to - vecx * (length2/2) + vecy * (length1/2);
						corners.Append( pt );
						pt=on_ln.to - vecx * (length2/2) + vecy * (length1/2-length4);
						corners.Append( pt );
						ON_Brep* pBrep2 = ON_BrepBox( corners );
						pBrep->Append (*pBrep2);
						pBrep2->Destroy ();
						corners.Destroy ();
						pt=on_ln.from + vecx * (length2/2) - vecy * (length1/2);
						corners.Append( pt);
						pt=on_ln.from + vecx * (length2/2) - vecy * (length1/2 - length4);
						corners.Append( pt);
						pt=on_ln.from - vecx * (length2/2) - vecy * (length1/2 - length4);
						corners.Append( pt );
						pt=on_ln.from - vecx * (length2/2) - vecy * (length1/2);
						corners.Append( pt );
						pt=on_ln.to + vecx * (length2/2) - vecy * (length1/2);
						corners.Append( pt);
						pt=on_ln.to + vecx * (length2/2) - vecy * (length1/2 - length4);
						corners.Append( pt);
						pt=on_ln.to - vecx * (length2/2) - vecy * (length1/2 - length4);
						corners.Append( pt );
						pt=on_ln.to - vecx * (length2/2) - vecy * (length1/2);
						corners.Append( pt );
						pBrep2=ON_BrepBox(corners);
						pBrep->Append (*pBrep2);
						pBrep2->Destroy ();
						if( pBrep )
						{
							CRhinoBrepObject* pBObj = new CRhinoBrepObject();
							pBObj->SetBrep( pBrep );
							CRhinoObjectAttributes attr(pBObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.289*length3));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(pBObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(pBObj) )
							{
								return TRUE;
							}
							else
							{
								delete pBObj;
								pBObj = 0;
								return FALSE;
							}
						}
					}
					if(L"SR" == m_Section->GetAt (index).SHAPE)
					{
						double diameter=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						ON_Circle cir(pln,diameter/2);
						ON_Cylinder cyl(cir,on_ln.Length ());
						ON_Brep* brep=ON_BrepCylinder(cyl,false,false);
						if( brep )
						{
							CRhinoBrepObject* pBObj = new CRhinoBrepObject();
							pBObj->SetBrep( brep );
							CRhinoObjectAttributes attr(pBObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.25*diameter));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(pBObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(pBObj) )
							{
								return TRUE;
							}
							else
							{
								delete pBObj;
								pBObj = 0;
								return FALSE;
							}
						}
					}
				}
			}
			if(L"TAPERED"==m_Section->GetAt (index).TYPE )
			{
				if(L"USER"==m_TAPERED->GetAt (m_Section->GetAt (index).index).STYPE )
				{
					double length11 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D11 ;
					double length12 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D12 ;
					double length13 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D13 ;
					double length14 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D14 ;
					double length21 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D21 ;
					double length22 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D22 ;
					double length23 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D23 ;
					double length24 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D24 ;
					ON_Plane pln(on_ln.from ,on_ln.Direction ());
					ON_3dVector vecx=pln.xaxis ;
					vecx.Unitize ();
					ON_3dVector vecy=pln.yaxis ;
					vecy.Unitize ();
					ON_3dPoint pt;
					ON_3dPointArray corners;
					pt=on_ln.from + vecx * (length13/2) + vecy * (length11/2-length14);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length13/2) + vecy * (length11/2-length14);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length13/2) - vecy * (length11/2-length14);
					corners.Append( pt );
					pt=on_ln.from + vecx * (length13/2) - vecy * (length11/2-length14);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length23/2) + vecy * (length21/2-length24);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length23/2) + vecy * (length21/2-length24);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length23/2) - vecy * (length21/2-length24);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length23/2) - vecy * (length21/2-length24);
					corners.Append( pt );
					ON_Brep* pBrep = ON_BrepBox( corners );
					corners.Destroy ();
					pt=on_ln.from + vecx * (length12/2) + vecy * (length11/2-length14);
					corners.Append( pt);
					pt=on_ln.from + vecx * (length12/2) + vecy * (length11/2);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length12/2) + vecy * (length11/2);
					corners.Append( pt );
					pt=on_ln.from - vecx * (length12/2) + vecy * (length11/2-length14);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length22/2) + vecy * (length21/2-length24);
					corners.Append( pt);
					pt=on_ln.to + vecx * (length22/2) + vecy * (length21/2);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length22/2) + vecy * (length21/2);
					corners.Append( pt );
					pt=on_ln.to - vecx * (length22/2) + vecy * (length21/2-length24);
					corners.Append( pt );
					ON_Brep* pBrep2 = ON_BrepBox( corners );
					pBrep->Append (*pBrep2);
					pBrep2->Destroy ();
					corners.Destroy ();
					pt=on_ln.from + vecx * (length12/2) - vecy * (length11/2);
					corners.Append( pt);
					pt=on_ln.from + vecx * (length12/2) - vecy * (length11/2 - length14);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length12/2) - vecy * (length11/2 - length14);
					corners.Append( pt );
					pt=on_ln.from - vecx * (length12/2) - vecy * (length11/2);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length22/2) - vecy * (length21/2);
					corners.Append( pt);
					pt=on_ln.to + vecx * (length22/2) - vecy * (length21/2 - length24);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length22/2) - vecy * (length21/2 - length24);
					corners.Append( pt );
					pt=on_ln.to - vecx * (length22/2) - vecy * (length21/2);
					corners.Append( pt );
					pBrep2=ON_BrepBox(corners);
					pBrep->Append (*pBrep2);
					pBrep2->Destroy ();
					if( pBrep )
					{
						CRhinoBrepObject* pBObj = new CRhinoBrepObject();
						pBObj->SetBrep( pBrep );
						CRhinoObjectAttributes attr(pBObj->Attributes ());
						attr.m_name = m_Section->GetAt (index).SNAME;
						attr.m_layer_index =layer_SECTION;
						attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
						if("MM"==m_Unit.LENGTH )
						{
							cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
							attr.SetUserString (L"Length",cstr);
						}
						if("M"==m_Unit.LENGTH )
						{
							cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
							attr.SetUserString (L"Length",cstr);
						}
						cstr.Format (L"%.3f",on_ln.Length() /(0.289*(length13+length23)/2));
						attr.SetUserString (L"长细比",cstr);
						CRhinoObjRef ref(pBObj);
						doc.ModifyObjectAttributes(ref, attr);
						if( doc.AddObject(pBObj) )
						{
							return TRUE;
						}
						else
						{
							delete pBObj;
							pBObj = 0;
							return FALSE;
						}
					}
				}
			}
		}*/
#pragma endregion
#pragma region AddSectionRhino5
		if(IDYES==with_section)
		{
			int index=m_iSECIndex->GetAt(Element.iPRO);

			if(L"DBUSER"==m_Section->GetAt (index).TYPE )
			{
				if(2==m_DBUSER->GetAt (m_Section->GetAt (index).index ).DATA1SIGN )
				{

					if(L"P" == m_Section->GetAt (index).SHAPE)
					{

						double diameter=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						double thickness=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D2;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						pln.xaxis.Unitize();
						pln.yaxis.Unitize();
						pln.zaxis.Unitize();
						pln.UpdateEquation();
						ON_Circle cir_out(ON_xy_plane,diameter/2);
						ON_NurbsCurve cirCrv;
						cir_out.GetNurbForm(cirCrv);
						ON_Curve* profile_out = new ON_NurbsCurve(cirCrv);
						ON_Circle cir_in(ON_xy_plane,diameter/2 - thickness);
						cir_in.GetNurbForm(cirCrv);
						ON_Curve* profile_in = new ON_NurbsCurve(cirCrv);
						ON_Extrusion* extru_cylinder = new ON_Extrusion();
						extru_cylinder->SetOuterProfile(profile_out,true);
						extru_cylinder->SetPathAndUp(on_ln.from,on_ln.to,pln.yaxis);
						extru_cylinder->AddInnerProfile(profile_in);
						if( extru_cylinder->IsValid() )
						{
							CRhinoExtrusionObject* extruObj = new CRhinoExtrusionObject();
							extruObj->SetExtrusion(extru_cylinder);
							CRhinoObjectAttributes attr(extruObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.25*sqrt(diameter*diameter+(diameter-2*thickness)*(diameter-2*thickness))));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(extruObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(extruObj) )
							{
								return TRUE;
							}
							else
							{
								delete extruObj;
								extruObj = 0;
								return FALSE;
							}
						}
						else
						{
							delete extru_cylinder;
						}
					}
					if(L"SB" == m_Section->GetAt (index).SHAPE)
					{
						double length=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						double width=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D2;
						double angle;
						if(L"BEAM"==Element.TYPE)
							angle=m_Beams->GetAt (Element.index ).ANGLE ;
						if(L"TRUSS"==Element.TYPE)
							angle=m_Trusses->GetAt (Element.index ).ANGLE ;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						pln.xaxis.Unitize();
						pln.yaxis.Unitize();
						pln.zaxis.Unitize();
						pln.UpdateEquation();
						ON_3dVector vecy=pln.yaxis ;
						vecy.Rotate(angle*ON_PI/180,pln.zaxis);

						ON_PolylineCurve* profile = new ON_PolylineCurve();
						profile->m_dim = 2;
						profile->m_t.Append(0.0);
						profile->m_t.Append(length);
						profile->m_t.Append(length+width);
						profile->m_t.Append(2.0*length+width);
						profile->m_t.Append(2.0*(length+width));
						profile->m_pline.Append(ON_3dPoint(length/2,width/2,0.0));
						profile->m_pline.Append(ON_3dPoint(-length/2,width/2,0.0));
						profile->m_pline.Append(ON_3dPoint(-length/2,-width/2,0.0));
						profile->m_pline.Append(ON_3dPoint(length/2,-width/2,0.0));
						profile->m_pline.Append(ON_3dPoint(length/2,width/2,0.0));

						ON_Extrusion* extru_box = new ON_Extrusion();
						extru_box->SetOuterProfile(profile,true);
						extru_box->SetPathAndUp(on_ln.from,on_ln.to,vecy);
						if( extru_box->IsValid() )
						{
							CRhinoExtrusionObject* extruObj = new CRhinoExtrusionObject();
							extruObj->SetExtrusion(extru_box);
							CRhinoObjectAttributes attr(extruObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.289*min(length,width)));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(extruObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(extruObj) )
							{
								return TRUE;
							}
							else
							{
								delete extruObj;
								extruObj = 0;
								return FALSE;
							}
						}
						else
						{
							delete extru_box;
						}
					}
					if(L"B" == m_Section->GetAt (index).SHAPE)
					{
						double length1=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						double length2=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D2;
						double length3=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D3;
						double length4=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D4;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						pln.xaxis.Unitize();
						pln.yaxis.Unitize();
						pln.zaxis.Unitize();
						pln.UpdateEquation();
						ON_3dVector vecy = pln.yaxis;
						
						ON_PolylineCurve* profile = new ON_PolylineCurve();
						profile->m_dim = 2;
						profile->m_t.Append(0.0);
						profile->m_t.Append(length2);
						profile->m_t.Append(length2+length4);
						profile->m_t.Append(3*length2/2+length4-length3/2);
						profile->m_t.Append(3*length2/2-length3/2+length1-length4);
						profile->m_t.Append(2*length2-length3+length1-length4);
						profile->m_t.Append(2*length2-length3+length1);
						profile->m_t.Append(3*length2-length3+length1);
						profile->m_t.Append(3*length2-length3+length1+length4);
						profile->m_t.Append(7*length2/2-3*length3/2+length1+length4);
						profile->m_t.Append(7*length2/2-3*length3/2+2*length1-length4);
						profile->m_t.Append(4*length2-2*length3+2*length1-length4);
						profile->m_t.Append(4*length2-2*length3+2*length1);
						profile->m_pline.Append(ON_3dPoint(-length2/2,-length1/2,0.0));
						profile->m_pline.Append(ON_3dPoint(length2/2,-length1/2,0.0));
						profile->m_pline.Append(ON_3dPoint(length2/2,-length1/2+length4,0.0));
						profile->m_pline.Append(ON_3dPoint(length3/2,-length1/2+length4,0.0));
						profile->m_pline.Append(ON_3dPoint(length3/2,length1/2-length4,0.0));
						profile->m_pline.Append(ON_3dPoint(length2/2,length1/2-length4,0.0));
						profile->m_pline.Append(ON_3dPoint(length2/2,length1/2,0.0));
						profile->m_pline.Append(ON_3dPoint(-length2/2,length1/2,0.0));
						profile->m_pline.Append(ON_3dPoint(-length2/2,length1/2-length4,0.0));
						profile->m_pline.Append(ON_3dPoint(-length3/2,length1/2-length4,0.0));
						profile->m_pline.Append(ON_3dPoint(-length3/2,-length1/2+length4,0.0));
						profile->m_pline.Append(ON_3dPoint(-length2/2,-length1/2+length4,0.0));
						profile->m_pline.Append(ON_3dPoint(-length2/2,-length1/2,0.0));
						ON_Extrusion* extru_box = new ON_Extrusion();
						extru_box->SetOuterProfile(profile,true);
						extru_box->SetPathAndUp(on_ln.from,on_ln.to,vecy);
						if( extru_box->IsValid() )
						{
							CRhinoExtrusionObject* extruObj = new CRhinoExtrusionObject();
							extruObj->SetExtrusion(extru_box);
							CRhinoObjectAttributes attr(extruObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.289*length3));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(extruObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(extruObj) )
							{
								return TRUE;
							}
							else
							{
								delete extruObj;
								extruObj = 0;
								return FALSE;
							}
						}
						else
						{
							delete extru_box;
						}
					}
					if(L"SR" == m_Section->GetAt (index).SHAPE)
					{
						double diameter=scale*m_DATA1_2->GetAt (m_DBUSER->GetAt (m_Section->GetAt (index).index ).index ).D1;
						ON_Plane pln(on_ln.from ,on_ln.Direction ());
						pln.xaxis.Unitize();
						pln.yaxis.Unitize();
						pln.zaxis.Unitize();
						pln.UpdateEquation();
						ON_Circle cir(ON_xy_plane,diameter/2);
						ON_NurbsCurve cirCrv;
						cir.GetNurbForm(cirCrv);
						ON_Curve* profile = new ON_NurbsCurve(cirCrv);
						ON_Extrusion* extru_cylinder = new ON_Extrusion();
						extru_cylinder->SetOuterProfile(profile,true);
						extru_cylinder->SetPathAndUp(on_ln.from,on_ln.to,pln.yaxis);
						if( extru_cylinder->IsValid() )
						{
							CRhinoExtrusionObject* extruObj = new CRhinoExtrusionObject();
							extruObj->SetExtrusion(extru_cylinder);
							CRhinoObjectAttributes attr(extruObj->Attributes ());
							attr.m_name = m_Section->GetAt (index).SNAME;
							attr.m_layer_index =layer_SECTION;
							attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
							if("MM"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							if("M"==m_Unit.LENGTH )
							{
								cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
								attr.SetUserString (L"Length",cstr);
							}
							cstr.Format (L"%.3f",on_ln.Length() /(0.25*diameter));
							attr.SetUserString (L"长细比",cstr);
							CRhinoObjRef ref(extruObj);
							doc.ModifyObjectAttributes(ref, attr);
							if( doc.AddObject(extruObj) )
							{
								return TRUE;
							}
							else
							{
								delete extruObj;
								extruObj = 0;
								return FALSE;
							}
						}
						else
						{
							delete extru_cylinder;
						}
					}
				}
			}
			if(L"TAPERED"==m_Section->GetAt (index).TYPE )
			{
				if(L"USER"==m_TAPERED->GetAt (m_Section->GetAt (index).index).STYPE )
				{
					double length11 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D11 ;
					double length12 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D12 ;
					double length13 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D13 ;
					double length14 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D14 ;
					double length21 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D21 ;
					double length22 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D22 ;
					double length23 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D23 ;
					double length24 = scale*m_DIM->GetAt (m_TAPERED->GetAt (m_Section->GetAt (index).index).index ).D24 ;
					ON_Plane pln(on_ln.from ,on_ln.Direction ());
					ON_3dVector vecx=pln.xaxis ;
					vecx.Unitize ();
					ON_3dVector vecy=pln.yaxis ;
					vecy.Unitize ();
					ON_3dPoint pt;
					ON_3dPointArray corners;
					pt=on_ln.from + vecx * (length13/2) + vecy * (length11/2-length14);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length13/2) + vecy * (length11/2-length14);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length13/2) - vecy * (length11/2-length14);
					corners.Append( pt );
					pt=on_ln.from + vecx * (length13/2) - vecy * (length11/2-length14);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length23/2) + vecy * (length21/2-length24);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length23/2) + vecy * (length21/2-length24);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length23/2) - vecy * (length21/2-length24);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length23/2) - vecy * (length21/2-length24);
					corners.Append( pt );
					ON_Brep* pBrep = ON_BrepBox( corners );
					corners.Destroy ();
					pt=on_ln.from + vecx * (length12/2) + vecy * (length11/2-length14);
					corners.Append( pt);
					pt=on_ln.from + vecx * (length12/2) + vecy * (length11/2);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length12/2) + vecy * (length11/2);
					corners.Append( pt );
					pt=on_ln.from - vecx * (length12/2) + vecy * (length11/2-length14);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length22/2) + vecy * (length21/2-length24);
					corners.Append( pt);
					pt=on_ln.to + vecx * (length22/2) + vecy * (length21/2);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length22/2) + vecy * (length21/2);
					corners.Append( pt );
					pt=on_ln.to - vecx * (length22/2) + vecy * (length21/2-length24);
					corners.Append( pt );
					ON_Brep* pBrep2 = ON_BrepBox( corners );
					pBrep->Append (*pBrep2);
					pBrep2->Destroy ();
					corners.Destroy ();
					pt=on_ln.from + vecx * (length12/2) - vecy * (length11/2);
					corners.Append( pt);
					pt=on_ln.from + vecx * (length12/2) - vecy * (length11/2 - length14);
					corners.Append( pt);
					pt=on_ln.from - vecx * (length12/2) - vecy * (length11/2 - length14);
					corners.Append( pt );
					pt=on_ln.from - vecx * (length12/2) - vecy * (length11/2);
					corners.Append( pt );
					pt=on_ln.to + vecx * (length22/2) - vecy * (length21/2);
					corners.Append( pt);
					pt=on_ln.to + vecx * (length22/2) - vecy * (length21/2 - length24);
					corners.Append( pt);
					pt=on_ln.to - vecx * (length22/2) - vecy * (length21/2 - length24);
					corners.Append( pt );
					pt=on_ln.to - vecx * (length22/2) - vecy * (length21/2);
					corners.Append( pt );
					pBrep2=ON_BrepBox(corners);
					pBrep->Append (*pBrep2);
					pBrep2->Destroy ();
					if( pBrep )
					{
						CRhinoBrepObject* pBObj = new CRhinoBrepObject();
						pBObj->SetBrep( pBrep );
						CRhinoObjectAttributes attr(pBObj->Attributes ());
						attr.m_name = m_Section->GetAt (index).SNAME;
						attr.m_layer_index =layer_SECTION;
						attr.SetUserString (L"SNAME",m_Section->GetAt (index).SNAME );
						if("MM"==m_Unit.LENGTH )
						{
							cstr.Format (L"%.2fmm",on_ln.Length ()/scale);
							attr.SetUserString (L"Length",cstr);
						}
						if("M"==m_Unit.LENGTH )
						{
							cstr.Format (L"%.2fmm",1000*on_ln.Length ()/scale);
							attr.SetUserString (L"Length",cstr);
						}
						cstr.Format (L"%.3f",on_ln.Length() /(0.289*(length13+length23)/2));
						attr.SetUserString (L"长细比",cstr);
						CRhinoObjRef ref(pBObj);
						doc.ModifyObjectAttributes(ref, attr);
						if( doc.AddObject(pBObj) )
						{
							return TRUE;
						}
						else
						{
							delete pBObj;
							pBObj = 0;
							return FALSE;
						}
					}
				}
			}
		}
#pragma endregion
	}
	return TRUE;
}

void CImportMGTPlugIn::Check(double scale)
{
	int i,j,m;
	ON_SimpleArray<ON_wString> str;

	//长度检验
	m=0;
	str.Destroy ();
	if("MM"==m_Unit.LENGTH )
		str.Append(L"   iEL, Length(mm)\n");
	if("M"==m_Unit.LENGTH )
		str.Append(L"   iEL, Length(m)\n");
	ON_3dPoint on_3dpt1,on_3dpt2;
	ON_Line on_ln;
	for(i=0;i<m_Elements->GetSize ();i++)
	{
		if(L"BEAM"==m_Elements->GetAt (i).TYPE)
		{
			on_3dpt1.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (m_Elements->GetAt (i).index).iN1) ).X ;
			on_3dpt1.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (m_Elements->GetAt (i).index).iN1) ).Y ;
			on_3dpt1.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (m_Elements->GetAt (i).index).iN1) ).Z ;
			on_3dpt2.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (m_Elements->GetAt (i).index).iN2) ).X ;
			on_3dpt2.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (m_Elements->GetAt (i).index).iN2) ).Y ;
			on_3dpt2.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Beams->GetAt (m_Elements->GetAt (i).index).iN2) ).Z ;
			on_ln.Create (on_3dpt1,on_3dpt2);
			if("MM"==m_Unit.LENGTH )
			{

				if(on_ln.Length()<400)
				{
					m_Beams->GetAt (m_Elements->GetAt (i).index).CHECK =1;
					str.AppendNew ();
					str[m+1].Format (L"%6d,%10.6f\n", m_Elements->GetAt (i).iEL ,on_ln.Length());
					m++;
				}		
			}
			if("M"==m_Unit.LENGTH )
			{
				if(on_ln.Length()<0.4)
				{
					m_Beams->GetAt (m_Elements->GetAt (i).index).CHECK =1;
					str.AppendNew ();
					str[m+1].Format (L"%6d,%10.6f\n", m_Elements->GetAt (i).iEL ,on_ln.Length());
					m++;
				}
			}
		}
		if(L"TRUSS"==m_Elements->GetAt (i).TYPE)
		{
			on_3dpt1.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (m_Elements->GetAt (i).index).iN1) ).X ;
			on_3dpt1.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (m_Elements->GetAt (i).index).iN1) ).Y ;
			on_3dpt1.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (m_Elements->GetAt (i).index).iN1) ).Z ;
			on_3dpt2.x =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (m_Elements->GetAt (i).index).iN2) ).X ;
			on_3dpt2.y =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (m_Elements->GetAt (i).index).iN2) ).Y ;
			on_3dpt2.z =scale*m_Nodes->GetAt (m_iNOIndex->GetAt (m_Trusses->GetAt (m_Elements->GetAt (i).index).iN2) ).Z ;
			on_ln.Create (on_3dpt1,on_3dpt2);
			if("MM"==m_Unit.LENGTH )
			{
				if(on_ln.Length()<400)
				{
					m_Trusses->GetAt (m_Elements->GetAt (i).index).CHECK =1;
					str.AppendNew ();
					str[m+1].Format (L"%6d,%10.6f\n", m_Elements->GetAt (i).iEL ,on_ln.Length());
					m++;
				}

			}
			if("M"==m_Unit.LENGTH )
			{
				if(on_ln.Length()<0.4)
				{
					m_Trusses->GetAt (m_Elements->GetAt (i).index).CHECK =1;
					str.AppendNew ();
					str[m+1].Format (L"%6d,%10.6f\n", m_Elements->GetAt (i).iEL ,on_ln.Length());
					m++;
				}

			}
		}

	}

	//Get filename
	ON_wString filename=L"Length.txt";
	CRhinoGetFileDialog gf;
	//gf.SetScriptMode (true);
	gf.SetDialogTitle (L"Save LENGTH file to");
	gf.DisplayFileDialog(CRhinoGetFileDialog::save_text_file_dialog , filename, CWnd::FromHandle( RhinoApp().MainWnd() ));
	filename = gf.FileName();
	filename.TrimLeftAndRight();
	// Write to a text file
	CStdioFile f1;
	if( !f1.Open( filename, CFile::modeCreate | CFile::modeWrite | CFile::typeText ) ) 
	{
		exit( 1 );
	}
	for(i=0;i<str.Count ();i++)
		f1.WriteString(str[i]);
	f1.Close ();

	//角度检验

	m=0;
	str.Destroy ();
	str.Append(L"  iEL1,  iEL2, angle(rad)\n");
	int s,t;
	CHECK checktmp;
	CArray<CHECK,CHECK>* checks=new CArray<CHECK,CHECK>;
	ON_3dVector v0,v1;
	for(i=0;i<m_Nodes->GetSize ();i++)
	{
		checks->SetSize (0);
		for(j=0;j<m_Elements->GetSize ();j++)
		{
			if(L"BEAM"==m_Elements->GetAt (j).TYPE)
			{
				if(m_Nodes->GetAt (i).iNO==m_Beams->GetAt( m_Elements->GetAt (j).index).iN1)
				{
					checktmp.index = j;
					checktmp.End =m_Beams->GetAt( m_Elements->GetAt (j).index).iN2;
					checks->Add (checktmp);
				}
				if(m_Nodes->GetAt (i).iNO==m_Beams->GetAt( m_Elements->GetAt (j).index).iN2)
				{
					checktmp.index = j;
					checktmp.End =m_Beams->GetAt( m_Elements->GetAt (j).index).iN1;
					checks->Add (checktmp);
				}
			}
			if(L"TRUSS"==m_Elements->GetAt (j).TYPE)
			{
				if(m_Nodes->GetAt (i).iNO==m_Trusses->GetAt( m_Elements->GetAt (j).index).iN1)
				{
					checktmp.index = j;
					checktmp.End =m_Trusses->GetAt( m_Elements->GetAt (j).index).iN2;
					checks->Add (checktmp);
				}
				if(m_Nodes->GetAt (i).iNO==m_Trusses->GetAt( m_Elements->GetAt (j).index).iN2)
				{
					checktmp.index = j;
					checktmp.End =m_Trusses->GetAt( m_Elements->GetAt (j).index).iN1;
					checks->Add (checktmp);
				}
			}
		}
		for(s=0;s<checks->GetSize ()-1;s++)
		{
			v0.x =m_Nodes->GetAt(m_iNOIndex->GetAt(checks->GetAt (s).End )).X -m_Nodes->GetAt (i).X;
			v0.y =m_Nodes->GetAt(m_iNOIndex->GetAt(checks->GetAt (s).End )).Y -m_Nodes->GetAt (i).Y; 
			v0.z =m_Nodes->GetAt(m_iNOIndex->GetAt(checks->GetAt (s).End )).Z -m_Nodes->GetAt (i).Z;
			v0.Unitize ();
			for(t=s+1;t<checks->GetSize ();t++)
			{
				v1.x =m_Nodes->GetAt(m_iNOIndex->GetAt(checks->GetAt (t).End )).X -m_Nodes->GetAt (i).X ;
				v1.y =m_Nodes->GetAt(m_iNOIndex->GetAt(checks->GetAt (t).End )).Y -m_Nodes->GetAt (i).Y ;
				v1.z =m_Nodes->GetAt(m_iNOIndex->GetAt(checks->GetAt (t).End )).Z -m_Nodes->GetAt (i).Z;
				v1.Unitize ();
				double dot = ON_DotProduct( v0, v1 );
				dot = ( dot < -1.0 ? -1.0 : ( dot > 1.0 ? 1.0 : dot ) );
				double angle = acos( dot );
				if(angle < ON_PI/6)
				{
					if(L"BEAM"==m_Elements->GetAt(checks->GetAt (s).index ).TYPE  )
						if(m_Beams->GetAt(m_Elements->GetAt(checks->GetAt (s).index ).index ).CHECK < 2)
							m_Beams->GetAt(m_Elements->GetAt(checks->GetAt (s).index ).index ).CHECK +=2;
					if(L"TRUSS"==m_Elements->GetAt(checks->GetAt (s).index ).TYPE  )
						if(m_Trusses->GetAt(m_Elements->GetAt(checks->GetAt (s).index ).index ).CHECK < 2)
							m_Trusses->GetAt(m_Elements->GetAt(checks->GetAt (s).index ).index ).CHECK +=2;
					if(L"BEAM"==m_Elements->GetAt(checks->GetAt (t).index ).TYPE  )
						if(m_Beams->GetAt(m_Elements->GetAt(checks->GetAt (t).index ).index ).CHECK < 2)
							m_Beams->GetAt(m_Elements->GetAt(checks->GetAt (t).index ).index ).CHECK +=2;
					if(L"TRUSS"==m_Elements->GetAt(checks->GetAt (t).index ).TYPE  )
						if(m_Trusses->GetAt(m_Elements->GetAt(checks->GetAt (t).index ).index ).CHECK < 2)
							m_Trusses->GetAt(m_Elements->GetAt(checks->GetAt (t).index ).index ).CHECK +=2;
					str.AppendNew ();
					str[m+1].Format(L"%6d,%6d, %f\n",m_Elements->GetAt(checks->GetAt (s).index ).iEL ,m_Elements->GetAt(checks->GetAt (t).index ).iEL,angle);
					m++;
				}
			}
		}

	}
	//Get filename
	ON_wString filename2=L"Angle.txt";
	CRhinoGetFileDialog gf2;
	//gf.SetScriptMode (true);
	gf2.SetDialogTitle (L"Save Angle file to");
	gf2.DisplayFileDialog(CRhinoGetFileDialog::save_text_file_dialog , filename2, CWnd::FromHandle( RhinoApp().MainWnd() ));
	filename2 = gf2.FileName();
	filename2.TrimLeftAndRight();
	// Write to a text file
	CStdioFile f2;
	if( !f2.Open( filename2, CFile::modeCreate | CFile::modeWrite | CFile::typeText ) ) 
	{
		exit( 1 );
	}
	for(i=0;i<str.Count ();i++)
		f2.WriteString(str[i]);
	f2.Close ();
}
