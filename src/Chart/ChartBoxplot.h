#pragma once
#include "Chart.h"

namespace Statistica{

	public ref class ChartBoxplot : public Chart{
	private:
		CheckBox^ showMean;
		CheckBox^ showOutliers;
		Button^ borderColor;
		Button^ color;
		ColorDialog^ colorDialog;

		void showMean_CheckedChanged(Object^  sender, EventArgs^  e);
		void showOutliers_CheckedChanged(Object^  sender, EventArgs^  e);
		void borderColor_Clicked(Object^  sender, EventArgs^  e);
		void color_Clicked(Object^  sender, EventArgs^  e);
	protected:
		virtual void drawChart() override;
	public:
		ChartBoxplot(System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
		virtual void localizeTitles() override;
		virtual array<Control^>^ getControls() override;
	};
}
