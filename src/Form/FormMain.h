/////////////////////////////////////////90////////////////////////////////////////////
#pragma once
#include "InputForm.h"
#include "..\Util\ResourceUtil.h"
#include "..\Sequence\SequenceConst.h"
#include "..\Sequence\SequenceArithmetic.h"
#include "..\Sequence\SequenceUniformDistribution.h"
#include "..\Sequence\SequenceBinomialDistribution.h"
#include "..\Sequence\SequenceNormalDistribution.h"
#include "..\Sequence\SequenceExpression.h"
#include "..\Calculation\Calculation1Variable.h"
#include "..\Calculation\Calculation2Variables.h"
#include "..\Chart\ChartHistogram.h"
#include "..\Chart\ChartBoxplot.h"
#include "..\Chart\ChartPoint.h"
#include "..\Chart\ChartLine.h"

namespace Statistica {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class FormMain : public System::Windows::Forms::Form{

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->mnuColumn = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuColumnAdd = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuColumnRemove = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuColumnClear = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator3 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuColumnLoad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuColumnSaveSelected = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuColumnSaveAll = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSequence = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSequenceConst = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSequenceArithmetic = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuSequenceUniformDistribution = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSequenceBinomialDistribution = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuSequenceNormalDistribution = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuSequenceExpression = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCalculation = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCalculation1Variable = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuCalculation2Variables = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator6 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuCalculationSaveResults = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuChart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuChartHistogram = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuChartBoxplot = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuChartScatterPlot = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuChartLineChart = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator5 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuChartSaveImage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuLanguage = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuLanguageGerman = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuLanguageEnglish = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mnuLanguageRussian = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->ctxtMnuDataGridView = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->ctxtMnuDeleteRow = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPageText = (gcnew System::Windows::Forms::TabPage());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tabPageGrafik = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolStripSeparator7 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->mnuColumnCopy = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->BeginInit();
			this->ctxtMnuDataGridView->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->tabControl->SuspendLayout();
			this->tabPageText->SuspendLayout();
			this->tabPageGrafik->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->mnuColumn, this->mnuSequence, 
				this->mnuCalculation, this->mnuChart, this->mnuLanguage});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(992, 24);
			this->menuStrip1->TabIndex = 0;
			// 
			// mnuColumn
			// 
			this->mnuColumn->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->mnuColumn->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {this->mnuColumnAdd, 
				this->mnuColumnRemove, this->mnuColumnClear, this->toolStripSeparator3, this->mnuColumnCopy, this->toolStripSeparator7, this->mnuColumnLoad, 
				this->mnuColumnSaveSelected, this->mnuColumnSaveAll});
			this->mnuColumn->Name = L"mnuColumn";
			this->mnuColumn->Size = System::Drawing::Size(49, 20);
			this->mnuColumn->Text = L"Spalte";
			// 
			// mnuColumnAdd
			// 
			this->mnuColumnAdd->Name = L"mnuColumnAdd";
			this->mnuColumnAdd->Size = System::Drawing::Size(180, 22);
			this->mnuColumnAdd->Text = L"Hinzufügen";
			this->mnuColumnAdd->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnAdd_Click);
			// 
			// mnuColumnRemove
			// 
			this->mnuColumnRemove->Enabled = false;
			this->mnuColumnRemove->Name = L"mnuColumnRemove";
			this->mnuColumnRemove->Size = System::Drawing::Size(180, 22);
			this->mnuColumnRemove->Text = L"Entfernen";
			this->mnuColumnRemove->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnRemove_Click);
			// 
			// mnuColumnClear
			// 
			this->mnuColumnClear->Enabled = false;
			this->mnuColumnClear->Name = L"mnuColumnClear";
			this->mnuColumnClear->Size = System::Drawing::Size(180, 22);
			this->mnuColumnClear->Text = L"Leeren";
			this->mnuColumnClear->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnClear_Click);
			// 
			// toolStripSeparator3
			// 
			this->toolStripSeparator3->Name = L"toolStripSeparator3";
			this->toolStripSeparator3->Size = System::Drawing::Size(177, 6);
			// 
			// mnuColumnLoad
			// 
			this->mnuColumnLoad->Name = L"mnuColumnLoad";
			this->mnuColumnLoad->Size = System::Drawing::Size(180, 22);
			this->mnuColumnLoad->Text = L"Laden...";
			this->mnuColumnLoad->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnLoad_Click);
			// 
			// mnuColumnSaveSelected
			// 
			this->mnuColumnSaveSelected->Enabled = false;
			this->mnuColumnSaveSelected->Name = L"mnuColumnSaveSelected";
			this->mnuColumnSaveSelected->Size = System::Drawing::Size(180, 22);
			this->mnuColumnSaveSelected->Text = L"Markierte speichern...";
			this->mnuColumnSaveSelected->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnSaveSelected_Click);
			// 
			// mnuColumnSaveAll
			// 
			this->mnuColumnSaveAll->Enabled = false;
			this->mnuColumnSaveAll->Name = L"mnuColumnSaveAll";
			this->mnuColumnSaveAll->Size = System::Drawing::Size(180, 22);
			this->mnuColumnSaveAll->Text = L"Alle speichern...";
			this->mnuColumnSaveAll->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnSaveAll_Click);
			// 
			// mnuSequence
			// 
			this->mnuSequence->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->mnuSequence->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {this->mnuSequenceConst, 
				this->mnuSequenceArithmetic, this->toolStripSeparator1, this->mnuSequenceUniformDistribution, this->mnuSequenceBinomialDistribution, 
				this->mnuSequenceNormalDistribution, this->toolStripSeparator2, this->mnuSequenceExpression});
			this->mnuSequence->Name = L"mnuSequence";
			this->mnuSequence->Size = System::Drawing::Size(60, 20);
			this->mnuSequence->Text = L"Sequenz";
			// 
			// mnuSequenceConst
			// 
			this->mnuSequenceConst->Name = L"mnuSequenceConst";
			this->mnuSequenceConst->Size = System::Drawing::Size(168, 22);
			this->mnuSequenceConst->Text = L"Konstante Werte";
			this->mnuSequenceConst->Click += gcnew System::EventHandler(this, &FormMain::mnuSequence_Click);
			// 
			// mnuSequenceArithmetic
			// 
			this->mnuSequenceArithmetic->Name = L"mnuSequenceArithmetic";
			this->mnuSequenceArithmetic->Size = System::Drawing::Size(168, 22);
			this->mnuSequenceArithmetic->Text = L"Arithmetische Folge";
			this->mnuSequenceArithmetic->Click += gcnew System::EventHandler(this, &FormMain::mnuSequence_Click);
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(165, 6);
			// 
			// mnuSequenceUniformDistribution
			// 
			this->mnuSequenceUniformDistribution->Name = L"mnuSequenceUniformDistribution";
			this->mnuSequenceUniformDistribution->Size = System::Drawing::Size(168, 22);
			this->mnuSequenceUniformDistribution->Text = L"Gleichverteilung";
			this->mnuSequenceUniformDistribution->Click += gcnew System::EventHandler(this, &FormMain::mnuSequence_Click);
			// 
			// mnuSequenceBinomialDistribution
			// 
			this->mnuSequenceBinomialDistribution->Name = L"mnuSequenceBinomialDistribution";
			this->mnuSequenceBinomialDistribution->Size = System::Drawing::Size(168, 22);
			this->mnuSequenceBinomialDistribution->Text = L"Binomialverteilung";
			this->mnuSequenceBinomialDistribution->Click += gcnew System::EventHandler(this, &FormMain::mnuSequence_Click);
			// 
			// mnuSequenceNormalDistribution
			// 
			this->mnuSequenceNormalDistribution->Name = L"mnuSequenceNormalDistribution";
			this->mnuSequenceNormalDistribution->Size = System::Drawing::Size(168, 22);
			this->mnuSequenceNormalDistribution->Text = L"Normalverteilung";
			this->mnuSequenceNormalDistribution->Click += gcnew System::EventHandler(this, &FormMain::mnuSequence_Click);
			// 
			// toolStripSeparator2
			// 
			this->toolStripSeparator2->Name = L"toolStripSeparator2";
			this->toolStripSeparator2->Size = System::Drawing::Size(165, 6);
			// 
			// mnuSequenceExpression
			// 
			this->mnuSequenceExpression->Name = L"mnuSequenceExpression";
			this->mnuSequenceExpression->Size = System::Drawing::Size(168, 22);
			this->mnuSequenceExpression->Text = L"Ausdruck";
			this->mnuSequenceExpression->Click += gcnew System::EventHandler(this, &FormMain::mnuSequence_Click);
			// 
			// mnuCalculation
			// 
			this->mnuCalculation->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {this->mnuCalculation1Variable, 
				this->mnuCalculation2Variables, this->toolStripSeparator6, this->mnuCalculationSaveResults});
			this->mnuCalculation->Name = L"mnuCalculation";
			this->mnuCalculation->Size = System::Drawing::Size(76, 20);
			this->mnuCalculation->Text = L"Berechnung";
			// 
			// mnuCalculation1Variable
			// 
			this->mnuCalculation1Variable->Enabled = false;
			this->mnuCalculation1Variable->Name = L"mnuCalculation1Variable";
			this->mnuCalculation1Variable->Size = System::Drawing::Size(187, 22);
			this->mnuCalculation1Variable->Text = L"1 Variable";
			this->mnuCalculation1Variable->Click += gcnew System::EventHandler(this, &FormMain::mnuCalculation_Click);
			// 
			// mnuCalculation2Variables
			// 
			this->mnuCalculation2Variables->Enabled = false;
			this->mnuCalculation2Variables->Name = L"mnuCalculation2Variables";
			this->mnuCalculation2Variables->Size = System::Drawing::Size(187, 22);
			this->mnuCalculation2Variables->Text = L"2 Variable";
			this->mnuCalculation2Variables->Click += gcnew System::EventHandler(this, &FormMain::mnuCalculation_Click);
			// 
			// toolStripSeparator6
			// 
			this->toolStripSeparator6->Name = L"toolStripSeparator6";
			this->toolStripSeparator6->Size = System::Drawing::Size(184, 6);
			// 
			// mnuCalculationSaveResults
			// 
			this->mnuCalculationSaveResults->Enabled = false;
			this->mnuCalculationSaveResults->Name = L"mnuCalculationSaveResults";
			this->mnuCalculationSaveResults->Size = System::Drawing::Size(187, 22);
			this->mnuCalculationSaveResults->Text = L"Ergebnisse speichern...";
			this->mnuCalculationSaveResults->Click += gcnew System::EventHandler(this, &FormMain::mnuCalculationSaveResults_Click);
			// 
			// mnuChart
			// 
			this->mnuChart->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(7) {this->mnuChartHistogram, 
				this->mnuChartBoxplot, this->toolStripSeparator4, this->mnuChartScatterPlot, this->mnuChartLineChart, this->toolStripSeparator5, 
				this->mnuChartSaveImage});
			this->mnuChart->Name = L"mnuChart";
			this->mnuChart->Size = System::Drawing::Size(66, 20);
			this->mnuChart->Text = L"Diagramm";
			// 
			// mnuChartHistogram
			// 
			this->mnuChartHistogram->Enabled = false;
			this->mnuChartHistogram->Name = L"mnuChartHistogram";
			this->mnuChartHistogram->Size = System::Drawing::Size(151, 22);
			this->mnuChartHistogram->Text = L"Histogramm";
			this->mnuChartHistogram->Click += gcnew System::EventHandler(this, &FormMain::mnuChart_Click);
			// 
			// mnuChartBoxplot
			// 
			this->mnuChartBoxplot->Enabled = false;
			this->mnuChartBoxplot->Name = L"mnuChartBoxplot";
			this->mnuChartBoxplot->Size = System::Drawing::Size(151, 22);
			this->mnuChartBoxplot->Text = L"Boxplot";
			this->mnuChartBoxplot->Click += gcnew System::EventHandler(this, &FormMain::mnuChart_Click);
			// 
			// toolStripSeparator4
			// 
			this->toolStripSeparator4->Name = L"toolStripSeparator4";
			this->toolStripSeparator4->Size = System::Drawing::Size(148, 6);
			// 
			// mnuChartScatterPlot
			// 
			this->mnuChartScatterPlot->Enabled = false;
			this->mnuChartScatterPlot->Name = L"mnuChartScatterPlot";
			this->mnuChartScatterPlot->Size = System::Drawing::Size(151, 22);
			this->mnuChartScatterPlot->Text = L"Streudiagramm";
			this->mnuChartScatterPlot->Click += gcnew System::EventHandler(this, &FormMain::mnuChart_Click);
			// 
			// mnuChartLineChart
			// 
			this->mnuChartLineChart->Enabled = false;
			this->mnuChartLineChart->Name = L"mnuChartLineChart";
			this->mnuChartLineChart->Size = System::Drawing::Size(151, 22);
			this->mnuChartLineChart->Text = L"Liniendiagramm";
			this->mnuChartLineChart->Click += gcnew System::EventHandler(this, &FormMain::mnuChart_Click);
			// 
			// toolStripSeparator5
			// 
			this->toolStripSeparator5->Name = L"toolStripSeparator5";
			this->toolStripSeparator5->Size = System::Drawing::Size(148, 6);
			// 
			// mnuChartSaveImage
			// 
			this->mnuChartSaveImage->Enabled = false;
			this->mnuChartSaveImage->Name = L"mnuChartSaveImage";
			this->mnuChartSaveImage->Size = System::Drawing::Size(151, 22);
			this->mnuChartSaveImage->Text = L"Bild speichern...";
			this->mnuChartSaveImage->Click += gcnew System::EventHandler(this, &FormMain::mnuChartSaveImage_Click);
			// 
			// mnuLanguage
			// 
			this->mnuLanguage->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->mnuLanguageGerman, 
				this->mnuLanguageEnglish, this->mnuLanguageRussian});
			this->mnuLanguage->Name = L"mnuLanguage";
			this->mnuLanguage->Size = System::Drawing::Size(58, 20);
			this->mnuLanguage->Text = L"Sprache";
			// 
			// mnuLanguageGerman
			// 
			this->mnuLanguageGerman->Checked = true;
			this->mnuLanguageGerman->CheckState = System::Windows::Forms::CheckState::Checked;
			this->mnuLanguageGerman->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->mnuLanguageGerman->Name = L"mnuLanguageGerman";
			this->mnuLanguageGerman->Size = System::Drawing::Size(114, 22);
			this->mnuLanguageGerman->Tag = L"de";
			this->mnuLanguageGerman->Text = L"Deutsch";
			this->mnuLanguageGerman->Click += gcnew System::EventHandler(this, &FormMain::mnuLanguage_Click);
			// 
			// mnuLanguageEnglish
			// 
			this->mnuLanguageEnglish->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->mnuLanguageEnglish->Name = L"mnuLanguageEnglish";
			this->mnuLanguageEnglish->Size = System::Drawing::Size(114, 22);
			this->mnuLanguageEnglish->Tag = L"en";
			this->mnuLanguageEnglish->Text = L"English";
			this->mnuLanguageEnglish->Click += gcnew System::EventHandler(this, &FormMain::mnuLanguage_Click);
			// 
			// mnuLanguageRussian
			// 
			this->mnuLanguageRussian->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->mnuLanguageRussian->Name = L"mnuLanguageRussian";
			this->mnuLanguageRussian->Size = System::Drawing::Size(114, 22);
			this->mnuLanguageRussian->Tag = L"ru";
			this->mnuLanguageRussian->Text = L"Русский";
			this->mnuLanguageRussian->Click += gcnew System::EventHandler(this, &FormMain::mnuLanguage_Click);
			// 
			// dataGridView
			// 
			this->dataGridView->AllowUserToDeleteRows = false;
			this->dataGridView->AllowUserToResizeRows = false;
			this->dataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView->Location = System::Drawing::Point(0, 0);
			this->dataGridView->Name = L"dataGridView";
			this->dataGridView->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::ColumnHeaderSelect;
			this->dataGridView->Size = System::Drawing::Size(496, 498);
			this->dataGridView->TabIndex = 0;
			this->dataGridView->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &FormMain::dataGridView_CellBeginEdit);
			this->dataGridView->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormMain::dataGridView_CellEndEdit);
			this->dataGridView->ColumnHeaderMouseDoubleClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &FormMain::dataGridView_ColumnHeaderMouseDoubleClick);
			this->dataGridView->RowsAdded += gcnew System::Windows::Forms::DataGridViewRowsAddedEventHandler(this, &FormMain::dataGridView_RowsAdded);
			this->dataGridView->SelectionChanged += gcnew System::EventHandler(this, &FormMain::dataGridView_SelectionChanged);
			// 
			// ctxtMnuDataGridView
			// 
			this->ctxtMnuDataGridView->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->ctxtMnuDeleteRow});
			this->ctxtMnuDataGridView->Name = L"ctxtMnuDataGridView";
			this->ctxtMnuDataGridView->Size = System::Drawing::Size(190, 26);
			// 
			// ctxtMnuDeleteRow
			// 
			this->ctxtMnuDeleteRow->Name = L"ctxtMnuDeleteRow";
			this->ctxtMnuDeleteRow->Size = System::Drawing::Size(189, 22);
			this->ctxtMnuDeleteRow->Text = L"Markierte Zeilen löschen";
			this->ctxtMnuDeleteRow->Click += gcnew System::EventHandler(this, &FormMain::ctxtMnuDeleteRow_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 24);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->dataGridView);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->tabControl);
			this->splitContainer1->Size = System::Drawing::Size(992, 498);
			this->splitContainer1->SplitterDistance = 496;
			this->splitContainer1->SplitterWidth = 2;
			this->splitContainer1->TabIndex = 2;
			// 
			// tabControl
			// 
			this->tabControl->Alignment = System::Windows::Forms::TabAlignment::Bottom;
			this->tabControl->Controls->Add(this->tabPageText);
			this->tabControl->Controls->Add(this->tabPageGrafik);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Multiline = true;
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(494, 498);
			this->tabControl->TabIndex = 1;
			// 
			// tabPageText
			// 
			this->tabPageText->Controls->Add(this->tableLayoutPanel1);
			this->tabPageText->Location = System::Drawing::Point(4, 4);
			this->tabPageText->Name = L"tabPageText";
			this->tabPageText->Padding = System::Windows::Forms::Padding(3);
			this->tabPageText->Size = System::Drawing::Size(486, 472);
			this->tabPageText->TabIndex = 0;
			this->tabPageText->Text = L"Text";
			this->tabPageText->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				50)));
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 466)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 466)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(480, 466);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tabPageGrafik
			// 
			this->tabPageGrafik->Controls->Add(this->splitContainer2);
			this->tabPageGrafik->Location = System::Drawing::Point(4, 4);
			this->tabPageGrafik->Name = L"tabPageGrafik";
			this->tabPageGrafik->Padding = System::Windows::Forms::Padding(3);
			this->tabPageGrafik->Size = System::Drawing::Size(486, 472);
			this->tabPageGrafik->TabIndex = 1;
			this->tabPageGrafik->Text = L"Grafik";
			this->tabPageGrafik->UseVisualStyleBackColor = true;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(3, 3);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->chart1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->flowLayoutPanel1);
			this->splitContainer2->Size = System::Drawing::Size(480, 466);
			this->splitContainer2->SplitterDistance = 424;
			this->splitContainer2->SplitterWidth = 2;
			this->splitContainer2->TabIndex = 0;
			// 
			// chart1
			// 
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			this->chart1->Size = System::Drawing::Size(480, 424);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(480, 40);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// toolStripSeparator7
			// 
			this->toolStripSeparator7->Name = L"toolStripSeparator7";
			this->toolStripSeparator7->Size = System::Drawing::Size(177, 6);
			// 
			// mnuColumnCopy
			// 
			this->mnuColumnCopy->Enabled = false;
			this->mnuColumnCopy->Name = L"mnuColumnCopy";
			this->mnuColumnCopy->Size = System::Drawing::Size(180, 22);
			this->mnuColumnCopy->Text = L"Kopieren";
			this->mnuColumnCopy->Click += gcnew System::EventHandler(this, &FormMain::mnuColumnCopy_Click);
			// 
			// FormMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(992, 522);
			this->Controls->Add(this->splitContainer1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"FormMain";
			this->Text = L"Statistica";
			this->Load += gcnew System::EventHandler(this, &FormMain::FormMain_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView))->EndInit();
			this->ctxtMnuDataGridView->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->tabControl->ResumeLayout(false);
			this->tabPageText->ResumeLayout(false);
			this->tabPageGrafik->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Windows::Forms::MenuStrip^  menuStrip1;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumn;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnAdd;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnRemove;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnClear;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator3;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnCopy;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator7;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnLoad;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnSaveSelected;
		System::Windows::Forms::ToolStripMenuItem^  mnuColumnSaveAll;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequence;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequenceArithmetic;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequenceConst;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequenceUniformDistribution;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequenceBinomialDistribution;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequenceNormalDistribution;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
		System::Windows::Forms::ToolStripMenuItem^  mnuSequenceExpression;
		System::Windows::Forms::ToolStripMenuItem^  mnuCalculation;
		System::Windows::Forms::ToolStripMenuItem^  mnuCalculation1Variable;
		System::Windows::Forms::ToolStripMenuItem^  mnuCalculation2Variables;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator6;
		System::Windows::Forms::ToolStripMenuItem^  mnuCalculationSaveResults;
		System::Windows::Forms::ToolStripMenuItem^  mnuChart;
		System::Windows::Forms::ToolStripMenuItem^  mnuChartHistogram;
		System::Windows::Forms::ToolStripMenuItem^  mnuChartBoxplot;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator4;
		System::Windows::Forms::ToolStripMenuItem^  mnuChartScatterPlot;
		System::Windows::Forms::ToolStripMenuItem^  mnuChartLineChart;
		System::Windows::Forms::ToolStripSeparator^  toolStripSeparator5;
		System::Windows::Forms::ToolStripMenuItem^  mnuChartSaveImage;
		System::Windows::Forms::ToolStripMenuItem^  mnuLanguage;
		System::Windows::Forms::ToolStripMenuItem^  mnuLanguageGerman;
		System::Windows::Forms::ToolStripMenuItem^  mnuLanguageEnglish;
		System::Windows::Forms::ToolStripMenuItem^  mnuLanguageRussian;
		System::Windows::Forms::SplitContainer^  splitContainer1;
		System::Windows::Forms::DataGridView^  dataGridView;
		System::Windows::Forms::TabControl^  tabControl;
		System::Windows::Forms::TabPage^  tabPageText;
		System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
		System::Windows::Forms::TabPage^  tabPageGrafik;
		System::Windows::Forms::SplitContainer^  splitContainer2;
		System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
		System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
		System::ComponentModel::IContainer^  components;
		System::Windows::Forms::ContextMenuStrip^  ctxtMnuDataGridView;
		System::Windows::Forms::ToolStripMenuItem^  ctxtMnuDeleteRow;
		System::Windows::Forms::OpenFileDialog^  openFileDialog;
		System::Windows::Forms::SaveFileDialog^  saveFileDialog;
		RowStyle^ defaultTableLayoutPanelRowStyle;
		String^ oldCellValue;
		Calculation^ calculation;
		Chart^ chart;

		void updateLanguage(String^ id);
		void addColumn();
		void setEmptyCellToZero();
		array<int>^ getSelectedColumnsSortedIndices();
		array<double, 2>^ getDoubleArrayFromSelectedColumns();
		array<String^>^ getStringArrayFromSelectedColumnsHeaders();
		void displayCalculationResults();
		Label^ createLabelForTableLayoutPanel(String^ text);
		void localizeChart();
		void saveColumns(array<int>^ columns);
	protected:
		~FormMain();
	public:
		FormMain();
		void FormMain_Load(Object^  sender, EventArgs^  e);
		void mnuColumnAdd_Click(Object^  sender, EventArgs^  e);
		void mnuColumnRemove_Click(Object^  sender, EventArgs^  e);
		void mnuColumnClear_Click(Object^  sender, EventArgs^  e);
		void mnuColumnCopy_Click(Object^  sender, EventArgs^  e);
		void mnuColumnLoad_Click(Object^  sender, EventArgs^  e);
		void mnuColumnSaveSelected_Click(Object^  sender, EventArgs^  e);
		void mnuColumnSaveAll_Click(Object^  sender, EventArgs^  e);
		void mnuSequence_Click(Object^  sender, EventArgs^  e);
		void mnuCalculation_Click(Object^  sender, EventArgs^  e);
		void mnuCalculationSaveResults_Click(Object^  sender, EventArgs^  e);
		void mnuChart_Click(Object^  sender, EventArgs^  e);
		void mnuChartSaveImage_Click(Object^  sender, EventArgs^  e);
		void mnuLanguage_Click(Object^  sender, EventArgs^  e);
		void dataGridView_ColumnHeaderMouseDoubleClick(Object^  sender, DataGridViewCellMouseEventArgs^  e);
		void dataGridView_CellBeginEdit(Object^  sender, DataGridViewCellCancelEventArgs^  e);
		void dataGridView_CellEndEdit(Object^  sender, DataGridViewCellEventArgs^  e);
		void dataGridView_RowsAdded(Object^  sender, DataGridViewRowsAddedEventArgs^  e);
		void dataGridView_SelectionChanged(Object^  sender, EventArgs^  e);
		void ctxtMnuDeleteRow_Click(Object^  sender, EventArgs^  e);
	};
}
