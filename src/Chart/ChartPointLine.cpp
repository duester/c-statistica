#include "ChartPointLine.h"

namespace Statistica{

	void ChartPointLine::color_Clicked(Object^  sender, EventArgs^  e){
		colorDialog->Color = color->BackColor;
		if (colorDialog->ShowDialog() == DialogResult::OK){
			color->BackColor = colorDialog->Color;
			chart->Series["pointLine"]->Color = colorDialog->Color;
		}
	}

	void ChartPointLine::drawChart(){
		array<double>^ x = Util::extractOneDimensionalArray(data, 0);
		array<double>^ y = Util::extractOneDimensionalArray(data, 1);

		Series^ series = gcnew Series("pointLine");
		series->Color = color->BackColor;
		series->Points->DataBindXY(x, y);
		series->IsVisibleInLegend = false;

		ChartArea^ chartArea = chart->ChartAreas["chartArea0"];
		chart->Series->Add(series);
		chartArea->AxisX->Title = columnHeaders[0];
		chartArea->AxisY->Title = columnHeaders[1];
	}

	ChartPointLine::ChartPointLine(System::Windows::Forms::DataVisualization::Charting::Chart^ chart)
		: Chart(chart){
			color = gcnew Button();
			color->BackColor = System::Drawing::Color::Blue;
			color->Size = System::Drawing::Size(20, 20);
			color->Click += gcnew EventHandler(this, &ChartPointLine::color_Clicked);

			colorDialog = gcnew ColorDialog();
	}
}
