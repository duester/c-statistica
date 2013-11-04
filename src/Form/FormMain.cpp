#include "FormMain.h"

namespace Statistica{

	void FormMain::updateLanguage(String^ id){
		ResourceUtil::getInstance()->cultureInfo = gcnew CultureInfo(id);

		// Strings-Lokalisierung
		mnuColumn->Text = ResourceUtil::getString("mnuColumn");
		mnuColumnAdd->Text = ResourceUtil::getString("mnuColumnAdd");
		mnuColumnRemove->Text = ResourceUtil::getString("mnuColumnRemove");
		mnuColumnClear->Text = ResourceUtil::getString("mnuColumnClear");
		mnuColumnCopy->Text = ResourceUtil::getString("mnuColumnCopy");
		mnuColumnLoad->Text = ResourceUtil::getString("mnuColumnLoad");
		mnuColumnSaveSelected->Text = ResourceUtil::getString("mnuColumnSaveSelected");
		mnuColumnSaveAll->Text = ResourceUtil::getString("mnuColumnSaveAll");

		mnuSequence->Text = ResourceUtil::getString("mnuSequence");
		mnuSequenceConst->Text = ResourceUtil::getString("mnuSequenceConst");
		mnuSequenceArithmetic->Text = ResourceUtil::getString("mnuSequenceArithmetic");
		mnuSequenceUniformDistribution->Text = ResourceUtil::getString("mnuSequenceUniformDistribution");
		mnuSequenceBinomialDistribution->Text = ResourceUtil::getString("mnuSequenceBinomialDistribution");
		mnuSequenceNormalDistribution->Text = ResourceUtil::getString("mnuSequenceNormalDistribution");
		mnuSequenceExpression->Text = ResourceUtil::getString("mnuSequenceExpression");

		mnuCalculation->Text = ResourceUtil::getString("mnuCalculation");
		mnuCalculation1Variable->Text = ResourceUtil::getString("mnuCalculation1Variable");
		mnuCalculation2Variables->Text = ResourceUtil::getString("mnuCalculation2Variables");
		mnuCalculationSaveResults->Text = ResourceUtil::getString("mnuCalculationSaveResults");

		mnuChart->Text = ResourceUtil::getString("mnuChart");
		mnuChartHistogram->Text = ResourceUtil::getString("mnuChartHistogram");
		mnuChartBoxplot->Text = ResourceUtil::getString("mnuChartBoxplot");
		mnuChartScatterPlot->Text = ResourceUtil::getString("mnuChartScatterPlot");
		mnuChartLineChart->Text = ResourceUtil::getString("mnuChartLineChart");
		mnuChartSaveImage->Text = ResourceUtil::getString("mnuChartSaveImage");

		mnuLanguage->Text = ResourceUtil::getString("mnuLanguage");

		ctxtMnuDeleteRow->Text = ResourceUtil::getString("ctxtMnuDeleteRow");

		tabPageText->Text = ResourceUtil::getString("txtText");
		tabPageGrafik->Text = ResourceUtil::getString("txtGraphics");

		if (calculation != nullptr)
			displayCalculationResults();

		if (chart != nullptr)
			localizeChart();
	}

	void FormMain::addColumn(){
		DataGridViewColumn^ column = gcnew DataGridViewColumn(gcnew DataGridViewTextBoxCell());
		int n = dataGridView->Columns->Count + 1;
		column->Name = "Column" + n;
		column->HeaderText = n + ".";
		column->SortMode = DataGridViewColumnSortMode::NotSortable;
		column->HeaderCell->Tag = "";
		column->HeaderCell->Style->Alignment = DataGridViewContentAlignment::MiddleCenter;
		dataGridView->Columns->Add(column);
		setEmptyCellToZero();

		mnuColumnSaveAll->Enabled = true;
	}

	void FormMain::setEmptyCellToZero(){
		for (int i=0; i<dataGridView->RowCount-1; i++)
			for (int j=0; j<dataGridView->ColumnCount; j++)
				if (dataGridView->Rows[i]->Cells[j]->Value == nullptr)
					dataGridView->Rows[i]->Cells[j]->Value = "0";
	}

	array<int>^ FormMain::getSelectedColumnsSortedIndices(){
		array<int>^ columnIndices = gcnew array<int>(dataGridView->SelectedColumns->Count);
		for (int i=0; i<dataGridView->SelectedColumns->Count; i++)
			columnIndices[i] = dataGridView->SelectedColumns[i]->Index;
		Array::Sort(columnIndices);

		return columnIndices;
	}

	array<double, 2>^ FormMain::getDoubleArrayFromSelectedColumns(){
		array<double, 2>^ data = gcnew array<double, 2>(dataGridView->RowCount-1, dataGridView->SelectedColumns->Count);
		array<int>^ columnIndices = getSelectedColumnsSortedIndices();

		for (int i=0; i<dataGridView->RowCount-1; i++)
			for (int j=0; j<columnIndices->Length; j++)
				data[i, j] = Double::Parse((String^) dataGridView->Rows[i]->Cells[columnIndices[j]]->Value);

		return data;
	}

	array<String^>^ FormMain::getStringArrayFromSelectedColumnsHeaders(){
		array<String^>^ headers = gcnew array<String^>(dataGridView->SelectedColumns->Count);
		array<int>^ columnIndices = getSelectedColumnsSortedIndices();

		for (int i=0; i<columnIndices->Length; i++)
			headers[i] = (String^) dataGridView->Columns[columnIndices[i]]->HeaderCell->Tag;

		return headers;
	}

	void FormMain::displayCalculationResults(){
		tableLayoutPanel1->Controls->Clear();
		tableLayoutPanel1->RowStyles->Clear();

		array<String^>^ list = calculation->getStrings();
		// Werte einfügen
		for (int i=0; i<list->Length/2; i++){
			Label^ label = createLabelForTableLayoutPanel(list[2 * i]);
			tableLayoutPanel1->Controls->Add(label);
			if (list[2 * i + 1]->Equals("")){
				tableLayoutPanel1->SetColumnSpan(label, 2);
				tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 30));
			}
			else{
				tableLayoutPanel1->Controls->Add(createLabelForTableLayoutPanel(list[2 * i + 1]));
				tableLayoutPanel1->RowStyles->Add(gcnew RowStyle(SizeType::Absolute, 60));
			}
		}
	}

	Label^ FormMain::createLabelForTableLayoutPanel(String^ text){
		Label^ label = gcnew Label();
		label->AutoSize = true;
		label->Font = gcnew System::Drawing::Font(label->Font->Name, 10);
		label->Text = text;
		return label;
	}

	void FormMain::localizeChart(){
		chart->localizeTitles();

		flowLayoutPanel1->Controls->Clear();
		array<Control^>^ controls = chart->getControls();
		for (int i=0; i<controls->Length/2; i++){
			Panel^ panel = gcnew Panel();
			Control^ control1 = controls[2 * i];
			Control^ control2 = controls[2 * i + 1];
			control2->Location = Point(control1->Width + 5, 0);
			panel->Controls->Add(control1);
			panel->Controls->Add(control2);
			panel->Width = control1->Width + control2->Width + 15;
			panel->Height = Math::Max(control1->Height, control2->Height);
			flowLayoutPanel1->Controls->Add(panel);
		}
	}

	void FormMain::saveColumns(array<int>^ columns){
		saveFileDialog->DefaultExt = "csv";
		saveFileDialog->Filter = ResourceUtil::getString("txtFileDialogFilterCSV") + "|*.csv";
		saveFileDialog->FilterIndex = 1;
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(saveFileDialog->FileName);

			for (int i=0; i<dataGridView->Rows->Count - 1; i++){
				for (int j=0; j<columns->Length - 1; j++){
					writer->Write(dataGridView->Rows[i]->Cells[columns[j]]->Value);
					writer->Write(";");
				}
				writer->WriteLine(dataGridView->Rows[i]->Cells[columns[columns->Length - 1]]->Value);
			}

			writer->Close();
		}
	}

	FormMain::~FormMain(){
		if (components){
			delete components;
		}
	}

	FormMain::FormMain(){
		InitializeComponent();
		tableLayoutPanel1->ColumnCount = 2;
		tableLayoutPanel1->RowCount = 0;
	}

	void FormMain::FormMain_Load(Object^  sender, EventArgs^  e) {
		updateLanguage("de");
		mnuLanguageGerman->Text = ResourceUtil::getString("mnuLanguageGerman");
		mnuLanguageEnglish->Text = ResourceUtil::getString("mnuLanguageEnglish");
		mnuLanguageRussian->Text = ResourceUtil::getString("mnuLanguageRussian");

		mnuSequenceConst->Tag = gcnew SequenceConst();
		mnuSequenceArithmetic->Tag = gcnew SequenceArithmetic();
		mnuSequenceUniformDistribution->Tag = gcnew SequenceUniformDistribution();
		mnuSequenceBinomialDistribution->Tag = gcnew SequenceBinomialDistribution();
		mnuSequenceNormalDistribution->Tag = gcnew SequenceNormalDistribution();
		mnuSequenceExpression->Tag = gcnew SequenceExpression();

		mnuCalculation1Variable->Tag = gcnew Calculation1Variable();
		mnuCalculation2Variables->Tag = gcnew Calculation2Variables();

		mnuChartHistogram->Tag = gcnew ChartHistogram(chart1);
		mnuChartBoxplot->Tag = gcnew ChartBoxplot(chart1);
		mnuChartScatterPlot->Tag = gcnew ChartPoint(chart1);
		mnuChartLineChart->Tag = gcnew ChartLine(chart1);
	}

	void FormMain::mnuColumnAdd_Click(Object^  sender, EventArgs^  e) {
		addColumn();
	}

	void FormMain::mnuColumnRemove_Click(Object^  sender, EventArgs^  e) {
		for each (DataGridViewColumn^ column in dataGridView->SelectedColumns){
			dataGridView->Columns->Remove(column);
		}

		for (int i=0; i<dataGridView->Columns->Count; i++){
			DataGridViewColumn^ column = dataGridView->Columns[i];
			column->HeaderText = (i + 1) + ". " + column->HeaderCell->Tag;
		}

		if (dataGridView->Columns->Count == 0)
			mnuColumnSaveAll->Enabled = false;
	}

	void FormMain::mnuColumnClear_Click(Object^  sender, EventArgs^  e){
		for each(DataGridViewColumn^ column in dataGridView->SelectedColumns){
			for (int i=0; i<dataGridView->RowCount - 1; i++)
				dataGridView->Rows[i]->Cells[column->Index]->Value = "0";
		}
	}

	void FormMain::mnuColumnCopy_Click(Object^  sender, EventArgs^  e){
		array<double, 2>^ data = getDoubleArrayFromSelectedColumns();
		array<int>^ columnIndices = getSelectedColumnsSortedIndices();
		int count = data->GetLength(1);
		int columnsSoFar = dataGridView->Columns->Count;

		// neue Spalten einfügen und Überschriften kopieren
		for (int i=0; i<count; i++){
			addColumn();
			DataGridViewColumn^ newColumn = dataGridView->Columns[columnsSoFar + i];
			newColumn->HeaderCell->Tag = dataGridView->Columns[columnIndices[i]]->HeaderCell->Tag;
			newColumn->HeaderText = (columnsSoFar + i + 1) + ". " + newColumn->HeaderCell->Tag;
		}

		// Daten kopieren
		for (int i=0; i<data->GetLength(0); i++)
			for (int j=0; j<count; j++)
				dataGridView->Rows[i]->Cells[columnsSoFar + j]->Value = data[i, j].ToString();
	}

	void FormMain::mnuColumnLoad_Click(Object^  sender, EventArgs^  e){
		openFileDialog->DefaultExt = "csv";
		openFileDialog->Filter = ResourceUtil::getString("txtFileDialogFilterCSV") + "|*.csv";
		if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			System::IO::StreamReader^ reader = gcnew System::IO::StreamReader(openFileDialog->FileName);
			String^ line = reader->ReadLine();
			int count = line->Split(gcnew array<Char>(1){';'})->Length;
			int columnsSoFar = dataGridView->Columns->Count;
			for (int i=0; i<count; i++)
				addColumn();

			int row = 0;
			while (line != nullptr){
				// ggf. neue Zeile einfügen
				if (row == dataGridView->Rows->Count - 1){
					dataGridView->AllowUserToAddRows = false;
					dataGridView->RowCount = row + 1;
					dataGridView->AllowUserToAddRows = true;
				}

				array<String^>^ values = line->Split(gcnew array<Char>(1){';'});
				for (int j=0; j<count; j++)
					dataGridView->Rows[row]->Cells[columnsSoFar + j]->Value = values[j];

				line = reader->ReadLine();
				row++;
			}
		}
	}

	void FormMain::mnuColumnSaveSelected_Click(Object^  sender, EventArgs^  e){
		saveColumns(getSelectedColumnsSortedIndices());
	}

	void FormMain::mnuColumnSaveAll_Click(Object^  sender, EventArgs^  e){
		array<int>^ columns = gcnew array<int>(dataGridView->Columns->Count);
		for (int i=0; i<columns->Length; i++)
			columns[i] = i;
		saveColumns(columns);
	}

	void FormMain::mnuSequence_Click(Object^  sender, EventArgs^  e) {
		array<double>^ list = ((Sequence^) ((ToolStripMenuItem^) sender)->Tag)->generate();
		if (list == nullptr)
			return;
		addColumn();
		// ggf. neue Zeilen einfügen
		if (list->Length > dataGridView->Rows->Count - 1){
			dataGridView->AllowUserToAddRows = false;
			dataGridView->RowCount = list->Length;
			dataGridView->AllowUserToAddRows = true;
		}
		// Werte einfügen
		for (int i=0; i<list->Length; i++)
			dataGridView->Rows[i]->Cells[dataGridView->Columns->Count - 1]->Value = list[i].ToString();
	}

	void FormMain::mnuCalculation_Click(Object^  sender, EventArgs^  e){
		calculation = (Calculation^) ((ToolStripMenuItem^) sender)->Tag;
		calculation->calculate(getDoubleArrayFromSelectedColumns());
		displayCalculationResults();

		mnuCalculationSaveResults->Enabled = tableLayoutPanel1->Controls->Count > 0;
	}

	void FormMain::mnuCalculationSaveResults_Click(Object^  sender, EventArgs^  e){
		saveFileDialog->DefaultExt = "txt";
		saveFileDialog->Filter = ResourceUtil::getString("txtFileDialogFilterTextFiles") + "|*.txt";
		saveFileDialog->FilterIndex = 1;
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			System::IO::StreamWriter^ writer = gcnew System::IO::StreamWriter(saveFileDialog->FileName);

			for (int i=0; i<tableLayoutPanel1->Controls->Count; i++)
				writer->WriteLine(tableLayoutPanel1->Controls[i]->Text);

			writer->Close();
		}
	}

	void FormMain::mnuChart_Click(System::Object^  sender, System::EventArgs^  e){
		chart = (Chart^) ((ToolStripMenuItem^) sender)->Tag;
		chart->setData(getDoubleArrayFromSelectedColumns(), getStringArrayFromSelectedColumnsHeaders());
		chart->draw();
		localizeChart();

		mnuChartSaveImage->Enabled = chart->hasValidData();
	}

	void FormMain::mnuChartSaveImage_Click(Object^  sender, EventArgs^  e){
		saveFileDialog->Filter = "BMP|*.bmp|JPG|*.jpg|PNG|*.png";
		saveFileDialog->FilterIndex = 3;
		if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			ChartImageFormat format;
			switch (saveFileDialog->FilterIndex){
			case 1:
				format = ChartImageFormat::Bmp;
				break;
			case 2:
				format = ChartImageFormat::Jpeg;
				break;
			case 3:
				format = ChartImageFormat::Png;
				break;
			}
			chart1->SaveImage(saveFileDialog->FileName, format);
		}
	}

	void FormMain::mnuLanguage_Click(Object^  sender, EventArgs^  e){
		updateLanguage((String^) ((ToolStripMenuItem^) sender)->Tag);
		// Häckchen aktualisieren
		for (int i=0; i<mnuLanguage->DropDownItems->Count; i++)
			((ToolStripMenuItem^) mnuLanguage->DropDownItems[i])->Checked = false;
		((ToolStripMenuItem^) sender)->Checked = true;
	}

	void FormMain::dataGridView_ColumnHeaderMouseDoubleClick(Object^  sender, DataGridViewCellMouseEventArgs^  e) {
		DataGridViewColumn^ column = dataGridView->Columns[e->ColumnIndex];
		column->Selected = false;
		InputForm^ form = gcnew InputForm(nullptr);
		form->addField("txtEnterColumnName", column->HeaderCell->Tag->ToString());
		form->addButtons();
		if (form->ShowDialog() == System::Windows::Forms::DialogResult::OK){
			column->HeaderCell->Tag = form->getTextBoxValue("txtEnterColumnName");
			column->HeaderText = (e->ColumnIndex + 1) + ". " + column->HeaderCell->Tag;
		}
	}

	void FormMain::dataGridView_CellBeginEdit(Object^  sender, DataGridViewCellCancelEventArgs^  e) {
		oldCellValue = (String^) dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value;
	}

	void FormMain::dataGridView_CellEndEdit(Object^  sender, DataGridViewCellEventArgs^  e) {
		try{
			double d = Double::Parse((String^) dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);
			dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = d.ToString();
		} catch (Exception^){
			dataGridView->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value = oldCellValue;
		}
	}

	void FormMain::dataGridView_RowsAdded(Object^  sender, DataGridViewRowsAddedEventArgs^  e) {
		for (int i=e->RowIndex; i<e->RowIndex+e->RowCount; i++)
			dataGridView->Rows[i]->HeaderCell->Value = (i+1) + ".";
		setEmptyCellToZero();
	}

	void FormMain::dataGridView_SelectionChanged(Object^  sender, EventArgs^  e){
		mnuColumnRemove->Enabled = (dataGridView->SelectedColumns->Count > 0);
		mnuColumnClear->Enabled = (dataGridView->SelectedColumns->Count > 0);
		mnuColumnCopy->Enabled = (dataGridView->SelectedColumns->Count > 0);
		mnuColumnSaveSelected->Enabled = (dataGridView->SelectedColumns->Count > 0);

		mnuCalculation1Variable->Enabled = (dataGridView->SelectedColumns->Count == 1);
		mnuCalculation2Variables->Enabled = (dataGridView->SelectedColumns->Count == 2);

		mnuChartHistogram->Enabled = (dataGridView->SelectedColumns->Count > 0);
		mnuChartBoxplot->Enabled = (dataGridView->SelectedColumns->Count > 0);
		mnuChartScatterPlot->Enabled = (dataGridView->SelectedColumns->Count == 2);
		mnuChartLineChart->Enabled = (dataGridView->SelectedColumns->Count == 2);

		dataGridView->ContextMenuStrip = (dataGridView->SelectedCells->Count > 0) ? ctxtMnuDataGridView : nullptr;
	}

	void FormMain::ctxtMnuDeleteRow_Click(Object^  sender, EventArgs^  e){
		List<int>^ rowNumbers = gcnew List<int>();
		for each (DataGridViewCell^ cell in dataGridView->SelectedCells){
			if (!rowNumbers->Contains(cell->RowIndex))
				rowNumbers->Add(cell->RowIndex);
		}
		rowNumbers->Sort();

		for (int i=rowNumbers->Count - 1; i>=0; i--){
			try{
				dataGridView->Rows->RemoveAt(rowNumbers[i]);
			} catch (Exception^){
			}
		}

		for (int i=0; i<dataGridView->RowCount; i++)
			dataGridView->Rows[i]->HeaderCell->Value = (i+1) + ".";

		dataGridView->ClearSelection();
	}
}