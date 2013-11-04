#pragma once
#include "ChartPointLine.h"

namespace Statistica{

	public ref class ChartLine : public ChartPointLine{
	private:
		CheckBox^ showAsSpline;

		void showAsSpline_CheckedChanged(Object^  sender, EventArgs^  e);
	protected:
		virtual void drawChart() override;
	public:
		ChartLine(System::Windows::Forms::DataVisualization::Charting::Chart^ chart);
		virtual void localizeTitles() override;
		virtual array<Control^>^ getControls() override;
	};
}
