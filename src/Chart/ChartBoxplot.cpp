#include "ChartBoxplot.h"

namespace Statistica{

	void ChartBoxplot::showMean_CheckedChanged(Object^  sender, EventArgs^  e){
		for (int i=0; i<data->GetLength(1); i++){
			Series^ seriesBoxPlot = chart->Series["boxplot" + i];
			seriesBoxPlot["BoxPlotShowAverage"] = Boolean(showMean->Checked).ToString();
		}
	}

	void ChartBoxplot::showOutliers_CheckedChanged(Object^  sender, EventArgs^  e){
		for (int i=0; i<data->GetLength(1); i++){
			Series^ seriesBoxPlot = chart->Series["boxplot" + i];
			seriesBoxPlot["BoxPlotShowUnusualValues"] = Boolean(showOutliers->Checked).ToString();
		}
	}

	void ChartBoxplot::borderColor_Clicked(Object^  sender, EventArgs^  e){
		colorDialog->Color = borderColor->BackColor;
		if (colorDialog->ShowDialog() == DialogResult::OK){
			borderColor->BackColor = colorDialog->Color;
			for (int i=0; i<data->GetLength(1); i++)
				chart->Series["boxplot" + i]->BorderColor = colorDialog->Color;
		}
	}

	void ChartBoxplot::color_Clicked(Object^  sender, EventArgs^  e){
		colorDialog->Color = color->BackColor;
		if (colorDialog->ShowDialog() == DialogResult::OK){
			color->BackColor = colorDialog->Color;
			for (int i=0; i<data->GetLength(1); i++)
				chart->Series["boxplot" + i]->Color = colorDialog->Color;
		}
	}

	void ChartBoxplot::drawChart(){
		legend->Enabled = true;

		for (int i=0; i<data->GetLength(1); i++){
			Series^ seriesData = gcnew Series("data" + i);
			chart->Series->Add(seriesData);
			seriesData->Points->DataBindY(Util::extractOneDimensionalArray(data, i));
			seriesData->Enabled = false;

			Series^ seriesBoxPlot = gcnew Series("boxplot" + i);
			chart->Series->Add(seriesBoxPlot);

			seriesBoxPlot->ChartType = SeriesChartType::BoxPlot;
			seriesBoxPlot->BorderColor = borderColor->BackColor;
			seriesBoxPlot->Color = color->BackColor;
			seriesBoxPlot["BoxPlotSeries"] = "data" + i;
			seriesBoxPlot["BoxPlotShowAverage"] = Boolean(showMean->Checked).ToString();
			seriesBoxPlot["BoxPlotShowUnusualValues"] = Boolean(showOutliers->Checked).ToString();
			seriesBoxPlot["DrawSideBySide"] = "true";
			seriesBoxPlot->IsVisibleInLegend = false;

			LegendItem^ legendItem = gcnew LegendItem();
			LegendCell^ cell1 = gcnew LegendCell((i + 1) + ".");
			cell1->Alignment = System::Drawing::ContentAlignment::MiddleLeft;
			LegendCell^ cell2 = gcnew LegendCell(columnHeaders[i]);
			cell2->Alignment = System::Drawing::ContentAlignment::MiddleLeft;
			legendItem->Cells->Add(cell1);
			legendItem->Cells->Add(cell2);
			legend->CustomItems->Add(legendItem);
		}
	}

	ChartBoxplot::ChartBoxplot(System::Windows::Forms::DataVisualization::Charting::Chart^ chart)
		: Chart(chart){
			showMean = gcnew CheckBox();
			showMean->Checked = false;
			showMean->AutoSize = true;
			showMean->CheckedChanged += gcnew EventHandler(this, &ChartBoxplot::showMean_CheckedChanged);

			showOutliers = gcnew CheckBox();
			showOutliers->Checked = true;
			showOutliers->AutoSize = true;
			showOutliers->CheckedChanged += gcnew EventHandler(this, &ChartBoxplot::showOutliers_CheckedChanged);

			borderColor = gcnew Button();
			borderColor->BackColor = System::Drawing::Color::Black;
			borderColor->Size = System::Drawing::Size(20, 20);
			borderColor->Click += gcnew EventHandler(this, &ChartBoxplot::borderColor_Clicked);

			color = gcnew Button();
			color->BackColor = System::Drawing::Color::FromArgb(252, 180, 65);
			color->Size = System::Drawing::Size(20, 20);
			color->Click += gcnew EventHandler(this, &ChartBoxplot::color_Clicked);

			colorDialog = gcnew ColorDialog();
	}

	void ChartBoxplot::localizeTitles(){
		if (!valid)
			return;

		setChartTitle("txtBoxplot");
	}

	array<Control^>^ ChartBoxplot::getControls(){
		if (!valid)
			return gcnew array<Control^>(0);

		return gcnew array<Control^>(8){createLabel("txtBorderColor"), borderColor,
			createLabel("txtFillColor"), color,
			createLabel("txtShowMean"), showMean,
			createLabel("txtShowOutliers"), showOutliers};
	}
}
