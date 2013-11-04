#pragma once
#include "ChartPointLine.h"

namespace Statistica{
	
	using namespace System::Drawing;

	public ref class ChartPoint : public ChartPointLine{
	private:
		CheckBox^ showRegressionLine;
		Color regressionLineColor;
		LegendItem^ regressionLineLegendItem;

		void showRegressionLine_CheckedChanged(Object^  sender, EventArgs^  e);
	protected:
		virtual void drawChart() override;
	public:
		ChartPoint(System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
		virtual void localizeTitles() override;
		virtual array<Control^>^ getControls() override;
	};
}
