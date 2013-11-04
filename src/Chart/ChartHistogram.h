#pragma once
#include "Chart.h"

namespace Statistica{

	public ref class ChartHistogram : public Chart{
	private:
		NumericUpDown^ numberOfIntervals;
		Button^ borderColor;
		Button^ columnColor;
		ColorDialog^ colorDialog;

		void numberOfIntervals_ValueChanged(Object^  sender, EventArgs^  e);
		void borderColor_Clicked(Object^  sender, EventArgs^  e);
		void columnColor_Clicked(Object^  sender, EventArgs^  e);
		double roundInterval(double interval);
	protected:
		virtual void drawChart() override;
	public:
		ChartHistogram(System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
		virtual void localizeTitles() override;
		virtual array<Control^>^ getControls() override;
	};
}
