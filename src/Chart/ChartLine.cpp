#include "ChartLine.h"

namespace Statistica{

	void ChartLine::showAsSpline_CheckedChanged(Object^  sender, EventArgs^  e){
		chart->Series["pointLine"]->ChartType = showAsSpline->Checked ? SeriesChartType::Spline : SeriesChartType::Line;
	}

	void ChartLine::drawChart(){
		ChartPointLine::drawChart();

		chart->Series["pointLine"]->ChartType = showAsSpline->Checked ? SeriesChartType::Spline : SeriesChartType::Line;
	}

	ChartLine::ChartLine(System::Windows::Forms::DataVisualization::Charting::Chart^ chart)
		: ChartPointLine(chart){
			showAsSpline = gcnew CheckBox();
			showAsSpline->Checked = false;
			showAsSpline->AutoSize = true;
			showAsSpline->CheckedChanged += gcnew EventHandler(this, &ChartLine::showAsSpline_CheckedChanged);
	}

	void ChartLine::localizeTitles(){
		if (!valid)
			return;

		setChartTitle("txtLineChart");
	}

	array<Control^>^ ChartLine::getControls(){
		if (!valid)
			return gcnew array<Control^>(0);

		return gcnew array<Control^>(4){createLabel("txtLineColor"), color,
			createLabel("txtShowAsSpline"), showAsSpline};
	}
}
