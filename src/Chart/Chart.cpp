#include "Chart.h"

namespace Statistica{

	ChartArea^ Chart::createChartArea(String^ title){
		ChartArea^ chartArea = gcnew ChartArea(title);

		chartArea->AxisX->IsStartedFromZero = false;
		chartArea->AxisX->MajorGrid->Enabled = false;
		chartArea->AxisX->TitleFont = titleFont;
		
		chartArea->AxisY->IsStartedFromZero = false;
		chartArea->AxisY->MajorGrid->Enabled = false;
		chartArea->AxisY->TitleFont = titleFont;

		return chartArea;
	}

	Label^ Chart::createLabel(String^ key){
		Label^ label = gcnew Label();
		label->AutoSize = true;
		label->Text = ResourceUtil::getString(key);
		label->Size = label->PreferredSize;
		
		return label;
	}

	void Chart::setChartTitle(String^ key){
		chart->Titles->Clear();
		Title^ title = gcnew Title(ResourceUtil::getString(key));
		title->Font = gcnew System::Drawing::Font(chart->Font->Name, 14);
		chart->Titles->Add(title);
	}

	Chart::Chart(System::Windows::Forms::DataVisualization::Charting::Chart^ chart){
		this->chart = chart;
		titleFont = gcnew System::Drawing::Font(chart->Font->Name, 11);
	}

	void Chart::setData(array<double, 2>^ data, array<String^>^ columnHeaders){
		this->data = data;
		this->columnHeaders = columnHeaders;
		valid = (data->Length > 0);
	}

	bool Chart::hasValidData(){
		return valid;
	}

	void Chart::draw(){
		chart->ChartAreas->Clear();
		chart->ChartAreas->Add(createChartArea("chartArea0"));

		chart->Legends->Clear();
		legend = gcnew Legend();
		legend->BackColor = System::Drawing::Color::FromArgb(255, 255, 192);
		legend->DockedToChartArea = "chartArea0";
		legend->Enabled = false;
		chart->Legends->Add(legend);

		chart->Series->Clear();

		if (!valid){
			chart->Titles->Clear();
			return;
		}

		drawChart();
	}
}